#include "simulation.hpp"

#include "conf.hpp"
#include "grid.hpp"
#include "logger.hpp"

#include <iostream>
Simulation::Simulation(){
    log_trace << "CTOR Simulation::Simulation()";
    this->grid = std::make_unique<Grid>(conf::GRID_ROWS, conf::GRID_COLS);
}

Simulation::~Simulation() {
    log_trace << "DTOR Simulation::~Simulation()";
}

void Simulation::update(float dt) {
}

void Simulation::render(sf::RenderWindow& window) {
    this->grid->render(window);
}
