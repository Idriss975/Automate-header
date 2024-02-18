#include "AnalyseSyntaxique.hpp"

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


Variable_terminale::Variable_terminale(char valeur) 
{
    this -> val = valeur;
}

std::string Variable_terminale::toString() const
{
    return std::string() + this -> val;
}

bool Variable_terminale::operator==(const Variable_terminale & Vt) const
{
    return this -> val == Vt.val;
}


Variable_non_terminale::Variable_non_terminale(char valeur)
{
    this -> val = valeur;
}
Variable_non_terminale::Variable_non_terminale(char valeur, Regle* R)
{
    this -> val = valeur;
    this -> Right = R;
}
std::string Variable_non_terminale::toString() const
{
    return std::string() + this-> val;
}
bool Variable_non_terminale::operator==(const Variable_non_terminale & Vn) const
{
    return this->val == Vn.val;
}

Regle::Regle(Variable_non_terminale left, std::vector<std::vector<Variable_Lexicale>> right, bool is_null)
{
    this -> Partie_gauche = left;
    this -> Partie_gauche.Right = this;
    this -> Partie_droite = right;
    this -> is_nullable = is_null;
}
Regle::Regle(char left, std::vector<std::string> right, bool is_null)
{
    this -> Partie_gauche = Variable_non_terminale(left, this);

    Partie_droite = std::vector<std::vector<Variable_Lexicale>>(right.size());
    this -> is_nullable = is_null;
    
    for (size_t i = 0; i < right.size(); i++)
    {
        for (size_t j = 0; j < right[i].size(); j++)
        {
            if (std::isupper(right[i][j]))
                Partie_droite[i].push_back(Variable_non_terminale(right[i][j]));
            else
                Partie_droite[i].push_back(Variable_terminale(right[i][j]));
        }
    }
}

bool Regle::Recursive_aGauche() const
{
    throw std::logic_error("Regle::Recursive_aGauche() not yet implemented.");
}
void Regle::Eliminer_Recursivite_aGauche()
{
    throw std::logic_error("Regle::Eliminer_Recursivite_aGauche() not yet implemented.");
}
bool Regle::Factorisation_aGauche() const
{
    throw std::logic_error("Regle::Factorisation_aGauche() not yet implemented.");
}
void Regle::Eliminer_Factorisation_aGauche()
{
    throw std::logic_error("Regle::Eliminer_Factorisation_aGauche() not yet implemented.");
}

bool Regle::Nullable() const
{
    return this -> is_nullable;
}
std::unordered_set<Variable_terminale> Regle::Premier() const
{
        throw std::logic_error("Regle::Premier() not yet implemented.");

    std::unordered_set<Variable_terminale, Variable_terminale::HashFunction> Outp;
    //TODO
}

void Ajouter_OU(std::vector<Variable_Lexicale> r)
{
    throw std::logic_error("Regle::Premier() not yet implemented.");
}

std::string Regle::toString() const
{

}