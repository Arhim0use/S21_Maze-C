#include "./s21_maze_model/maze_model.h"
#include "./s21_maze_generator/maze_generator.h"

int main() {
    
    rectangular_maze maze = null_maze();
    int size = 8;
    create_maze(size, size, &maze);

    generate_ideal_maze(size, size, &maze);
    generate_ideal_maze(size, size, &maze);
    delete_maze(&maze);

    generate_ideal_maze(size, size, &maze);
    print_maze(&maze);

    delete_maze(&maze);
    
    return 0;
}

