#pragma once
#include "pokemon.h"

class Ressource
{
private :
	int tune;
	int pokeball;
	int potion;
public : 
	Ressource(void);
	int gettune(void);
	int getpokeball(void);
	int getpotion(void);
	void settune(int);
	void setpokeball(int);
	void setpotion(int);
};

class Pokedex
{
private:
	int nbpokemon;
	int taille;
	pokemon* mespokemons;
public : 
	Pokedex(const int size);
	int getnbpokemon(void);
	int gettaille(void);
	pokemon* getmespokemons(void);
	pokemon getpokemon(int indice);
	void setnbpokemon(int);
	void settaille(int);
	void setmespokemons(pokemon*);
	void setpokemon(pokemon p, int indice);
};

void insertPokemon(Pokedex** monpokedex, pokemon p);
pokemon genererPokemon(especepokemon bestiaire[150]);
pokemon genererPokemonadv(especepokemon bestiaire[150]);
void supPokemon(Pokedex** monpokedex, int num, especepokemon bestiaire[]);
void insertPokemon2(Pokedex** monpokedex, pokemon p, int place);

