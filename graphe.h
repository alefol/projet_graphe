#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream> 

using namespace std;

class Graphe{

private:
	int nbSommets;
	vector< vector<bool> > sommets; 
public:
	/**
	*Construit le graphe à partir du fichier
	*du nom du fichier passé en paramètre
	**/
	Graphe(string fileName){
		ifstream file(fileName.c_str());
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
			cout<<"échec ouverture"<<endl;
		}
		display();
	}

	/**
	*Découpe la chaine en fonction du caractère espace
	*et stocke chaque sous-chaine dans le vector en paramètre
	**/
	void split(const string &ch,vector<string>& vector){
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

	void ajouterArc(int sommetDepart,int sommetArrive){
		auto s=sommets.begin()+sommetDepart-1;
		auto arc=(*s).begin()+sommetArrive-1;
		(*arc)=true;
	}

	/**
	*initialise la matrice à false
	*
	**/
	void init(){
		for(uint i=0;i<nbSommets;i++){
			vector<bool> vect;
			//fillFalse(vect);
			vect.assign(nbSommets,false);
			sommets.push_back(vect);
		}
	}

	/**
	*Affiche le graphe
	**/
	void display(){
		for(auto sommet=sommets.begin();sommet<sommets.end();sommet++){
			for(auto arcs=sommet->begin();arcs<sommet->end();arcs++){
				cout<<*arcs;
			}
			cout<<endl;
		}
	}

};