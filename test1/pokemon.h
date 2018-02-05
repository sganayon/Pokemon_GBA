#pragma once
#include <SFML/Graphics.hpp>
#include"pokemonTypes.h"
#include"bestiaire.h"
#include<string>
#include"util.h"
#include<string.h>

class pokemon
{
private :
	std::string nom;
	std::string attaque1;
	std::string attaque2;
	std::string attaque3;
	std::string attaque4;

	unsigned int XP;				//XP du niveau actuel
	unsigned int niveau;
	unsigned int stade_evolution;
	unsigned int PV;				//pv max (croissant avec niv)
	unsigned int Dgt1;				//degat attaque 1
	unsigned int Dgt2;
	unsigned int Dgt3;
	unsigned int Dgt4;
	unsigned int puissance;			//degat de base (croissant avec niv)

	int actPV;	//pv actuel

	pokemon_genre genre;

public : 
	sf::Texture TpokeF;
	sf::Sprite SpokeF;

	sf::Texture TpokeB;
	sf::Sprite SpokeB;

	pokemon();
	pokemon(std::string name);
	std::string getnom(void);
	std::string getatt1(void);
	std::string getatt2(void);
	std::string getatt3(void);
	std::string getatt4(void);
	unsigned int getXP(void);
	unsigned int getniveau(void);
	unsigned int getstade(void);
	unsigned int getPV(void);
	unsigned int getdgt1(void);
	unsigned int getdgt2(void);
	unsigned int getdgt3(void);
	unsigned int getdgt4(void);
	unsigned int getpuissance(void);
	int getactPV(void);
	pokemon_genre getgenre(void);

	void setnom(std::string);
	void setatt1(std::string);
	void setatt2(std::string);
	void setatt3(std::string);
	void setatt4(std::string);
	void setXP(unsigned int);
	void setniveau(unsigned int);
	void setstade(unsigned int);
	void setPV(unsigned int);
	void setdgt1(unsigned int);
	void setdgt2(unsigned int);
	void setdgt3(unsigned int);
	void setdgt4(unsigned int);
	void setpuissance(unsigned int);
	void setactPV(int);
	void setgenre(pokemon_genre genre);
	
	void majsprite(std::string cheminB, std::string cheminF);
};

void evolve(pokemon* p, especepokemon bestiaire[]);
void powerup(pokemon* p, especepokemon bestiaire[]);
void unlockatt2(pokemon* p, PokemonType type);
void unlockatt3(pokemon* p, PokemonType type);
void unlockatt4(pokemon* p, PokemonType type);
int chercher(std::string pnom, especepokemon bestiaire[]);