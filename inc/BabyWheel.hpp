/*
** EPITECH PROJECT, 2019
** ClassCreator
** File description:
** BabyWheel
*/

#ifndef BABYWHEEL_HPP_
#define BABYWHEEL_HPP_

/* STD LIB */
#include <iostream>
#include <vector>

/* CLASS */
#include "File.hpp"

class BabyWheel {

	public:

		BabyWheel() = default;
		~BabyWheel() = default;

		/* Unlock BabyWheel */
		bool unlock(std::vector<std::string> v);

	private:

		/* Tools */
		void printFile(std::string s);
		bool overloadingFile(std::string source, std::string target, std::string path);
		bool createFile(std::string source, std::string target);
		bool removeFile(std::string target);
		void build();

		/* overlaoding */
		bool overloading();
		bool create();
		bool remove();

		/* Verification of BabyWheel State */
		bool babyCheck();
		bool babyImprove();

		File _f;
		std::vector<std::string> _v;
		std::string s;

};

#endif /* !BABYWHEEL_HPP_ */
