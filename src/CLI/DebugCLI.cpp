#include <iostream>
#include <thread>
#include <string>
#include <Windows.h>

#include "DebugCLI.h"


NostalgicMem::DebugCLI::DebugCLI()
{

}

NostalgicMem::DebugCLI::~DebugCLI()
{

}


void NostalgicMem::DebugCLI::Menu()
{
    std::string Menu[3] = { "1. Select the process (using pid)",
                            "2. Select the process (using name)",
                            "3. Select the process (using window name)"};
    int pointer = 0;

    while(is_running)
    {
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        std::cout << "==================================" << std::endl;
        std::cout << " Nostalgic Memory Scanner (Debug)" << std::endl;
        std::cout << "==================================\n" << std::endl;

        for (int i = 0; i < 3; ++i)
        {
            if (i == pointer)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                std::cout << Menu[i] << std::endl;
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                std::cout << Menu[i] << std::endl;
            }
        }

        while (true)
        {
            if (GetAsyncKeyState(VK_UP) != 0)
            {
                pointer -= 1;
                if (pointer == -1)
                {
                    pointer = 2;
                }
                break;
            }
            else if (GetAsyncKeyState(VK_DOWN) != 0)
            {
                pointer += 1;
                if (pointer == 4)
                {
                    pointer = 0;
                }
                break;
            }
            else if (GetAsyncKeyState(VK_RETURN) != 0)
            {
                switch (pointer)
				{
					case 0:
					{
						std::cout << "\n\n\nScanning 678657...";
                        // just stopping is_running cuz it's a test
                        is_running = false;
						Sleep(1000);
					} break;
					case 1:
					{
						std::cout << "\n\n\nScanning blabla.exe...";
                        // just stopping is_running cuz it's a test
                        is_running = false;
						Sleep(1000);
					} break;
					case 2:
					{
						std::cout << "\n\n\nScanning asdasd (window)...";
                        // just stopping is_running cuz it's a test
                        is_running = false;
						Sleep(1000);
					} break;
				}
				break;
            }
            // This shit save us 🧀
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
        Sleep(150);
    }
}