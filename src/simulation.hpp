#ifndef SIM_HPP
#define SIM_HPP

#include "grid.hpp"
#include <SFML/Graphics.hpp>

#include <memory>
class Simulation
{
    std::unique_ptr<Grid> grid_ptr;

    public:
        Simulation();
        ~Simulation();
        void update(float dt);
        void render(sf::RenderWindow &window);
};

#endif