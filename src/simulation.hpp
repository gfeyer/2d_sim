#ifndef SIM_HPP
#define SIM_HPP

#include <SFML/Graphics.hpp>

class Simulation
{
    public:
        Simulation();
        void update(float dt);
        void render(sf::RenderWindow &window);
};

#endif