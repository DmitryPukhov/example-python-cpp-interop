# Import c++ unmanaged library
from mylib import MyLib

# Instantiate c++ object
mylib = MyLib("Cpp lib")

# Python -> c++ call
cpp_response = mylib.say_hello("Python main")
print(cpp_response)

# Python -> c++ -> python call
cpp_response = mylib.talk_to_python("Python main")
print(cpp_response)
