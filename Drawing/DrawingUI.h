#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "ShapeMgr.h"

// DrawingUI, has all the code for creating the menu on the left side of the program
class DrawingUI {
private:
	RectangleShape canvas; // the white rectangle known as the canvas
public:
	// constructor that sets up the position and the color for the canvas
	DrawingUI(Vector2f p) {
		canvas.setPosition(p);
		canvas.setOutlineColor(Color::White);
		canvas.setOutlineThickness(1);
		canvas.setSize(Vector2f(550, 500));
	}

	// this function draws the canvas along with all of the points in the shapes vector
	void draw(RenderWindow& win, ShapeMgr *mgr) {
		win.draw(canvas);

		vector<DrawingShape*> shapes = mgr->getShapes();
		for (int x = 0; x < shapes.size(); x++) {
			shapes[x]->draw(win);
		}
	}
	
	// this function checks to see if the mouse is over the canvas, and if it is it returns true 
	// used when creating a new shape
	bool isMouseInCanvas(Vector2f mousePos) {
		if (canvas.getGlobalBounds().contains(mousePos) && canvas.getGlobalBounds().contains(Vector2f(mousePos.x + 10, mousePos.y + 10))) {
			return true;
		}
		else {
			return false;
		}
	};
};

