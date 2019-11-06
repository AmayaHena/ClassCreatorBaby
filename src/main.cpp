/*
** EPITECH PROJECT, 2019
** ClassCreator
** File description:
** main
*/

/* STD LIB */
#include <functional>

#include "Core.hpp"
#include "BabyWheel.hpp"

int main(int ac, char **av)
{
	(void)ac;
	BabyWheel b;
	std::vector<std::string> v;

	for (unsigned int i = 0; av[i]; i++)
		v.push_back(av[i]);
	v.erase(v.begin());
	if (b.unlock(v))
		return 0;

	Core c(v);

	if (c.run() == false)
		return 84;
	std::cout << "\033[1;32mCreation Done\033[0m" << std::endl;
	return 0;
}