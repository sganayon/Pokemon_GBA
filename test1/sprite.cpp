#include "sprite.h"
#include <SFML/Graphics.hpp>
#include<iostream>
#include<string.h>


Herbe::Herbe(void) 
{
	Therbe.loadFromFile(herbestr);
	Sherbe.setTexture(Therbe);
}

Fnoir::Fnoir(void) 
{
	Tfnoir.loadFromFile(fnoirstr);
	Sfnoir.setTexture(Tfnoir);
}

Eau::Eau(void)
{
	Teau.loadFromFile(eaustr);
	Seau.setTexture(Teau);
}

Rien::Rien(void)
{
	Trien.loadFromFile(rienstr);
	Srien.setTexture(Trien);
}

Fond::Fond(void)
{
	Tfond.loadFromFile(fondstr);
	Tfond.setRepeated(true);
	Sfond.setTexture(Tfond);
	Sfond.setTextureRect(sf::IntRect(0, 0, 800, 592)); //taille du sprite == taille de fenetre pour faire un draw avec une texture repetter pour remplire la taille du sprite
	Sfond.setPosition(0.f, 0.f);
}

Arbre::Arbre(void)
{
	Tarbre.loadFromFile(arbrestr);
	Sarbre.setTexture(Tarbre);
	Sarbre.setOrigin(Sarbre.getOrigin().x, Sarbre.getOrigin().y + 16);//l'arbre fait 2 case de haut or la hitbox n'est que la case du bas
}

CentrePokemon::CentrePokemon(void)
{
	TCentreP.loadFromFile(CentrePstr);
	SCentreP.setTexture(TCentreP);

	TCentrePvide.loadFromFile(CentrePvidestr);
	SCentrePvide.setTexture(TCentrePvide);

	TCentrePporte.loadFromFile(CentrePportestr);
	TCentrePporte.setSmooth(true);
	SCentrePporte.setTexture(TCentrePporte);

	TfondCentreP.loadFromFile(fondCentrePstr);
	TfondCentreP.setRepeated(true);
	SfondCentreP.setTexture(TfondCentreP);
	SfondCentreP.setTextureRect(sf::IntRect(0, 0, 240, 160));
	SfondCentreP.setPosition(240.f, 176.f);

	TmurCentreP.loadFromFile(murCentrePstr);
	SmurCentreP.setTexture(TmurCentreP);
	SmurCentreP.setOrigin(SmurCentreP.getOrigin().x, SmurCentreP.getOrigin().y + 16);

	TwallDCP.loadFromFile(wallDCPstr);
	SwallDCP.setTexture(TwallDCP);

	TwallRCP.loadFromFile(wallRCPstr);
	SwallRCP.setTexture(TwallRCP);

	TwallLCP.loadFromFile(wallLCPstr);
	SwallLCP.setTexture(TwallLCP);
}

int CentrePokemon::getportex(void) 
{
	return portex;
}
int CentrePokemon::getportey(void)
{
	return portey;
}

int CentrePokemon::gettx(void)
{
	return tx;
}
int CentrePokemon::getty(void)
{
	return ty;
}

ShopPokemon::ShopPokemon(void)
{
	TShopP.loadFromFile(ShopPstr);
	SShopP.setTexture(TShopP);

	TshopPvide.loadFromFile(ShopPvidestr);
	SshopPvide.setTexture(TshopPvide);

	TshopPporte.loadFromFile(ShopPportestr);
	SshopPporte.setTexture(TshopPporte);

	TfondshopP.loadFromFile(fondShopPstr);
	TfondshopP.setRepeated(true);
	SfondshopP.setTexture(TfondshopP);
	SfondshopP.setTextureRect(sf::IntRect(0, 0, 240, 160));
	SfondshopP.setPosition(240.f, 176.f);

	TmurshopP.loadFromFile(murShopPstr);
	SmurshopP.setTexture(TmurshopP);
	SmurshopP.setOrigin(SmurshopP.getOrigin().x, SmurshopP.getOrigin().y + 16);

	TwallDSP.loadFromFile(wallDSPstr);
	SwallDSP.setTexture(TwallDSP);

	TwallRSP.loadFromFile(wallRSPstr);
	SwallRSP.setTexture(TwallRSP);

	TwallLSP.loadFromFile(wallLSPstr);
	SwallLSP.setTexture(TwallLSP);
}

int ShopPokemon::getSportex(void)
{
	return portex;
}
int ShopPokemon::getSportey(void)
{
	return portey;
}

int ShopPokemon::getStx(void)
{
	return taillex;
}
int ShopPokemon::getSty(void)
{
	return tailley;
}

MaisonV::MaisonV(void)
{
	TmaisonV.loadFromFile(maisonVstr);
	SmaisonV.setTexture(TmaisonV);
}

Falaise::Falaise(void)
{
	TfalaiseU.loadFromFile(falaiseUstr);
	SfalaiseU.setTexture(TfalaiseU);
	TfalaiseD.loadFromFile(falaiseDstr);
	SfalaiseD.setTexture(TfalaiseD); 
	TfalaiseR.loadFromFile(falaiseRstr);
	SfalaiseR.setTexture(TfalaiseR);
	TfalaiseL.loadFromFile(falaiseLstr);
	SfalaiseL.setTexture(TfalaiseL);

	TfalaisebordU.loadFromFile(falaisebordUstr);
	SfalaisebordU.setTexture(TfalaisebordU);
	TfalaisebordD.loadFromFile(falaisebordDstr);
	SfalaisebordD.setTexture(TfalaisebordD);
	TfalaisebordR.loadFromFile(falaisebordRstr);
	SfalaisebordR.setTexture(TfalaisebordR);
	TfalaisebordL.loadFromFile(falaisebordLstr);
	SfalaisebordL.setTexture(TfalaisebordL);

	TbordfalaisemerUR.loadFromFile(bordfalaisemerURstr);
	SbordfalaisemerUR.setTexture(TbordfalaisemerUR);

	TbordterreU.loadFromFile(bordterreUstr);
	SbordterreU.setTexture(TbordterreU);
	TbordterreR.loadFromFile(bordterreRstr);
	SbordterreR.setTexture(TbordterreR);
}

PorteSortie::PorteSortie(void) 
{
	Tportesortie.loadFromFile(portesortiestr);
	Sportesortie.setTexture(Tportesortie);
}

Bull::Bull(void) 
{
	TbulleR.loadFromFile(bulleRstr);
	SbulleR.setTexture(TbulleR);
	TbulleL.loadFromFile(bulleLstr);
	SbulleL.setTexture(TbulleL);
	TbulleD.loadFromFile(bulleDstr);
	SbulleD.setTexture(TbulleD);
	TbulleU.loadFromFile(bulleUstr);
	SbulleU.setTexture(TbulleU);
}


Menudeco::Menudeco(void)
{
	Tfondmenu.loadFromFile(fondmenustr);
	Sfondmenu.setTexture(Tfondmenu);
	Sfondmenu.setPosition(80.f, 263.f);

	Tlogo.loadFromFile(logostr);
	Slogo.setTexture(Tlogo);
	Slogo.setPosition(200.f, 0.f);

	font.loadFromFile(fontstr);

	text0.setFont(font);
	text0.setString(texte0str);
	text0.setCharacterSize(16);
	text0.setFillColor(sf::Color::Black);
	text0.setPosition(90.f, 273.f);

	text1.setFont(font);
	text1.setString(texte1str);
	text1.setCharacterSize(16);
	text1.setFillColor(sf::Color::Black);
	text1.setPosition(90.f, 305.f);

	text2.setFont(font);
	text2.setString(texte2str);
	text2.setCharacterSize(16);
	text2.setFillColor(sf::Color::Black);
	text2.setPosition(90.f, 337.f);

	text3.setFont(font);
	text3.setString(texte3str);
	text3.setCharacterSize(16);
	text3.setFillColor(sf::Color::Black);
	text3.setPosition(90.f, 369.f);

	textreini.setFont(font);
	textreini.setString(textereinistr);
	textreini.setCharacterSize(16);
	textreini.setFillColor(sf::Color::Black);
	textreini.setPosition(90.f, 273.f);

	textcont.setFont(font);
	textcont.setString(textcontstr);
	textcont.setCharacterSize(16);
	textcont.setFillColor(sf::Color::Black);
	textcont.setPosition(90.f, 305.f);
}

Combatdeco::Combatdeco(void) 
{
	Tfondcmbt.loadFromFile(fondcmbtstr);
	Sfondcmbt.setTexture(Tfondcmbt);

	Tftextecmbt.loadFromFile(ftextecmbtstr);
	Sftextecmbt.setTexture(Tftextecmbt);
	Sftextecmbt.setPosition(0.f,420.f);

	Tbarrevie.loadFromFile(barreviestr);
	Sbarreviepkmsav.setTexture(Tbarrevie);
	Sbarreviepkmsav.setPosition(191.f,83.f);
	Sbarrevie.setTexture(Tbarrevie);
	Sbarrevie.setPosition(582.f, 338.f);

	font.loadFromFile(fontstr);

	textatt.setFont(font);
	textatt.setString(texteattstr);
	textatt.setCharacterSize(48);
	textatt.setFillColor(sf::Color::Black);
	textatt.setPosition(21.f, 448.f);

	textfuite.setFont(font);
	textfuite.setString(textefuitestr);
	textfuite.setCharacterSize(48);
	textfuite.setFillColor(sf::Color::Black);
	textfuite.setPosition(21.f, 530.f);

	textobj.setFont(font);
	textobj.setString(texteobjstr);
	textobj.setCharacterSize(48);
	textobj.setFillColor(sf::Color::Black);
	textobj.setPosition(421.f, 448.f);

	textpokemon.setFont(font);
	textpokemon.setString(textepokemonstr);
	textpokemon.setCharacterSize(48);
	textpokemon.setFillColor(sf::Color::Black);
	textpokemon.setPosition(421.f, 530.f);

	textatt1.setFont(font);
	textatt1.setCharacterSize(32);
	textatt1.setFillColor(sf::Color::Black);
	textatt1.setPosition(21.f, 448.f);

	textatt3.setFont(font);
	textatt3.setCharacterSize(32);
	textatt3.setFillColor(sf::Color::Black);
	textatt3.setPosition(21.f, 530.f);

	textatt2.setFont(font);
	textatt2.setCharacterSize(32);
	textatt2.setFillColor(sf::Color::Black);
	textatt2.setPosition(421.f, 448.f);

	textatt4.setFont(font);
	textatt4.setCharacterSize(32);
	textatt4.setFillColor(sf::Color::Black);
	textatt4.setPosition(421.f, 530.f);

	textpokeball.setFont(font);
	textpokeball.setString(textepokeballstr);
	textpokeball.setCharacterSize(32);
	textpokeball.setFillColor(sf::Color::Black);
	textpokeball.setPosition(21.f, 448.f);

	textpotion.setFont(font);
	textpotion.setString(textepotionstr);
	textpotion.setCharacterSize(32);
	textpotion.setFillColor(sf::Color::Black);
	textpotion.setPosition(21.f, 530.f);
	
	textnompkm.setFont(font);
	textnompkm.setCharacterSize(32);
	textnompkm.setFillColor(sf::Color::Black);
	textnompkm.setPosition(467.f, 291.f);

	textnompkmsav.setFont(font);
	textnompkmsav.setCharacterSize(32);
	textnompkmsav.setFillColor(sf::Color::Black);
	textnompkmsav.setPosition(66.f, 33.f);
	
	textviepkm.setFont(font);
	textviepkm.setCharacterSize(32);
	textviepkm.setFillColor(sf::Color::Black);
	textviepkm.setPosition(582.f, 351.f);

	textviepkmsav.setFont(font);
	textviepkmsav.setCharacterSize(16);
	textviepkmsav.setFillColor(sf::Color::Black);
	textviepkmsav.setPosition(59.f, 78.f);

	comm1.setFont(font);
	comm1.setFillColor(sf::Color::Black);
	comm1.setPosition(30.f, 484.f);

	comm2.setFont(font);
	comm2.setFillColor(sf::Color::Black);
	comm2.setPosition(30.f, 516.f);
}
void Combatdeco::majtextecmbtatt(std::string txt1, std::string txt2)
{
	comm1.setString(txt1);
	comm2.setString(txt2);
}

void Combatdeco::majtextecmbt(std::string nbpokeball, std::string nbpotion) 
{
	textpokeball.setString("" + textepokeballstr + " (x" + nbpokeball + ")");
	textpotion.setString("" + textepotionstr + " (x" + nbpotion + ")");
}

void Combatdeco::majbarrevie(float ratio, char pkm) 
{
	if (pkm == 'E') {
		Sbarrevie.setTextureRect(sf::IntRect(0, 0, 181 * ratio, 11));
		if (ratio > 0.5) { Sbarrevie.setColor(sf::Color::Green); }
		else if (ratio > 0.2) { Sbarrevie.setColor(sf::Color::Yellow); }
		else { { Sbarrevie.setColor(sf::Color::Red); } }
	}
	else {
		Sbarreviepkmsav.setTextureRect(sf::IntRect(0, 0, 181 * ratio, 11));
		if (ratio > 0.5) { Sbarreviepkmsav.setColor(sf::Color::Green); }
		else if (ratio > 0.2) { Sbarreviepkmsav.setColor(sf::Color::Yellow); }
		else { { Sbarreviepkmsav.setColor(sf::Color::Red); } }
	}
}

Pokedeco::Pokedeco() 
{
	float x = 0;
	float y = 0;
	Tfondaff.loadFromFile(fondstr);
	Sfondaff.setTexture(Tfondaff);

	font.loadFromFile(fontstr);

	for (int i = 0; i<6; i++)
	{ 
		textnompkm[i].setFont(font);
		textnompkm[i].setCharacterSize(16);
		textnompkm[i].setFillColor(sf::Color::Black);
		textnivpkm[i].setFont(font);
		textnivpkm[i].setCharacterSize(16);
		textnivpkm[i].setFillColor(sf::Color::Black);
		textstadepkm[i].setFont(font);
		textstadepkm[i].setCharacterSize(16);
		textstadepkm[i].setFillColor(sf::Color::Black);
		textpvpkm[i].setFont(font);
		textpvpkm[i].setCharacterSize(16);
		textpvpkm[i].setFillColor(sf::Color::Black);
		textpvactpkm[i].setFont(font);
		textpvactpkm[i].setCharacterSize(16);
		textpvactpkm[i].setFillColor(sf::Color::Black);
		textpuisspkm[i].setFont(font);
		textpuisspkm[i].setCharacterSize(16);
		textpuisspkm[i].setFillColor(sf::Color::Black);
		textgenrepkm[i].setFont(font);
		textgenrepkm[i].setCharacterSize(16);
		textgenrepkm[i].setFillColor(sf::Color::Black);
		texttypepkm[i].setFont(font);
		texttypepkm[i].setCharacterSize(16);
		texttypepkm[i].setFillColor(sf::Color::Black);
		textxppkm[i].setFont(font);
		textxppkm[i].setCharacterSize(16);
		textxppkm[i].setFillColor(sf::Color::Black);

		if ((i == 0) || (i == 2) || (i == 4)) { x = 0; }
		else { x = 400; }

		if ((i == 2) || (i == 3)) { y = 200; }
		else if ((i == 4) || (i == 5)) { y = 400; }
		else { y = 0; }

		textnompkm[i].setPosition(30.f + x, 30.f +y);
		textnivpkm[i].setPosition(30.f + x, 62.f + y);
		textstadepkm[i].setPosition(150.f + x, 62.f + y);
		textpvpkm[i].setPosition(30.f + x, 94.f + y);
		textpuisspkm[i].setPosition(110.f + x, 94.f + y);
		textpvactpkm[i].setPosition(220.f + x, 94.f + y);
		textgenrepkm[i].setPosition(30.f + x, 126.f + y);
		texttypepkm[i].setPosition(200.f + x, 126.f + y);
		textxppkm[i].setPosition(30.f + x, 158.f + y);
	}
}

Shopdeco::Shopdeco(void)
{
	font.loadFromFile(fontstr);

	textpokeballx1.setFont(font);
	textpokeballx1.setString(textepballx1str);
	textpokeballx1.setCharacterSize(16);
	textpokeballx1.setFillColor(sf::Color::Black);
	textpokeballx1.setPosition(40.f, 532.f);

	textpokeballx10.setFont(font);
	textpokeballx10.setString(textepballx10str);
	textpokeballx10.setCharacterSize(16);
	textpokeballx10.setFillColor(sf::Color::Black);
	textpokeballx10.setPosition(240.f, 532.f);

	textpotionx1.setFont(font);
	textpotionx1.setString(textepopox1str);
	textpotionx1.setCharacterSize(16);
	textpotionx1.setFillColor(sf::Color::Black);
	textpotionx1.setPosition(440.f, 532.f);

	textpotionx10.setFont(font);
	textpotionx10.setString(textepopox10str);
	textpotionx10.setCharacterSize(16);
	textpotionx10.setFillColor(sf::Color::Black);
	textpotionx10.setPosition(640.f, 532.f);
}

EffectAtt::EffectAtt() 
{
	Tcharge.loadFromFile(chargestr);
	Trush.loadFromFile(rushstr);
	Tcombo_1.loadFromFile(combo1str);
	Tcombo_2.loadFromFile(combo2str);
	Tfeu_ball.loadFromFile(feu_ballstr);
	Tfeu_burn_1.loadFromFile(feu_burn1str);
	Tfeu_burn_2.loadFromFile(feu_burn2str);
	Tfeu_explode.loadFromFile(feu_explodestr);
	Tfond_closecombat.loadFromFile(fond_closecombatstr);
	Tpoing.loadFromFile(poingstr);
	Tredstars.loadFromFile(redstarsstr);
	Tyellowstars.loadFromFile(yellowstarsstr);
	Sattaque.setTexture(Tfond_closecombat);
}