// Textbox.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Textbox.h"
#include <iostream>

void Textbox::draw() {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(out, &info);
	SetConsoleCursorPosition(out, this->position);
	std::cout << value;
	SetConsoleTextAttribute(out, info.wAttributes);
	SetConsoleCursorPosition(out, info.dwCursorPosition);
	gotoxy(this->position.X + this->width, this->position.Y);
}

void Textbox::delChar() {
	if (this->width) {
		this->value.replace(this->value.size() - 1, 1, " ");
		draw();
		this->value.pop_back();
		this->width--;
		draw();
	}
}



void Textbox::gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Textbox::makeRect() {
	gotoxy(this->position.X - 1, this->position.Y);
	cout << "\xB3";
	gotoxy(this->position.X + this->maxWidth, this->position.Y);
	cout << "\xB3";
	for (int i = 0; i < this->maxWidth; i++) {
		gotoxy(this->position.X - 1, this->position.Y - 1);
		cout << "\xDA";
		gotoxy(this->position.X - 1, this->position.Y + 1);
		cout << "\xC0";
		gotoxy(this->position.X + this->maxWidth, this->position.Y - 1);
		cout << "\xBF";
		gotoxy(this->position.X + this->maxWidth, this->position.Y + 1);
		cout << "\xD9";
		gotoxy(this->position.X + i, this->position.Y - 1);
		cout << "\xC4";
		gotoxy(this->position.X + i, this->position.Y + 1);
		cout << "\xC4";
	}
	gotoxy(this->position.X, this->position.Y);
}