#include "LineShapes.h"

LineShapes::LineShapes(sf::Vector2f _pos, float _radius, unsigned int _count, float _thickness){
    //Set center position
    this->thickness = _thickness;
    this->screenPos = _pos;
    this->defaultColor = sf::Color::Black;

    this->vertices.setPrimitiveType(sf::LinesStrip);
    //Calculate vertices positions
    for (int i = 0; i < _count; i++){
        double x = _radius * cos((TWO_PI/_count)*i);
        double y = _radius * sin((TWO_PI/_count)*i);
        this->vertices.append(sf::Vertex(sf::Vector2f(x, y), this->defaultColor));
    }
}

void LineShapes::draw(sf::RenderTarget & target, sf::RenderStates states) const{
    //apply any existing transform
    states.transform *= getTransform();
    //Translate to the right screen position
    states.transform.translate(this->screenPos);
    
    // draw the vertex array
    for (int i = 0; i < this->vertices.getVertexCount(); i++){
        target.draw(WeightedLine(this->vertices[i], this->vertices[(i+1)%(vertices.getVertexCount())], this->thickness), states);
        //this->vertices.append(sf::Vertex(sf::Vector2f(x, y), sf::Color::Black));
    }

    //target.draw(this->vertices, states);
}

bool LineShapes::setColorAt(sf::Color newColor, unsigned int index){
    bool ret = true;
    if(index >= this->vertices.getVertexCount()){
        std::cout << "Index out of range." << std::endl;
        return false;
    }
    if(this->vertices[index].color != newColor)
        ret = false;
    
    this->vertices[index].color = newColor;
    
    return ret;
}
sf::Color LineShapes::getColorAt(unsigned int i){return this->vertices[i].color;}