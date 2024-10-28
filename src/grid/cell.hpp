#ifndef CELL_HPP
#define CELL_HPP

#include "cell_properties.hpp"
#include <SFML/Graphics.hpp>
#include <atomic>


class Cell{
    static std::atomic<uint64_t> idCounter;  // ID counter, thread safe
    const uint64_t id;

    // Properties
    CellProperties properties;

    // Position in grid
    int row;
    int column;

    // Rendering vars
    sf::RectangleShape shape;
    sf::Text text;

public:
    Cell();
    ~Cell();

    void render(sf::RenderWindow& window);
    void update(float dt);

    const CellProperties& getProperties() const;

};

#endif  // CELL_HPP