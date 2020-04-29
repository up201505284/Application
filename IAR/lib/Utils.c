#include "C:\Users\riban\OneDrive\Ambiente de Trabalho\IAR\lib\Utils.h"
#include "C:\Users\riban\OneDrive\Ambiente de Trabalho\IAR\lib\ControlUnit.h"

void init_clock(void) {
    //  Enable high speed internal oscillator
        //  Enable MVR regulator in Active-halt mode.
        //  Disable the LSI.
        //  Disable fast wakeup from Halt/Active-halt modes.
    CLK_ICKR          = 0x00;       
    //  Enable the HSI.
    CLK_ICKR_HSIEN   = 1;
    CLK_ECKR         = 0x00; //  Disable the external clock.
    while (CLK_ICKR_HSIRDY == 0); //  Wait for the HSI to be ready for use.
    CLK_CKDIVR       = 0x00; //  Ensure the clocks are running at full speed (without prescaling factor).
    CLK_PCKENR1      = 0xFF; //  Enable peripheral clocks (TIMx, UARTx, SPI, I2C).
    CLK_PCKENR2      = 0xFF; //  Enable peripheral clocks (CAN, ADC, AWU)     
    CLK_CCOR         = 0x00; //  Turn off CCO.
    CLK_HSITRIMR     = 0x00; //  Turn off any HSIU trimming.
    CLK_SWIMCCR      = 0x00; //  Set SWIM to run at clock / 2.
    CLK_SWR          = 0xE1; //  Use HSI as the clock source.
   
    //  Reset the clock switch control register.
        //  Disable clock switch interrupt.
        //  Disable clock switch execution.
        //  Clear clock  switch interrupt flag.
    CLK_SWCR         = 0x00; 
    CLK_SWCR_SWEN    = 1; //  Enable clock switch execution.
   
    while (CLK_SWCR_SWBSY != 0); //  Wait while the clock switch is busy.

    return;
}

void init_ports(void) { 
    //  Initialise digital outputs 
        //  INA     -> PC3
        //  INB     -> PC4
        //  SEL0    -> PE0
        //  PWM     -> PD3 (TIM2_CH2)

    //  Pin is set to output mode.
    PD_DDR_DDR3 = 1; 
    PC_DDR_DDR3 = 1; 
    PC_DDR_DDR4 = 1;
    PE_DDR_DDR0 = 1;
    //  Pin is set to Push-Pull mode.
    PD_CR1_C13  = 1;
    PC_CR1_C14  = 1;
    PC_CR1_C13  = 1;
    PE_CR1_C10  = 1;
    // Pin can run up to 10MHz.
    PD_CR2_C23  = 1;
    PC_CR2_C23  = 1;
    PC_CR2_C24  = 1;
    PE_CR2_C20  = 1;

    //  Initialise digital inputs
        //  HALL_S1    -> PC1 
        //  HALL_S2    -> PC2 
    //  Pin is set to input mode.
    PC_DDR_DDR2 = 0;
    PC_DDR_DDR1 = 0;
    //  Pin is set to input with pull-up.
    PC_CR1_C12 = 1;
    PC_CR1_C11 = 1;
    //  Disable external interrupt.
    PC_CR2_C22 = 0;
    PC_CR2_C21 = 0;
    
    //  Inicialise analog inputs
        //  CCS         -> PB5
    //  Pin is set to input mode.
    PB_DDR_DDR5 = 0;
    //  Pin is configured as floating input.
    PB_CR1_C15  = 0;
    //  Disable external interrupts.
    PB_CR2_C25  = 0;


    // //  SPI port init
    //     //  MISO -> PC7 is push-pull out
    // PC_DDR_DDR7 = 1; 
    // PC_CR1_C17  = 1;
    // PC_CR2_C27  = 1; 
    //     //  MOSI -> PC6 is pull-up in  
    //     //  SCK  -> PC5 is pull-up in
    //     //  SS   -> PD2 is pull-up in 
    // PC_DDR_DDR6 = 0;
    // PC_DDR_DDR5 = 0;
    // PD_DDR_DDR2 = 0;
    // PC_CR1_C16  = 1;
    // PC_CR1_C15  = 1;
    // PD_CR1_C12  = 1;
    // PC_CR2_C26  = 0;
    // PC_CR2_C25  = 0;
    // PD_CR2_C22  = 0;

    // //  ADC pin init
    //     //  CS -> PB5 is a floating input
    // PB_DDR_DDR5 = 0;
    // PB_CR1_C15  = 0;
    // PB_CR2_C25  = 0;

    return;
}

void setup_adc (void) {
    //  Reset ADC registers to a known state.
    ADC_CSR = 0x00;
    ADC_CR1 = 0x00;
    ADC_CR2 = 0x00;
    ADC_CR3 = 0x00;
    
    //  Set prescaler division factor to 2.
    //  Single conversion mode.
    //  Disable external trigger.
    //  Set data alignment to left alignment.
    //  Disable scan mode.
    //  Select input channel 5 to be converted.
    ADC_CSR_CH = 5; 
    //  Enable ADC. 
    ADC_CR1_ADON = 1;
    
    return;     
}

void setup_pwm(uint8_t duty_cycle) {
    int timer2_arr = TIM2_ARR_10KHz - 1;
    int timer2_ccr2 = TIM2_ARR_10KHz/100*duty_cycle-1;
    
    //  Reset Timer 2 to a known state.
    TIM2_CR1    = 0x00;               
    TIM2_IER    = 0x00;
    TIM2_SR2    = 0x00;
    TIM2_CCER1  = 0x00;
    TIM2_CCER2  = 0x00;
    TIM2_CCER1  = 0x00;
    TIM2_CCER2  = 0x00;
    TIM2_CCMR1  = 0x00;
    TIM2_CCMR2  = 0x00;
    TIM2_CCMR3  = 0x00;
    TIM2_CNTRH  = 0x00;
    TIM2_CNTRL  = 0x00;
    TIM2_PSCR   = 0x00;
    TIM2_ARRH   = 0x00;
    TIM2_ARRL   = 0x00;
    TIM2_CCR1H  = 0x00;
    TIM2_CCR1L  = 0x00;
    TIM2_CCR2H  = 0x00;
    TIM2_CCR2L  = 0x00;
    TIM2_CCR3H  = 0x00;
    TIM2_CCR3L  = 0x00;
    TIM2_SR1    = 0x00;
    
        //  Set prescaler to 1.
    TIM2_PSCR = 0x00;
    //  Fill 16 bit timer2_arr to two 8 bit registers.
    TIM2_ARRH = (uint8_t)((timer2_arr) >> 8) & (0xFF);
    TIM2_ARRL = (uint8_t)(timer2_arr) & 0xFF;
 
    //  Fill 16 bit timer2_ccr1 to two 8 bit registers.
    TIM2_CCR2H = (uint8_t) (timer2_ccr2 >> 8) & (0xFF);
    TIM2_CCR2L = (uint8_t) (timer2_ccr2)& 0xFF;
    //  Active is defined as high.
    TIM2_CCER1_CC2P = 0;
    // Enable compare mode for channel 2
    TIM2_CCER1_CC2E = 1;    
    //  Output is enable.
    TIM2_CCMR2_OC2PE = 1;
    //  Enable PWM mode 1 (0b110 = 6) in channel 2
    TIM2_CCMR2_OC2M = 6;

    // Enable counter.
    TIM2_CR1_CEN = 1;



    return;
}

void setup_spi(void) {

    // SPI registers reset. 
    SPI_CR1 = 0x00;
    SPI_CR2 = 0x00;
    
    //  Disable SPI.
    SPI_CR1_SPE = 0;
    //  Frame format: MSB is transmitted first.
    SPI_CR1_LSBFIRST = 0;
    //  Baud Rate Control:  Fcpu/256 (62,500 baud). 
    SPI_CR1_BR = 7;
    //  Clock Phase: first clock transition is the first data capture edge.
    SPI_CR1_CPHA = 0;
    //  Clock Polarity: SCK to 0 when idle.
    SPI_CR1_CPOL = 0;
    //  Slave configuration
    SPI_CR1_MSTR = 0;
    //  Bidirectional data mode enable: 2-line unidirectional data mode.
    SPI_CR2_BDM = 0;
    //  Full-duplex.
    SPI_CR2_RXONLY = 0;
    //  Slave management performed by software disabled.
    SPI_CR2_SSM = 0;         
    //  Slave mode.
    SPI_CR2_SSI = 0;
    //  Enable the SPI RXE interrupt.
    SPI_ICR_RXIE = 1;                   
    //  Enable SPI.
    SPI_CR1_SPE = 0;

    return;
}

void setup_interrupts_sensors (uint8_t _state) {
    //  Disable/Enable external interrupts. 
    PC_CR2_C22 = _state;
    PC_CR2_C21 = _state;
    //  Interrupt on falling edge
    EXTI_CR1_PCIS = 2; 

    return;
}


void send_byte (uint8_t byte){  
    while (!SPI_SR_TXE); //  Transmit buffer is empty.
    SPI_DR = byte;
    while (!SPI_SR_TXE); //  Wait for complete transmission.
}

uint16_t read_cs (void) { 
    //  Start conversion.
    ADC_CR1_ADON = 1;
    //  Wait for end of conversion.
    while(ADC_CSR_EOC == 0);
    //  Clear flag "End of conversion".
    ADC_CSR_EOC = 0; 
    
    //  Left aligned
    return  ((ADC_DRH << 2) | (ADC_DRL >> 6));
}

void InitialiseUART(void)
{
    //
    //  Clear the Idle Line Detected bit in the status rerister by a read
    //  to the UART1_SR register followed by a Read to the UART1_DR register.
    //
    unsigned char tmp = UART1_SR;
    tmp = UART1_DR;
    //
    //  Reset the UART registers to the reset values.
    //
    UART1_CR1 = 0;
    UART1_CR2 = 0;
    UART1_CR4 = 0;
    UART1_CR3 = 0;
    UART1_CR5 = 0;
    UART1_GTR = 0;
    UART1_PSCR = 0;
    //
    //  Now setup the port to 115200,n,8,1.
    //
    UART1_CR1_M = 0;        //  8 Data bits.
    UART1_CR1_PCEN = 0;     //  Disable parity.
    UART1_CR3_STOP = 0;     //  1 stop bit.
    UART1_BRR2 = 0x0a;      //  Set the baud rate registers to 115200 baud
    UART1_BRR1 = 0x08;      //  based upon a 16 MHz system clock.
    //
    //  Disable the transmitter and receiver.
    //
    UART1_CR2_TEN = 0;      //  Disable transmit.
    UART1_CR2_REN = 0;      //  Disable receive.
    //
    //  Set the clock polarity, lock phase and last bit clock pulse.
    //
    UART1_CR3_CPOL = 1;
    UART1_CR3_CPHA = 1;
    UART1_CR3_LBCL = 1;
    //
    //  Turn on the UART transmit, receive and the UART clock.
    //
    UART1_CR2_TEN = 1;
    UART1_CR2_REN = 1;
    UART1_CR3_CKEN = 1;
}

//  Send the message in the string to UART1.
void UARTPrintf(char *message)
{
    char *ch = message;
    while (*ch)
    {
        UART1_DR = (unsigned char) *ch;     //  Put the next character into the data transmission register.
        while (UART1_SR_TXE == 0);          //  Wait for transmission to complete.
        ch++;                               //  Grab the next character.
    }
}

void InitialiseUserButton (void){
  //  Button USER  is set to input mode.
  PE_DDR_DDR4 = 0;
  //  Button USER is set to floating inpit.
  PE_CR1_C14  = 1;
  //  Enaable external interrupt.
  PE_CR2_C24  = 1;
  //  Interrupt on falling edge
  EXTI_CR2_PEIS  = 1;
}

void simulate_hall_sensor (void) {
    PA_DDR_DDR3 = 1;
    PD_DDR_DDR0 = 1;
    PA_CR1_C13  = 1;
    PD_CR1_C10  = 1;
    PA_CR2_C23  = 1;
    PD_CR2_C20  = 1;
    
    //  Reset Timer 3 to a known state.
    TIM3_CR1    = 0x00;               
    TIM3_IER    = 0x00;
    TIM3_SR1    = 0x00;
    TIM3_SR2    = 0x00;
    TIM3_EGR    = 0x00;
    TIM3_CCER1  = 0x00;
    TIM3_CCMR1  = 0x00;
    TIM3_CCMR2  = 0x00;
    TIM3_CNTRH  = 0x00;
    TIM3_CNTRL  = 0x00;
    TIM3_PSCR   = 0x00;
    TIM3_ARRH   = 0x00;
    TIM3_ARRL   = 0x00;
    TIM3_CCR1H  = 0x00;
    TIM3_CCR1L  = 0x00;
    TIM3_CCR2H  = 0x00;
    TIM3_CCR2L  = 0x00;

    
        //  Set prescaler to 1.
    TIM3_PSCR = 0x03;
    //  Fill 16 bit timer3_arr to two 8 bit registers.
    TIM3_ARRH = 0x4A;
    TIM3_ARRL = 0x68;
    
    //  Fill 16 bit timer3_ccr1 to two 8 bit registers.
    TIM3_CCR1H = 0x25;
    TIM3_CCR1L = 0x34;
    //  Fill 16 bit timer3_ccr1 to two 8 bit registers.
    TIM3_CCR2H = 0x25;
    TIM3_CCR2L = 0x34;

    //  Active is defined as high.
    TIM3_CCER1_CC1P = 0;
    TIM3_CCER1_CC2P = 0;
    // Enable compare mode for channel 1 and 2
    TIM3_CCER1_CC1E = 1;
    TIM3_CCER1_CC2E = 1;    
    //  Output is enable.
    TIM3_CCMR1_OC1PE = 1;
    TIM3_CCMR2_OC2PE = 1;
        
    //  Enable PWM mode 1 (0b110 = 6) in channel 1
    TIM3_CCMR1_OC1M = 6;
    //  Enable PWM mode 1 (0b111 = 7) in channel 2
    TIM3_CCMR2_OC2M = 6;
    


    // Enable counter.
    TIM3_CR1_CEN = 1;



    return;
}
