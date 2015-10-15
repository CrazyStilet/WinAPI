#include <Windows.h>
#include <string>
#include "resource.h"

using namespace std;

HWND hFirstNumber, hOperation, hSecondNumber, hResult, hAnswer;
TCHAR firstNumber[50], operation[2], secondNumber[50], answer[150];

BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);

INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	return DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);
}

BOOL CALLBACK DlgProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{
	switch (uMessage)
	{
	case WM_CLOSE:
		EndDialog(hWnd, 0);
		return TRUE;
	case WM_INITDIALOG:
		hFirstNumber = GetDlgItem(hWnd, IDC_FIRSTNUMBER);
		hOperation = GetDlgItem(hWnd, IDC_OPERATION);
		hSecondNumber = GetDlgItem(hWnd, IDC_SECONDNUMBER);
		hResult = GetDlgItem(hWnd, IDC_RESULT);
		hAnswer = GetDlgItem(hWnd, IDC_ANSWER);

		return TRUE;
	case WM_COMMAND:
	{
		if (LOWORD(wParam) == IDC_FIRSTNUMBER || LOWORD(wParam) == IDC_OPERATION ||
			LOWORD(wParam) == IDC_SECONDNUMBER && HIWORD(wParam) == EN_CHANGE)
		{
			GetWindowText(hFirstNumber, firstNumber, 50);
			GetWindowText(hOperation, operation, 2);
			GetWindowText(hSecondNumber, secondNumber, 50);
			if (!lstrcmp(operation,TEXT("+")))
			{
				if (lstrlen(firstNumber) == 0 || lstrlen(secondNumber) == 0)
				{
					EnableWindow(hResult, 0);
				}
				else
				{
					EnableWindow(hResult, 1);
				}
			}
			else if (!lstrcmp(operation,TEXT("-")))
			{
				if (lstrlen(firstNumber) == 0 || lstrlen(secondNumber) == 0)
				{
					EnableWindow(hResult, 0);
				}
				else
				{
					EnableWindow(hResult, 1);
				}
			}
			else if (!lstrcmp(operation,TEXT("*")))
			{
				if (lstrlen(firstNumber) == 0 || lstrlen(secondNumber) == 0)
				{
					EnableWindow(hResult, 0);
				}
				else
				{
					EnableWindow(hResult, 1);
				}
			}
			else if (!lstrcmp(operation,TEXT("/")))
			{
				if (lstrlen(firstNumber) == 0 || lstrlen(secondNumber) == 0 || (!lstrcmp(secondNumber, TEXT("0"))))
				{
					EnableWindow(hResult, 0);
				}
				else
				{
					EnableWindow(hResult, 1);
				}
			}
		}
		if (LOWORD(wParam) == IDC_RESULT)
		{
			INT nFirstNumber,nSecondNumber, nResult;
			nFirstNumber = stoi(firstNumber);
			nSecondNumber = stoi(secondNumber);
			if (!lstrcmp(operation,TEXT("+")))
			{
				nResult = nFirstNumber + nSecondNumber;
			}
			else if (!lstrcmp(operation,TEXT("-")))
			{
				nResult = nFirstNumber - nSecondNumber;
			}
			else if (!lstrcmp(operation,TEXT("*")))
			{
				nResult = nFirstNumber * nSecondNumber;
			}
			else if (!lstrcmp(operation,TEXT("/")))
			{
				nResult = nFirstNumber / nSecondNumber;
			}
			wsprintf(answer, TEXT("%d"), nResult);
			SetWindowText(hAnswer, answer);
		}
	}
		return TRUE;
	}
	return FALSE;
}