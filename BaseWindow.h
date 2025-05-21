#pragma once
#include <windows.h>

class BaseWindow {
    protected:
        HWND m_hwnd;
        virtual BOOL ClassName() const { return L"BaseWindow" };
        virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) = 0;

    public:
        BaseWindow();
        virtual ~BaseWindow();
        BOOL Create();
}
