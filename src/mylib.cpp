#include "mylib.hpp"
#include <boost/python.hpp>
#include <iostream>
#include <string>

namespace py = boost::python;

MyLib::MyLib(std::string name): name(name) {}

std::string MyLib::say_hello(const std::string& caller) {
    return name + ": Hello " + caller;
}; 

std::string MyLib::talk_to_python(const std::string&caller) {
    
    std::string python_name = "Python lib";
    // Calling python from c++ is more complicated than c++ from python
    // Create python class to be called
    py::object pymodule = py::import("mypylib");      
    py::object pyclass = pymodule.attr("MyPyLib");
    py::object pyinstance = pyclass(python_name);  // Constructor args
    py::object pyfunc = pyinstance.attr("say_hello");
    py::object result = pyfunc(name);

    // Call python class
    std::string python_response = py::extract<std::string>(result);

    // Resulted string from both c++ and python responses
    return name + ": Hello " + caller + "! Will talk to " + python_name + "\n" + python_response + "\n";
}

