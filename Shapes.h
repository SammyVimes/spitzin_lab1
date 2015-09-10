#pragma once
#include <iostream>
#include <string>

class Shape {
protected:
	float xCenter, yCenter;
	float lineWidth;
public:
	Shape (float lineWidth, float xCenter, float yCenter);
	virtual void draw () = 0;
	virtual friend std::ostream& operator<< (std::ostream& stream, const Shape& shape) = 0;
	void setCenter (float xCenter, float yCenter);
	float getX () const;
	float getY () const;
};

class Circle: public Shape {
protected:
	float radius;
public:
	Circle(float radius, float lineWidth, float xCenter, float yCenter); 
	void draw ();
	friend std::ostream& operator<< (std::ostream& stream, const Shape& shape);
};

class Text: public Shape {
protected:
	int font_size;
	std::string text;
public:
	Text(int font_size, std::string text, float lineWidth, float xCenter, float yCenter);
	void draw ();
	friend std::ostream& operator<< (std::ostream& stream, const Shape& shape);
};

class DoubleCircle: public Circle, public Shape {
private:
	float inner_radius;
public:
	DoubleCircle(float radius, float inner_radius, float lineWidth, float xCenter, float yCenter);
	void draw ();
	friend std::ostream& operator<< (std::ostream& stream, const Shape& shape);
};

class CircleText: public Circle, public Text, public Shape  {
public:
	CircleText(float radius, float inner_radius, int font_size, std::string text, float lineWidth, float xCenter, float yCenter);
	void draw ();
	friend std::ostream& operator<< (std::ostream& stream, const Shape& shape);
};