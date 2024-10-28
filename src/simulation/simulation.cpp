#include "simulation.hpp"

#include "action/action_manager.hpp"
#include "conf.hpp"
#include "grid/grid.hpp"
#include "utility/logger.hpp"

#include <iostream>
Simulation::Simulation(){
    log_trace << "CTOR Simulation::Simulation()";
    this->grid = std::make_unique<Grid>(conf::GRID_ROWS, conf::GRID_COLS);
    
    auto entity = std::make_unique<Entity>(*this->grid);
    this->entities.push_back(std::move(entity));
}

Simulation::~Simulation() {
    log_trace << "DTOR Simulation::~Simulation()";
}

void Simulation::update(float dt) {
    updateGrid(dt);
    updateEntities(dt);
    updateActions(dt);
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
        entity->update(dt);
    }
}

void Simulation::updateActions(float dt) {
    ActionManager::getInstance().update(dt);
}

void Simulation::renderGrid(sf::RenderWindow& window) {
    this->grid->render(window);
}

void Simulation::renderEntities(sf::RenderWindow& window) {
    for (auto& entity : entities) {
        entity->render(window);
    }
}
