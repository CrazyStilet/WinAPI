#include<Windows.h>
#include<tchar.h>

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

TCHAR szClassWindow[] = TEXT("Каркасное приложение");

INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	HWND hWnd;
	MSG lpMsg;
	WNDCLASSEX wcl;
	wcl.cbSize = sizeof(wcl);
	wcl.style = CS_HREDRAW | CS_VREDRAW;
	wcl.lpfnWndProc = WindowProc;
	wcl.cbClsExtra = 0;
	wcl.cbWndExtra = 0;
	wcl.hInstance = hInst;
	wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcl.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcl.lpszMenuName = NULL;
	wcl.lpszClassName = szClassWindow;
	wcl.hIconSm = NULL;

	if(!RegisterClassEx(&wcl))
	{
		return 0;
	}
		
	hWnd = CreateWindowEx(0, szClassWindow, TEXT("Домашнее задание 2"),
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, NULL, NULL, hInst, NULL);

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	while(GetMessage(&lpMsg,NULL,0,0))
	{
		TranslateMessage(&lpMsg);
		DispatchMessage(&lpMsg);
	}
	return lpMsg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{
	TCHAR str[100];
	switch(uMessage)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_LBUTTONDOWN:
	{
						   RECT rect;
						   GetClientRect(hWnd, &rect);
						   int x = LOWORD(lParam);
						   int y = HIWORD(lParam);
						   if(x > rect.left + 10 && x < rect.right - 10 && y > rect.top + 10 && y < rect.bottom - 10)
						   {
							   wsprintf(str, TEXT("Внутри прямоугольника"));
						   }
						   else if(x == rect.left + 10 || x == rect.right - 10 || y == rect.top + 10 || y == rect.bottom - 10)
						   {
							   wsprintf(str, TEXT("На границе прямоугольника"));
						   }
						   else
						   {
							   wsprintf(str, TEXT("Снаружи прямоугольника"));
						   }
	}
		SetWindowText(hWnd, str);
		break;
	case WM_RBUTTONDOWN:
	{
						   RECT rect;
						   GetClientRect(hWnd, &rect);
						   int x = rect.right;
						   int y = rect.bottom;
						   wsprintf(str, TEXT("Ширина: %d, Высота: %d"), x, y);
	}
		SetWindowText(hWnd, str);
		break;
	default:
		return DefWindowProc(hWnd, uMessage, wParam, lParam);
	}
	return 0;
}