#include "cell.hpp"

#include "conf.hpp"
#include "utility/logger.hpp"
#include "resource/resource_manager.hpp"

// Properties
std::atomic<uint64_t> Cell::idCounter{0};

// Cell
Cell::Cell() : id(Cell::idCounter.fetch_add(1)) {
    log_trace << "CTOR Cell::Cell(), id:" << this->id;

    // Base properties
    row = this->id % conf::GRID_COLS;
    column = this->id / conf::GRID_COLS;
    properties.terrainType = 0;
    properties.isWalkable = true;
    properties.resourceAmount = 0;

    // Rendering
    this->shape = sf::RectangleShape(sf::Vector2f(conf::TILE_SIZE, conf::TILE_SIZE));
    this->shape.setFillColor(sf::Color::Black);
    this->shape.setOutlineColor(sf::Color::White);
    this->shape.setOutlineThickness(1);

    // Pixel Position
    this->shape.setPosition(
        static_cast<float>(row) * conf::TILE_SIZE,
        static_cast<float>(column) * conf::TILE_SIZE
    );

    sf::Font& font = ResourceManager::getFont(conf::FONT_1);
    this->text.setFont(font);
    this->text.setString(std::to_string(this->id));
    this->text.setScale(conf::TILE_SIZE/128.0, conf::TILE_SIZE/128.0);
    this->text.setPosition(
        static_cast<float>(row) * conf::TILE_SIZE + 0,
        static_cast<float>(column) * conf::TILE_SIZE + 0
    );
}

Cell::~Cell() {
    log_trace << "~DTOR Cell::~Cell(), id:" << this->id;
}

void Cell::render(sf::RenderWindow& window) {
    
    window.draw(this->shape);
    window.draw(this->text);
}

void Cell::update(float dt) {
}

const CellProperties& Cell::getProperties() const {
        return this->properties;
}


