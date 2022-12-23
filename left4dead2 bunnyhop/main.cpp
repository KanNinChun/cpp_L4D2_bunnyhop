#include<iostream>
#include<Windows.h>
#include <time.h>

using namespace std;

// Reference video
// https://www.youtube.com/watch?v=A5kSHtROX1c 

// SendMessageA Document
// https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-sendmessage

// SendMessageA LPARAM 0x390000 Document
// https://learn.microsoft.com/en-us/windows/win32/inputdev/about-keyboard-input#keystroke-message-flags
// Key location	101/102 Enhanced keyboard	Scan 1 make	 Scan 1 break
//      61			      Space Bar				39			 B9

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
//------------------------ End---------------------------//

const char* handle_name{ "Left 4 Dead 2 - Direct3D 9" };
const HWND  Game_handle{ FindWindowA(NULL, handle_name) };

int main()
{
	if (!Game_handle) 
	{
		MessageBoxA(NULL, "Please Start Left 4 Dead 2 first ...", "Error Message", MB_ICONERROR | MB_OK);
		exit(-1);
	}
	else
	{
		std::cout << "Game Handle Found"						 << std::endl;
		std::cout												 << std::endl;
		std::cout << "Press Numpad 1 to enable/disable Bunnyhop" << std::endl;
		std::cout												 << std::endl;
		print_colored(FOREGROUND_RED,"Tip:");
		std::cout << "if you want , you can open game console and type cl_showpos 1 to show velocity" << std::endl;
		
	}

	while (true)
	{
		if (GetKeyState(VK_NUMPAD1) & 1)
		{
			if (GetAsyncKeyState(VK_SPACE))
			{
				SendMessageA(Game_handle, WM_KEYDOWN, VK_SPACE, 0X390000);
				Sleep(18); // must have, give some delay to avoid it pressing the key too fast
				SendMessageA(Game_handle, WM_KEYUP, VK_SPACE, 0X390000);
				Sleep(1);  // must have, give some delay to avoid it pressing the key too fast
			}
		}
				Sleep(1); // Add Sleep to optimize the CPU useage
	}
	return 0;
}

//Discord: Hippo#6524