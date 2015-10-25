#include"CalcDlg.h"

void Plus(bool &historyEmpty, HWND &hEdit1, TCHAR *firstNumber, TCHAR *operation, TCHAR *buf, HWND &hEdit2, TCHAR *history, int &count, TCHAR *lastOperation, TCHAR *secondNumber, TCHAR *answer,bool &divideByZero);
void Minus(bool &historyEmpty, HWND &hEdit1, TCHAR *firstNumber, TCHAR *operation, TCHAR *buf, HWND &hEdit2, TCHAR *history, int &count, TCHAR *lastOperation, TCHAR *secondNumber, TCHAR *answer, bool &divideByZero);
void Multiply(bool &historyEmpty, HWND &hEdit1, TCHAR *firstNumber, TCHAR *operation, TCHAR *buf, HWND &hEdit2, TCHAR *history, int &count, TCHAR *lastOperation, TCHAR *secondNumber, TCHAR *answer, bool &divideByZero);
void Divide(bool &historyEmpty, HWND &hEdit1, TCHAR *firstNumber, TCHAR *operation, TCHAR *buf, HWND &hEdit2, TCHAR *history, int &count, TCHAR *lastOperation, TCHAR *secondNumber, TCHAR *answer, bool &divideByZero);
void operationPlus(double &nResult, double &nFirstNumber, double &nSecondNumber, TCHAR *answer, HWND &hEdit1, TCHAR*buf, TCHAR*secondNumber, TCHAR*operation, TCHAR*history, HWND &hEdit2, TCHAR*firstNumber, int &count, TCHAR *lastOperation, bool &divideByZero);
void operationMinus(double &nResult, double &nFirstNumber, double &nSecondNumber, TCHAR*answer, HWND &hEdit1, TCHAR*buf, TCHAR *secondNumber, TCHAR *operation, TCHAR*history, HWND&hEdit2, TCHAR*firstNumber, int &count, TCHAR*lastOperation, bool &divideByZero);
void operationMultiply(double &nResult, double &nFirstNumber, double &nSecondNumber, TCHAR*answer, HWND &hEdit1, TCHAR*buf, TCHAR *secondNumber, TCHAR *operation, TCHAR*history, HWND&hEdit2, TCHAR*firstNumber, int &count, TCHAR*lastOperation, bool &divideByZero);
void operationDivide(double &nResult, double &nFirstNumber, double &nSecondNumber, TCHAR*answer, HWND &hEdit1, TCHAR*buf, TCHAR *secondNumber, TCHAR *operation, TCHAR*history, HWND&hEdit2, TCHAR*firstNumber, int &count, TCHAR*lastOperation, bool &divideByZero);
void OneDivideX(HWND &hEdit1,bool &divideByZero,HWND &hEdit2,TCHAR *lastOperation,TCHAR *operation,TCHAR *answer,TCHAR *buf,TCHAR *history, int &count,TCHAR *firstNumber);
void Backspace(HWND &hEdit1,TCHAR *buf, int &size);
void Sqrt(TCHAR *buf,TCHAR *answer, HWND &hEdit1, TCHAR *history, HWND &hEdit2, TCHAR *firstNumber,int &count,bool &historyEmpty);
void PlusMinus(TCHAR *buf, bool&bufZero, HWND &hEdit1);

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
	static bool divideByZero = false;
	TCHAR buf[25] = {0};
	GetWindowText(hEdit1, buf, 25);
	int size = SendMessage(hEdit1, EM_LINELENGTH, 0, 0);
	bool secondEmpty = !lstrcmp(secondNumber, TEXT(EMPTY)),
		historyEmpty = !lstrcmp(history, TEXT(EMPTY)),
		bufZero = !lstrcmp(buf, TEXT("0"));
	static int count = 0;
	static bool comma = false;

	if (id == IDC_NULL)
	{
		SetWindowText(hEdit1, TEXT("0"));
		SetWindowText(hEdit2, TEXT(""));
		lstrcpy(firstNumber, TEXT(EMPTY));
		lstrcpy(operation, TEXT(EMPTY));
		lstrcpy(lastOperation, TEXT(EMPTY));
		lstrcpy(secondNumber, TEXT(EMPTY));
		lstrcpy(answer, TEXT(EMPTY));
		lstrcpy(history, TEXT(EMPTY));
		divideByZero = false;
	}
	else if (id == IDC_NULL2)
	{
		SetWindowText(hEdit1, TEXT("0"));
		lstrcpy(firstNumber, answer);
		lstrcpy(operation, TEXT(EMPTY));
		lstrcpy(secondNumber, TEXT(EMPTY));
		lstrcpy(answer, TEXT(EMPTY));
		divideByZero = false;
	}

	if (divideByZero)
	{
		MessageBeep(0xFFFFFFFF);
	}
	else
	{
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
						SetWindowText(hEdit1, TEXT("0."));
						comma = true;
						count++;
					}
					else
					{
						if (count != 0)
						{
							lstrcat(buf, TEXT("."));
							SetWindowText(hEdit1, buf);
							comma = true;
							count++;
						}
						else
						{
							lstrcpy(buf, TEXT("0."));
							SetWindowText(hEdit1, buf);
							comma = true;
							count++;
						}
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
			lstrcpy(operation, TEXT("+"));
			Plus(historyEmpty, hEdit1, firstNumber, operation, buf, hEdit2, history, count, lastOperation, secondNumber, answer,divideByZero);
		}
		else if (id == IDC_MINUS)
		{
			lstrcpy(operation, TEXT("-"));
			Minus(historyEmpty, hEdit1, firstNumber, operation, buf, hEdit2, history, count, lastOperation, secondNumber, answer, divideByZero);
		}
		else if (id == IDC_MULTIPLY)
		{
			lstrcpy(operation, TEXT("*"));
			Multiply(historyEmpty, hEdit1, firstNumber, operation, buf, hEdit2, history, count, lastOperation, secondNumber, answer, divideByZero);
		}
		else if (id == IDC_DIVIDE)
		{
			lstrcpy(operation, (TEXT("/")));
			Divide(historyEmpty, hEdit1, firstNumber, operation, buf, hEdit2, history, count, lastOperation, secondNumber, answer, divideByZero);
		}
		else if (id == IDC_ONEDIVIDEX)
		{
			GetWindowText(hEdit1, firstNumber, 10);
			OneDivideX(hEdit1,divideByZero,hEdit2,lastOperation,operation,answer,buf,history,count,firstNumber);	
		}
		else if (id == IDC_SQRT)
		{
			Sqrt(buf,answer,hEdit1, history, hEdit2, firstNumber, count, historyEmpty);
		}
		else if (id == IDC_PERCENT)
		{
			
		}
		else if (id == IDC_PLUSMINUS)
		{
			PlusMinus(buf, bufZero, hEdit1);
		}
		else if (id == IDC_BACKSPACE)
		{
			if (bufZero)
			{
				MessageBeep(0xFFFFFFFF);
			}
			else
			{
				Backspace(hEdit1,buf,size);
			}
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
				double nFirstNumber, nSecondNumber, nResult;
				nFirstNumber = stof(firstNumber);
				nSecondNumber = stof(secondNumber);
				if (!lstrcmp(lastOperation, TEXT("+")))
				{
					nResult = nFirstNumber + nSecondNumber;
					_stprintf(answer, TEXT("%lf"), nResult);
					SetWindowText(hEdit1, answer);
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
					_stprintf(answer, TEXT("%lf"), nResult);
					SetWindowText(hEdit1, answer);
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
					_stprintf(answer, TEXT("%lf"), nResult);
					SetWindowText(hEdit1, answer);
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
					if (nSecondNumber == 0)
					{
						SetWindowText(hEdit1, TEXT("Деление на ноль невозможно"));
						MessageBeep(0xFFFFFFFF);
						divideByZero = true;
					}
					else
					{
						nResult = nFirstNumber / nSecondNumber;
						_stprintf(answer, TEXT("%lf"), nResult);
						SetWindowText(hEdit1, answer);
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
			}
			else if (secondEmpty)
			{
				MessageBeep(0xFFFFFFFF);
			}
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

void Plus(bool &historyEmpty, HWND &hEdit1, TCHAR *firstNumber, TCHAR *operation, TCHAR *buf, HWND &hEdit2, TCHAR *history, int &count, TCHAR *lastOperation, TCHAR *secondNumber, TCHAR *answer, bool &divideByZero)
{
	bool same = !lstrcmp(lastOperation, operation);
	if (historyEmpty)
	{
		SendMessage(hEdit1, WM_GETTEXT, 10, (LPARAM)firstNumber);
		lstrcpy(lastOperation, operation);
		lstrcpy(buf, firstNumber);
		lstrcat(buf, TEXT(" "));
		lstrcat(buf, operation);
		SetWindowText(hEdit2, buf);
		lstrcat(history, buf);
		count = 0;
	}
	else if (count)
	{
		SendMessage(hEdit1, WM_GETTEXT, 10, (LPARAM)secondNumber);
		double nFirstNumber, nSecondNumber, nResult;
		nFirstNumber = stof(firstNumber);
		nSecondNumber = stof(secondNumber);
		if (!lstrcmp(lastOperation, TEXT("+")))
		{
			operationPlus(nResult, nFirstNumber, nSecondNumber, answer, hEdit1, buf, secondNumber, operation, history, hEdit2, firstNumber, count, lastOperation, divideByZero);
		}
		else if (!lstrcmp(lastOperation, TEXT("-")))
		{
			operationMinus(nResult, nFirstNumber, nSecondNumber, answer, hEdit1, buf, secondNumber, operation, history, hEdit2, firstNumber, count, lastOperation, divideByZero);
		}
		else if (!lstrcmp(lastOperation, TEXT("*")))
		{
			operationMultiply(nResult, nFirstNumber, nSecondNumber, answer, hEdit1, buf, secondNumber, operation, history, hEdit2, firstNumber, count, lastOperation, divideByZero);
		}
		else if (!lstrcmp(lastOperation, TEXT("/")))
		{
			operationDivide(nResult, nFirstNumber, nSecondNumber, answer, hEdit1, buf, secondNumber, operation, history, hEdit2, firstNumber, count, lastOperation, divideByZero);
		}
	}
	else if (!same)
	{
		TCHAR newHistory[100] = {0};
		int sizeHistory = lstrlen(history);
		lstrcpyn(newHistory, history, sizeHistory);
		lstrcat(newHistory, operation);
		lstrcpy(lastOperation, operation);
		SetWindowText(hEdit2, newHistory);
		lstrcpy(history, newHistory);
	}
}

void Minus(bool &historyEmpty, HWND &hEdit1, TCHAR *firstNumber, TCHAR *operation, TCHAR *buf, HWND &hEdit2, TCHAR *history, int &count, TCHAR *lastOperation, TCHAR *secondNumber, TCHAR *answer, bool &divideByZero)
{
	bool same = !lstrcmp(lastOperation, operation);
	if (historyEmpty)
	{
		SendMessage(hEdit1, WM_GETTEXT, 10, (LPARAM)firstNumber);
		lstrcpy(lastOperation, operation);
		lstrcpy(buf, firstNumber);
		lstrcat(buf, TEXT(" "));
		lstrcat(buf, operation);
		SetWindowText(hEdit2, buf);
		lstrcat(history, buf);
		count = 0;
	}
	else if (count)
	{
		SendMessage(hEdit1, WM_GETTEXT, 10, (LPARAM)secondNumber);
		double nFirstNumber, nSecondNumber, nResult;
		nFirstNumber = stof(firstNumber);
		nSecondNumber = stof(secondNumber);
		if (!lstrcmp(lastOperation, TEXT("+")))
		{
			operationPlus(nResult, nFirstNumber, nSecondNumber, answer, hEdit1, buf, secondNumber, operation, history, hEdit2, firstNumber, count, lastOperation, divideByZero);
		}
		else if (!lstrcmp(lastOperation, TEXT("-")))
		{
			operationMinus(nResult, nFirstNumber, nSecondNumber, answer, hEdit1, buf, secondNumber, operation, history, hEdit2, firstNumber, count, lastOperation, divideByZero);
		}
		else if (!lstrcmp(lastOperation, TEXT("*")))
		{
			operationMultiply(nResult, nFirstNumber, nSecondNumber, answer, hEdit1, buf, secondNumber, operation, history, hEdit2, firstNumber, count, lastOperation, divideByZero);
		}
		else if (!lstrcmp(lastOperation, TEXT("/")))
		{
			operationDivide(nResult, nFirstNumber, nSecondNumber, answer, hEdit1, buf, secondNumber, operation, history, hEdit2, firstNumber, count, lastOperation, divideByZero);
		}
	}
	else if (!same)
	{
		TCHAR newHistory[100] = {0};
		int sizeHistory = lstrlen(history);
		lstrcpyn(newHistory, history, sizeHistory);
		lstrcat(newHistory, operation);
		lstrcpy(lastOperation, operation);
		SetWindowText(hEdit2, newHistory);
		lstrcpy(history, newHistory);
	}
}

void Multiply(bool &historyEmpty, HWND &hEdit1, TCHAR *firstNumber, TCHAR *operation, TCHAR *buf, HWND &hEdit2, TCHAR *history, int &count, TCHAR *lastOperation, TCHAR *secondNumber, TCHAR *answer, bool &divideByZero)
{
	bool same = !lstrcmp(lastOperation, operation);
	if (historyEmpty)
	{
		SendMessage(hEdit1, WM_GETTEXT, 10, (LPARAM)firstNumber);
		lstrcpy(lastOperation, operation);
		lstrcpy(buf, firstNumber);
		lstrcat(buf, TEXT(" "));
		lstrcat(buf, operation);
		SetWindowText(hEdit2, buf);
		lstrcat(history, buf);
		count = 0;
	}
	else if (count)
	{
		SendMessage(hEdit1, WM_GETTEXT, 10, (LPARAM)secondNumber);
		double nFirstNumber, nSecondNumber, nResult;
		nFirstNumber = stof(firstNumber);
		nSecondNumber = stof(secondNumber);
		if (!lstrcmp(lastOperation, TEXT("+")))
		{
			operationPlus(nResult, nFirstNumber, nSecondNumber, answer, hEdit1, buf, secondNumber, operation, history, hEdit2, firstNumber, count, lastOperation, divideByZero);
		}
		else if (!lstrcmp(lastOperation, TEXT("-")))
		{
			operationMinus(nResult, nFirstNumber, nSecondNumber, answer, hEdit1, buf, secondNumber, operation, history, hEdit2, firstNumber, count, lastOperation, divideByZero);
		}
		else if (!lstrcmp(lastOperation, TEXT("*")))
		{
			operationMultiply(nResult, nFirstNumber, nSecondNumber, answer, hEdit1, buf, secondNumber, operation, history, hEdit2, firstNumber, count, lastOperation, divideByZero);
		}
		else if (!lstrcmp(lastOperation, TEXT("/")))
		{
			operationDivide(nResult, nFirstNumber, nSecondNumber, answer, hEdit1, buf, secondNumber, operation, history, hEdit2, firstNumber, count, lastOperation, divideByZero);
		}
	}
	else if (!same)
	{
		TCHAR newHistory[100] = {0};
		int sizeHistory = lstrlen(history);
		lstrcpyn(newHistory, history, sizeHistory);
		lstrcat(newHistory, operation);
		lstrcpy(lastOperation, operation);
		SetWindowText(hEdit2, newHistory);
		lstrcpy(history, newHistory);
	}
}

void Divide(bool &historyEmpty, HWND &hEdit1, TCHAR *firstNumber, TCHAR *operation, TCHAR *buf, HWND &hEdit2, TCHAR *history, int &count, TCHAR *lastOperation, TCHAR *secondNumber, TCHAR *answer, bool &divideByZero)
{
	bool same = !lstrcmp(lastOperation, operation);
	if (historyEmpty)
	{
		SendMessage(hEdit1, WM_GETTEXT, 10, (LPARAM)firstNumber);
		lstrcpy(lastOperation, operation);
		lstrcpy(buf, firstNumber);
		lstrcat(buf, TEXT(" "));
		lstrcat(buf, operation);
		SetWindowText(hEdit2, buf);
		lstrcat(history, buf);
		count = 0;
	}
	else if (count)
	{
		SendMessage(hEdit1, WM_GETTEXT, 10, (LPARAM)secondNumber);
		double nFirstNumber, nSecondNumber, nResult;
		nFirstNumber = stof(firstNumber);
		nSecondNumber = stof(secondNumber);
		if (!lstrcmp(lastOperation, TEXT("+")))
		{
			operationPlus(nResult, nFirstNumber, nSecondNumber, answer, hEdit1, buf, secondNumber, operation, history, hEdit2, firstNumber, count, lastOperation, divideByZero);
		}
		else if (!lstrcmp(lastOperation, TEXT("-")))
		{
			operationMinus(nResult, nFirstNumber, nSecondNumber, answer, hEdit1, buf, secondNumber, operation, history, hEdit2, firstNumber, count, lastOperation, divideByZero);
		}
		else if (!lstrcmp(lastOperation, TEXT("*")))
		{
			operationMultiply(nResult, nFirstNumber, nSecondNumber, answer, hEdit1, buf, secondNumber, operation, history, hEdit2, firstNumber, count, lastOperation, divideByZero);
		}
		else if (!lstrcmp(lastOperation, TEXT("/")))
		{
			operationDivide(nResult, nFirstNumber, nSecondNumber, answer, hEdit1, buf, secondNumber, operation, history, hEdit2, firstNumber, count, lastOperation, divideByZero);
		}
	}
	else if (!same)
	{
		TCHAR newHistory[100] = {0};
		int sizeHistory = lstrlen(history);
		lstrcpyn(newHistory, history, sizeHistory);
		lstrcat(newHistory, operation);
		lstrcpy(lastOperation, operation);
		SetWindowText(hEdit2, newHistory);
		lstrcpy(history, newHistory);
	}
}

void operationPlus(double &nResult, double &nFirstNumber, double &nSecondNumber, TCHAR *answer, HWND &hEdit1, TCHAR*buf, TCHAR*secondNumber, TCHAR*operation, TCHAR*history, HWND &hEdit2, TCHAR*firstNumber, int &count, TCHAR *lastOperation, bool &divideByZero)
{
	lstrcpy(lastOperation, operation);
	nResult = nFirstNumber + nSecondNumber;
	_stprintf(answer, TEXT("%lf"), nResult);
	SetWindowText(hEdit1, answer);
	lstrcpy(buf, TEXT(" "));
	lstrcat(buf, secondNumber);
	lstrcat(buf, TEXT(" "));
	lstrcat(buf, operation);
	lstrcat(history, buf);
	SetWindowText(hEdit2, history);
	lstrcpy(firstNumber, answer);
	count = 0;
}

void operationMinus(double &nResult, double &nFirstNumber, double &nSecondNumber, TCHAR*answer, HWND &hEdit1, TCHAR*buf, TCHAR *secondNumber, TCHAR *operation, TCHAR*history, HWND&hEdit2, TCHAR*firstNumber, int &count, TCHAR*lastOperation, bool &divideByZero)
{
	lstrcpy(lastOperation, operation);
	nResult = nFirstNumber - nSecondNumber;
	_stprintf(answer, TEXT("%lf"), nResult);
	SetWindowText(hEdit1, answer);
	lstrcpy(buf, TEXT(" "));
	lstrcat(buf, secondNumber);
	lstrcat(buf, TEXT(" "));
	lstrcat(buf, operation);
	lstrcat(history, buf);
	SetWindowText(hEdit2, history);
	lstrcpy(firstNumber, answer);
	count = 0;
}

void operationMultiply(double &nResult, double &nFirstNumber, double &nSecondNumber, TCHAR*answer, HWND &hEdit1, TCHAR*buf, TCHAR *secondNumber, TCHAR *operation, TCHAR*history, HWND&hEdit2, TCHAR*firstNumber, int &count, TCHAR*lastOperation, bool &divideByZero)
{
	lstrcpy(lastOperation, operation);
	nResult = nFirstNumber * nSecondNumber;
	_stprintf(answer, TEXT("%lf"), nResult);
	SetWindowText(hEdit1, answer);
	lstrcpy(buf, TEXT(" "));
	lstrcat(buf, secondNumber);
	lstrcat(buf, TEXT(" "));
	lstrcat(buf, operation);
	lstrcat(history, buf);
	SetWindowText(hEdit2, history);
	lstrcpy(firstNumber, answer);
	count = 0;
}

void operationDivide(double &nResult, double &nFirstNumber, double &nSecondNumber, TCHAR*answer, HWND &hEdit1, TCHAR*buf, TCHAR *secondNumber, TCHAR *operation, TCHAR*history, HWND&hEdit2, TCHAR*firstNumber, int &count, TCHAR*lastOperation, bool &divideByZero)
{
	if (nSecondNumber == 0)
	{
		SetWindowText(hEdit1, TEXT("Деление на ноль невозможно"));
		MessageBeep(0xFFFFFFFF);
		divideByZero = true;
	}
	else
	{
		lstrcpy(lastOperation, operation);
		nResult = nFirstNumber / nSecondNumber;
		_stprintf(answer, TEXT("%lf"), nResult);
		SetWindowText(hEdit1, answer);
		lstrcpy(buf, TEXT(" "));
		lstrcat(buf, secondNumber);
		lstrcat(buf, TEXT(" "));
		lstrcat(buf, operation);
		lstrcat(history, buf);
		SetWindowText(hEdit2, history);
		lstrcpy(firstNumber, answer);
		count = 0;
	}
}

void OneDivideX(HWND &hEdit1, bool &divideByZero, HWND &hEdit2, TCHAR *lastOperation, TCHAR *operation, TCHAR *answer, TCHAR *buf, TCHAR *history, int &count, TCHAR*firstNumber)
{
	bool firstZero = !lstrcmp(firstNumber, TEXT("0"));
	if (firstZero)
	{
		SetWindowText(hEdit1, TEXT("Деление на ноль невозможно"));
		SetWindowText(hEdit2, TEXT("1 / 0"));
		MessageBeep(0xFFFFFFFF);
		divideByZero = true;
	}
	else
	{
		lstrcpy(lastOperation, operation);
		double nNumber, nResult;
		nNumber = stof(firstNumber);
		nResult = 1 / nNumber;
		_stprintf(answer, TEXT("%lf"), nResult);
		SetWindowText(hEdit1, answer);
		lstrcpy(buf, TEXT("1 / "));
		lstrcat(buf, firstNumber);
		lstrcat(buf, TEXT(" "));
		lstrcat(buf, operation);
		lstrcat(history, buf);
		SetWindowText(hEdit2, history);
		lstrcpy(firstNumber, answer);
		count = 0;
	}
}

void Backspace(HWND &hEdit1,TCHAR *buf, int &size)
{
	if (size == 1)
	{
		SetWindowText(hEdit1, TEXT("0"));
	}
	else
	{
		int sizeBuf = lstrlen(buf);
		TCHAR newBuf[25] = {0};
		lstrcpyn(newBuf,buf,sizeBuf);
		SetWindowText(hEdit1, newBuf);
	}
}

void Sqrt(TCHAR *buf, TCHAR *answer, HWND &hEdit1, TCHAR *history, HWND &hEdit2, TCHAR *firstNumber, int &count, bool &historyEmpty)
{
	double nNumber, nResult;
	nNumber = stof(buf);
	nResult = sqrt(nNumber);
	_stprintf(answer, TEXT("%lf"), nResult);
	SetWindowText(hEdit1, answer);
	if (historyEmpty)
	{
		lstrcpy(history, TEXT("√"));
	}
	else
	{
		lstrcat(history, TEXT("√"));
	}
	lstrcat(history, buf);
	SetWindowText(hEdit2, history);
	lstrcpy(firstNumber, answer);
	//count = 0;
}

void PlusMinus(TCHAR* buf, bool &bufZero, HWND &hEdit1)
{
	if (bufZero)
	{
		MessageBeep(0xFFFFFFFF);
	}
	else
	{
		TCHAR newBuf[2] = {0};
		lstrcpyn(newBuf, buf, 2);
		TCHAR newNewBuf[25] = {0};
		if (!lstrcmp(newBuf, TEXT("-")))
		{
			int sizeBuf = lstrlen(buf);
			for (int i = 0; i < sizeBuf-1; i++)
			{
				newNewBuf[i] = buf[i + 1];
			}
			SetWindowText(hEdit1, newNewBuf);
		}
		else
		{
			lstrcpy(newNewBuf, TEXT("-"));
			lstrcat(newNewBuf, buf);
			SetWindowText(hEdit1, newNewBuf);
		}
	}
}