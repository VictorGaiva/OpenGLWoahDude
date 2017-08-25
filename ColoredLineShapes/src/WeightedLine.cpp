#include "WeightedLine.h"
#include <math.h>

WeightedLine::WeightedLine(const sf::Vertex& point1, const sf::Vertex& point2, double _thickness){
    sf::Vector2f direction = point2.position - point1.position;
    
    double multiplier = sqrt(direction.x*direction.x+direction.y*direction.y);
    
    sf::Vector2f unitDirection(direction.x / multiplier, direction.y / multiplier);
    sf::Vector2f unitPerpendicular(-unitDirection.y,unitDirection.x);

    sf::Vector2f offset((_thickness*unitPerpendicular.x)/2, (_thickness*unitPerpendicular.y)/2);

    vertices[0].position = point1.position + offset;
    vertices[0].color = point1.color;

    vertices[1].position = point2.position + offset;
    vertices[1].color = point2.color;

    vertices[2].position = point2.position - offset;
    vertices[2].color = point2.color;

    vertices[3].position = point1.position - offset;
    vertices[3].color = point1.color;
}

void WeightedLine::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    //apply any existing transform
    states.transform *= getTransform();

    target.draw(vertices,4,sf::Quads, states);
}