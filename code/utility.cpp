#include "headers/utility.hpp"

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
                //cout << mot << endl;
                retour.push_back(mot);
            }
            if(!found){
                for (size_t i = 0; i < retour.size(); i+=4)
                {
                    //cout << retour[i] << " + " << retour[i+1] << endl;
                    if (retour[i]+' '+retour[i+1] == name)
                    {
                        //cout << retour[i]  << ' ' << retour[i+1] << endl;
                        res=stod(retour[i+2]);
                        found = true;
                    }
                }
            }
            file.close();  // on ferme le fichier
        }
        else  // sinon
                std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
            

    return res;
 
}

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
            file.close();  // on ferme le fichier
        }
        else  // sinon
                std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
 
 return res;
}