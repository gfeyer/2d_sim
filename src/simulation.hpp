#ifndef SIM_HPP
#define SIM_HPP

#include "grid.hpp"
#include <SFML/Graphics.hpp>

#include <memory>
class Simulation
{
    Grid grid;

    public:
        Simulation();
        ~Simulation();
        void update(float dt);
        void render(sf::RenderWindow &window);
};

#endif