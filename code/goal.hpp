#pragma once 
#include "player.hpp"


class Goal: public Player{
    public: 
        Goal();
        void catch_ball();
        void stop();
};