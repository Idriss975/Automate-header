#pragma once

/*
*            ___                __              
*           /   |  ____  ____ _/ /_  __________ 
*          / /| | / __ \/ __ `/ / / / / ___/ _ \
*         / ___ |/ / / / /_/ / / /_/ (__  )  __/
*        /_/  |_/_/ /_/\__,_/_/\__, /____/\___/ 
*                             /____/            
*                             __             _                
*           _______  ______  / /_____ __  __(_)___ ___  _____ 
*         / ___/ / / / __ \/ __/ __ `/ |/_/ / __ `/ / / / _ \
*        (__  ) /_/ / / / / /_/ /_/ />  </ / /_/ / /_/ /  __/
*       /____/\__, /_/ /_/\__/\__,_/_/|_/_/\__, /\__,_/\___/ 
*            /____/                          /_/             
*
*
*           https://github.com/Idriss975/Automate-header
*
*/

#include <exception>
#include <string>
#include <stdexcept>
#include <vector>
#include <array>
#include <unordered_set>

class InvalidVariable: public std::runtime_error
{

public:
    InvalidVariable(const char* m) : std::runtime_error(m) 
    {}
};

/// @brief Abstract class for Variable_terminale & Variable_non_terminale
class Variable_Lexicale 
{
public:
    char val;
};


class Variable_terminale : public Variable_Lexicale
{
public:
    Variable_terminale() = default;
    Variable_terminale(char valeur);
    std::string toString() const;
};

class Variable_non_terminale : public Variable_Lexicale
{
public:
    Regle* Right;

    Variable_non_terminale(char valeur, Regle* R) noexcept(false); // throws InvalidVariable
    std::string toString() const;    
};

class Regle
{
private:
    bool is_nullable;
public:
    Variable_non_terminale Partie_gauche;
    std::vector<Variable_Lexicale> Partie_droite;

    Regle() = default;
    Regle(Variable_non_terminale left, std::vector<Variable_terminale> right, bool is_null=false);
    Regle(std::string left, std::vector<Variable_terminale> right, bool is_null=false);
    
    bool Recursive_aGauche() const;
    void Eliminer_Recursivite_aGauche();
    bool Factorisation_aGauche() const;
    void Eliminer_Factorisation_aGauche();

    bool Nullable() const;
    std::unordered_set<Variable_terminale> Premier() const;

    std::string toString() const;
};

template<size_t NB_Vn, size_t NB_Vt>
class Grammaire
{
public:
    std::array<Regle, NB_Vn> Regles;
    std::array<Variable_non_terminale, NB_Vn> Vn;
    std::array<Variable_terminale, NB_Vt> Vt;
    Variable_non_terminale* Axiome;

    Grammaire() = default;
    Grammaire(std::array<Regle, NB_Vn> R, std::char Axiome);
    Grammaire(std::array<Regle, NB_Vn> R, Variable_non_terminale* Axiome);

    bool Recursive_aGauche() const;
    void Eliminer_Recursivite_aGauche();
    bool Factorisation_aGauche() const;
    void Eliminer_Factorisation_aGauche() const;

    std::unordered_set<Variable_terminale> Suivant(Variable_non_terminale Vt) const;
    Tableau_analyse<NB_Vn, NB_Vt> Generer_Tableau_analyse() const:
    std::string toString() const;
};

template<size_t NB_Vn, size_t NB_Vt>
class Tableau_analyse
{
public:
    std::array<Variable_non_terminale, NB_Vn> Vn;
    std::array<Variable_terminale, NB_Vt> Vt;

    Tableau_analyse() = default;
};
