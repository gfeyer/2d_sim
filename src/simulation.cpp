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
    updateGrid(dt);
    updateEntities(dt);
}

void Simulation::render(sf::RenderWindow& window) {
    renderGrid(window);
    renderEntities(window);
}

void Simulation::updateGrid(float dt) {
    this->grid->update(dt);
}

void Simulation::updateEntities(float dt) {
    for (auto& entity : entities) {
        entity->update(dt, *this->grid);
    }
}

void Simulation::renderGrid(sf::RenderWindow& window) {
    this->grid->render(window);
}

void Simulation::renderEntities(sf::RenderWindow& window) {
    for (auto& entity : entities) {
        entity->render(window);
    }
}
