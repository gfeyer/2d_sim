#ifndef GRID_HPP
#define GRID_HPP

#include "cell.hpp"

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class Grid{
    std::vector<std::vector<std::unique_ptr<Cell>>> grid;

public:
    Grid(size_t rows, size_t cols);
    ~Grid();

    void render(sf::RenderWindow &window);
    void update(float dt);

    sf::Vector2f cellToPixel(sf::Vector2i position);
    sf::Vector2u size();
};

#endif