
#ifndef FLAGS_H
#define FLAGS_H

#include <cstdint>

class Flags 
{
    
    bool N;  
    bool Z;  
    public:
    Flags();
    bool getN() const ;
    bool getZ() const;
    void update(uint32_t result);
};

#endif