#include <iostream>
#include "LinearActuatorSpecifications.h"
#include "LinearActuatorStatus.h"
#include "ControlSystem.h"

using namespace std;

int main(int argc, char *argv[]) {

    LinearActuatorSpecifications specifications;
    float   _strokeLenght; 
    float   _maxCurrent  ; 
    int     _maxLoadPush ;    
    int     _maxLoadPull ; 
    int     _powerRating ;     
    int     _pulseRate   ; 
    int     _dutyCycle   ;     
    string  _model       ;    

    std::cout << "----- Linear Actuator Specifications -----\n";

    std::cout << "Model\n";
    std::cin >> _model;
    specifications.setModel(_model);

    std::cout << "Duty Cycle\n";
    std::cin >> _dutyCycle;
    specifications.setDutyCycle(_dutyCycle);

    std::cout << "Power Rating\n";
    std::cin >> _powerRating;
    specifications.setPowerRating(_powerRating);

    std::cout << "Maximum load in push\n";
    std::cin >> _maxLoadPush;
    specifications.setMaxLoadPush(_maxLoadPush);

    std::cout << "Maximum load in pull\n";
    std::cin >> _maxLoadPull;
    specifications.setMaxLoadPull(_maxLoadPull);

    std::cout << "Maximum current\n";
    std::cin >> _maxCurrent;
    specifications.setMaxCurrent(_maxCurrent);

    std::cout << "Stroke lenght\n";
    std::cin >> _strokeLenght;
    specifications.setStrokeLenght(_strokeLenght);


    ControlSystem control;
    float _accelarationRate  ; 
    float _accelarationTime  ; 
    int   _pwmFrequency      ; 

    std::cout << "----- Setup of control system -----\n";

    std::cout << "Accelaration Rate\n";
    std::cin >> _accelarationRate;
    control.setAccelarationRate(_accelarationRate);

    std::cout << "Accelaration Time\n";
    std::cin >> _accelarationTime;
    control.setAccelarationTime(_accelarationTime);

    std::cout << "PWM Frequency\n";
    std::cin >> _pwmFrequency;
    control.setPwmFrequency(_pwmFrequency);


    LinearActuatorStatus status;
    std::cout << "----- Linear Actuator Status -----\n";  
    std::cout << "Linear speed: " << status.getLinearSpeed() << " mm/s\n";
    std::cout << "Rotor speed: " << status.getRotorSpeed() << " rad/s\n";
    std::cout << "Position: " << status.getPosition() << " mm\n";
    std::cout << "State: " << status.getState() << "\n";



}