cmake_minimum_required(VERSION 3.30)
project(CrucibleShaderBundler)

set(CMAKE_CXX_STANDARD 20)
find_package(Boost REQUIRED COMPONENTS program_options)
add_executable(CrucibleShaderBundler
        src/main.cpp)
target_link_libraries(CrucibleShaderBundler PRIVATE Boost::program_options)
