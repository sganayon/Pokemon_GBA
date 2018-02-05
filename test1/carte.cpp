#include"carte.h"
#include <SFML/Graphics.hpp>
#include "sprite.h"
#include"player.h"
#include<iostream>
#include<string.h>

Map::Map(Rien rien, int txmax = 50, int tymax = 37) 
{
	for (int i = 0; i < txmax; i++)
	{
		for (int j = 0; j < tymax; j++)
		{
			row.push_back(rien.Srien); //ini une row avec texture transparente
		}
		place.push_back(row); //ini chaque case de place par une row 
		row.clear(); // reset row (inutile ici on aurais put faire deux for separer)
	}
}

void Map::set(sf::Sprite elem, int i, int j) 
{
	elem.setPosition(16 * i, 16 * j);
	place[i][j] = elem;
}

sf::Sprite Map::get(int i, int j)
{
	return place[i][j];
}
