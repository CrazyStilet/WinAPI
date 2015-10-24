#pragma once
#include "Header.h"

class CalcDlg
{
public:
	CalcDlg(void);
public:
	static BOOL CALLBACK DlgProc(HWND hWnd, UINT mes, WPARAM wp, LPARAM lp);
	static CalcDlg*ptr;
	BOOL Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam);
	void Cls_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify);
	void Cls_OnClose(HWND hwnd);
	HWND hDialog;
	HWND hZero, hOne, hTwo, hThree, hFour, hFive, hSix, hSeven, hEight, hNine, hComma, hPlus, hMinus, hMultiply,hDivide, hAnswer, hBackSpace, hCE, hC,hPlusMinus,hSqrt,hPercent, hOneDivideX, hEdit1,hEdit2;
};