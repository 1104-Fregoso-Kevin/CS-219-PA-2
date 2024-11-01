#include "Read.h"
#include "Operations.h"
#include <iostream>
#include <fstream>
#include <iomanip>

Read::Read() 
{
    operation = "none";
    operand_1 = 0x0;
    operand_2 = 0x0;
}

Read::Read(std::string o, uint32_t op1, uint32_t op2) 
{
    operation = o;
    operand_1 = op1;
    operand_2 = op2;
}

Read::Read(const Read& rhs) 
{
    operation = rhs.operation;
    operand_1 = rhs.operand_1;
    operand_2 = rhs.operand_2;
}

std::string Read::get_operation() const 
{ 
    return operation; 
}
uint32_t Read::get_operand_1() const 
{ 
    return operand_1;
}
uint32_t Read::get_operand_2() const 
{ 
    return operand_2; 
}

bool Read::readFromFile(const std::string& filename) 
{
    std::ifstream file(filename);
    if (!file.is_open()) 
    { 
        std::cerr << "Error reading file" << std::endl;
        return false; 
    }

    Operations opObj;
    while (file >> operation >> std::hex >> operand_1) 
    {
        if (operation == "NOT" || operation == "NOTS") 
        {
            uint32_t result = opObj.not_op(operand_1);
            std::cout << operation << " 0x" << std::hex << operand_1 << " = 0x" << result << std::endl;
            std::cout << "N: <" << opObj.get_flags().getN() << "> Z: <" << opObj.get_flags().getZ() << ">" << std::endl;
        } 
        else 
        {
            file >> operand_2;
            uint32_t result = 0;
            if (operation == "ADD" || operation == "ADDS") 
            {
                result = opObj.add(operand_1, operand_2);
                std::cout << operation << " 0x" << std::hex << operand_1 << " 0x" << std::hex << operand_2 << " = 0x" << std::hex << result << std::endl;
                std::cout << "N: <" << opObj.get_flags().getN() << "> Z: <" << opObj.get_flags().getZ() << ">" << std::endl;
            } 
            else if (operation == "AND" || operation == "ANDS") 
            {
                result = opObj.and_op(operand_1, operand_2);
                std::cout << operation << " 0x" << std::hex << operand_1 << " 0x" << std::hex << operand_2 << " = 0x" << std::hex << result << std::endl;
                std::cout << "N: <" << opObj.get_flags().getN() << "> Z: <" << opObj.get_flags().getZ() << ">" << std::endl;
            } 
            else if (operation == "ORR" || operation == "ORRS") 
            {
                result = opObj.orr(operand_1, operand_2);
                std::cout << operation << " 0x" << std::hex << operand_1 << " 0x" << std::hex << operand_2 << " = 0x" << std::hex << result << std::endl;
                std::cout << "N: <" << opObj.get_flags().getN() << "> Z: <" << opObj.get_flags().getZ() << ">" << std::endl;
            } 
            else if (operation == "XOR" || operation == "XORS") 
            {
                result = opObj.xor_op(operand_1, operand_2);
                std::cout << operation << " 0x" << std::hex << operand_1 << " 0x" << std::hex << operand_2 << " = 0x" << std::hex << result << std::endl;
                std::cout << "N: <" << opObj.get_flags().getN() << "> Z: <" << opObj.get_flags().getZ() << ">" << std::endl;
            } 
            else if (operation == "SUB" || operation == "SUBS") 
            {
                result = opObj.sub(operand_1, operand_2);
                std::cout << operation << " 0x" << std::hex << operand_1 << " 0x" << std::hex << operand_2 << " = 0x" << std::hex << result << std::endl;
                std::cout << "N: <" << opObj.get_flags().getN() << "> Z: <" << opObj.get_flags().getZ() << ">" << std::endl;
            } 
            else if (operation == "ASR" || operation == "ASRS") 
            {
                result = opObj.asr(operand_1, operand_2);
                std::cout << operation << " 0x" << std::hex << operand_1 << " >> " << std::dec << operand_2 << " = 0x" << std::hex << result << std::endl;
                std::cout << "N: <" << opObj.get_flags().getN() << "> Z: <" << opObj.get_flags().getZ() << ">" << std::endl;
            } 
            else if (operation == "LSR" || operation == "LSRS") 
            {
                result = opObj.lsr(operand_1, operand_2);
                std::cout << operation << " 0x" << std::hex << operand_1 << " >> " << std::hex << operand_2 << " = 0x" << std::hex << result << std::endl;
                std::cout << "N: <" << opObj.get_flags().getN() << "> Z: <" << opObj.get_flags().getZ() << ">" << std::endl;
            } 
            else if (operation == "LSL" || operation == "LSLS") 
            {
                result = opObj.lsl(operand_1, operand_2);
                std::cout << operation << " 0x" << std::hex << operand_1 << " << " << std::hex << operand_2 << " = 0x" << std::hex << result << std::endl;
                std::cout << "N: <" << opObj.get_flags().getN() << "> Z: <" << opObj.get_flags().getZ() << ">" << std::endl;
            }
        }
    }
    file.close();
    return true;
}