#include <string>

/**
 * Example of cpp class to call from python
 */
class MyLib {
public:
    MyLib(std::string name);
    /**
     * Receives the string, returns the string
     */
    std::string say_hello(const std::string& name);

    /**
     * Will call python class
     */
    std::string talk_to_python(const std::string&caller);    
private:
    std::string name;
};