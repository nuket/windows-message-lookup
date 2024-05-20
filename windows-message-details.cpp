// --------------------------------------------------------------------------
// Written in 2024 by Max Vilimpoc and released into the Public Domain,
// do what you like with it, but keep this header in place.
//
// Generates and returns a string description of the Windows message.
// Hopefully with Return Value Optimization.
//
// Import It
// extern std::wstring WindowsMessageDetails(UINT message, WPARAM wParam, LPARAM lParam);
//
// Use It
// OutputDebugStringW(WindowsMessageDetails(uMsg, wParam, lParam).c_str());
// --------------------------------------------------------------------------

#include <windows.h>

#include <format>

extern "C" const TCHAR * const WindowsMessageLookup(UINT message);

#ifndef UNICODE
std::string WindowsMessageDetails(UINT message, WPARAM wParam, LPARAM lParam)
#else
std::wstring WindowsMessageDetails(UINT message, WPARAM wParam, LPARAM lParam)
#endif
{
    switch (message)
    {
        case WM_SIZE:
            return std::format(TEXT("{:04x}: {}: {} x {}\n"), message, WindowsMessageLookup(message), LOWORD(lParam), HIWORD(lParam));
        default:
            return std::format(TEXT("{:04x}: {:32} WP: {:016x} LP: {:016x} (message details unknown)\n"), message, WindowsMessageLookup(message), wParam, lParam);
    }
}
