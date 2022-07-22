#ifndef UNIVERSE0_0_MAIN_LOGIC_HPP
#define UNIVERSE0_0_MAIN_LOGIC_HPP
#include "main.hpp"
#include <vector>
#include <SFML/Graphics.hpp>

void addCell(std::vector<std::vector<Cell>>& cells, const sf::Vector2i& local_mouse_position, const InputArgs& input_args);
void iterationStep(std::vector<std::vector<Cell>>& cells);
#endif //UNIVERSE0_0_MAIN_LOGIC_HPP
