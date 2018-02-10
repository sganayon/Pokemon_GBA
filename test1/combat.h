#pragma once
#include"pokemon.h"
#include"pokedex.h"
#include"sprite.h"

typedef struct pokemon;

typedef struct combatespece
{
	char* nature;
	char* strongagainst[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };
	char* weakagainst[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };
	combatespece* next = nullptr;
}combatespece;

typedef struct hashtable
{
	combatespece* cmbtab[26] = { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr };
	const int m = 26; // nombre de combatespece (18 elem avec charge a 0.7)
	int keysetSize = 0; // nombre de cles
} hashtable;

class CombatPokemon
{
private:
	int viepkmequipe;
	int viepkmsauv;
	int dgtfrompkmequi;
	int dgtfrompkmsauv;
	int dgtattpkmequi;
	int dgtattpkmsauv;
	bool IsPkmEquiFirst;
	bool Iscmbt;
	bool IsPkmEquiDead;
	float multpkmequi;
	float multpkmsauv;
	std::string typeequi;
	std::string typesauv;

public :
	int getviepkmequi();
	int getviepkmsauv();
	int getdgtpkmequi();
	int getdgtpkmsauv();
	bool getpkmequifirst();
	bool getIsCmbt();
	bool getIsPkmEquiDead();
	float getmultpkmequi();
	float getmultpkmsauv();
	int getdgtattpkmequi();
	int getdgtattpkmsauv();
	std::string gettypeequi();
	std::string gettypesauv();

	void setviepkmequi(int);
	void setviepkmsauv(int);
	void setdgtpkmequi(int);
	void setdgtpkmsauv(int);
	void setpkmequifirst(bool);
	void setmultpkmequi(float);
	void setmultpkmsauv(float);
	void setdgtattpkmequi(int);
	void setdgtattpkmsauv(int);
	void settypeequi(std::string);
	void settypesauv(std::string);
	void setIsCmbt(bool);
	void setIsPkmEquiDead(bool);

	CombatPokemon();
};

int hash(const char *str, hashtable* htab);

char* pokemonTypeToChar(PokemonType t);

combatespece* get(hashtable* htab, char* key);

bool contains(hashtable* htab, combatespece* c);

void insert(combatespece* c, hashtable* htab);

hashtable* inithashtable();

void combat(pokemon* p1, pokemon* p2, hashtable* htab, especepokemon bestiaire[], unsigned int dgtatt1, bool* CmbtIsOver, bool* IsP1Dead, Ressource* mesressource, sf::RenderWindow* window, Combatdeco cmbtdeco, EffectAtt* effect, CombatPokemon* cmbtpkm);

void combatsav(pokemon* p1, pokemon* p2, hashtable* htab, especepokemon bestiaire[], bool* CmbtIsOver, bool* IsP1Dead, CombatPokemon* cmbtpkm);

void ispowerup(pokemon*p1, especepokemon bestiaire[]);

std::string floattostring(float reel);

std::string  majspriteatt(EffectAtt* effect, std::string type, unsigned int dgtatt, char sens);

