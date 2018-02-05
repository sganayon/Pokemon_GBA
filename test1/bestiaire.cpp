#include"bestiaire.h"
#include"fct.h"
#include<iostream>
#include<string>
#include<cstdlib>
#include<cstring>
using namespace std;

void showbestiaire(especepokemon bestiaire[], char* labeltype[])
{
	char suite = 'n';
	for (int i = 0; i < 50; i++)
	{
		cout << "nom : " << bestiaire[i].nom << endl;
		cout << "type : " << labeltype[bestiaire[i].type] << endl;
		cout << "nb de bonbon pour evoluer : " << bestiaire[i].nbBonbonsPourEvoluer << endl;
		if (bestiaire[i].evolvesTo == NULL)
		{
			cout << "n'evolue pas" << endl;
		}
		else
		{
			cout << "evolue en : " << bestiaire[i].evolvesTo << endl;
		}
		cout << endl;
	}
	while (suite != 'o')
	{
		cout << "entrer o pour continuer" << endl;
		cin >> suite;
	}
	suite = 'n';
	system("cls");// efface la console
	for (int i = 50; i < 100; i++)
	{
		cout << "nom : " << bestiaire[i].nom << endl;
		cout << "type : " << labeltype[bestiaire[i].type] << endl;
		cout << "nb de bonbon pour evoluer : " << bestiaire[i].nbBonbonsPourEvoluer << endl;
		if (bestiaire[i].evolvesTo == NULL)
		{
			cout << "n'evolue pas" << endl;
		}
		else
		{
			cout << "evolue en : " << bestiaire[i].evolvesTo << endl;
		}
		cout << endl;
	}
	while (suite != 'o')
	{
		cout << "entrer o pour continuer" << endl;
		cin >> suite;
	}
	suite = 'n';
	system("cls");// efface la console
	for (int i = 100; i < 150; i++)
	{
		cout << "nom : " << bestiaire[i].nom << endl;
		cout << "type : " << labeltype[bestiaire[i].type] << endl;
		cout << "nb de bonbon pour evoluer : " << bestiaire[i].nbBonbonsPourEvoluer << endl;
		if (bestiaire[i].evolvesTo == NULL)
		{
			cout << "n'evolue pas" << endl;
		}
		else
		{
			cout << "evolue en : " << bestiaire[i].evolvesTo << endl;
		}
		cout << endl;
	}
}

void tribestiaire(especepokemon bestiaire[])
{
	int ordre;
	especepokemon temp;
	for (int j = 0; j < 149; j++)
	{
		for (int i = 0; i < 149; i++)
		{
			ordre = strcmp(bestiaire[i].nom, bestiaire[i + 1].nom);
			if (ordre > 0) // nom1 est apres nom2 dans l'ordre alphabetique
			{
				temp = bestiaire[i + 1];
				bestiaire[i + 1] = bestiaire[i];
				bestiaire[i] = temp;
			}
		}
	}
}

void initbestiaire(especepokemon bestiaire[])
{
	int evol = random_at_most(1000) % 3;
	bestiaire[0].nom = "Bulbasaur";
	bestiaire[0].type = Grass;
	bestiaire[0].nbBonbonsPourEvoluer = 25;
	bestiaire[0].evolvesTo = "Ivysaur";
	bestiaire[0].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/bulbizzardB.png";
	bestiaire[0].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/bulbizzardF.png";

	bestiaire[1].nom = "Ivysaur";
	bestiaire[1].type = Grass;
	bestiaire[1].nbBonbonsPourEvoluer = 100;
	bestiaire[1].evolvesTo = "Venusaur";
	bestiaire[1].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/herbizzardB.png";
	bestiaire[1].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/herbizzardF.png";

	bestiaire[2].nom = "Venusaur";
	bestiaire[2].type = Grass;
	bestiaire[2].nbBonbonsPourEvoluer = 0;
	bestiaire[2].evolvesTo = NULL;
	bestiaire[2].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/florizarreB.png";
	bestiaire[2].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/florizzareF.png";

	bestiaire[3].nom = "Charmander";
	bestiaire[3].type = Fire;
	bestiaire[3].nbBonbonsPourEvoluer = 25;
	bestiaire[3].evolvesTo = "Charmeleon";
	bestiaire[3].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/salamecheB.png";
	bestiaire[3].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/salamecheF.png";

	bestiaire[4].nom = "Charmeleon";
	bestiaire[4].type = Fire;
	bestiaire[4].nbBonbonsPourEvoluer = 100;
	bestiaire[4].evolvesTo = "Charizard";
	bestiaire[4].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/reptincelB.png";
	bestiaire[4].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/reptincelF.png";

	bestiaire[5].nom = "Charizard";
	bestiaire[5].type = Fire;
	bestiaire[5].nbBonbonsPourEvoluer = 0;
	bestiaire[5].evolvesTo = NULL;
	bestiaire[5].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/dracaufeuB.png";
	bestiaire[5].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/dracaufeuF.png";

	bestiaire[6].nom = "Squirtle";
	bestiaire[6].type = Water;
	bestiaire[6].nbBonbonsPourEvoluer = 25;
	bestiaire[6].evolvesTo = "Wartortle";
	bestiaire[6].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/carapuceB.png";
	bestiaire[6].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/carapuceF.png";

	bestiaire[7].nom = "Wartortle";
	bestiaire[7].type = Water;
	bestiaire[7].nbBonbonsPourEvoluer = 100;
	bestiaire[7].evolvesTo = "Blastoise";
	bestiaire[7].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/carabaffeB.png";
	bestiaire[7].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/carabaffeF.png";

	bestiaire[8].nom = "Blastoise";
	bestiaire[8].type = Water;
	bestiaire[8].nbBonbonsPourEvoluer = 0;
	bestiaire[8].evolvesTo = NULL;
	bestiaire[8].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/tortankB.png";
	bestiaire[8].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/tortankF.png";

	bestiaire[9].nom = "Caterpie";
	bestiaire[9].type = Bug;
	bestiaire[9].nbBonbonsPourEvoluer = 12;
	bestiaire[9].evolvesTo = "Metapod";
	bestiaire[9].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/chenipanB.png";
	bestiaire[9].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/chenipanF.png";

	bestiaire[10].nom = "Metapod";
	bestiaire[10].type = Bug;
	bestiaire[10].nbBonbonsPourEvoluer = 50;
	bestiaire[10].evolvesTo = "Butterfree";
	bestiaire[10].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/chrysacierB.png";
	bestiaire[10].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/chrysacierF.png";

	bestiaire[11].nom = "Butterfree";
	bestiaire[11].type = Bug;
	bestiaire[11].nbBonbonsPourEvoluer = 0;
	bestiaire[11].evolvesTo = NULL;
	bestiaire[11].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/papilusionB.png";
	bestiaire[11].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/papilusionF.png";

	bestiaire[12].nom = "Weedle";
	bestiaire[12].type = Bug;
	bestiaire[12].nbBonbonsPourEvoluer = 12;
	bestiaire[12].evolvesTo = "Kakuna";
	bestiaire[12].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/aspicotB.png";
	bestiaire[12].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/aspicotF.png";

	bestiaire[13].nom = "Kakuna";
	bestiaire[13].type = Bug;
	bestiaire[13].nbBonbonsPourEvoluer = 50;
	bestiaire[13].evolvesTo = "Beedrill";
	bestiaire[13].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/coconfortB.png";
	bestiaire[13].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/coconfortF.png";

	bestiaire[14].nom = "Beedrill";
	bestiaire[14].type = Bug;
	bestiaire[14].nbBonbonsPourEvoluer = 0;
	bestiaire[14].evolvesTo = NULL;
	bestiaire[14].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/dardargnanB.png";
	bestiaire[14].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/dardargnanF.png";

	bestiaire[15].nom = "Pidgey";
	bestiaire[15].type = Normal;
	bestiaire[15].nbBonbonsPourEvoluer = 12;
	bestiaire[15].evolvesTo = "Pidgeotto";
	bestiaire[15].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/roucoulB.png";
	bestiaire[15].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/roucoulF.png";

	bestiaire[16].nom = "Pidgeotto";
	bestiaire[16].type = Normal;
	bestiaire[16].nbBonbonsPourEvoluer = 50;
	bestiaire[16].evolvesTo = "Pidgeot";
	bestiaire[16].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/roucoupsB.png";
	bestiaire[16].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/roucoupsF.png";

	bestiaire[17].nom = "Pidgeot";
	bestiaire[17].type = Normal;
	bestiaire[17].nbBonbonsPourEvoluer = 0;
	bestiaire[17].evolvesTo = NULL;
	bestiaire[17].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/roucarnageB.png";
	bestiaire[17].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/roucarnageF.png";

	bestiaire[18].nom = "Rattata";
	bestiaire[18].type = Normal;
	bestiaire[18].nbBonbonsPourEvoluer = 25;
	bestiaire[18].evolvesTo = "Raticate";
	bestiaire[18].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/rattataB.png";
	bestiaire[18].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/rattataF.png";

	bestiaire[19].nom = "Raticate";
	bestiaire[19].type = Normal;
	bestiaire[19].nbBonbonsPourEvoluer = 0;
	bestiaire[19].evolvesTo = NULL;
	bestiaire[19].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/rattatacB.png";
	bestiaire[19].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/rattatacF.png";

	bestiaire[20].nom = "Spearow";
	bestiaire[20].type = Normal;
	bestiaire[20].nbBonbonsPourEvoluer = 50;
	bestiaire[20].evolvesTo = "Fearow";
	bestiaire[20].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/piafabecB.png";
	bestiaire[20].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/piafabecF.png";

	bestiaire[21].nom = "Fearow";
	bestiaire[21].type = Normal;
	bestiaire[21].nbBonbonsPourEvoluer = 0;
	bestiaire[21].evolvesTo = NULL;
	bestiaire[21].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/rapasdepicB.png";
	bestiaire[21].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/rapasdepicF.png";

	bestiaire[22].nom = "Ekans";
	bestiaire[22].type = Poison;
	bestiaire[22].nbBonbonsPourEvoluer = 50;
	bestiaire[22].evolvesTo = "Arbok";
	bestiaire[22].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/aboB.png";
	bestiaire[22].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/aboF.png";

	bestiaire[23].nom = "Arbok";
	bestiaire[23].type = Poison;
	bestiaire[23].nbBonbonsPourEvoluer = 0;
	bestiaire[23].evolvesTo = NULL;
	bestiaire[23].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/arbokB.png";
	bestiaire[23].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/arbokF.png";

	bestiaire[24].nom = "Pikachu";
	bestiaire[24].type = Electric;
	bestiaire[24].nbBonbonsPourEvoluer = 50;
	bestiaire[24].evolvesTo = "Raichu";
	bestiaire[24].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/pikachuB.png";
	bestiaire[24].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/pikachuF.png";

	bestiaire[25].nom = "Raichu";
	bestiaire[25].type = Electric;
	bestiaire[25].nbBonbonsPourEvoluer = 0;
	bestiaire[25].evolvesTo = NULL;
	bestiaire[25].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/raichuB.png";
	bestiaire[25].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/raichuF.png";

	bestiaire[26].nom = "Sandshrew";
	bestiaire[26].type = Ground;
	bestiaire[26].nbBonbonsPourEvoluer = 50;
	bestiaire[26].evolvesTo = "Sandslash";
	bestiaire[26].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/sabeletteB.png";
	bestiaire[26].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/sabeletteF.png";

	bestiaire[27].nom = "Sandslash";
	bestiaire[27].type = Ground;
	bestiaire[27].nbBonbonsPourEvoluer = 0;
	bestiaire[27].evolvesTo = NULL;
	bestiaire[27].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/sablaireauB.png";
	bestiaire[27].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/sablaireauF.png";

	bestiaire[28].nom = "NidoranF";
	bestiaire[28].type = Poison;
	bestiaire[28].nbBonbonsPourEvoluer = 25;
	bestiaire[28].evolvesTo = "Nidorina";
	bestiaire[28].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/nidoranfB.png";
	bestiaire[28].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/nidoranfF.png";

	bestiaire[29].nom = "Nidorina";
	bestiaire[29].type = Poison;
	bestiaire[29].nbBonbonsPourEvoluer = 100;
	bestiaire[29].evolvesTo = "Nidoqueen";
	bestiaire[29].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/nidorinaB.png";
	bestiaire[29].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/nidorinaF.png";

	bestiaire[30].nom = "Nidoqueen";
	bestiaire[30].type = Poison;
	bestiaire[30].nbBonbonsPourEvoluer = 0;
	bestiaire[30].evolvesTo = NULL;
	bestiaire[30].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/nidoqueenB.png";
	bestiaire[30].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/nidoqueenF.png";

	bestiaire[31].nom = "NidoranM";
	bestiaire[31].type = Poison;
	bestiaire[31].nbBonbonsPourEvoluer = 25;
	bestiaire[31].evolvesTo = "Nidorino";
	bestiaire[31].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/nidoranmB.png";
	bestiaire[31].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/nidoranmF.png";

	bestiaire[32].nom = "Nidorino";
	bestiaire[32].type = Poison;
	bestiaire[32].nbBonbonsPourEvoluer = 100;
	bestiaire[32].evolvesTo = "Nidoking";
	bestiaire[32].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/nidorinoB.png";
	bestiaire[32].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/nidorinoF.png";

	bestiaire[33].nom = "Nidoking";
	bestiaire[33].type = Poison;
	bestiaire[33].nbBonbonsPourEvoluer = 0;
	bestiaire[33].evolvesTo = NULL;
	bestiaire[33].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/nidokingB.png";
	bestiaire[33].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/nidokingF.png";

	bestiaire[34].nom = "Clefairy";
	bestiaire[34].type = Normal;
	bestiaire[34].nbBonbonsPourEvoluer = 50;
	bestiaire[34].evolvesTo = "Clefable";
	bestiaire[34].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/melofeeB.png";
	bestiaire[34].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/melofeeF.png";

	bestiaire[35].nom = "Clefable";
	bestiaire[35].type = Normal;
	bestiaire[35].nbBonbonsPourEvoluer = 0;
	bestiaire[35].evolvesTo = NULL;
	bestiaire[35].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/melodelfeB.png";
	bestiaire[35].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/melodelfeF.png";

	bestiaire[36].nom = "Vulpix";
	bestiaire[36].type = Fire;
	bestiaire[36].nbBonbonsPourEvoluer = 50;
	bestiaire[36].evolvesTo = "Ninetales";
	bestiaire[36].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/goupixB.png";
	bestiaire[36].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/goupixF.png";

	bestiaire[37].nom = "Ninetales";
	bestiaire[37].type = Fire;
	bestiaire[37].nbBonbonsPourEvoluer = 0;
	bestiaire[37].evolvesTo = NULL;
	bestiaire[37].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/feunardB.png";
	bestiaire[37].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/feunardF.png";

	bestiaire[38].nom = "Jigglypuff";
	bestiaire[38].type = Normal;
	bestiaire[38].nbBonbonsPourEvoluer = 50;
	bestiaire[38].evolvesTo = "Wigglytuff";
	bestiaire[38].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/rondoudouB.png";
	bestiaire[38].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/rondoudouF.png";

	bestiaire[39].nom = "Wigglytuff";
	bestiaire[39].type = Normal;
	bestiaire[39].nbBonbonsPourEvoluer = 0;
	bestiaire[39].evolvesTo = NULL;
	bestiaire[39].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/grodoudouB.png";
	bestiaire[39].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/grodoudouF.png";

	bestiaire[40].nom = "Zubat";
	bestiaire[40].type = Poison;
	bestiaire[40].nbBonbonsPourEvoluer = 50;
	bestiaire[40].evolvesTo = "Golbat";
	bestiaire[40].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/nosferaptiB.png";
	bestiaire[40].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/nosferaptiF.png";

	bestiaire[41].nom = "Golbat";
	bestiaire[41].type = Poison;
	bestiaire[41].nbBonbonsPourEvoluer = 0;
	bestiaire[41].evolvesTo = NULL;
	bestiaire[41].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/nosferaltoB.png";
	bestiaire[41].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/nosferaltoF.png";

	bestiaire[42].nom = "Oddish";
	bestiaire[42].type = Grass;
	bestiaire[42].nbBonbonsPourEvoluer = 25;
	bestiaire[42].evolvesTo = "Gloom";
	bestiaire[42].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/mystherbeB.png";
	bestiaire[42].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/mystherbeF.png";

	bestiaire[43].nom = "Gloom";
	bestiaire[43].type = Grass;
	bestiaire[43].nbBonbonsPourEvoluer = 100;
	bestiaire[43].evolvesTo = "Vileplume";
	bestiaire[43].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/ortideB.png";
	bestiaire[43].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/ortideF.png";

	bestiaire[44].nom = "Vileplume";
	bestiaire[44].type = Grass;
	bestiaire[44].nbBonbonsPourEvoluer = 0;
	bestiaire[44].evolvesTo = NULL;
	bestiaire[44].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/rafflesiaB.png";
	bestiaire[44].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/rafflesiaF.png";

	bestiaire[45].nom = "Paras";
	bestiaire[45].type = Bug;
	bestiaire[45].nbBonbonsPourEvoluer = 50;
	bestiaire[45].evolvesTo = "Parasect";
	bestiaire[45].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/parasB.png";
	bestiaire[45].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/parasF.png";

	bestiaire[46].nom = "Parasect";
	bestiaire[46].type = Bug;
	bestiaire[46].nbBonbonsPourEvoluer = 0;
	bestiaire[46].evolvesTo = NULL;
	bestiaire[46].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/parasectB.png";
	bestiaire[46].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/parasectF.png";

	bestiaire[47].nom = "Venonat";
	bestiaire[47].type = Bug;
	bestiaire[47].nbBonbonsPourEvoluer = 50;
	bestiaire[47].evolvesTo = "Venomoth";
	bestiaire[47].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/mimitossB.png";
	bestiaire[47].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/mimitossF.png";

	bestiaire[48].nom = "Venomoth";
	bestiaire[48].type = Bug;
	bestiaire[48].nbBonbonsPourEvoluer = 0;
	bestiaire[48].evolvesTo = NULL;
	bestiaire[48].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/aeromiteB.png";
	bestiaire[48].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/aeromiteF.png";

	bestiaire[49].nom = "Diglett";
	bestiaire[49].type = Ground;
	bestiaire[49].nbBonbonsPourEvoluer = 50;
	bestiaire[49].evolvesTo = "Dugtrio";
	bestiaire[49].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/taupiqueurB.png";
	bestiaire[49].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/taupiqueurF.png";

	bestiaire[50].nom = "Dugtrio";
	bestiaire[50].type = Ground;
	bestiaire[50].nbBonbonsPourEvoluer = 0;
	bestiaire[50].evolvesTo = NULL;
	bestiaire[50].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/triopikeurB.png";
	bestiaire[50].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/triopikeurF.png";

	bestiaire[51].nom = "Meowth";
	bestiaire[51].type = Normal;
	bestiaire[51].nbBonbonsPourEvoluer = 50;
	bestiaire[51].evolvesTo = "Persian";
	bestiaire[51].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/miaoussB.png";
	bestiaire[51].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/miaoussF.png";

	bestiaire[52].nom = "Persian";
	bestiaire[52].type = Normal;
	bestiaire[52].nbBonbonsPourEvoluer = 0;
	bestiaire[52].evolvesTo = NULL;
	bestiaire[52].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/persianB.png";
	bestiaire[52].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/persianF.png";

	bestiaire[53].nom = "Psyduck";
	bestiaire[53].type = Water;
	bestiaire[53].nbBonbonsPourEvoluer = 50;
	bestiaire[53].evolvesTo = "Golduck";
	bestiaire[53].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/psykokwakB.png";
	bestiaire[53].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/psykokwakF.png";

	bestiaire[54].nom = "Golduck";
	bestiaire[54].type = Water;
	bestiaire[54].nbBonbonsPourEvoluer = 0;
	bestiaire[54].evolvesTo = NULL;
	bestiaire[54].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/akwakwakB.png";
	bestiaire[54].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/akwakwakF.png";

	bestiaire[55].nom = "Mankey";
	bestiaire[55].type = Fighting;
	bestiaire[55].nbBonbonsPourEvoluer = 50;
	bestiaire[55].evolvesTo = "Primeape";
	bestiaire[55].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/ferosingeB.png";
	bestiaire[55].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/ferosingeF.png";

	bestiaire[56].nom = "Primeape";
	bestiaire[56].type = Fighting;
	bestiaire[56].nbBonbonsPourEvoluer = 0;
	bestiaire[56].evolvesTo = NULL;
	bestiaire[56].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/colossingeB.png";
	bestiaire[56].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/colossingeF.png";

	bestiaire[57].nom = "Growlithe";
	bestiaire[57].type = Fire;
	bestiaire[57].nbBonbonsPourEvoluer = 50;
	bestiaire[57].evolvesTo = "Arcanine";
	bestiaire[57].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/caninosB.png";
	bestiaire[57].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/caninosF.png";

	bestiaire[58].nom = "Arcanine";
	bestiaire[58].type = Fire;
	bestiaire[58].nbBonbonsPourEvoluer = 0;
	bestiaire[58].evolvesTo = NULL;
	bestiaire[58].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/arcaninB.png";
	bestiaire[58].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/arcaninF.png";

	bestiaire[59].nom = "Poliwag";
	bestiaire[59].type = Water;
	bestiaire[59].nbBonbonsPourEvoluer = 25;
	bestiaire[59].evolvesTo = "Poliwhirl";
	bestiaire[59].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/ptitardB.png";
	bestiaire[59].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/ptitardF.png";

	bestiaire[60].nom = "Poliwhirl";
	bestiaire[60].type = Water;
	bestiaire[60].nbBonbonsPourEvoluer = 100;
	bestiaire[60].evolvesTo = "Poliwrath";
	bestiaire[60].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/tetarteB.png";
	bestiaire[60].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/tetarteF.png";

	bestiaire[61].nom = "Poliwrath";
	bestiaire[61].type = Water;
	bestiaire[61].nbBonbonsPourEvoluer = 0;
	bestiaire[61].evolvesTo = NULL;
	bestiaire[61].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/tartardB.png";
	bestiaire[61].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/tartardF.png";

	bestiaire[62].nom = "Abra";
	bestiaire[62].type = Psychic;
	bestiaire[62].nbBonbonsPourEvoluer = 25;
	bestiaire[62].evolvesTo = "Kadabra";
	bestiaire[62].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/abraB.png";
	bestiaire[62].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/abraF.png";

	bestiaire[63].nom = "Kadabra";
	bestiaire[63].type = Psychic;
	bestiaire[63].nbBonbonsPourEvoluer = 100;
	bestiaire[63].evolvesTo = "Alakazam";
	bestiaire[63].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/kadabraB.png";
	bestiaire[63].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/kadabraF.png";

	bestiaire[64].nom = "Alakazam";
	bestiaire[64].type = Psychic;
	bestiaire[64].nbBonbonsPourEvoluer = 0;
	bestiaire[64].evolvesTo = NULL;
	bestiaire[64].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/alakazamB.png";
	bestiaire[64].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/alakazamF.png";

	bestiaire[65].nom = "Machop";
	bestiaire[65].type = Fighting;
	bestiaire[65].nbBonbonsPourEvoluer = 25;
	bestiaire[65].evolvesTo = "Machoke";
	bestiaire[65].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/machocB.png";
	bestiaire[65].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/machocF.png";

	bestiaire[66].nom = "Machoke";
	bestiaire[66].type = Fighting;
	bestiaire[66].nbBonbonsPourEvoluer = 100;
	bestiaire[66].evolvesTo = "Machamp";
	bestiaire[66].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/machopeurB.png";
	bestiaire[66].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/machopeurF.png";

	bestiaire[67].nom = "Machamp";
	bestiaire[67].type = Fighting;
	bestiaire[67].nbBonbonsPourEvoluer = 0;
	bestiaire[67].evolvesTo = NULL;
	bestiaire[67].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/mackogneurB.png";
	bestiaire[67].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/mackogneurF.png";

	bestiaire[68].nom = "Bellsprout";
	bestiaire[68].type = Grass;
	bestiaire[68].nbBonbonsPourEvoluer = 25;
	bestiaire[68].evolvesTo = "Weepinbell";
	bestiaire[68].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/chetiflorB.png";
	bestiaire[68].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/chetiflorF.png";

	bestiaire[69].nom = "Weepinbell";
	bestiaire[69].type = Grass;
	bestiaire[69].nbBonbonsPourEvoluer = 100;
	bestiaire[69].evolvesTo = "Victreebel";
	bestiaire[69].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/boustiflorB.png";
	bestiaire[69].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/boustiflorF.png";

	bestiaire[70].nom = "Victreebel";
	bestiaire[70].type = Grass;
	bestiaire[70].nbBonbonsPourEvoluer = 0;
	bestiaire[70].evolvesTo = NULL;
	bestiaire[70].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/empiflorB.png";
	bestiaire[70].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/empiflorF.png";

	bestiaire[71].nom = "Tentacool";
	bestiaire[71].type = Water;
	bestiaire[71].nbBonbonsPourEvoluer = 50;
	bestiaire[71].evolvesTo = "Tentacruel";
	bestiaire[71].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/tentacoolB.png";
	bestiaire[71].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/tentacoolF.png";

	bestiaire[72].nom = "Tentacruel";
	bestiaire[72].type = Water;
	bestiaire[72].nbBonbonsPourEvoluer = 0;
	bestiaire[72].evolvesTo = NULL;
	bestiaire[72].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/tentacruelB.png";
	bestiaire[72].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/tentacruelF.png";

	bestiaire[73].nom = "Geodude";
	bestiaire[73].type = Rock;
	bestiaire[73].nbBonbonsPourEvoluer = 25;
	bestiaire[73].evolvesTo = "Graveler";
	bestiaire[73].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/racaillouB.png";
	bestiaire[73].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/racaillouF.png";

	bestiaire[74].nom = "Graveler";
	bestiaire[74].type = Rock;
	bestiaire[74].nbBonbonsPourEvoluer = 100;
	bestiaire[74].evolvesTo = "Golem";
	bestiaire[74].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/gravalanchB.png";
	bestiaire[74].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/gravalanchF.png";

	bestiaire[75].nom = "Golem";
	bestiaire[75].type = Rock;
	bestiaire[75].nbBonbonsPourEvoluer = 0;
	bestiaire[75].evolvesTo = NULL;
	bestiaire[75].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/grolemB.png";
	bestiaire[75].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/grolemF.png";

	bestiaire[76].nom = "Ponyta";
	bestiaire[76].type = Fire;
	bestiaire[76].nbBonbonsPourEvoluer = 50;
	bestiaire[76].evolvesTo = "Rapidash";
	bestiaire[76].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/ponytaB.png";
	bestiaire[76].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/ponytaF.png";

	bestiaire[77].nom = "Rapidash";
	bestiaire[77].type = Fire;
	bestiaire[77].nbBonbonsPourEvoluer = 0;
	bestiaire[77].evolvesTo = NULL;
	bestiaire[77].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/galopaB.png";
	bestiaire[77].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/galopaF.png";

	bestiaire[78].nom = "Slowpoke";
	bestiaire[78].type = Water;
	bestiaire[78].nbBonbonsPourEvoluer = 50;
	bestiaire[78].evolvesTo = "Slowbro";
	bestiaire[78].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/ramolossB.png";
	bestiaire[78].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/ramolossF.png";

	bestiaire[79].nom = "Slowbro";
	bestiaire[79].type = Water;
	bestiaire[79].nbBonbonsPourEvoluer = 0;
	bestiaire[79].evolvesTo = NULL;
	bestiaire[79].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/flagadossB.png";
	bestiaire[79].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/flagadossF.png";

	bestiaire[80].nom = "Magnemite";
	bestiaire[80].type = Electric;
	bestiaire[80].nbBonbonsPourEvoluer = 50;
	bestiaire[80].evolvesTo = "Magneton";
	bestiaire[80].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/magnetiB.png";
	bestiaire[80].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/magnetiF.png";

	bestiaire[81].nom = "Magneton";
	bestiaire[81].type = Electric;
	bestiaire[81].nbBonbonsPourEvoluer = 0;
	bestiaire[81].evolvesTo = NULL;
	bestiaire[81].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/magnetonB.png";
	bestiaire[81].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/magnetonF.png";

	bestiaire[82].nom = "Farfetch'd";
	bestiaire[82].type = Normal;
	bestiaire[82].nbBonbonsPourEvoluer = 0;
	bestiaire[82].evolvesTo = NULL;
	bestiaire[82].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/canartichoB.png";
	bestiaire[82].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/canartichoF.png";

	bestiaire[83].nom = "Doduo";
	bestiaire[83].type = Normal;
	bestiaire[83].nbBonbonsPourEvoluer = 50;
	bestiaire[83].evolvesTo = "Dodrio";
	bestiaire[83].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/doduoB.png";
	bestiaire[83].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/doduoF.png";

	bestiaire[84].nom = "Dodrio";
	bestiaire[84].type = Normal;
	bestiaire[84].nbBonbonsPourEvoluer = 0;
	bestiaire[84].evolvesTo = NULL;
	bestiaire[84].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/dodrioB.png";
	bestiaire[84].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/dodrioF.png";

	bestiaire[85].nom = "Seel";
	bestiaire[85].type = Water;
	bestiaire[85].nbBonbonsPourEvoluer = 50;
	bestiaire[85].evolvesTo = "Dewgong";
	bestiaire[85].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/otariaB.png";
	bestiaire[85].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/otariaF.png";

	bestiaire[86].nom = "Dewgong";
	bestiaire[86].type = Water;
	bestiaire[86].nbBonbonsPourEvoluer = 0;
	bestiaire[86].evolvesTo = NULL;
	bestiaire[86].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/lamantineB.png";
	bestiaire[86].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/lamantineF.png";

	bestiaire[87].nom = "Grimer";
	bestiaire[87].type = Poison;
	bestiaire[87].nbBonbonsPourEvoluer = 50;
	bestiaire[87].evolvesTo = "Muk";
	bestiaire[87].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/tadmorvB.png";
	bestiaire[87].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/tadmorvF.png";

	bestiaire[88].nom = "Muk";
	bestiaire[88].type = Poison;
	bestiaire[88].nbBonbonsPourEvoluer = 0;
	bestiaire[88].evolvesTo = NULL;
	bestiaire[88].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/grotadmorvB.png";
	bestiaire[88].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/grotadmorvF.png";

	bestiaire[89].nom = "Shellder";
	bestiaire[89].type = Water;
	bestiaire[89].nbBonbonsPourEvoluer = 50;
	bestiaire[89].evolvesTo = "Cloyster";
	bestiaire[89].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/kokiyasB.png";
	bestiaire[89].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/kokiyasF.png";

	bestiaire[90].nom = "Cloyster";
	bestiaire[90].type = Water;
	bestiaire[90].nbBonbonsPourEvoluer = 0;
	bestiaire[90].evolvesTo = NULL;
	bestiaire[90].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/crustabriB.png";
	bestiaire[90].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/crustabriF.png";

	bestiaire[91].nom = "Gastly";
	bestiaire[91].type = Ghost;
	bestiaire[91].nbBonbonsPourEvoluer = 25;
	bestiaire[91].evolvesTo = "Haunter";
	bestiaire[91].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/fantominusB.png";
	bestiaire[91].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/fantominusF.png";

	bestiaire[92].nom = "Haunter";
	bestiaire[92].type = Ghost;
	bestiaire[92].nbBonbonsPourEvoluer = 100;
	bestiaire[92].evolvesTo = "Haunter";
	bestiaire[92].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/spectrumB.png";
	bestiaire[92].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/spectrumF.png";

	bestiaire[93].nom = "Gengar";
	bestiaire[93].type = Ghost;
	bestiaire[93].nbBonbonsPourEvoluer = 0;
	bestiaire[93].evolvesTo = NULL;
	bestiaire[93].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/ectoplasmaB.png";
	bestiaire[93].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/ectoplasmaF.png";


	bestiaire[94].nom = "Onix";
	bestiaire[94].type = Rock;
	bestiaire[94].nbBonbonsPourEvoluer = 0;
	bestiaire[94].evolvesTo = NULL;
	bestiaire[94].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/onixB.png";
	bestiaire[94].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/onixF.png";

	bestiaire[95].nom = "Drowzee";
	bestiaire[95].type = Psychic;
	bestiaire[95].nbBonbonsPourEvoluer = 50;
	bestiaire[95].evolvesTo = "Hypno";
	bestiaire[95].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/soporifikB.png";
	bestiaire[95].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/soporifikF.png";

	bestiaire[96].nom = "Hypno";
	bestiaire[96].type = Psychic;
	bestiaire[96].nbBonbonsPourEvoluer = 0;
	bestiaire[96].evolvesTo = NULL;
	bestiaire[96].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/hypnoB.png";
	bestiaire[96].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/hypnoF.png";

	bestiaire[97].nom = "Krabby";
	bestiaire[97].type = Water;
	bestiaire[97].nbBonbonsPourEvoluer = 50;
	bestiaire[97].evolvesTo = "Kingler";
	bestiaire[97].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/krabbyB.png";
	bestiaire[97].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/krabbyF.png";

	bestiaire[98].nom = "Kingler";
	bestiaire[98].type = Water;
	bestiaire[98].nbBonbonsPourEvoluer = 0;
	bestiaire[98].evolvesTo = NULL;
	bestiaire[98].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/krabbossB.png";
	bestiaire[98].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/krabbossF.png";

	bestiaire[99].nom = "Voltorb";
	bestiaire[99].type = Electric;
	bestiaire[99].nbBonbonsPourEvoluer = 50;
	bestiaire[99].evolvesTo = "Electrode";
	bestiaire[99].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/voltorbB.png";
	bestiaire[99].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/voltorbF.png";

	bestiaire[100].nom = "Electrode";
	bestiaire[100].type = Electric;
	bestiaire[100].nbBonbonsPourEvoluer = 0;
	bestiaire[100].evolvesTo = NULL;
	bestiaire[100].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/electrodeB.png";
	bestiaire[100].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/electrodeF.png";

	bestiaire[101].nom = "Exeggcute";
	bestiaire[101].type = Grass;
	bestiaire[101].nbBonbonsPourEvoluer = 50;
	bestiaire[101].evolvesTo = "Exeggcutor";
	bestiaire[101].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/noeunoeufB.png";
	bestiaire[101].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/noeunoeufF.png";

	bestiaire[102].nom = "Exeggcutor";
	bestiaire[102].type = Grass;
	bestiaire[102].nbBonbonsPourEvoluer = 0;
	bestiaire[102].evolvesTo = NULL;
	bestiaire[102].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/noadkokoB.png";
	bestiaire[102].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/noadkokoF.png";

	bestiaire[103].nom = "Cubone";
	bestiaire[103].type = Ground;
	bestiaire[103].nbBonbonsPourEvoluer = 50;
	bestiaire[103].evolvesTo = "Marowak";
	bestiaire[103].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/osselaitB.png";
	bestiaire[103].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/osselaitF.png";

	bestiaire[104].nom = "Marowak";
	bestiaire[104].type = Ground;
	bestiaire[104].nbBonbonsPourEvoluer = 0;
	bestiaire[104].evolvesTo = NULL;
	bestiaire[104].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/ossatueurB.png";
	bestiaire[104].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/ossatueurF.png";

	bestiaire[105].nom = "Hitmonlee";
	bestiaire[105].type = Fighting;
	bestiaire[105].nbBonbonsPourEvoluer = 0;
	bestiaire[105].evolvesTo = NULL;
	bestiaire[105].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/kickleeB.png";
	bestiaire[105].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/kickleeF.png";

	bestiaire[106].nom = "Hitmonchan";
	bestiaire[106].type = Fighting;
	bestiaire[106].nbBonbonsPourEvoluer = 0;
	bestiaire[106].evolvesTo = NULL;
	bestiaire[106].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/tygnonB.png";
	bestiaire[106].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/tygnonF.png";

	bestiaire[107].nom = "Lickitung";
	bestiaire[107].type = Normal;
	bestiaire[107].nbBonbonsPourEvoluer = 0;
	bestiaire[107].evolvesTo = NULL;
	bestiaire[107].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/excelangueB.png";
	bestiaire[107].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/excelangueF.png";

	bestiaire[108].nom = "Koffing";
	bestiaire[108].type = Poison;
	bestiaire[108].nbBonbonsPourEvoluer = 50;
	bestiaire[108].evolvesTo = "Weezing";
	bestiaire[108].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/smogoB.png";
	bestiaire[108].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/smogoF.png";

	bestiaire[109].nom = "Weezing";
	bestiaire[109].type = Poison;
	bestiaire[109].nbBonbonsPourEvoluer = 0;
	bestiaire[109].evolvesTo = NULL;
	bestiaire[109].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/smogogoB.png";
	bestiaire[109].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/smogogoF.png";

	bestiaire[110].nom = "Rhyhorn";
	bestiaire[110].type = Ground;
	bestiaire[110].nbBonbonsPourEvoluer = 50;
	bestiaire[110].evolvesTo = "Rhydon";
	bestiaire[110].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/rhinocorneB.png";
	bestiaire[110].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/rhinocorneF.png";

	bestiaire[111].nom = "Rhydon";
	bestiaire[111].type = Ground;
	bestiaire[111].nbBonbonsPourEvoluer = 0;
	bestiaire[111].evolvesTo = NULL;
	bestiaire[111].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/rhinoferosB.png";
	bestiaire[111].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/rhinoferosF.png";

	bestiaire[112].nom = "Chansey";
	bestiaire[112].type = Normal;
	bestiaire[112].nbBonbonsPourEvoluer = 0;
	bestiaire[112].evolvesTo = NULL;
	bestiaire[112].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/leveinardB.png";
	bestiaire[112].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/leveinardF.png";

	bestiaire[113].nom = "Tangela";
	bestiaire[113].type = Grass;
	bestiaire[113].nbBonbonsPourEvoluer = 0;
	bestiaire[113].evolvesTo = NULL;
	bestiaire[113].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/saquedeneuB.png";
	bestiaire[113].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/saquedeneuF.png";

	bestiaire[114].nom = "Kangaskhan";
	bestiaire[114].type = Normal;
	bestiaire[114].nbBonbonsPourEvoluer = 0;
	bestiaire[114].evolvesTo = NULL;
	bestiaire[114].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/kangourexB.png";
	bestiaire[114].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/kangourexF.png";

	bestiaire[115].nom = "Horsea";
	bestiaire[115].type = Water;
	bestiaire[115].nbBonbonsPourEvoluer = 50;
	bestiaire[115].evolvesTo = "Seadra";
	bestiaire[115].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/hypotrempeB.png";
	bestiaire[115].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/hypotrempeF.png";

	bestiaire[116].nom = "Seadra";
	bestiaire[116].type = Water;
	bestiaire[116].nbBonbonsPourEvoluer = 0;
	bestiaire[116].evolvesTo = NULL;
	bestiaire[116].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/hypoceanB.png";
	bestiaire[116].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/hypoceanF.png";

	bestiaire[117].nom = "Goldeen";
	bestiaire[117].type = Water;
	bestiaire[117].nbBonbonsPourEvoluer = 50;
	bestiaire[117].evolvesTo = "Seaking";
	bestiaire[117].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/poisireneB.png";
	bestiaire[117].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/poisireneF.png";

	bestiaire[118].nom = "Seaking";
	bestiaire[118].type = Water;
	bestiaire[118].nbBonbonsPourEvoluer = 0;
	bestiaire[118].evolvesTo = NULL;
	bestiaire[118].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/poissoroyB.png";
	bestiaire[118].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/poissoroyF.png";

	bestiaire[119].nom = "Staryu";
	bestiaire[119].type = Water;
	bestiaire[119].nbBonbonsPourEvoluer = 50;
	bestiaire[119].evolvesTo = "Starmie";
	bestiaire[119].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/stariB.png";
	bestiaire[119].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/stariF.png";

	bestiaire[120].nom = "Starmie";
	bestiaire[120].type = Water;
	bestiaire[120].nbBonbonsPourEvoluer = 0;
	bestiaire[120].evolvesTo = NULL;
	bestiaire[120].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/starossB.png";
	bestiaire[120].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/starossF.png";

	bestiaire[121].nom = "Mr.Mime";
	bestiaire[121].type = Psychic;
	bestiaire[121].nbBonbonsPourEvoluer = 0;
	bestiaire[121].evolvesTo = NULL;
	bestiaire[121].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/mrmimeB.png";
	bestiaire[121].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/mrmimeF.png";

	bestiaire[122].nom = "Scyther";
	bestiaire[122].type = Bug;
	bestiaire[122].nbBonbonsPourEvoluer = 0;
	bestiaire[122].evolvesTo = NULL;
	bestiaire[122].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/insecateurB.png";
	bestiaire[122].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/insecateurF.png";

	bestiaire[123].nom = "Jynx";
	bestiaire[123].type = Ice;
	bestiaire[123].nbBonbonsPourEvoluer = 0;
	bestiaire[123].evolvesTo = NULL;
	bestiaire[123].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/lippoutouB.png";
	bestiaire[123].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/lippoutouF.png";

	bestiaire[124].nom = "Electabuzz";
	bestiaire[124].type = Electric;
	bestiaire[124].nbBonbonsPourEvoluer = 0;
	bestiaire[124].evolvesTo = NULL;
	bestiaire[124].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/elektekB.png";
	bestiaire[124].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/elektekF.png";

	bestiaire[125].nom = "Magmar";
	bestiaire[125].type = Fire;
	bestiaire[125].nbBonbonsPourEvoluer = 0;
	bestiaire[125].evolvesTo = NULL;
	bestiaire[125].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/magmarB.png";
	bestiaire[125].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/magmarF.png";

	bestiaire[126].nom = "Pinsir";
	bestiaire[126].type = Bug;
	bestiaire[126].nbBonbonsPourEvoluer = 0;
	bestiaire[126].evolvesTo = NULL;
	bestiaire[126].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/scarabruteB.png";
	bestiaire[126].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/scarabruteF.png";

	bestiaire[127].nom = "Tauros";
	bestiaire[127].type = Normal;
	bestiaire[127].nbBonbonsPourEvoluer = 0;
	bestiaire[127].evolvesTo = NULL;
	bestiaire[127].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/taurosB.png";
	bestiaire[127].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/taurosF.png";

	bestiaire[128].nom = "Magikarp";
	bestiaire[128].type = Water;
	bestiaire[128].nbBonbonsPourEvoluer = 400;
	bestiaire[128].evolvesTo = "Gyarados";
	bestiaire[128].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/magicarpeB.png";
	bestiaire[128].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/magicarpeF.png";

	bestiaire[129].nom = "Gyarados";
	bestiaire[129].type = Water;
	bestiaire[129].nbBonbonsPourEvoluer = 0;
	bestiaire[129].evolvesTo = NULL;
	bestiaire[129].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/leviatorB.png";
	bestiaire[129].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/leviatorF.png";

	bestiaire[130].nom = "Lapras";
	bestiaire[130].type = Water;
	bestiaire[130].nbBonbonsPourEvoluer = 0;
	bestiaire[130].evolvesTo = NULL;
	bestiaire[130].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/lokhlassB.png";
	bestiaire[130].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/lokhlassF.png";

	bestiaire[131].nom = "Ditto";
	bestiaire[131].type = Normal;
	bestiaire[131].nbBonbonsPourEvoluer = 0;
	bestiaire[131].evolvesTo = NULL;
	bestiaire[131].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/metamorpheB.png";
	bestiaire[131].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/metamorpheF.png";

	bestiaire[132].nom = "Eevee";
	bestiaire[132].type = Normal;
	bestiaire[132].nbBonbonsPourEvoluer = 25;
	if(evol == 0){bestiaire[132].evolvesTo = "Vaporeon";}
	if (evol == 1) { bestiaire[132].evolvesTo = "Jolteon"; }
	if (evol == 2) { bestiaire[132].evolvesTo = "Flareon"; }
	bestiaire[132].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/evoliB.png";
	bestiaire[132].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/evoliF.png";
	
	bestiaire[133].nom = "Vaporeon";
	bestiaire[133].type = Water;
	bestiaire[133].nbBonbonsPourEvoluer = 0;
	bestiaire[133].evolvesTo = NULL;
	bestiaire[133].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/aqualiB.png";
	bestiaire[133].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/aqualiF.png";

	bestiaire[134].nom = "Jolteon";
	bestiaire[134].type = Electric;
	bestiaire[134].nbBonbonsPourEvoluer = 0;
	bestiaire[134].evolvesTo = NULL;
	bestiaire[134].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/voltaliB.png";
	bestiaire[134].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/voltaliF.png";

	bestiaire[135].nom = "Flareon";
	bestiaire[135].type = Fire;
	bestiaire[135].nbBonbonsPourEvoluer = 0;
	bestiaire[135].evolvesTo = NULL;
	bestiaire[135].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/pyroliB.png";
	bestiaire[135].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/pyroliF.png";

	bestiaire[136].nom = "Porygon";
	bestiaire[136].type = Normal;
	bestiaire[136].nbBonbonsPourEvoluer = 0;
	bestiaire[136].evolvesTo = NULL;
	bestiaire[136].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/porygonB.png";
	bestiaire[136].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/porygonF.png";

	bestiaire[137].nom = "Omanyte";
	bestiaire[137].type = Rock;
	bestiaire[137].nbBonbonsPourEvoluer = 50;
	bestiaire[137].evolvesTo = "Omastar";
	bestiaire[137].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/amonitaB.png";
	bestiaire[137].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/amonitaF.png";

	bestiaire[138].nom = "Omastar";
	bestiaire[138].type = Rock;
	bestiaire[138].nbBonbonsPourEvoluer = 0;
	bestiaire[138].evolvesTo = NULL;
	bestiaire[138].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/amonistarB.png";
	bestiaire[138].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/amonistarF.png";

	bestiaire[139].nom = "Kabuto";
	bestiaire[139].type = Rock;
	bestiaire[139].nbBonbonsPourEvoluer = 50;
	bestiaire[139].evolvesTo = "Kabutops";
	bestiaire[139].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/kabutoB.png";
	bestiaire[139].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/kabutoF.png";

	bestiaire[140].nom = "Kabutops";
	bestiaire[140].type = Rock;
	bestiaire[140].nbBonbonsPourEvoluer = 0;
	bestiaire[140].evolvesTo = NULL;
	bestiaire[140].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/kabutopsB.png";
	bestiaire[140].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/kabutopsF.png";

	bestiaire[141].nom = "Aerodactyl";
	bestiaire[141].type = Rock;
	bestiaire[141].nbBonbonsPourEvoluer = 0;
	bestiaire[141].evolvesTo = NULL;
	bestiaire[141].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/pteraB.png";
	bestiaire[141].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/pteraF.png";

	bestiaire[142].nom = "Snorlax";
	bestiaire[142].type = Normal;
	bestiaire[142].nbBonbonsPourEvoluer = 0;
	bestiaire[142].evolvesTo = NULL;
	bestiaire[142].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/ronflexB.png";
	bestiaire[142].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/ronflexF.png";

	bestiaire[143].nom = "Articuno";
	bestiaire[143].type = Ice;
	bestiaire[143].nbBonbonsPourEvoluer = 0;
	bestiaire[143].evolvesTo = NULL;
	bestiaire[143].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/artikodinB.png";
	bestiaire[143].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/artikodinF.png";

	bestiaire[144].nom = "Zapdos";
	bestiaire[144].type = Electric;
	bestiaire[144].nbBonbonsPourEvoluer = 0;
	bestiaire[144].evolvesTo = NULL;
	bestiaire[144].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/electhorB.png";
	bestiaire[144].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/electhorF.png";

	bestiaire[145].nom = "Moltres";
	bestiaire[145].type = Fire;
	bestiaire[145].nbBonbonsPourEvoluer = 0;
	bestiaire[145].evolvesTo = NULL;
	bestiaire[145].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/sulfuraB.png";
	bestiaire[145].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/sulfuraF.png";

	bestiaire[146].nom = "Dratini";
	bestiaire[146].type = Dragon;
	bestiaire[146].nbBonbonsPourEvoluer = 25;
	bestiaire[146].evolvesTo = "Dragonair";
	bestiaire[146].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/minidracoB.png";
	bestiaire[146].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/minidracoF.png";

	bestiaire[147].nom = "Dragonair";
	bestiaire[147].type = Dragon;
	bestiaire[147].nbBonbonsPourEvoluer = 100;
	bestiaire[147].evolvesTo = "Dragonite";
	bestiaire[147].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/dracoB.png";
	bestiaire[147].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/dracoF.png";

	bestiaire[148].nom = "Dragonite";
	bestiaire[148].type = Dragon;
	bestiaire[148].nbBonbonsPourEvoluer = 0;
	bestiaire[148].evolvesTo = NULL;
	bestiaire[148].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/dracolosseB.png";
	bestiaire[148].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/dracolosseF.png";

	bestiaire[149].nom = "Mewtwo";
	bestiaire[149].type = Psychic;
	bestiaire[149].nbBonbonsPourEvoluer = 0;
	bestiaire[149].evolvesTo = NULL;
	bestiaire[149].cheminback = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/mewtwoB.png";
	bestiaire[149].cheminface = "C:/Users/axel/Desktop/telecom/Info/sfml/testpoke/img/mewtwoF.png";

	for (int i = 0; i < 150; i++)
	{
		bestiaire[i].estEvolue = true;
	}
	// set all evolved pokemon to true
	bestiaire[0].estEvolue = 0;
	bestiaire[3].estEvolue = 0;
	bestiaire[6].estEvolue = 0;
	bestiaire[9].estEvolue = 0;
	bestiaire[12].estEvolue = 0;
	bestiaire[15].estEvolue = 0;
	bestiaire[18].estEvolue = 0;
	bestiaire[20].estEvolue = 0;
	bestiaire[22].estEvolue = 0;
	bestiaire[24].estEvolue = 0;
	bestiaire[26].estEvolue = 0;
	bestiaire[28].estEvolue = 0;
	bestiaire[31].estEvolue = 0;
	bestiaire[34].estEvolue = 0;
	bestiaire[36].estEvolue = 0;
	bestiaire[38].estEvolue = 0;
	bestiaire[40].estEvolue = 0;
	bestiaire[42].estEvolue = 0;
	bestiaire[45].estEvolue = 0;
	bestiaire[47].estEvolue = 0;
	bestiaire[49].estEvolue = 0;
	bestiaire[51].estEvolue = 0;
	bestiaire[53].estEvolue = 0;
	bestiaire[55].estEvolue = 0;
	bestiaire[57].estEvolue = 0;
	bestiaire[59].estEvolue = 0;
	bestiaire[62].estEvolue = 0;
	bestiaire[65].estEvolue = 0;
	bestiaire[68].estEvolue = 0;
	bestiaire[71].estEvolue = 0;
	bestiaire[73].estEvolue = 0;
	bestiaire[76].estEvolue = 0;
	bestiaire[78].estEvolue = 0;
	bestiaire[80].estEvolue = 0;
	bestiaire[82].estEvolue = 0;
	bestiaire[83].estEvolue = 0;
	bestiaire[107].estEvolue = 0;
	bestiaire[108].estEvolue = 0;
	bestiaire[110].estEvolue = 0;
	bestiaire[112].estEvolue = 0;
	bestiaire[113].estEvolue = 0;
	bestiaire[114].estEvolue = 0;
	bestiaire[115].estEvolue = 0;
	bestiaire[117].estEvolue = 0;
	bestiaire[119].estEvolue = 0;
	bestiaire[121].estEvolue = 0;
	bestiaire[122].estEvolue = 0;
	bestiaire[123].estEvolue = 0;
	bestiaire[124].estEvolue = 0;
	bestiaire[125].estEvolue = 0;
	bestiaire[126].estEvolue = 0;
	bestiaire[127].estEvolue = 0;
	bestiaire[128].estEvolue = 0;
	bestiaire[130].estEvolue = 0;
	bestiaire[131].estEvolue = 0;
	bestiaire[132].estEvolue = 0;
	bestiaire[136].estEvolue = 0;
	bestiaire[137].estEvolue = 0;
	bestiaire[139].estEvolue = 0;
	bestiaire[141].estEvolue = 0;
	bestiaire[142].estEvolue = 0;
	bestiaire[143].estEvolue = 0;
	bestiaire[144].estEvolue = 0;
	bestiaire[145].estEvolue = 0;
	bestiaire[146].estEvolue = 0;
	bestiaire[149].estEvolue = 0;
}
