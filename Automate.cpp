#include "Automate.hpp"

Automate::Automate(vector<char> A, vector<int> E, int EI, vector<int> EF, vector<vector<int>> TT)
{
	Alphabet = A;
	Etats = E;
	Etat_I = EI;
	Etat_F = EF;
	Tab_Tr = TT;
}

int Automate::Afficher_q0() const
{
	return Etat_I;
}

string Automate::Afficher_Etat_Final() const
{
	string BUFF_outp = "{ ";
	for(int i : Etat_F)
		BUFF_outp += to_string(i)+", ";
	return BUFF_outp.substr(0,BUFF_outp.length()-2) + " }";
}

string Automate::Afficher_Alphabets() const
{
	string BUFF_outp = "{ ";
	for (char A : Alphabet)
		BUFF_outp += string(1,A) + ", ";
	return BUFF_outp.substr(0,BUFF_outp.length()-2) + " }";
}

string Automate::Afficher_Etats() const
{
	string BUFF_outp = "{ ";
	for (int A : Etats)
		BUFF_outp += to_string(A) + ", ";
	return BUFF_outp.substr(0,BUFF_outp.length()-2) + " }";
}

string Automate::Afficher_Transitions() const
{
	string Buff_outp = "   ";
	for (unsigned int i = 0; i < Alphabet.size(); i++)
		Buff_outp += string(1,Alphabet[i]) + " ";
	Buff_outp += "\n";
	

	for (int i = 0; i < Etats.size(); i++)
	{
		Buff_outp += to_string(Etats[i]) + "  ";
		for (int j = 0; j < Alphabet.size(); j++) //check for NULL
			Buff_outp += (Tab_Tr[i][j] == -1 ? "-" : to_string(Tab_Tr[i][j])) + " ";
		Buff_outp += "\n";
	}


	return Buff_outp;
}

int Automate::Existe_Trans(int EtatD, char sysm) const
{
	int _Index_ED = -1;
	for (int i = 0; i < Etats.size(); i++)
		if (Etats[i] == EtatD)
			_Index_ED = i;
				
	int _Index_A = -1;
	for (int i = 0; i < Alphabet.size(); i++)
		if (Alphabet[i] == sysm)
			_Index_A = i;
		
	if (_Index_ED == -1 || _Index_A == -1)
		return -1;
		
	return Tab_Tr[_Index_ED][_Index_A];
}

bool Automate::is_final(int E)
{
	for (int i : Etat_F)
		if (i == E)
			return true;
	return false;
}

bool Automate::Message_valide(string m) const
{
	int Etat = Etat_I;
	int Next_Etat;

	for(char i : m)
	{
		Next_Etat = Existe_Trans(Etat, i);
		if (Next_Etat == -1)
			return false;
			
		Etat = Next_Etat;
	}

	for(int i : this -> Etat_F)
		if (Etat == i)
			return true;
	return false;
}