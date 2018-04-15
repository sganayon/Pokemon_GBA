#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include<string.h>
#include "pokedex.h"

class Perso 
{
public: 
	const std::string persoFstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/persofaceF.png";
	const std::string persoLstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/persofaceL.png";
	const std::string persoRstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/persofaceR.png";
	const std::string persoBstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/persofaceB.png";
	sf::Texture TpersoF;
	sf::Texture TpersoL;
	sf::Texture TpersoR;
	sf::Texture TpersoB;
	sf::Sprite Sperso;

	sf::Vector2i posmap;
	char face;

public :
	Perso(void);
	void setposition(sf::Vector2f);
	void setface(void);
};

class PNJ : public Perso //un PNJ est un joueur qui parle 
{
public :
	sf::Font font;
	sf::Text text;
private : 
	const std::string fontstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/arial.ttf";
	std::string textestr = "bonjour visiteur";
	int ID; // 0 = basique, 1 = centreP, 2 = shopP, 3 = echange equipe ...
public :
	PNJ();
	void settexte(std::string texte);
	void setID(int i);
	int getID(void);
};

class Adversaire : public Perso //un adversaire a une equipe  
{
public:
	sf::Font font;
	sf::Text text;
private:
	const std::string fontstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/arial.ttf";
	std::string textestr = "Vien te battre !!!";
	Pokedex* equipe;
	bool isdown_;
public:
	Adversaire(Pokedex* equipeptr);
	void setequipe(Pokedex* equipeptr);
	Pokedex* getequipe();
	bool isdown();
	void setdown(bool down);
};

