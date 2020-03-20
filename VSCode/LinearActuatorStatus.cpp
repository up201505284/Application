#include <iostream>
#include "LinearActuatorStatus.h"

using namespace std;

LinearActuatorStatus::LinearActuatorStatus() {
    LinearActuatorStatus::setLinearSpeed(0);
    LinearActuatorStatus::setRotorSpeed(0);
    LinearActuatorStatus::setPosition(0);
    LinearActuatorStatus::setState("Stop");
}

LinearActuatorStatus::~LinearActuatorStatus() {
}

void LinearActuatorStatus::setLinearSpeed(float _linearSpeed) {
    linearSpeed = _linearSpeed;
}

void LinearActuatorStatus::setRotorSpeed(float _rotorSpeed) {
    rotorSpeed = _rotorSpeed;    
}

void LinearActuatorStatus::setPosition(float _position) {
    if (_position >= 0)
        position = _position;
    else // Error
        printf("INVALID VALUE \n");
}

void LinearActuatorStatus::setState(string _state) {
    if (_state == "Stop" || _state == "In extended" || _state == "In refracted")
        state = _state;
    else // Error
        printf("INVALID VALUE \n");
}

float LinearActuatorStatus::getLinearSpeed(void){
    return linearSpeed;
}

float LinearActuatorStatus::getRotorSpeed(void){
    return rotorSpeed;
}

float LinearActuatorStatus::getPosition(void){
    return position;
}

string LinearActuatorStatus::getState(void){
    return state;
}