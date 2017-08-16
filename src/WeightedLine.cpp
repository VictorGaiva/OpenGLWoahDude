#include "WeightedLine.h"
#include <math.h>

WeightedLine::WeightedLine(sf::Vector2f _point1, sf::Vector2f _point2, double _weight, sf::Color color){
    //Taking the normal vector to the line
    sf::Vector2f normalVector(-(_point1.y - _point2.y), (_point1.x - _point2.x));

    //Setting the right lenght for the normalVector
    double multiplier = _weight/sqrt(normalVector.x*normalVector.x + normalVector.y*normalVector.y);
    normalVector.x *= multiplier;
    normalVector.y *= multiplier;

    //Creating the vertices of the shape
    this->vertices.setPrimitiveType(sf::Quads);
    this->vertices.append(sf::Vertex(_point1 + normalVector, color));
    this->vertices.append(sf::Vertex(_point1 - normalVector, color));
    this->vertices.append(sf::Vertex(_point2 - normalVector, color));
    this->vertices.append(sf::Vertex(_point2 + normalVector, color));
    
}

WeightedLine::WeightedLine(double x1, double y1, double x2, double y2, double _weight, sf::Color color){
    sf::Vector2f _point1(x1, y1);
    sf::Vector2f _point2(x2, y2);
    //Taking the normal vector to the line
    sf::Vector2f normalVector(-(_point1.y - _point2.y), (_point1.x - _point2.x));
    
    //Setting the right lenght for the normalVector
    double multiplier = _weight/sqrt(normalVector.x*normalVector.x + normalVector.y*normalVector.y);
    normalVector.x *= multiplier;
    normalVector.y *= multiplier;

    //Creating the vertices of the shape
    this->vertices.setPrimitiveType(sf::Quads);
    this->vertices.append(sf::Vertex(_point1 + normalVector, color));
    this->vertices.append(sf::Vertex(_point1 - normalVector, color));
    this->vertices.append(sf::Vertex(_point2 - normalVector, color));
    this->vertices.append(sf::Vertex(_point2 + normalVector, color));
}

WeightedLine::~WeightedLine(){
    //don't know why I'm doing this...
    this->vertices.clear();
}

void WeightedLine::draw(sf::RenderTarget& target, sf::RenderStates state) const{
    //
    target.draw(this->vertices);
}
