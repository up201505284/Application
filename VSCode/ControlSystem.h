#ifndef CONTROLSYSTEM_H
#define CONTROLSYSTEM_H

class ControlSystem
{
private:
    float accelarationRate  ; // 4.1 mm/s²
    float accelarationTime  ; // 1.4 s
    int   pwmFrequency      ; // 25kHz

public:
    // Constructor
    ControlSystem();

    // Destructor
    ~ControlSystem();

    // "Set" Methods
    void setAccelarationRate(float _accelarationRate_)  ;
    void setAccelarationTime(float _accelarationRate_)  ;
    void setPwmFrequency    (int _pwmFrequency)         ;

     // "Get" Methods
    float   getAccelarationRate (void);
    float   getAccelarationTime (void);
    int     getPwmFrequency     (void);
};



#endif // CONTROLSYSTEM_H