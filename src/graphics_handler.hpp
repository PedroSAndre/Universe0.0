#ifndef UNIVERSE0_0_GRAPHICS_HANDLER_HPP
#define UNIVERSE0_0_GRAPHICS_HANDLER_HPP
#include <SFML/Graphics.hpp>
#include "main.hpp"

void updateWindow(sf::RenderWindow& window, const InputArgs& input_args, const std::vector<std::vector<Cell>>& cells);

#endif //UNIVERSE0_0_GRAPHICS_HANDLER_HPP
