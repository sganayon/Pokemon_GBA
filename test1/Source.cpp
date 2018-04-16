#include <SFML/Graphics.hpp>
#include "pokemon.h"
#include"pokedex.h"
#include "sprite.h"
#include"player.h"
#include "carte.h"
#include<iostream>
#include<string.h>
#include "util.h"
#include "fct.h"
#include"sauvegarde.h"
#include "combat.h"

int main() //(niv * 0.4 +2)*force*dgtatt/(defadverse * 50) +2 
{
	srand(time(nullptr));
	sf::RenderWindow window(sf::VideoMode(800, 592), "POKEMON");

	bool isattackable = false;
	bool speech = false;
	bool chgmap = false; 
	bool menu = true;
	bool cmbt = false;
	bool cmbtatt = false;
	bool P1IsDead = false;
	bool EquiIsDead = false;
	bool venteshop = false;
	bool echange = false;
	bool cmbtatttrigger = false;
	bool battel = false;

	char choixmenucmbt1 = 'M'; //selectionne l'affichage du menu de combat
	char pagemenu = 'I'; //selectionne l'affichage du menu

	int IDmap = 0; // 0 = general, 1 = CentrePokemon, 2 = Shoppokemon, 3 = maisonV
	int IDlignemenu = 0; // quelle ligne l'utilisateur a selectioner
	int IDlignemenucmbt = 0; //ligne select par le joueur en cmbt
	int IDcolonemenucmbt = 0; //colone select par le joueur en cmbt
	int rangpkmaff = 0; //entier selectionnant le premier pkm a afficher
	int IDlignemenuini = 0; //quelle ligne l'utilisateur a selectioner au menu de demmarrage
	int IDpkmequi = 0; //quelle pkm de l'equipe est select pour combattre
	int IDobjvente = 0; //ID de l'objet selectioner lors d'un achat au shop pkm
	int IDpokeechan = 0;//id du pokemon a echanger
	int IDpkmadv = 0; //ID du pokemon de l'adversaire

	sf::Vector2f tscreen(800.f, 592.f);
	sf::Vector2i ini(10, 10); //position initial du perso sur map general
	sf::Vector2i posmapbefore(0, 0);
	sf::Vector2i posmapbat(22, 20);
	sf::Vector2i postmp;
	
	sf::Clock clk;
	sf::Time time;
	sf::Sprite tmp;
	std::string text("Bienvenue visiteur");
	std::string cheminsave("C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/save1.txt");
	std::string attstr("...");

	Herbe herbe;
	Fnoir fnoir;
	Rien rien;
	Fond fond;
	Eau eau;
	Arbre arbre;
	Falaise falaise;
	Menudeco menudeco;
	Combatdeco cmbtdeco;
	CombatPokemon cmbtpkm;
	EffectAtt effect;
	Pokedeco pokedeco;
	CentrePokemon centreP;
	ShopPokemon shopP;
	PorteSortie portesortie;
	Shopdeco shopdeco;
	Perso perso;
	PNJ marcel; //pnj test map general
	PNJ gerard; //pnj cntpkm
	PNJ trans; //pnj d'echange pokdexe equipe
	PNJ hubert; //pnj shppkm
	PNJ* pnjptr = &marcel;
	Bull bulle; //
	Map map(rien,100,100);
	Map mapCntPkm(rien, 50, 37); // taille ecrant
	Map mapShpPkm(rien, 50, 37);
	Map* mapptr = &map; //pointeur de map qui pointera sur tel ou tel map suivant IDmap par defaut on est sur la map general

	char* labeltype[18] = { "Normal", "Fighting", "Flying", "Poison", "Ground", "Rock", "Bug", "Ghost", "Steel", "Fire", "Grass", "Water", "Electric", "Psychic", "Ice", "Dragon", "Dark", "Fairy" };
	especepokemon bestiaire[150];
	initbestiaire(bestiaire);
	Pokedex* equipe = new Pokedex(6); //equipe de 6pkm max
	Pokedex* stocagepkm = new Pokedex(10); //stocage ilimiter de pkm
	Pokedex* equipeadv = new Pokedex(6); //equipe adverse
	Ressource* mesressource = new Ressource();
	pokemon pokemonsav = genererPokemon(bestiaire);
	pokemon pokemoncmbtptr;
	hashtable* htab = inithashtable();
	
	std::vector<Adversaire*> alladv; // contient tt les adversaires
	Adversaire* advptr = nullptr; //pointeur qui select l'adversaire
	Adversaire Remis(equipeadv); //pnj agressif
	Remis.posmap.x = 80; Remis.posmap.y = 30;
	alladv.push_back(&Remis);
	map.set(Remis.Sperso, 80, 30);
	map.set(arbre.Sarbre, 79, 30);
	map.set(herbe.Sherbe, 80, 29);

	inipnj(&marcel, &gerard, &hubert, &trans);
	inimapgene(&map, eau.Seau, herbe.Sherbe, arbre.Sarbre, falaise.SfalaisebordR, falaise.SbordterreU, falaise.SbordfalaisemerUR, marcel.Sperso, marcel.posmap.x, marcel.posmap.y, centreP, shopP);
	inimapcntpkm(&mapCntPkm, centreP.SmurCentreP, portesortie.Sportesortie, centreP.SwallRCP, centreP.SwallDCP, centreP.SwallLCP, gerard.Sperso, gerard.posmap.x, gerard.posmap.y, trans.Sperso, trans.posmap.x, trans.posmap.y);
	inimapshppkm(&mapShpPkm, shopP.SmurshopP, portesortie.Sportesortie, shopP.SwallRSP, shopP.SwallDSP, shopP.SwallLSP, hubert.Sperso, hubert.posmap.x, hubert.posmap.y);
	iniequiadv(equipeadv, bestiaire);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))//recupere tout les events de la derniere boucle
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::LostFocus:
				break;

			case sf::Event::KeyPressed:
				if (menu) //on est sur le menu on neutralise les fct de deplacement et autre
				{
					if (pagemenu != 'I') //si on n'est pas en phase de demarrage
					{
						gestionmenu(event, &window, &IDlignemenu, &menu, cheminsave, perso.posmap, posmapbefore, IDmap, &pagemenu, &rangpkmaff, stocagepkm, equipe, mesressource, &echange,bestiaire, &IDpokeechan, &pokemoncmbtptr, IDpkmequi, alladv);
					}
					else 
					{ 
						gestionmenuini(event, &IDlignemenuini,&pagemenu,cheminsave,&perso.posmap,&posmapbefore,&IDmap, stocagepkm,equipe,mesressource,labeltype,bestiaire,&perso, &pokemoncmbtptr, &menu, alladv);
					}
				}
				else if (cmbt) //on est en combat on neutralise le deplacement
				{
					gestionmenucombat(event, &IDlignemenucmbt, &IDcolonemenucmbt, &choixmenucmbt1, &cmbt, &pokemoncmbtptr, &pokemonsav, htab,bestiaire, &P1IsDead,mesressource, &stocagepkm, &window,cmbtdeco,&effect, &cmbtatt, &cmbtpkm, battel);
				}
				else if (venteshop) //neutralise les deplacement pendant la vente
				{
					if (event.key.code == sf::Keyboard::Right)
					{
						if (IDobjvente < 3) { IDobjvente++; } // on a 4 obj en vente
					}
					if (event.key.code == sf::Keyboard::Left)
					{
						if (IDobjvente > 0) { IDobjvente--; }
					}
					if (event.key.code == sf::Keyboard::Y) //on achete
					{
						venteshop = false;
						speech = true;
						switch (IDobjvente)
						{
						case 0 : 
							if (mesressource->gettune() >= 300) 
							{
								mesressource->setpokeball(mesressource->getpokeball() + 1);
								mesressource->settune(mesressource->gettune() - 300);
								(*pnjptr).settexte("Merci d'avoir effectue votre achat, a une prochaine fois !!!");
							}
							else{ (*pnjptr).settexte("Vous n'avez pas assez de tune"); }
							break;

						case 1 :
							if (mesressource->gettune() >= 3000)
							{
								mesressource->setpokeball(mesressource->getpokeball() + 10);
								mesressource->settune(mesressource->gettune() - 3000);
								(*pnjptr).settexte("Merci d'avoir effectue votre achat, a une prochaine fois !!!");
							}
							else { (*pnjptr).settexte("Vous n'avez pas assez de tune"); }
							break;

						case 2 :
							if (mesressource->gettune() >= 200)
							{
								mesressource->setpotion(mesressource->getpotion() + 1);
								mesressource->settune(mesressource->gettune() - 200);
								(*pnjptr).settexte("Merci d'avoir effectue votre achat, a une prochaine fois !!!");
							}
							else { (*pnjptr).settexte("Vous n'avez pas assez de tune"); }
							break;

						case 3:
							if (mesressource->gettune() >= 2000)
							{
								mesressource->setpotion(mesressource->getpotion() + 10);
								mesressource->settune(mesressource->gettune() - 2000);
								(*pnjptr).settexte("Merci d'avoir effectue votre achat, a une prochaine fois !!!");
							}
							else { (*pnjptr).settexte("Vous n'avez pas assez de tune"); }
							break;
						default:
							break;
						}
						IDobjvente = 0;
					}
					if (event.key.code == sf::Keyboard::N) // on part
					{
						IDobjvente = 0;
						venteshop = false;
						speech = true;
						(*pnjptr).settexte("A une prochaine fois !"); 
					}
				}
				else //on est sur une map
				{
					if (event.key.code == sf::Keyboard::D)
					{
						if (perso.posmap.x != 99)//si on est en bordure droite et que l'on veut aller a droite on depasse la map donc on ne bouge pas
						{
							chgmap = colliporte(centreP.SCentrePporte, shopP.SshopPporte, portesortie.Sportesortie, *mapptr, perso, 'R', &IDmap);
							if (!collisions_elem(herbe.Sherbe, rien.Srien, falaise, *mapptr, perso, 'R')) { perso.posmap.x++; isattackable = true; speech = false;}// si l'on bouge on peut de nouveau se faire attaquer
						}
						perso.face = 'R';
					}

					if (event.key.code == sf::Keyboard::Q)
					{
						if (perso.posmap.x != 0) // si l'on est en bordure gauche et que l'on veut aller a gauche on depasse la map donc on ne bouge pas
						{
							chgmap = colliporte(centreP.SCentrePporte, shopP.SshopPporte, portesortie.Sportesortie, *mapptr, perso, 'L', &IDmap);
							if (!collisions_elem(herbe.Sherbe, rien.Srien, falaise, *mapptr, perso, 'L')) { perso.posmap.x--; isattackable = true; speech = false; } // si l'on bouge on peut de nouveau se faire attaquer
						}
						perso.face = 'L';
					}

					if (event.key.code == sf::Keyboard::Z)
					{
						if (perso.posmap.y != 0)
						{
							chgmap = colliporte(centreP.SCentrePporte, shopP.SshopPporte, portesortie.Sportesortie, *mapptr, perso, 'U', &IDmap);
							if (!collisions_elem(herbe.Sherbe, rien.Srien, falaise, *mapptr, perso, 'U')) { perso.posmap.y--; isattackable = true; speech = false; } // si l'on bouge on peut de nouveau se faire attaquer
						}
						perso.face = 'B';
					}

					if (event.key.code == sf::Keyboard::S)
					{
						if (perso.posmap.y != 99)
						{
							chgmap = colliporte(centreP.SCentrePporte, shopP.SshopPporte, portesortie.Sportesortie, *mapptr, perso, 'D', &IDmap);
							if (!collisions_elem(herbe.Sherbe, rien.Srien, falaise, *mapptr, perso, 'D')) { perso.posmap.y++; isattackable = true; speech = false; } // si l'on bouge on peut de nouveau se faire attaquer
						}
						perso.face = 'F';
					}

					
					if (event.key.code == sf::Keyboard::P)
					{
						gestionspeech(IDmap, &perso, &pnjptr, &marcel, &gerard, &hubert, &trans, &speech, &venteshop, mesressource->gettune());
					}
					if (speech)
					{
						if (event.key.code == sf::Keyboard::Y) //accepte la demande du PNJ
						{
							speech = true;
							switch ((*pnjptr).getID())
							{
							case 0: //pnj classique inutile
								break;
							case 1: //pnj centreP soigne pkm
								(*pnjptr).settexte("Et voila tous vos pokemon ont ete soignes !!!");
								soincntpkm(equipe);
								pokemoncmbtptr.setactPV(pokemoncmbtptr.getPV()); // nessecaire pour ne pas reini la vie act par fct majcmbpkm
								P1IsDead = false;
								cmbtpkm.setIsPkmEquiDead(false);
								EquiIsDead = false;
								IDpkmequi = 0;
								pokemoncmbtptr = equipe->getpokemon(0);
								break;
							case 2: //pnj vendeur de pokeboules
								(*pnjptr).settexte("Merci d'avoir effectue votre achat, a une prochaine fois !!!");
								break;
							case 3 : //pnj d'echange equipe/pokedexe
								echange = true;
								menu = true;
								pagemenu = 'E';
								break;
							default:
								break;
							}
						}

						if (event.key.code == sf::Keyboard::N) //refuse la demande du PNJ
						{
							speech = true;
							(*pnjptr).settexte("A une prochaine fois !"); //balec ils diront tt la mm phrase c'est des fucking PNJ
						}
					}
					if (event.key.code == sf::Keyboard::Escape) //on veut afficher le menu
					{
						menu = true;
						pagemenu = 'M';
					}
				}
				break;

			case sf::Event::TextEntered:
				break;

			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Right) { std::cout << "x : " << perso.posmap.x << std::endl << "y : " << perso.posmap.y << std::endl; }
				if (event.mouseButton.button == sf::Mouse::Left) { perso.posmap.x = 78; perso.posmap.y = 29; }
				break;

			default:
				break;
			}
		}

		if ((!cmbt)&&(!battel))// si on est pas en cmbt on check qu'il y en a pas un a declencher, tjr faire avant majposchgmap !!!!!
			launchCmbtBattel(&window, speech, EquiIsDead, battel, isattackable, cmbt, chgmap, mapptr, perso, herbe, rien, arbre, fond, fnoir, bulle, pnjptr, alladv, &advptr, pokemonsav,  pokemoncmbtptr, bestiaire, cmbtdeco, cmbtpkm, ini);

		majvente(&shopdeco, IDobjvente);//gere le gras
		majpkmcmbt(&pokemoncmbtptr, equipe, IDpkmequi);//meta jours les info du pkm de combat
		majmenu(IDlignemenu, &menudeco); //gere le gras
		majmenuini(IDlignemenuini, &menudeco); // gere le gras ds un menu qui n'apparait qu'au demarrage
		majmenucmbt(IDlignemenucmbt, IDcolonemenucmbt, choixmenucmbt1, &cmbtdeco); // gere le gras
		majposchgmap(&chgmap, IDmap, &perso, &posmapbefore, posmapbat); // met a jours la position du perso si il y a chg de map
		perso.setface();//met a jour l'orientation du perso
		if(pagemenu != 'I'){
			pokemoncmbtptr.majsprite(bestiaire[chercher(pokemoncmbtptr.getnom(), bestiaire)].cheminback, bestiaire[chercher(pokemoncmbtptr.getnom(), bestiaire)].cheminface); // met a jour l'image du pkm qui vas combattre
		}//si l'on a pas choisi entre nouvel partie ou charger on ne peut avoir un pkm de combat
		
		cmbtdeco.majtextecmbt(inttostring(mesressource->getpokeball()), inttostring(mesressource->getpotion()));//met a jours le nb de popo et poke dans le menu combat
		if (cmbtatt && !cmbtatttrigger) { cmbtatttrigger = true; clk.restart(); } //restart the clock when an animation begin
		if(cmbtatt){majTextAnnimation(attstr, P1IsDead, cmbtatttrigger,cmbt, cmbtatt, clk, cmbtpkm, cmbtdeco, pokemoncmbtptr, pokemonsav, effect);}
		
		if ((pokemonsav.getactPV() <= 0) && battel && !cmbtatt) //si le pkm de l'adversaire est mort on le switch ou on arrette le combat si il n'en a plus
			switchPkmAdv(battel, cmbt, cmbtatt, IDpkmadv, advptr, pokemonsav, pokemoncmbtptr, cmbtdeco, bestiaire, cmbtpkm);

		if (P1IsDead && !EquiIsDead && !cmbtatt) //si le pkm de l'equipe est mort on le switch ou on arrette le combat et on respawn
			switchPkmEqui(EquiIsDead, P1IsDead, battel, cmbt, cmbtatt, IDpkmequi, equipe, pokemonsav, pokemoncmbtptr, cmbtdeco, bestiaire, cmbtpkm, perso, ini);

		window.clear();
		if (cmbt) // si on est en combat on n'a pas acces au menu
		{
			if (cmbtatt) //si on a declencher une attaque
			{
				affcmbtatt(&window, &cmbtdeco, pokemonsav.SpokeF, pokemoncmbtptr.SpokeB,&effect,attstr, clk.getElapsedTime());
			}
			else { affcmbt(&window, &cmbtdeco, pokemonsav.SpokeF, pokemoncmbtptr.SpokeB, choixmenucmbt1); }
		}
		else if (menu)
		{
			if(pagemenu == 'M'){ affmenus(&window, fond.Sfond, menudeco.Slogo, menudeco.Sfondmenu, menudeco.text0, menudeco.text1, menudeco.text2, menudeco.text3); }
			else if (pagemenu == 'P') { affpokedexe(&window, pokedeco, stocagepkm, rangpkmaff, bestiaire); }
			else if (pagemenu == 'E') { affpokedexe(&window, pokedeco, equipe, IDpokeechan, bestiaire); }
			else if (pagemenu == 'I') { affmenuini(&window, fond.Sfond, menudeco.Slogo, menudeco.Sfondmenu, menudeco.textreini, menudeco.textcont); }
		}
		else
		{
			switch (IDmap)
			{
			case 0: // on est sur la map general
				mapptr = &map;
				affmapgeneral(&window, mapptr, speech, herbe.Sherbe, fond.Sfond, rien.Srien, arbre.Sarbre, perso,(*pnjptr).text, bulle,0,0,0,0);
				break;

			case 1: // on est au centre pokemon
				mapptr = &mapCntPkm;
				affmapcntpkm(&window, mapptr, speech, (*pnjptr).text, rien.Srien, perso, centreP.SfondCentreP, bulle); //fct diff de map general car ici on ne vas pas bouger la map par rapport au perso
				break;

			case 2: // on est au shop pokemon
				mapptr = &mapShpPkm;
				affmapshppkm(&window, mapptr, speech, (*pnjptr).text, rien.Srien, perso, shopP.SfondshopP, bulle, venteshop, shopdeco);
				break;

			default: // si l'on est sur aucune map
				break;
			}
		}
		window.display();
	}
	return 0;
}

// equilibrage du jeux (stats, power up, degat, capture, fuite, money
// rareter pkm -- zone de type
// animation de combat
// afficher nb de pokemon de l'adversaire
// fct insertion deco izi
// echange de pkm en cmbt
// decorer la map
// son
// remove save if corrupt