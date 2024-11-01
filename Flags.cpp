#include "Flags.h"

Flags::Flags()
{
    N=false;
    Z=false;
}
bool Flags::getN() const 
{
    return N;
}

bool Flags::getZ() const 
{
    return Z;
}
void Flags::update(uint32_t result)
{
    N = (result & (1U << 31)) != 0;  
    Z = (result == 0);               
}