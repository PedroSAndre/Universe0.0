#include "main_logic.hpp"

void addCell(std::vector<std::vector<Cell>>& cells, const sf::Vector2i& local_mouse_position, const InputArgs& input_args){
    unsigned int x,y;
    x = local_mouse_position.x / input_args.pixels_x_per_block;
    y = local_mouse_position.y / input_args.pixels_y_per_block;

    cells[x][y].is_alive=!cells[x][y].is_alive;
}

void iterationStep(std::vector<std::vector<Cell>>& cells){
    unsigned int aux;
    for(int i = 0; i < cells.size(); i++){
        for(int j = 0; j < cells[i].size(); j++){
            aux = 0;
            for(int ii = i-1; ii <= i+1; ii++){
                if(ii > -1 && ii < cells.size()){
                    for(int jj = j-1; jj <= j+1; jj++){
                        if(jj > -1 && jj < cells[i].size()){
                            if(ii != i || jj != j){
                                if(cells[ii][jj].is_alive){
                                    aux++;
                                }
                            }
                        }
                    }
                }
            }
            if(cells[i][j].is_alive){
                if(aux/2 != 1){
                    cells[i][j].will_change = true;
                }
            }
            else{
                if(aux == 3){
                    cells[i][j].will_change = true;
                }
            }
        }
    }

    for(unsigned int i = 0; i < cells.size(); i++){
        for(unsigned int j = 0; j < cells[i].size(); j++){
            if(cells[i][j].will_change){
                cells[i][j].will_change = false;
                cells[i][j].is_alive = !cells[i][j].is_alive;
            }
        }
    }
}
