#include "LinearActuator.h"

LinearActuator::LinearActuator(
            LinearActuatorSpecifications*   _specifications ,
            LinearActuatorStatus*           _status         ,
            ControlSystem*                  _control) {
     
    LinearActuator::setSpecifications   (_specifications);
    LinearActuator::setStatus           (_status);
    LinearActuator::setControl          (_control); 

}

LinearActuator::~LinearActuator(){
}

void LinearActuator::setSpecifications(LinearActuatorSpecifications* _specifications) {
    specifications = _specifications;
}

void LinearActuator::setStatus(LinearActuatorStatus* _status) {
    status = _status;
}

void LinearActuator::setControl(ControlSystem* _control) {
    control = _control;
}

LinearActuatorSpecifications* LinearActuator::getSpecifications (void) {
    return specifications;
}

LinearActuatorStatus* LinearActuator::getStatus (void) {
    return status;
}

ControlSystem* LinearActuator::getControl (void) {
    return control;
}