#include <iostream>

#include "simulation/simulation.hpp"
#include "conf.hpp"
#include "utility/logger.hpp"

int main()
{
    // Logger
    logger::SetLevelDebug();
    log_debug << "Starting simulation";

    // Seed random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

    // Window
    auto window = sf::RenderWindow({conf::WINDOW_WIDTH_PX, conf::WINDOW_HEIGHT_PX}, "2D Sim");
    window.setFramerateLimit(60);

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
                log_trace << "Window closed";
                window.close();  
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                log_trace << "Escape pressed, closing window";
                window.close();
            }

        }

        // Update(dt)
        sim.update(time.restart().asSeconds());

        // Draw(window)
        window.clear(sf::Color::Black);

        // Render
        sim.render(window);

        window.display();
    }
}
