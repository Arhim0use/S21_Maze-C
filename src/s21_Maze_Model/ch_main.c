#include "maze_model.h"

int main() {
    
    rectangular_maze maze = null_maze();

    create_maze(10, 10, &maze);

    init_random_matrix(&maze);
    print_two_matrix(&maze);
    print_maze(&maze);

    delete_maze(&maze);

    return 0;
}