#include"handle.h"
#include"console.h"
#include"function.h"
using namespace std;

// Reference video
// https://www.youtube.com/watch?v=A5kSHtROX1c 

// SendMessageA Document
// https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-sendmessage

// SendMessageA LPARAM 0x390000 Document
// https://learn.microsoft.com/en-us/windows/win32/inputdev/about-keyboard-input#keystroke-message-flags
// Key location	101/102 Enhanced keyboard	Scan 1 make	 Scan 1 break
//      61			      Space Bar				39			 B9

const char* handle_name{ "Left 4 Dead 2 - Direct3D 9" };
const HWND  Game_handle{ FindWindowA(NULL, handle_name) };

int main()
{
	check_handle(Game_handle);

	while (true)
	{
		setTitle();
		hideConsole();
		bunnyhop(Game_handle);
		autopistol();
		Sleep(1); // Add Sleep to optimize the CPU useage
	}
	return 0;
}

//Discord: Hippo#6524