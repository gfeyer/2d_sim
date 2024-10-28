#include "entity.hpp"

#include "conf.hpp"
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
    this->shape.setRadius(conf::TILE_SIZE / 4);
    this->shape.setOrigin(this->shape.getRadius(), this->shape.getRadius());
    this->shape.setFillColor(sf::Color::Green);
    auto pos = grid.cellToPixel(this->cellPosition);
    this->properties->position = pos;

    // Add some random actions
    auto sequence = std::make_shared<ActionSequence>();
    int totalActions = rand() % 20+1;
    
    for(int i=0; i < totalActions; ++i){

        auto moveTo = std::make_shared<MoveTo>(0.f, grid.cellToPixel(this->cellPosition));
        moveTo->setCallback([this, sequence] { 
            
            auto direction = rand() % 5;
            if(direction == 0){
                // no further callbacks
                return;
            }

            sf::Vector2i targetCellPosition;

            if(direction == 1 && this->cellPosition.y < this->grid.size().y-1){ // Move Up
                targetCellPosition = sf::Vector2i(this->cellPosition.x, this->cellPosition.y+1);
            } else if(direction == 2 && this->cellPosition.y > 0){ // Move Down
                targetCellPosition = sf::Vector2i(this->cellPosition.x, this->cellPosition.y-1);
            } else if(direction == 3 && this->cellPosition.x > 0){ // Move Left
                targetCellPosition = sf::Vector2i(this->cellPosition.x-1, this->cellPosition.y);
            } else if(direction == 4 && this->cellPosition.x < this->grid.size().x-1){ // Move Right
                targetCellPosition = sf::Vector2i(this->cellPosition.x+1, this->cellPosition.y);
            }
            else{
                // cannot move in that direction so no change
                targetCellPosition = this->cellPosition;
            }

            std::shared_ptr<Action> moveTo;
            moveTo = std::make_shared<MoveTo>(0.5f, this->grid.cellToPixel(targetCellPosition));
            this->cellPosition = targetCellPosition;
            
            sequence->addAction(moveTo);
        });
        sequence->addAction(moveTo);
    }

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