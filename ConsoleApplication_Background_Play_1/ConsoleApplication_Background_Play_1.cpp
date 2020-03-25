// ConsoleApplication_Background_Play_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <Windows.h>
#include <stdio.h>
#include <ShObjIdl_core.h>
#include <iostream>
#include <string>
#include <iostream>
#include <filesystem>


namespace fs = std::filesystem;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pCmdLine, int nCmdShow)
{
	std::string path = "C:\\Users\\user\\Desktop\\Desktop_Background";
	std::srand(std::time(0)); // must be called once at the start of the program
	std::size_t num_files = (std::size_t)std::distance(std::filesystem::directory_iterator{ path }, std::filesystem::directory_iterator{});

	//your program should replace this loop:
	int i = 0;
	while (1) {

		if (i >= num_files)
			i = 0;

		auto it = fs::directory_iterator(path);

		std::advance(it, i);

		const wchar_t *p = (*it).path().c_str();

		std::cout << (*it).path() << std::endl;

		int result = SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, (void *)p, SPIF_UPDATEINIFILE);

		Sleep(1000000); //because of the the empty loop, I don't want to waste CPU...

		i++;
	}

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
