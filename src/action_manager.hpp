#ifndef ACTION_MANAGER_HPP
#define ACTION_MANAGER_HPP

#include <vector>
#include <memory>
#include "action.hpp"  
#include "entity.hpp"  

class ActionManager {
public:
    // Singleton access
    static ActionManager& getInstance() {
        static ActionManager instance;
        return instance;
    }

    // Add an action for an entity
    void runAction(Entity* entity, std::shared_ptr<Action> action);

    // Update all actions
    void update(float dt);

private:
    // Private constructor for the singleton
    ActionManager() = default;

    // No copy or assignment
    ActionManager(const ActionManager&) = delete;
    ActionManager& operator=(const ActionManager&) = delete;

    // Struct to store an entity and its action
    struct EntityAction {
        Entity* entity;
        std::shared_ptr<Action> action;
    };

    // List of all active actions
    std::vector<EntityAction> activeActions;
};

#endif // ACTION_MANAGER_HPP