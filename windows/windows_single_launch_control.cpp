#include <iostream>
#include <string>
#include <Windows.h>
#include <Psapi.h>

void GetProcessName(DWORD processId, char *processName, size_t size)
{
    HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processId);
    if (hProcess != NULL)
    {
        HMODULE hModule;
        DWORD cbNeeded;

        if (EnumProcessModules(hProcess, &hModule, sizeof(hModule), &cbNeeded))
        {
            GetModuleBaseNameA(hProcess, hModule, processName, static_cast<DWORD>(size));
        }

        CloseHandle(hProcess);
    }
}

int AppControl(const char *originalName, LPCWSTR windowTitleName)
{
    HWND hwnd = nullptr;

    int counter = 0;

    while ((hwnd = FindWindowEx(NULL, hwnd, NULL, windowTitleName)) != nullptr)
    {
        counter++;
        DWORD processId;
        GetWindowThreadProcessId(hwnd, &processId);

        char processName[MAX_PATH];
        GetProcessName(processId, processName, sizeof(processName));

        if (strstr(processName, originalName) != nullptr)
        {
            if (counter > 1)
            {
                ShowWindow(hwnd, SW_RESTORE);
                SetForegroundWindow(hwnd);
                return 1;
            }
        }
    }

    return 0;
}