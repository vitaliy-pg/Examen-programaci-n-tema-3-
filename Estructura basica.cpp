#include <map>
#include <string>
#include <iostream>
class Variant {
    // Implementación de la clase Variant
};

Class Environment
        // Puedes realizar inicializaciones adicionales aquí si es necesario
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

    bool insert(const std::string& name, const Variant& value) {
        auto result = symbolTable.insert({name, value});
        return result.second;
    }


    void executeScript(const std::string& script) {
        // Implementación de la ejecución del script, por ejemplo, interpretación de comandos
}

};

int main(){
    Environment env;

    if (env.insert("x", Variant(10))) {
        std::cout << "Símbolo 'x' insertado con éxito.\n";
    } else {
        std::cout << "El símbolo 'x' ya existe en el entorno.\n";
    }






}