#ifndef LINEARACTUATORSTATUSADVANCED_H
#define LINEARACTUATORSTATUSADVANCED_H

#include <iostream>

using namespace std;

class LinearActuatorStatusAdvanced {

    private:
        float    motorCurrent   ; // 4.5 A
        float    linearSpeed    ; // 4,7 mm/s
        float    rotorSpeed     ; // 4500 rad/s
        float    position       ; // 0.0 mm
        string   state          ; // Stop/In extended/In refracted/In inital setup

    public:
        // Constructor
        LinearActuatorStatusAdvanced();

        // Destructor
        ~LinearActuatorStatusAdvanced();

        // "Set" Methods
        void setLinearSpeed (float  _linearSpeed    );
        void setRotorSpeed  (float  _rotorSpeed     );
        void setPosition    (float  _position       );
        void setMotorCurrent(float  _motorCurrent   );
        void setState       (string _state          );    


        // "Get" Methods
        float   getLinearSpeed  (void);
        float   getRotorSpeed   (void);
        float   getPosition     (void);
        float   getMotorCurrent (void);
        string  getState        (void);

};

#endif // LINEARACTUATPRSTATUSADVANCED_H