#include<windows.h>
#include<tchar.h>

INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpczCmdLine, int nCmdShow) {
	TCHAR czName[] = _TEXT("Орлов Олег Александрович");
	MessageBox(0,
		czName,
		TEXT("ФИО"),
		MB_OK | MB_ICONINFORMATION);
	
	TCHAR czFindWork[] = _TEXT("Ищу работу в сфере информационных технологий");
	MessageBox(0,
		czFindWork,
		TEXT("Цель"),
		MB_OK | MB_ICONINFORMATION);

	TCHAR czBorn[] = _TEXT("Родился 20 июня 1986 года, в городе Николаеве");
	MessageBox(0,
		czBorn,
		TEXT("Общая информация о себе"),
		MB_OK | MB_ICONINFORMATION);
	
	TCHAR czStudy[] = _TEXT("Учусь в Компьютерной Академии ШАГ на программиста");
	MessageBox(0,
		czStudy,
		TEXT("Учеба"),
		MB_OK | MB_ICONINFORMATION);

	UINT nSize = (lstrlen(czName) + lstrlen(czFindWork) + lstrlen(czBorn)+lstrlen(czStudy)) / 4;
	TCHAR buffer[4];
	wsprintf(buffer, L"%i", nSize);

	MessageBox(0,
		TEXT("В заголовке окна указано среднее число символов в сообщениях\nGoodbye!"),
		buffer,
		MB_OK | MB_ICONINFORMATION);
	return 0;
}