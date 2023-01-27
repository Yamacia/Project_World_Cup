#include "headers/utility.hpp"

/*Fonction qui retourne la stat du joueur depuis un fichier*/
double initStat(std::string fichier, std::string name){
    std::ifstream file(fichier, std::ios::in);  // on ouvre le fichier en lecture
    double res=0;

        if(file)  // si l'ouverture a réussi
        {   
            bool found=false;
            std::string mot;
            std::vector<std::string> retour;

            while (file.peek()!=EOF){
                file >> mot;
                retour.push_back(mot);
            }
            if(!found){
                for (size_t i = 0; i < retour.size(); i+=4)
                {
                    
                    if (retour[i]+' '+retour[i+1] == name)
                    {
                        
                        res=stod(retour[i+2]);
                        found = true;
                    }
                }
            }
            retour.clear();
            file.close();  // on ferme le fichier
        }
        else  // sinon
                std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
            

    return res;

 
}
/*Fonction qui permet d'extraire le poste du joueur depuis un fichier*/
std::string initPoste(std::string fichier, std::string name){
    std::ifstream file(fichier, std::ios::in);  // on ouvre le fichier en lecture
    
    std::string res="";

        if(file)  // si l'ouverture a réussi
        {   
            bool found=false;
            std::string ligne;
            std::string mot;
            std::vector<std::string> retour;

            while (file.peek()!=EOF){
                file >> mot;
                //cout << mot << endl;
                retour.push_back(mot);
            }
            if(!found){
                for (size_t i = 0; i < retour.size(); i+=4)
                {
                    //cout << retour[i] << " + " << retour[i+1] << endl;
                    if (retour[i]+' '+retour[i+1] == name)
                    {
                        //std::cout << retour[i]  << ' ' << retour[i+1] << std::endl;
                        res=retour[i+3];
                        found = true;
                    }
                }
            }
            retour.clear();
            file.close();  // on ferme le fichier
        }
        else  // sinon
                std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
 
 return res;
}


/* Crée une petite boite de dialogue à la position désirée */
sf::Sprite createBox(size_t l_pos, size_t h_pos)
{
    sf::Texture *text_box = new sf::Texture;
    text_box->loadFromFile("../images/box_blank.png");
    sf::Sprite box(*text_box);
    box.setTextureRect(sf::IntRect(0, 0, LARGEUR_BOX, HAUTEUR_BOX));
    box.setPosition(l_pos,h_pos);

    return box;

    delete text_box;
    text_box = nullptr;
}

/* Crée une grande boite de dialogue à la position désirée */
sf::Sprite createBigBox(size_t l_pos, size_t h_pos)
{
    sf::Texture *text_box = new sf::Texture;
    text_box->loadFromFile("../images/big_box_blank.png");
    sf::Sprite box(*text_box);
    box.setTextureRect(sf::IntRect(0, 0, LARGEUR_BIG, HAUTEUR_BIG));
    box.setPosition(l_pos,h_pos);

    return box;

    delete text_box;
    text_box = nullptr;
}

/* Crée le texte à la position et taille désirées */
sf::Text createText(std::string string, size_t size, size_t l_pos, size_t h_pos)
{
    sf::Font *font = new sf::Font;
    font->loadFromFile("../font/arial.ttf");

    sf::Text text;
    text.setFont(*font);
    text.setCharacterSize(size);
    text.setFillColor(sf::Color::White);
    text.setString(string);
    text.setPosition(sf::Vector2f(l_pos,h_pos));

    return text;

    delete font;
    font = nullptr;
}
