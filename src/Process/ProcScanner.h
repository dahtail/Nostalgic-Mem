#ifndef __PROCSCANNER_H__
#define __PROCSCANNER_H__

#define size 0x00000808

#include <Windows.h>
#include "../Utils/FindProcess.h"
#include <string>
#include <vector>

namespace NostalgicMem 
{
	class ProcScanner
	{
		
		DWORD pid;
		HANDLE hProcess;

	public:
		ProcScanner(DWORD process_id);
		ProcScanner(const char* process_name);
		ProcScanner(std::string process_name);
		~ProcScanner();

		template <typename T>
    	constexpr const T Read(const std::uintptr_t& address) const noexcept;

		template <typename T>
    	constexpr const std::vector<DWORD> NostalgicMem::ProcScanner::Search(T wanted_val) const noexcept

		template <typename T>
    	constexpr const std::vector<DWORD> NostalgicMem::ProcScanner::SearchNext(T wanted_val, std::vector<DWORD> lastScan) const noexcept

		template <typename T>
    	constexpr void Write(const std::uintptr_t& address, const T& value) const noexcept;
	};

}

#endif
