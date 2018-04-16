#pragma once
#include <SFML/Graphics.hpp>
#include<string>
#include<string.h>
#include "player.h"

void sauvegarder(std::string chemin, sf::Vector2i position, sf::Vector2i posmapbefore, int IDmap, Pokedex* stocage, Pokedex* equipe, Ressource* mesressource, std::vector<Adversaire*>& alladv);
void charger(std::string chemin, sf::Vector2i* position, sf::Vector2i* posmapbefore, int* IDmap, Pokedex** stocage, Pokedex** equipe, Ressource* mesressource, std::vector<Adversaire*>& alladv);
int hasch(std::string str);