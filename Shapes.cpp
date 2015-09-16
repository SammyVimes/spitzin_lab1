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

std::ostream& operator<< (std::ostream& stream, Shape& shape){
	shape.draw(stream);
	stream << "\nThe central point is (" << shape.getX() << ", " << shape.getY() << "); line width = " << shape.getLineWidth() << ".";
	/*if (dynamic_cast<CircleText*>(&shape) != NULL){
		CircleText* elem = dynamic_cast<CircleText*>(&shape);
		stream << "I'm a circle with radius " << elem->getRadius() << ";";
	} else if (dynamic_cast<DoubleCircle*>(&shape) != NULL){
		DoubleCircle* elem = dynamic_cast<DoubleCircle*>(&shape);
		stream << "I'm a section of the torus with inner radius = " << elem->getInnerRadius() << " and outer radius = " << elem->getRadius() << ";";
	} else if (dynamic_cast<Text*>(&shape) != NULL){
		Text* elem = dynamic_cast<Text*>(&shape);
		stream << "I'm a text with font size = " << elem->getFontSize() << " and text = '" << elem->getText() << "';";
	} else if (dynamic_cast<Circle*>(&shape) != NULL){
	} else {
	}*/
	return stream;
}

Circle::Circle(float radius, int lineWidth, float xCenter, float yCenter): Shape(lineWidth, xCenter, yCenter){
	this->radius = radius;
}

void Circle::draw(std::ostream& stream){
	stream << "I'm a circle with radius " << this->radius << ";";
}

float Circle::getRadius() const{
	return this->radius;
}

Text::Text(int font_size, std::string text, int lineWidth, float xCenter, float yCenter): Shape(lineWidth, xCenter, yCenter){
	this->font_size = font_size;
	this->text = text;
}

void Text::draw(std::ostream& stream){
	stream << "I'm a text with font size = " << this->getFontSize() << " and text = '" << this->getText() << "';";
}

int Text::getFontSize() const {
	return this->font_size;
}

std::string Text::getText() const {
	return text;
}


DoubleCircle::DoubleCircle(float radius, float inner_radius, int lineWidth, float xCenter, float yCenter): Circle(radius, lineWidth, xCenter, yCenter), Shape(lineWidth, xCenter, yCenter){
	this->inner_radius = inner_radius;
}

void DoubleCircle::draw(std::ostream& stream){
	stream << "I'm a section of the torus with inner radius = " << this->getInnerRadius() << " and outer radius = " << this->getRadius() << ";";
}

float DoubleCircle::getInnerRadius() const {
	return inner_radius;
}

CircleText::CircleText(float radius, int font_size, std::string text, int lineWidth, float xCenter, float yCenter): Circle(radius, lineWidth, xCenter, yCenter), Text(font_size, text, lineWidth, xCenter, yCenter), Shape(lineWidth, xCenter, yCenter){}

void CircleText::draw(std::ostream& stream){
	stream << "I'm a text inside the circle with radius = " << this->radius << ", font size = " << this->font_size << " and text = '" << this->text << "';";
}