#pragma once

#include <vector>
#include <string>
#include <ostream>

class Automate {
	/// @brief vector of alphabets in automata
	std::vector<char> Alphabet;
	/// @brief vector of states in automata
	std::vector<int> Etats;
	/// @brief initial state
	int Etat_I;
	/// @brief vetor of final states
	std::vector<int> Etat_F;
	/// @brief Transaction table (Matrix format)
	std::vector<std::vector<int>> Tab_Tr;

public:
	/// @brief Automata Constructor
	/// @param A vector of alphabets in utomata
	/// @param E vector of states
	/// @param EI initial state
	/// @param EF final state
	/// @param TT List of transactions (Matrix format)
	Automate(std::vector<char> A, std::vector<int> E, int EI, std::vector<int> EF, std::vector<std::vector<int>> TT);

	/// @brief getter for initial state
	/// @return initial state of automata
	int Afficher_q0() const;
	/// @brief getter for final state
	/// @return Final state of automata
	std::string Afficher_Etat_Final() const;
	/// @brief Lists Alphabets
	/// @return Alphabets of automata
	std::string Afficher_Alphabets() const;
	/// @brief Lists states
	/// @return states of automata
	std::string Afficher_Etats() const;
	/// @brief Lists Transitions in a Matrix format
	/// @return transitions (-1 if no transition)
	std::string Afficher_Transitions() const;
	/// @brief Shows next State based on transition from alphabet and beginning state
	/// @param EtatD Starting state
	/// @param sysm Alphabet
	/// @return Next state (-1 if no transition exist)
	int Existe_Trans(int EtatD, char sysm) const;
	/// @brief check if state is final state
	/// @param E state
	/// @return bool if final state
	bool isFinalState(int E) const;
	/// @brief Check if message is valid with the automate
	/// @param m message
	/// @return true if message is valid
	bool isValidMessage(std::string m) const;
};

std::ostream& operator<<(std::ostream& O, const Automate& A);