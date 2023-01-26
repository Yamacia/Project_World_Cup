#pragma once 
#include "character.hpp"
#include "constants.hpp"

class Player : public Character {

    public: 
        //Player(std::string n, std::string o):Character(n,o){};
        Player():Character(){};
        Player(std::string n, std::string o);
        Player(const Player & p): Character(p), ball(p.ball){}
        //Player (std::string n, std::string o, std::string p, double s): Character(n,o,p,s){};
        Player(std::ifstream& f);
        //void initStat( std::string fichier);
        //void initPoste(std::string fichier);
        
        
        void initInfo(std::string fichier);
        void initLeftPosition();
        std::string toInfo() const;
        void move(){_x++; _y++;}
        // void move();
        bool has_ball() const {std::cout << ball << std::endl; return ball;}
        void set_ball(bool has_ball) {std::cout << "Set ball applique a : " + name << std::endl; ball = has_ball;}
        Player operator=(const Player p);
        // void dribble() const;
        // void shoot() const;
        // void pass() const;
        // void stop() const;
        // void disturb() const;
        // void tackle() const;
        

    private:

    bool ball;
    
    
};