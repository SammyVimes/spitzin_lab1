#pragma once
#include <iostream>
#include <string>

class Shape {
protected:
	float xCenter, yCenter;
	int lineWidth;
public:
	Shape (int lineWidth, float xCenter, float yCenter);
	virtual void draw (std::ostream& stream) = 0;
	friend std::ostream& operator<< (std::ostream& stream, Shape& shape);
	void setCenter (float xCenter, float yCenter);
	void setLineWidth(int lineWidth);
	float getX () const;
	float getY () const;
	int getLineWidth () const;
};

class Circle: public virtual Shape {
protected:
	float radius;
public:
	Circle(float radius, int lineWidth, float xCenter, float yCenter); 
	void draw (std::ostream& stream);
	float getRadius() const;
};

class DoubleCircle: public Circle {
private:
	float inner_radius;
public:
	DoubleCircle(float radius, float inner_radius, int lineWidth, float xCenter, float yCenter);
	void draw (std::ostream& stream);
	float getInnerRadius() const;
};

class Text: public virtual Shape {
protected:
	int font_size;
	std::string text;
public:
	void draw (std::ostream& stream);
	Text(int font_size, std::string text, int lineWidth, float xCenter, float yCenter);
	int getFontSize() const;
	std::string getText() const;
};

class CircleText: public Circle, public Text  {
public:
	CircleText(float radius, int font_size, std::string text, int lineWidth, float xCenter, float yCenter);
	void draw (std::ostream& stream);
};