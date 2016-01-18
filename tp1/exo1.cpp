#include "semaphore.h"
#include<iostream>
#include<thread>

#define PLACES_SDB 3

using namespace std;
enum Etat { empty, H, F }; // la salle de bain a trois etats
Etat bath = empty;
int cpt = 0;
Semaphore placeSDB(PLACES_SDB);

void fille()
{
	cout << "je suis une femme" << endl;
	while (true)
	{
		this_thread::sleep_for(chrono::seconds(2));
		if (bath == empty)
		{
			bath = F;
			cout << "la salle de bain est reserve aux FEMMES !" << endl;
		}
		if (bath == F)
		{
			P(placeSDB);// prend une place dans la sdb
			cout << "une FEMME rentre dans la sdb" << endl;
			cpt ++; //pour afficher graphiquement les places de la sdb et gerer le changement d'etat
			cout << "places occupees :" << cpt << "/" << PLACES_SDB << endl;
			this_thread::sleep_for(chrono::seconds(5));// tps passé dans la sdb
			cpt --;
			cout << "une FEMME sort de la sdb" << endl;
			cout << "places occupees :" << cpt << "/" << PLACES_SDB << endl;
			if (cpt <= 0)
			{
				bath = empty;
			}
			V(placeSDB);// libere une place dans la sdb
			this_thread::sleep_for(chrono::seconds(20));//tps entre deux acces sdb
		}
	}
}

void gars()
{
	cout << "je suis un homme" << endl;
	while (true)
	{
		this_thread::sleep_for(chrono::seconds(2));
		if (bath == empty)
		{
			
			bath = H;
			cout << "la sdb est reserve aux HOMMES !" << endl;
		}
		if (bath == H)
		{
			P(placeSDB);// prend une place dans la sdb
			cout << "un HOMME rentre dans la sdb" << endl;
			cpt ++; //pour afficher graphiquement les places de la sdb et gerer le changement d'etat
			cout << "places occupees :" << cpt << "/" << PLACES_SDB << endl;
			this_thread::sleep_for(chrono::seconds(3)); // tps passé dans la sdb
			cpt --;
			cout << "un HOMME sort de la sdb" << endl;
			cout << "places occupees :" << cpt << "/" << PLACES_SDB << endl;
			if (cpt <= 0)
			{
				bath = empty;
			}
			V(placeSDB);// libere une place dans la sdb
			this_thread::sleep_for(chrono::seconds(25)); //tps entre deux acces sdb
		}
	}
}

int main()
{
	// instantiation des threads
	thread f (fille);
	thread g (gars);
	thread g2 (gars);
	thread f2 (fille);
	thread g3 (gars);
	thread f3 (fille);
	thread g4 (gars);
	thread f4 (fille);
	thread g5 (gars);
	thread f5 (fille);
	thread g6 (gars);
	thread f6 (fille);
	thread g7 (gars);
	thread f7 (fille);
	thread g8 (gars);
	thread f8 (fille);
	thread g9 (gars);
	thread f9 (fille);
	thread g10 (gars);
	thread f10 (fille);
	// lancement des threads
	f.join();
	f2.join();
	g2.join();
	g.join();
	f3.join();
	g3.join();
	f4.join();
	g4.join();
	f5.join();
	g5.join();
	f6.join();
	g6.join();
	f7.join();
	g7.join();
	f8.join();
	g8.join();
	f9.join();
	g9.join();
	f10.join();
	g10.join();
	return 0;
}
