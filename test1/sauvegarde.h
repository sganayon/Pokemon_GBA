#pragma once
#include <SFML/Graphics.hpp>
#include<string>
#include<string.h>
#include "pokedex.h"

void sauvegarder(std::string chemin, sf::Vector2i position, sf::Vector2i posmapbefore, int IDmap, Pokedex* stocage, Pokedex* equipe, Ressource* mesressource);
void charger(std::string chemin, sf::Vector2i* position, sf::Vector2i* posmapbefore, int* IDmap, Pokedex** stocage, Pokedex** equipe, Ressource* mesressource);
int hasch(std::string str);