#include "entity.hpp"

#include "grid.hpp"
Entity::Entity(Grid& grid) : grid(grid) {

    // get cell position
    this->cellPosition = sf::Vector2i(0, 1);

    // create shape
    this->shape.setRadius(20.f);
    this->shape.setOrigin(this->shape.getRadius(), this->shape.getRadius());
    this->shape.setFillColor(sf::Color::Green);
    auto pos = grid.cellToPixel(this->cellPosition);
    this->shape.setPosition(pos.x, pos.y);

    // Add command to move to right cell
    moveToCell(sf::Vector2i{0,0});
}

Entity::~Entity() {
}

void Entity::update(float dt) {
    if(this->isMoving) {
        auto dx = this->deltaPosition.x * dt;
        auto dy = this->deltaPosition.y * dt;
        this->shape.move(dx, dy);

        this->deltaRemaining.x -= dx;
        this->deltaRemaining.y -= dy;
        
        // check if the vector size deltaRemaining is close to 0
        if(abs(this->deltaRemaining.x) < 1.f && abs(this->deltaRemaining.y) < 1.f) {
            this->isMoving = false;
            this->shape.setFillColor(sf::Color::Green);
        }
    }
}

void Entity::render(sf::RenderWindow& window) {
    window.draw(this->shape);
}

void Entity::moveToCell(sf::Vector2i targetCell) {
    this->isMoving = true;
    this->deltaPosition = grid.cellToPixel(targetCell) - this->shape.getPosition();
    this->deltaRemaining = this->deltaPosition;
}
