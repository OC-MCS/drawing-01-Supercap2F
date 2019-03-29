#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

enum ShapeEnum { CIRCLE, SQUARE };

// This code takes care of all of the logic relating to the menu buttons on the left
class SettingsMgr {
private:
	Color selectedColor;		// contains the current color the user selected
	ShapeEnum selectedShape;	// contains the current shape the user selected
public:
	// constructor that sets up the default shape and color values for the menu
	SettingsMgr(Color startingColor, ShapeEnum startingShape ) {
		selectedColor = startingColor;
		selectedShape = startingShape;
	}

	void setCurColor(Color c) {
		selectedColor = c;
	}

	void setCurShape (ShapeEnum c) {
		selectedShape = c;
	}

	Color getCurColor() {
		return selectedColor; // just to make it compile 
	}

	ShapeEnum getCurShape() {
		return selectedShape; // just to make it compile;
	}

	// used for reading the last menu settings from the file
	void readFile(fstream& myFile) {
		unsigned int set;
		myFile.read(reinterpret_cast<char*>(&set), sizeof(unsigned int));
		myFile.read(reinterpret_cast<char*>(&selectedShape), sizeof(ShapeEnum));
		selectedColor = Color(set);
	}

	// used for writing the last menu settings to the file 
	void writeFile(fstream& myFile) {
		unsigned int set = selectedColor.toInteger();
		myFile.write(reinterpret_cast<char*>(&set), sizeof(unsigned int));
		myFile.write(reinterpret_cast<char*>(&selectedShape), sizeof(ShapeEnum));
	}

};
