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
    this->shape.setPosition(pos.x, pos.y);


    auto moveTo = std::make_shared<MoveTo>(3.0f, this->shape.getPosition(), sf::Vector2f(200, 200));
    moveTo->setCallback([this] { 
        log_debug << "Move complete";
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
    window.draw(this->shape);
}

sf::Vector2f Entity::getPosition() const {
    return this->shape.getPosition();
}

void Entity::setPosition(sf::Vector2f pos) {
    this->shape.setPosition(pos.x, pos.y);
}