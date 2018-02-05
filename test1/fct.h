#pragma once
#include <SFML/Graphics.hpp>
#include "sprite.h"
#include"player.h"
#include<iostream>
#include<string.h>
#include"carte.h"
#include "pokemonTypes.h"
#include "bestiaire.h"
#include "pokemon.h"
#include "pokedex.h"
#include"combat.h"

bool collisions_elem(sf::Sprite herbe, sf::Sprite rien, Falaise falaise, Map map, Perso perso, char sens);

void insertCntpoke(CentrePokemon centreP, Map* map, int casex, int casey);

void insertShppoke(ShopPokemon shopP, Map* map, int casex, int casey);

bool colliporte(sf::Sprite porteCentreP, sf::Sprite porteShopP, sf::Sprite portesortie, Map map, Perso perso, char sens, int* IDmap);

bool istalkingPNJ(int persoposmapx, int persoposmapy, int pnjposmapx, int pnjposmapy, char* sens);

void inimapgene(Map* map, sf::Sprite eau, sf::Sprite herbe, sf::Sprite arbre, sf::Sprite falaisebordR, sf::Sprite bordterreU, sf::Sprite bordfalaisemerUR, sf::Sprite marcel, int marcelposmapx, int marcelposmapy, CentrePokemon centreP, ShopPokemon shopP);

void inimapcntpkm(Map* map, sf::Sprite mur, sf::Sprite porte, sf::Sprite wallR, sf::Sprite wallD, sf::Sprite wallL, sf::Sprite gerard, int gerardposx, int gerardposy, sf::Sprite trans, int transposx, int transposy);

void inimapshppkm(Map* map, sf::Sprite mur, sf::Sprite porte, sf::Sprite wallR, sf::Sprite wallD, sf::Sprite wallL, sf::Sprite hubert, int hubertposx, int hubertposy);

void majposchgmap(bool* chgmap, int IDmap, Perso* perso, sf::Vector2i* posmapbefore, sf::Vector2i posmapbat);

void detercmbpkm(Map* mapptr, int posmapx, int posmapy, bool* isattackable, sf::Sprite herbe, bool* combat, bool chgmap);

void affbulle(Bull bulle, sf::RenderWindow* window, sf::Text texte);

void affbulleshop(Bull bulle, sf::RenderWindow* window, sf::Text textpokeballx1, sf::Text textpokeballx10, sf::Text textpotionx1, sf::Text textpotionx10);

void affmapgeneral(sf::RenderWindow* window, Map* mapptr, bool speech, sf::Sprite herbe, sf::Sprite fond, sf::Sprite rien, sf::Sprite arbre, Perso perso, sf::Text marceltexte, Bull bulle, int xmeff, int xeff, int ymeff, int yeff);

void affmapcntpkm(sf::RenderWindow* window, Map* mapptr, bool speech, sf::Text gerardtext, sf::Sprite rien, Perso perso, sf::Sprite fondcentreP, Bull bulle);

void affmapshppkm(sf::RenderWindow* window, Map* mapptr, bool speech, sf::Text huberttext, sf::Sprite rien, Perso perso, sf::Sprite fondshopP, Bull bulle, bool venteshop, Shopdeco shopdeco);

void affmenus(sf::RenderWindow* window, sf::Sprite fond, sf::Sprite logo, sf::Sprite fondmenu, sf::Text T0, sf::Text T1, sf::Text T2, sf::Text T3);

void affmenuini(sf::RenderWindow* window, sf::Sprite fond, sf::Sprite logo, sf::Sprite fondmenu, sf::Text T0, sf::Text T1);

void majmenu(int IDlignemenu, Menudeco* menudeco);

void majmenuini(int IDlignemenuini, Menudeco* menudeco);

void affcmbt(sf::RenderWindow* window, Combatdeco* cmbtdeco, sf::Sprite Spkmsav, sf::Sprite Spkm, char choix1);

void majmenucmbt(int IDligne, int IDcolone, char choixmenu, Combatdeco* combatdeco);

void gestionmenu(sf::Event event, sf::RenderWindow* window, int* IDlignemenu, bool* menu, std::string cheminsave, sf::Vector2i persoposmap, sf::Vector2i posmapbefore, int IDmap, char* pagemenu, int* rangpkmaff, Pokedex* stocage, Pokedex* equipe, Ressource* mesressource, bool* echange, especepokemon bestiaire[], int* IDpkmequipe, pokemon* pokemonptr, int IDpkmcmbt);

void gestionmenuini(sf::Event event, int * IDlignemenuini, char* pagemenu, std::string cheminsave, sf::Vector2i* persoposmap, sf::Vector2i* posmapbefore, int* IDmap, Pokedex* stocage, Pokedex* equipe, Ressource* mesressource, char* labeltype[], especepokemon bestiraire[], Perso* perso, pokemon* pkmcmbt, bool* isinmenu);

void gestionmenucombat(sf::Event event, int* IDlignemenucmbt, int* IDcolonemenucmbt, char* choixmenucmbt, bool* cmbt, pokemon* pokemonptr, pokemon* pokemonsav, hashtable* htab, especepokemon bestiaire[], bool* IsP1Dead, Ressource* mesressource, Pokedex** stocage, sf::RenderWindow* window, Combatdeco cmbtdeco, EffectAtt* effect, bool* cmbtatt, CombatPokemon* cmbtpkm);

void gestionspeech(int IDmap, Perso* perso, PNJ** pnjptr, PNJ* marcel, PNJ* gerard, PNJ* hubert, PNJ* trans, bool* speech, bool* venteshop, int tune);

std::string inttostring(int entier);

std::string pokemonTypeToString(PokemonType t);

void affpokedexe(sf::RenderWindow* window, Pokedeco pokedeco, Pokedex * monpokedex, int i, especepokemon bestiaire[]);

void inipokedexe(Pokedex* pokedex, char* labeltype[], especepokemon bestiraire[]);

void inipnj(PNJ* marcel, PNJ* gerard, PNJ* hubert, PNJ* trans);

void majpkmcmbt(pokemon* pkmcmbt, Pokedex* equipe, int IDpkmcmbt);

void soincntpkm(Pokedex* equipe);

void majvente(Shopdeco* shopdeco, int IDobjvente);

bool attraperpkmsav(float ratiopv, Pokedex** stocage, pokemon* pkmsav);

void affnoircmbt(sf::RenderWindow* window, sf::Sprite fnoir);

void affnoircmbt2(sf::RenderWindow* window, sf::Sprite fnoir, Map* mapptr, bool speech, sf::Sprite herbe, sf::Sprite fond, sf::Sprite rien, sf::Sprite arbre, Perso perso, sf::Text texte, Bull bulle);

void affcmbtatt(sf::RenderWindow* window, Combatdeco* cmbtdeco, sf::Sprite Spkmsav, sf::Sprite Spkm, EffectAtt* effect, std::string attstr, sf::Time);

void afffondcmbt(sf::RenderWindow* window, Combatdeco* cmbtdeco, sf::Sprite Spkmsav, sf::Sprite Spkm);

std::string majeffectatt(Combatdeco* cmbtdeco, float mult, pokemon* pkm, unsigned int dgtatt, float dommage, EffectAtt* effect, std::string type, char sens);

