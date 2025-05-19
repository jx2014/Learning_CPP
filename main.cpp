#define UNICODE
#define _UNICODE
#include <windows.h>
#include <wchar.h>

// https://learn.microsoft.com/en-us/windows/win32/learnwin32/painting-the-window

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow) {
    // Register the window class
    const wchar_t CLASS_NAME[] = L"Sample Window Class";

    WNDCLASSW wc = {0};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClassW(&wc);

    // Create the window
    HWND hwnd = CreateWindowExW(
        0,                              // Optional window styles
        CLASS_NAME,                     // Window class
        L"Learn to Program Windows",    // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,       // Parent window
        NULL,       // Menu
        hInstance,  // Instance handle
        NULL        // Additional application data
    );

    if (hwnd == NULL) {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    // Run the message loop
    MSG msg = {};
    while (GetMessageW(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    static HWND hButton1, hButton2;
    switch (uMsg) {

    case WM_SIZE: {
        UINT width = LOWORD(lParam);  // Macro to get the low-order word.
        UINT height = HIWORD(lParam); // Macro to get the high-order word.
        wchar_t msgBuffer[64];
        swprintf_s(msgBuffer, 64, L"New size: %u x %u", width, height);
        SetWindowTextW(hwnd, msgBuffer);
        break;
    }
        

    case WM_CREATE: {
        hButton1 = CreateWindowW(
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
        return 0;
    }

    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
        EndPaint(hwnd, &ps);
    }
        return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
