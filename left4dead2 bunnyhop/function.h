#pragma once
void bunnyhop(const HWND Game_handle)
{
	if (GetKeyState(VK_NUMPAD1) & 1)
	{
		if (GetAsyncKeyState(VK_SPACE) & 0x8000 )
		{
			SendMessageA(Game_handle, WM_KEYDOWN, VK_SPACE, 0X390000);
			Sleep(18); // must have, give some delay to avoid it pressing the key too fast
			SendMessageA(Game_handle, WM_KEYUP, VK_SPACE, 0X390000);
			Sleep(1);  // must have, give some delay to avoid it pressing the key too fast
		}
	}
}

