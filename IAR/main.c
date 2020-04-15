#include "C:\Users\riban\OneDrive\Ambiente de Trabalho\IAR\lib\Utils.h"
#include "C:\Users\riban\OneDrive\Ambiente de Trabalho\IAR\lib\ControlUnit.h"
#include <intrinsics.h>

#define OVERFLOW16BITS    65535‬

// Global count of hall sensors pulses
uint16_t count_pulse_s1         = 0x0000;
uint16_t count_pulse_s2         = 0x0000;
uint16_t count_pulse_initial_s1 = 0x0000;
uint16_t count_pulse_initial_s2 = 0x0000;

// Pulse rate
uint8_t pulse_rate              = 0x00;
uint8_t pulse_rate_s1           = 0x00;
uint8_t pulse_rate_s2           = 0x00;

// SPI register
uint8_t spiCode                 = 0x00;

// Stroke lenght
uint8_t  stroke_lenght          = 0x00;  

// Auxiliar flags
uint8_t RESET_COUNT_PULSES      = 0x00;
uint8_t TX_PULSE_RATE           = 0x00;
uint8_t RX_STROKE_LENGHT        = 0x00;
uint8_t TX_POSITION             = 0x00;
uint8_t INTERRUPTS_ENABLE       = 0x00;

//  Wait until receive stroke lenght value throught SPI
void receiveStrokeLenght(void               );
//  Calculate and send pulse rate value throught SPI
void sendPulseRate      (void               );
//  Send actuator position throught SPI
    // 0xFF - Fully extended
    // 0x00 - Fully refracted
void sendPosition       (uint8_t position   );
//  Enable  or disable interrupts generated by hall sensors
void interruptsSensors  (uint8_t state      );
//  Reset pulses counts
void resetCountPulses   (void               );



#pragma vector = SPI_TXE_vector
__interrupt void SPI_IRQHandler(void){
    if (SPI_SR_RXNE) 
        spiCode = SPI_DR;          //  Read the byte we have received.
}

#pragma vector = EXTI2_vector                    
__interrupt void EXTI_PORTC_IRQHandler(void){
    if (HALL_S1 == 0)             //  Falling edge of hall sensor 1.
        count_pulse_s1++;
    else if (HALL_S2 == 0)        //  Falling edge of hall sensor 2.  
        count_pulse_s2++;
}

int main( void ){ 
    uint8_t  current_state       = 0x00;
    uint8_t  next_state          = 0x00;


    //  Disable interrupts
    __disable_interrupt();

    init_clock();
    init_ports();
    setup_spi();
    setup_adc();
    setup_interrupts_sensors(DISABLE);
    
    //  Turn-off all outputs
    INA                         = 0;
    INB                         = 0;
    SEL0                        = 0;
    PWM                         = 0;
    
    //  Initialize pulse_rate
    pulse_rate                  = 0x00;
    pulse_rate_s1               = 0x00;
    pulse_rate_s2               = 0x00;

    //  Initialize stroke lenght
    stroke_lenght               = 0x00;


    RESET_COUNT_PULSES          = 0; //  Clear flag RESET_COUNT_PULSES
    INTERRUPTS_ENABLE           = 0; //  Clear flag INTERRUPTS_ENABLE
    TX_PULSE_RATE               = 0; //  Clear flag TX_PULSE_RATE
    RX_STROKE_LENGHT            = 0; //  Clear flag RX_STROKE_LENGHT
    
    //  Enable interrupts
    __enable_interrupt();

    while (1) {
        
        current_state = next_state;
        
        switch (current_state) {    
            case WAIT:
                INA  = 0;
                INB  = 0;
                SEL0 = 0;
                PWM  = 0;
                
                if (!stroke_lenght) //  Not yet received stroke lenght
                    RX_STROKE_LENGHT    = 0; //  Clear flag RX_STROKE_LENGHT
                
                if (!pulse_rate){  //  Not yet calculate pulse rate
                    RESET_COUNT_PULSES  = 0; //  Clear flag RESET_COUNT_PULSES
                    TX_PULSE_RATE       = 0; //  Clear flag TX_PULSE_RATE
                }

                TX_POSITION = 0; // Clear flag TX_POSITION
            break;

            case IS_STOP:
                INA  = 0;
                INB  = 0;
                SEL0 = 0;
                PWM  = 0;

                if (!RX_STROKE_LENGHT)
                    receiveStrokeLenght();
            break;

            case IS_EXTENDED:
                INB  = 0;
                INA  = 1;
                SEL0 = 1;
                PWM  = 1;
            break;

            case IS_REFRACTED:
                if(!RESET_COUNT_PULSES)
                    resetCountPulses();
                
                if(!INTERRUPTS_ENABLE)
                    interruptsSensors(ENABLE);
                
                INA  = 0;
                SEL0 = 0;
                INB  = 1;
                PWM  = 1;
            break;

            case IS_SEND:
                if(INTERRUPTS_ENABLE)
                    interruptsSensors(DISABLE);
                
                INA  = 0;
                INB  = 0;
                SEL0 = 0;
                PWM  = 0;

                if(!TX_PULSE_RATE)
                    sendPulseRate();    
            break;

            case SR_STOP:
                INA  = 0;
                INB  = 0;
                SEL0 = 0;
                PWM  = 0;
            break;

            case SR_REFRACTED:
                INA  = 0;
                SEL0 = 0;
                INB  = 1;
                PWM  = 1;
            break;

            case SR_SEND:
                INA  = 0;
                INB  = 0;
                SEL0 = 0;
                PWM  = 0;

                if (!TX_POSITION)
                    sendPosition(F_R_POSITION);
            break;

            case B_STOP:
                INA  = 0;
                INB  = 0;
                SEL0 = 0;
                PWM  = 0;
            break;

            case B_EXTENDED:
                INB  = 0;
                INA  = 1;
                SEL0 = 1;
                PWM  = 1;
            break;

            case B_REFRACTED:
                INA  = 0;
                SEL0 = 0;
                INB  = 1;
                PWM  = 1;
            break;

            default:
                INA  = 0;
                INB  = 0;
                SEL0 = 0;
                PWM  = 0;
            break;
        }
        

        switch (current_state) {
            case WAIT:
                if (spiCode == INITIALSETUP())
                    next_state = IS_EXTENDED;
                else if (spiCode == SAFERESET())
                    next_state = SR_REFRACTED;
                else if (spiCode == BASIC())
                    next_state = B_STOP;
                /*
                else if (spiCode == ADVANCED())
                    next_state = A_STOP;
                */
            break;
            
            case IS_STOP:
                if (spiCode == DISCONNECTED()) 
                    next_state = WAIT;    
                else if (RX_STROKE_LENGHT)
                    next_state = IS_EXTENDED;
            break;
            
            case IS_EXTENDED:
                if (read_cs() == 0x0000) //  Output current is null because the limit switches cause an open load.
                    next_state = IS_REFRACTED;
            break;
            
            case IS_REFRACTED:
                if (read_cs() == 0x0000) //  Output current is null because the limit switches cause an open load.
                    next_state = IS_SEND;
            break;
            
            case IS_SEND:
                if (TX_PULSE_RATE) //  Transmitter pulse rate finished
                    next_state = IS_STOP;
            break;

            case SR_REFRACTED:
                if (read_cs() == 0x0000)
                    next_state = SR_SEND;
            break;

            case SR_SEND:
                if (SPI_SR_TXE) //  Transmitter position finished
                    next_state = SR_STOP;
            break;

            case SR_STOP:
                if (spiCode == DISCONNECTED())
                    next_state = WAIT;
            break;
            
            case B_STOP:
                if (spiCode == EXTENDED())
                    next_state = B_EXTENDED;
                else if (spiCode == REFRACTED())
                    next_state = B_REFRACTED;
                else if (spiCode == DISCONNECTED())
                    next_state = WAIT;
            break;      
            
            case B_EXTENDED:
                if ((spiCode == STOP()) || (read_cs() == 0x0000))
                    next_state = B_STOP;
            break;
            
            case B_REFRACTED:
                if ((spiCode == STOP()) || (read_cs() == 0x0000))
                    next_state = B_STOP;
            break;


            /*
            case A_STOP:
                if (spiCode == EXTENDED())
                    next_state = A_WAIT_SHIFT_E;
                else if (spiCode == REFRACTED())
                    next_state = A_WAIT_SHIFT_R;
                else if (spiCode == DISCONNECTED())
                    next_state = WAIT;
            break;      
            
            case A_EXTENDED:
                if (read_cs() == 0x0000)
                    next_state = A_SENDFULLYEXTENDED;
                else if ()
            break;
            
            case A_REFRACTED:
                if (read_cs() == 0x0000)
                    next_state = A_SENDFULLYREFRACTED;
            break;
            */
            default:
                next_state = WAIT;
            break;
        }
        
    }
        
    return 0;
}

void resetCountPulses(void){
    count_pulse_initial_s1  = 0x0000;
    count_pulse_initial_s2  = 0x0000;
    RESET_COUNT_PULSES      = 0x01;  //  Set flag RESET_COUNT_PULSES
    
    return;
}

void interruptsSensors (uint8_t state) {
    setup_interrupts_sensors(state);
    
    if (state == ENABLE)  
        INTERRUPTS_ENABLE = 0x01;  
    
    else
        INTERRUPTS_ENABLE = 0x00;
    
    return;
}

void sendPosition(uint8_t position){
    send_byte(position);
    TX_POSITION           = 0x01; //  Set flag TX_POSITION
    return;
}

void sendPulseRate (void){
    if (pulse_rate_s1 >= count_pulse_initial_s1) //  No overflow
        pulse_rate_s1 = ((uint8_t)(count_pulse_s1 - count_pulse_initial_s1))/stroke_lenght;
    else 
        pulse_rate_s1 = ((uint8_t)((65535 - count_pulse_initial_s1) + count_pulse_s1))/stroke_lenght;
    
    if (pulse_rate_s2 >= count_pulse_initial_s2) //  No overflow
        pulse_rate_s2 = ((uint8_t)(count_pulse_s2 - count_pulse_initial_s2))/stroke_lenght;
    else 
        pulse_rate_s2 = ((uint8_t)((65535 - count_pulse_initial_s2) + count_pulse_s2))/stroke_lenght;
            
    //  Pulse avarage of two hall sensors.
    pulse_rate = (pulse_rate_s1 + pulse_rate_s2) / 2;

    send_byte(pulse_rate);
    TX_PULSE_RATE = 0x01;   //  Set flag TX_PULSE_RATE

    return;
}

void receiveStrokeLenght (void){
    while (spiCode == DISCONNECTED() || spiCode == INITIALSETUP());
    stroke_lenght = spiCode;
    RX_STROKE_LENGHT = 0x01; //  Set flag RX_STROKE_LENGHT

    return;
}