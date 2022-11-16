#include "FindProcess.h"

DWORD NostalgicMem::FindProcessByName(const char* proc_name)
{

    DWORD result_pid = 0;

    PROCESSENTRY32 entry;
    entry.dwSize = sizeof(PROCESSENTRY32);

    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

    if (Process32First(snapshot, &entry) == TRUE)
    {
        while (Process32Next(snapshot, &entry) == TRUE)
        {
            if (stricmp((const char*)entry.szExeFile, proc_name) == 0)
            {
                result_pid = entry.th32ProcessID;
                break;
            }
        }
    }

    CloseHandle(snapshot);

    return result_pid;
}

DWORD NostalgicMem::FindProcessByName(std::string proc_name)
{

    DWORD result_pid = 0;

    PROCESSENTRY32 entry;
    entry.dwSize = sizeof(PROCESSENTRY32);

    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

    if (Process32First(snapshot, &entry) == TRUE)
    {
        while (Process32Next(snapshot, &entry) == TRUE)
        {
            if (stricmp((const char*)entry.szExeFile, proc_name.c_str()) == 0)
            {
                result_pid = entry.th32ProcessID;
                break;
            }
        }
    }

    CloseHandle(snapshot);

    return result_pid;
}

DWORD NostalgicMem::FindProcessByWindowName(const char* window_name)
{
    HWND hwnd = FindWindowA(0, (LPCSTR)window_name);
    if (hwnd == 0)
    {
        MessageBoxA(0, "Error cannot find window", "ERROR", MB_OK | MB_ICONERROR);
    }
    else
    {
        DWORD result_pid;
        GetWindowThreadProcessId(hwnd, &result_pid);
        HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, result_pid);

        if (!hProcess)
        {
            MessageBoxA(0, "Could not open the process!", "ERROR", MB_OK | MB_ICONERROR);
            return 0;
        }
        else
        {
            CloseHandle(hProcess);
            return result_pid;
        }
    }
    return 0;
}

DWORD NostalgicMem::FindProcessByWindowName(std::string window_name)
{
    HWND hwnd = FindWindowA(0, (LPCSTR)window_name.c_str());
    if (hwnd == 0)
    {
        MessageBoxA(0, "Error cannot find window", "ERROR", MB_OK | MB_ICONERROR);
    }
    else
    {
        DWORD result_pid;
        GetWindowThreadProcessId(hwnd, &result_pid);
        HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, result_pid);

        if (!hProcess)
        {
            MessageBoxA(0, "Could not open the process!", "ERROR", MB_OK | MB_ICONERROR);
            return 0;
        }
        else
        {
            CloseHandle(hProcess);
            return result_pid;
        }
    }
    return 0;
}