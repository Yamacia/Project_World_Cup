#pragma once 
#include "character.hpp"
#include "constants.hpp"

class Player : public Character {

    public: 
        /*Constructeurs*/
        Player():Character(){};
        Player(std::string n, std::string o);
        Player(const Player & p): Character(p), ball(p.ball){}
        //void initStat( std::string fichier);
        //void initPoste(std::string fichier);
        
        /*Méthode virtuelle*/
        std::string toInfo() const;

        /*Méthodes de positionnement*/
        bool initInfo(std::string fichier);
        void initLeftPosition();
        void initRightPosition();

        /*Méthodes d'actions */
        void move(){_x++; _y++;}
        bool dribble(size_t proba);
        bool shoot(size_t proba);
        // void pass() const;
        // void stop() const;
        // void disturb() const;
        // void tackle() const;

        /*Getters*/
        bool has_ball() const {return ball;}
        
        /*Setters*/
        void set_ball(bool has_ball) {std::cout << "Set ball applique a : " + name << std::endl; ball = has_ball;}
        void setSpriteball();

        /*Operator*/
        Player& operator=(const Player &p);
        
        
        /*Méthodes de calculs*/
        size_t dribble_proba(size_t Nbadversaire) const;
        size_t shoot_proba() const;
        
        

    private:

    bool ball;
    
    
};