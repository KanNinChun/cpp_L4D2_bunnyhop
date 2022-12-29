#pragma once
#include"console.h"

bool check_handle(const HWND Game_handle)
{
	console(750, 180);
	if (!Game_handle)
	{
		MessageBoxA(NULL, "Please Start Left 4 Dead 2 first ...", "Error Message", MB_ICONERROR | MB_OK);
		exit(-1);
		return false;
	}
	else
	{
		std::cout << "Game Handle Found" << std::endl;
		std::cout << std::endl;
		std::cout << "Press mouse side button (XBUTTON 1) to use auto pistol" << std::endl;
		std::cout << "Press Numpad 1 to enable/disable Bunnyhop" << std::endl;
		std::cout << "Press Numpad 2 to hide/show console" << std::endl;
		std::cout << std::endl;
		print_colored(FOREGROUND_RED, "Tip:");
		std::cout << "Open game console and type cl_showpos 1 to show velocity..." << std::endl;
		std::cout << "Please notice that you can not bhoping and autopistol at the same time..." << std::endl;
		Beep(330, 100);
		return true;
	}
}