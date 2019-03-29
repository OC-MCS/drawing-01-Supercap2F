#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "SettingsMgr.h"

// This class draws the menu on the left side of the screen
class SettingsUI {
private:
	CircleShape blueBtn, redBtn, greenBtn, circleBtn; // Instances for each of the buttons 
	RectangleShape squareBtn;

	SettingsMgr *settingsManager; // create an instance of a settings manager 
public:
	// the constructor simply creates a pointer to the previously created settings manager
	SettingsUI(SettingsMgr *mgr) {
		settingsManager = mgr;
	}

	// this function takes care of when one of the buttons on the left side is pressed 
	void handleMouseUp(Vector2f mouse) {
		if (blueBtn.getGlobalBounds().contains(mouse)) {
			settingsManager->setCurColor(Color::Blue);
		} else if (redBtn.getGlobalBounds().contains(mouse)) {
			settingsManager->setCurColor(Color::Red);
		} else if (greenBtn.getGlobalBounds().contains(mouse)) {
			settingsManager->setCurColor(Color::Green);
		}

		if (circleBtn.getGlobalBounds().contains(mouse)) {
			settingsManager->setCurShape(CIRCLE);
		}
		else if (squareBtn.getGlobalBounds().contains(mouse)) {
			settingsManager->setCurShape(SQUARE);
		}
	}

	// this function draws the menu on the left side 
	void draw(RenderWindow& win) {
		// first have to load font
		Font font;
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
			die("couldn't load font");

		// Selected Color Title
		Text title1("Selected Color", font, 25);
		title1.setPosition(30, 25);
		win.draw(title1);

		// Selected Shape Title
		Text title2("Selected Shape", font, 25);
		title2.setPosition(30, 330);
		win.draw(title2);

		// draw circles and squares 
		Vector2f pos(100, 100);
		blueBtn.setPosition(pos);
		blueBtn.setRadius(15);
		blueBtn.setOutlineThickness(2);
		blueBtn.setOutlineColor(Color::Blue);
		// for just an outlined button
		if (settingsManager->getCurColor() == Color::Blue) {
			blueBtn.setFillColor(Color::Blue);
		} else {
			blueBtn.setFillColor(Color::Transparent);
		}
		// The following renders the circle on the screen
		// win is a RenderWindow (see provided code)
		win.draw(blueBtn);


		pos.x = 100;
		pos.y = 175;
		redBtn.setPosition(pos);
		redBtn.setRadius(15);
		redBtn.setOutlineThickness(2);
		redBtn.setOutlineColor(Color::Red);
		// for just an outlined button
		if (settingsManager->getCurColor() == Color::Red) {
			redBtn.setFillColor(Color::Red);
		} else {
			redBtn.setFillColor(Color::Transparent);
		}
		// The following renders the circle on the screen
		// win is a RenderWindow (see provided code)
		win.draw(redBtn);


		pos.x = 100;
		pos.y = 250;
		greenBtn.setPosition(pos);
		greenBtn.setRadius(15);
		greenBtn.setOutlineThickness(2);
		greenBtn.setOutlineColor(Color::Green);
		if (settingsManager->getCurColor() == Color::Green) {
			greenBtn.setFillColor(Color::Green);
		} else {
			greenBtn.setFillColor(Color::Transparent);
		}
		// The following renders the circle on the screen
		// win is a RenderWindow (see provided code)
		win.draw(greenBtn);


		pos.x = 100;
		pos.y = 400;
		circleBtn.setPosition(pos);
		circleBtn.setRadius(15);
		circleBtn.setOutlineThickness(2);
		circleBtn.setOutlineColor(Color::White);
		// for just an outlined button
		if (settingsManager->getCurShape() == CIRCLE) {
			circleBtn.setFillColor(Color::White);
		} else {
			circleBtn.setFillColor(Color::Transparent);
		}
		// The following renders the circle on the screen
		// win is a RenderWindow (see provided code)
		win.draw(circleBtn);


		 // RectangleShape is Graphics lib class
		Vector2f sqPos(100, 480);
		squareBtn.setPosition(sqPos);
		squareBtn.setOutlineColor(Color::White);
		squareBtn.setOutlineThickness(2);
		squareBtn.setSize(Vector2f(30, 30));
		if (settingsManager->getCurShape() == SQUARE) {
			squareBtn.setFillColor(Color::White);
		} else {
			squareBtn.setFillColor(Color::Transparent);
		}
		// renders a RectangleShape
		win.draw(squareBtn);
	}

	// this function exits the program if an error is encountered 
	void die(string msg) {
		cout << msg << endl;
		exit(-1);
	}
};
