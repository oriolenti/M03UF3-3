#pragma once
#include <string>

struct Sentence {
	char symbol;
	std::string name;
	std::string text;

	void Initialize(char s, std::string n, std::string t);

	std::string GetString();

};