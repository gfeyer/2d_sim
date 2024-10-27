#include "simulation.hpp"

#include "conf.hpp"
#include "grid.hpp"

#include <iostream>
Simulation::Simulation(){
    this->grid = Grid(conf::WINDOW_WIDTH_PX / conf::TILE_SIZE, conf::WINDOW_HEIGHT_PX / conf::TILE_SIZE);
}

void Simulation::update(float dt) {
}

void Simulation::render(sf::RenderWindow& window) {
}
