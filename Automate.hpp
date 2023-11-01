#pragma once

#include <vector>
#include <string>
#include <iostream>

class Automate {
public:
	std::vector<char> Alphabet;
	std::vector<int> Etats;
	int Etat_I;
	std::vector<int> Etat_F;
	std::vector<std::vector<int>> Tab_Tr;
	
    Automate(std::vector<char> A, std::vector<int> E, int EI, std::vector<int> EF, std::vector<std::vector<int>> TT);

	int Afficher_q0() const;
	std::string Afficher_Etat_Final() const;
	std::string Afficher_Alphabets() const;
	std::string Afficher_Etats() const;
	std::string Afficher_Transitions() const;
	int Existe_Trans(int EtatD, char sysm) const;
	bool is_final(int E) const;
	bool Message_valide(std::string m) const;
};

std::ostream& operator<<(std::ostream& O, const Automate& A);