#include"player.h"
#include <SFML/Graphics.hpp>
#include<iostream>
#include<string.h>

Perso::Perso(void)
{
	TpersoF.loadFromFile(persoFstr);
	TpersoL.loadFromFile(persoLstr);
	TpersoB.loadFromFile(persoBstr);
	TpersoR.loadFromFile(persoRstr);
	Sperso.setTexture(TpersoF);
	Sperso.setOrigin(Sperso.getOrigin().x, Sperso.getOrigin().y + 16); //perso fait deux case de haut, les pied case sont la case inf et declenchent les actions
	face = 'F';
}

void Perso::setposition(sf::Vector2f coord)
{
	Sperso.setPosition(coord);
}

void Perso::setface(void)
{
	switch (face)
	{
	case 'F':
		Sperso.setTexture(TpersoF);
		break;
	case 'B':
		Sperso.setTexture(TpersoB);
		break;
	case 'R':
		Sperso.setTexture(TpersoR);
		break;
	case 'L':
		Sperso.setTexture(TpersoL);
		break;
	default:
		Sperso.setTexture(TpersoF);
		break;
	}
	
}


PNJ::PNJ() 
{
	Sperso.setColor(sf::Color::Yellow);
	font.loadFromFile(fontstr);
	text.setFont(font);
	text.setString(textestr);
	text.setCharacterSize(16);
	text.setFillColor(sf::Color::Black);
	text.setPosition(40.f, 564.f);
}

void PNJ::settexte(std::string texte) 
{
	text.setString(texte);
}

void PNJ::setID(int i) 
{
	ID = i;
}

int PNJ::getID(void)
{
	return ID;
}