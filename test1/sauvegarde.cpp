#include "sauvegarde.h"
#include <SFML/Graphics.hpp>
#include<string>
#include<iomanip>
#include<string.h>
#include<iostream>
#include <fstream>
#include<stdlib.h>
#include <stdio.h>
#include "pokedex.h"

void sauvegarder(std::string chemin, sf::Vector2i position, sf::Vector2i posmapbefore, int IDmap, Pokedex* stocage, Pokedex* equipe, Ressource* mesressource)
{
	unsigned int codehash = 0;
	unsigned int codetmp = 0;
	unsigned int codeequi = 0;
	unsigned int codesto = 0;

	std::ofstream wrsave1(chemin.c_str(), std::ios::out | std::ios::trunc);  //déclaration du flux et ouverture du fichier on l'efface si il n'est pas vide (trunc)

	if (wrsave1)  // si l'ouverture a réussi
	{
		wrsave1 << position.x << std::endl;
		wrsave1 << position.y << std::endl;
		wrsave1 << posmapbefore.x << std::endl;
		wrsave1 << posmapbefore.y << std::endl;
		wrsave1 << IDmap << std::endl;
		wrsave1 << (*stocage).getnbpokemon() << std::endl;
		for (int i = 0; i < (*stocage).getnbpokemon(); i++) 
		{
			wrsave1 << (*stocage).getpokemon(i).getnom() << std::endl;
			wrsave1 << (*stocage).getpokemon(i).getactPV() << std::endl;;
			wrsave1 << (*stocage).getpokemon(i).getatt1() << std::endl;
			wrsave1 << (*stocage).getpokemon(i).getatt2() << std::endl;
			wrsave1 << (*stocage).getpokemon(i).getatt3() << std::endl;
			wrsave1 << (*stocage).getpokemon(i).getatt4() << std::endl;
			wrsave1 << (*stocage).getpokemon(i).getdgt1() << std::endl;
			wrsave1 << (*stocage).getpokemon(i).getdgt2() << std::endl;
			wrsave1 << (*stocage).getpokemon(i).getdgt3() << std::endl;
			wrsave1 << (*stocage).getpokemon(i).getdgt4() << std::endl;
			wrsave1 << (*stocage).getpokemon(i).getgenre() << std::endl;
			wrsave1 << (*stocage).getpokemon(i).getniveau() << std::endl;
			wrsave1 << (*stocage).getpokemon(i).getpuissance() << std::endl;
			wrsave1 << (*stocage).getpokemon(i).getPV() << std::endl;
			wrsave1 << (*stocage).getpokemon(i).getstade() << std::endl;
			wrsave1 << (*stocage).getpokemon(i).getXP() << std::endl;

			codesto += stocage->getpokemon(i).getactPV() + 60 + 80 + 100 + 120 + (*stocage).getpokemon(i).getniveau() + (*stocage).getpokemon(i).getpuissance() + (*stocage).getpokemon(i).getPV() + (*stocage).getpokemon(i).getstade() + (*stocage).getpokemon(i).getXP() + hasch((*stocage).getpokemon(i).getnom()) + (*stocage).getpokemon(i).getgenre();
		}
		wrsave1<< (*equipe).getnbpokemon() << std::endl;
		for (int i = 0; i < (*equipe).getnbpokemon(); i++)
		{
			wrsave1 << (*equipe).getpokemon(i).getnom() << std::endl;
			wrsave1 << (*equipe).getpokemon(i).getactPV() << std::endl;
			wrsave1 << (*equipe).getpokemon(i).getatt1() << std::endl;
			wrsave1 << (*equipe).getpokemon(i).getatt2() << std::endl;
			wrsave1 << (*equipe).getpokemon(i).getatt3() << std::endl;
			wrsave1 << (*equipe).getpokemon(i).getatt4() << std::endl;
			wrsave1 << (*equipe).getpokemon(i).getdgt1() << std::endl;
			wrsave1 << (*equipe).getpokemon(i).getdgt2() << std::endl;
			wrsave1 << (*equipe).getpokemon(i).getdgt3() << std::endl;
			wrsave1 << (*equipe).getpokemon(i).getdgt4() << std::endl;
			wrsave1 << (*equipe).getpokemon(i).getgenre() << std::endl;
			wrsave1 << (*equipe).getpokemon(i).getniveau() << std::endl;
			wrsave1 << (*equipe).getpokemon(i).getpuissance() << std::endl;
			wrsave1 << (*equipe).getpokemon(i).getPV() << std::endl;
			wrsave1 << (*equipe).getpokemon(i).getstade() << std::endl;
			wrsave1 << (*equipe).getpokemon(i).getXP() << std::endl;
			codeequi += equipe->getpokemon(i).getactPV() + 60 + 80 + 100 + 120 + (*equipe).getpokemon(i).getniveau() + (*equipe).getpokemon(i).getpuissance() + (*equipe).getpokemon(i).getPV() + (*equipe).getpokemon(i).getstade() + (*equipe).getpokemon(i).getXP() + hasch((*equipe).getpokemon(i).getnom()) + (*equipe).getpokemon(i).getgenre();
		}
		wrsave1 << (*mesressource).getpokeball() << std::endl;
		wrsave1 << (*mesressource).getpotion() << std::endl;
		wrsave1 << (*mesressource).gettune() << std::endl;

		codetmp = (position.x * position.y * posmapbefore.x * posmapbefore.y + IDmap * (*mesressource).getpokeball() * (*mesressource).getpotion() * (*mesressource).gettune())%999999999;
		codehash = (codesto* stocage->getnbpokemon() + codeequi *equipe->getnbpokemon() + codetmp)%666666666;
		wrsave1 << codehash<<std::endl;
		
		wrsave1 << "END";
		wrsave1.close();  // on referme le fichier
	}
	else  // sinon
		std::cerr << "Erreur à l'ouverture !" << std::endl;
}


void charger(std::string chemin, sf::Vector2i* position, sf::Vector2i* posmapbefore, int* IDmap, Pokedex** stocage, Pokedex** equipe, Ressource* mesressource)
{
	int nbpkmsto = 0;
	int nbpkmequ = 0;
	pokemon tmp;
	std::string strtmp;
	int inttmp = 0;
	unsigned int uinttmp = 0;
	pokemon_genre genretmp;
	unsigned int codesto = 0;
	unsigned int codeequi = 0;
	unsigned int codehash = 0;
	unsigned int codetmp = 0;
	unsigned int reelcodehas = 0;

	std::ifstream fichier(chemin.c_str(), std::ios::in);  // on ouvre le fichier en lecture le .c_str permet de convertire en cst char

	if (fichier)  // si l'ouverture a réussi
	{
		std::string L1 = "init";
		
		while (L1 != "END")
		{
			fichier >> (*position).x;
			fichier >> (*position).y;
			fichier >> (*posmapbefore).x;
			fichier >> (*posmapbefore).y;
			fichier >> *IDmap;
			fichier >> nbpkmsto;
			for (int i = 0; i < nbpkmsto; i++)
			{
				fichier >> strtmp;
				tmp.setnom(strtmp);
				fichier >> inttmp;
				tmp.setactPV(inttmp);
				fichier >> strtmp;
				tmp.setatt1(strtmp);
				fichier >> strtmp;
				tmp.setatt2(strtmp);
				fichier >> strtmp;
				tmp.setatt3(strtmp);
				fichier >> strtmp;
				tmp.setatt4(strtmp);
				fichier >> uinttmp;
				tmp.setdgt1(uinttmp);
				fichier >> uinttmp;
				tmp.setdgt2(uinttmp);
				fichier >> uinttmp;
				tmp.setdgt3(uinttmp);
				fichier >> uinttmp;
				tmp.setdgt4(uinttmp);
				fichier >> inttmp;
				if (inttmp == 0) { genretmp = male; }
				else if (inttmp == 1) { genretmp = femmelle; }
				else { genretmp = neutre; }
				tmp.setgenre(genretmp);
				fichier >> uinttmp;
				tmp.setniveau(uinttmp);
				fichier >> uinttmp;
				tmp.setpuissance(uinttmp);
				fichier >> uinttmp;
				tmp.setPV(uinttmp);
				fichier >> uinttmp;
				tmp.setstade(uinttmp);
				fichier >> uinttmp;
				tmp.setXP(uinttmp);
				insertPokemon(stocage, tmp);
				codesto = codesto + tmp.getactPV() + 60 + 80 + 100 + 120 + tmp.getniveau() + tmp.getpuissance() + tmp.getPV() + tmp.getstade() + tmp.getXP() + hasch(tmp.getnom()) + tmp.getgenre();
			}
			fichier >> nbpkmequ;
			for (int i = 0; i < nbpkmequ; i++)
			{
				fichier >> strtmp;
				tmp.setnom(strtmp);
				fichier >> inttmp;
				tmp.setactPV(inttmp);
				fichier >> strtmp;
				tmp.setatt1(strtmp);
				fichier >> strtmp;
				tmp.setatt2(strtmp);
				fichier >> strtmp;
				tmp.setatt3(strtmp);
				fichier >> strtmp;
				tmp.setatt4(strtmp);
				fichier >> uinttmp;
				tmp.setdgt1(uinttmp);
				fichier >> uinttmp;
				tmp.setdgt2(uinttmp);
				fichier >> uinttmp;
				tmp.setdgt3(uinttmp);
				fichier >> uinttmp;
				tmp.setdgt4(uinttmp);
				fichier >> inttmp;
				if (inttmp == 0) { genretmp = male; }
				else if (inttmp == 1) { genretmp = femmelle; }
				else { genretmp = neutre; }
				tmp.setgenre(genretmp);
				fichier >> uinttmp;
				tmp.setniveau(uinttmp);
				fichier >> uinttmp;
				tmp.setpuissance(uinttmp);
				fichier >> uinttmp;
				tmp.setPV(uinttmp);
				fichier >> uinttmp;
				tmp.setstade(uinttmp);
				fichier >> uinttmp;
				tmp.setXP(uinttmp);
				insertPokemon2(equipe, tmp, i);
				codeequi += tmp.getactPV() + 60 + 80 + 100 + 120 + tmp.getniveau() + tmp.getpuissance() + tmp.getPV() + tmp.getstade() + tmp.getXP() + hasch(tmp.getnom()) + tmp.getgenre();
			}
			fichier >> inttmp;
			(*mesressource).setpokeball(inttmp);
			fichier >> inttmp;
			(*mesressource).setpotion(inttmp);
			fichier >> inttmp;
			(*mesressource).settune(inttmp);
			fichier >> codehash;

			codetmp = ((*position).x * (*position).y * (*posmapbefore).x * (*posmapbefore).y + (*IDmap) * mesressource->getpotion() * mesressource->getpokeball() * mesressource->gettune())%999999999;
			reelcodehas = (codesto * (*stocage)->getnbpokemon() + codeequi * (*equipe)->getnbpokemon() + codetmp) % 666666666;

			fichier >> L1;// a mettre en fin de boucle d'insersion attention L1 prend une valeur qui est potentiellement un nom que l'on veut garder
		}
		fichier.close();  // on ferme le fichier
		if (codehash != reelcodehas) { std::cout << "save corrompu" << std::endl; }
		else { std::cout << "save is good" << std::endl; }
	}
	else  // sinon
		std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
}

int hasch(std::string str) 
{
	unsigned long hash = 5381;
	int c;
	
	for (int i = 0; i < str.length(); i++) {
		c = str.at(i);
		hash = ((hash << 5) + hash) + c;/* hash * 33 + c */
	}
	return (hash % 50); //modulo m
}