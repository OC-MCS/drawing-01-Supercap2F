#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

// this is used for returning shapes and their position from the circle and square functions 
struct record {
	ShapeEnum shape;     // holds the type of shape 
	float x, y;			 // holds the position of the shape
	unsigned int color;  // holds the color of the shape
};

// DrawingShape should be an abstract base class 
// for Circle and Square
class DrawingShape {
public:
	Color color;  // color of the shape
	Vector2f pos; // position of the shape 

	virtual void draw(RenderWindow &w) = 0;
	virtual record getRecord() = 0;
};

// Circle class, derived from the drawing shape class
class Circle : public DrawingShape {
private:
	CircleShape circle;   
	const int RADIUS = 10; 
public:
	Circle(Color c, Vector2f p) { 
		color = c;
		pos = p;
		circle.setPosition(p);
		circle.setRadius(RADIUS);
		circle.setOutlineThickness(2);
		circle.setOutlineColor(c);
		circle.setFillColor(c);
	};

	void draw(RenderWindow &w) {
		w.draw(circle);
	};

	record getRecord() {
		return { CIRCLE, pos.x, pos.y, circle.getFillColor().toInteger() };
	}
};

// Square class, derived from the drawing shape class
class Square : public DrawingShape {
private:
	RectangleShape square;
	const int size = 10;

public:
	Square(Color c, Vector2f p) {
		color = c;
		pos = p;
		square.setPosition(p);
		square.setOutlineColor(c);
		square.setOutlineThickness(2);
		square.setSize(Vector2f(size, size));
		square.setFillColor(c);
	};

	void draw(RenderWindow &w) {
		w.draw(square);
	};

	record getRecord() {
		return { CIRCLE, pos.x, pos.y, square.getFillColor().toInteger() };
	}
};
