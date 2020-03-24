#include <iostream>
#include "LinearActuatorStatusAdvanced.h"

using namespace std;

LinearActuatorStatusAdvanced::LinearActuatorStatusAdvanced() {
    LinearActuatorStatusAdvanced::setMotorCurrent(0);
    LinearActuatorStatusAdvanced::setState("In initial setup");
    LinearActuatorStatusAdvanced::setLinearSpeed(0);
    LinearActuatorStatusAdvanced::setRotorSpeed(0);
    LinearActuatorStatusAdvanced::setPosition(0);
}

LinearActuatorStatusAdvanced::~LinearActuatorStatusAdvanced() {
}

void LinearActuatorStatusAdvanced::setMotorCurrent(float _motorCurrent) {
    motorCurrent = _motorCurrent;
}

void LinearActuatorStatusAdvanced::setLinearSpeed(float _linearSpeed) {
    linearSpeed = _linearSpeed;
}

void LinearActuatorStatusAdvanced::setRotorSpeed(float _rotorSpeed) {
    rotorSpeed = _rotorSpeed;    
}

void LinearActuatorStatusAdvanced::setPosition(float _position) {
    if (_position >= 0)
        position = _position;
    else // Error
        printf("INVALID VALUE \n");
}

void LinearActuatorStatusAdvanced::setState(string _state) {
    if (_state == "Stop" || _state == "In extended" || _state == "In refracted" || _state == "In inital setup")
        state = _state;
    else // Error
        printf("INVALID VALUE \n");
}

float LinearActuatorStatusAdvanced::getMotorCurrent(void){
    return motorCurrent;
}

string LinearActuatorStatusAdvanced::getState(void){
    return state;
}

float LinearActuatorStatusAdvanced::getLinearSpeed(void){
    return linearSpeed;
}

float LinearActuatorStatusAdvanced::getRotorSpeed(void){
    return rotorSpeed;
}

float LinearActuatorStatusAdvanced::getPosition(void){
    return position;
}
