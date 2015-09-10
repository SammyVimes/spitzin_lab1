#include "Shapes.h"

Shape::Shape(int lineWidth, float xCenter, float yCenter){
	this->lineWidth = lineWidth;
	this->xCenter = xCenter;
	this->yCenter = yCenter;
}

void Shape::setCenter(float xCenter, float yCenter){
	this->xCenter = xCenter;
	this->yCenter = yCenter;
}

void Shape::setLineWidth(int lineWidth){
	this->lineWidth = lineWidth;
}

float Shape::getX() const {
	return this->xCenter;
}

float Shape::getY() const {
	return this->yCenter;
}

int Shape::getLineWidth() const {
	return this->lineWidth;
}

std::ostream& operator<< (std::ostream& stream, const Shape& shape){
	//shape.draw(stream);
	stream << "\nThe central point is (" << shape.getX() << ", " << shape.getY() << "); line width = " << shape.getLineWidth() << ".";
	return stream;
}

Circle::Circle(float radius, int lineWidth, float xCenter, float yCenter): Shape(lineWidth, xCenter, yCenter){
	this->radius = radius;
}

void Circle::draw(std::ostream& stream){
	stream << "I'm a circle with radius " << this->radius << ";";
}

Text::Text(int font_size, std::string text){
	this->font_size = font_size;
	this->text = text;
}


DoubleCircle::DoubleCircle(float radius, float inner_radius, int lineWidth, float xCenter, float yCenter): Circle(radius, lineWidth, xCenter, yCenter){
	this->inner_radius = inner_radius;
}

void DoubleCircle::draw(std::ostream& stream){
	stream << "I'm a section of the torus with inner radius = " << this->inner_radius << " and outer radius = " << this->radius << ";";
}

CircleText::CircleText(float radius, int font_size, std::string text, int lineWidth, float xCenter, float yCenter): Circle(radius, lineWidth, xCenter, yCenter), Text(font_size, text){}

void CircleText::draw(std::ostream& stream){
	stream << "I'm a text inside the circle with radius = " << this->radius << ", font size = " << this->font_size << " and text = '" << this->text << "';";
}