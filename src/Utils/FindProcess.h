#ifndef __FINDPROCESS_H__
#define __FINDPROCESS_H__

#include <string>
#include <cstdio>
#include <windows.h>
#include <tlhelp32.h>

namespace NostalgicMem
{
	DWORD FindProcessByName(const char* proc_name);
	DWORD FindProcessByName(std::string proc_name);
}

#endif