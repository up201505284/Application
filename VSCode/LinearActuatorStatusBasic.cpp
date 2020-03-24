#include <iostream>
#include "LinearActuatorStatusBasic.h"

using namespace std;

LinearActuatorStatusBasic::LinearActuatorStatusBasic() {
    LinearActuatorStatusBasic::setMotorCurrent(0);
    LinearActuatorStatusBasic::setState("Stop");
}

LinearActuatorStatusBasic::~LinearActuatorStatusBasic() {
}

void LinearActuatorStatusBasic::setMotorCurrent(float _motorCurrent) {
    motorCurrent = _motorCurrent;
}

void LinearActuatorStatusBasic::setState(string _state) {
    if (_state == "Stop" || _state == "In extended" || _state == "In refracted" || _state == "In inital setup")
        state = _state;
    else // Error
        printf("INVALID VALUE \n");
}

float LinearActuatorStatusBasic::getMotorCurrent(void){
    return motorCurrent;
}

string LinearActuatorStatusBasic::getState(void){
    return state;
}