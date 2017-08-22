#include "LineShapes.h"

LineShapes::LineShapes(sf::Vector2f _pos, float _radius, unsigned int _count){
    for (int i = 0; i < _count; i++){
        double x = _radius * cos((TWO_PI/_count)*i);
        double y = _radius * sin((TWO_PI/_count)*i);
        this->vertices.append(sf::Vertex(sf::Vector2f(x, y)));
    }
}

void draw(sf::RenderTarget & target, sf::RenderStates states){

}