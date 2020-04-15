
// Outputs
    //  INA     -> PD5
    //  INB     -> PD6
    //  SEL0    -> PE0     
    //  PWM     -> PC1       
#define INA                     PD_ODR_ODR5  
#define INB                     PD_ODR_ODR6  
#define SEL0                    PE_ODR_ODR0  
#define PWM                     PC_ODR_ODR1  

//  Inputs
    //  HALL_S1   -> PG0  
    //  HALL_S2   -> PC2
#define HALL_S1                 PG_IDR_IDR0
#define HALL_S2                 PC_IDR_IDR2

//  State of external interrupts
#define ENABLE                  1
#define DISABLE                 0

//  SPI Commands
#define DISCONNECTED()          0x00 
    //  Operation modes
#define INITIALSETUP()          0x01 
#define SAFERESET()             0x02  
#define BASIC()                 0x03 
#define ADVANCED()              0x04      
    //  Basic commands    
#define STOP()                  0x05
#define EXTENDED()              0x06
#define REFRACTED()             0x07

//  State Names
#define WAIT                    0x00 //  Communication between the control unit and the platform is off.
    //  Initial Setup
#define IS_STOP                 0x01 //  Stopped actuator.
#define IS_REFRACTED            0x02 //  Position the actuator in a fully refracted position.
#define IS_EXTENDED             0x03 //  Position the actuator in a fully extended position.
#define IS_SEND                 0x04 //  Sending pulse rate to central application throught SPI.
    //  Safe Reset 
#define SR_STOP                 0x05 //  Stopped actuator.
#define SR_REFRACTED            0x06 //  Position the actuator in a fully refracted position.
#define SR_SEND                 0x07 //  Sending sucessufully.
    //  Basic Commands 
#define B_STOP                  0x08 //  Stopped actuator.
#define B_REFRACTED             0x09 //  Put the actuator in refraction.
#define B_EXTENDED              0x0A //  Put the actuator in extension.
    //  Advanced Commands
#define A_STOP                  0x0B //  Stopped actuator.
#define A_REFRACTED             0x0C //  Put the actuator in refraction.
#define A_EXTENDED              0x0D //  Put the actuator in extension.
#define A_WAIT_SHIFT_R          0x0E //  Waiting to receive the shift value in the refracted moviment.
#define A_WAIT_SHIFT_E          0x0F //  Waiting to receive the shift value in the extension moviment.
#define A_SENDFULLYEXTENDED     0x10 //  Sending fully extended position.
#define A_SENDFULLYREFRACTED    0x11 //  Sending fully refracted position.
#define A_SENDPOSITION          0x12 //  Sending position.

//  Code for positions of all sensors
#define F_R_POSITION            0x0000 //  Fully refracted actuator
#define F_E_POSITION            0xFFFF //  Fully extended actuator