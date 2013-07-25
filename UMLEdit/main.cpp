#include "stdafx.h"

static TCHAR szWindowClass[] = _T("UMLEditMainWnd");
static TCHAR szTitle[] = _T("UMLEdit");

HINSTANCE hInst;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{
    WNDCLASSEX wcex = {0};

    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
    wcex.hCursor        = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = NULL;
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

    if (!RegisterClassEx(&wcex))
    {
        MessageBox(NULL, _T("Call to RegisterClassEx failed!"), _T("Win32 Guided Tour"), NULL);
        return 1;
    }

    hInst = hInstance; 
    HWND hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
        500, 500, NULL, NULL, hInstance, NULL);

    if (!hWnd)
    {
        MessageBox(NULL, _T("Call to CreateWindow failed!"), _T("Win32 Guided Tour"), NULL);
        return 1;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    // Main message loop:
    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int) msg.wParam;

}
//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Show message crackersfrom windowsx.h
//

void OnPaint(HWND);
void OnMouseMove(HWND, int, int, UINT);
void OnLButtonDown(HWND, BOOL, int, int, UINT);
void OnRButtonUp(HWND, int, int, UINT);
void OnDestroy(HWND);

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
        HANDLE_MSG(hWnd, WM_PAINT, OnPaint);
        HANDLE_MSG(hWnd, WM_MOUSEMOVE, OnMouseMove);
        HANDLE_MSG(hWnd, WM_LBUTTONDOWN, OnLButtonDown);
        HANDLE_MSG(hWnd, WM_RBUTTONUP, OnRButtonUp);
        HANDLE_MSG(hWnd, WM_DESTROY, OnDestroy);
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
        break;
    }

    return 0;
}

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




