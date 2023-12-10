#include"handle.h"
#include"console.h"
#include"function.h"
using namespace std;

// Reference video
// https://www.youtube.com/watch?v=A5kSHtROX1c 

const char* handle_name  { "Left 4 Dead 2 - Direct3D 9" };
const char* handle_name2 { "Left 4 Dead 2 - Vulkan" };
const HWND  Game_handle  { FindWindowA(NULL, handle_name) };
const HWND  Game_handle2 { FindWindowA(NULL, handle_name2) };
bool Game_running(HWND handle, HWND handle2)
{ 
	if (handle == Game_handle || handle2 == Game_handle2)
	{
		return true;
	}
	else
	{
		MessageBoxA(NULL, "Please Start Left 4 Dead 2 first ...", "Error Message", MB_ICONERROR | MB_OK);
		exit(-1);
		return false;
	}
};

int main()
{
	
	if (Game_running(Game_handle, Game_handle2) == true)
	{
		Menu();
	}

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
