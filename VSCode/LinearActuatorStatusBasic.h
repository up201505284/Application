#ifndef LINEARACTUATORSTATUSBASIC_H
#define LINEARACTUATORSTATUSBASIC_H

#include <iostream>

using namespace std;

class LinearActuatorStatusBasic {

    private:
        float    motorCurrent; // 4.5 A
        string   state      ; // Stop/In extended/In refracted/In inital setup

    public:
        // Constructor
        LinearActuatorStatusBasic();

        // Destructor
        ~LinearActuatorStatusBasic();

        // "Set" Methods
        void setMotorCurrent(float  _motorCurrent   );
        void setState       (string _state          );    


        // "Get" Methods
        float   getMotorCurrent (void);
        string  getState        (void);

};

#endif // LINEARACTUATPRSTATUSBASIC_H