#ifndef LINEARACTUATORSTATUS_H
#define LINEARACTUATORSTATUS_H

#include <iostream>

using namespace std;

class LinearActuatorStatus {

    private:
        float    linearSpeed ; // 4,7 mm/s
        float    rotorSpeed  ; // 4500 rad/s
        float    position    ; // 0.0 mm
        string   state      ; // Stop/In extended/In refracted

    public:
        // Constructor
        LinearActuatorStatus();

        // Destructor
        ~LinearActuatorStatus();

        // "Set" Methods
        void setLinearSpeed (float  _linearSpeed)   ;
        void setRotorSpeed  (float  _rotorSpeed)    ;
        void setPosition    (float  _position)      ;
        void setState       (string _state)         ;    


        // "Get" Methods
        float   getLinearSpeed  (void);
        float   getRotorSpeed   (void);
        float   getPosition     (void);
        string  getState        (void);

};

#endif // LINEARACTUATPRSTATUS_H