#include "ControlSystem.h"

ControlSystem::ControlSystem(
    float   _accelarationRate,
    int     _accelarationTime
) {
    setAccelarationRate(_accelarationRate);
    setAccelarationTime(_accelarationTime);
}

ControlSystem::~ControlSystem() {
}

void ControlSystem::setAccelarationRate(float _accelarationRate) {
    accelarationRate = _accelarationRate;
}

void ControlSystem::setAccelarationTime(int _accelarationTime) {
    accelarationTime = _accelarationTime;
}

float ControlSystem::getAccelarationRate(void) {
    return accelarationRate;
}

int  ControlSystem::getAccelarationTime(void) {
    return accelarationTime;
}

