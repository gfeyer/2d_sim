#include "grid.hpp"

Cell::Cell() {
}

Grid::Grid(size_t rows, size_t cols) {
    for(size_t r = 0; r < rows; r++) {
        std::vector<Cell> row;
        for(size_t c = 0; c < cols; c++) {
            row.push_back(Cell());
        }
        grid.push_back(row);
    }
}


