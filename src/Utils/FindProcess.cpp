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