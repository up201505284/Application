#include "LinearActuator.h"

LinearActuator::LinearActuator(
            LinearActuatorSpecifications*   _specifications ,
            LinearActuatorStatusAdvanced*   _statusAdvanced ,
            LinearActuatorStatusBasic*      _statusBasic    ,
            ControlSystem*                  _control        ,
            Connection*                     _connection     ) {
     
    setSpecifications   (_specifications);
    setStatusBasic      (_statusBasic   );
    setStatusAdvanced   (_statusAdvanced);
    setControl          (_control       ); 
    setConnection       (_connection    );

}

LinearActuator::~LinearActuator(){
}

void LinearActuator::setSpecifications(LinearActuatorSpecifications* _specifications) {
    specifications = _specifications;
}

void LinearActuator::setStatusBasic(LinearActuatorStatusBasic* _statusBasic) {
    statusBasic = _statusBasic;
}

void LinearActuator::setStatusAdvanced(LinearActuatorStatusAdvanced* _statusAdvanced) {
    statusAdvanced = _statusAdvanced;
}

void LinearActuator::setControl(ControlSystem* _control) {
    control = _control;
}

void LinearActuator::setConnection(Connection* _connection) {
    connection = _connection;
}

LinearActuatorSpecifications* LinearActuator::getSpecifications (void) {
    return specifications;
}

LinearActuatorStatusBasic* LinearActuator::getStatusBasic (void) {
    return statusBasic;
}

LinearActuatorStatusAdvanced* LinearActuator::getStatusAdvanced (void) {
    return statusAdvanced;
}

ControlSystem* LinearActuator::getControl (void) {
    return control;
}

Connection* LinearActuator::getConnection (void) {
    return connection;
}
