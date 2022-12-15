#define MAX_PIXELS_X 3840
#define MAX_PIXELS_Y 2160
#define MIN_PIXEL_PER_BLOCK_SIZE 3

#include <cstring>
#include <string>
#include <stdexcept>

#include "input_read.hpp"

InputArgs readInputArgs(int argc, char** argv){
    InputArgs input_args;

    for(int i=0; i < argc; i++){
        if(std::strcmp(argv[i], "-px") == 0){
            i++;
            input_args.pixels_x = static_cast<unsigned int>(std::stoi(argv[i]));
        }
        else if(std::strcmp(argv[i], "-py") == 0){
            i++;
            input_args.pixels_y = static_cast<unsigned int>(std::stoi(argv[i]));
        }
        else if(std::strcmp(argv[i], "-bx") == 0){
            i++;
            input_args.blocks_x = static_cast<unsigned int>(std::stoi(argv[i]));
        }
        else if(std::strcmp(argv[i], "-by") == 0){
            i++;
            input_args.blocks_y = static_cast<unsigned int>(std::stoi(argv[i]));
        }
    }

    if(input_args.pixels_x % input_args.blocks_x != 0 || input_args.pixels_y % input_args.blocks_y != 0){
        throw std::invalid_argument("Number of pixels cannot be divided by number of blocks");
    }

    input_args.pixels_x_per_block = input_args.pixels_x/input_args.blocks_x;
    input_args.pixels_y_per_block = input_args.pixels_y/input_args.blocks_y;

    checkInputArgs(input_args);

    return input_args;
}

void checkInputArgs(const InputArgs& input_args){
    if(input_args.pixels_x == 0 || input_args.pixels_x > MAX_PIXELS_X){
        throw std::invalid_argument("Cannot create window with x pixel dimension provided");
    }
    else if(input_args.pixels_y == 0 || input_args.pixels_y > MAX_PIXELS_Y){
        throw std::invalid_argument("Cannot create window with y pixel dimension provided");
    }

    else if(input_args.blocks_x == 0 || input_args.blocks_x > input_args.pixels_x || input_args.pixels_x % input_args.blocks_x != 0){
        throw std::invalid_argument("Cannot create window with x blocks dimension provided");
    }
    else if(input_args.blocks_y == 0 || input_args.blocks_y > input_args.pixels_y || input_args.pixels_y % input_args.blocks_y != 0){
        throw std::invalid_argument("Cannot create window with y blocks dimension provided");
    }

    else if(input_args.pixels_x_per_block < MIN_PIXEL_PER_BLOCK_SIZE || input_args.pixels_y_per_block < MIN_PIXEL_PER_BLOCK_SIZE){
        throw std::invalid_argument("Block size in pixels needs to be bigger");
    }

    else if(input_args.time_between_iteration == 0){
        throw std::invalid_argument("Invalid time between iterations");
    }

}