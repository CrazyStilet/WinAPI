#include<windows.h>
using namespace std;

INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow) {
	MessageBox(0, TEXT("Привет!"), TEXT("Мир!"), MB_OK);
}