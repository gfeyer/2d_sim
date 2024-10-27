#include <iostream>

#include "simulation.hpp"
#include "conf.hpp"
#include "logger.hpp"

int main()
{
    logger::SetLevelTrace();
    
    auto window = sf::RenderWindow({conf::WINDOW_WIDTH_PX, conf::WINDOW_HEIGHT_PX}, "2D Sim");
    window.setFramerateLimit(60);

    log_info << "Starting...";
    Simulation sim;

    auto time = sf::Clock();

    // Main Loop
    while (window.isOpen())
    {
        // Event Handler
        for (auto event = sf::Event(); window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();  
            }
            if(event.key.code == sf::Keyboard::Escape){
                window.close();
            }
        }

        // Update(dt)
        sim.update(time.restart().asSeconds());


        // Draw(window)
        window.clear();

        // Render
        sim.render(window);

        window.display();
    }
}
