#include"pokemon.h"
#include"pokemonTypes.h"
#include"util.h"
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<thread>
#include<chrono>
#include<limits>
#include<string>
#include<iomanip>
#include<string.h>

pokemon::pokemon(std::string name) {
	int type = (rand() % 3 + 1);
	switch (type)
	{
	case 1:
		genre = male;
		break;

	case 2:
		genre = femmelle;
		break;

	case 3:
		genre = neutre;
		break;

	default:
		genre = neutre;
		break;
	}

	nom = name;
	attaque1 = "charge";
	attaque2 = "...";
	attaque3 = "...";
	attaque4 = "...";
	XP = 0;
	niveau = 0;
	stade_evolution = 0;
	PV = random_at_most(500 - 200) + 200; //pv entre 200 et 500
	actPV = PV;
	puissance = random_at_most(100 - 20) + 20; // degat entre 20 et 100 (+ degat attaque)
	Dgt1 = 10;
	Dgt2 = 0;
	Dgt3 = 0;
	Dgt4 = 0;
	
	SpokeB.setPosition(30.f, 233.f);
	SpokeF.setPosition(465.f, 14.f);
}

pokemon::pokemon()
{
}

std::string pokemon::getnom() {return nom;}
std::string pokemon::getatt1(void) {return attaque1;}
std::string pokemon::getatt2(void) {return attaque2;}
std::string pokemon::getatt3(void) {return attaque3;}
std::string pokemon::getatt4(void){return attaque4;}
unsigned int pokemon::getXP(void) { return XP; }
unsigned int pokemon::getniveau(void) { return niveau; }
unsigned int pokemon::getstade(void) { return stade_evolution; }
unsigned int pokemon::getPV(void) { return PV; }
unsigned int pokemon::getdgt1(void) { return Dgt1; }
unsigned int pokemon::getdgt2(void) { return Dgt2; }
unsigned int pokemon::getdgt3(void) { return Dgt3; }
unsigned int pokemon::getdgt4(void) { return Dgt4; }
unsigned int pokemon::getpuissance(void) { return puissance; }
int pokemon::getactPV(void) { return actPV; }
pokemon_genre pokemon::getgenre(void) { return genre; }

void pokemon::setnom(std::string name) { nom = name; }
void pokemon::setatt1(std::string att1) { attaque1 = att1; }
void pokemon::setatt2(std::string att2) { attaque2 = att2; }
void pokemon::setatt3(std::string att3) { attaque3 = att3; }
void pokemon::setatt4(std::string att4) { attaque4 = att4; }
void pokemon::setXP(unsigned int exp) { XP = exp; }
void pokemon::setniveau(unsigned int niv) { niveau = niv; }
void pokemon::setstade(unsigned int stade) { stade_evolution = stade; }
void pokemon::setPV(unsigned int vie) { PV = vie; }
void pokemon::setdgt1(unsigned int degat1) { Dgt1 = degat1; }
void pokemon::setdgt2(unsigned int degat2) { Dgt2 = degat2; }
void pokemon::setdgt3(unsigned int degat3) { Dgt3 = degat3; }
void pokemon::setdgt4(unsigned int degat4) { Dgt4 = degat4; }
void pokemon::setpuissance(unsigned int puis) { puissance = puis; }
void pokemon::setactPV(int vieact) { actPV = vieact; }
void pokemon::setgenre(pokemon_genre genre1) { genre = genre1; }

void pokemon::majsprite(std::string cheminB, std::string cheminF)
{
	TpokeB.loadFromFile(cheminB);
	SpokeB.setTexture(TpokeB);
	SpokeB.setPosition(30.f, 233.f);

	TpokeF.loadFromFile(cheminF);
	SpokeF.setTexture(TpokeF);
	SpokeF.setPosition(465.f, 14.f);
}

void evolve(pokemon* p, especepokemon bestiaire[])
{
	int i = chercher(p->getnom(), bestiaire);
	if (bestiaire[i].evolvesTo != NULL)
	{
		std::cout << "Quoi"; std::this_thread::sleep_for(std::chrono::milliseconds(500)); for (int j = 0; j < 3; j++) { std::cout << " . "; std::this_thread::sleep_for(std::chrono::milliseconds(330)); } std::cout << p->getnom() << " evolue en ";
		p->setnom(bestiaire[i].evolvesTo);
		p->setstade( p->getstade() + 1);
		std::cout << p->getnom() << " !!! " << std::endl;
	
		p->setPV(p->getPV() + 120); //buff PV
	}
	else { std::cout << "Ce pokemon n'evolue pas" << std::endl; }
}

void powerup(pokemon* p, especepokemon bestiaire[])
{
	int i = chercher(p->getnom(), bestiaire);

	if (p->getniveau() < 20) //si on est inf au lvl max
	{
		p->setniveau(p->getniveau() + 1);
		p->setXP(0);
		p->setpuissance(p->getpuissance() + p->getniveau()); // gain de 200 environ au total
		p->setPV(p->getPV() + p->getniveau() * 2); //gain de 400 environ au total

		if (p->getniveau() == 5) // si on attein le lvl 5 on gagne l'attaque 2 
		{
			unlockatt2(p, bestiaire[i].type);
		}
		if (p->getniveau() == 10) // si on attein le lvl 10 on evolue le pkm et debloque att3
		{
			evolve(p, bestiaire);
			unlockatt3(p, bestiaire[i].type);
		}
		if (p->getniveau() == 15) // si on attein le lvl 15 on evolue le pkm et on lui donne la 4 ieme attaque
		{
			evolve(p, bestiaire);
			unlockatt4(p, bestiaire[i].type);
		}
	}
}


int chercher(std::string pnom, especepokemon bestiaire[])
{
	int i = 0;
	while ((pnom != bestiaire[i].nom) && (i<150))
	{
		i++;
	}
	return i;
}

void unlockatt2(pokemon* p, PokemonType type)
{
	switch (type) //determine l'attaque n3 du pokemon
	{
	case Normal:
		p->setatt2("Rush");
		p->setdgt2(80); //degat d'attaque aug de 20 par numero et partent de 60
		break;
	case Fighting:
		p->setatt2("Catch");
		p->setdgt2(80);
		break;
	case Flying:
		p->setatt2("Pique");
		p->setdgt2(80);
		break;
	case Poison:
		p->setatt2("Arsenic");
		p->setdgt2(80);
		break;
	case Ground:
		p->setatt2("Eboulement");
		p->setdgt2(80);
		break;
	case Rock:
		p->setatt2("Grava");
		p->setdgt2(80);
		break;
	case Bug:
		p->setatt2("Piqure");
		p->setdgt2(80);
		break;
	case Ghost:
		p->setatt2("Hante");
		p->setdgt2(80);
		break;
	case Steel:
		p->setatt2("Tranchant");
		p->setdgt2(80);
		break;
	case Fire:
		p->setatt2("Fireball");
		p->setdgt2(80);
		break;
	case Grass:
		p->setatt2("Join");
		p->setdgt2(80);
		break;
	case Water:
		p->setatt2("Bulle");
		p->setdgt2(80);
		break;
	case Electric:
		p->setatt2("Decharge");
		p->setdgt2(80);
		break;
	case Psychic:
		p->setatt2("Hmm->->->");
		p->setdgt2(80);
		break;
	case Ice:
		p->setatt2("Eclat");
		p->setdgt2(80);
		break;
	case Dragon:
		p->setatt2("Souffle");
		p->setdgt2(80);
		break;
	case Dark:
		p->setatt2("Crepuscule");
		p->setdgt2(80);
		break;
	case Fairy:
		p->setatt2("Dust");
		p->setdgt2(80);
		break;
	default:
		break;
	}
}

void unlockatt3(pokemon* p, PokemonType type)
{
	switch (type) //determine l'attaque n3 du pokemon
	{
	case Normal:
		p->setatt3("Ecrasement");
		p->setdgt3(100); //degat d'attaque aug de 20 par numero et partent de 60
		break;
	case Fighting:
		p->setatt3("Furie");
		p->setdgt3(100);
		break;
	case Flying:
		p->setatt3("vol");
		p->setdgt3(100);
		break;
	case Poison:
		p->setatt3("soude");
		p->setdgt3(100);
		break;
	case Ground:
		p->setatt3("avalanche");
		p->setdgt3(100);
		break;
	case Rock:
		p->setatt3("pieux");
		p->setdgt3(100);
		break;
	case Bug:
		p->setatt3("envahissement");
		p->setdgt3(100);
		break;
	case Ghost:
		p->setatt3("possession");
		p->setdgt3(100);
		break;
	case Steel:
		p->setatt3("guillotine");
		p->setdgt3(100);
		break;
	case Fire:
		p->setatt3("Flamboiment");
		p->setdgt3(100);
		break;
	case Grass:
		p->setatt3("weed");
		p->setdgt3(100);
		break;
	case Water:
		p->setatt3("inondation");
		p->setdgt3(100);
		break;
	case Electric:
		p->setatt3("tonnerre");
		p->setdgt3(100);
		break;
	case Psychic:
		p->setatt3("telephatie");
		p->setdgt3(100);
		break;
	case Ice:
		p->setatt3("carcan");
		p->setdgt3(100);
		break;
	case Dragon:
		p->setatt3("cros");
		p->setdgt3(100);
		break;
	case Dark:
		p->setatt3("tenebre");
		p->setdgt3(100);
		break;
	case Fairy:
		p->setatt3("sort");
		p->setdgt3(100);
		break;
	default:
		break;
	}
}

void unlockatt4(pokemon* p, PokemonType type)
{
	switch (type) //determine l'attaque n3 du pokemon
	{
	case Normal:
		p->setatt4("Combo");
		p->setdgt4(120); //degat d'attaque aug de 20 par numero et partent de 60
		break;
	case Fighting:
		p->setatt4("OnePunch");
		p->setdgt4(120);
		break;
	case Flying:
		p->setatt4("Rapace");
		p->setdgt4(120);
		break;
	case Poison:
		p->setatt4("Septicemie");
		p->setdgt4(120);
		break;
	case Ground:
		p->setatt4("Effondrement");
		p->setdgt4(120);
		break;
	case Rock:
		p->setatt4("Meteor");
		p->setdgt4(120);
		break;
	case Bug:
		p->setatt4("Lethargie");
		p->setdgt4(120);
		break;
	case Ghost:
		p->setatt4("Destruction");
		p->setdgt4(120);
		break;
	case Steel:
		p->setatt4("Decapitaion");
		p->setdgt4(120);
		break;
	case Fire:
		p->setatt4("Enfer");
		p->setdgt4(120);
		break;
	case Grass:
		p->setatt4("7e ciel");
		p->setdgt4(120);
		break;
	case Water:
		p->setatt4("Tsunamie");
		p->setdgt4(120);
		break;
	case Electric:
		p->setatt4("FatalFoudre");
		p->setdgt4(120);
		break;
	case Psychic:
		p->setatt4("Telefrag");
		p->setdgt4(120);
		break;
	case Ice:
		p->setatt4("Blizzar");
		p->setdgt4(120);
		break;
	case Dragon:
		p->setatt4("Cendre");
		p->setdgt4(120);
		break;
	case Dark:
		p->setatt4("Anihilation");
		p->setdgt4(120);
		break;
	case Fairy:
		p->setatt4("Transposition");
		p->setdgt4(120);
		break;
	default:
		break;
	}
}