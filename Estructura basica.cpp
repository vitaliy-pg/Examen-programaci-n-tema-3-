#include <map>
#include <string>
#include <stdexcept>    //para el manejo de excepciones
#include <iostream>
#include <variant>
class Variant {

public:
    using Value = std::variant<int, float, std::string>;


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
    size_t size() const {
        return symbolTable.size();
    }
    void clear() {
        symbolTable.clear();
    }

};

int main(){
    try {
        Environment env;

        env.insert("player_health", Variant(100));
        env.insert("player_position", Variant("0,0"));

        std::cout << "Estado inicial del entorno:\n";
        env.printEnvironment();

        env.insert("player_health", Variant(80));

        if (env.exists("player_health")) {
            Variant health;
            env.lookup("player_health", health);
            std::cout << "La salud del jugador es: " << health.getIntValue() << "\n";
        } else {
            std::cout << "El símbolo 'player_health' no existe en el entorno.\n";
        }

        env.remove("player_position");

        std::cout << "\nEstado final del entorno:\n";
        env.printEnvironment();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }




    return 0;


}