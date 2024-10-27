#ifndef GRID_HPP
#define GRID_HPP

#include <vector>

class Cell{

public:
    Cell();
};

class Grid{
    std::vector<std::vector<Cell>> grid;

public:
    Grid() = default;
    Grid(size_t rows, size_t cols);
};

#endif