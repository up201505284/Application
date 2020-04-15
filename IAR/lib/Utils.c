#include "C:\Users\riban\OneDrive\Ambiente de Trabalho\IAR\lib\Utils.h"
#include "C:\Users\riban\OneDrive\Ambiente de Trabalho\IAR\lib\ControlUnit.h"


void init_clock(void) {
    //  Enable high speed internal oscillator
        //  Enable MVR regulator in Active-halt mode.
        //  Disable the LSI.
        //  Disable fast wakeup from Halt/Active-halt modes.
        //  Enable the HSI.
    CLK_ICKR          = 0x01;                    
  
    while (CLK_ICKR_HSIRDY == 0); //  Wait for the HSI to be ready for use.
   
    CLK_ECKR         = 0x00; //  Disable the external clock.
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
    //  Initialise outputs 
        //  INA     -> PD5
        //  INB     -> PD6
        //  SEL0    -> PE0
        //  PWM     -> PC1 -> TIM1_CH1

    //  Pin is set to output mode.
    PC_DDR_DDR1 = 1; 
    PD_DDR_DDR5 = 1; 
    PD_DDR_DDR6 = 1;
    PE_DDR_DDR0 = 1;
    //  Pin is set to Push-Pull mode.
    PC_CR1_C11  = 1;
    PD_CR1_C15  = 1;
    PD_CR1_C16  = 1;
    PE_CR1_C10  = 1;
    // Pin can run up to 10MHz.
    PC_CR2_C21  = 1;
    PD_CR2_C25  = 1;
    PD_CR2_C26  = 1;
    PE_CR2_C20  = 1;

    //  Initialise inputs 
        //  HALL_S1    -> PG0  
        //  HALL_S1    -> PC2 
    //  Pin is set to input mode.
    PC_DDR_DDR2 = 0;
    PG_DDR_DDR0 = 0;
    //  Pin is set to input with pull-up.
    PC_CR1_C12 = 1;
    PG_CR1_C10 = 1;
    //  Disable external interrupt. 
    PC_CR2_C22 = 0;
    PG_CR2_C20 = 0;

    return;
}

void setup_adc (void) {
    //  ADC configuration
        //  Set prescaler division factor to 2.
        //  Single conversion mode.
    ADC_CR1 = 0x00;
        //  Disable external trigger.
        //  Set data alignment to left alignment.
        //  Disable scan mode.
    ADC_CR2 = 0x00;
        //  Disable data buffer.
    ADC_CR3 = 0x00;
        //  Select input channel 5 to be converted.
    ADC_CSR_CH = 5;  

    return;
}

void setup_pwm(uint8_t duty_cycle) {
  //  uint16_t TIMER1_ARR   = 800;
    //  Evaluate the limits for the duty cycle (0%-100%).
  //  if (duty_cycle > 100)
    //    return; 
    //  Set duty-cycle. 
    uint16_t timer1_ccr1 = 800*(duty_cycle/100)-1;

    //  Set prescaler to 1.
    TIM1_PSCRH = 0x00;
    TIM1_PSCRL = 0x00;
    
    //  Fill 16 bit timer2_arr to two 8 bit registers.
    TIM1_ARRH = (800 - 1) >> 8;
    TIM1_ARRL = (800 - 1) & 0x00FF;

    //  Fill 16 bit timer1_ccr1 to two 8 bit registers.
    TIM1_CCR1H = timer1_ccr1 >> 8;
    TIM1_CCR1L = timer1_ccr1 & 0x00FF;

    //  Output is enable.
    TIM1_CCMR1_OC1PE = 1;
    //  Active is defined as low.
    TIM1_CCER1_CC1P = 1;
    //  Enable PWM mode 1 (0b110 = 6).
    TIM1_CCMR1_OC1M = 6;
    // Enable counter.
    TIM2_CR1_CEN = 1;

    return;
}

void setup_spi(void) {
    //  SPI port init.
        //  MISO -> PC7 is push-pull out
    PC_DDR_DDR7 = 1; 
    PC_CR1_C17  = 1;
    PC_CR2_C27  = 1; 
        //  MOSI -> PC6 is pull-up in  
        //  SCK  -> PC5 is pull-up in
        //  SS   -> PD2 is pull-up in 
    PC_DDR_DDR6 = 0;
    PC_DDR_DDR5 = 0;
    PD_DDR_DDR2 = 0;
    PC_CR1_C16  = 1;
    PC_CR1_C15  = 1;
    PD_CR1_C12  = 1;
    PC_CR2_C26  = 0;
    PC_CR2_C25  = 0;
    PD_CR2_C22  = 0;

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
    PG_CR2_C20 = _state;
    //  Interrupt on falling edge
    EXTI_CR1_PCIS = 2; 

    return;
}


void send_byte (uint8_t byte){
    //  
    if (SPI_SR_TXE) { //  Transmit buffer is empty.
        SPI_DR = byte;
        while (!SPI_SR_TXE); //  Wait for complete transmission.
    }
}

uint16_t read_cs (void) {
    uint16_t low  = 0x0000;
    uint16_t high = 0x0000;
    
    //  Start conversion.
    ADC_CR1 |= ADC_CR1_ADON;
    //  Wait for end of conversion.
    while(ADC_CSR_EOC == 0);
    //  Clear flag "End of conversion".
    ADC_CSR &= ~ADC_CSR_EOC;
    //  Left aligned
    low  = (uint16_t) (ADC_DRH << 8);
    high = (uint16_t) ADC_DRL;
    
    return  low | high;
}




