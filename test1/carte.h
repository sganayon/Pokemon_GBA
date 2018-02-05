#pragma once
#include <SFML/Graphics.hpp>
#include "sprite.h"
#include"player.h"
#include<iostream>
#include<string.h>

class Map
{
private:
	std::vector<std::vector<sf::Sprite>> place;
	std::vector<sf::Sprite> row;
public:
	Map(Rien rien, int txmax, int tymax);
	void set(sf::Sprite elem, int i, int j);
	sf::Sprite get(int i, int j);
};
