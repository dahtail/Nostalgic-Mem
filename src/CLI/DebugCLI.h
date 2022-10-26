#ifndef __DEBUGCLI_H__
#define __DEBUGCLI_H__

#include <iostream>
#include <thread>

namespace NostalgicMem 
{
	class DebugCLI
	{
        bool is_running;

	public:
        DebugCLI();
		~DebugCLI();

        void Menu();
	};

}

#endif