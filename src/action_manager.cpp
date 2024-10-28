#include "action_manager.hpp"

#include "logger.hpp"

#include <algorithm>

void ActionManager::runAction(Entity* entity, std::shared_ptr<Action> action) {
    // Add the action to the list
    activeActions.push_back({entity, action});
}

void ActionManager::update(float dt) {
    
    // Iterate over all active actions
    for (auto it = activeActions.begin(); it != activeActions.end(); ) {
        // Update the action
        it->action->update(dt, it->entity);

        // Check if the action is complete
        if (it->action->isComplete()) {
            // Remove the action from the list
            it = activeActions.erase(it);
        } else {
            // Move to the next action
            ++it;
        }
    }
}