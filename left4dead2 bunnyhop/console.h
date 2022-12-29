#pragma once
#include<iostream>
#include<Windows.h>
#include <time.h>

// Set console color Document
// https://stackoverflow.com/questions/20608058/c-colour-console-text

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

void console(int width, int height)
{
	HWND console = GetConsoleWindow();
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

inline std::string Randomtitle(size_t length)
{
	std::string r;
	static const char bet[] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890/*-+!@#$%^&*" };
	srand((unsigned)time(NULL) * 5);
	for (int i = 0; i < length; ++i)
	{
		r += bet[rand() % (sizeof(bet) - 1)];
	}
	return r;
}

void setTitle()
{
	SetConsoleTitleA(Randomtitle(26).c_str());
}