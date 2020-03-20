#include "ControlSystem.h"

ControlSystem::ControlSystem() {
}

ControlSystem::~ControlSystem() {
}

void ControlSystem::setAccelarationRate(float _accelarationRate) {
    accelarationRate = _accelarationRate;
}

void ControlSystem::setAccelarationTime(float _accelarationTime) {
    accelarationTime = _accelarationTime;
}

void ControlSystem::setPwmFrequency(int _pwmFrequency) {
    pwmFrequency = _pwmFrequency;
}

float ControlSystem::getAccelarationRate(void) {
    return accelarationRate;
}

float  ControlSystem::getAccelarationTime(void) {
    return accelarationTime;
}

int ControlSystem::getPwmFrequency(void) {
    return pwmFrequency;
}