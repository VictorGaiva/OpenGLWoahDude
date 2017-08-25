#ifndef WEIGHTEDLINE_H
#define WEIGHTEDLINE_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <math.h>

#define TWO_PI 2*M_PI



class WeightedLine : public sf::Drawable, public sf::Transformable
{
public:
    WeightedLine(const sf::Vertex& , const sf::Vertex&, double);
    virtual void draw(sf::RenderTarget &, sf::RenderStates ) const;


private:
    sf::Vertex vertices[4];
    float thickness;
    sf::Color color;
};

#endif