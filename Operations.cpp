#include "Operations.h"
#include <cstdint>

uint32_t Operations::add(uint32_t op1, uint32_t op2) 
{ 
    uint32_t result = op1 + op2;
    flags.update(result); 
    return result;
}

uint32_t Operations::and_op(uint32_t op1, uint32_t op2) 
{ 
    uint32_t result = op1 & op2;
    flags.update(result);
    return result;
}

uint32_t Operations::asr(uint32_t op1, uint32_t shift) 
{ 
    uint32_t result = static_cast<uint32_t>(op1) >> shift;
    flags.update(result);  
    return result;
}

uint32_t Operations::lsr(uint32_t op1, uint32_t shift) 
{ 
    uint32_t result = op1 >> shift;
    flags.update(result);  
    return result;
}

uint32_t Operations::lsl(uint32_t op1, uint32_t shift) 
{ 
    uint32_t result = op1 << shift;
    flags.update(result);  
    return result;
}

uint32_t Operations::not_op(uint32_t op1) 
{ 
    uint32_t result = ~op1;
    flags.update(result);  
    return result;
}

uint32_t Operations::orr(uint32_t op1, uint32_t op2) 
{ 
    uint32_t result = op1 | op2;
    flags.update(result);  
    return result;
}

uint32_t Operations::sub(uint32_t op1, uint32_t op2) 
{ 
    uint32_t result = op1 - op2;
    flags.update(result);  
    return result;
}

uint32_t Operations::xor_op(uint32_t op1, uint32_t op2) 
{ 
    uint32_t result = op1 ^ op2;
    flags.update(result);  
    return result;
}
Flags Operations::get_flags() const 
{ 
    return flags;
}
