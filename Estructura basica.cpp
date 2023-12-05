#include <map>
#include <string>
#include <stdexcept>    //para el manejo de excepciones
#include <iostream>
class Variant {
public:
    enum class Type {
        Integer,
        Float,
        String

};
private:
    Type dataType;

    union {
        int intValue;
        float floatValue;
        std::string stringValue;
    };
public:
    Variant() : dataType(Type::Integer), intValue(0) {}
    Variant(int value) : dataType(Type::Integer), intValue(value) {}
    Variant(float value) : dataType(Type::Float), floatValue(value) {}
    Variant(const std::string& value) : dataType(Type::String), stringValue(value) {}

    Type getType() const {
        return dataType;
    }
    int getIntValue() const {
        if (dataType == Type::Integer) {
            return intValue;
        } else {
            throw std::runtime_error("El Variant no contiene un valor entero.");
        }
    }
    float getFloatValue() const {
        if (dataType == Type::Float) {
            return floatValue;
        } else {
            throw std::runtime_error("El Variant no contiene un valor de punto flotante.");
        }
    }
    const std::string& getStringValue() const {
        if (dataType == Type::String) {
            return stringValue;
        } else {
            throw std::runtime_error("El Variant no contiene un valor de cadena.");
        }
    }


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

    try {
        // Insertar símbolos en el entorno
        env.insert("x", Variant(10));
        std::cout << "Símbolo 'x' insertado con éxito.\n";
        env.insert("x", Variant(20));
        std::cout << "Símbolo 'x' insertado con éxito.\n";  // Este mensaje no se imprimirá debido a la excepción

    } catch (const std::exception& e) {
        std::cerr << "Error al insertar símbolo: " << e.what() << std::endl;
    }


    try {
        // Buscar símbolos en el entorno
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
    } catch (const std::exception& e) {
        std::cerr << "Error al buscar símbolo: " << e.what() << std::endl;
    }


    return 0;


}