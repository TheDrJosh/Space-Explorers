#pragma once
#include <fstream>
#include <iostream>
#include <string>

namespace ExplorerEngine
{
	namespace FileSystem
	{
		std::string GetFile(const std::string& filepath)
		{
			std::string file = "";
			std::string line;
			std::ifstream myfile(filepath);
			if (myfile.is_open())
			{
				while (getline(myfile, line))
				{
					file += line + "\n";
				}
				myfile.close();
			}
			else std::cout << "Unable to open file " << filepath << std::endl;
			return file;
		}

	}

}
