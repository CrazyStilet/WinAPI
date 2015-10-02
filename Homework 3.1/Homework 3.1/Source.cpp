#include <Windows.h>
#include "resource.h"

BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);

HWND hStatic;
HINSTANCE hInst;

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	hInst = hInstance;
	return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);
}

BOOL CALLBACK DlgProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{
	static WORD xPosStart, yPosStart,xPosEnd,yPosEnd;
	static int count = 1;
	TCHAR CountStatic[10];
	switch(uMessage)
	{
	case WM_CLOSE:
		EndDialog(hWnd, 0);
		return TRUE;
	case WM_LBUTTONDOWN:
		xPosStart = LOWORD(lParam);
		yPosStart = HIWORD(lParam);
		return TRUE;
	case WM_LBUTTONUP:
		xPosEnd = LOWORD(lParam);
		yPosEnd = HIWORD(lParam);
		/*if((xPosEnd - xPosStart < 10 || yPosEnd - yPosStart < 10) ||
			(xPosEnd - xPosStart < 10 || yPosStart - yPosEnd > -10) ||
			(xPosStart - xPosEnd > -10 || yPosEnd - yPosStart < 10) ||
			(xPosEnd - xPosStart < 10 || yPosStart - yPosEnd > -10))
		{
			MessageBox(hWnd, TEXT("Размер Static'a должен быть минимум 10х10"), TEXT("Предупреждение"), MB_OK | MB_ICONINFORMATION);
			return TRUE;
		}*/
		wsprintf(CountStatic, TEXT("Static %i"), count);
		if(xPosEnd - xPosStart >= 10 && yPosEnd - yPosStart >= 10)
		{
			hStatic = CreateWindowEx(0, TEXT("STATIC"), CountStatic, WS_CHILD | WS_VISIBLE | WS_BORDER,
				xPosStart, yPosStart, xPosEnd - xPosStart, yPosEnd - yPosStart, hWnd, 0, hInst, 0);
		}
		else if(xPosEnd - xPosStart >= 10 && yPosStart - yPosEnd >= 10)
		{
			hStatic = CreateWindowEx(0, TEXT("STATIC"), CountStatic, WS_CHILD | WS_VISIBLE | WS_BORDER,
				xPosStart, yPosEnd, xPosEnd - xPosStart, yPosStart - yPosEnd, hWnd, 0, hInst, 0);
		}
		else if(xPosStart - xPosEnd >= 10 && yPosEnd - yPosStart >= 10)
		{
			hStatic = CreateWindowEx(0, TEXT("STATIC"), CountStatic, WS_CHILD | WS_VISIBLE | WS_BORDER,
				xPosEnd, yPosStart, xPosStart - xPosEnd, yPosEnd - yPosStart, hWnd, 0, hInst, 0);
		}
		else if(xPosStart - xPosEnd >= 10 && yPosStart - yPosEnd >= 10)
		{
			hStatic = CreateWindowEx(0, TEXT("STATIC"), CountStatic, WS_CHILD | WS_VISIBLE | WS_BORDER,
				xPosEnd, yPosEnd, xPosStart - xPosEnd, yPosStart - yPosEnd, hWnd, 0, hInst, 0);
		}
		
		count++;
		return TRUE;
	case WM_RBUTTONUP:

		return TRUE;
	}
	return FALSE;
}