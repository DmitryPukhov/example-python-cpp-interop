cmake_minimum_required(VERSION 3.12)
SET(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

project(MyCppModule)

find_package(PythonLibs REQUIRED)
find_package(Boost REQUIRED COMPONENTS python)

file(GLOB_RECURSE SOURCES "src/*.cpp" "include/*.hpp")

add_library(mylib SHARED ${SOURCES})
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(mylib PRIVATE -g -O0)
endif()
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -fPIC -ggdb3 -fno-inline -fno-omit-frame-pointer")
set(CMAKE_SHARED_LINKER_FLAGS_DEBUG "-g -Wl,--no-as-needed")

target_include_directories(mylib PRIVATE ${PYTHON_INCLUDE_DIRS} "src" "include")
target_link_libraries(mylib ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})

set_target_properties(mylib PROPERTIES 
    PREFIX ""
    OUTPUT_NAME "mylib"  # Important for Python import
)