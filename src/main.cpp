#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>

#include "conf.hpp"


int main()
{
    auto window = sf::RenderWindow({640u, 480u}, "SFML Example");
    window.setFramerateLimit(60);

    // create shape
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition({100.f, 100.f});

    // create shape
    sf::RectangleShape shape2(sf::Vector2f(100.f, 100.f));
    shape2.setFillColor(sf::Color::Blue);


    // Create a view with the same size as the window
    sf::View view(sf::FloatRect(0, 0, 640, 480));

    // Move the view's center (e.g., to (320, 240))
    view.setCenter(320, 240);

    // Set the view to the window
    window.setView(view);

    bool isDragging = false;
    sf::Vector2f initialPosition;


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

            if(event.type == sf::Event::MouseWheelScrolled){
                if(event.mouseWheelScroll.delta > 0){
                    view.zoom(1.1f);
                }else{
                    view.zoom(0.9f);
                }
                window.setView(view);
            }

            // If mouse is clicked and dragged, move the view
            // Mouse button pressed
            if (event.type == sf::Event::MouseButtonPressed && 
                event.mouseButton.button == sf::Mouse::Left) {
                isDragging = true;  // Start dragging
                initialPosition = window.mapPixelToCoords(
                    {event.mouseButton.x, event.mouseButton.y});  // Initial drag position
            }

            // Mouse button released
            if (event.type == sf::Event::MouseButtonReleased && 
                event.mouseButton.button == sf::Mouse::Left) {
                isDragging = false;  // Stop dragging
            }

            // Mouse moved
            if (event.type == sf::Event::MouseMoved && isDragging) {
                // Get the current position
                sf::Vector2f currentPosition = window.mapPixelToCoords(
                    {event.mouseMove.x, event.mouseMove.y});

                // Calculate the offset
                sf::Vector2f offset = initialPosition - currentPosition;

                // Move the view by the offset
                view.move(offset);

                // Update the view in the window
                window.setView(view);

                // Update the initial position to the current one for continuous dragging
                initialPosition = currentPosition;
            }
        }

        // Update(dt)
        sf::FloatRect viewBounds(
            view.getCenter() - view.getSize() / 2.f,
            view.getSize()
        );


        // Draw(window)
        window.clear();

        // Culling - only draw if shape is inside view
        // Check if the sprite is within the view's bounds
        if (shape.getGlobalBounds().intersects(viewBounds)) {
            window.draw(shape);  // Draw the sprite if it intersects
            std::cout << "shape" << '\n';
        }

        if (shape2.getGlobalBounds().intersects(viewBounds)) {
            window.draw(shape2);  // Draw the sprite if it intersects
            std::cout << "shape2" << '\n';

        }

        window.display();
    }
}
