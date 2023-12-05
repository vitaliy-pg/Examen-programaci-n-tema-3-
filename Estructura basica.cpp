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
    Variant getVariable(const std::string& name, const Variant& defaultValue = Variant()) const {
        auto it = symbolTable.find(name);
        if (it != symbolTable.end()) {
            return it->second;
        } else {
            return defaultValue;
        }
    }
    void executeScript(const std::string& script) {