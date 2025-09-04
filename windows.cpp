#ifndef UNICODE
#define UNICODE
#endif 

#include <windows.h>

#include <iostream>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    // Register the window class.
    const wchar_t CLASS_NAME[]  = L"Sample Window Class";
    
    WNDCLASS wc = { };

    wc.lpfnWndProc   = WindowProc;
    wc.hInstance     = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    // Create the window.

    HWND hwnd = CreateWindowEx(
        1,                              // Optional window styles.
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

    if (hwnd == NULL)
    {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    // Run the message loop.

    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_CLOSE:
        {
            std::cout << "asdasdfasdffasdf" << std::endl;
                if (MessageBox(hwnd, L"Confirm to quit.", L"My application", MB_OKCANCEL) == IDOK)
            {
                
                DestroyWindow(hwnd);
            }
        // Else: User canceled. Do nothing.
        return 0;
        }
        
    case WM_CREATE:
        AllocConsole();
        freopen("CONOUTS", "w", stdout);
        std::cout << "Console created" << std::endl;
        return 0;

    case WM_DESTROY:
        std::cout << "asdfasdf" << std::endl;
        FreeConsole();
        PostQuitMessage(0);
        return 0;

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            // === 1. Get client area dimensions ===
            RECT rect;
            GetClientRect(hwnd, &rect);
            int width = rect.right - rect.left;
            int height = rect.bottom - rect.top;

            // === 2. Create a memory buffer for double-buffering (smoother rendering) ===
            HDC hdcMem = CreateCompatibleDC(hdc);
            HBITMAP hbmMem = CreateCompatibleBitmap(hdc, width, height);
            SelectObject(hdcMem, hbmMem);

            // === 3. Paint a gradient background (blue to black) ===
            TRIVERTEX vertices[] = {
                { 0, 0, 0xFF00, 0x0000, 0x0000 },          // Top-left (red=0xFF, green=0x00, blue=0x00)
                { width, height, 0x0000, 0xaf00, 0x8000 }   // Bottom-right (blue=0x80)
            };
            GRADIENT_RECT gradientRect = { 0, 1 };
            GradientFill(hdcMem, vertices, 2, &gradientRect, 1, GRADIENT_FILL_RECT_V);

            // === 4. Draw a transparent circle with a border ===
            HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 0)); // Yellow brush
            HPEN hPen = CreatePen(PS_SOLID, 3, RGB(0, 255, 0)); // Green pen
            SelectObject(hdcMem, hBrush);
            SelectObject(hdcMem, hPen);

            Ellipse(hdcMem, width / 4, height / 4, 3 * width / 4, 3 * height / 4);

            // === 5. Draw text with anti-aliasing and a shadow ===
            SetBkMode(hdcMem, TRANSPARENT);
            SetTextColor(hdcMem, RGB(255, 255, 255)); // White text

            HFONT hFont = CreateFont(48, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, 
                                    DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, 
                                    CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, 
                                    VARIABLE_PITCH, TEXT("Arial"));
            SelectObject(hdcMem, hFont);

            const wchar_t* text = L"Hello, GDI!";
            RECT textRect = { 0, 0, width, height };
            DrawTextW(hdcMem, text, -1, &textRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

            // === 6. Blit the memory buffer to the screen (avoids flickering) ===
            BitBlt(hdc, 0, 0, width, height, hdcMem, 0, 0, SRCCOPY);

            // === 7. Clean up resources ===
            DeleteObject(hFont);
            DeleteObject(hPen);
            DeleteObject(hBrush);
            DeleteObject(hbmMem);
            DeleteDC(hdcMem);

            // FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+5));

            EndPaint(hwnd, &ps);
        }
        return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

// https://learn.microsoft.com/en-us/windows/win32/learnwin32/managing-application-state-
// https://learn.microsoft.com/en-us/windows/win32/learnwin32/initializing-the-com-library
// https://learn.microsoft.com/en-us/windows/win32/learnwin32/example--the-open-dialog-box