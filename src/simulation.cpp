#include "simulation.hpp"

#include "conf.hpp"
#include "grid.hpp"
#include "logger.hpp"

#include <iostream>
Simulation::Simulation(){
    log_trace << "Simulation::Simulation()";
    this->grid_ptr = std::make_unique<Grid>(conf::WINDOW_WIDTH_PX / conf::TILE_SIZE, conf::WINDOW_HEIGHT_PX / conf::TILE_SIZE);
}

Simulation::~Simulation() {
    log_trace << "Simulation::~Simulation()";
}

void Simulation::update(float dt) {
}

void Simulation::render(sf::RenderWindow& window) {
}
