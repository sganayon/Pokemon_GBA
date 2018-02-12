#include"fct.h"
#include <SFML/Graphics.hpp>
#include<iostream>
#include<string.h>
#include<sstream>
#include<iomanip>
#include"util.h"
#include"sauvegarde.h"
#include "pokemon.h"
#include"pokedex.h"
#include "combat.h"
#include<thread>
#include<chrono>
#include<limits>

bool collisions_elem(sf::Sprite herbe, sf::Sprite rien, Falaise falaise, Map map, Perso perso, char sens) 
{
	bool colli = true;
	switch (sens)
	{
	case 'R':
		if (map.get(perso.posmap.x + 1,perso.posmap.y).getTexture() == rien.getTexture()) { colli = false; }
		else if (map.get(perso.posmap.x + 1, perso.posmap.y).getTexture() == herbe.getTexture()){ colli = false; }
		else if (map.get(perso.posmap.x + 1, perso.posmap.y).getTexture() == falaise. SbordterreU.getTexture()) { colli = false; }
		//else if (map.place[perso.posmapx + 1][perso.posmapy].getTexture() == falaise.SbordterreR.getTexture()) { colli = false; }
		break;
	case 'L' : 
		if (map.get(perso.posmap.x - 1,perso.posmap.y).getTexture() == rien.getTexture()){ colli = false; }
		else if (map.get(perso.posmap.x - 1, perso.posmap.y).getTexture() == herbe.getTexture()) { colli = false; }
		else if (map.get(perso.posmap.x - 1, perso.posmap.y).getTexture() == falaise.SbordterreU.getTexture()) { colli = false; }
		//else if (map.place[perso.posmapx - 1][perso.posmapy].getTexture() == falaise.SbordterreR.getTexture()) { colli = false; }
		break;
	case 'U':
		if (map.get(perso.posmap.x,perso.posmap.y - 1).getTexture() == rien.getTexture()){ colli = false; }
		else if (map.get(perso.posmap.x, perso.posmap.y - 1).getTexture() == herbe.getTexture()) { colli = false; }
		else if (map.get(perso.posmap.x, perso.posmap.y - 1).getTexture() == falaise.SbordterreU.getTexture()) { colli = false; }
		//else if (map.place[perso.posmapx][perso.posmapy - 1].getTexture() == falaise.SbordterreR.getTexture()) { colli = false; }
		break;
	case 'D' : 
		if (map.get(perso.posmap.x,perso.posmap.y + 1).getTexture() == rien.getTexture()){ colli = false; }
		else if (map.get(perso.posmap.x, perso.posmap.y + 1).getTexture() == herbe.getTexture()) { colli = false; }
		else if (map.get(perso.posmap.x, perso.posmap.y + 1).getTexture() == falaise.SbordterreU.getTexture()) { colli = false; }
		//else if (map.place[perso.posmapx][perso.posmapy + 1].getTexture() == falaise.SbordterreR.getTexture()) { colli = false; }
		break;
	default:
		break;
	}
	return colli;
}

void insertCntpoke(CentrePokemon centreP, Map* map, int casex, int casey) 
{
	for (int i = casex; i < casex + (centreP.gettx() / 16); i++) { for (int j = casey; j < casey + (centreP.getty() / 16) - 1; j++) {(*map).set(centreP.SCentrePvide,i,j); } } //name la place reel du batiment
	(*map).set(centreP.SCentreP,casex,casey);//on place un sprite d'une case avec une image plus grande
	(*map).set(centreP.SCentrePporte, casex + (centreP.getportex() / 16),casey + (centreP.getportey() / 16) - 1);//place un sprite transparent avec id porte pour detecter colli porte
}

void insertShppoke(ShopPokemon shopP, Map* map, int casex, int casey)
{
	for (int i = casex; i < casex + (shopP.getStx() / 16); i++) { for (int j = casey; j < casey + (shopP.getSty() / 16) -1; j++) { (*map).set(shopP.SshopPvide, i, j); } } //name la place reel du batiment
	(*map).set(shopP.SShopP, casex, casey);//on place un sprite d'une case avec une image plus grande
	(*map).set(shopP.SshopPporte, casex + (shopP.getSportex() / 16), casey + (shopP.getSportey() / 16) - 2);//place un sprite transparent avec id porte pour detecter colli porte
}

bool colliporte(sf::Sprite portecentrep, sf::Sprite porteshopp, sf::Sprite portesortie, Map map, Perso perso, char sens, int* IDmap) 
{//IDmap : 0 = mapgeneral, 1 = mapcntpkm, 2 = shoppkm, 3 = maisonV
	bool chgmap = true;
	switch (sens)
	{
	case 'R':
		if (map.get(perso.posmap.x+1, perso.posmap.y).getTexture() == portesortie.getTexture()) { *IDmap = 0; std::cout << "porte sortie detecter" << std::endl; }
		else if (map.get(perso.posmap.x+1, perso.posmap.y).getTexture() == portecentrep.getTexture()) { *IDmap = 1;  std::cout << "porte centrep detecter" << std::endl; }
		else if (map.get(perso.posmap.x+1, perso.posmap.y).getTexture() == porteshopp.getTexture()) { *IDmap = 2;  std::cout << "porte shopp detecter" << std::endl; }
		else { chgmap = false; }
		break;
	case 'L':
		if (map.get(perso.posmap.x-1, perso.posmap.y).getTexture() == portesortie.getTexture()) { *IDmap = 0; std::cout << "porte sortie detecter" << std::endl; }
		else if (map.get(perso.posmap.x-1, perso.posmap.y).getTexture() == portecentrep.getTexture()) { *IDmap = 1;  std::cout << "porte centrep detecter" << std::endl; }
		else if (map.get(perso.posmap.x-1, perso.posmap.y).getTexture() == porteshopp.getTexture()) { *IDmap = 2;  std::cout << "porte shopp detecter" << std::endl; }
		else { chgmap = false; }
		break;
	case 'U':
		if (map.get(perso.posmap.x, perso.posmap.y-1).getTexture() == portesortie.getTexture()) { *IDmap = 0; std::cout << "porte sortie detecter" << std::endl; }
		else if (map.get(perso.posmap.x, perso.posmap.y-1).getTexture() == portecentrep.getTexture()) { *IDmap = 1;  std::cout << "porte centrep detecter" << std::endl; }
		else if (map.get(perso.posmap.x, perso.posmap.y-1).getTexture() == porteshopp.getTexture()) { *IDmap = 2;  std::cout << "porte shopp detecter" << std::endl; }
		else { chgmap = false; }
		break;
	case 'D':
		if (map.get(perso.posmap.x, perso.posmap.y+1).getTexture() == portesortie.getTexture()) { *IDmap = 0; std::cout << "porte sortie detecter" << std::endl; }
		else if (map.get(perso.posmap.x, perso.posmap.y+1).getTexture() == portecentrep.getTexture()) { *IDmap = 1;  std::cout << "porte centrep detecter" << std::endl; }
		else if (map.get(perso.posmap.x, perso.posmap.y+1).getTexture() == porteshopp.getTexture()) { *IDmap = 2;  std::cout << "porte shopp detecter" << std::endl; }
		else { chgmap = false; }
		break;
	default:
		chgmap = false;
		break;
	}
	return chgmap;
}

bool istalkingPNJ(int persoposmapx, int persoposmapy, int pnjposmapx, int pnjposmapy, char* sens)
{
	bool speech = false;
	if (persoposmapx == pnjposmapx) //joueur et pnj aligner sur x
	{
		if (persoposmapy == pnjposmapy - 1) 
		{
			*sens = 'F';
			speech = true;
		}
		if (persoposmapy == pnjposmapy + 1)
		{
			*sens = 'B';
			speech = true;
		}
	}
	else if (persoposmapy == pnjposmapy) // joueur aligner sur y
	{
		if (persoposmapx == pnjposmapx - 1)
		{
			*sens = 'R';
			speech = true;
		}
		if (persoposmapx == pnjposmapx + 1)
		{
			*sens = 'L';
			speech = true;
		}
	}
	return speech;
}

void inimapgene(Map* map, sf::Sprite eau, sf::Sprite herbe, sf::Sprite arbre, sf::Sprite falaisebordR, sf::Sprite bordterreU, sf::Sprite bordfalaisemerUR, sf::Sprite marcel, int marcelposmapx, int marcelposmapy, CentrePokemon centreP, ShopPokemon shopP)
{
	(*map).set(marcel, marcelposmapx, marcelposmapy);

	insertCntpoke(centreP, map, 20, 7);
	insertShppoke(shopP, map, 40, 12);

	(*map).set(herbe, 1, 1);
	(*map).set(arbre, 3, 1);

	(*map).set(falaisebordR, 48, 2);
	(*map).set(falaisebordR, 48, 3);
	(*map).set(falaisebordR, 48, 4);
	(*map).set(falaisebordR, 48, 5);
	(*map).set(bordterreU, 48, 6);
	(*map).set(bordfalaisemerUR, 48, 1);
	(*map).set(bordterreU, 47, 1);
	(*map).set(bordterreU, 46, 1);
	(*map).set(bordterreU, 45, 1);
	(*map).set(bordterreU, 44, 1);
	(*map).set(bordterreU, 43, 1);
	(*map).set(falaisebordR, 43, 0);

	(*map).set(eau, 48, 0);
	(*map).set(eau, 47, 0);
	(*map).set(eau, 46, 0);
	(*map).set(eau, 45, 0);
	(*map).set(eau, 44, 0);

	for (int i = 49; i < 98; i++) 
	{
		(*map).set(eau, i, 0);
		(*map).set(eau, i, 1);
		(*map).set(eau, i, 2);
		(*map).set(eau, i, 3);
		(*map).set(eau, i, 4);
		(*map).set(eau, i, 5);
		(*map).set(bordterreU, i, 6);
	}


	for (int i = 5; i<10; i++)
	{
		for (int j = 5; j < 10; j++) { (*map).set(eau, i, j); }
	}

	for (int i = 20; i<30; i++)
	{
		for (int j = 20; j < 25; j++) { (*map).set(herbe, i, j); }
	}

	for (int i = 60; i<85; i++)
	{
		for (int j = 80; j < 90; j++) { (*map).set(herbe, i, j); }
	}

	for (int i = 35; i<47; i++)
	{
		for (int j = 26; j < 35; j++) { (*map).set(arbre, i, j); }
	}
}

void inimapcntpkm(Map* map, sf::Sprite mur, sf::Sprite porte, sf::Sprite wallR, sf::Sprite wallD, sf::Sprite wallL, sf::Sprite gerard, int gerardposx, int gerardposy, sf::Sprite trans, int transposx, int transposy)
{
	for (int i = 15; i < 30; i++)
	{
		(*map).set(mur, i, 10);
		(*map).set(wallD, i, 21);
	}

	(*map).set(porte, 22, 20); //porte de sorti

	for (int j = 9; j < 22; j++) 
	{
		(*map).set(wallL, 14, j);
		(*map).set(wallR, 30, j);
	}

	(*map).set(gerard, gerardposx, gerardposy);
	(*map).set(trans, transposx, transposy);
}

void inimapshppkm(Map* map, sf::Sprite mur, sf::Sprite porte, sf::Sprite wallR, sf::Sprite wallD, sf::Sprite wallL, sf::Sprite hubert, int hubertposx, int hubertposy) 
{
	for (int i = 15; i < 30; i++)
	{
		(*map).set(mur, i, 10);
		(*map).set(wallD, i, 21);
	}

	(*map).set(porte, 22, 20); //porte de sorti

	for (int j = 9; j < 22; j++)
	{
		(*map).set(wallL, 14, j);
		(*map).set(wallR, 30, j);
	}

	(*map).set(hubert, hubertposx, hubertposy);
}

void majposchgmap(bool* chgmap, int IDmap, Perso* perso, sf::Vector2i* posmapbefore, sf::Vector2i posmapbat)
{
	if (*chgmap) //met a jours la pos du perso si chgmap
	{
		if (IDmap != 0)//on est passer de la map general a un batiment
		{
			*posmapbefore = (*perso).posmap; //on save la position sur la map;
			(*perso).posmap = posmapbat; //on met le perso a l'entre (et la sortie) du batiment
		}
		else // on fait l'op inverse (on sort d'un bat pour aller map general)
		{
			(*perso).posmap = (*posmapbefore);
			(*perso).face = 'D';
		}
		*chgmap = false;
	}
}

void detercmbpkm(Map* mapptr, int posmapx, int posmapy, bool* isattackable, sf::Sprite herbe, bool* combat, bool chgmap) 
{
	if (chgmap){} // empeche la verification de la texture des porte qui pour une raison inconnue et impossible devien la meme que celle de l'herbe juste dans le if ...
	else if (((*mapptr).get(posmapx, posmapy).getTexture() == herbe.getTexture()) && *isattackable)
	{
		if (random_at_most(100) < 10)
		{
			*combat = true;
			std::cout << "un pokemon sauvage apparait" << std::endl;
			//p1 = genererPokemon(bestiaire);
		}
		*isattackable = false; //previend le spam combat en restant sur une mm feuille 
	}
}

void affbulle(Bull bulle, sf::RenderWindow* window, sf::Text texte) 
{
	bulle.SbulleL.setPosition(0, 35 * 16);
	(*window).draw(bulle.SbulleL);
	for (int i = 1; i < 49; i++)
	{
		bulle.SbulleU.setPosition(i * 16, 35 * 16);
		(*window).draw(bulle.SbulleU);
		bulle.SbulleD.setPosition(i * 16, 36 * 16);
		(*window).draw(bulle.SbulleD);
	}
	bulle.SbulleR.setPosition(49 * 16, 35 * 16);
	(*window).draw(bulle.SbulleR);
	(*window).draw(texte);
}

void affbulleshop(Bull bulle, sf::RenderWindow* window, sf::Text textpokeballx1, sf::Text textpokeballx10, sf::Text textpotionx1, sf::Text textpotionx10)
{
	bulle.SbulleL.setPosition(0, 33 * 16);
	(*window).draw(bulle.SbulleL);
	for (int i = 1; i < 49; i++)
	{
		bulle.SbulleU.setPosition(i * 16, 33 * 16);
		(*window).draw(bulle.SbulleU);
		bulle.SbulleD.setPosition(i * 16, 34 * 16);
		(*window).draw(bulle.SbulleD);
	}
	bulle.SbulleR.setPosition(49 * 16, 33 * 16);
	(*window).draw(bulle.SbulleR);
	(*window).draw(textpokeballx1);
	(*window).draw(textpokeballx10);
	(*window).draw(textpotionx1);
	(*window).draw(textpotionx10);
}

void affmapgeneral(sf::RenderWindow* window, Map* mapptr, bool speech, sf::Sprite herbe, sf::Sprite fond, sf::Sprite rien, sf::Sprite arbre, Perso perso, sf::Text texte, Bull bulle, int xmeff, int xeff, int ymeff, int yeff)
{
	sf::Sprite tmp;

	int xmin = perso.posmap.x - 25; // fenetre de 50 en x 
	int xmax = perso.posmap.x + 25;
	int ymin = perso.posmap.y - 18; // fenetre de 37 en y
	int ymax = perso.posmap.y + 19;
	float pospersx = 25.f * 16.f; //perso centrer sur la map
	float pospersy = 18.f * 16.f;

	if (perso.posmap.x < 25) { xmin = 0; xmax = 50; pospersx = (float)(perso.posmap.x) * 16.f; } // si l'on risque d'afficher un indice negatif on affiche les 50 premiere case en x (perso se raprochera du bord) et la position reel du perso
	else if (perso.posmap.x > 75) {xmin = 50; xmax = 100; pospersx = ((float)(perso.posmap.x) - (float)(100 - 50))* 16.f;}// si l'on risque d'afficher un indice sup a 100 (max de la map) on bloque l'affichage a 50 - 100 et la position du perso est ajuster
	if (perso.posmap.y < 18) {ymin = 0; ymax = 37; pospersy = (float)(perso.posmap.y) * 16.f;} // de meme 
	else if (perso.posmap.y > 81) {ymin = 63; ymax = 100; pospersy = ((float)(perso.posmap.y) - (float)(100 - 37))* 16.f;}

	fond.setPosition(xeff*16, yeff*16); //si on deplace le fond il fera du noir au dessus et a gauche de l'ecrant
	fond.setTextureRect(sf::IntRect(0, 0, 800-xmeff*32, 592 - ymeff*32)); //si on reduit le rectangle de texture par le bas droite on aura du noir mais il faut reduire 2x car on deplace aussi le fond. 

	(*window).draw(fond);
	for (int i = xmin+xeff; i < xmax - xmeff; i++) // les eff permettent d'afficher le noir du combat en reduisant le cadre afficher  
	{
		for (int j = ymin+yeff; j < ymax-ymeff; j++)
		{
			if ((*mapptr).get(i, j).getTexture() != rien.getTexture()) // optimise l'affichage, srien etant transparent on voit le fond qui est tjr dessiner en 1 appel on vas donc reduire l'appel draw
			{ 
				tmp = (*mapptr).get(i, j);
				tmp.setPosition((i-xmin)*16.f, (j-ymin)*16.f); //on repositionne le sprite sur l'ecrant (si l'on est en 25 en x on veut afficher l'elem en x = 0)
				(*window).draw(tmp); 
			} 
		}
	}
	tmp = perso.Sperso;
	tmp.setPosition(pospersx,pospersy);
	(*window).draw(tmp);
	if ((xeff == 0) && (xmeff == 0) && (yeff == 0) && (ymeff == 0)) { //si on veut afficher un noir combat il ne faut pas que les sapins se voit sur le noir
		for (int i = xmin; i < xmax; i++)
		{
			for (int j = ymin; j < ymax; j++)
			{
				if ((*mapptr).get(i, j).getTexture() == arbre.getTexture()) //permet d'avoir les arbre dessiner sur nous si l'on est derriere eux  
				{
					tmp = (*mapptr).get(i, j);
					tmp.setPosition((float)((i - xmin) * 16), (float)((j - ymin) * 16)); //on repositionne le sprite sur l'ecrant (si l'on est en 25 en x on veut afficher l'elem en x = 0)
					(*window).draw(tmp);
				}
			}
		}
	}
	if (speech)
	{
		affbulle(bulle, window, texte);
	}
}

void affmapcntpkm(sf::RenderWindow* window, Map* mapptr, bool speech, sf::Text texte, sf::Sprite rien, Perso perso, sf::Sprite fond, Bull bulle)
{
	sf::Sprite tmp;

	(*window).draw(fond);
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 37; j++)
		{
			if ((*mapptr).get(i, j).getTexture() != rien.getTexture()) { (*window).draw((*mapptr).get(i, j)); } //optimise l'affichage, srien etant transparent on voit le fond qui est tjr dessiner en 1 appel on vas donc reduire l'appel draw 
		}
	}
	tmp = perso.Sperso;
	tmp.setPosition((float)(perso.posmap.x * 16),(float)(perso.posmap.y * 16));
	(*window).draw(tmp);
	if (speech)
	{
		affbulle(bulle, window, texte);
	}
}

void affmapshppkm(sf::RenderWindow* window, Map* mapptr, bool speech, sf::Text texte, sf::Sprite rien, Perso perso, sf::Sprite fond, Bull bulle,bool venteshop, Shopdeco shopdeco)
{
	sf::Sprite tmp;

	(*window).draw(fond);
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 37; j++)
		{
			if ((*mapptr).get(i, j).getTexture() != rien.getTexture()) { (*window).draw((*mapptr).get(i, j)); } //optimise l'affichage, srien etant transparent on voit le fond qui est tjr dessiner en 1 appel on vas donc reduire l'appel draw 
		}
	}
	tmp = perso.Sperso;
	tmp.setPosition((float)(perso.posmap.x * 16), (float)(perso.posmap.y * 16));
	(*window).draw(tmp);
	if (speech)
	{
		affbulle(bulle, window, texte);
	}
	if (venteshop)
	{
		affbulleshop(bulle, window, shopdeco.textpokeballx1, shopdeco.textpokeballx10, shopdeco.textpotionx1, shopdeco.textpotionx10);
	}
}

void affmenus(sf::RenderWindow* window, sf::Sprite fond, sf::Sprite logo, sf::Sprite fondmenu, sf::Text T0, sf::Text T1, sf::Text T2, sf::Text T3)
{
	(*window).draw(fond);
	(*window).draw(logo);
	(*window).draw(fondmenu);
	(*window).draw(T0);
	(*window).draw(T1);
	(*window).draw(T2);
	(*window).draw(T3);
}

void affmenuini(sf::RenderWindow* window, sf::Sprite fond, sf::Sprite logo, sf::Sprite fondmenu, sf::Text T0, sf::Text T1)
{
	(*window).draw(fond);
	(*window).draw(logo);
	(*window).draw(fondmenu);
	(*window).draw(T0);
	(*window).draw(T1);
}

void majmenu(int IDlignemenu, Menudeco* menudeco) 
{
	(*menudeco).text0.setStyle(sf::Text::Regular);
	(*menudeco).text1.setStyle(sf::Text::Regular);
	(*menudeco).text2.setStyle(sf::Text::Regular);
	(*menudeco).text3.setStyle(sf::Text::Regular);
	switch (IDlignemenu)
	{
	case 0:
		(*menudeco).text0.setStyle(sf::Text::Bold);
		break;

	case 1:
		(*menudeco).text1.setStyle(sf::Text::Bold);
		break;

	case 2:
		(*menudeco).text2.setStyle(sf::Text::Bold);
		break;

	case 3 : 
		(*menudeco).text3.setStyle(sf::Text::Bold);
		break;
	default:
		break;
	}
}

void majmenuini(int IDlignemenuini, Menudeco* menudeco)
{
	(*menudeco).textreini.setStyle(sf::Text::Regular);
	(*menudeco).textcont.setStyle(sf::Text::Regular);
	switch (IDlignemenuini)
	{
	case 0:
		(*menudeco).textreini.setStyle(sf::Text::Bold);
		break;

	case 1:
		(*menudeco).textcont.setStyle(sf::Text::Bold);
		break;

	default:
		break;
	}
}

void affcmbt(sf::RenderWindow* window, Combatdeco* cmbtdeco, sf::Sprite Spkmsav, sf::Sprite Spkm, char choix1)
{
	(*window).draw((*cmbtdeco).Sfondcmbt);
	(*window).draw((*cmbtdeco).textnompkm);
	(*window).draw((*cmbtdeco).textnompkmsav);
	(*window).draw((*cmbtdeco).textviepkm);
	(*window).draw((*cmbtdeco).textviepkmsav);
	(*window).draw((*cmbtdeco).Sbarrevie);
	(*window).draw((*cmbtdeco).Sbarreviepkmsav);
	(*window).draw(Spkmsav);
	(*window).draw(Spkm);
	switch (choix1)
	{
	case 'A' :	//on a choisi attaque
		(*window).draw((*cmbtdeco).textatt1);
		(*window).draw((*cmbtdeco).textatt2);
		(*window).draw((*cmbtdeco).textatt3);
		(*window).draw((*cmbtdeco).textatt4);
		break;

	case 'O' :	//on a choisi objet
		(*window).draw((*cmbtdeco).textpokeball);
		(*window).draw((*cmbtdeco).textpotion);
		break;

	case 'P' :	//on a choisi pokemon
		break;

	case 'M' :	//on est au menu
		(*window).draw((*cmbtdeco).textatt);
		(*window).draw((*cmbtdeco).textobj);
		(*window).draw((*cmbtdeco).textfuite);
		(*window).draw((*cmbtdeco).textpokemon);
		break;

	default:	//menu par defaut
		(*window).draw((*cmbtdeco).textatt);
		(*window).draw((*cmbtdeco).textobj);
		(*window).draw((*cmbtdeco).textfuite);
		(*window).draw((*cmbtdeco).textpokemon);
		break;
	}
}

void majmenucmbt(int IDligne, int IDcolone, char choixmenu, Combatdeco* combatdeco) 
{
	(*combatdeco).textatt.setStyle(sf::Text::Regular);
	(*combatdeco).textobj.setStyle(sf::Text::Regular);
	(*combatdeco).textfuite.setStyle(sf::Text::Regular);
	(*combatdeco).textpokemon.setStyle(sf::Text::Regular);
	(*combatdeco).textatt1.setStyle(sf::Text::Regular);
	(*combatdeco).textatt2.setStyle(sf::Text::Regular);
	(*combatdeco).textatt3.setStyle(sf::Text::Regular);
	(*combatdeco).textatt4.setStyle(sf::Text::Regular);
	(*combatdeco).textpokeball.setStyle(sf::Text::Regular);
	(*combatdeco).textpotion.setStyle(sf::Text::Regular);

		
	switch (choixmenu)
	{
	case 'M': //on est au menus general
		if (IDligne == 0)  //on a attaquer ou objet
		{
			if (IDcolone == 0) { (*combatdeco).textatt.setStyle(sf::Text::Bold); } // on a choisi attaquer
			else {  (*combatdeco).textobj.setStyle(sf::Text::Bold);} // on a choisi objet 
		}
		else
		{
			if (IDcolone == 0) { (*combatdeco).textfuite.setStyle(sf::Text::Bold); }// on a choisi de fuire 
			else { (*combatdeco).textpokemon.setStyle(sf::Text::Bold); } // on a choisi pokemon 
		}
		break;

	case 'A'://on est au menu d'attaque 
		if (IDligne == 0)
		{
			if (IDcolone == 0) { (*combatdeco).textatt1.setStyle(sf::Text::Bold); } // attaque 1
			else { (*combatdeco).textatt2.setStyle(sf::Text::Bold); } //attaque 2
		}
		else
		{
			if (IDcolone == 0) { (*combatdeco).textatt3.setStyle(sf::Text::Bold); } //attaque 3
			else { (*combatdeco).textatt4.setStyle(sf::Text::Bold); } //attaque 4 
		}
		break;

	case 'O':
		if (IDligne == 0)
		{
			if (IDcolone == 0) { (*combatdeco).textpokeball.setStyle(sf::Text::Bold); } // pokeball
			else {  } // not implemented yet 
		}
		else
		{
			if (IDcolone == 0) { (*combatdeco).textpotion.setStyle(sf::Text::Bold); }//potion
			else { }// not implemented yet
		}
		break;

	default:
		break;
	}
}

void gestionmenu(sf::Event event, sf::RenderWindow* window, int* IDlignemenu, bool* menu, std::string cheminsave, sf::Vector2i persoposmap, sf::Vector2i posmapbefore, int IDmap, char* pagemenu, int* rangpkmaff, Pokedex* stocage, Pokedex* equipe, Ressource* mesressource, bool* echange, especepokemon bestiaire[], int* IDpkmequipe, pokemon* pokemonptr, int IDpkmcmbt)
{
	pokemon tmp; 

	if ((*pagemenu) == 'M') // on est sur le menu principal
	{
		if (event.key.code == sf::Keyboard::Up) //permet de selec la ligne
		{
			if ((*IDlignemenu) > 0) { (*IDlignemenu)--; }
		}

		if (event.key.code == sf::Keyboard::Down)
		{
			if ((*IDlignemenu) < 3) { (*IDlignemenu)++; } //on n'a que 4 choix pour le moment
		}

		if (event.key.code == sf::Keyboard::Y) //valide le choix 
		{
			switch ((*IDlignemenu))
			{
			case 0: //Mes pokemons
				(*pagemenu) = 'P';
				break;

			case 1 : //mon equipe
				(*pagemenu) = 'E';
				break;

			case 2:// reprendre la partie
				*menu = false;
				break;

			case 3: //Sauvegarder/Quitter

				sauvegarder(cheminsave, persoposmap, posmapbefore, IDmap, stocage, equipe, mesressource);
				(*window).close();
				break;
			default:
				break;
			}
		}
	}
	else if ((*pagemenu) == 'P') //on est sur le menu afficher mes pokemon
	{
		if (event.key.code == sf::Keyboard::Right) 
		{
			if ((*rangpkmaff)<stocage->getnbpokemon()) { (*rangpkmaff)++; }//decale les pkm que l'on vas affaicher 
			
		}

		if (event.key.code == sf::Keyboard::Left) 
		{
			if ((*rangpkmaff)>0) { (*rangpkmaff)--; }//decale les pkm que l'on vas affaicher 
		}

		if (event.key.code == sf::Keyboard::N) //retourne au menu principal
		{
			if (*echange){ (*pagemenu) = 'E'; }
			else { (*pagemenu) = 'M'; }
		}

		if ((event.key.code == sf::Keyboard::Y) && (*echange)&& (equipe->getnbpokemon() < 6))
		{
			tmp = stocage->getpokemon(*rangpkmaff); // on recup le pkm a echanger
			supPokemon(&stocage, *rangpkmaff, bestiaire); // on le suprime du stocage
			insertPokemon2(&equipe, tmp, *IDpkmequipe); //on l'insert dans l'equipe sans le trier 
			if (*IDpkmequipe == IDpkmcmbt) 
			{
				pokemonptr->setactPV(tmp.getactPV());
				pokemonptr->setPV(tmp.getPV());
				pokemonptr->setatt1(tmp.getatt1());
				pokemonptr->setatt2(tmp.getatt2());
				pokemonptr->setatt3(tmp.getatt3());
				pokemonptr->setatt4(tmp.getatt4());
				pokemonptr->setgenre(tmp.getgenre());
				pokemonptr->setniveau(tmp.getniveau());
				pokemonptr->setnom(tmp.getnom());
				pokemonptr->setpuissance(tmp.getpuissance());
				pokemonptr->setstade(tmp.getstade());
				pokemonptr->setXP(tmp.getXP());
			}
			(*pagemenu) = 'M';
			*menu = false;
			*echange = false;
		}
	}

	else if ((*pagemenu) == 'E') //on est sur le menu afficher mes pokemon
	{
		if (event.key.code == sf::Keyboard::Right)
		{
			if ((*IDpkmequipe)<equipe->getnbpokemon()) { (*IDpkmequipe)++; }//decale les pkm que l'on vas echanger 

		}

		if (event.key.code == sf::Keyboard::Left)
		{
			if ((*IDpkmequipe)>0) { (*IDpkmequipe)--; }//decale les pkm que l'on vas echanger 
		}

		if (event.key.code == sf::Keyboard::N) //retourne au menu principal
		{
			if (*echange) { (*pagemenu) = 'M'; *echange = false; *menu = false; }
			else { (*pagemenu) = 'M'; }
		}

		if ((event.key.code == sf::Keyboard::Y) && (*echange))
		{
			if(*IDpkmequipe >= equipe->getnbpokemon()){}//si on a moin de 6 pkm et que on choisi un emplacement vide on ne garde que l'ID
			else 
			{
				tmp = equipe->getpokemon(*IDpkmequipe); //on recup le pkm
				insertPokemon(&stocage, tmp);
			}//on le met dans le stocage
			(*pagemenu) = 'P'; //on affiche les pkm du stocage
		}
	}
	else 
	{
		if (event.key.code == sf::Keyboard::N) //retourne au menu principal
		{
			(*pagemenu) = 'M';
		}
	}
}

void gestionmenucombat(sf::Event event, int* IDlignemenucmbt, int* IDcolonemenucmbt, char* choixmenucmbt, bool* cmbt, pokemon* pokemonptr, pokemon* pokemonsav, hashtable* htab, especepokemon bestiaire[], bool* IsP1Dead, Ressource* mesressource, Pokedex** stocage, sf::RenderWindow* window, Combatdeco cmbtdeco, EffectAtt* effect, bool* cmbtatt, CombatPokemon* cmbtpkm)
{

	if (event.key.code == sf::Keyboard::Up)
	{
		if ((*IDlignemenucmbt) > 0) { (*IDlignemenucmbt)--; }
	}
	if (event.key.code == sf::Keyboard::Down)
	{
		if ((*IDlignemenucmbt) < 1) { (*IDlignemenucmbt)++; }
	}
	if (event.key.code == sf::Keyboard::Right)
	{
		if ((*IDcolonemenucmbt) < 1) { (*IDcolonemenucmbt)++; }
	}
	if (event.key.code == sf::Keyboard::Left)
	{
		if ((*IDcolonemenucmbt) > 0) { (*IDcolonemenucmbt)--; }
	}
	if (event.key.code == sf::Keyboard::Y) //valide le choix 
	{
		switch ((*choixmenucmbt))
		{
		case 'M': //on est au menus general
			if ((*IDlignemenucmbt) == 0)  //on a attaquer ou objet
			{
				if ((*IDcolonemenucmbt) == 0) { (*choixmenucmbt) = 'A'; } // on a choisi attaquer chg le menu
				else { (*choixmenucmbt) = 'O'; } // on a choisi objet
			}
			else
			{
				if ((*IDcolonemenucmbt) == 0) { (*cmbt) = false; std::cout << "vous fuyer lachement" << std::endl; }// on a choisi la fuite 
				else { (*choixmenucmbt) = 'P'; } // on a choisi pokemon chg le menu
			}
			break;

		case 'A'://on est au menu d'attaque 
			if ((*IDlignemenucmbt) == 0)
			{
				if ((*IDcolonemenucmbt) == 0) { combat(pokemonptr, pokemonsav, htab, bestiaire, 60, cmbt, IsP1Dead, mesressource, window, cmbtdeco, effect, cmbtpkm); (*choixmenucmbt) = 'M'; *cmbtatt = true; }  // attaque 1
				else { if (pokemonptr->getatt2() != "...") { combat(pokemonptr, pokemonsav, htab, bestiaire, 80, cmbt, IsP1Dead, mesressource, window, cmbtdeco, effect, cmbtpkm); (*choixmenucmbt) = 'M'; *cmbtatt = true;} }//attaque 2
			}
			else
			{
				if ((*IDcolonemenucmbt) == 0) { if (pokemonptr->getatt3() != "...") { combat(pokemonptr, pokemonsav, htab, bestiaire, 100, cmbt, IsP1Dead, mesressource, window, cmbtdeco, effect, cmbtpkm); (*choixmenucmbt) = 'M'; *cmbtatt = true;} } //attaque 3
				else { if (pokemonptr->getatt4() != "...") { combat(pokemonptr, pokemonsav, htab, bestiaire, 120, cmbt, IsP1Dead, mesressource, window, cmbtdeco, effect, cmbtpkm); (*choixmenucmbt) = 'M'; *cmbtatt = true;} } //attaque 4 
			}
			break;

		case 'O': // on est au menu objet
			if ((*IDlignemenucmbt) == 0)
			{
				if ((*IDcolonemenucmbt) == 0) 
				{
					if (mesressource->getpokeball() > 0) // si on a des pokeball
					{
						mesressource->setpokeball(mesressource->getpokeball() - 1);
						if (attraperpkmsav((float)(pokemonsav->getactPV()) / (float)(pokemonsav->getPV()), stocage, pokemonsav)) { *cmbt = false; *choixmenucmbt = 'M'; }
						else { combatsav(pokemonptr, pokemonsav, htab, bestiaire, cmbt, IsP1Dead, cmbtpkm); *cmbtatt = true; *choixmenucmbt = 'M';}// pokemon sauvage attaque si il n'est pas capturer
						 
					}
				} // pokeball
				else {} // not implemented yet
			}
			else
			{
				if ((*IDcolonemenucmbt) == 0)
				{
					if (mesressource->getpotion() > 0) //si on a des potions 
					{
						if (pokemonptr->getactPV() + 300 < pokemonptr->getPV()) { pokemonptr->setactPV(pokemonptr->getactPV() + 300); }//on soigne le pkm si on n'attein pas le max de ces pv
						else { pokemonptr->setactPV(pokemonptr->getPV()); }//on le soigne au max et pas au dessus
						mesressource->setpotion(mesressource->getpotion() - 1);
						combatsav(pokemonptr, pokemonsav, htab, bestiaire, cmbt, IsP1Dead, cmbtpkm); // pokemon sauvage attaque
						*cmbtatt = true;
						*choixmenucmbt = 'M';
					}
				} //potion
				else {} //not implemented yet
			}
			break;

		case 'p': 
			//select le pkm a mettre dans le cmbt
			break;
		default:
			break;
		}
		(*IDcolonemenucmbt) = 0;
		(*IDlignemenucmbt) = 0;
	}

	if (event.key.code == sf::Keyboard::N)
	{
		(*choixmenucmbt) = 'M'; //on revien au menu principal du cmbt
	}
}

void gestionmenuini(sf::Event event, int * IDlignemenuini, char* pagemenu, std::string cheminsave, sf::Vector2i* persoposmap, sf::Vector2i* posmapbefore, int* IDmap, Pokedex* stocage, Pokedex* equipe, Ressource* mesressource, char* labeltype[], especepokemon bestiraire[], Perso* perso, pokemon* pkmcmbt, bool* isinmenu)
{
	if (event.key.code == sf::Keyboard::Up) //permet de selec la ligne
	{
		if ((*IDlignemenuini) > 0) { (*IDlignemenuini)--; }
	}

	if (event.key.code == sf::Keyboard::Down)
	{
		if ((*IDlignemenuini) < 1) { (*IDlignemenuini)++; } //on n'a que 2 choix
	}
	if (event.key.code == sf::Keyboard::Y) //valide le choix 
	{
		switch ((*IDlignemenuini))
		{
		case 0: //reini
			(*pagemenu) = 'M';
			(*persoposmap).x = 10;
			(*persoposmap).y = 10;
			(*posmapbefore).x = 0;
			(*posmapbefore).y = 0;
			(*IDmap) = 0;
			inipokedexe(equipe, labeltype, bestiraire);
			(*mesressource).setpokeball(2);
			(*mesressource).setpotion(0);
			(*mesressource).settune(3000);
			(*perso).posmap.x = 10;
			(*perso).posmap.y = 10;
			(*pkmcmbt) = (*equipe).getpokemon(0);
			(*isinmenu) = false; // on sort du menu
			break;

		case 1: //continuer
			(*pagemenu) = 'M';
			charger(cheminsave, persoposmap, posmapbefore, IDmap, &stocage, &equipe, mesressource);
			(*perso).posmap.x = (*persoposmap).x;
			(*perso).posmap.y = (*persoposmap).y;
			(*pkmcmbt) = (*equipe).getpokemon(0);
			(*isinmenu) = false; // on sort du menu
			break;
		default:
			break;
		}
	}
}

void gestionspeech(int IDmap,Perso* perso, PNJ** pnjptr, PNJ* marcel, PNJ* gerard, PNJ* hubert, PNJ* trans, bool* speech, bool* venteshop, int tune) 
{
	std::string text;
	switch (IDmap)
	{
	case 0:
		if (istalkingPNJ((*perso).posmap.x, (*perso).posmap.y, (*marcel).posmap.x, (*marcel).posmap.y, &((*perso).face)))
		{
			(*pnjptr) = marcel;
			text = "bienvenu visiteur";
			(*speech) = true;
		}
		break;
	case 1:
		if (istalkingPNJ((*perso).posmap.x, (*perso).posmap.y, (*gerard).posmap.x, (*gerard).posmap.y, &((*perso).face)))
		{
			(*pnjptr) = gerard;
			text = "voulez vous soigner vos pokemon ?  OUI (Y)   NON (N) ";
			(*speech) = true;
		}

		else if (istalkingPNJ((*perso).posmap.x, (*perso).posmap.y, (*trans).posmap.x, (*trans).posmap.y, &((*perso).face)))
		{
			(*pnjptr) = trans;
			text = "Selectioner le pkm de votre equipe a changer avec celui du pokedexe";
			(*speech) = true;
		}
		break;

	case 2:
		if (istalkingPNJ((*perso).posmap.x, (*perso).posmap.y, (*hubert).posmap.x, (*hubert).posmap.y, &((*perso).face)))
		{
			(*pnjptr) = hubert;
			text = "Vous disposez de "+ inttostring(tune)+" tunes que voulez vous acheter ?";
			(*venteshop) = true;
			(*speech) = true;
		}
		break;
	default:
		break;
	}
	(*(*pnjptr)).settexte(text);
}

std::string inttostring(int entier) 
{
	std::ostringstream oss;
	oss << std::setw(3) << std::setfill('0') << entier;
	return oss.str();
	/*
	std::string V("");
	char cent = entier / 100 + 48;
	char diz = entier / 10 % 10 + 48;
	char uni = entier % 10 + 48;
	std::string viestr(V + cent + diz + uni);
	return viestr;
	*/
}

std::string pokemonTypeToString(PokemonType t) {
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

void affpokedexe(sf::RenderWindow* window, Pokedeco pokedeco, Pokedex* monpokedex, int i, especepokemon bestiaire[])
{
	std::string genre1;
	int num;
	pokemon tmp1;
	int nbmax = 6; //affichage max de pokemon

	(*window).draw(pokedeco.Sfondaff);

	if ((*monpokedex).getnbpokemon() < 6) { nbmax = (*monpokedex).getnbpokemon(); }

	for(int j =0; j<nbmax;j++)
	{
		if (i + j < (*monpokedex).getnbpokemon()) // i represente le pokemon de debut que l'on affiche et j les 6 pkm a afficher donc i < nb pokemon
		{
			tmp1 = (*monpokedex).getpokemon(j + i);
			num = chercher(tmp1.getnom(), bestiaire);
			if (tmp1.getgenre() == 1) { genre1 = "male"; }
			else if (tmp1.getgenre() == 2) { genre1 = "femmelle"; }
			else { genre1 = "neutre"; }
			pokedeco.textnompkm[j].setString("nom : " + tmp1.getnom());
			pokedeco.textgenrepkm[j].setString("genre : " + genre1);
			pokedeco.textnivpkm[j].setString("niveau : " + inttostring(tmp1.getniveau()));
			pokedeco.textpuisspkm[j].setString("force : " + inttostring(tmp1.getpuissance()));
			pokedeco.textpvpkm[j].setString("vie : " + inttostring(tmp1.getPV()));
			pokedeco.textpvactpkm[j].setString("vie act : " + inttostring(tmp1.getactPV()));
			pokedeco.textstadepkm[j].setString("stade : " + inttostring(tmp1.getstade()));
			pokedeco.texttypepkm[j].setString("type : " + pokemonTypeToString(bestiaire[num].type));
			pokedeco.textxppkm[j].setString("XP : " + inttostring(tmp1.getXP()));
			
			(*window).draw(pokedeco.textgenrepkm[j]);
			(*window).draw(pokedeco.textnivpkm[j]);
			(*window).draw(pokedeco.textnompkm[j]);
			(*window).draw(pokedeco.textpuisspkm[j]);
			(*window).draw(pokedeco.textpvactpkm[j]);
			(*window).draw(pokedeco.textpvpkm[j]);
			(*window).draw(pokedeco.textstadepkm[j]);
			(*window).draw(pokedeco.texttypepkm[j]);
			(*window).draw(pokedeco.textxppkm[j]);
		}
	}
}

void inipokedexe(Pokedex* pokedex, char* labeltype[], especepokemon bestiraire[])
{
	pokemon a;
	a.setnom("Bulbasaur");
	a.setXP(0);
	a.setpuissance(25);
	a.setstade(1);
	a.setPV(400);
	a.setactPV(a.getPV());
	a.setgenre(femmelle);
	a.setniveau(0);
	a.setatt1("charge");
	a.setatt2("...");
	a.setatt3("...");
	a.setatt4("...");
	a.setdgt1(60);
	a.setdgt2(80);
	a.setdgt3(100);
	a.setdgt4(120);

	pokemon b;
	b.setnom("Charmander");
	b.setXP(0);
	b.setpuissance(50);
	b.setstade(1);
	b.setPV(200);
	b.setactPV(b.getPV());
	b.setgenre(male);
	b.setniveau(0);
	b.setatt1("charge");
	b.setatt2("...");
	b.setatt3("...");
	b.setatt4("...");
	b.setdgt1(60);
	b.setdgt2(80);
	b.setdgt3(100);
	b.setdgt4(120);

	pokemon c;
	c.setnom("Squirtle");
	c.setXP(0);
	c.setpuissance(35);
	c.setstade(1);
	c.setPV(150);
	c.setactPV(c.getPV());
	c.setgenre(neutre);
	c.setniveau(0);
	c.setatt1("charge");
	c.setatt2("...");
	c.setatt3("...");
	c.setatt4("...");
	c.setdgt1(60);
	c.setdgt2(80);
	c.setdgt3(100);
	c.setdgt4(120);

	insertPokemon(&pokedex, a);
	insertPokemon(&pokedex, b);
	insertPokemon(&pokedex, c);

}

void inipnj(PNJ* marcel, PNJ* gerard, PNJ* hubert, PNJ* trans) 
{
	(*marcel).posmap.x = 11;
	(*marcel).posmap.y = 11;
	(*marcel).setID(0);

	(*gerard).posmap.x = 22;
	(*gerard).posmap.y = 12;
	(*gerard).Sperso.setColor(sf::Color::Magenta);
	(*gerard).settexte("voulez vous soigner vos pokemon ?  OUI (Y)   NON (N) ");
	(*gerard).setID(1);

	(*trans).posmap.x = 28;
	(*trans).posmap.y = 11;
	(*trans).Sperso.setColor(sf::Color::Green);
	(*trans).settexte("Selectioner le pkm de votre equipe a changer avec celui du pokedexe");
	(*trans).setID(3);

	(*hubert).posmap.x = 22;
	(*hubert).posmap.y = 12;
	(*hubert).Sperso.setColor(sf::Color::Blue);
	(*hubert).settexte("voulez vous acheter des pokeball ?  OUI (Y)   NON (N) ");
	(*hubert).setID(2);
}

void majpkmcmbt(pokemon* pkmcmbt, Pokedex* equipe, int IDpkmcmbt) 
{
	pokemon* tmp = equipe->getmespokemons();
	tmp[IDpkmcmbt].setPV(pkmcmbt->getPV());
	tmp[IDpkmcmbt].setactPV(pkmcmbt->getactPV());
	tmp[IDpkmcmbt].setXP(pkmcmbt->getXP());
	tmp[IDpkmcmbt].setniveau(pkmcmbt->getniveau());
	tmp[IDpkmcmbt].setpuissance(pkmcmbt->getpuissance());
	tmp[IDpkmcmbt].setatt1(pkmcmbt->getatt1());
	tmp[IDpkmcmbt].setatt2(pkmcmbt->getatt2());
	tmp[IDpkmcmbt].setatt3(pkmcmbt->getatt3());
	tmp[IDpkmcmbt].setatt4(pkmcmbt->getatt4());
	tmp[IDpkmcmbt].setstade(pkmcmbt->getstade());
	tmp[IDpkmcmbt].setnom(pkmcmbt->getnom());
}

void soincntpkm(Pokedex* equipe) 
{
	pokemon* tmp = equipe->getmespokemons();
	int nbmax = equipe->getnbpokemon();
	for (int i = 0; i < nbmax; i++) {
		tmp[i].setactPV(tmp[i].getPV());
	}
}

void majvente(Shopdeco* shopdeco, int IDobjvente) 
{
	(*shopdeco).textpokeballx1.setStyle(sf::Text::Regular);
	(*shopdeco).textpokeballx10.setStyle(sf::Text::Regular);
	(*shopdeco).textpotionx1.setStyle(sf::Text::Regular);
	(*shopdeco).textpotionx10.setStyle(sf::Text::Regular);
	switch (IDobjvente)
	{
	case 0:
		(*shopdeco).textpokeballx1.setStyle(sf::Text::Bold);
		break;

	case 1:
		(*shopdeco).textpokeballx10.setStyle(sf::Text::Bold);
		break;

	case 2 :
		(*shopdeco).textpotionx1.setStyle(sf::Text::Bold);
		break;

	case 3 :
		(*shopdeco).textpotionx10.setStyle(sf::Text::Bold);
		break;

	default:
		break;
	}
}

bool attraperpkmsav(float ratiopv, Pokedex** stocage, pokemon* pkmsav) 
{
	float capture = (random_at_most(10000) % 100);
	if (capture > ratiopv*100) { insertPokemon(stocage, *pkmsav); std::cout << "pkmcapturer" << std::endl; return true; }
	else { return false; }
}

void affnoircmbt(sf::RenderWindow* window, sf::Sprite fnoir) 
{
	unsigned int tempo = 10;

	for (int k = 0; k < 19; k++)
	{
		for (int i = k; i < 49-k; i++)
		{		
			fnoir.setPosition(i*16, k*16);
			window->draw(fnoir);
			window->display();
			window->draw(fnoir);
			window->display();
			std::this_thread::sleep_for(std::chrono::microseconds(tempo));
		}
		for (int j = k; j < 36-k; j++)
		{
			fnoir.setPosition((49-k)*16, j*16);
			window->draw(fnoir);
			window->display();
			window->draw(fnoir);
			window->display();
			std::this_thread::sleep_for(std::chrono::microseconds(tempo));
		}
		for (int i = 49-k; i > 0+k; i--)
		{
			fnoir.setPosition(i*16, (36-k)*16);
			window->draw(fnoir);
			window->display();
			window->draw(fnoir);
			window->display();
			std::this_thread::sleep_for(std::chrono::microseconds(tempo));
		}
		for (int j = 36-k; j > 0+k; j--)
		{
			fnoir.setPosition((0+k)*16, j*16);
			window->draw(fnoir);
			window->display();
			window->draw(fnoir);
			window->display();
			std::this_thread::sleep_for(std::chrono::microseconds(tempo));
		}
	}
}

void affnoircmbt2(sf::RenderWindow* window, sf::Sprite fnoir, Map* mapptr, bool speech, sf::Sprite herbe, sf::Sprite fond, sf::Sprite rien, sf::Sprite arbre, Perso perso, sf::Text texte, Bull bulle) 
{
	unsigned int tempo = 10000;

	for (int k = 1; k < 19; k++)
	{
		window->clear();
		affmapgeneral(window, mapptr, speech, herbe, fond, rien, arbre, perso, texte, bulle, k - 1, k - 1, k - 1, k);
		window->display();
		std::this_thread::sleep_for(std::chrono::microseconds(tempo));
		window->clear();
		affmapgeneral(window, mapptr, speech, herbe, fond, rien, arbre, perso, texte, bulle, k, k - 1, k - 1, k);
		window->display();
		std::this_thread::sleep_for(std::chrono::microseconds(tempo));
		window->clear();
		affmapgeneral(window, mapptr, speech, herbe, fond, rien, arbre, perso, texte, bulle, k, k - 1, k, k);
		window->display();
		std::this_thread::sleep_for(std::chrono::microseconds(tempo));
		window->clear();
		affmapgeneral(window, mapptr, speech, herbe, fond, rien, arbre, perso, texte, bulle, k, k, k, k);
		window->display();
		std::this_thread::sleep_for(std::chrono::microseconds(tempo));
	}
}

void affcmbtatt(sf::RenderWindow* window, Combatdeco* cmbtdeco, sf::Sprite Spkmsav, sf::Sprite Spkm, EffectAtt* effect, std::string attstr, sf::Time time)
{
	int tempo = 100;
	sf::Sprite Spkmattquer; //sprite temporaire pour les animation du pkm attaquer
	Spkmattquer.setOrigin(0, 0);
	Spkmattquer.setScale(1, 1);
	float i = time.asMilliseconds()/100;
	if (i >= 20) { i = i - 20; }

	if (attstr == "chargeB")
	{
		if (i <10) { effect->Sattaque.setScale(0.1*i, 0.1*i); }
		if (i > 10) { effect->Sattaque.setScale(0.1*(i - 10), 0.1*(i - 10)); } //double animation
		afffondcmbt(window,cmbtdeco,Spkmsav,Spkm);
		window->draw(effect->Sattaque);
	}
	else if (attstr == "chargeF")
	{
		if (i<10) { effect->Sattaque.setScale(0.1*i, 0.1*i); }                //double animation
		if (i > 10) { effect->Sattaque.setScale(0.1*(i - 10), 0.1*(i - 10)); }
		afffondcmbt(window, cmbtdeco, Spkmsav, Spkm);
		window->draw(effect->Sattaque);
	}
	else if (attstr == "rushB")
	{
		afffondcmbt(window, cmbtdeco, Spkmsav, Spkm);
		if ((int)i % 2 == 0) { window->draw(effect->Sattaque); }
	}
	else if (attstr == "rushF")
	{
		afffondcmbt(window, cmbtdeco, Spkmsav, Spkm);
		if ((int)i % 2 == 0) { window->draw(effect->Sattaque); }
	}
	else if (attstr == "comboB")
	{
			if ((int)i % 2 == 0) { effect->Sattaque.setTexture(effect->Tcombo_1); }
			else { effect->Sattaque.setTexture(effect->Tcombo_2); }
			if ((i >= 2) && (i < 4)) 
			{
				effect->Sattaque.move(75, 0);
				effect->Sattaque.setScale(1, 1);
			}
			else if ((i >= 4) && (i < 6))
			{
				effect->Sattaque.move(-150, 0);
				effect->Sattaque.setScale(1.25, 1.25);
			}
			else if ((i >= 6) && (i < 8))
			{
				effect->Sattaque.move(75, -75);
				effect->Sattaque.setScale(1.5, 1.5);
			}
			else if ((i >= 8) && (i < 10))
			{
				effect->Sattaque.move(0, 150);
				effect->Sattaque.setScale(1.75, 1.75);
			}
			else if (i >= 10) 
			{
				effect->Sattaque.setScale(2, 2);
				effect->Sattaque.setColor(sf::Color::Color(255, 0, 0, 255));
			}
			afffondcmbt(window, cmbtdeco, Spkmsav, Spkm);
			window->draw(effect->Sattaque);
		
	}
	else if (attstr == "comboF")
	{
		afffondcmbt(window, cmbtdeco, Spkmsav, Spkm);
		if ((int)i % 2 == 0) { window->draw(effect->Sattaque); }
	}
	else if (attstr == "feuballB") 
	{
		afffondcmbt(window, cmbtdeco, Spkmsav, Spkm);
		if (i < 5)
		{
			if ((int)i % 2 == 0) { effect->Sattaque2.setTexture(effect->Tboulefeu1, true); }
			else { effect->Sattaque2.setTexture(effect->Tboulefeu2, true); }
			effect->Sattaque2.setScale(0.3*i, 0.3*i);
			window->draw(effect->Sattaque2);
		}
		else if (i<10)
		{
			effect->Sattaque.move(40 * (i-5), -28 * (i-5));
			window->draw(effect->Sattaque);
		}
		else
		{
			effect->Sattaque1.scale(0.2*(i - 10), 0.2*(i - 10));
			window->draw(effect->Sattaque1);
		}
	}
	else if (attstr == "feuballF") 
	{
		afffondcmbt(window, cmbtdeco, Spkmsav, Spkm);
		if (i < 5)
		{
			if ((int)i % 2 == 0) { effect->Sattaque2.setTexture(effect->Tboulefeu1, true); }
			else { effect->Sattaque2.setTexture(effect->Tboulefeu2, true); }
			effect->Sattaque2.setScale(0.3*i, 0.3*i);
			window->draw(effect->Sattaque2);
		}
		else if (i<10)
		{
			effect->Sattaque.move(-40 * (i-5), 28 * (i-5));
			window->draw(effect->Sattaque);
		}
		else
		{
			effect->Sattaque1.scale(0.2*(i - 10), 0.2*(i - 10));
			window->draw(effect->Sattaque1);
		}
	}
	else if (attstr == "feuburn")
	{
		afffondcmbt(window, cmbtdeco, Spkmsav, Spkm);
		if ((int)i % 2 == 1) { effect->Sattaque.setTexture(effect->Tfeu_burn_2); }
		else { effect->Sattaque.setTexture(effect->Tfeu_burn_1); }
		window->draw(effect->Sattaque);
	}
	else if (attstr == "feuexplode")
	{
		effect->Sattaque.setScale(0.5*i, 0.5*i);
		afffondcmbt(window, cmbtdeco, Spkmsav, Spkm);
		window->draw(effect->Sattaque);
	}
	else if (attstr == "ecrasemenB")
	{
		Spkmattquer = Spkmsav;
		Spkmattquer.setOrigin(118,0);
		Spkmattquer.setPosition(Spkmsav.getPosition().x + 118, Spkmsav.getPosition().y + (176 / 20)*i); //the scale make the bottom closer to the top but the origin is on the top so we need to move the sprite downward
		Spkmattquer.setScale(1,(1.f - i/20.f));//reduce the scale of the pkm 
		window->draw(cmbtdeco->Sfondcmbt);
		window->draw(cmbtdeco->textnompkm);
		window->draw(cmbtdeco->textnompkmsav);
		window->draw(cmbtdeco->textviepkm);
		window->draw(cmbtdeco->textviepkmsav);
		window->draw(cmbtdeco->Sbarrevie);
		window->draw(cmbtdeco->Sbarreviepkmsav);
		window->draw(cmbtdeco->comm1);
		window->draw(cmbtdeco->comm2);
		window->draw(Spkmattquer);
		window->draw(Spkm);
	}
	else if (attstr == "ecrasemenF")
	{
		Spkmattquer = Spkm;
		Spkmattquer.setOrigin(118,0);
		Spkmattquer.setPosition(Spkm.getPosition().x + 118, Spkm.getPosition().y + (176 / 20)*i);
		Spkmattquer.setScale(1, (1.f - i / 20.f));//reduce the scale of the pkm 
		window->draw(cmbtdeco->Sfondcmbt);
		window->draw(cmbtdeco->textnompkm);
		window->draw(cmbtdeco->textnompkmsav);
		window->draw(cmbtdeco->textviepkm);
		window->draw(cmbtdeco->textviepkmsav);
		window->draw(cmbtdeco->Sbarrevie);
		window->draw(cmbtdeco->Sbarreviepkmsav);
		window->draw(cmbtdeco->comm1);
		window->draw(cmbtdeco->comm2);
		window->draw(Spkmattquer);
		window->draw(Spkmsav);
	}
	else if (attstr == "Catch")
	{
		if ((i>5)&&(i < 15) )
		{
			effect->Sattaque.move(25 * (i-5), 0);
			effect->Sattaque1.move(-25 * (i-5), 0);
		}
		else if (i>=15){
			effect->Sattaque.move(25 * 10, 0);
			effect->Sattaque1.move(-25 * 10, 0);
		}
		afffondcmbt(window, cmbtdeco, Spkmsav, Spkm);
		window->draw(effect->Sattaque);
		window->draw(effect->Sattaque1);
	}
	else if (attstr == "Furie")
	{
		afffondcmbt(window, cmbtdeco, Spkmsav, Spkm);
		if ((int)i%2 == 0) { effect->Sattaque.move(10, -10);}
		else { effect->Sattaque2.move(-10, 10); }
		if ((int)i % 3 == 0) 
		{ 
			effect->Sattaque2.setTexture(effect->Tcharge, true);
			effect->Sattaque2.setScale(0.5, 0.5);
			effect->Sattaque2.setColor(sf::Color::Black);
			window->draw(effect->Sattaque); 
			window->draw(effect->Sattaque2); 
		}
		if ((int)i % 3 == 1) 
		{ 
			effect->Sattaque.setTexture(effect->Tcharge, true);
			effect->Sattaque.setScale(0.5, 0.5);
			effect->Sattaque.setColor(sf::Color::Black);
			window->draw(effect->Sattaque1); 
			window->draw(effect->Sattaque);
		}
		if ((int)i % 3 == 2) 
		{ 
			effect->Sattaque1.setTexture(effect->Tcharge, true);
			effect->Sattaque1.setScale(0.5, 0.5);
			effect->Sattaque1.setColor(sf::Color::Black);
			window->draw(effect->Sattaque2); 
			window->draw(effect->Sattaque1);
		}

	}
	else if (attstr == "OnePunch")
	{
		
		effect->Sattaquefond.move(-120 * i, 0);
		if (i<15){
			effect->Sattaque1.setScale(4.f - (i / 5.f), 4.f - (i / 5.f));
			window->draw(cmbtdeco->Sfondcmbt);
			window->draw(cmbtdeco->textnompkm);
			window->draw(cmbtdeco->textnompkmsav);
			window->draw(cmbtdeco->textviepkm);
			window->draw(cmbtdeco->textviepkmsav);
			window->draw(cmbtdeco->Sbarrevie);
			window->draw(cmbtdeco->Sbarreviepkmsav);
			window->draw(effect->Sattaquefond);
			window->draw(effect->Sattaque1);
			window->draw(Spkmsav);
			window->draw(Spkm);
			window->draw(cmbtdeco->comm1);
			window->draw(cmbtdeco->comm2);
		}
		else 
		{
			if ((int)i % 2 == 0) { effect->Sattaque2.setTexture(effect->Tredstars, true); }
			else { effect->Sattaque2.setTexture(effect->Tyellowstars, true); }
			window->draw(cmbtdeco->Sfondcmbt);
			window->draw(cmbtdeco->textnompkm);
			window->draw(cmbtdeco->textnompkmsav);
			window->draw(cmbtdeco->textviepkm);
			window->draw(cmbtdeco->textviepkmsav);
			window->draw(cmbtdeco->Sbarrevie);
			window->draw(cmbtdeco->Sbarreviepkmsav);
			window->draw(effect->Sattaquefond);
			window->draw(effect->Sattaque2);
			window->draw(Spkmsav);
			window->draw(Spkm);
			window->draw(cmbtdeco->comm1);
			window->draw(cmbtdeco->comm2);
			window->draw(effect->Sattaque1);
		}
	}
	else if (attstr == "spikeB")
	{
		afffondcmbt(window, cmbtdeco, Spkmsav, Spkm);
		if (i < 10)
		{
			effect->Sattaque.move(30.f*i, -20.f*i);
		}
		else
		{
			effect->Sattaque.move(30.f*(i - 10), -20.f*(i - 10));
		}
		window->draw(effect->Sattaque);
	}
	else if (attstr == "spikeF")
	{
		afffondcmbt(window, cmbtdeco, Spkmsav, Spkm);
		if (i < 10)
		{
			effect->Sattaque.move(-30.f*i, 20.f*i);
		}
		else
		{
			effect->Sattaque.move(-30.f*(i - 10), 20.f*(i - 10));
		}
		window->draw(effect->Sattaque);
	}
	else if (attstr == "volB") 
	{
		window->draw(cmbtdeco->Sfondcmbt);
		window->draw(cmbtdeco->textnompkm);
		window->draw(cmbtdeco->textnompkmsav);
		window->draw(cmbtdeco->textviepkm);
		window->draw(cmbtdeco->textviepkmsav);
		window->draw(cmbtdeco->Sbarrevie);
		window->draw(cmbtdeco->Sbarreviepkmsav);
		window->draw(effect->Sattaquefond);
		window->draw(Spkmsav);
		if (i < 5) 
		{ 
			window->draw(effect->Sattaque); 
		}
		else if (i<10) 
		{ 
			effect->Sattaque1.move(0, -92 * (i-5));
			window->draw(effect->Sattaque1); 
		}
		else if (i<15) 
		{ 
			effect->Sattaque1.setOrigin(50, 100);
			effect->Sattaque1.setPosition(590, -200);
			effect->Sattaque1.setRotation(180);
			effect->Sattaque1.move(0, 80 * (i-10));
			window->draw(effect->Sattaque1); 
		}
		else 
		{
			effect->Sattaque2.setScale(0.4*(i-15), 0.4*(i-15));
			window->draw(effect->Sattaque2);
		}
		window->draw(cmbtdeco->comm1);
		window->draw(cmbtdeco->comm2);
		
	}
	else if (attstr == "volF")
	{
		window->draw(cmbtdeco->Sfondcmbt);
		window->draw(cmbtdeco->textnompkm);
		window->draw(cmbtdeco->textnompkmsav);
		window->draw(cmbtdeco->textviepkm);
		window->draw(cmbtdeco->textviepkmsav);
		window->draw(cmbtdeco->Sbarrevie);
		window->draw(cmbtdeco->Sbarreviepkmsav);
		window->draw(effect->Sattaquefond);
		window->draw(Spkm);
		if (i < 5)
		{
			window->draw(effect->Sattaque);
		}
		else if (i<10)
		{
			effect->Sattaque1.move(0, -80 * (i-5));
			window->draw(effect->Sattaque1);
		}
		else if (i<15)
		{
			effect->Sattaque1.setOrigin(50, 100);
			effect->Sattaque1.setPosition(140, -130);
			effect->Sattaque1.setRotation(180.f);
			effect->Sattaque1.move(0, 92 * (i-10));
			window->draw(effect->Sattaque1);
		}
		else
		{
			effect->Sattaque2.setScale(0.4*(i-15), 0.4*(i-15));
			window->draw(effect->Sattaque2);
		}
		window->draw(cmbtdeco->comm1);
		window->draw(cmbtdeco->comm2);

	}
	else if (attstr == "phenixB") 
	{
		afffondcmbt(window, cmbtdeco, Spkmsav, Spkm);
		if (i<2.5) { effect->Sattaque.scale(1.f, -1.f); effect->Sattaque.move(0, 250); }
		else if ((i>5)&&(i<7.5)) { effect->Sattaque.scale(1.f, -1.f); effect->Sattaque.move(0, 250); }
		else if ((i>10) && (i<12.5)) { effect->Sattaque.scale(1.f, -1.f); effect->Sattaque.move(0, 250); }
		else if ((i>15) && (i<17.5)) { effect->Sattaque.scale(1.f, -1.f); effect->Sattaque.move(0, 250); }
		effect->Sattaque.move(100 * i, 0);
		window->draw(effect->Sattaque);
	}
	else if (attstr == "phenixF") 
	{
		afffondcmbt(window, cmbtdeco, Spkmsav, Spkm);
		if ((int)i % 2 == 0) { effect->Sattaque.scale(1.f, -1.f); }
		effect->Sattaque.move(-100 * i, 0);
		window->draw(effect->Sattaque);
	}
	else if (attstr == "spore")
	{
		afffondcmbt(window, cmbtdeco, Spkmsav, Spkm);
		if ((int)i % 3 == 0) { effect->Sattaque.setTexture(effect->Tspore1, true); }
		else if ((int)i % 3 == 1) { effect->Sattaque.setTexture(effect->Tspore2, true); }
		else { effect->Sattaque.setTexture(effect->Tspore3, true); }
		window->draw(effect->Sattaque);
	}
	else if (attstr == "mudshot") 
	{
		afffondcmbt(window, cmbtdeco, Spkmsav, Spkm);
		if ((int)i % 3 == 0) { effect->Sattaque.setTexture(effect->Tmudshot1, true); }
		else if ((int)i % 3 == 1) { effect->Sattaque.setTexture(effect->Tmudshot2, true); }
		else { effect->Sattaque.setTexture(effect->Tmudshot3, true); }
		window->draw(effect->Sattaque);
	}
	else if (attstr == "magicleavesB")
	{
		afffondcmbt(window, cmbtdeco, Spkmsav, Spkm);
		if ((int)i % 3 == 0) { effect->Sattaque.setTexture(effect->Tmleave1); }
		else if ((int)i % 3 == 1) { effect->Sattaque.setTexture(effect->Tmleave2); }
		else { effect->Sattaque.setTexture(effect->Tmleave3); }

		if ((int)i % 4 == 0) { effect->Sattaque1.setTexture(effect->Tmstar1); }
		else if ((int)i % 4 == 1) { effect->Sattaque1.setTexture(effect->Tmstar2); }
		else if ((int)i%4 == 2){ effect->Sattaque1.setTexture(effect->Tmstar3); }
		else { effect->Sattaque1.setTexture(effect->Tmstar4); }

		for (int j = 0; j < i; j++) 
		{
			effect->Sattaque.move(20 *(i-j), -14 * (i -j));
			window->draw(effect->Sattaque);
			effect->Sattaque.move(0, 50);
			window->draw(effect->Sattaque);
			effect->Sattaque.move(0, -50);
		}
		if (i > 5)
		{ 
			effect->Sattaque1.move(30 * ((int)i % 2), -50 * ((int)i % 2));
			window->draw(effect->Sattaque1); 
		}
		if ((i>10)&&(i<18)){
			effect->Sattaque1.move(-70, -20);
			window->draw(effect->Sattaque1);
		}
		
	}
	else if (attstr == "magicleavesF")
	{
		afffondcmbt(window, cmbtdeco, Spkmsav, Spkm);
		if ((int)i % 3 == 0) { effect->Sattaque.setTexture(effect->Tmleave1); }
		else if ((int)i % 3 == 1) { effect->Sattaque.setTexture(effect->Tmleave2); }
		else { effect->Sattaque.setTexture(effect->Tmleave3); }

		if ((int)i % 4 == 0) { effect->Sattaque1.setTexture(effect->Tmstar1); }
		else if ((int)i % 4 == 1) { effect->Sattaque1.setTexture(effect->Tmstar2); }
		else if ((int)i % 4 == 2) { effect->Sattaque1.setTexture(effect->Tmstar3); }
		else { effect->Sattaque1.setTexture(effect->Tmstar4); }

		for (int j = 0; j < i; j++)
		{
			effect->Sattaque.move(-20 * (i - j), 14 * (i - j));
			window->draw(effect->Sattaque);
			effect->Sattaque.move(0, 50);
			window->draw(effect->Sattaque);
			effect->Sattaque.move(0, -50);
		}
		if (i > 5)
		{
			effect->Sattaque1.move(30 * ((int)i % 2), -50 * ((int)i % 2));
			window->draw(effect->Sattaque1);
		}
		if ((i>10) && (i<18)) {
			effect->Sattaque1.move(-70, -20);
			window->draw(effect->Sattaque1);
		}
	}
	else if (attstr == "rock") 
	{
		afffondcmbt(window, cmbtdeco, Spkmsav, Spkm);
		if(i<5)
		{
			effect->Sattaque.setPosition(effect->Sattaque.getPosition().x, effect->Sattaque.getPosition().y - 200);
			effect->Sattaque.move(0, 40 * i);
			window->draw(effect->Sattaque);
		}
		else if (i < 15)
		{
			effect->Sattaque1.setScale(0.125*(i-5), 0.125*(i-5));
			window->draw(effect->Sattaque);
			window->draw(effect->Sattaque1);
		}
		else 
		{
			effect->Sattaque2.setPosition(effect->Sattaque.getPosition().x+100-(20*(i-15)), effect->Sattaque.getPosition().y+100 - (20 * (i - 15)));
			window->draw(effect->Sattaque2);
			effect->Sattaque2.setPosition(effect->Sattaque.getPosition().x+100 + (20 * (i - 15)), effect->Sattaque.getPosition().y+100 - (20 * (i - 15)));
			window->draw(effect->Sattaque2);
			effect->Sattaque2.setPosition(effect->Sattaque.getPosition().x+100 + (20 * (i - 15)), effect->Sattaque.getPosition().y+100 + (20 * (i - 15)));
			window->draw(effect->Sattaque2);
			effect->Sattaque2.setPosition(effect->Sattaque.getPosition().x+100 - (20 * (i - 15)), effect->Sattaque.getPosition().y+100 + (20 * (i - 15)));
			window->draw(effect->Sattaque2);
		}
	}
	else if (attstr == "rockfallB")
	{
		afffondcmbt(window, cmbtdeco, Spkmsav, Spkm);
		if ((i>5) && (i < 10))
		{
			effect->Sattaque.move(0, 40 * (i - 5));
		}
		window->draw(effect->Sattaque);
	}
	else if (attstr == "rockfallF") 
	{
		afffondcmbt(window, cmbtdeco, Spkmsav, Spkm);
		if ((i>5) && (i < 15))
		{
			effect->Sattaque.move(0, 42 * (i - 5));
		}
		window->draw(effect->Sattaque);
	}
	else if (attstr == "Lrock") 
	{
		afffondcmbt(window, cmbtdeco, Spkmsav, Spkm);
		if ((int)i % 3 == 2) { window->draw(effect->Sattaque1); }
		if (i<3){ effect->Sattaque.move(-200 + 100 * i, 0); } //gauche
		else if (i<6){effect->Sattaque.move(+200 - 100 * (i-3), +200 - 100 * (i-3));} //diag bas droit
		else if (i<9) { effect->Sattaque.move(+200 - 100 * (i-6), 0); }//droit
		else if (i<12) { effect->Sattaque.move(0, -200 + 100 * (i - 9)); }//haut
		else if (i<15){ effect->Sattaque.move(-200 + 100 * (i - 12), +200 - 100 * (i - 12)); } //diag bas gauche
		else if (i<18) { effect->Sattaque.move(+200 - 100 * (i - 15), -200 + 100 * (i - 15)); }//diag haut droite
		else if (i<20) { effect->Sattaque.move(-200 + 100 * (i - 18), -200 + 100 * (i - 18)); }//diag haut gauche
		window->draw(effect->Sattaque);
	}
	else 
	{
		afffondcmbt(window, cmbtdeco, Spkmsav, Spkm);
	}
}

void afffondcmbt(sf::RenderWindow* window, Combatdeco* cmbtdeco, sf::Sprite Spkmsav, sf::Sprite Spkm)
{
	window->draw(cmbtdeco->Sfondcmbt);
	window->draw(cmbtdeco->textnompkm);
	window->draw(cmbtdeco->textnompkmsav);
	window->draw(cmbtdeco->textviepkm);
	window->draw(cmbtdeco->textviepkmsav);
	window->draw(cmbtdeco->Sbarrevie);
	window->draw(cmbtdeco->Sbarreviepkmsav);
	window->draw(Spkmsav);
	window->draw(Spkm);
	window->draw(cmbtdeco->comm1);
	window->draw(cmbtdeco->comm2);
}

std::string majeffectatt(Combatdeco* cmbtdeco, float mult, pokemon* pkm, unsigned int dgtatt, float dommage, EffectAtt* effect, std::string type, char sens)
{
	std::string phrase;
	std::string phrase2;
	std::string att;
	std::string comm;
	std::string attstr;

	if (dgtatt == 60) { att = pkm->getatt1(); }
	else if (dgtatt == 80) { att = pkm->getatt2(); }
	else if (dgtatt == 100) { att = pkm->getatt3(); }
	else if (dgtatt == 120) { att = pkm->getatt4(); }
	else{}
	if (att == "...") { att = "une attaque"; } //pour le pkm sauvage
	if (mult == 0.5) { comm = "Ce n'est pas tres efficace ..."; }
	else if (mult == 1.5) { comm = "C'est tres efficace !!!"; }
	else { comm = ""; }
	
	phrase = pkm->getnom() + " lance " + att + " et lui inflige " + floattostring(dommage) + " degats. ";
	phrase2 = comm;
	if (dgtatt == 0) //soin via popo
	{
		phrase = pkm->getnom() + " utilise une potion et recupere 300 Pv ";
		phrase2 = "";
	}

	cmbtdeco->majtextecmbtatt(phrase, phrase2);
	
	attstr = majspriteatt(effect, type, dgtatt, sens);
	return attstr;
}