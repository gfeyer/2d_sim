#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "grid.hpp"
#include <SFML/Graphics.hpp>


class Entity
{
    Grid& grid;

    sf::Vector2i cellPosition;

    // Movement
    bool isMoving;
    const float speed = 1.0f;
    sf::Vector2f deltaPosition;
    sf::Vector2f deltaRemaining;

    // Rendering
    sf::CircleShape shape;

public:
    Entity(Grid&);
    ~Entity();

    void update(float dt);
    void render(sf::RenderWindow& window);

private:
    void moveToCell(sf::Vector2i);
};


#endif