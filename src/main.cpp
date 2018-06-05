#include "graphe.h"
int main(int argc,char ** argv){
	if(argc > 1) {
		cout << "fichier en paramètre: "<< argv[1] << endl;
		string graphe_file = string(argv[1]);
		try{
			Graphe graphe(graphe_file);
			vector<int> clique=graphe.calculerCliqueMaximale();
			//vector<int> clique=graphe.calculerCliqueMaximale();
			cout<<"taille de la clique: "<<clique.size()<<endl;
			for(uint32_t i=0;i<clique.size();i++){
				cout<<clique[i]<<" ";
			}
			cout<<endl;
		}catch(const string& err){
			cout << err << endl;
		}
	}
	else {
		cout<< "veuillez spécifier un fichier contenant un graphe" << endl;
	}
	return 0;
}