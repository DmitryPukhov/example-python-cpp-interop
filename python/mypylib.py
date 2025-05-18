class MyPyLib:
    """This Python class will be available from C++"""
    
    def __init__(self, name: str):
        self.name = name
    
    def say_hello(self, name: str) -> str:
        """ This function will be called from C++"""

        hello = f"{self.name}: hello {name}!"
        return hello