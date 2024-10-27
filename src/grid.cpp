#include "grid.hpp"
#include "cell.hpp"
#include "logger.hpp"


Grid::Grid(size_t rows, size_t cols) {
    log_trace << "CTOR Grid::Grid() " << rows << "x" << cols;
    for(size_t r = 0; r < rows; r++) {
        std::vector<std::unique_ptr<Cell>> row;
        for(size_t c = 0; c < cols; c++) {
            auto cell = std::make_unique<Cell>();
            row.push_back(std::move(cell));
        }
        grid.push_back(std::move(row));
    }
}

Grid::~Grid() {
    log_trace << "DTOR Grid::~Grid()";
}

void Grid::render(sf::RenderWindow& window) {
    for(size_t r = 0; r < grid.size(); r++) {
        for(size_t c = 0; c < grid[r].size(); c++) {
            grid[r][c]->render(window);
        }
    }
}
