cmake_minimum_required(VERSION 3.16)

project(
    RecursiveAlgorithm
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(RecursiveAlgorithm
    input.hpp
    input.cpp
    main.cpp
    participant.hpp
    participant.cpp
)

include(GNUInstallDirs)
install(TARGETS RecursiveAlgorithm
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
