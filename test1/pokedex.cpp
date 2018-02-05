#include"pokedex.h"
#include"pokemon.h"
#include"sprite.h"
#include <iostream>
#include<stdlib.h>
#include<time.h>
#include "util.h"
#include<thread>
#include<chrono>
#include<cstring>


Ressource::Ressource(void) { tune = 3000; pokeball = 0; potion = 0; }
int Ressource::gettune(void) { return tune; }
int Ressource::getpokeball(void) { return pokeball; }
int Ressource::getpotion(void) { return potion; }
void Ressource::settune(int argent) { tune = argent; }
void Ressource::setpokeball(int pokeboule) { pokeball = pokeboule; }
void Ressource::setpotion(int popo) { potion = popo; }

Pokedex::Pokedex(const int size) 
{
	pokemon* pokedexjoueur = new pokemon[size];
	mespokemons = pokedexjoueur;
	taille = size;
	nbpokemon = 0;
}

int Pokedex::getnbpokemon(void) { return nbpokemon; }
int Pokedex::gettaille(void) { return taille; }
pokemon* Pokedex::getmespokemons(void) { return mespokemons; }
void Pokedex::setnbpokemon(int nbpkm) { nbpokemon = nbpkm; }
void Pokedex::settaille(int size) { taille = size; }
void Pokedex::setmespokemons(pokemon* p) { mespokemons = p; }

pokemon Pokedex::getpokemon(int indice) 
{
	if (indice >= nbpokemon) { throw std::out_of_range("pokedexe::getpokemon_out_of_range"); }
	return mespokemons[indice];
}

void Pokedex::setpokemon(pokemon p, int indice){mespokemons[indice] = p;}

void insertPokemon(Pokedex** monpokedex, pokemon p)
{
	int ordre = 0;
	int j = 0;
	pokemon temp;
	if ((*monpokedex)->gettaille() == (*monpokedex)->getnbpokemon()) //on ne peut plus inserer de pokemon, aug de 50%
	{
		int oldtaille = (*monpokedex)->gettaille(); // on garde l'ancienne taille pour le recopiage (taille = nbpokemon)
		(*monpokedex)->settaille((*monpokedex)->gettaille() * 1.5); //aug de 50% la capa
		pokemon *pokedexjoueur = new pokemon[(*monpokedex)->gettaille()]; //on cree un tableau plus grand

		for (int i = 0; i < oldtaille; i++)
		{
			pokedexjoueur[i] = (*monpokedex)->getpokemon(i); //copiage dans le nouveau tableau
		}

		delete[](*monpokedex)->getmespokemons(); //on libere l'espace de l'ancien tableau
		(*monpokedex)->setmespokemons(pokedexjoueur); // on deplace le pointeur sur le nouveau tableau
	}

	while ((j<(*monpokedex)->getnbpokemon()) && (p.getnom() >= (*monpokedex)->getpokemon(j).getnom())) //trouve a quelle case on doit inserer le pokemon
	{
		/*ordre = strcmp(p.nom, (*monpokedex)->mespokemons[j].nom);
		if (ordre == -1)
		{
		break;
		}*/
		j++;
	}
	for (int i = (*monpokedex)->getnbpokemon(); i>j; i--)
	{
		(*monpokedex)->setpokemon((*monpokedex)->getpokemon(i - 1),i);
	}
	(*monpokedex)->setpokemon(p,j); // insertion pokemon;
	(*monpokedex)->setnbpokemon((*monpokedex)->getnbpokemon() + 1);
}

void supPokemon(Pokedex** monpokedex, int num, especepokemon bestiaire[])
{
	pokemon* tmp;

	int i = chercher((*monpokedex)->getpokemon(num).getnom(), bestiaire);
	for (int i = num; i <(*monpokedex)->getnbpokemon() -1; i++)
	{
		(*monpokedex)->setpokemon((*monpokedex)->getpokemon(i + 1),i);
	}
	(*monpokedex)->setnbpokemon((*monpokedex)->getnbpokemon() - 1);
}

pokemon genererPokemon(especepokemon bestiaire[150])
{
	int i = (random_at_most(10000) % 150);
	while (bestiaire[i].estEvolue)
	{
		i = (random_at_most(10000) % 150);
	}
	pokemon pokesauvage(bestiaire[i].nom);
	pokesauvage.majsprite(bestiaire[i].cheminback, bestiaire[i].cheminface);
	return pokesauvage;
}

void insertPokemon2(Pokedex** monpokedex, pokemon p, int place)
{
	(*monpokedex)->setpokemon(p, place); // insertion pokemon;
	if(place >= (*monpokedex)->getnbpokemon()){ (*monpokedex)->setnbpokemon((*monpokedex)->getnbpokemon() + 1); }// si on insertr sur un pkm existant alors on aug pas le nb de pkm
	
}