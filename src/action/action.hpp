#ifndef ACTION_HPP
#define ACTION_HPP

#include "entity/entity_properties.hpp"

#include <functional>
#include <memory>

class Action {
public:
    virtual ~Action() = default;

    // Set the completion callback
    void setCallback(std::function<void()> callback) {
        this->callback = std::move(callback);
    }

    // Update the action
    virtual void update(float dt, std::shared_ptr<EntityProperties>  properties) = 0;

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