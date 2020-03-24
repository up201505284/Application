#ifndef CONTROLSYSTEM_H
#define CONTROLSYSTEM_H

class ControlSystem
{
private:
    float accelarationRate  ; // 4.1 mm/s²
    int accelarationTime  ; // 1.4 s
    
public:
    // Constructor
    ControlSystem(float _accelarationRate, int _accelarationTime);

    // Destructor
    ~ControlSystem();

    // "Set" Methods
    void setAccelarationRate(float _accelarationRate)   ;
    void setAccelarationTime(int _accelarationTime)     ;

     // "Get" Methods
    float   getAccelarationRate (void);
    int     getAccelarationTime (void);
};



#endif // CONTROLSYSTEM_H