#pragma once
#include<string>

// le type enuméré décrivant le type de Pokemon parmi les 18 existants
// enum permet de definir les valeurs possible
typedef enum {
	Normal, Fighting, Flying, Poison, Ground, Rock, Bug,
	Ghost, Steel, Fire, Grass, Water, Electric, Psychic,
	Ice, Dragon, Dark, Fairy
} PokemonType;

typedef enum {
	male, femmelle, neutre
}pokemon_genre;

typedef struct especepokemon {
	char* nom;
	PokemonType type;
	char* evolvesTo;
	unsigned int nbBonbonsPourEvoluer;
	bool estEvolue;
	std::string cheminface;
	std::string cheminback;
}especepokemon;
