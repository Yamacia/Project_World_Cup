#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "constants.hpp"

double initStat(std::string fichier, std::string name);
std::string initPoste(std::string fichier, std::string name);
sf::Sprite createBox(size_t l_pos, size_t h_pos);
sf::Sprite createBigBox(size_t l_pos, size_t h_pos);
sf::Text createText(std::string string, size_t size, size_t l_pos, size_t h_pos);