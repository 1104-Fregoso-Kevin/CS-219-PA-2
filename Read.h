#ifndef READ_H
#define READ_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>

class Read 
{
    private:
    std::string operation;
    uint32_t operand_1;
    uint32_t operand_2;

    public:
    Read();
    Read(std::string, uint32_t, uint32_t);
    Read(const Read&);
    std::string get_operation() const;
    uint32_t get_operand_1() const;
    uint32_t get_operand_2() const;
    bool readFromFile(const std::string& filename);
};

#endif