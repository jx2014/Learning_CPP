#include <windows.h>
#include <WinDef.h>
#include <BaseWindow.h>

BaseWindow::BaseWindow() : m_hwnd(nullptr) {};

BOOL BaseWindow::Create(PCWSTR lpWindowName, DWORD dwStyle, DWORD dwExStyle = 0, int x = CW_USEDEFAULT, int y = CW_USEDEFAULT, int nWidth = CW_USEDEFAULT,
                        int nHeight = CW_USEDEFAULT, HWND hWndParent = 0, HMENU hMenu = 0) {
    WNDCLASSW wc = {0};

    wc.lpfnWndProc = DERIVED_TYPE::WindowProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = ClassName();

    RegisterClassW(&wc);
    
    m_hwnd = CreateWindowExW(
        dwExStyle,                      // Optional window styles
        ClassName(),                    // Window class
        lpWindowName,                   // Window text
        dwStyle, 
        x, y, nWidth, nHeight,
        hWndParent,
        hMenu,
        GetModuleHandle(NULL),
        this
    );
    return (m_hwnd ? TRUE : FALSE);
};


LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    static HWND hButton1, hButton2, colorSlider;
    static int currentColorIndex = COLOR_WINDOW;
    switch (uMsg) {

        case WM_SIZE: {
        UINT width = LOWORD(lParam);  // Macro to get the low-order word.
        UINT height = HIWORD(lParam); // Macro to get the high-order word.
        wchar_t msgBuffer[64];
        swprintf_s(msgBuffer, 64, L"New size: %u x %u", width, height);
        SetWindowTextW(hwnd, msgBuffer);
        break;
        }

        case WM_HSCROLL: {
            if ((HWND)lParam == colorSlider) {
                currentColorIndex = (int)SendMessage(colorSlider, TBM_GETPOS, 0, 0);
                InvalidateRect(hwnd, NULL, TRUE);
            }
            break;
        }
            

        case WM_CREATE: {
            hButton1 =  CreateWindowW(
                L"BUTTON",
                L"click 1",
                WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                50, 50, 100, 30,
                hwnd,
                (HMENU)1,
                (HINSTANCE)GetWindowLongPtrW(hwnd, GWLP_HINSTANCE),
                NULL
            );

            hButton2 = CreateWindowW(
                L"BUTTON",
                L"click 2",
                WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                160, 50, 100, 30,
                hwnd,
                (HMENU)2,
                (HINSTANCE)GetWindowLongPtrW(hwnd, GWLP_HINSTANCE),
                NULL
            );

            colorSlider = CreateWindowW(
                TRACKBAR_CLASS, L"",
                WS_CHILD | WS_VISIBLE | TBS_HORZ,
                50, 90, 200, 30,
                hwnd,
                (HMENU)3,
                (HINSTANCE)GetWindowLongPtrW(hwnd, GWLP_HINSTANCE),
                NULL
            );
            SendMessage(colorSlider, TBM_SETRANGE, TRUE, MAKELONG(1, 24));
            SendMessage(colorSlider, TBM_SETPOS, TRUE, currentColorIndex);
            break;
        }
        
        case WM_COMMAND: {
            switch (LOWORD(wParam)) { // Check if the button was clicked
            case 1:
                MessageBox(hwnd, L"You clicked button 1!", L"Button 1 Clicked", MB_OK);
                break;
            case 2:
                MessageBox(hwnd, L"You clicked button 2!", L"Button 2 Clicked", MB_OK);
                break;
            }
            break;
        }

        case WM_DESTROY: {
            PostQuitMessage(0);
            break;
        }

        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            FillRect(hdc, &ps.rcPaint, (HBRUSH)(currentColorIndex + 1));
            EndPaint(hwnd, &ps);
            break;
        }

        case WM_CLOSE: {
            if (MessageBox(hwnd, L"Quit?", L"My application", MB_OKCANCEL) == IDOK) {
                DestroyWindow(hwnd);
            }
            return 0;
        }
    }    
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
};