#ifndef UNIVERSE0_0_MAIN_HPP
#define UNIVERSE0_0_MAIN_HPP

struct InputArgs{
    unsigned int time_between_iteration = 1000;
    unsigned int pixels_x=0;
    unsigned int pixels_y=0;
    unsigned int blocks_x=0;
    unsigned int blocks_y=0;
    unsigned int pixels_x_per_block=0;
    unsigned int pixels_y_per_block=0;
};

struct Cell{
    bool is_alive = false;
    bool will_change = false;
};

#endif //UNIVERSE0_0_MAIN_HPP
