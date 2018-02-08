#include"combat.h"
#include"sprite.h"
#include<string.h>
#include<iostream>
#include<thread>
#include<chrono>
#include<limits>
#include<string>
#include<sstream>
#include<iomanip>
#include<thread>
#include<chrono>
#include<limits>

int CombatPokemon::getviepkmequi() { return viepkmequipe; }
int CombatPokemon::getviepkmsauv() { return viepkmsauv; }
int CombatPokemon::getdgtpkmequi() { return dgtfrompkmequi; }
int CombatPokemon::getdgtpkmsauv() { return dgtfrompkmsauv; }
bool CombatPokemon::getpkmequifirst() { return IsPkmEquiFirst; }
bool CombatPokemon::getIsCmbt() { return Iscmbt; }
bool CombatPokemon::getIsPkmEquiDead() { return IsPkmEquiDead; }
float CombatPokemon::getmultpkmequi() { return multpkmequi; }
float CombatPokemon::getmultpkmsauv() { return multpkmsauv; }
int CombatPokemon::getdgtattpkmequi() { return dgtattpkmequi; }
int CombatPokemon::getdgtattpkmsauv() { return dgtattpkmsauv; }
std::string CombatPokemon::gettypeequi() { return typeequi; }
std::string CombatPokemon::gettypesauv() { return typesauv; }

void CombatPokemon::setviepkmequi(int i) { viepkmequipe = i; }
void CombatPokemon::setviepkmsauv(int i) { viepkmsauv = i; }
void CombatPokemon::setdgtpkmequi(int i) { dgtfrompkmequi = i; }
void CombatPokemon::setdgtpkmsauv(int i) { dgtfrompkmsauv = i; }
void CombatPokemon::setpkmequifirst(bool b) { IsPkmEquiFirst = b; }
void CombatPokemon::setIsCmbt(bool b) { Iscmbt = b; }
void CombatPokemon::setIsPkmEquiDead(bool b) { IsPkmEquiDead = b; }
void CombatPokemon::setmultpkmequi(float f) { multpkmequi = f; }
void CombatPokemon::setmultpkmsauv(float f) { multpkmsauv = f; }
void CombatPokemon::setdgtattpkmequi(int i) { dgtattpkmequi = i; }
void CombatPokemon::setdgtattpkmsauv(int i) { dgtattpkmsauv = i; }
void CombatPokemon::settypeequi(std::string s) { typeequi = s; }
void CombatPokemon::settypesauv(std::string s) { typesauv = s; }

CombatPokemon::CombatPokemon() { IsPkmEquiDead = false; Iscmbt = true; }

char* pokemonTypeToChar(PokemonType t) {
	if (t == Normal) { return "Normal"; }
	else if (t == Fighting) { return "Fighting"; }
	else if (t == Flying) { return "Flying"; }
	else if (t == Poison) { return "Poison"; }
	else if (t == Ground) { return "Ground"; }
	else if (t == Rock) { return "Rock"; }
	else if (t == Bug) { return "Bug"; }
	else if (t == Ghost) { return "Ghost"; }
	else if (t == Steel) { return "Steel"; }
	else if (t == Fire) { return "Fire"; }
	else if (t == Grass) { return "Grass"; }
	else if (t == Water) { return "Water"; }
	else if (t == Electric) { return "Electric"; }
	else if (t == Psychic) { return "Psychic"; }
	else if (t == Ice) { return "Ice"; }
	else if (t == Dragon) { return "Dragon"; }
	else if (t == Dark) { return "Dark"; }
	else { return "Fairy"; }
}

int hash(const char *str, hashtable* htab) {//fct de hachage opti trouver en cours
	unsigned long hash = 5381;
	int c;
	while (c = *str++)
	{
		hash = ((hash << 5) + hash) + c;/* hash * 33 + c */
	}
	return (hash % htab->m); //modulo m
}

combatespece* get(hashtable* htab, char* nature)
{
	combatespece* tmp = new combatespece;
	int indice = hash(nature, htab);
	tmp = htab->cmbtab[indice];
	if (tmp != nullptr)
	{
		while (tmp->next != nullptr)
		{
			if (strcmp(tmp->nature, nature) == 0)
			{
				return(tmp);
			}
			else
			{
				tmp = tmp->next;
			}
		}
		if (strcmp(tmp->nature, nature) == 0)
		{
			return(tmp);
		}
	}
}

bool contains(hashtable* htab, combatespece* c)
{
	combatespece* element = get(htab, c->nature);
	return (element != nullptr);
}

void insert(combatespece* c, hashtable* htab)
{
	int indice = hash(c->nature, htab);
	if (htab->cmbtab[indice] == nullptr)
	{
		htab->cmbtab[indice] = c;
	}
	else
	{
		c->next = htab->cmbtab[indice];
		htab->cmbtab[indice] = c;
	}

}

hashtable* inithashtable() {

	hashtable* htab = new hashtable;
	htab->keysetSize = 18;

	combatespece* bug = new combatespece;
	bug->nature = "Bug";
	bug->next = nullptr;
	bug->strongagainst[0] = "Dark";
	bug->strongagainst[1] = "Grass";
	bug->strongagainst[2] = "Psychic";
	bug->weakagainst[0] = "Fire";
	bug->weakagainst[1] = "Flying";
	bug->weakagainst[2] = "Rock";
	insert(bug, htab);

	combatespece* dark = new combatespece;
	dark->nature = "Dark";
	dark->next = nullptr;
	dark->strongagainst[0] = "Ghost";
	dark->strongagainst[1] = "Psychic";
	dark->weakagainst[0] = "Bug";
	dark->weakagainst[1] = "Fairy";
	dark->weakagainst[2] = "Fight";
	insert(dark, htab);

	combatespece* dragon = new combatespece;
	dragon->nature = "Dragon";
	dragon->next = nullptr;
	dragon->strongagainst[0] = "Dragon";
	dragon->weakagainst[0] = "Dragon";
	dragon->weakagainst[1] = "Fairy";
	dragon->weakagainst[2] = "Ice";
	insert(dragon, htab);

	combatespece* electric = new combatespece;
	electric->nature = "Electric";
	electric->next = nullptr;
	electric->strongagainst[0] = "Flying";
	electric->strongagainst[1] = "Water";
	electric->weakagainst[0] = "Ground";
	insert(electric, htab);

	combatespece* fairy = new combatespece;
	fairy->nature = "Fairy";
	fairy->next = nullptr;
	fairy->strongagainst[0] = "Dark";
	fairy->strongagainst[1] = "Dragon";
	fairy->strongagainst[2] = "Fight";
	fairy->weakagainst[0] = "Poison";
	fairy->weakagainst[1] = "Steel";
	insert(fairy, htab);

	combatespece* fighting = new combatespece;
	fighting->nature = "Fighting";
	fighting->next = nullptr;
	fighting->strongagainst[0] = "Dark";
	fighting->strongagainst[1] = "Ice";
	fighting->strongagainst[2] = "Normal";
	fighting->strongagainst[3] = "Rock";
	fighting->strongagainst[4] = "Steel";
	fighting->weakagainst[0] = "Fairly";
	fighting->weakagainst[1] = "Flying";
	fighting->weakagainst[2] = "Psychic";
	insert(fighting, htab);

	combatespece* fire = new combatespece;
	fire->nature = "Fire";
	fire->next = nullptr;
	fire->strongagainst[0] = "Bug";
	fire->strongagainst[1] = "Grass";
	fire->strongagainst[2] = "Ice";
	fire->strongagainst[3] = "Steel";
	fire->weakagainst[0] = "Ground";
	fire->weakagainst[1] = "Rock";
	fire->weakagainst[2] = "Water";
	insert(fire, htab);

	combatespece* flying = new combatespece;
	flying->nature = "Flying";
	flying->next = nullptr;
	flying->strongagainst[0] = "Bug";
	flying->strongagainst[1] = "Fight";
	flying->strongagainst[2] = "Grass";
	flying->weakagainst[0] = "Electric";
	flying->weakagainst[1] = "Ice";
	flying->weakagainst[2] = "Rock";
	insert(flying, htab);

	combatespece* ghost = new combatespece;
	ghost->nature = "Ghost";
	ghost->next = nullptr;
	ghost->strongagainst[0] = "Ghost";
	ghost->strongagainst[1] = "Psychic";
	ghost->weakagainst[0] = "Dark";
	ghost->weakagainst[1] = "Ghost";
	insert(ghost, htab);

	combatespece* grass = new combatespece;
	grass->nature = "Grass";
	grass->next = nullptr;
	grass->strongagainst[0] = "Ground";
	grass->strongagainst[1] = "Rock";
	grass->strongagainst[2] = "Water";
	grass->weakagainst[0] = "Bug";
	grass->weakagainst[1] = "Fire";
	grass->weakagainst[2] = "Flying";
	grass->weakagainst[3] = "Ice";
	grass->weakagainst[4] = "Poison";
	insert(grass, htab);

	combatespece* ground = new combatespece;
	ground->nature = "Ground";
	ground->next = nullptr;
	ground->strongagainst[0] = "Electric";
	ground->strongagainst[1] = "Fire";
	ground->strongagainst[2] = "Poison";
	ground->strongagainst[3] = "Rock";
	ground->strongagainst[4] = "Steel";
	ground->weakagainst[0] = "Grass";
	ground->weakagainst[1] = "Ice";
	ground->weakagainst[2] = "Water";
	insert(ground, htab);

	combatespece* ice = new combatespece;
	ice->nature = "Ice";
	ice->next = nullptr;
	ice->strongagainst[0] = "Dragon";
	ice->strongagainst[1] = "Flying";
	ice->strongagainst[2] = "Grass";
	ice->strongagainst[3] = "Ground";
	ice->weakagainst[0] = "Fight";
	ice->weakagainst[1] = "Fire";
	ice->weakagainst[2] = "Rock";
	ice->weakagainst[3] = "Steel";
	insert(ice, htab);

	combatespece* normal = new combatespece;
	normal->nature = "Normal";
	normal->next = nullptr;
	normal->weakagainst[0] = "Fight";
	insert(normal, htab); // correction ici.

	combatespece* poison = new combatespece;
	poison->nature = "Poison";
	poison->next = nullptr;
	poison->strongagainst[0] = "Fairy";
	poison->strongagainst[1] = "Grass";
	poison->weakagainst[0] = "Ground";
	poison->weakagainst[1] = "Psychic";
	insert(poison, htab);

	combatespece* psychic = new combatespece;
	psychic->nature = "Psychic";
	psychic->next = nullptr;
	psychic->strongagainst[0] = "Fight";
	psychic->strongagainst[1] = "Poison";
	psychic->weakagainst[0] = "Bug";
	psychic->weakagainst[1] = "Dark";
	psychic->weakagainst[2] = "Ghost";
	insert(psychic, htab);

	combatespece* rock = new combatespece;
	rock->nature = "Rock";
	rock->next = nullptr;
	rock->strongagainst[0] = "Bug";
	rock->strongagainst[1] = "Fire";
	rock->strongagainst[2] = "Flying";
	rock->strongagainst[3] = "Ice";
	rock->weakagainst[0] = "Fight";
	rock->weakagainst[1] = "Grass";
	rock->weakagainst[2] = "Ground";
	rock->weakagainst[3] = "Steel";
	rock->weakagainst[3] = "Water";
	insert(rock, htab);

	combatespece* steel = new combatespece;
	steel->nature = "Steel";
	steel->next = nullptr;
	steel->strongagainst[0] = "Fairy";
	steel->strongagainst[1] = "Ice";
	steel->strongagainst[2] = "Rock";
	steel->weakagainst[0] = "Fight";
	steel->weakagainst[1] = "Fire";
	steel->weakagainst[2] = "Ground";
	insert(steel, htab);


	combatespece* water = new combatespece;
	water->nature = "Water";
	water->next = nullptr;
	water->strongagainst[0] = "Fire";
	water->strongagainst[1] = "Ground";
	water->strongagainst[2] = "Rock";
	water->weakagainst[0] = "Electric";
	water->weakagainst[1] = "Grass";
	insert(water, htab);

	return htab;

}

void combat(pokemon* p1, pokemon* p2, hashtable* htab, especepokemon bestiaire[], unsigned int dgtatt1, bool* Cmbt, bool* IsP1Dead, Ressource* mesressource, sf::RenderWindow* window, Combatdeco cmbtdeco, EffectAtt* effect, CombatPokemon* cmbtpkm)
{
	int i = 0;
	int indiceP1 = chercher(p1->getnom(), bestiaire);
	int indiceP2 = chercher(p2->getnom(), bestiaire);
	char* type1 = pokemonTypeToChar(bestiaire[indiceP1].type);
	char* type2 = pokemonTypeToChar(bestiaire[indiceP2].type);
	combatespece* cmbesp1 = get(htab, type1);
	combatespece* cmbesp2 = get(htab, type2);
	int attrand = (random_at_most(1000) % 4);

	if ((p1->getactPV() > 0) && (p2->getactPV() > 0))// verifie que les pokemon soit en etat de se battre
	{
		cmbtpkm->setmultpkmequi(1);
		cmbtpkm->setmultpkmsauv(1);
		cmbtpkm->setdgtattpkmequi(dgtatt1);
		cmbtpkm->settypeequi(type1);
		cmbtpkm->settypesauv(type2);

		if (attrand == 0) {cmbtpkm->setdgtattpkmsauv(60); }
		else if (attrand == 1) {cmbtpkm->setdgtattpkmsauv(80); }
		else if (attrand == 2) {cmbtpkm->setdgtattpkmsauv(100); }
		else {cmbtpkm->setdgtattpkmsauv(120); }//selection alea attaque du pkmsauv

		if (cmbesp1 != nullptr)
		{
			while ((cmbesp1->strongagainst[i] != nullptr) && (i<5))
			{
				if (cmbesp1->strongagainst[i] == type2){cmbtpkm->setmultpkmequi(1.5);}
				i++;
			}

			i = 0;

			while ((cmbesp1->weakagainst[i] != nullptr) && (i<5))
			{
				if (cmbesp1->weakagainst[i] == type2){cmbtpkm->setmultpkmequi(0.5);}
				i++;
			}

		}

		if (cmbesp2 != nullptr)
		{
			while ((cmbesp2->strongagainst[i] != nullptr) && (i<5))
			{
				if (cmbesp2->strongagainst[i] == type1){cmbtpkm->setmultpkmsauv(1.5);}
				i++;
			}

			i = 0;

			while ((cmbesp2->weakagainst[i] != nullptr) && (i<5))
			{
				if (cmbesp2->weakagainst[i] == type1){cmbtpkm->setmultpkmsauv(0.5);}
				i++;
			}

		}

		cmbtpkm->setdgtpkmequi((p1->getpuissance() + dgtatt1)*cmbtpkm->getmultpkmequi());
		cmbtpkm->setdgtpkmsauv((p2->getpuissance() + cmbtpkm->getdgtattpkmsauv())*cmbtpkm->getmultpkmsauv());

		if ((random_at_most(1000) % 2) == 0) 
		{ 
			cmbtpkm->setpkmequifirst(true); 
			p2->setactPV(p2->getactPV() - cmbtpkm->getdgtpkmequi());
			if (p2->getactPV() > 0)//si p2 n'est pas mort
			{
				p1->setactPV(p1->getactPV() - cmbtpkm->getdgtpkmsauv());
			}
		}
		else 
		{ 
			cmbtpkm->setpkmequifirst(false);
			p1->setactPV(p1->getactPV() - cmbtpkm->getdgtpkmsauv());
			if (p1->getactPV() > 0)//si p2 n'est pas mort
			{
				p2->setactPV(p2->getactPV() - cmbtpkm->getdgtpkmequi());
			}
		}
		if (p2->getactPV() <= 0) { cmbtpkm->setIsCmbt(false); p1->setXP(p1->getXP() + 100); mesressource->settune(mesressource->gettune() + 100); ispowerup(p1, bestiaire); } // P2 est mort combat est terminer
		else if (p1->getactPV() <= 0) { cmbtpkm->setIsPkmEquiDead(true); } // P1 est mort il faut le changer
		else { cmbtpkm->setIsCmbt(true); }
	}
	else
	{
		(*Cmbt) = false; // ici on ne lance pas de combat donc on stoppe directement le combat
		std::cout << "veulliez soigner vos pokemon barbare !!" << std::endl;
	}
}

void combatsav(pokemon* p1, pokemon* p2, hashtable* htab, especepokemon bestiaire[], bool* Cmbt, bool* IsP1Dead, CombatPokemon* cmbtpkm) 
{
	int i = 0;
	float mult_degat2 = 1;
	int indiceP1 = chercher(p1->getnom(), bestiaire);
	int indiceP2 = chercher(p2->getnom(), bestiaire);
	char* type1 = pokemonTypeToChar(bestiaire[indiceP1].type);
	char* type2 = pokemonTypeToChar(bestiaire[indiceP2].type);
	combatespece* cmbesp2 = get(htab, type2);
	int attrand = (random_at_most(1000) % 4);

	if ((p1->getactPV() > 0) && (p2->getactPV() > 0))// verifie que les pokemon soit en etat de se battre
	{
		cmbtpkm->setmultpkmequi(1);
		cmbtpkm->setmultpkmsauv(1);
		cmbtpkm->setdgtattpkmequi(0);
		cmbtpkm->settypeequi(type1);
		cmbtpkm->settypesauv(type2);
		cmbtpkm->setdgtpkmequi(0);
		cmbtpkm->setpkmequifirst(true);

		if (attrand == 0) { cmbtpkm->setdgtattpkmsauv(60); }
		else if (attrand == 1) { cmbtpkm->setdgtattpkmsauv(80); }
		else if (attrand == 2) { cmbtpkm->setdgtattpkmsauv(100); }
		else { cmbtpkm->setdgtattpkmsauv(120); }//selection alea attaque du pkmsauv

		if (cmbesp2 != nullptr)
		{
			while ((cmbesp2->strongagainst[i] != nullptr) && (i<5))
			{
				if (cmbesp2->strongagainst[i] == type1)
				{
					mult_degat2 = 1.5; cmbtpkm->setmultpkmsauv(1.5);
				}
				i++;
			}

			i = 0;

			while ((cmbesp2->weakagainst[i] != nullptr) && (i<5))
			{
				if (cmbesp2->weakagainst[i] == type1)
				{
					mult_degat2 = 0.5; cmbtpkm->setmultpkmsauv(0.5);
				}
				i++;
			}
		}
		cmbtpkm->setdgtpkmsauv((p2->getpuissance() + cmbtpkm->getdgtattpkmsauv())*mult_degat2);
		p1->setactPV(p1->getactPV() - cmbtpkm->getdgtpkmsauv());
	
		if (p1->getactPV() <= 0) { cmbtpkm->setIsPkmEquiDead(true); } // P1 est mort il faut le changer
		else {}
	}
	else
	{
		(*Cmbt) = false;
		std::cout << "veulliez soigner vos pokemon barbare !!" << std::endl;
	}
}

void ispowerup(pokemon* p1, especepokemon bestiaire[])
{
	if (p1->getXP() >= p1->getniveau()*100)
	{
		powerup(p1, bestiaire);
	}
}

std::string floattostring(float reel)
{
	std::ostringstream oss;
	oss << std::setw(3) << std::setfill('0') << (int)reel;
	return oss.str();
}

std::string majspriteatt(EffectAtt* effect, std::string type, unsigned int dgtatt, char sens)
{
	effect->Sattaque.setRotation(0.f); // put the rotation to 0
	effect->Sattaque.setScale(1.f, 1.f); //put the scale to the normal
	effect->Sattaque.setOrigin(0.f, 0.f); //put the origine to top left and corner
	effect->Sattaque.setColor(sf::Color::White); //put the color by default

	effect->Sattaque1.setRotation(0.f); // put the rotation to 0
	effect->Sattaque1.setScale(1.f, 1.f); //put the scale to the normal
	effect->Sattaque1.setOrigin(0.f, 0.f); //put the origine to top left and corner
	effect->Sattaque1.setColor(sf::Color::White); //put the color by default

	effect->Sattaque2.setRotation(0.f); // put the rotation to 0
	effect->Sattaque2.setScale(1.f, 1.f); //put the scale to the normal
	effect->Sattaque2.setOrigin(0.f, 0.f); //put the origine to top left and corner
	effect->Sattaque2.setColor(sf::Color::White); //put the color by default

	effect->Sattaquefond.setRotation(0.f); // put the rotation to 0
	effect->Sattaquefond.setScale(1.f, 1.f); //put the scale to the normal
	effect->Sattaquefond.setOrigin(0.f, 0.f); //put the origine to top left and corner
	effect->Sattaquefond.setColor(sf::Color::White); //put the color by default

	switch (dgtatt)
	{
	case 60:
		effect->Sattaque.setTexture(effect->Tcharge, true);
		effect->Sattaque.setOrigin(75, 75);
		if (sens == 'B')
		{ 
			effect->Sattaque.setPosition(575, 120);
			return "chargeB"; 
		} //pkm equipe position basse attaquant
		else 
		{ 
			effect->Sattaque.setPosition(175, 320);
			return "chargeF"; 
		}
		break;
	case 80:
		if (type == "Normal") 
		{ 
			effect->Sattaque.setTexture(effect->Trush);
			effect->Sattaque.setOrigin(75, 75);
			if (sens == 'B')
			{
				effect->Sattaque.setPosition(575, 120);
				return "rushB";
			}
			else 
			{
				effect->Sattaque.setPosition(175, 320);
				return"rushF";
			}
		}
		else if (type == "Fighting") 
		{ 
			if(sens == 'B')
			{
				effect->Sattaque.setTexture(effect->Tpoing, true);
				effect->Sattaque.setPosition(210.f, 50.f);
				effect->Sattaque1.setTexture(effect->Tpoing, true);
				effect->Sattaque1.setPosition(800.f, 50.f);
			}
			else
			{
				effect->Sattaque.setTexture(effect->Tpoing, true);
				effect->Sattaque.setPosition(-190.f, 250.f);
				effect->Sattaque1.setTexture(effect->Tpoing, true);
				effect->Sattaque1.setPosition(410.f, 250.f);
			}
			return "Catch";
		}
		else if (type == "Flying") { return " "; }
		else if (type == "Poison") { return " "; }
		else if (type == "Ground") { return " "; }
		else if (type == "Rock") { return " "; }
		else if (type == "Bug") { return " "; }
		else if (type == "Ghost") { return " "; }
		else if (type == "Steel") { return " "; }
		else if (type == "Fire") 
		{ 
			effect->Sattaque.setTexture(effect->Tfeu_ball, true); 
			if (sens == 'B') //pkm equipe position basse attaquant
			{
				effect->Sattaque.setPosition(160.f,220.f);
				effect->Sattaque.setOrigin(effect->Sattaque.getOrigin().x + 200, effect->Sattaque.getOrigin().y + 160); //the rotation move around the origin so it is place in the bottom right and corner to turn into the top left and corner (the origin) and thus place correctly the img
				effect->Sattaque.rotate(180.f); //base image is oriented pkm sauv to pkm equipe we need to turn it in the other direction
				return "feuballB";
			}
			else { effect->Sattaque.setPosition(360.f, 80.f); return "feuballF"; } //pkm sauv position haute
			
		} 
		else if (type == "Grass"){ return " "; }
		else if (type == "Water"){ return " "; }
		else if (type == "Electric"){ return " "; }
		else if (type == "Psychic"){ return " "; }
		else if (type == "Ice"){ return " "; }
		else if (type == "Dragon"){ return  " "; }
		else if (type == "Dark"){ return " "; }
		else { return " "; }//fairy
		break;
	case 100:
		if (type == "Normal") 
		{ 
			if (sens == 'B'){return "ecrasemenB";}
			else{return "ecrasemenF";} 
		}//scale pkm
		else if (type == "Fighting") 
		{ 
			effect->Sattaque.setTexture(effect->Tpoing);
			effect->Sattaque1.setTexture(effect->Tpoing);
			effect->Sattaque2.setTexture(effect->Tpoing);
			if (sens=='B')
			{
				effect->Sattaque.setPosition(360.f, 0.f);
				effect->Sattaque1.setPosition(510.f, 50.f);
				effect->Sattaque2.setPosition(660.f, 100.f);
			}
			else 
			{
				effect->Sattaque.setPosition(110.f, 225.f);
				effect->Sattaque1.setPosition(260.f, 300.f);
				effect->Sattaque2.setPosition(10.f, 225.f);
			}
			return "Furie"; 
		}
		else if (type == "Flying") { return " "; }
		else if (type == "Poison") { return " "; }
		else if (type == "Ground") { return " "; }
		else if (type == "Rock") { return " "; }
		else if (type == "Bug") { return " " ; }
		else if (type == "Ghost") { return " "; }
		else if (type == "Steel") { return " "; }
		else if (type == "Fire") 
		{ 
			effect->Sattaque.setTexture(effect->Tfeu_burn_2, true); 
			if (sens == 'B') //pkm equipe position basse
			{effect->Sattaque.setPosition(490.f, 0.f);}
			else { effect->Sattaque.setPosition(80.f, 190.f); } //pkm sauv position haute
			return "feuburn";
		}
		else if (type == "Grass") { return " "; }
		else if (type == "Water") { return " "; }
		else if (type == "Electric") { return " "; }
		else if (type == "Psychic") { return " "; }
		else if (type == "Ice") { return " "; }
		else if (type == "Dragon") { return " "; }
		else if (type == "Dark") { return " "; }
		else { return " "; }//fairy
		break;
	case 120:
		if (type == "Normal") 
		{
			effect->Sattaque.setTexture(effect->Tcombo_1, true);
			effect->Sattaque.setOrigin(75, 75);
			if(sens=='B'){ 
				
				effect->Sattaque.setPosition(575, 120);
				return "comboB";
			}
			else{ 
				effect->Sattaque.setPosition(175, 320);
				return "comboF"; 
			}
		}
		else if (type == "Fighting") 
		{ 
			effect->Sattaquefond.setTexture(effect->Tfond_closecombat, true);
			effect->Sattaquefond.setPosition(0, 0);
			effect->Sattaquefond.setScale(4, 1);
			if(sens == 'B')
			{
				effect->Sattaque1.setTexture(effect->Tpoing, true);
				effect->Sattaque1.setOrigin(effect->Sattaque1.getOrigin().x + 75, effect->Sattaque1.getOrigin().y + 75); // origine is in the center
				effect->Sattaque1.setPosition(510.f + 75.f, 60.f + 75.f);

				effect->Sattaque2.setOrigin(effect->Sattaque2.getOrigin().x + 75/2 , effect->Sattaque2.getOrigin().y + 75/2 );
				effect->Sattaque2.setPosition(510.f + 70.f , 60.f + 70.f );
				effect->Sattaque2.setScale(5.f, 5.f);
			}
			else
			{
				effect->Sattaque1.setTexture(effect->Tpoing, true);
				effect->Sattaque1.setOrigin(effect->Sattaque1.getOrigin().x + 75, effect->Sattaque1.getOrigin().y + 75); // origine is in the center
				effect->Sattaque1.setPosition(110.f + 75.f, 250.f + 75.f);

				effect->Sattaque2.setOrigin(effect->Sattaque2.getOrigin().x + 75 / 2, effect->Sattaque2.getOrigin().y + 75 / 2);
				effect->Sattaque2.setPosition(110.f + 70.f, 250.f + 70.f);
				effect->Sattaque2.setScale(5.f, 5.f);
			}
			return "OnePunch";
			 
		}
		else if (type == "Flying") { return " "; }
		else if (type == "Poison") { return " "; }
		else if (type == "Ground") { return  " "; }
		else if (type == "Rock") { return " "; }
		else if (type == "Bug") { return " "; }
		else if (type == "Ghost") { return " "; }
		else if (type == "Steel") { return " "; }
		else if (type == "Fire") 
		{ 
			effect->Sattaque.setTexture(effect->Tfeu_explode, true);
			effect->Sattaque.setOrigin(effect->Sattaque.getOrigin().x + 110, effect->Sattaque.getOrigin().y + 110); // origine is in the center
			if (sens == 'B') //pkm equipe position basse
			{
				effect->Sattaque.setPosition(600.f, 110.f);
			}
			else { effect->Sattaque.setPosition(190.f, 300.f); } //pkm sauv position haute
			//effect->Sattaque.setScale(0.5, 0.5);
			return "feuexplode";
		}
		else if (type == "Grass") { return " "; }
		else if (type == "Water") { return " "; }
		else if (type == "Electric") { return " "; }
		else if (type == "Psychic") { return " "; }
		else if (type == "Ice") { return " "; }
		else if (type == "Dragon") { return " "; }
		else if (type == "Dark") { return " "; }
		else { return " "; }//fairy
		break;
	default:
		return " ";
		break;
	}
}

void animeatt(sf::RenderWindow* window, EffectAtt* effect, std::string attstr, sf::Sprite fond)
{
	int tempo = 100;
	sf::Sprite Satt;

	if (attstr == "chargeB") 
	{
		for (int i = 0; i < 20; i++)
		{
			if(i<10){ effect->Sattaque.setScale(0.1*i, 0.1*i); }
			if(i==10){ effect->Sattaque.setScale(0.1,0.1); }                   //double animation
			if (i > 10) { effect->Sattaque.setScale(0.1*(i-10), 0.1*(i-10)); }
			window->clear();
			window->draw(fond);
			window->draw(effect->Sattaque);
			window->display();
			std::this_thread::sleep_for(std::chrono::milliseconds(tempo));
		}
		window->clear();
		window->draw(fond); //on n'affiche que le fond sans l'attaque pour ne pas la superposer a celle du pkm sauvage
		window->display();
	}
	else if (attstr == "chargeF") 
	{ 
		for (int i = 0; i < 20; i++)
		{
			if (i<10) { effect->Sattaque.setScale(0.1*i, 0.1*i); }
			if (i == 10) { effect->Sattaque.setScale(0.1, 0.1); }                   //double animation
			if (i > 10) { effect->Sattaque.setScale(0.1*(i - 10), 0.1*(i - 10)); }
			window->clear();
			window->draw(fond);
			window->draw(effect->Sattaque);
			window->display();
			std::this_thread::sleep_for(std::chrono::milliseconds(tempo));
		}
		window->clear();
		window->draw(fond); //on n'affiche que le fond sans l'attaque pour ne pas la superposer a celle du pkm sauvage
		window->display();
	}
	else if (attstr == "rushB")
	{
		for (int i = 0; i < 20; i++)
		{
			window->clear();
			window->draw(fond);
			if (i % 2 == 0) { window->draw(effect->Sattaque); }
			window->display();
			std::this_thread::sleep_for(std::chrono::milliseconds(tempo));
		}
		window->clear();
		window->draw(fond); //on n'affiche que le fond sans l'attaque pour ne pas la superposer a celle du pkm sauvage
		window->display();
	}
	else if (attstr == "rushF")
	{
		for (int i = 0; i < 20; i++)
		{
			window->clear();
			window->draw(fond);
			if (i % 2 == 0) { window->draw(effect->Sattaque); }
			window->display();
			std::this_thread::sleep_for(std::chrono::milliseconds(tempo));
		}
		window->clear();
		window->draw(fond); //on n'affiche que le fond sans l'attaque pour ne pas la superposer a celle du pkm sauvage
		window->display();
	}
	else if (attstr == "comboB")
	{
		for (int i = 0; i < 20; i++)
		{
			if (i % 2 == 0) { effect->Sattaque.setTexture(effect->Tcombo_1);}
			else{ effect->Sattaque.setTexture(effect->Tcombo_2);}
			switch (i)
			{
			case 2:
				effect->Sattaque.move(75,0);
				effect->Sattaque.setScale(1, 1);
				break;
			case 4 :
				effect->Sattaque.move(-150,0);
				effect->Sattaque.setScale(1.25, 1.25);
				break;
			case 6:
				effect->Sattaque.move(75,-75);
				effect->Sattaque.setScale(1.5, 1.5);
				break;
			case 8:
				effect->Sattaque.move(0,150);
				effect->Sattaque.setScale(1.75, 1.75);
				break;
			case 10 :
				effect->Sattaque.move(0, -75);
				effect->Sattaque.setScale(2, 2);
				effect->Sattaque.setColor(sf::Color::Color(255, 0, 0, 255));
				break;
			default:
				break;
			}
			window->clear();
			window->draw(fond);
			window->draw(effect->Sattaque);
			window->display();
			std::this_thread::sleep_for(std::chrono::milliseconds(tempo));
		}
		window->clear();
		window->draw(fond); //on n'affiche que le fond sans l'attaque pour ne pas la superposer a celle du pkm sauvage
		window->display();
	}
	else if (attstr == "comboF")
	{
		for (int i = 0; i < 20; i++)
		{
			window->clear();
			window->draw(fond);
			if (i % 2 == 0) { window->draw(effect->Sattaque); }
			window->display();
			std::this_thread::sleep_for(std::chrono::milliseconds(tempo));
		}
		window->clear();
		window->draw(fond); //on n'affiche que le fond sans l'attaque pour ne pas la superposer a celle du pkm sauvage
		window->display();
	}
	else if (attstr == "feuballB") {
		for (int i = 0; i < 20; i++)
		{
			//effect->RTeffect.clear();
			//effect->RTeffect.draw(effect->Sattaque);
			//effect->RTeffect.display();
			//Satt.setTexture(effect->RTeffect.getTexture());

			window->clear();
			window->draw(fond);
			window->draw(effect->Sattaque);
			//window->draw(Satt);
			window->display();
			
			std::this_thread::sleep_for(std::chrono::milliseconds(tempo));
			effect->Sattaque.move(10.f, -7.f);
			//Satt.move(10.f,-7.f);
		}
		window->clear();
		window->draw(fond); //on n'affiche que le fond sans l'attaque pour ne pas la superposer a celle du pkm sauvage
		window->display();
	}
	else if (attstr == "feuballF") {
		for (int i = 0; i < 20; i++)
		{
			//effect->RTeffect.clear();
			//effect->RTeffect.draw(effect->Sattaque);
			//effect->RTeffect.display();
			//Satt.setTexture(effect->RTeffect.getTexture());
			//Satt.move(-10.f, +7.f);

			window->clear();
			window->draw(fond);
			//window->draw(Satt);
			window->draw(effect->Sattaque);
			window->display();
			std::this_thread::sleep_for(std::chrono::milliseconds(tempo));
			effect->Sattaque.move(-10.f, 7.f);
			window->clear();
			window->draw(fond); //on n'affiche que le fond sans l'attaque pour ne pas la superposer a celle du pkm equipe
			window->display();
		}
	}
	else if (attstr == "feuburn") 
	{
		for (int i = 0; i < 20; i++)
		{
			window->clear();
			window->draw(fond);
			window->draw(effect->Sattaque);
			window->display();
			std::this_thread::sleep_for(std::chrono::milliseconds(tempo));
			if(i%2 == 1){ effect->Sattaque.setTexture(effect->Tfeu_burn_2); }
			else{ effect->Sattaque.setTexture(effect->Tfeu_burn_1); }
		}
		window->clear();
		window->draw(fond); //on n'affiche que le fond sans l'attaque pour ne pas la superposer a celle du pkm sauvage
		window->display();
	}
	else if (attstr == "feuexplode")
	{
		for (int i = 0; i < 20; i++)
		{
			//if(i<10){ effect->Sattaque.setScale(0.1*i, 0.1*i); }
			//if(i==10){ effect->Sattaque.setScale(0.1,0.1); }                   double explosion
			//if (i > 10) { effect->Sattaque.setScale(0.1*(i-10), 0.1*(i-10)); }
			effect->Sattaque.setScale(0.5*i, 0.5*i);
			window->clear();
			window->draw(fond);
			window->draw(effect->Sattaque);
			window->display();
			std::this_thread::sleep_for(std::chrono::milliseconds(tempo));
		}
		window->clear();
		window->draw(fond); //on n'affiche que le fond sans l'attaque pour ne pas la superposer a celle du pkm sauvage
		window->display();
	}
	else { std::this_thread::sleep_for(std::chrono::milliseconds(tempo*20)); }
}