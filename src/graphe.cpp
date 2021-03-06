#include "graphe.h"


/**
*Construit le graphe à partir
*du nom du fichier passé en paramètre
**/
Graphe::Graphe(const string fileName){
	ifstream file(fileName.c_str(), ios::in);
	vector<string> mots;
	if(file){
		string line;
		while(getline(file,line)){
			int s1=0,s2=0;
			if(line[0]=='p'){
				split(line,mots);
				nbSommets=atoi(mots[2].c_str());
				init();
			}
			else if(line[0]=='e'){
				split(line,mots);
				s1=atoi(mots[1].c_str());
				s2=atoi(mots[2].c_str());
				ajouterArc(s1,s2);
				ajouterArc(s2,s1);
			}
		}
	}
	else{
		throw string("échec de l'ouverture du fichier");
	}
		//display();
}


/**
*Découpe la chaine en fonction du caractère espace
*et stocke chaque sous-chaine dans le vector en paramètre
**/
void Graphe::split(const string &ch, vector<string>& vector){
	int pos1=0;
	int pos2=0;
	vector.clear();
	while(pos2!=-1){
		pos2=ch.find_first_of(' ',pos1);
		vector.push_back(ch.substr(pos1,pos2-pos1));
		pos1=pos2+1;
		//cout << vector.back() <<endl;
	}
}

void Graphe::ajouterArc(const int sommetDepart,const int sommetArrive){
	auto s=sommets.begin()+sommetDepart-1;
	auto arc=s->begin()+sommetArrive-1;
	(*arc)=true;
}


/**
*initialise la matrice à false
*
**/
void Graphe::init(){
	for(uint32_t i=0;i<nbSommets;i++){
		vector<bool> vect;
		//fillFalse(vect);
		vect.assign(nbSommets,false);
		sommets.push_back(vect);
	}
}

bool Graphe::sommetDejaParcouru(int sommet){
	return find(sommetsParcourus.begin(),sommetsParcourus.end(),sommet)!=sommetsParcourus.end();
}


/*int Graphe::nbSommetsAdjacents(int sommet){
	int somme=0;
	auto s1=sommets.begin()+sommet-1;
	for(auto s2=(*s1).begin();s2<(*s1).end();s2++){
		if((*s2)){
			somme++;
		}
	}
	return somme;
}*/

int Graphe::nbSommetsAdjacents(int sommet){
	auto s1=sommets.begin()+sommet-1;
	return accumulate(s1->begin(), s1->end(), 0);
}


void Graphe::test(){
	int sommetMax=sommetMaxAdjacences();
	cout<<"sommet max: "<<sommetMax<<endl;
	sommetsParcourus.push_back(sommetMax);
	sommetMax=sommetMaxAdjacences();
	cout<<"sommet max: "<<sommetMax<<endl;
}


int Graphe::sommetMaxAdjacences(){
	int sommetMax=0;
	int adjacents;
	int max=0;
	for(uint32_t i=1;i<=nbSommets;i++){
		adjacents=nbSommetsAdjacents(i);
		if(adjacents>max&&!sommetDejaParcouru(i)){
			max=adjacents;
			sommetMax=i;
		}
	}
	return sommetMax;
}


/**
*Affiche le graphe
**/
void Graphe::display(){
	for(auto sommet=sommets.begin();sommet<sommets.end();sommet++){
		for(auto arcs=sommet->begin();arcs<sommet->end();arcs++){
			cout<<*arcs;
		}
		cout<<endl;
	}
}


bool Graphe::agranditClique(int s1){
	int s2;
	for(uint32_t i=0;i<clique.size();i++){
		s2=clique.at(i);
		if(!sommets.at(s1-1).at(s2-1)){
			return false;
		}
	}
	return true;
}


/**
*on sélectionne le sommet qui a le plus de sommets adjacents
*si ce sommet est adjacent à tous les sommets de la clique actuelle on l'y ajoute
**/
vector<int>& Graphe::calculerCliqueMaximale(){
	bool termine=false;
	int sommetMax;
	do{
		sommetMax=sommetMaxAdjacences();
		if(sommets.size()==sommetsParcourus.size()){
			termine=true;
		}

		else if(agranditClique(sommetMax)){
			cout<<"on agrandit la clique avec : "<<sommetMax<<endl;
			clique.push_back(sommetMax);
		}
		sommetsParcourus.push_back(sommetMax);

	}
	while(termine==false);

	return clique;
}
