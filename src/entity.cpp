#include "entity.hpp"

#include "action.hpp"
#include "action_manager.hpp"
#include "grid.hpp"
#include "move_to.hpp"

Entity::Entity(Grid& grid) : grid(grid) {

    // get cell position
    this->cellPosition = sf::Vector2i(0, 0);

    // create shape
    this->shape.setRadius(20.f);
    this->shape.setOrigin(this->shape.getRadius(), this->shape.getRadius());
    this->shape.setFillColor(sf::Color::Green);
    auto pos = grid.cellToPixel(this->cellPosition);
    // this->shape.setPosition(pos.x, pos.y);
    this->properties.position = pos;


    auto moveTo = std::make_shared<MoveTo>(1.0f, this->shape.getPosition(), grid.cellToPixel(sf::Vector2i(1, 1)));
    moveTo->setCallback([this] { 
        this->shape.setFillColor(sf::Color::Red); 
        this->cellPosition = sf::Vector2i(1, 1);    
    });

    // Run the action on the entity
    ActionManager::getInstance().runAction(this, moveTo);
}

Entity::~Entity() {
}

void Entity::update(float dt) {
}

void Entity::render(sf::RenderWindow& window) {
    this->shape.setPosition(this->properties.position);
    window.draw(this->shape);
}

sf::Vector2f Entity::getPosition() const {
    return this->properties.position;
}

void Entity::setPosition(sf::Vector2f pos) {
    this->properties.position = pos;
}