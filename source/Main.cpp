
 /* int iRetKey = MessageBox(0, "Fajne okno?", "App1", MB_YESNO);
  if (iRetKey == IDYES) MessageBox(0, "Fajnie", ":)", MB_OK);
  else MessageBox(0, "Lol", ":(", MB_OK|MB_ICONQUESTION);*/

#include <windows.h>
#include "res.h"

HINSTANCE hInst;

INT_PTR CALLBACK DialogProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
  switch (uMsg) {
  case WM_CREATE:
    break;
  case WM_PAINT:
    HDC hDC;
    hDC = GetDC(hwnd);

    

    HBITMAP hBitmap;
    //hBitmap = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP1));
    hBitmap =(HBITMAP)LoadImage(hInst, "C:\\Users\\lab\\Desktop\\Emilia Nowacka\\BMP.bmp", IMAGE_BITMAP, 0, 0 ,LR_LOADFROMFILE);

    HDC hDCBitmap;
    hDCBitmap = CreateCompatibleDC(hDC);
    SelectObject(hDCBitmap, hBitmap);
    
    BitBlt(hDC, 0, 0, 900, 400, hDCBitmap, 0, 0, SRCCOPY);
   
    DeleteDC(hDCBitmap);
    DeleteObject(hBitmap);
   
    
    
    SelectObject(hDC, GetStockObject(ANSI_VAR_FONT));

    SetTextColor(hDC, RGB(255, 0, 0));

    TextOut(hDC, 0, 0, TEXT("Text output to client area."), 27);
    ReleaseDC(hwnd, hDC);
    break;

  case WM_COMMAND:
    switch (HIWORD(wParam)) {
    case BN_CLICKED:
      switch (LOWORD(wParam)) {
        case IDC_BUTTON1:
          MessageBox(hwnd, TEXT("Teksteeeeel"), TEXT("kli ck"), MB_OK);
          HWND hwndEditBox = GetDlgItem(hwnd, IDC_EDIT1);
          int iTextLength = GetWindowTextLength(hwndEditBox);
          CHAR szText[500];
          GetWindowText(hwndEditBox, szText, iTextLength + 1);
          SetWindowText((HWND)lParam, szText);
          return TRUE;
      }
    }
    return FALSE;
  case WM_LBUTTONDOWN:
    CHAR szText[200];
    wsprintf(szText, "Kliknales myszka x=%d  y=%d", LOWORD(lParam), HIWORD(lParam));
    MessageBox(hwnd, szText, TEXT("Klik klik"), MB_OK);
  case WM_CLOSE:
    DestroyWindow(hwnd);
    PostQuitMessage(0);
    return TRUE;
  }
  return FALSE;
  }

  int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
  {
    hInst = hInstance;
    HWND hwndMainWindow = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_MAINVIEW), NULL, DialogProc);
    MSG msg = {};
      ShowWindow(hwndMainWindow, iCmdShow);
      while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
      }



    return 0;
  }

