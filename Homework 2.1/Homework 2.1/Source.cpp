#include<Windows.h>
#include<tchar.h>

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

TCHAR szClassWindow[] = TEXT("Домашнее задание");
UINT nLB, nMB, nRB = 0;
TCHAR buffer[100];
TCHAR Text[] = TEXT("Нажатий левой кнопкой - 0, средней - 0, правой - 0");

INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpczCmdLint, int nCmdShow) {
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

	if(!RegisterClassEx(&wcl)) {
		return 0;
	}

	hWnd = CreateWindowEx(
		0,
		szClassWindow,
		Text,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInst,
		NULL);

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	while(GetMessage(&lpMsg,NULL,0,0)) {
		TranslateMessage(&lpMsg);
		DispatchMessage(&lpMsg);
	}
	return lpMsg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam) {
	switch(uMessage) {
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_LBUTTONUP:
		wsprintf(buffer, TEXT("Нажатий левой кнопкой - %d, cредней - %d, правой - %d"), ++nLB , nMB, nRB);
		SetWindowText(hWnd, buffer);
		break;
	case WM_MBUTTONUP:
		wsprintf(buffer, TEXT("Нажатий левой кнопкой - %d, cредней - %d, правой - %d"), nLB, ++nMB, nRB);
		SetWindowText(hWnd, buffer);
		break;
	case WM_RBUTTONUP:
		wsprintf(buffer, TEXT("Нажатий левой кнопкой - %d, cредней - %d, правой - %d"), nLB, nMB, ++nRB);
		SetWindowText(hWnd, buffer);
		break;
	default:
		return DefWindowProc(hWnd, uMessage, wParam, lParam);
	}
	return 0;
}