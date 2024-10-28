#ifndef SEQUENCE_ACTION_HPP
#define SEQUENCE_ACTION_HPP

#include "action.hpp"
#include <queue>
#include <memory>

class ActionSequence : public Action {
public:
    // Add an action to the sequence
    void addAction(std::shared_ptr<Action> action) {
        if (action) actions.push(std::move(action));
    }

    // Update the current action in the sequence
    void update(float dt, std::shared_ptr<EntityProperties> entity) override {
        if (actions.empty()) return;

        // Update the current action
        auto currentAction = actions.front();
        currentAction->update(dt, entity);

        // Check if the current action is complete
        if (currentAction->isComplete()) {
            currentAction->checkAndRunCallback();  // Run the callback if any
            actions.pop();  // Move to the next action

            if (actions.empty()) {
                // All actions are complete
                checkAndRunCallback();  // Run the callback for the sequence, if any
            }
        }
    }

    // Check if all actions are complete
    bool isComplete() const override {
        return actions.empty();
    }

private:
    std::queue<std::shared_ptr<Action>> actions;  // Queue of actions
};

#endif // SEQUENCE_ACTION_HPP
