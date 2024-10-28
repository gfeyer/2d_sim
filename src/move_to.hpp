#ifndef MOVE_TO_HPP
#define MOVE_TO_HPP

#include "action.hpp"

#include <SFML/Graphics.hpp>

class MoveTo : public Action {
public:
    MoveTo(float duration, sf::Vector2f from, sf::Vector2f to)
        : duration(duration), startPosition(from), targetPosition(to), elapsed(0.0f) {}

    void update(float dt, Entity* entity) override {
        if (isComplete()) return;

        // Calculate the progress
        elapsed += dt;
        float t = elapsed / duration;

        // Clamp t to [0, 1]
        if (t > 1.0f) t = 1.0f;

        // Linearly interpolate the position
        sf::Vector2f newPosition = this->startPosition + (this->targetPosition - this->startPosition) * t;
        entity->setPosition(newPosition);

        // Check for completion and run callback
        checkAndRunCallback();
    }

    bool isComplete() const override {
        return elapsed >= duration;
    }

private:
    float duration;          // Duration of the action
    float elapsed;           // Elapsed time
    sf::Vector2f targetPosition;     // Target position
    sf::Vector2f startPosition; // original position
};

#endif // MOVE_TO_HPP
