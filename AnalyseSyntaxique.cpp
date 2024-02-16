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

Variable_non_terminale::Variable_non_terminale(char valeur, Regle* R) noexcept(false)
{
    if (R == NULL)
        throw InvalidVariable("argument R should not be NULL");
    
    this -> val = valeur;
    this -> Right = R;   
}
std::string Variable_non_terminale::toString() const
{
    return std::string() + this-> val;
}