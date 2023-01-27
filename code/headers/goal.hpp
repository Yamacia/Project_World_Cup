#pragma once 
#include "player.hpp"
#include "utility.hpp"

class Goal: public Player{
    public: 
        /*Constructeurs*/
        Goal():Player(){};
        Goal(std::string n, std::string o);
        Goal(const Goal & g): Player(g), _gball(g._gball){} //Constructeur par copie
        ~Goal();
        /*Méthode de positionnement*/
        void initGoalDroit();
        void initGoalGauche();

        /*Méthode d'informations sur le goal*/
        std::string toInfo() const;
        
        /*Méthode d'action*/
        void move();
        

    private:
        bool _gball;
};