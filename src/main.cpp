#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>

#include "conf.hpp"


int main()
{
    auto window = sf::RenderWindow({conf::WINDOW_WIDTH_PX, conf::WINDOW_HEIGHT_PX}, "2d Sim");
    window.setFramerateLimit(60);

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

        // Draw(window)
        window.clear();

        // Render

        window.display();
    }
}
