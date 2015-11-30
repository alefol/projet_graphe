#include "graphe.h"
int main(int argc,char ** argv){
	Graphe graphe("MANN_a81.clq");
	vector<int> clique=graphe.calculerCliqueMaximale();
	//vector<int> clique=graphe.calculerCliqueMaximale();
	cout<<"taille de la clique: "<<clique.size()<<endl;
	for(int i=0;i<clique.size();i++){
		cout<<clique[i]<<" ";
	}
	cout<<endl;
}