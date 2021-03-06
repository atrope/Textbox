// Textbox.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Textbox.h"
#include <iostream>

void Textbox::draw() {
	gotoxy(this->position.X, this->position.Y);
	cout << value; 
}
void Textbox::addValue(CHAR newvalue) {
	if (this->width < this->maxWidth) {
		this->width++;
		this->value.push_back(newvalue);
		draw();
	}
}
void Textbox::delChar() {
	if (this->width) {
		this->value.replace(this->value.size() - 1, 1, " ");
		draw(); // Draw string without the Char
		this->value.pop_back(); //Remove it
		this->width--;
		gotoxy(this->position.X + this->width, this->position.Y); //Refresh Cursor
	}
}
void Textbox::gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Textbox::makeRect() { // make Rectangle over text
	gotoxy(this->position.X - 1, this->position.Y);
	cout << "\xB3";
	gotoxy(this->position.X + this->maxWidth, this->position.Y);
	cout << "\xB3";
	gotoxy(this->position.X - 1, this->position.Y - 1);
	cout << "\xDA";
	gotoxy(this->position.X - 1, this->position.Y + 1);
	cout << "\xC0";
	gotoxy(this->position.X + this->maxWidth, this->position.Y - 1);
	cout << "\xBF";
	gotoxy(this->position.X + this->maxWidth, this->position.Y + 1);
	cout << "\xD9";
	for (int i = 0; i < this->maxWidth; i++) {
		gotoxy(this->position.X + i, this->position.Y - 1);
		cout << "\xC4";
		gotoxy(this->position.X + i, this->position.Y + 1);
		cout << "\xC4";
	}
	gotoxy(this->position.X, this->position.Y); // Refresh cursor position
}