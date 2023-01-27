#include "headers/endscreen.hpp"

/* Unique instance */
EndScreen& EndScreen::Instance()
{
    static EndScreen endManager;
    return endManager;
}

EndScreen::EndScreen()
{
    /* Boite de dialogue contenant le résultat du match */
    final_box = createBox(255,385);
    
}

EndScreen::~EndScreen()
{

}

/* Ecran de victoire */
void EndScreen::loadBackgroundEndVictory(sf::RenderWindow& window)
{
    sf::Texture *menu_screen = new sf::Texture;
    menu_screen->loadFromFile("../images/victoire.jpg");
    background.setTexture(*menu_screen);
    final_text = createText("Victoire !", 30, 310, 389);
    loadMusic();
    drawEndScreen(window);
}

/* Ecran de défaite */
void EndScreen::loadBackgroundEndDefeat(sf::RenderWindow& window)
{
    sf::Texture *menu_screen = new sf::Texture;
    menu_screen->loadFromFile("../images/defaite.jpg");
    background.setTexture(*menu_screen);
    final_text = createText("Defaite.", 30, 310, 389);
    loadMusic();
    drawEndScreen(window);
}

/* Ecran de match nul */
void EndScreen::loadBackgroundEndDraw(sf::RenderWindow& window)
{
    sf::Texture *menu_screen = new sf::Texture;
    menu_screen->loadFromFile("../images/egalite.jpg");
    background.setTexture(*menu_screen);
    final_text = createText("Match nul", 30, 305, 389);
    loadMusic();
    drawEndScreen(window);
}

/* Dessine l'écran désiré */
void EndScreen::drawEndScreen(sf::RenderWindow& window)
{
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed || InputManager::Instance().GetKey(sf::Keyboard::Key::Escape))
            {
                window.close();
                std::cout << "Closing the game intentionally..." << std::endl;
            }
            if(InputManager::Instance().GetKey(sf::Keyboard::Key::Enter))
                return;
        }
    window.draw(background);
    window.draw(final_box);
    window.draw(final_text);
    window.display();
    }
}

/* Charge la musique finale */
void EndScreen::loadMusic()
{
    /* Création musique principale */
    ending_song.openFromFile("../musique/nfl_theme.wav");

    /* Musique en boucle */
    ending_song.setLoop(true);
    ending_song.setVolume(10);
    ending_song.play();  
}