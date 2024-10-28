#include "move_to.hpp"

MoveTo::MoveTo(float duration, sf::Vector2f from, sf::Vector2f to) 
: duration(duration), startPosition(from), targetPosition(to), elapsed(0.0f) {}


void MoveTo::update(float dt, Entity* entity) {
        if (isComplete()) return;

        // Calculate the progress
        elapsed += dt;
        float t = elapsed / duration;

        // Clamp t to [0, 1]
        if (t > 1.0f) t = 1.0f;

        // Linearly interpolate the position
        sf::Vector2f newPosition = startPosition + (targetPosition - startPosition) * t;
        entity->setPosition(newPosition);

        // Check for completion and run callback
        checkAndRunCallback();
}

bool MoveTo::isComplete() const {
    return elapsed >= duration;
}
