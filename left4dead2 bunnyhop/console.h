#pragma once
#include<iostream>
#include<Windows.h>
#include <time.h>

// Set console color Document
// https://stackoverflow.com/questions/20608058/c-colour-console-text

//------------------------ console stuff-------------------//
void change_color(const int color_flags)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color_flags);
}

template <class T>
void print_colored(const int color_flags, const T& arg)
{
	change_color(color_flags);
	std::cout << arg << std::endl;;
	change_color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//back to normal
}

void console(int width = 750, int height = 180) // Default value
{
	HWND console = GetConsoleWindow();
	SetConsoleTitleA("l4d2 bh");
	MoveWindow(console, 0, 0, width, height, TRUE);
}

void hideConsole()
{
	if (GetKeyState(VK_NUMPAD2) & 1)
	{
		ShowWindow(GetConsoleWindow(), SW_HIDE);

	}
	else
	{
		ShowWindow(GetConsoleWindow(), SW_SHOW);
		
	}
}
//------------------------ End---------------------------//

// Center Console Code and set topmost
//int posx = GetSystemMetrics(SM_CXSCREEN) / 2 - width / 2;
//int posy = GetSystemMetrics(SM_CYSCREEN) / 2 - height / 2;
//MoveWindow(console, posx, posy, width, height, TRUE);
//SetWindowPos(console, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);