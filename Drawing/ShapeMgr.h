#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Shape.h"

using namespace std;
using namespace sf;

// ShapeMgr class does all of the important stuff with the current shape logic
class ShapeMgr {
private:
	vector<DrawingShape*> shapesDrawn; // this contains all of the shapes that are drawn on the canvas
									   // along with their position and color 
public:
	ShapeMgr() { }

	// adds a new shape (circle or square) to the shapesDrawn vector 
	void addShape(Vector2f pos, ShapeEnum whichShape, Color color) {
		if (whichShape == CIRCLE) { // circle
			Circle *newCircle;
			newCircle = new Circle(color, pos);
			shapesDrawn.push_back(newCircle);

		} else { // square
			Square *newSquare;
			newSquare = new Square(color, pos);
			shapesDrawn.push_back(newSquare);
		}
	}

	// returns the shapesDrawn vector, used for writing to the binary file 
	const vector<DrawingShape*>& getShapes() {
		return shapesDrawn;
	}

	// reads the shapesDrawn vector from the binary file 
	void readFile(fstream& file) {
		record inshape;
		while (file.read(reinterpret_cast<char*>(&inshape), sizeof(inshape))) {
			addShape(Vector2f(inshape.x, inshape.y), inshape.shape, Color(inshape.color));
		}
	}

	// writes the shapesDrawn vector the the binary file 
	void writeFile(fstream& file) {
		for (int i = 0; i < shapesDrawn.size(); i++) {
			file.write(reinterpret_cast<char*>(&shapesDrawn[i]->getRecord()), sizeof(record));
		}
	}
};
