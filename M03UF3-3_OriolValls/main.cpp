#include <string>
#include <sstream>
#include <iostream>

#include"Sentence.h"

#include "rapidxml.hpp"
#include "rapidxml_iterators.hpp"
#include "rapidxml_print.hpp"
#include "rapidxml_utils.hpp"

std::string GetFileString(std::string path) {
	std::ifstream file(path);

	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();

	std::string content(buffer.str());

	return content;
}

enum Scene{MENU, CONVERSATION};
bool Menu();
void Conversation();
std::string verifyedPath = "";

int main() {

	Scene currentScene = MENU;

	bool shouldlQuit = false;

	while (!shouldlQuit)
	{
		switch (currentScene)
		{
		case MENU:
			Menu();
			currentScene = CONVERSATION;
			break;

		case CONVERSATION:
			Conversation();
			currentScene = MENU;
			break;

		default:
			break;
		}
	}
}

bool Menu() {
	int choice;
	bool validInput = true;
	
	do {

		std::cout << "----- FeedbackSeekerBOT ----- \n";
		std::cout << " 1.- Load conversation \n";
		std::cout << " 2.- Exit \n";
		std::cout << "----------------------------- \n";

		std::cout << " Choice: ";

		std::cin >> choice;

		validInput = choice == 1 || choice == 2;

		if (!validInput)
		{
			system("cls");
			continue;
		}



		if (choice == 1) {
			std::cout << std::endl << " --> Enter conversation name: ";

			std::string path;

			std::cin >> path;

			std::ifstream file(path + "xml");
			if (file.is_open()) {
				file.close();
				return false;

			}
			else
			{
				std::cout << std::endl << " !! The name provided does not exist !! \n";
				system("pause");
				system("cls");
			}
		}

		else if (choice == 2) {
			return true;
		}

	} while (validInput);
}

void Conversation() {
	system("cls");

	rapidxml::xml_document<> doc;
	std::string fileStr = GetFileString(verifyedPath + ".xml");
	doc.parse<0>(&fileStr[0]);

	std::vector <Sentence> sentences;
	rapidxml::xml_node<>* root = doc.first_node();
	rapidxml::xml_node<>* sentenceNode = root->first_node();

	for (sentenceNode; sentenceNode != nullptr; sentenceNode = sentenceNode->next_sibling()) {

		char symbol = sentenceNode->first_attribute("symbol")->value()[0];
		std::string name = sentenceNode->first_node()->value();
		std::string text = sentenceNode->first_node()->next_sibling()->value();

		Sentence newSent;
		newSent.Initialize(symbol, name, text);
		sentences.push_back(newSent);

		for (int i = 0; i < sentences.size(); i++)
		{
			for (int j = 0; j <= i; j++)
			{
				std::cout << sentences[j].GetString();
			}
			system("pause");
			system("cls");
		}

	}
}