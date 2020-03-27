#ifndef CONNECTION_H
#define CONNECTION_H

#include <iostream>

using namespace std;

class Connection
{
private:
    string  status  ; // 4.1 mm/s²
    int     channel ; // 1.4 s
    
public:
    // Constructor
    Connection(int _channel);

    // Destructor
    ~Connection();

    // "Set" Methods
    void setChannel (int    _channel            );
    void setStatus  (string _setStatus   );

     // "Get" Methods
    int     getChannel  (void);
    string  getStauts   (void);
};



#endif // CONNECTION_H
