project(rng)

add_library(${PROJECT_NAME} src/rng.cpp)

target_include_directories( ${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)