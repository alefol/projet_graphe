#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream> 
#include <numeric>

using namespace std;

class Graphe {

private:
	uint32_t nbSommets;
	vector< vector<bool> > sommets; 
	vector<int> clique;
	vector<int> sommetsParcourus;
public:
	/**
	*Construit le graphe à partir
	*du nom du fichier passé en paramètre
	**/
	Graphe(const string fileName);

	/**
	*Découpe la chaine en fonction du caractère espace
	*et stocke chaque sous-chaine dans le vector en paramètre
	**/
	void split(const string &ch, vector<string>& vector);

	void ajouterArc(const int sommetDepart,const int sommetArrive);

	/**
	*initialise la matrice à false
	*
	**/
	void init();

	bool sommetDejaParcouru(int sommet);

	int nbSommetsAdjacents(int sommet);

	void test();

	int sommetMaxAdjacences();

	/**
	*Affiche le graphe
	**/
	void display();	

	bool agranditClique(int s1);
	
	/**
	*on sélectionne le sommet qui a le plus de sommets adjacents
	*si ce sommet est adjacent à tous les sommets de la clique actuelle on l'y ajoute
	**/
	vector<int>& calculerCliqueMaximale();

};