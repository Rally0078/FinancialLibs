﻿# CMakeList.txt : CMake project for FinancialLibs, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("FinancialLibs" VERSION 0.1 DESCRIPTION "Financial Simulation Library written in C++")

set(libsrc Financial/rng/src/rng.cpp Financial/walk/src/walk.cpp)
add_subdirectory(Financial)

# Add source to this project's executable.
add_library(FinancialLibrary STATIC ${libsrc})
target_link_libraries(FinancialLibrary PUBLIC rng)
target_link_libraries(FinancialLibrary PUBLIC walk)


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET rng PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed
add_subdirectory(tests)