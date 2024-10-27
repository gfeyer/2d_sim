#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "grid.hpp"
#include <SFML/Graphics.hpp>


class Entity
{
    int row;
    int column;
        
public:
    Entity();
    ~Entity();

    void update(float dt, const Grid&);
    void render(sf::RenderWindow& window);
};


#endif