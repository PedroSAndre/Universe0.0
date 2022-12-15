find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(Universe0.0 main.cpp input_read.cpp input_read.hpp main.hpp graphics_handler.cpp graphics_handler.hpp main_logic.cpp main_logic.hpp)
target_link_libraries(Universe0.0 sfml-graphics)