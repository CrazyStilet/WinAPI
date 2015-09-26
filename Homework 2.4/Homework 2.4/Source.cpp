﻿#include<Windows.h>
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

	hWnd = CreateWindowEx(0, szClassWindow, TEXT("Домашнее задание 4"),
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

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{
	switch(uMessage)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
	{
					   RECT rectW,rectC;
					   GetWindowRect(hWnd, &rectW);
					   GetClientRect(hWnd, &rectC);
					   if(wParam == VK_RETURN)
					   {
						   MoveWindow(hWnd, 0, 0, 300, 300, TRUE);
					   }
					   else if(wParam == VK_UP)
					   {
						   MoveWindow(hWnd, rectW.left, rectW.top - 10, rectC.right+16, rectW.bottom, TRUE);
					   }
					   else if(wParam == VK_DOWN)
					   {
						   MoveWindow(hWnd, rectW.left, rectW.top + 10, rectC.right+16, rectW.bottom, TRUE);
					   }
					   else if(wParam==VK_RIGHT)
					   {
						   MoveWindow(hWnd, rectW.left + 10, rectW.top, rectC.right+19, rectC.bottom+19, TRUE);
					   }
					   else if(wParam==VK_LEFT)
					   {
						   MoveWindow(hWnd, rectW.left - 10, rectW.top, rectC.right+19, rectC.bottom+19, TRUE);
					   }
	}
		break;
	default:
		return DefWindowProc(hWnd, uMessage, wParam, lParam);
	}
	return 0;
}