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

	void split(string ch,vector<string>& vector){
		int pos1=0;
		int pos2=0;
		while(pos2!=-1){
			pos2=ch.find_first_of(' ',pos1);
			vector.push_back(ch.substr(pos1,pos2-pos1));
			pos1=pos2+1;
			//cout << vector.back() <<endl;
		}
	}

	Graphe(string fileName){
		ifstream file(fileName.c_str());
		vector<string> mots;
		if(file){
			string line;
			while(getline(file,line)){
				//cout <<line <<endl;
				if(line[0]=='p'){
					split(line,mots);
					istringstream stream(mots.at(2));
					stream>>nbSommets;
					init();
				}
			}
		}
		else{
			cout<<"échec ouverture"<<endl;
		}
		nbSommets=30;
		init();
		display();
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

	void display(){
		for(auto sommet=sommets.begin();sommet<sommets.end();sommet++){
			for(auto arcs=sommet->begin();arcs<sommet->end();arcs++){
				cout<<*arcs<<" ";
			}
			cout<<endl;
		}
	}

};