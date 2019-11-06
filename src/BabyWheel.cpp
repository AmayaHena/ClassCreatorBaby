/*
** EPITECH PROJECT, 2019
** ClassCreator
** File description:
** BabyWheel
*/

#include "BabyWheel.hpp"

/* STD LIB */
#include <functional>
#include <fstream>

void BabyWheel::printFile(std::string s)
{
	std::vector<std::string> v = _f.loadFile(s, true);

	for (const std::string &s : v)
		std::cout << s << std::endl;
}

bool BabyWheel::overloadingFile(std::string source, std::string target, std::string path)
{
	std::vector<std::string> v = _f.loadFile(source, true);
	std::string command = "rm " + target;

	std::cout << "\033[0;32mOverloading \033[0m" << target << "\033[0;32m with \033[0m" << source << std::endl;
	system(command.c_str());

	command = "cp " + source + " " + path;
	system(command.c_str());
	return true;
}

bool BabyWheel::createFile(std::string source, std::string target)
{
	std::string command = "cp " + source + " " + target;

	std::cout << "\033[0;32mCreating \033[0m" << source << std::endl;
	system(command.c_str());
	return true;
}

bool BabyWheel::removeFile(std::string target)
{
	std::string command = "rm " + target;

	std::cout << "\033[0;32mDeleting \033[0m" << target << std::endl;
	system(command.c_str());
	return true;
}

bool BabyWheel::babyImprove()
{
	std::vector<std::string> v = _f.loadFile("config/.baby", true);

	if (std::stoi(v[0]) > 25)
		return true;
	std::ofstream file("config/.baby");
	int i = std::stoi(v[0]) + 1;
	file << i << std::endl;
	return false;
}

bool BabyWheel::overloading()
{
	BabyWheel::overloadingFile(".ADVANCED/inc/Core.hpp", "inc/Core.hpp", "inc/");
	BabyWheel::overloadingFile(".ADVANCED/src/Core.cpp", "src/Core.cpp", "src/");

	BabyWheel::overloadingFile(".ADVANCED/inc/Dir.hpp", "inc/Dir.hpp", "inc/");
	BabyWheel::overloadingFile(".ADVANCED/src/Dir.cpp", "src/Dir.cpp", "src/");

	BabyWheel::overloadingFile(".ADVANCED/inc/File.hpp", "inc/File.hpp", "inc/");
	BabyWheel::overloadingFile(".ADVANCED/src/File.cpp", "src/File.cpp", "src/");

	BabyWheel::overloadingFile(".ADVANCED/inc/Parser.hpp", "inc/Parser.hpp", "inc/");
	BabyWheel::overloadingFile(".ADVANCED/src/Parser.cpp", "src/Parser.cpp", "src/");

	BabyWheel::overloadingFile(".ADVANCED/inc/State.hpp", "inc/State.hpp", "inc/");
	BabyWheel::overloadingFile(".ADVANCED/src/State.cpp", "src/State.cpp", "src/");

	BabyWheel::overloadingFile(".ADVANCED/inc/Writer.hpp", "inc/Writer.hpp", "inc/");
	BabyWheel::overloadingFile(".ADVANCED/src/Writer.cpp", "src/Writer.cpp", "src/");

	BabyWheel::overloadingFile(".ADVANCED/src/main.cpp", "src/main.cpp", "src/");
	return true;
}

bool BabyWheel::create()
{
	BabyWheel::createFile(".ADVANCED/inc/Architecture.hpp", "inc/");
	BabyWheel::createFile(".ADVANCED/src/Architecture.cpp", "src/");

	BabyWheel::createFile(".ADVANCED/config/interface.hpp", "config/");
	return true;
}

bool BabyWheel::remove()
{
	BabyWheel::removeFile("config/.baby");
	BabyWheel::removeFile("config/.header");
	BabyWheel::removeFile("src/BabyWheel.cpp");
	BabyWheel::removeFile("inc/BabyWheel.hpp");
	BabyWheel::removeFile("CMakeLists.txt");
	return true;
}

void BabyWheel::build()
{
	system("mv .ADVANCED/CMakeLists.txt .");
	//system("rm -rf .ADVANCED");
	system("cmake . && make");
}

bool BabyWheel::unlock(std::vector<std::string> v)
{
	_v = v;
	if (!babyImprove())
		return false;
	std::cout << "\033[1;32mBaby wheel complete\033[0m" << std::endl;
	std::cout << "\033[1;32mYou'll have the full fonctionality of ClassCreator\033[0m" << std::endl;
	printFile("config/.header");
	std::cout << "\033[1;32mOverloading project to ADVANCED version\033[0m" << std::endl;
	BabyWheel::remove();
	BabyWheel::overloading();
	BabyWheel::create();
	BabyWheel::build();
	std::cout << "\033[1;32mOverloading done\033[0m" << std::endl;
	return true;
}