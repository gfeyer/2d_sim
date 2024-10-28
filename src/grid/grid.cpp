#include "grid.hpp"
#include "cell.hpp"
#include "conf.hpp"
#include "utility/logger.hpp"


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

void Grid::update(float dt) {
}

sf::Vector2f Grid::cellToPixel(sf::Vector2i position) {
    return sf::Vector2f(
        position.y * conf::TILE_SIZE + conf::TILE_SIZE / 2,
        position.x * conf::TILE_SIZE + conf::TILE_SIZE / 2
    );
}

sf::Vector2u Grid::size() {
    unsigned int rows = grid.size();
    unsigned int cols = grid[0].size();
    return sf::Vector2u{rows, cols};
}
