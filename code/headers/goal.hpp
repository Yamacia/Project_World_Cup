#pragma once 
#include "player.hpp"
#include "utility.hpp"

class Goal: public Player{
    public: 
        /*Constructeurs*/
        Goal():Player(){};
        Goal(std::string n, std::string o);
        Goal(const Goal & g): Player(g), _gball(g._gball){} //Constructeur par copie

        /*Méthode de positionnement*/
        void initGoalDroit();
        void initGoalGauche();

        /*Méthode virtuelle*/
        std::string toInfo() const;

        /*Méthode d'actions*/
        void catch_ball();
        void stop();
        void move();

        void setSpriteColor();
    private:
        bool _gball;
};