#include "Sentence.h"

void Sentence::Initialize(char s, std::string n, std::string t) {

	symbol = s;
	name = n;
	text = t;

}

std::string Sentence::GetString() {
	//" symbol name: text\n\n"
	std::string result = " ";
	result += symbol;
	result += " ";
	result += name;
	result += ": ";
	result += text;
	result += "\n\n";

	return result;
}