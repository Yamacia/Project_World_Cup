#include "headers/endscreen.hpp"

EndScreen& EndScreen::Instance()
{
    static EndScreen endManager;
    return endManager;
}

EndScreen::EndScreen()
{
    final_box = createBox(255,385);
    
}

EndScreen::~EndScreen()
{

}

void EndScreen::loadBackgroundEndVictory(sf::RenderWindow& window)
{
    sf::Texture *menu_screen = new sf::Texture;
    menu_screen->loadFromFile("../images/victoire.jpg");
    background.setTexture(*menu_screen);
    final_text = createText("Victoire !", 30, 310, 389);
    loadMusic();
    drawEndScreen(window);
}

void EndScreen::loadBackgroundEndDefeat(sf::RenderWindow& window)
{
    sf::Texture *menu_screen = new sf::Texture;
    menu_screen->loadFromFile("../images/defaite.jpg");
    background.setTexture(*menu_screen);
    final_text = createText("Defaite.", 30, 310, 389);
    loadMusic();
    drawEndScreen(window);
}

void EndScreen::loadBackgroundEndDraw(sf::RenderWindow& window)
{
    sf::Texture *menu_screen = new sf::Texture;
    menu_screen->loadFromFile("../images/egalite.jpg");
    background.setTexture(*menu_screen);
    final_text = createText("Match nul", 30, 305, 389);
    loadMusic();
    drawEndScreen(window);
}

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

void EndScreen::loadMusic()
{
    /* Création musique principale */
    ending_song.openFromFile("../musique/nfl_theme.wav");

    /* Musique en boucle */
    ending_song.setLoop(true);
    ending_song.setVolume(10);
    ending_song.play();  
}