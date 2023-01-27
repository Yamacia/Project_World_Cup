#include "constants.hpp"
#include "utility.hpp"
#include "inputmanager.hpp"

class EndScreen
{
protected:
    sf::Sprite background;
    sf::Sprite final_box;
    sf::Text final_text;
    sf::Music ending_song;

public:
    static EndScreen& Instance();
    EndScreen();
    ~EndScreen();
    void loadBackgroundEndVictory(sf::RenderWindow& window);
    void loadBackgroundEndDefeat(sf::RenderWindow& window);
    void loadBackgroundEndDraw(sf::RenderWindow& window);
    void drawEndScreen(sf::RenderWindow& window);
    void loadMusic();

};