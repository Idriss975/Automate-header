#pragma once

#include <vector>
#include <string>
using namespace std;

class Automate {
public:
	vector<char> Alphabet;
	vector<int> Etats;
	int Etat_I;
	vector<int> Etat_F;
	vector<vector<int>> Tab_Tr;
	
    Automate(vector<char> A, vector<int> E, int EI, vector<int> EF, vector<vector<int>> TT);

	int Afficher_q0() const;
	string Afficher_Etat_Final() const;
	string Afficher_Alphabets() const;
	string Afficher_Etats() const;
	string Afficher_Transitions() const;
	int Existe_Trans(int EtatD, char sysm) const;
	bool is_final(int E);
	bool Message_valide(string m) const;
};