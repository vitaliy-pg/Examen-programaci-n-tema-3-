#include <map>
#include <string>
#include "Variant.h"#include <map>

Class Environment
{
    private :
        std::map<std::string, Variant> symbolTable;
public :
    Environment() {

}

    void setVariable(const std::string& name, const Variant& value) {
        symbolTable[name] = value;
    }

