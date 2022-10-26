#include <iostream>
#include <thread>
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
    system("cls");
    while (is_running)
    {
        int opt;

        std::cout << "\t\t\t\t\t======================================\t\t\t\t\t" << std::endl;
        std::cout << "\t\t\t\t\t Nostalgic Memory Scanner (Debug)\t\t\t\t\t" << std::endl;
        std::cout << "\t\t\t\t\t======================================\n\t\t\t\t\t" << std::endl;
        
        std::cout << "\t\t\t\t\t 1. Select the process (using pid)\n\t\t\t\t\t" << std::endl;
        std::cout << "\t\t\t\t\t 2. Select the process (using name)\n\t\t\t\t\t" << std::endl;
        std::cout << "\t\t\t\t\t 3. Exit\n\t\t\t\t\t" << std::endl;

        std::cin >> opt;
        
        switch (opt)
        {
        case 1:
            std::cout << "test" << std::endl;
            is_running = false;
            system("cls");
            break;
        case 2:
            std::cout << "test2" << std::endl;
            is_running = false;
            system("cls");
            break;
        case 3:
            std::cout << "Leaving... " << std::endl;
            is_running = false;
            Sleep(1000); // 1 second
            system("cls");
        default:
            break;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}