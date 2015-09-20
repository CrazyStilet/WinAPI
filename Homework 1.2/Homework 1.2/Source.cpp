#include<windows.h>
#include<tchar.h>

INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpczCmdLine, int nCmdShow) {
	wchar_t size[4] = L"101";

	MessageBox(0,
		TEXT("абра-кадабра"),
		size,
		MB_OK | MB_ICONINFORMATION);
	return 0;
}