# CMakeList.txt : CMake project for FinancialLibs, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("FinancialLibs" VERSION 0.1 DESCRIPTION "Financial Simulation Library written in C++")

add_subdirectory(Financial)

# Add source to this project's executable.
add_executable(rngtest "./tests/main.cpp" "Financial/walk/src/walk.cpp")
target_link_libraries(rngtest PUBLIC rng)
target_link_libraries(rngtest PUBLIC walk)
add_library(FinancialLibrary INTERFACE)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET rng PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
add_test(rngtest "./tests/main.cpp")