#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "entity_properties.hpp"
#include "grid/grid.hpp"
#include <SFML/Graphics.hpp>

#include <memory>

class Entity
{
    Grid& grid;
    sf::Vector2i cellPosition;

    // Properties that can be interpolated externally
    std::shared_ptr<EntityProperties> properties;

    // Rendering
    sf::CircleShape shape;

public:
    Entity(Grid&);
    ~Entity();

    void update(float dt);
    void render(sf::RenderWindow& window);
};


#endif