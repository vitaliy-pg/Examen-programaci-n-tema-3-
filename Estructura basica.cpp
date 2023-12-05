#include <map>
#include <string>
#include <stdexcept>    //para el manejo de excepciones
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
    bool lookup(const std::string& name, Variant& result) const {
        auto it = symbolTable.find(name);
        if (it != symbolTable.end()) {
            result = it->second;
            return true;
        } else {
            return false;
        }
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
    Variant result;
    if (env.lookup("x", result)) {
        std::cout << "Símbolo 'x' encontrado. Valor: " << result.getIntValue() << std::endl;
    } else {
        std::cout << "El símbolo 'x' no existe en el entorno.\n";
    }
    if (env.lookup("y", result)) {
        std::cout << "Símbolo 'y' encontrado. Valor: " << result.getIntValue() << std::endl;
    } else {
        std::cout << "El símbolo 'y' no existe en el entorno.\n";
    }



return 0;


}