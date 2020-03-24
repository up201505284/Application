#ifndef LINEARACTUATORSPECIFICATIONS_H
#define LINEARACTUATORSPECIFICATIONS_H

#include <iostream>

using namespace std;

class LinearActuatorSpecifications {
    private:
        float   strokeLenght        ; // 450.0 mm
        float   maxCurrent          ; // 5.0 A
        int     maxLoadPush         ; // 5000 N
        int     maxLoadPull         ; // 3000 N 
        int     powerRating         ; // 24 V
        int     pulseRate           ; // 152 imp/mm
        int     dutyCycle           ; // 10%
        int     numberHallSensors   ; // 2    
        string  model               ; // TA31   

    public:
        // Constructor
        LinearActuatorSpecifications (
            float   _strokeLenght       , 
            float   _maxCurrent         , 
            float   _powerRating        , 
            int     _numberHallSensors  , 
            string  _model
        );   

        // Destructor
        ~LinearActuatorSpecifications();    
        
        // "set" Methods
        void setStrokeLenght        (float  _strokeLenght       );
        void setMaxCurrent          (float  _maxCurrent         );   
        void setMaxLoadPush         (int    _maxLoadPush        );
        void setMaxLoadPull         (int    _maxLoadPull        );        
        void setPowerRating         (int    _powerRating        );
        void setPulseRate           (int    _pulseRate          );
        void setDutyCycle           (int    _dutyCycle          );    
        void setNumberHallSensors   (int    _numberHallSensors  );
        void setModel               (string _model              );    


        // "get" Methods (void);  
        float   getStrokeLenght         (void);
        float   getMaxCurrent           (void);     
        int     getMaxLoadPush          (void);  
        int     getMaxLoadPull          (void);     
        int     getPowerRating          (void);  
        int     getPulseRate            (void);  
        int     getDutyCycle            (void);
        int     getNumberHallSensors    (void);
        string  getModel                (void);   
          
};

#endif // LINEARACTUATORSPECIFICATIONS_H