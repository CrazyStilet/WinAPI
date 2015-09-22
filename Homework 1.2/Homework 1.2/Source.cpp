#include<Windows.h>
#include<tchar.h>

INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpczCmdLine, int nCmdShow) {
	UINT Count = 0;
	UINT Number = 50;
	UINT MinNumber = 1;
	UINT MaxNumber = 100;
	UINT YesNo;
	UINT Again;
	TCHAR Title[] = _TEXT("Угадывание чисел");
	TCHAR Message[] = _TEXT("Ваше число больше: %i");
	TCHAR buffer[50];

	MessageBox(0, TEXT("Загадайте число от 1 до 100\nНажмите кнопку \"Отмена\" когда увидите свое загаданное число, или когда захотите выйти"), Title, MB_OK | MB_ICONINFORMATION);

	do {
		do {
			wsprintf(buffer, Message, Number);
			YesNo = MessageBox(0, buffer, Title, MB_YESNOCANCEL);
			Count++;
			switch(YesNo) {
			case IDYES:
				MinNumber = Number + 1;
				Number = (MinNumber + MaxNumber) / 2;
				continue;
			case IDNO:
				MaxNumber = Number;
				Number = (MinNumber + MaxNumber) / 2;
				continue;
			}
		} while(YesNo != IDCANCEL);
		wsprintf(buffer, TEXT("Число было угадано за %i попыток\nПовторить?"), Count);
		Again = MessageBox(0, buffer, Title, MB_YESNO | MB_ICONINFORMATION);
		Number = 50;
		MinNumber = 1;
		MaxNumber = 100;
		Count = 0;
	} while(Again==IDYES);
	
	return 0;
}