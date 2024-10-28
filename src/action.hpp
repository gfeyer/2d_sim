#ifndef ACTION_HPP
#define ACTION_HPP

#include "entity.hpp"

#include <functional>

class Action {
public:
    virtual ~Action() = default;

    // Set the completion callback
    void setCallback(std::function<void()> callback) {
        this->callback = std::move(callback);
    }

    // Update the action
    // TODO: should we actually pass other properties in here?
    virtual void update(float dt, Entity* entity) = 0;

    // Check if the action is complete
    virtual bool isComplete() const = 0;

    // Call the callback if complete
    void checkAndRunCallback() {
        if (isComplete() && callback) {
            callback();
            callback = nullptr;  // Reset to prevent multiple calls
        }
    }

protected:
    std::function<void()> callback;  // Completion callback
};


#endif