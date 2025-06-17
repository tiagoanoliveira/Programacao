cmake_minimum_required(VERSION 3.15)
project(mt1_model)

# Define your common flags here
set(COMMON_FLAGS "-g -Wall -pedantic -Wuninitialized -Werror -fsanitize=address -fsanitize=undefined")
set(COMMON_CXX_FLAGS "-std=c++17")


# Apply the flags globally
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMMON_FLAGS} ${COMMON_CXX_FLAGS} ${EXTRA}")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${COMMON_FLAGS} ${EXTRA}")

# Add common linker flags
link_libraries(m)

# If you want to choose the compiler, when calling cmake use the following flags (clang in this case):
# cmake <path to CMakeLists.txt, usually ..> -D CMAKE_C_COMPILER=clang -D CMAKE_CXX_COMPILER=clang++ 


# Add one line for each executable using the command add_executable(<name> <sources>)

# You can uncomment the executables below as you progress
add_executable(word_count word_count.cpp)
add_executable(Airport Airport.cpp)
#add_executable(floatable floatable.cpp)
add_executable(print_grades print_grades.cpp)
add_executable(Hanoi Hanoi.cpp)