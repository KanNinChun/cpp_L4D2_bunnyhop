#pragma once
#include<Windows.h>

// SendMessageA Document
// https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-sendmessage

// SendMessageA LPARAM 0x390000 Document
// https://learn.microsoft.com/en-us/windows/win32/inputdev/about-keyboard-input#keystroke-message-flags
// Key location	101/102 Enhanced keyboard	Scan 1 make	 Scan 1 break
//      61			      Space Bar				39			 B9

void bunnyhop(const HWND Game_handle)
{
	if (GetKeyState(VK_NUMPAD1) & 1)
	{
		if (GetAsyncKeyState(VK_SPACE) & 0x8000 )
		{
			SendMessageA(Game_handle, WM_KEYDOWN, VK_SPACE, 0X390000);
			Sleep(1);   // must have, give some delay to avoid it pressing the key too fast
			SendMessageA(Game_handle, WM_KEYUP, VK_SPACE, 0X390000);
			Sleep(17);  // must have, give some delay to avoid it pressing the key too fast
		}
	}
}

void autopistol()
{
	while (GetAsyncKeyState(VK_XBUTTON1))
	{
		mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
		Sleep(1);  // must have delay , otherwise it won't work
		mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		Sleep(19); // must have delay , otherwise it won't work
	}

}
