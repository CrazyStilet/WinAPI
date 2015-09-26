#include<Windows.h>
#include<tchar.h>

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

TCHAR szClassWindow[] = TEXT("Домашнее задание");

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

	hWnd = CreateWindowEx(0, szClassWindow, TEXT("Домашнее задание 6"),
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, NULL, NULL, hInst, NULL);

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	while(GetMessage(&lpMsg, NULL, 0, 0))
	{
		TranslateMessage(&lpMsg);
		DispatchMessage(&lpMsg);
	}
	return lpMsg.wParam;
}

VOID CALLBACK TimerProc(HWND hWnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime)
{
	RECT rect;
	GetWindowRect(hWnd, &rect);
	INT x = GetSystemMetrics(0);
	INT y = GetSystemMetrics(1);
	if(rect.right < x && rect.top == 0)
	{
		MoveWindow(hWnd, rect.left + 10, rect.top, rect.right - rect.left, rect.bottom - rect.top, TRUE);
	}
	else if(rect.right >= x && rect.bottom < y)
	{
		MoveWindow(hWnd, rect.left, rect.top + 10, rect.right - rect.left, rect.bottom - rect.top, TRUE);
	}
	else if(rect.bottom >= y && rect.left != 0)
	{
		MoveWindow(hWnd, rect.left - 10, rect.top, rect.right - rect.left, rect.bottom - rect.top, TRUE);
	}
	else if(rect.left == 0 && rect.top != 0)
	{
		MoveWindow(hWnd, rect.left, rect.top - 10, rect.right - rect.left, rect.bottom - rect.top, TRUE);
	}

}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{
	switch(uMessage)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
		if(wParam == VK_RETURN)
		{
			MoveWindow(hWnd, 0, 0, 300, 300, TRUE);
			SetTimer(hWnd, 1, 50, TimerProc);
		}
		if(wParam == VK_ESCAPE)
		{
			KillTimer(hWnd, 1);
		}
	default:
		return DefWindowProc(hWnd, uMessage, wParam, lParam);
	}
	return 0;
}