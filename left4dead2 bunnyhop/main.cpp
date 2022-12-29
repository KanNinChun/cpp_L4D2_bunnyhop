#include"handle.h"
#include"console.h"
#include"function.h"
using namespace std;

// Reference video
// https://www.youtube.com/watch?v=A5kSHtROX1c 

const char* handle_name { "Left 4 Dead 2 - Direct3D 9" };
const HWND  Game_handle { FindWindowA(NULL, handle_name) };

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
