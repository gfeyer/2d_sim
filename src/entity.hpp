#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>

class Entity
{
public:
    Entity();
    ~Entity();

    void update(float dt);
    void render(sf::RenderWindow& window);
};


#endif