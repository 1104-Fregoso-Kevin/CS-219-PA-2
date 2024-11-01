#ifndef OPERATIONS_H
#define OPERATIONS_H
#include "Flags.h"

#include <cstdint>

class Operations 
{
    Flags flags;
    public:
    uint32_t add(uint32_t, uint32_t);
    uint32_t and_op(uint32_t, uint32_t);
    uint32_t asr(uint32_t, uint32_t);
    uint32_t lsr(uint32_t, uint32_t);
    uint32_t lsl(uint32_t, uint32_t);
    uint32_t not_op(uint32_t);
    uint32_t orr(uint32_t, uint32_t);
    uint32_t sub(uint32_t, uint32_t);
    uint32_t xor_op(uint32_t, uint32_t);
    Flags get_flags()const; 
};

#endif