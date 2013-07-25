#include "stdafx.h"
#include "MessageCrackers.h"

void OnPaint(HWND hWnd)
{
    PAINTSTRUCT ps = {0};
    HDC hDC;
    TCHAR greeting[] = _T("Hello, World!");
    hDC=BeginPaint(hWnd, &ps);
    TextOut(hDC, 5, 5, greeting, _tcslen(greeting));
    EndPaint(hWnd, &ps);
}
void OnMouseMove(HWND hWnd, int x, int y, UINT keyFlags)
{
    HDC hdc = GetDC(hWnd); 
    SetPixel(hdc, x, y, RGB(255,0,0)); 
    ReleaseDC(hWnd, hdc);
}

void OnLButtonDown(HWND hWnd, BOOL fDoubleClick, int x, int y, UINT keyFlags)
{
    std::wstringstream oss;
    oss << "Left mouse click detected: x = " << x << ", y = " << y << std::endl;
    MessageBox(hWnd, oss.str().c_str(), _T("Attention"), MB_OK);
}

void OnRButtonUp(HWND hWnd, int x, int y, UINT keyFlags)
{
    std::wstringstream oss;
    oss << "Right mouse button released: x = " << x << ", y = " << y << std::endl;
    MessageBox(hWnd, oss.str().c_str(), _T("Attention"), MB_OK);
}
void OnDestroy(HWND hWnd)
{
    PostQuitMessage(0);
}