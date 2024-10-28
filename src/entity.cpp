#include "entity.hpp"

#include "action.hpp"
#include "action_sequence.hpp"
#include "action_manager.hpp"
#include "grid.hpp"
#include "move_to.hpp"

Entity::Entity(Grid& grid) : grid(grid) {

    // create properties
    this->properties = std::make_shared<EntityProperties>();

    // get cell position
    this->cellPosition = sf::Vector2i(0, 0);

    // create shape
    this->shape.setRadius(20.f);
    this->shape.setOrigin(this->shape.getRadius(), this->shape.getRadius());
    this->shape.setFillColor(sf::Color::Green);
    auto pos = grid.cellToPixel(this->cellPosition);
    this->properties->position = pos;

    auto moveTo1 = std::make_shared<MoveTo>(0.5f, grid.cellToPixel(sf::Vector2i(0, 1)));
    auto moveTo2 = std::make_shared<MoveTo>(0.5f, grid.cellToPixel(sf::Vector2i(1, 0)));

    auto sequence = std::make_shared<ActionSequence>();
    sequence->addAction(moveTo1);
    sequence->addAction(moveTo2);
    sequence->setCallback([this] { 
        this->shape.setFillColor(sf::Color::Red); 
        this->cellPosition = sf::Vector2i(1, 1); 
    });



    // Run the action on the entity
    ActionManager::getInstance().runAction(this->properties, sequence);
}

Entity::~Entity() {
}

void Entity::update(float dt) {
}

void Entity::render(sf::RenderWindow& window) {
    this->shape.setPosition(this->properties->position);
    window.draw(this->shape);
}