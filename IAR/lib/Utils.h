#ifndef _UTILS_H_
#define _UTILS_H_

#include <iostm8s208rb.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>


//  Set PWM frequency to 20kHz.
    //  Fcpu = 16MHz
    //  Fcpu/Fpwm = TIMER1_ARR 
#define TIMER1_ARR   = 800;

void        init_clock              (void               );
void        init_ports              (void               );
void        setup_adc               (void               );
void        setup_spi               (void               );
void        setup_pwm               (uint8_t duty_cycle );
void        setup_interrupts_sensors(uint8_t _state     );
uint16_t    read_cs                 (void               );
void        send_byte               (uint8_t byte       ); 


#endif //  _UTILS_H_