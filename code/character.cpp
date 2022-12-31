#include "character.hpp"
#include <string>
#include <iostream>

std::string Character::toInfo() const{
    std::string retour="";

    retour = name + " , " + origin + " , " + poste;
    return retour;
}


std::ostream & operator<<(std::ostream& os, const Character& e){
    os << e.toInfo();
    return os;
}