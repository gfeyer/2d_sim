#ifndef SIM_HPP
#define SIM_HPP

#include "entity/entity.hpp"
#include "grid/grid.hpp"
#include <SFML/Graphics.hpp>

#include <memory>
#include <vector>
class Simulation
{
    std::unique_ptr<Grid> grid;
    std::vector<std::unique_ptr<Entity>> entities;

public:
    Simulation();
    ~Simulation();
    void update(float dt);
    void render(sf::RenderWindow &window);

private:
    void updateGrid(float dt);
    void updateEntities(float dt);
    void updateActions(float dt);

    void renderGrid(sf::RenderWindow &window);
    void renderEntities(sf::RenderWindow &window);
};

#endif