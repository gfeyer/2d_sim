#ifndef MOVE_TO_HPP
#define MOVE_TO_HPP

#include "action.hpp"

#include <SFML/Graphics.hpp>

class MoveTo : public Action {
public:
    MoveTo(float duration, sf::Vector2f from, sf::Vector2f to);
    void update(float dt, Entity* entity) override;
    bool isComplete() const override;

private:
    template <typename T> T interpolate(float duration, T from, T to);

    float duration;                 // Duration of the action
    float elapsed;                  // Elapsed time
    sf::Vector2f targetPosition;    // Target position
    sf::Vector2f startPosition;     // original position
};

#endif // MOVE_TO_HPP

template <typename T>
inline T MoveTo::interpolate(float t, T from, T to) {
    T newPosition = from + (to - from) * t;
    return newPosition;
}
