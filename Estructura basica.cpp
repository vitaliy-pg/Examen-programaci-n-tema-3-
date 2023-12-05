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

    std::string toString() const {
        switch (dataType) {
            case Type::Integer:
                return std::to_string(intValue);
            case Type::Float:
                return std::to_string(floatValue);
            case Type::String:
                return stringValue;
            default:
                return "Tipo de dato desconocido";
        }
    }
};


    Class Environment
        // Puedes realizar inicializaciones adicionales aquí si es necesario
{
    private :
        std::map<std::string, Variant> symbolTable;
    public :
    Environment() {}

    void insert(const std::string& name, const Variant& value) {
        auto result = symbolTable.insert({name, value});
        if (!result.second) {
            throw std::runtime_error("El símbolo '" + name + "' ya existe en el entorno.");
        }
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

    void remove(const std::string& name) {
        auto it = symbolTable.find(name);
        if (it != symbolTable.end()) {
            symbolTable.erase(it);
        } else {
            throw std::runtime_error("El símbolo '" + name + "' no existe en el entorno y no se puede eliminar.");
        }
    }

    bool exists(const std::string& name) const {
        return symbolTable.find(name) != symbolTable.end();
    }

    void printEnvironment() const {
        for (const auto& entry : symbolTable) {
            std::cout << entry.first << ": " << entry.second.toString() << std::endl;
        }
    }
};

int main(){
    try {
    Environment env;


        // Insertar símbolos en el entorno
        env.insert("x", Variant(10));
        std::cout << "Símbolo 'x' insertado con éxito.\n";
        env.insert("x", Variant(20));
        std::cout << "Símbolo 'x' insertado con éxito.\n";  // Este mensaje no se imprimirá debido a la excepción

     catch (const std::exception& e) {
        std::cerr << "Error al insertar símbolo: " << e.what() << std::endl;
    }



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