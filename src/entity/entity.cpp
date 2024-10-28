#include "entity.hpp"

#include "action/action.hpp"
#include "action/action_sequence.hpp"
#include "action/action_manager.hpp"
#include "grid/grid.hpp"
#include "action/move_to.hpp"
#include "utility/logger.hpp"

Entity::Entity(Grid& grid) : grid(grid) {

    // create properties
    this->properties = std::make_shared<EntityProperties>();

    // set cell position
    auto gridSize = grid.size();
    this->cellPosition = sf::Vector2i(rand() % gridSize.x, rand() % gridSize.y);

    // create shape
    this->shape.setRadius(20.f);
    this->shape.setOrigin(this->shape.getRadius(), this->shape.getRadius());
    this->shape.setFillColor(sf::Color::Green);
    auto pos = grid.cellToPixel(this->cellPosition);
    this->properties->position = pos;

    // Add some random actions
    auto sequence = std::make_shared<ActionSequence>();
    int totalActions = rand() % 10+1;
    
    for(int i=0; i < totalActions; ++i){
        int row = rand() % gridSize.x;
        int col = rand() % gridSize.y;
        auto moveTo = std::make_shared<MoveTo>(0.5f, grid.cellToPixel(sf::Vector2i(row, col)));
        moveTo->setCallback([this, row, col] { 
            this->cellPosition = sf::Vector2i(row, col); 
        });
        sequence->addAction(moveTo);
    }

    sequence->setCallback([this] { 
        this->shape.setFillColor(sf::Color::Red); 
        this->cellPosition = sf::Vector2i(1, 1);
        log_debug << "Sequence Completed";
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