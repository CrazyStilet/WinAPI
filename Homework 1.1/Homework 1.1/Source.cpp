#include<windows.h>
#include<tchar.h>

INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpczCmdLine, int nCmdShow) {
	wchar_t MB1[] = L"����� ���� �������������";
	MessageBox(0,
		MB1,
		TEXT("���"),
		MB_OK | MB_ICONINFORMATION);
	
	wchar_t MB2[] = L"��� ������ � ����� �������������� ����������";
	MessageBox(0,
		MB2,
		TEXT("����"),
		MB_OK | MB_ICONINFORMATION);

	wchar_t MB3[] = L"������� 20 ���� 1986 ����, � ������ ���������";
	MessageBox(0,
		MB3,
		TEXT("����� ���������� � ����"),
		MB_OK | MB_ICONINFORMATION);
	
	int nSize = wcslen(MB1) / sizeof(wchar_t);
	wchar_t size[4] = L"101";

	MessageBox(0,
		TEXT("����-�������"),
		(LPWSTR) nSize,
		MB_OK | MB_ICONINFORMATION);
	return 0;
}