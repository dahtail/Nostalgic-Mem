#include "ProcScanner.h"

NostalgicMem::ProcScanner::ProcScanner(DWORD process_id)
{
	this->pid = process_id;
	this->hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, this->pid);
}

NostalgicMem::ProcScanner::ProcScanner(const char* process_name)
{
	this->pid = NostalgicMem::FindProcessByName(process_name);
	this->hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, this->pid);
}

NostalgicMem::ProcScanner::ProcScanner(std::string process_name)
{
	this->pid = NostalgicMem::FindProcessByName(process_name);
	this->hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, this->pid);
}

NostalgicMem::ProcScanner::~ProcScanner()
{
	CloseHandle(this->hProcess);
}

template <typename T>
constexpr const T NostalgicMem::ProcScanner::Read(const std::uintptr_t& address) const noexcept
{
	T value = { };
    ::ReadProcessMemory(this->hProcess, reinterpret_cast<const void*>(address), &value, sizeof(T), NULL);
    return value;
}

/* Probably wrong, needs testing */
template <typename T>
constexpr const std::vector<DWORD> NostalgicMem::ProcScanner::Search(T wanted_val) const noexcept
{
	std::vector<DWORD> scanResult;

	unsigned char* buffer = (unsigned char*)calloc(1, size);
	DWORD bytes_read = 0;

	for (DWORD i = 0x00000000; i < 0x7FFFFFFF; i += size) {
		ReadProcessMemory(this->hProcess, (void*)i, buffer, size, &bytes_read);

		for (int j = 0; j < size - 4; j += 4) {
			T val;
			memcpy(&val, &buffer[j], sizeof(T));
			if (val == wanted_val) {
				scanResult.push_back(i);
			}
		}
	}

	free(buffer);

	return scanResult;
}


template <typename T>
constexpr const std::vector<DWORD> NostalgicMem::ProcScanner::SearchNext(T wanted_val, std::vector<DWORD> lastScan) const noexcept
{

	std::vector<DWORD> scanResult;

	for (DWORD addr : lastScan)
	{
		if (this->Read(addr) ==  wanted_val)
		{
			scanResult.push_back(addr);
		}
	}

	return scanResult;
}


template <typename T>
constexpr void NostalgicMem::ProcScanner::Write(const std::uintptr_t& address, const T& value) const noexcept
{
	 ::WriteProcessMemory(this->hProcess, reinterpret_cast<void*>(address), &value, sizeof(T), NULL);
}