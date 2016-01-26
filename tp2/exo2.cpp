#include "semaphore.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <tbb/blocked_range.h>
#include <tbb/parallel_for.h>


using namespace std;
using namespace tbb;

typedef blocked_range<int> range;

class compMot {
	public:
		compMot(vector<string>& d, string exp) :dico(d),expr(exp)  {}
		
		void operator()(const range&r) const{
			string mot;
			for (int i=r.begin(); i!=r.end(); ++i){
				mot=dico[i];
				if ( mot.size() == expr.size() ){
					size_t j = 0;
					while(j<mot.size()){ // pour chaque lettre du mot
						if (!((expr[j]=='.')||(mot[j] == expr[j]))){
							j = mot.size()+1;
						}else{
							j++;
							if (j == mot.size()){
								cout << mot << endl;
							}
						}
					}
				}
				
			}
		}
	private:
		vector<string>& dico;
		string expr;
};


int main(int argc, char* argv[])
{
	if (argc < 2){
		cout << "rentrer au moins 1 argument" << endl;
	}else{
		vector<string> dico; // vector contenant les mots de sowpods.txt
		string mot;
		string expr = argv[1];
		cout << "expression :" << expr << endl;
		ifstream fichier("sowpods.txt", ios::in);
		if (fichier) { // chargement du fichier en mememoire
			while(getline(fichier, mot)){
				dico.push_back(mot);
			}
			parallel_for(range(0,dico.size(),dico.size()/2), compMot(dico,expr));
		}else{
			cout << "impossible d'ouvrir le fichier" << endl;
		}
	}
	return 0;
}
