#ifndef VARIABLE_HPP
#define VARIABLE_HPP

#include <string>

enum class VarType {
    String,
    Char,
    Num,
    Decimal,
    Array,
    List
};

struct Variable {
    VarType type;
    std::string value;
};

#endif