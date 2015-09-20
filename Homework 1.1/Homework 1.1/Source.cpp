#include<windows.h>
#include<tchar.h>

INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpczCmdLine, int nCmdShow) {
	wchar_t MB1[] = L"Орлов Олег Александрович";
	MessageBox(0,
		MB1,
		TEXT("ФИО"),
		MB_OK | MB_ICONINFORMATION);
	
	wchar_t MB2[] = L"Ищу работу в сфере информационных технологий";
	MessageBox(0,
		MB2,
		TEXT("Цель"),
		MB_OK | MB_ICONINFORMATION);

	wchar_t MB3[] = L"Родился 20 июня 1986 года, в городе Николаеве";
	MessageBox(0,
		MB3,
		TEXT("Общая информация о себе"),
		MB_OK | MB_ICONINFORMATION);
	
	int nSize = wcslen(MB1) / sizeof(wchar_t);
	wchar_t size[4] = L"101";

	MessageBox(0,
		TEXT("абра-кадабра"),
		(LPWSTR) nSize,
		MB_OK | MB_ICONINFORMATION);
	return 0;
}