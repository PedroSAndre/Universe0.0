#define BACKGROUND_COLOR White

#include "graphics_handler.hpp"

void updateWindow(sf::RenderWindow& window, const InputArgs& input_args, const std::vector<std::vector<Cell>>& cells){
    window.clear(sf::Color::BACKGROUND_COLOR);

    sf::RectangleShape rectangle(sf::Vector2f((float)input_args.pixels_x_per_block, (float)input_args.pixels_y_per_block));
    rectangle.setOutlineThickness(1);
    rectangle.setOutlineColor(sf::Color::Black);

    for(unsigned int i = 0; i < cells.size(); i++){
        for(unsigned int j = 0; j < cells[i].size(); j++){
            if(cells[i][j].is_alive){
                rectangle.setFillColor(sf::Color::Yellow);
            }
            else {
                rectangle.setFillColor(sf::Color::BACKGROUND_COLOR);
            }
            rectangle.setPosition((float)(i*input_args.pixels_x_per_block), (float)(j*input_args.pixels_y_per_block));
            window.draw(rectangle);
        }
    }


    window.display();
}