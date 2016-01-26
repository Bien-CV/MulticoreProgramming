#include "semaphore.h"
#include<iostream>
#include<thread>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void chercher()
{
	
}

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
			for(size_t i=0; i<dico.size(); i++){ //pour chaque mot
				size_t j = 0;
				mot = dico[i];
				if ( mot.size() == expr.size() ){
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
		}else{
			cout << "impossible d'ouvrir le fichier" << endl;
		}
	}
	return 0;
}
