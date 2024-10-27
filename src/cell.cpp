#include "cell.hpp"

#include "logger.hpp"

// Properties
std::atomic<uint64_t> Cell::idCounter{0};


// Cell
Cell::Cell() : id(Cell::idCounter.fetch_add(1)) {
    log_trace << "Cell::Cell(), id:" << this->id;
}

Cell::~Cell() {
    log_trace << "Cell::~Cell(), id:" << this->id;
}

void Cell::render(sf::RenderWindow& window) {
}

void Cell::update(float dt) {
}

const Properties& Cell::getProperties() const {
        return this->properties;
}


