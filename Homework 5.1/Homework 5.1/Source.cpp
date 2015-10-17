#include <Windows.h>
#include <windowsx.h>
#include <time.h>
#include <cstdlib>
#include "resource.h"
#include <tchar.h>

BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);

HWND hList, hStart, hSum, hMult, hAverage, hResult;

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
		srand(time(0));
		
		hList = GetDlgItem(hWnd, IDC_LIST1);
		hStart = GetDlgItem(hWnd, IDC_START);
		hSum = GetDlgItem(hWnd, IDC_SUM);
		hMult = GetDlgItem(hWnd, IDC_MULT);
		hAverage = GetDlgItem(hWnd, IDC_AVERAGE);
		hResult = GetDlgItem(hWnd, IDC_RESULT);

		SendDlgItemMessage(hWnd, IDC_SUM, BM_SETCHECK, WPARAM(BST_CHECKED), 0);

		return TRUE;
	case WM_COMMAND:
		if (LOWORD(wParam) == IDC_START)
		{
			SendMessage(hList, LB_RESETCONTENT, 0, 0);
			int nSize;
			TCHAR buffer[50];
			do
			{
				nSize = rand() % 20;
			} while (nSize <= 10);

			for (int i = 0; i < nSize; i++)
			{
				int nNum;
				nNum = rand() % 20;
				if (nNum > 10)
				{
					nNum -= 20;
				}
				else if (nNum == 0)
				{
					i--;
					continue;
				}
				wsprintf(buffer, TEXT("%d"), nNum);
				SendMessage(hList, LB_ADDSTRING, 0, LPARAM(buffer));
				SendMessage(hList, LB_SETITEMDATA, i, nNum);
			}
			int nOper = SendDlgItemMessage(hWnd, IDC_SUM, BM_GETCHECK, 0, 0);
			int nResult = 0;
			if (nOper == BST_CHECKED)
			{
				for (int i = 0; i < nSize; i++)
				{
					nResult += SendMessage(hList, LB_GETITEMDATA, i, 0);
				}
				wsprintf(buffer, TEXT("%d"), nResult);
				SetWindowText(hResult, buffer);
			}
			else
			{
				nOper = SendDlgItemMessage(hWnd, IDC_MULT, BM_GETCHECK, 0, 0);
				if (nOper == BST_CHECKED)
				{
					double dResult = 1;
					for (int i = 0; i < nSize; i++)
					{
						dResult *= SendMessage(hList, LB_GETITEMDATA, i, 0);
					}
					//wsprintf(buffer, TEXT("%d"), dResult);
					_stprintf(buffer, _T("%lf"), dResult);
					SetWindowText(hResult, buffer);
				}
				else
				{
					nOper = SendDlgItemMessage(hWnd, IDC_AVERAGE, BM_GETCHECK, 0, 0);
					if (nOper == BST_CHECKED)
					{
						double dResult = 0;
						for (int i = 0; i < nSize; i++)
						{
							dResult += SendMessage(hList, LB_GETITEMDATA, i, 0);
						}
						dResult = dResult / nSize;
						_stprintf(buffer, _T("%lf"), dResult);
						SetWindowText(hResult, buffer);
					}
				}
			}

		}
		return TRUE;
	}
	return FALSE;
}