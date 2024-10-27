#ifndef CELL_HPP
#define CELL_HPP

#include "logger.hpp"

#include <SFML/Graphics.hpp>
#include <atomic>

struct Properties {
    int terrainType;
    bool isWalkable;
    int resourceAmount;

};

class Cell{
    static std::atomic<uint64_t> idCounter;  // ID counter, thread safe
    Properties properties;

    const uint64_t id;

    // Shape to visully represent the cell
    sf::RectangleShape shape;

    // Position in grid
    int row;
    int column;

public:
    Cell();
    ~Cell();

    void render(sf::RenderWindow& window);
    void update(float dt);

    const Properties& getProperties() const;

};

#endif  // CELL_HPP