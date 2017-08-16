#include <iostream>
#include <vector>

//User libs includes
#include "LineShapes.h"

void handleEvents(sf::RenderWindow *);
int main()
{
    sf::Color backgroundColor(230,230,230,255);    
    sf::RenderWindow window(sf::VideoMode(800, 600), "LineShapes");

    // change the position of the window (relatively to tmahe desktop)
    window.setPosition(sf::Vector2i(10, 50));
    int i = 0;

    //Setting up
    // run the program as long as the window is open
    while (window.isOpen())
    {
        //handle the user events
        handleEvents(&window);

        //clear the window
        window.clear(backgroundColor);
        
        //draw the lines

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
    }
}