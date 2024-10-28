#ifndef MOVE_TO_HPP
#define MOVE_TO_HPP

#include "action.hpp"
#include "entity_properties.hpp"
#include <SFML/Graphics.hpp>

#include <memory>

class MoveTo : public Action {
public:
    MoveTo(float duration, sf::Vector2f from, sf::Vector2f to);
    void update(float dt, std::shared_ptr<EntityProperties>  entity) override;
    bool isComplete() const override;

private:
    float duration;                 // Duration of the action
    float elapsed;                  // Elapsed time
    sf::Vector2f targetPosition;    // Target position
    sf::Vector2f startPosition;     // original position
};

#endif // MOVE_TO_HPP

