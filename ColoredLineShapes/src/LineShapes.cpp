#include "LineShapes.h"

LineShapes::LineShapes(sf::Vector2f _pos, float _radius, unsigned int _count, float _thickness, sf::Color _def){
    //Set center position
    double count = _count;

    this->thickness = _thickness;
    this->shapeTransform.translate(_pos);
    this->shapeTransform.rotate(90.0-(180.0/count));
    this->defaultColor = _def;

    //Calculate vertices positions
    for (int i = 0; i < _count; i++){
        double x = _radius * cos((TWO_PI/count)*i);
        double y = _radius * sin((TWO_PI/count)*i);
        this->vertices.append(sf::Vertex(sf::Vector2f(x, y), this->defaultColor));
    }
}

void LineShapes::draw(sf::RenderTarget & target, sf::RenderStates states) const{

    //apply any existing transform
    states.transform *= getTransform();
    
    //Apply translation and rotation
    states.transform *= this->shapeTransform;

    // draw the vertex array
    for (int i = 0; i < this->vertices.getVertexCount(); i++)
        target.draw(WeightedLine(this->vertices[i], this->vertices[(i+1)%(vertices.getVertexCount())], this->thickness), states);

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