#ifndef _UTILS_H_
#define _UTILS_H_

#include <iostm8s208rb.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <intrinsics.h>


void            init_clock              (void               );
void            init_ports              (void               );
void            setup_adc               (void               );
void            setup_spi               (void               );
void            setup_pwm               (uint8_t duty_cycle );
void            setup_interrupts_sensors(uint8_t _state     );
uint16_t        read_cs                 (void               );
void            send_byte               (uint8_t byte       ); 
void            UARTPrintf              (char *message      );
void            InitialiseUART          (void               );
void            InitialiseUserButton    (void               );
void            simulate_hall_sensor    (void               );


#endif //  _UTILS_H_