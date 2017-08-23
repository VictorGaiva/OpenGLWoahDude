#include "LineShapes.h"

LineShapes::LineShapes(sf::Vector2f _pos, float _radius, unsigned int _count){
    //Set center position
    this->screenPos = _pos;
    this->vertices.setPrimitiveType(sf::LinesStrip);
    //Calculate vertices positions
    for (int i = 0; i <= _count; i++){
        double x = _radius * cos((TWO_PI/_count)*i);
        double y = _radius * sin((TWO_PI/_count)*i);
        this->vertices.append(sf::Vertex(sf::Vector2f(x, y), sf::Color::Black));
    }
}

void LineShapes::draw(sf::RenderTarget & target, sf::RenderStates states) const{
    //apply the transforms
    states.transform *= getTransform();
    states.transform.translate(this->screenPos);
    
    // draw the vertex array
    target.draw(this->vertices, states);
}