#include <boost/python.hpp>
#include "mylib.hpp"

/**
 * Describe cpp class to be available in python
 */
BOOST_PYTHON_MODULE(mylib) {
    using namespace boost::python;
    
    class_<MyLib>("MyLib", init<std::string>())
        .def("say_hello", &MyLib::say_hello)
        .def("talk_to_python", &MyLib::talk_to_python);
}