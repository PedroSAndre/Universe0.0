#include <SFML/Graphics.hpp>
#include <iostream>
#include "main.hpp"
#include "input_read.hpp"
#include "graphics_handler.hpp"
#include "main_logic.hpp"

int main(int argc, char** argv){
    InputArgs input_args = readInputArgs(argc, argv);
    bool is_running = false;

    sf::Event event{};
    sf::Clock clock;
    sf::Vector2i local_mouse_position;

    std::vector<std::vector<Cell>> cells(input_args.blocks_x, std::vector<Cell>(input_args.blocks_y));

    sf::RenderWindow window(sf::VideoMode(input_args.pixels_x, input_args.pixels_y), "Universe0.0", sf::Style::Titlebar | sf::Style::Close);
    updateWindow(window, input_args, cells);

    while (window.isOpen()) {
        window.pollEvent(event);
        switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if(event.key.code == sf::Keyboard::Space){
                    is_running = !is_running;
                    clock.restart();
                }
                else if(event.key.code == sf::Keyboard::Right){
                    input_args.time_between_iteration += 50;
                    std::cout << "New iteration every: " << input_args.time_between_iteration << "ms" << std::endl;
                    clock.restart();
                }
                else if(event.key.code == sf::Keyboard::Left){
                    input_args.time_between_iteration += -50;
                    if(input_args.time_between_iteration <= 0){
                        input_args.time_between_iteration = 50;
                    }
                    std::cout << "New iteration every: " << input_args.time_between_iteration << "ms" << std::endl;
                    clock.restart();
                }
                event.type=sf::Event::MouseLeft;
                break;
            case sf::Event::MouseButtonPressed:
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    local_mouse_position = sf::Mouse::getPosition(window);
                    addCell(cells, local_mouse_position, input_args);
                    updateWindow(window, input_args, cells);
                }
                event.type=sf::Event::MouseLeft;
                break;
            default:
                break;
        }
        if(is_running){
            if(clock.getElapsedTime().asMilliseconds() > input_args.time_between_iteration){
                iterationStep(cells);
                updateWindow(window, input_args, cells);
                clock.restart();
            }
        }
    }

    return 0;
}