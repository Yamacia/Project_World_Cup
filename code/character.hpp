#pragma once 
#include <iostream>
#include <string>

class Character{

public: 
    Character(std::string f, std::string n) : first_name(f), last_name(n), present(0){};
    std::string getName(){return first_name + ' '+ last_name;}
    virtual void indicate_position() const = 0;
    virtual bool on_field() const = 0; 
    virtual void move() const = 0;

protected: 
    std::string first_name;
    std::string last_name;
    bool present; //Presence sur le terrain
    
};
