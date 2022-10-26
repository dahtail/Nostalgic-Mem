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

std::vector<DWORD> NostalgicMem::ProcScanner::Scan(std::vector<DWORD> last_scan, INT8 value)
{
	//todo
}

std::vector<DWORD> NostalgicMem::ProcScanner::Scan(std::vector<DWORD> last_scan, INT16 value)
{
	//todo
}

std::vector<DWORD> NostalgicMem::ProcScanner::Scan(std::vector<DWORD> last_scan, INT32 value)
{
	//todo
}

std::vector<DWORD> NostalgicMem::ProcScanner::Scan(std::vector<DWORD> last_scan, INT64 value)
{
	//todo
}

std::vector<DWORD> NostalgicMem::ProcScanner::Scan(std::vector<DWORD> last_scan, std::string value)
{
	//todo
}

std::vector<DWORD> NostalgicMem::ProcScanner::Scan(std::vector<DWORD> last_scan, const char* value)
{
	//todo
}

std::vector<DWORD> NostalgicMem::ProcScanner::Scan(std::vector<DWORD> last_scan, double value)
{
	//todo
}

std::vector<DWORD> NostalgicMem::ProcScanner::Scan(std::vector<DWORD> last_scan, float value) 
{
	//todo
}