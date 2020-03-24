#ifndef LINEARACTUATOR_H
#define LINEARACTUATOR_H

#include "ControlSystem.h"
#include "LinearActuatorSpecifications.h"
#include "LinearActuatorStatusBasic.h"
#include "LinearActuatorStatusAdvanced.h"
#include "Connection.h"

class LinearActuator {
    private:
        LinearActuatorSpecifications*   specifications  ;
        LinearActuatorStatusAdvanced*   statusAdvanced  ;
        LinearActuatorStatusBasic*      statusBasic     ;    
        ControlSystem*                  control         ;      
        Connection*                     connection      ;
    
    public:
        // Constructor
        LinearActuator(
            LinearActuatorSpecifications*   _specifications ,
            LinearActuatorStatusAdvanced*   _statusAdvanced ,
            LinearActuatorStatusBasic*      _statusBasic    ,
            ControlSystem*                  _control        ,
            Connection*                     _connection   
        );

        // Destructor
        ~LinearActuator();

        // "Set" methods
        void setSpecifications  (LinearActuatorSpecifications*  _specifications );
        void setStatusBasic     (LinearActuatorStatusBasic*     _statusBasic    );
        void setStatusAdvanced  (LinearActuatorStatusAdvanced*  _statusAdvanced );
        void setControl         (ControlSystem*                 _control        );
        void setConnection      (Connection*                    _connection     );


        // "Get" methods
        LinearActuatorSpecifications*   getSpecifications   (void);
        LinearActuatorStatusBasic*      getStatusBasic      (void);
        LinearActuatorStatusAdvanced*   getStatusAdvanced   (void);
        ControlSystem*                  getControl          (void); 
        Connection*                     getConnection       (void);
    };

#endif // LINEARACTUATOR_H