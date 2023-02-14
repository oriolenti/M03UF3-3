#include <iostream>
#include <sstream>
#include <string>

#include "rapidxml.hpp"
#include "rapidxml_iterators.hpp"
#include "rapidxml_print.hpp"
#include "rapidxml_utils.hpp"

rapidxml::xml_document<>* LoadXMLdoc(std::string path) {
	//Creem la variable (contenidor de funcións i tipus) que contindrà l'arxiu XML
	rapidxml::xml_document<>* doc = new rapidxml::xml_document<>();

	//Obrir l'arxiu XML amb un input file stream (ifstream), exactament igual que el que hem fet
	std::ifstream file(path);

	//Crear un buffer (espai de memoria on hi crees un arxiu)
	std::stringstream buffer;

	//Posar l'arxiu XML que hem obert (file) dins el buffer
	buffer << file.rdbuf();

	//Tanquem arxiu XML perque ja tenim carregat el buffer
	file.close();

	//Parse significa llegir i interpretar

	//Generar un string de C++ amb el contingut del buffer
	std::string content(buffer.str());

	//Carregar l'string a rapidXML
	doc->parse<0>(&content[0]);

	return doc;
}

int main() {

	rapidxml::xml_document<>* doc = LoadXMLdoc("bookstore.xml");
	
	std::cout << "El nombre de la raiz es: " << doc->first_node()->name();

}