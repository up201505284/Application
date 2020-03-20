#ifndef LINEARACTUATOR_H
#define LINEARACTUATOR_H

#include "ControlSystem.h"
#include "LinearActuatorSpecifications.h"
#include "LinearActuatorStatus.h"

class LinearActuator {
    private:
        LinearActuatorSpecifications*   specifications;
        LinearActuatorStatus*           status;    
        ControlSystem*                  control;      
    public:
        // Constructor
        LinearActuator(
            LinearActuatorSpecifications*   _specifications,
            LinearActuatorStatus*           _status,
            ControlSystem*                  _control   
        );

        // Destructor
        ~LinearActuator();

        // "Set" methods
        void setSpecifications  (LinearActuatorSpecifications*  _specifications );
        void setStatus          (LinearActuatorStatus*          _status         );
        void setControl         (ControlSystem*                 _control         );


        // "Get" methods
        LinearActuatorSpecifications*   getSpecifications   (void);
        LinearActuatorStatus*           getStatus           (void);
        ControlSystem*                  getControl          (void); 
    };

#endif // LINEARACTUATOR_H