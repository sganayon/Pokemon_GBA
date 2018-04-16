#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include<string.h>

class Herbe
{
public :
	sf::Texture Therbe;
	sf::Sprite Sherbe;
private : 
	const std::string herbestr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/pokeherbe.png";
public : 
	Herbe(void);
};

class Fnoir 
{
public : 
	sf::Texture Tfnoir;
	sf::Sprite Sfnoir;
private : 
	const std::string fnoirstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/fondnoir.png";
public : 
	Fnoir(void);
};

class Eau
{
public:
	sf::Texture Teau;
	sf::Sprite Seau;
private: 
	const std::string eaustr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/pokeeau.png";
public:
	Eau(void);
};

class Rien
{
public:
	sf::Texture Trien;
	sf::Sprite Srien;
private:
	const std::string rienstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/rien.png";
public:
	Rien(void);
};

class Fond
{
public:
	sf::Texture Tfond;
	sf::Sprite Sfond;
private: 
	const std::string fondstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/pokefond.png";
public:
	Fond(void);
};


class Arbre
{
public:
	sf::Texture Tarbre;
	sf::Sprite Sarbre;
private:
	const std::string arbrestr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/arbre.png";
public:
	Arbre(void);
};

class CentrePokemon 
{
public:
	sf::Texture TCentreP;
	sf::Sprite SCentreP; //sprite de 16/16 mais image de 80/80

	sf::Texture TCentrePvide;
	sf::Sprite SCentrePvide; // sprite destiner a faire detection collision du batiment entier

	sf::Texture TCentrePporte;
	sf::Sprite SCentrePporte; // sprite destiner a detecter l'entrer dans un nouvelle map

	sf::Texture TfondCentreP;
	sf::Sprite SfondCentreP;

	sf::Texture TmurCentreP;
	sf::Sprite SmurCentreP;

	sf::Texture TwallRCP;
	sf::Sprite SwallRCP;

	sf::Texture TwallLCP;
	sf::Sprite SwallLCP;

	sf::Texture TwallDCP;
	sf::Sprite SwallDCP;

private:
	const std::string CentrePstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/centrepokemon.png";
	const std::string CentrePvidestr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/rien.png"; // transparent pour laisser voir le batiment
	const std::string CentrePportestr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/rien.png"; // porte du centre
	const std::string fondCentrePstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/fondcentrepoke2.png"; 
	const std::string murCentrePstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/murcntpkm.png";
	const std::string wallRCPstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/wallRCP.png";
	const std::string wallLCPstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/wallLCP.png";
	const std::string wallDCPstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/wallDCP.png";

	int tx = 80;
	int ty = 80;

	int portex = 32;
	int portey = 64;
public:
	CentrePokemon(void);
	int getportex(void);
	int getportey(void);
	int gettx(void);
	int getty(void);
};

class ShopPokemon 
{
public:
	sf::Texture TShopP;
	sf::Sprite SShopP;

	sf::Texture TshopPvide;
	sf::Sprite SshopPvide; // sprite destiner a faire detection collision du batiment entier

	sf::Texture TshopPporte;
	sf::Sprite SshopPporte; // sprite destiner a detecter l'entrer dans un nouvelle map

	sf::Texture TfondshopP;
	sf::Sprite SfondshopP;

	sf::Texture TmurshopP;
	sf::Sprite SmurshopP;

	sf::Texture TwallRSP;
	sf::Sprite SwallRSP;

	sf::Texture TwallLSP;
	sf::Sprite SwallLSP;

	sf::Texture TwallDSP;
	sf::Sprite SwallDSP;
private: 
	const std::string ShopPstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/shoppokemon.png";
	const std::string ShopPvidestr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/rien.png"; // transparent pour laisser voir le batiment
	const std::string ShopPportestr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/rien.png"; // porte du centre
	const std::string fondShopPstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/fondshoppoke2.png";
	const std::string murShopPstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/murshppkm.png";
	const std::string wallRSPstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/wallRSP.png";
	const std::string wallLSPstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/wallLSP.png";
	const std::string wallDSPstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/wallDSP.png";


	int taillex = 64;
	int tailley = 64;

	int portex = 32;
	int portey = 64;

public : 
	ShopPokemon(void);
	int getSportex(void);
	int getSportey(void);
	int getStx(void);
	int getSty(void);
};

class MaisonV 
{
public:
	sf::Texture TmaisonV;
	sf::Sprite SmaisonV;

private:
	const std::string maisonVstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/maisonV.png";

public:
	MaisonV(void);
};

class Falaise
{
public:
	sf::Texture TfalaiseR;
	sf::Texture TfalaiseL;
	sf::Texture TfalaiseD;
	sf::Texture TfalaiseU;

	sf::Sprite SfalaiseR;
	sf::Sprite SfalaiseL;
	sf::Sprite SfalaiseD;
	sf::Sprite SfalaiseU;

	sf::Texture TfalaisebordR;
	sf::Texture TfalaisebordL;
	sf::Texture TfalaisebordD;
	sf::Texture TfalaisebordU;

	sf::Sprite SfalaisebordR;
	sf::Sprite SfalaisebordL;
	sf::Sprite SfalaisebordD;
	sf::Sprite SfalaisebordU;

	sf::Texture TbordfalaisemerUR;
	sf::Sprite SbordfalaisemerUR;

	sf::Texture TbordterreU;
	sf::Sprite SbordterreU;
	sf::Texture TbordterreR;
	sf::Sprite SbordterreR;
private : 
	const std::string falaiseRstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/pokefalaiseR.png";
	const std::string falaiseLstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/pokefalaiseL.png";
	const std::string falaiseDstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/pokefalaiseD.png";
	const std::string falaiseUstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/pokefalaiseU.png";

	const std::string falaisebordRstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/pokefalaisebordR.png";
	const std::string falaisebordLstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/pokefalaisebordL.png";
	const std::string falaisebordDstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/pokefalaisebordD.png";
	const std::string falaisebordUstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/pokefalaisebordU.png";

	const std::string bordfalaisemerURstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/bordfalaisemerUR.png";

	const std::string bordterreUstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/bordterreU.png";
	const std::string bordterreRstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/bordterreR.png";

public:
	Falaise(void);
};


class PorteSortie
{
public : 
	sf::Texture Tportesortie;
	sf::Sprite Sportesortie;
private : 
	const std::string portesortiestr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/portesortie.png";
public : 
	PorteSortie(void);

};

class Bull
{
public:
	sf::Texture TbulleR;
	sf::Sprite SbulleR;
	sf::Texture TbulleL;
	sf::Sprite SbulleL;
	sf::Texture TbulleD;
	sf::Sprite SbulleD;
	sf::Texture TbulleU;
	sf::Sprite SbulleU;
private:
	const std::string bulleRstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/bulleR.png";
	const std::string bulleLstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/bulleL.png";
	const std::string bulleDstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/bulleD.png";
	const std::string bulleUstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/bulleU.png";
public:
	Bull(void);
};


class Menudeco
{
public:
	sf::Texture Tfondmenu;
	sf::Sprite Sfondmenu;

	sf::Texture Tlogo;
	sf::Sprite Slogo;

	sf::Font font;

	sf::Text text0;
	sf::Text text1;
	sf::Text text2;
	sf::Text text3;

	sf::Text textreini;
	sf::Text textcont;

private:
	const std::string fondmenustr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/fondmenus.png";
	const std::string logostr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/pokemonlogo.png";
	const std::string fontstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/arial.ttf";

	std::string texte0str = "Mes pokemons";
	std::string texte1str = "Mon equipe";
	std::string texte2str = "Reprendre";
	std::string texte3str = "Sauvegarder/Quitter";
	std::string textereinistr = "Nouvelle partie";
	std::string textcontstr = "Continuer votre partie";
public:
	Menudeco(void);
};

class Combatdeco 
{
public : 
	sf::Texture Tfondcmbt;
	sf::Sprite Sfondcmbt;

	sf::Texture Tftextecmbt;
	sf::Sprite Sftextecmbt;

	sf::Texture Tbarrevie;
	sf::Sprite Sbarreviepkmsav;
	sf::Sprite Sbarrevie;

	sf::Texture Tpokeball;
	sf::Sprite Spokeball; // indique cb de pkm il reste a l'adv

	sf::Font font;

	sf::Text textatt;		//choix attaqe du 1er menus --> 4 attaques 
	sf::Text textobj;		//choix objet --> pokeball, potions
	sf::Text textfuite;		//choix du lache
	sf::Text textpokemon;	//remplace le pokemon
	sf::Text textatt1;		//fourni par le pkm
	sf::Text textatt2;		//fourni par le pkm
	sf::Text textatt3;		//fourni par le pkm
	sf::Text textatt4;		//fourni par le pkm
	sf::Text textpokeball;	//choix capturer
	sf::Text textpotion;	//choix heal pokemon
	sf::Text textnompkmsav;		//fourni par une fct
	sf::Text textnompkm;		//fourni par le pkm
	sf::Text textviepkm;		//fourni par le pkm
	sf::Text textviepkmsav;		//fourni par une fct
	sf::Text comm1;				//commentaire lors de l'attaque
	sf::Text comm2;				//commentaire lors de l'attaque 

private :
	const std::string fondcmbtstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/arenecmbtpkm.png";
	const std::string fontstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/arial.ttf";
	const std::string barreviestr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/barrevie.png";
	const std::string ftextecmbtstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/fonttextecmbt.png";
	const std::string pokeballstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/pokeballadv.png";

	std::string texteattstr = "Attaque";
	std::string texteobjstr = "Objet";
	std::string textefuitestr = "Fuir";
	std::string textepokemonstr = "Pokemon";
	std::string textepokeballstr = "Pokeball";
	std::string textepotionstr = "Potion";

public :
	Combatdeco(void);
	void majtextecmbt(std::string nbpokeball, std::string nbpotion);
	void majbarrevie(float ratio, char pkm);
	void majtextecmbtatt(std::string txt1, std::string txt2);
};

class Pokedeco
{
public:
	sf::Texture Tfondaff;
	sf::Sprite Sfondaff;

	sf::Font font;

	sf::Text textnompkm[6];
	sf::Text textnivpkm[6];
	sf::Text textstadepkm[6];
	sf::Text textpvpkm[6];
	sf::Text textpvactpkm[6];
	sf::Text textpuisspkm[6];
	sf::Text textgenrepkm[6];
	sf::Text texttypepkm[6];
	sf::Text textxppkm[6];

	private:
	const std::string fondstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/fondaffpkm.png";
	const std::string fontstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/arial.ttf";

public:
	Pokedeco();
};

class Shopdeco
{
public:

	sf::Font font;

	sf::Text textpokeballx1;
	sf::Text textpokeballx10;
	sf::Text textpotionx1;
	sf::Text textpotionx10;

private:
	const std::string fontstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/arial.ttf";

	std::string textepballx1str = "pokeball x1 (300)";
	std::string textepballx10str = "pokeball x10 (3000)";
	std::string textepopox1str = "potion x1 (200)";
	std::string textepopox10str = "potion x10 (2000)";
public:
	Shopdeco(void);
};

class EffectAtt 
{
public :
	sf::RenderTexture RTeffect;

	sf::Texture Tcharge;
	sf::Texture Trush;
	sf::Texture Tcombo_1;
	sf::Texture Tcombo_2;
	sf::Texture Tfeu_ball;
	sf::Texture Tflames;
	sf::Texture Tboulefeu1;
	sf::Texture Tboulefeu2;
	sf::Texture Tfeu_burn_1;
	sf::Texture Tfeu_burn_2;
	sf::Texture Tfeu_explode;
	sf::Texture Tfond_closecombat;
	sf::Texture Tpoing;
	sf::Texture Tredstars;
	sf::Texture Tyellowstars;
	sf::Texture Tspike;
	sf::Texture Tfondvol;
	sf::Texture Tvol1;
	sf::Texture Tvol2;
	sf::Texture Tphenix_bleu;
	sf::Texture Tchoc;
	sf::Texture Tspore1;
	sf::Texture Tspore2;
	sf::Texture Tspore3;
	sf::Texture Tmudshot1;
	sf::Texture Tmudshot2;
	sf::Texture Tmudshot3;
	sf::Texture Tmleave1;
	sf::Texture Tmleave2;
	sf::Texture Tmleave3;
	sf::Texture Tmstar1;
	sf::Texture Tmstar2;
	sf::Texture Tmstar3;
	sf::Texture Tmstar4;
	sf::Texture Trock;
	sf::Texture Tfissure;
	sf::Texture Tfallrock;
	sf::Texture Tlittelrock;
	sf::Texture Tbug1;
	sf::Texture Tbug2;
	sf::Texture Tbug3;
	sf::Texture Tbug3_2;

	
	sf::Sprite Sattaque;
	sf::Sprite Sattaque1;
	sf::Sprite Sattaque2;
	sf::Sprite Sattaquefond;

private:
	const std::string chargestr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/charge.png";
	//normal
	const std::string rushstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/rush.png";
	const std::string combo1str = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/charge.png";
	const std::string combo2str = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/combo2.png";
	//fire
	const std::string feu_ballstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/feu_ball.png";
	const std::string flamesstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/flames.png";
	const std::string boulefeu1str = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/boulefeu1.png";
	const std::string boulefeu2str = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/boulefeu2.png";
	const std::string feu_burn1str = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/feu_burn_1.png";
	const std::string feu_burn2str = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/feu_burn_2.png";
	const std::string feu_explodestr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/feu_explode.png";
	//combat
	const std::string fond_closecombatstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/fond_closecombat.png";
	const std::string poingstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/poing.png";
	const std::string redstarsstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/redstars.png";
	const std::string yellowstarsstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/yellowstars.png";
	//vol
	const std::string spikestr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/spike.png";
	const std::string vol1str = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/vol1.png";
	const std::string vol2str = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/vol2.png";
	const std::string fondvolstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/fondvol.png";
	const std::string phenix_bleustr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/phenix_bleu.png";
	const std::string chocstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/ondechoc.png";
	//poison
	const std::string spore1str = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/spore1.png";
	const std::string spore2str = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/spore2.png";
	const std::string spore3str = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/spore3.png";
	const std::string mud1str = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/mudshot1.png";
	const std::string mud2str = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/mudshot2.png";
	const std::string mud3str = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/mudshot3.png";
	const std::string mleave1str = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/magic_leave1.png";
	const std::string mleave2str = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/magic_leave2.png";
	const std::string mleave3str = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/magic_leave3.png";
	const std::string mstar1str = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/magic_star1.png";
	const std::string mstar2str = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/magic_star2.png";
	const std::string mstar3str = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/magic_star3.png";
	const std::string mstar4str = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/magic_star4.png";
	//rock
	const std::string rockstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/rock.png";
	const std::string fissurestr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/fissure.png";
	const std::string fallrockstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/fallingrock.png";
	const std::string littelrockstr = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/littelrock.png";
	//bug
	const std::string bug1str = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/bug1.png";
	const std::string bug2str = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/bug2.png";
	const std::string bug3str = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/bug3.png";
	const std::string bug3_2str = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/bug3_2.png";

public:
	EffectAtt();
};