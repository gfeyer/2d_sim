#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "entity_properties.hpp"
#include "grid.hpp"
#include <SFML/Graphics.hpp>


class Entity
{
    Grid& grid;
    sf::Vector2i cellPosition;
    EntityProperties properties;

    // Rendering
    sf::CircleShape shape;

public:
    Entity(Grid&);
    ~Entity();

    void update(float dt);
    void render(sf::RenderWindow& window);

    sf::Vector2f getPosition() const;
    void setPosition(sf::Vector2f);

};


#endif