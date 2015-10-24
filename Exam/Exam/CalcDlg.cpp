#include"CalcDlg.h"

CalcDlg* CalcDlg::ptr = NULL;

CalcDlg::CalcDlg(void)
{
	ptr = this;
}

void CalcDlg::Cls_OnClose(HWND hwnd)
{
	EndDialog(hwnd, 0);
}

BOOL CalcDlg::Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{
	hDialog = hwnd;
	hZero = GetDlgItem(hDialog, IDC_ZERO);
	hOne = GetDlgItem(hDialog, IDC_ONE);
	hTwo = GetDlgItem(hDialog, IDC_TWO);
	hThree = GetDlgItem(hDialog, IDC_THREE);
	hFour = GetDlgItem(hDialog, IDC_FOUR);
	hFive = GetDlgItem(hDialog, IDC_FIVE);
	hSix = GetDlgItem(hDialog, IDC_SIX);
	hSeven = GetDlgItem(hDialog, IDC_SEVEN);
	hEight = GetDlgItem(hDialog, IDC_EIGHT);
	hNine = GetDlgItem(hDialog, IDC_NINE);
	hComma = GetDlgItem(hDialog, IDC_COMMA);
	hPlus = GetDlgItem(hDialog, IDC_PLUS);
	hMinus = GetDlgItem(hDialog, IDC_MINUS);
	hMultiply = GetDlgItem(hDialog, IDC_MULTIPLY);
	hDivide = GetDlgItem(hDialog, IDC_DIVIDE);
	hBackSpace = GetDlgItem(hDialog, IDC_BACKSPACE);
	hC = GetDlgItem(hDialog, IDC_NULL);
	hCE = GetDlgItem(hDialog, IDC_NULL2);
	hPlusMinus = GetDlgItem(hDialog, IDC_PLUSMINUS);
	hSqrt = GetDlgItem(hDialog, IDC_SQRT);
	hPercent = GetDlgItem(hDialog, IDC_PERCENT);
	hOneDivideX = GetDlgItem(hDialog, IDC_ONEDIVIDEX);
	hAnswer = GetDlgItem(hDialog, IDC_ANSWER);
	hEdit1 = GetDlgItem(hDialog, IDC_EDIT1);
	hEdit2 = GetDlgItem(hDialog, IDC_EDIT2);

	SetWindowText(hEdit1, TEXT("0"));

	return TRUE;
}

void CalcDlg::Cls_OnCommand(HWND hwnd, int id, HWND hwndFocus,
	UINT codeNotify)
{
	static TCHAR firstNumber[10] = {0};
	static TCHAR operation[2] = {0};
	static TCHAR lastOperation[2] = {0};
	static TCHAR secondNumber[10] = {0};
	static TCHAR answer[25] = {0};
	static TCHAR history[100] = {0};
	TCHAR buf[25] = {0};
	GetWindowText(hEdit1, buf, 25);
	int size = SendMessage(hEdit1, EM_LINELENGTH, 0, 0);
	bool secondEmpty = !lstrcmp(secondNumber, TEXT(EMPTY)),
		historyEmpty = !lstrcmp(history, TEXT(EMPTY)),
		bufZero = !lstrcmp(buf, TEXT("0"));
		/*change = !lstrcmp(answer, buf);
	static bool changeAnswer = true;*/
	static int count = 0;
	static bool comma = false;
	/*if (codeNotify == EN_CHANGE)
	{
		MessageBox(hwnd, TEXT("More"), TEXT("More"), MB_OK | MB_ICONINFORMATION);
		
		char buffer[25];
		GetWindowText(hEdit1, (LPWSTR)buffer, 25);
		int size = strlen(buffer);
		if (size > 10)
		{
			MessageBox(hwnd, TEXT("More"), TEXT("More"), MB_OK | MB_ICONINFORMATION);
		}
	}*/
	
	if (id == IDC_ZERO)
	{
		if (size >= 10)
		{
			MessageBeep(0xFFFFFFFF);
		}
		else
		{
			if (!bufZero)
			{
				if (count != 0)
				{
					lstrcat(buf, TEXT("0"));
					SetWindowText(hEdit1, buf);
				}
				else
				{
					lstrcpy(buf, TEXT("0"));
					SetWindowText(hEdit1, buf);
					count++;
				}

				/*if (historyEmpty)
				{
					lstrcat(buf, TEXT("0"));
					SetWindowText(hEdit1, buf);
				}
				else
				{
					lstrcpy(buf, TEXT("0"));
					SetWindowText(hEdit1, TEXT("0"));
				}*/
			}
		}
	}
	else if (id == IDC_ONE)
	{
		if (size >= 10)
		{
			MessageBeep(0xFFFFFFFF);
		}
		else
		{
			if (bufZero)
			{
				SetWindowText(hEdit1, TEXT("1"));
				count++;
			}
			else
			{
				if (count != 0)
				{
					lstrcat(buf, TEXT("1"));
					SetWindowText(hEdit1, buf);
				}
				else
				{
					lstrcpy(buf, TEXT("1"));
					SetWindowText(hEdit1, buf);
					count++;
				}
			}
		}
	}
	else if (id == IDC_TWO)
	{
		if (size >= 10)
		{
			MessageBeep(0xFFFFFFFF);
		}
		else
		{
			if (bufZero)
			{
				SetWindowText(hEdit1, TEXT("2"));
				count++;
			}
			else
			{
				if (count != 0)
				{
					lstrcat(buf, TEXT("2"));
					SetWindowText(hEdit1, buf);
				}
				else
				{
					lstrcpy(buf, TEXT("2"));
					SetWindowText(hEdit1, buf);
					count++;
				}
			}
		}
	}
	else if (id == IDC_THREE)
	{
		if (size >= 10)
		{
			MessageBeep(0xFFFFFFFF);
		}
		else
		{
			if (bufZero)
			{
				SetWindowText(hEdit1, TEXT("3"));
				count++;
			}
			else
			{
				if (count != 0)
				{
					lstrcat(buf, TEXT("3"));
					SetWindowText(hEdit1, buf);
				}
				else
				{
					lstrcpy(buf, TEXT("3"));
					SetWindowText(hEdit1, buf);
					count++;
				}
			}
		}
	}
	else if (id == IDC_FOUR)
	{
		if (size >= 10)
		{
			MessageBeep(0xFFFFFFFF);
		}
		else
		{
			if (bufZero)
			{
				SetWindowText(hEdit1, TEXT("4"));
				count++;
			}
			else
			{
				if (count != 0)
				{
					lstrcat(buf, TEXT("4"));
					SetWindowText(hEdit1, buf);
				}
				else
				{
					lstrcpy(buf, TEXT("4"));
					SetWindowText(hEdit1, buf);
					count++;
				}
			}
		}
	}
	else if (id == IDC_FIVE)
	{
		if (size >= 10)
		{
			MessageBeep(0xFFFFFFFF);
		}
		else
		{
			if (bufZero)
			{
				SetWindowText(hEdit1, TEXT("5"));
				count++;
			}
			else
			{
				if (count != 0)
				{
					lstrcat(buf, TEXT("5"));
					SetWindowText(hEdit1, buf);
				}
				else
				{
					lstrcpy(buf, TEXT("5"));
					SetWindowText(hEdit1, buf);
					count++;
				}
			}
		}
	}
	else if (id == IDC_SIX)
	{
		if (size >= 10)
		{
			MessageBeep(0xFFFFFFFF);
		}
		else
		{
			if (bufZero)
			{
				SetWindowText(hEdit1, TEXT("6"));
				count++;
			}
			else
			{
				if (count != 0)
				{
					lstrcat(buf, TEXT("6"));
					SetWindowText(hEdit1, buf);
				}
				else
				{
					lstrcpy(buf, TEXT("6"));
					SetWindowText(hEdit1, buf);
					count++;
				}
			}
		}
	}
	else if (id == IDC_SEVEN)
	{
		if (size >= 10)
		{
			MessageBeep(0xFFFFFFFF);
		}
		else
		{
			if (bufZero)
			{
				SetWindowText(hEdit1, TEXT("7"));
				count++;
			}
			else
			{
				if (count != 0)
				{
					lstrcat(buf, TEXT("7"));
					SetWindowText(hEdit1, buf);
				}
				else
				{
					lstrcpy(buf, TEXT("7"));
					SetWindowText(hEdit1, buf);
					count++;
				}
			}
		}
	}
	else if (id == IDC_EIGHT)
	{
		if (size >= 10)
		{
			MessageBeep(0xFFFFFFFF);
		}
		else
		{
			if (bufZero)
			{
				SetWindowText(hEdit1, TEXT("8"));
				count++;
			}
			else
			{
				if (count != 0)
				{
					lstrcat(buf, TEXT("8"));
					SetWindowText(hEdit1, buf);
				}
				else
				{
					lstrcpy(buf, TEXT("8"));
					SetWindowText(hEdit1, buf);
					count++;
				}
			}
		}
	}
	else if (id == IDC_NINE)
	{
		if (size >= 10)
		{
			MessageBeep(0xFFFFFFFF);
		}
		else
		{
			if (bufZero)
			{
				SetWindowText(hEdit1, TEXT("9"));
				count++;
			}
			else
			{
				if (count != 0)
				{
					lstrcat(buf, TEXT("9"));
					SetWindowText(hEdit1, buf);
				}
				else
				{
					lstrcpy(buf, TEXT("9"));
					SetWindowText(hEdit1, buf);
					count++;
				}
			}
		}
	}
	else if (id == IDC_COMMA)
	{
		if (!comma)
		{
			if (size >= 10)
			{
				MessageBeep(0xFFFFFFFF);
			}
			else
			{
				if (bufZero)
				{
					SetWindowText(hEdit1, TEXT("0,"));
					comma = true;
					count++;
				}
				else
				{
					if (count != 0)
					{
						lstrcat(buf, TEXT(","));
						SetWindowText(hEdit1, buf);
						comma = true;
						count++;
					}
					/*else
					{
						lstrcpy(buf, TEXT("0,"));
						SetWindowText(hEdit1, buf);
						count++;
					}*/
				}
			}
		}
		else
		{
			MessageBeep(0xFFFFFFFF);
		}
	}
	else if (id == IDC_PLUS)
	{
		if (historyEmpty)
		{
			SendMessage(hEdit1, WM_GETTEXT, 10, (LPARAM)firstNumber);
			lstrcpy(operation, TEXT("+"));
			lstrcpy(buf, firstNumber);
			lstrcat(buf, TEXT(" "));
			lstrcat(buf, operation);
			SetWindowText(hEdit2, buf);
			lstrcat(history, buf);
			count = 0;
			lstrcpy(lastOperation, operation);
		}
		else if (count)
		{
			SendMessage(hEdit1, WM_GETTEXT, 10, (LPARAM)secondNumber);
			lstrcpy(operation, TEXT("+"));
			INT nFirstNumber, nSecondNumber, nResult;
			nFirstNumber = stoi(firstNumber);
			nSecondNumber = stoi(secondNumber);
			if (!lstrcmp(lastOperation, TEXT("+")))
			{
				nResult = nFirstNumber + nSecondNumber;
				wsprintf(answer, TEXT("%d"), nResult);
				SetWindowText(hEdit1, answer);
				lstrcpy(buf, TEXT(" "));
				lstrcat(buf, secondNumber);
				lstrcat(buf, TEXT(" "));
				lstrcat(buf, operation);
				lstrcat(history, buf);
				SetWindowText(hEdit2, history);
				lstrcpy(firstNumber, answer);
				lstrcpy(operation, TEXT("+"));
				count = 0;
				lstrcpy(lastOperation, operation);
			}
			else if (!lstrcmp(lastOperation, TEXT("-")))
			{
				nResult = nFirstNumber - nSecondNumber;
				wsprintf(answer, TEXT("%d"), nResult);
				SetWindowText(hEdit1, answer);
				lstrcpy(buf, TEXT(" "));
				lstrcat(buf, secondNumber);
				lstrcat(buf, TEXT(" "));
				lstrcat(buf, operation);
				lstrcat(history, buf);
				SetWindowText(hEdit2, history);
				lstrcpy(firstNumber, answer);
				lstrcpy(operation, TEXT("+"));
				count = 0;
				lstrcpy(lastOperation, operation);
			}
			else if (!lstrcmp(lastOperation, TEXT("*")))
			{
				nResult = nFirstNumber * nSecondNumber;
				wsprintf(answer, TEXT("%d"), nResult);
				SetWindowText(hEdit1, answer);
				lstrcpy(buf, TEXT(" "));
				lstrcat(buf, secondNumber);
				lstrcat(buf, TEXT(" "));
				lstrcat(buf, operation);
				lstrcat(history, buf);
				SetWindowText(hEdit2, history);
				lstrcpy(firstNumber, answer);
				lstrcpy(operation, TEXT("+"));
				count = 0;
				lstrcpy(lastOperation, operation);
			}
			else if (!lstrcmp(lastOperation, TEXT("/")))
			{
				nResult = nFirstNumber / nSecondNumber;
				wsprintf(answer, TEXT("%d"), nResult);
				SetWindowText(hEdit1, answer);
				lstrcpy(buf, TEXT(" "));
				lstrcat(buf, secondNumber);
				lstrcat(buf, TEXT(" "));
				lstrcat(buf, operation);
				lstrcat(history, buf);
				SetWindowText(hEdit2, history);
				lstrcpy(firstNumber, answer);
				lstrcpy(operation, TEXT("+"));
				count = 0;
				lstrcpy(lastOperation, operation);
			}
		}
	}
	else if (id == IDC_MINUS)
	{
		if (historyEmpty)
		{
			SendMessage(hEdit1, WM_GETTEXT, 10, (LPARAM)firstNumber);
			lstrcpy(operation, TEXT("-"));
			lstrcpy(buf, firstNumber);
			lstrcat(buf, TEXT(" "));
			lstrcat(buf, operation);
			SetWindowText(hEdit2, buf);
			lstrcat(history, buf);
			count = 0;
			lstrcpy(lastOperation, operation);
		}
		else if (count)
		{
			SendMessage(hEdit1, WM_GETTEXT, 10, (LPARAM)secondNumber);
			lstrcpy(operation, TEXT("-"));
			INT nFirstNumber, nSecondNumber, nResult;
			nFirstNumber = stoi(firstNumber);
			nSecondNumber = stoi(secondNumber);
			if (!lstrcmp(lastOperation, TEXT("+")))
			{
				nResult = nFirstNumber + nSecondNumber;
				wsprintf(answer, TEXT("%d"), nResult);
				SetWindowText(hEdit1, answer);
				lstrcpy(buf, TEXT(" "));
				lstrcat(buf, secondNumber);
				lstrcat(buf, TEXT(" "));
				lstrcat(buf, operation);
				lstrcat(history, buf);
				SetWindowText(hEdit2, history);
				lstrcpy(firstNumber, answer);
				lstrcpy(operation, TEXT("-"));
				count = 0;
				lstrcpy(lastOperation, operation);
			}
			else if (!lstrcmp(lastOperation, TEXT("-")))
			{
				nResult = nFirstNumber - nSecondNumber;
				wsprintf(answer, TEXT("%d"), nResult);
				SetWindowText(hEdit1, answer);
				lstrcpy(buf, TEXT(" "));
				lstrcat(buf, secondNumber);
				lstrcat(buf, TEXT(" "));
				lstrcat(buf, operation);
				lstrcat(history, buf);
				SetWindowText(hEdit2, history);
				lstrcpy(firstNumber, answer);
				lstrcpy(operation, TEXT("-"));
				count = 0;
				lstrcpy(lastOperation, operation);
			}
			else if (!lstrcmp(lastOperation, TEXT("*")))
			{
				nResult = nFirstNumber * nSecondNumber;
				wsprintf(answer, TEXT("%d"), nResult);
				SetWindowText(hEdit1, answer);
				lstrcpy(buf, TEXT(" "));
				lstrcat(buf, secondNumber);
				lstrcat(buf, TEXT(" "));
				lstrcat(buf, operation);
				lstrcat(history, buf);
				SetWindowText(hEdit2, history);
				lstrcpy(firstNumber, answer);
				lstrcpy(operation, TEXT("-"));
				count = 0;
				lstrcpy(lastOperation, operation);
			}
			else if (!lstrcmp(lastOperation, TEXT("/")))
			{
				nResult = nFirstNumber / nSecondNumber;
				wsprintf(answer, TEXT("%d"), nResult);
				SetWindowText(hEdit1, answer);
				lstrcpy(buf, TEXT(" "));
				lstrcat(buf, secondNumber);
				lstrcat(buf, TEXT(" "));
				lstrcat(buf, operation);
				lstrcat(history, buf);
				SetWindowText(hEdit2, history);
				lstrcpy(firstNumber, answer);
				lstrcpy(operation, TEXT("-"));
				count = 0;
				lstrcpy(lastOperation, operation);
			}
		}
	}
	else if (id == IDC_MULTIPLY)
	{
		if (historyEmpty)
		{
			SendMessage(hEdit1, WM_GETTEXT, 10, (LPARAM)firstNumber);
			lstrcpy(operation, TEXT("*"));
			lstrcpy(buf, firstNumber);
			lstrcat(buf, TEXT(" "));
			lstrcat(buf, operation);
			SetWindowText(hEdit2, buf);
			lstrcat(history, buf);
			count = 0;
			lstrcpy(lastOperation, operation);
		}
		else if (count)
		{
			SendMessage(hEdit1, WM_GETTEXT, 10, (LPARAM)secondNumber);
			INT nFirstNumber, nSecondNumber, nResult;
			nFirstNumber = stoi(firstNumber);
			nSecondNumber = stoi(secondNumber);
			if (!lstrcmp(lastOperation, TEXT("+")))
			{
				nResult = nFirstNumber + nSecondNumber;
				wsprintf(answer, TEXT("%d"), nResult);
				SetWindowText(hEdit1, answer);
				lstrcpy(buf, TEXT(" "));
				lstrcat(buf, secondNumber);
				lstrcat(buf, TEXT(" "));
				lstrcat(buf, operation);
				lstrcat(history, buf);
				SetWindowText(hEdit2, history);
				lstrcpy(firstNumber, answer);
				lstrcpy(operation, TEXT("*"));
				count = 0;
				lstrcpy(lastOperation, operation);
			}
			else if (!lstrcmp(lastOperation, TEXT("-")))
			{
				nResult = nFirstNumber - nSecondNumber;
				wsprintf(answer, TEXT("%d"), nResult);
				SetWindowText(hEdit1, answer);
				lstrcpy(buf, TEXT(" "));
				lstrcat(buf, secondNumber);
				lstrcat(buf, TEXT(" "));
				lstrcat(buf, operation);
				lstrcat(history, buf);
				SetWindowText(hEdit2, history);
				lstrcpy(firstNumber, answer);
				lstrcpy(operation, TEXT("*"));
				count = 0;
				lstrcpy(lastOperation, operation);
			}
			else if (!lstrcmp(lastOperation, TEXT("*")))
			{
				nResult = nFirstNumber * nSecondNumber;
				wsprintf(answer, TEXT("%d"), nResult);
				SetWindowText(hEdit1, answer);
				lstrcpy(buf, TEXT(" "));
				lstrcat(buf, secondNumber);
				lstrcat(buf, TEXT(" "));
				lstrcat(buf, operation);
				lstrcat(history, buf);
				SetWindowText(hEdit2, history);
				lstrcpy(firstNumber, answer);
				lstrcpy(operation, TEXT("*"));
				count = 0;
				lstrcpy(lastOperation, operation);
			}
			else if (!lstrcmp(lastOperation, TEXT("/")))
			{
				nResult = nFirstNumber / nSecondNumber;
				wsprintf(answer, TEXT("%d"), nResult);
				SetWindowText(hEdit1, answer);
				lstrcpy(buf, TEXT(" "));
				lstrcat(buf, secondNumber);
				lstrcat(buf, TEXT(" "));
				lstrcat(buf, operation);
				lstrcat(history, buf);
				SetWindowText(hEdit2, history);
				lstrcpy(firstNumber, answer);
				lstrcpy(operation, TEXT("*"));
				count = 0;
				lstrcpy(lastOperation, operation);
			}
		}
	}
	else if (id == IDC_DIVIDE)
	{
		if (historyEmpty)
		{
			SendMessage(hEdit1, WM_GETTEXT, 10, (LPARAM)firstNumber);
			lstrcpy(operation, TEXT("/"));
			lstrcpy(buf, firstNumber);
			lstrcat(buf, TEXT(" "));
			lstrcat(buf, operation);
			SetWindowText(hEdit2, buf);
			lstrcat(history, buf);
			count = 0;
			lstrcpy(lastOperation, operation);
		}
		else if (count)
		{
			SendMessage(hEdit1, WM_GETTEXT, 10, (LPARAM)secondNumber);
			INT nFirstNumber, nSecondNumber, nResult;
			nFirstNumber = stoi(firstNumber);
			nSecondNumber = stoi(secondNumber);
			if (!lstrcmp(lastOperation, TEXT("+")))
			{
				nResult = nFirstNumber + nSecondNumber;
				wsprintf(answer, TEXT("%d"), nResult);
				SetWindowText(hEdit1, answer);
				lstrcpy(buf, TEXT(" "));
				lstrcat(buf, secondNumber);
				lstrcat(buf, TEXT(" "));
				lstrcat(buf, operation);
				lstrcat(history, buf);
				SetWindowText(hEdit2, history);
				lstrcpy(firstNumber, answer);
				lstrcpy(operation, TEXT("/"));
				count = 0;
				lstrcpy(lastOperation, operation);
			}
			else if (!lstrcmp(lastOperation, TEXT("-")))
			{
				nResult = nFirstNumber - nSecondNumber;
				wsprintf(answer, TEXT("%d"), nResult);
				SetWindowText(hEdit1, answer);
				lstrcpy(buf, TEXT(" "));
				lstrcat(buf, secondNumber);
				lstrcat(buf, TEXT(" "));
				lstrcat(buf, operation);
				lstrcat(history, buf);
				SetWindowText(hEdit2, history);
				lstrcpy(firstNumber, answer);
				lstrcpy(operation, TEXT("/"));
				count = 0;
				lstrcpy(lastOperation, operation);
			}
			else if (!lstrcmp(lastOperation, TEXT("*")))
			{
				nResult = nFirstNumber * nSecondNumber;
				wsprintf(answer, TEXT("%d"), nResult);
				SetWindowText(hEdit1, answer);
				lstrcpy(buf, TEXT(" "));
				lstrcat(buf, secondNumber);
				lstrcat(buf, TEXT(" "));
				lstrcat(buf, operation);
				lstrcat(history, buf);
				SetWindowText(hEdit2, history);
				lstrcpy(firstNumber, answer);
				lstrcpy(operation, TEXT("/"));
				count = 0;
				lstrcpy(lastOperation, operation);
			}
			else if (!lstrcmp(lastOperation, TEXT("/")))
			{
				nResult = nFirstNumber / nSecondNumber;
				wsprintf(answer, TEXT("%d"), nResult);
				SetWindowText(hEdit1, answer);
				lstrcpy(buf, TEXT(" "));
				lstrcat(buf, secondNumber);
				lstrcat(buf, TEXT(" "));
				lstrcat(buf, operation);
				lstrcat(history, buf);
				SetWindowText(hEdit2, history);
				lstrcpy(firstNumber, answer);
				lstrcpy(operation, TEXT("/"));
				count = 0;
				lstrcpy(lastOperation, operation);
			}
		}
	}
	else if (id == IDC_ONEDIVIDEX)
	{
		SetWindowText(hEdit1, TEXT("1/x"));
	}
	else if (id == IDC_SQRT)
	{
		SetWindowText(hEdit1, TEXT("Sqrt"));
	}
	else if (id == IDC_PERCENT)
	{
		SetWindowText(hEdit1, TEXT("Percent"));
	}
	else if (id == IDC_PLUSMINUS)
	{
		SetWindowText(hEdit1, TEXT("+-"));
	}
	else if (id == IDC_BACKSPACE)
	{
		SetWindowText(hEdit1, TEXT("Backspace"));
	}
	else if (id == IDC_NULL)
	{
		SetWindowText(hEdit1, TEXT("0"));
		SetWindowText(hEdit2, TEXT(""));
		lstrcpy(firstNumber, TEXT(EMPTY));
		lstrcpy(operation, TEXT(EMPTY));
		lstrcpy(lastOperation, TEXT(EMPTY));
		lstrcpy(secondNumber, TEXT(EMPTY));
		lstrcpy(answer, TEXT(EMPTY));
		lstrcpy(history, TEXT(EMPTY));
	}
	else if (id == IDC_NULL2)
	{
		SetWindowText(hEdit1, TEXT("0"));
		SetWindowText(hEdit2, TEXT(""));
		lstrcpy(firstNumber, TEXT(EMPTY));
		lstrcpy(operation, TEXT(EMPTY));
		lstrcpy(lastOperation, TEXT(EMPTY));
		lstrcpy(secondNumber, TEXT(EMPTY));
		lstrcpy(answer, TEXT(EMPTY));
		lstrcpy(history, TEXT(EMPTY));
	}
	else if (id == IDC_ANSWER)
	{
		if (historyEmpty)
		{
			MessageBeep(0xFFFFFFFF);
		}
		else if (count)
		{
			SendMessage(hEdit1, WM_GETTEXT, 10, (LPARAM)secondNumber);
			INT nFirstNumber, nSecondNumber, nResult;
			nFirstNumber = stoi(firstNumber);
			nSecondNumber = stoi(secondNumber);
			if (!lstrcmp(lastOperation, TEXT("+")))
			{
				nResult = nFirstNumber + nSecondNumber;
				wsprintf(answer, TEXT("%d"), nResult);
				SetWindowText(hEdit1, answer);
				/*lstrcpy(buf, TEXT(" "));
				lstrcat(buf, secondNumber);
				lstrcat(buf, TEXT(" "));
				lstrcat(buf, operation);
				lstrcat(history, buf);
				SetWindowText(hEdit2, history);
				lstrcpy(firstNumber, answer);
				lstrcpy(operation, TEXT("/"));
				count = 0;
				lstrcpy(lastOperation, operation);*/
				SetWindowText(hEdit2, TEXT(""));
				lstrcpy(firstNumber, TEXT(EMPTY));
				lstrcpy(operation, TEXT(EMPTY));
				lstrcpy(secondNumber, TEXT(EMPTY));
				lstrcpy(history, TEXT(EMPTY));
				lstrcpy(answer, TEXT(EMPTY));
				lstrcpy(lastOperation, TEXT(EMPTY));
				count = 0;
			}
			else if (!lstrcmp(lastOperation, TEXT("-")))
			{
				nResult = nFirstNumber - nSecondNumber;
				wsprintf(answer, TEXT("%d"), nResult);
				SetWindowText(hEdit1, answer);
				/*lstrcpy(buf, TEXT(" "));
				lstrcat(buf, secondNumber);
				lstrcat(buf, TEXT(" "));
				lstrcat(buf, operation);
				lstrcat(history, buf);
				SetWindowText(hEdit2, history);
				lstrcpy(firstNumber, answer);
				lstrcpy(operation, TEXT("/"));
				count = 0;
				lstrcpy(lastOperation, operation);*/
				SetWindowText(hEdit2, TEXT(""));
				lstrcpy(firstNumber, TEXT(EMPTY));
				lstrcpy(operation, TEXT(EMPTY));
				lstrcpy(secondNumber, TEXT(EMPTY));
				lstrcpy(history, TEXT(EMPTY));
				lstrcpy(answer, TEXT(EMPTY));
				lstrcpy(lastOperation, TEXT(EMPTY));
				count = 0;
			}
			else if (!lstrcmp(lastOperation, TEXT("*")))
			{
				nResult = nFirstNumber * nSecondNumber;
				wsprintf(answer, TEXT("%d"), nResult);
				SetWindowText(hEdit1, answer);
				/*lstrcpy(buf, TEXT(" "));
				lstrcat(buf, secondNumber);
				lstrcat(buf, TEXT(" "));
				lstrcat(buf, operation);
				lstrcat(history, buf);
				SetWindowText(hEdit2, history);
				lstrcpy(firstNumber, answer);
				lstrcpy(operation, TEXT("/"));
				count = 0;
				lstrcpy(lastOperation, operation);*/
				SetWindowText(hEdit2, TEXT(""));
				lstrcpy(firstNumber, TEXT(EMPTY));
				lstrcpy(operation, TEXT(EMPTY));
				lstrcpy(secondNumber, TEXT(EMPTY));
				lstrcpy(history, TEXT(EMPTY));
				lstrcpy(answer, TEXT(EMPTY));
				lstrcpy(lastOperation, TEXT(EMPTY));
				count = 0;
			}
			else if (!lstrcmp(lastOperation, TEXT("/")))
			{
				nResult = nFirstNumber / nSecondNumber;
				wsprintf(answer, TEXT("%d"), nResult);
				SetWindowText(hEdit1, answer);
				/*lstrcpy(buf, TEXT(" "));
				lstrcat(buf, secondNumber);
				lstrcat(buf, TEXT(" "));
				lstrcat(buf, operation);
				lstrcat(history, buf);
				SetWindowText(hEdit2, history);
				lstrcpy(firstNumber, answer);
				lstrcpy(operation, TEXT("/"));
				count = 0;
				lstrcpy(lastOperation, operation);*/
				SetWindowText(hEdit2, TEXT(""));
				lstrcpy(firstNumber, TEXT(EMPTY));
				lstrcpy(operation, TEXT(EMPTY));
				lstrcpy(secondNumber, TEXT(EMPTY));
				lstrcpy(history, TEXT(EMPTY));
				lstrcpy(answer, TEXT(EMPTY));
				lstrcpy(lastOperation, TEXT(EMPTY));
				count = 0;
			}
		}
		else if (secondEmpty)
		{
			MessageBeep(0xFFFFFFFF);
		}
	}
}

BOOL CALLBACK CalcDlg::DlgProc(HWND hwnd, UINT message,
	WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		HANDLE_MSG(hwnd, WM_CLOSE, ptr->Cls_OnClose);
		HANDLE_MSG(hwnd, WM_COMMAND, ptr->Cls_OnCommand);
		HANDLE_MSG(hwnd, WM_INITDIALOG, ptr->Cls_OnInitDialog);
	}
	return FALSE;
}