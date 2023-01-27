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
        virtual void move();
        bool dribble_right(int proba);
        bool dribble_left(int proba);
        bool shoot(int proba);
        bool pass(int proba);
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
        int dribble_proba(size_t Nbadversaire) const;
        int shoot_proba_left() const;
        int shoot_proba_right() const;
        int pass_proba(Player p) const;
        
        

    protected:

    bool ball;
    
    
};