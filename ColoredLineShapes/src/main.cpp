#include <iostream>
#include <vector>

//User libs includes
#include "LineShapes.h"

void handleEvents(sf::RenderWindow *);
int main()
{
    sf::Color backgroundColor(230,230,230,255);    
    sf::RenderWindow window(sf::VideoMode(800, 600), "LineShapes");
    std::vector<class LineShapes> lines;

    for(int i = 3; i < 13; i++)
        lines.push_back(LineShapes(sf::Vector2f(400, 300), float(i*20), i, 4.0, sf::Color::Cyan));
    
    // change the position of the window (relatively to tmahe desktop)
    window.setPosition(sf::Vector2i(10, 50));
    //Setting up
    // run the program as long as the window is open
    while (window.isOpen())
    {
        //handle the user events
        handleEvents(&window);

        //clear the window
        window.clear(backgroundColor);
        
        //draw the lines
        for(int i = 0; i < lines.size(); i++)
            window.draw(lines[i]);
        
        //finish frame
        window.display();
    }

    return 0;
}

void handleEvents(sf::RenderWindow *window ){
    // check all the window's events that were triggered since the last iteration of the loop
    sf::Event event;
    while (window->pollEvent(event))
    {
        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed){
            window->close();
        }
        if (event.type == sf::Event::MouseButtonPressed){
        }
        if (event.type == sf::Event::KeyPressed){
            switch (event.key.code){
                case sf::Keyboard::Escape:
                    std::cout << "Escape key pressed." << std::endl;
                    window->close();
                    break;
                default:
                    std::cout << "Some key was pressed." << std::endl;
            }
        }
    }
}