#include <iostream>
#include "LinearActuatorSpecifications.h"

using namespace std;

LinearActuatorSpecifications::LinearActuatorSpecifications(
    float   _strokeLenght       , 
    float   _maxCurrent         , 
    float   _powerRating        , 
    int     _numberHallSensors  , 
    string  _model              ) {

        setStrokeLenght     (_strokeLenght      );
        setMaxCurrent       (_maxCurrent        );
        setPowerRating      (_powerRating       );
        setNumberHallSensors(_numberHallSensors );
        setModel            (_model             );
}



LinearActuatorSpecifications::~LinearActuatorSpecifications() {
}

void LinearActuatorSpecifications::setStrokeLenght(float  _strokeLenght) {
    if (_strokeLenght > 0)
        strokeLenght = _strokeLenght;
    else // Error
        printf("INVALID VALUE \n");
}

void LinearActuatorSpecifications::setMaxCurrent(float  _maxCurrent) {
    if (_maxCurrent > 0)
        maxCurrent = _maxCurrent;
    else // Error
        printf("INVALID VALUE \n");
}

void LinearActuatorSpecifications::setMaxLoadPush(int  _maxLoadPush) {
    if (_maxLoadPush > 0)
        maxLoadPush = _maxLoadPush;
    else // Error
        printf("INVALID VALUE \n");
}

void LinearActuatorSpecifications::setMaxLoadPull(int  _maxLoadPull) {
    if (_maxLoadPull > 0)
        maxLoadPull = _maxLoadPull;
    else // Error
        printf("INVALID VALUE \n");}

void LinearActuatorSpecifications::setPowerRating(int  _powerRating) {
    if (_powerRating > 0)    
        powerRating = _powerRating;
    else // Error
        printf("INVALID VALUE \n");
}

void LinearActuatorSpecifications::setPulseRate(int  _pulseRate) {
    if (_pulseRate > 0)    
        pulseRate = _pulseRate;
    else // Error
        printf("INVALID VALUE \n");
}

void LinearActuatorSpecifications::setDutyCycle(int  _dutyCycle) {
    if (_dutyCycle > 0 && _dutyCycle <= 100)
        dutyCycle = _dutyCycle;
    else // Error
        printf("INVALID VALUE \n");
}

void LinearActuatorSpecifications::setNumberHallSensors(int _numberHallSensors) {
    numberHallSensors = _numberHallSensors;
}

void LinearActuatorSpecifications::setModel(string  _model) {
    model = _model;
}

float LinearActuatorSpecifications::getStrokeLenght(void) {
    return strokeLenght;
}

float LinearActuatorSpecifications::getMaxCurrent(void) {
    return maxCurrent;
}

int LinearActuatorSpecifications::getMaxLoadPush(void) {
    return maxLoadPush;
}

int LinearActuatorSpecifications::getMaxLoadPull(void) {
    return maxLoadPull;
}

int LinearActuatorSpecifications::getPowerRating(void) {
    return powerRating;
}

int LinearActuatorSpecifications::getPulseRate(void) {
    return pulseRate;
}

int LinearActuatorSpecifications::getDutyCycle(void) {
    return dutyCycle;
}

int LinearActuatorSpecifications::getNumberHallSensors(void) {
    return numberHallSensors;
}

string LinearActuatorSpecifications::getModel(void) {
    return model;
}
