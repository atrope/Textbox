// stdafx.cpp : source file that includes just the standard includes
// Textbox.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information
#include "stdafx.h"
#include <stdio.h>
#include <Windows.h>
#include "Textbox.h"
#include <string>
#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	const int maxWidth = 20;
	const COORD pos = { 30,10 };
	HANDLE in = GetStdHandle(STD_INPUT_HANDLE);
	INPUT_RECORD ir;
	DWORD count;
	int pL; //Pressed Letter
	Textbox textbox(pos,maxWidth);
	while (ReadConsoleInput(in, &ir, 1, &count)) {
		pL = int(ir.Event.KeyEvent.uChar.AsciiChar);
		if (ir.Event.KeyEvent.bKeyDown && pL > 0) {
			if (pL == 8) textbox.delChar();	
			else if (pL == 27) break;
			else if (pL >= 32 &&  pL<=126) textbox.addValue(ir.Event.KeyEvent.uChar.AsciiChar);
		}
	}
	return 0;
}