find_package(Catch2 2 REQUIRED)
# создание исполняемого файла для программы тестирования
add_library(input ../src/input.h ../src/input.cpp)
add_library(operators ../src/operators.h ../src/operators.cpp)
add_library(simple_class ../src/simple_class.h ../src/simple_class.cpp)
add_library(class ../src/class.h ../src/class.cpp)

add_executable(func_testing testing.cpp)

target_link_libraries(func_testing input simple_class class operators Catch2::Catch2)
