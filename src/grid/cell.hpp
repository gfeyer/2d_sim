#ifndef CELL_HPP
#define CELL_HPP

#include <SFML/Graphics.hpp>
#include <atomic>

struct Properties {
    int terrainType;
    bool isWalkable;
    int resourceAmount;

};

class Cell{
    static std::atomic<uint64_t> idCounter;  // ID counter, thread safe
    const uint64_t id;

    // Properties
    Properties properties;

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

    const Properties& getProperties() const;

};

#endif  // CELL_HPP