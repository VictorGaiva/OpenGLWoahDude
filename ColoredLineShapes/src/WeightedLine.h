#ifndef WEIGHTEDLINE_H
#define WEIGHTEDLINE_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class WeightedLine : public sf::Drawable, public sf::Transformable{
public:
    WeightedLine(sf::Vector2f, sf::Vector2f, double, sf::Color);

    WeightedLine(double, double, double, double, double, sf::Color);
    ~WeightedLine();

private:
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
    sf::VertexArray vertices;
    double weight;
};

#endif
