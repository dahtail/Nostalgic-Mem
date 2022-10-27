#ifndef __PROCSCANNER_H__
#define __PROCSCANNER_H__

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

		/* How we will scan:
		 * Instead of making some kind of struct that stores each value and the address we found the value in, we will simply re-read all the time and compare each value to the wanted value
		 * If last_scan is empty, assume it's a new scan, if last_scan is not empty, only scan those addresses and compare it to the wanted value
		 */

		std::vector<DWORD> Scan(std::vector<DWORD> last_scan, INT8 value);
		std::vector<DWORD> Scan(std::vector<DWORD> last_scan, INT16 value);
		std::vector<DWORD> Scan(std::vector<DWORD> last_scan, INT32 value);
		std::vector<DWORD> Scan(std::vector<DWORD> last_scan, INT64 value);
		std::vector<DWORD> Scan(std::vector<DWORD> last_scan, std::string value);
		std::vector<DWORD> Scan(std::vector<DWORD> last_scan, const char* value);
		std::vector<DWORD> Scan(std::vector<DWORD> last_scan, double value);
		std::vector<DWORD> Scan(std::vector<DWORD> last_scan, float value);

	};

}

#endif