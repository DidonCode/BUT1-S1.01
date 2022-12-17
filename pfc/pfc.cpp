#include <iostream>
#include <string>
#include <windows.h>

int pfc(){
    char jeu1, jeu2;
    int score1 = 0, score2 = 0;
    std::string nom1, nom2;    

    std::cout<<"Démarrage Pierre Feuille Ciseau:  Un jeu qui se joue jusqu'à ce que l'un des deux joueurs marque 10 points."<<std::endl;
    std::cout<<"Nom du joueur 1:  "<<std::endl;
    std::cin>>nom1;

    std::cout<<"Nom du joueur 2:  "<<std::endl;
    std::cin>>nom2;

    while ((score1<10) or (score2<10)){
        std::cout<<"Joueur 1 pierre(p) feuille(f) ou ciseaux(c) ? Pour jouer, entrer p ou f ou c. "<<std::endl;
        std::cin>>jeu1;

        system("clear");

        std::cout<<"Joueur 2 pierre(p) feuille(f) ou ciseaux(c) ? Pour jouer, entrer p ou f ou c.  "<<std::endl;
        std::cin>>jeu2;

        if(jeu1 == jeu2){
            std::cout<<"Egalité"<<std::endl;
        }
        else if((jeu1 == 'p') and (jeu2 == 'f')){
            score2 = score2 + 1;
            std::cout<<"1 point pour "+nom2<<std::endl;
        }
        else if((jeu1 == 'p') and (jeu2 == 'c')){
            score1 = score1 + 1;
            std::cout<<"1 point pour "+nom1<<std::endl;
        }
       else if((jeu1 == 'f') and (jeu2 == 'p')){
            score1 = score1 + 1;
            std::cout<<"1 point pour "+nom1<<std::endl;
        }
        else if((jeu1 == 'f') and (jeu2 == 'c')){
            score2 = score2 + 1;
            std::cout<<"1 point pour "+nom2<<std::endl;
        }
        else if((jeu1 == 'c') and (jeu2 == 'p')){
            score2 = score2 + 1;
            std::cout<<"1 point pour "+nom2<<std::endl;
        }
        else if((jeu1 == 'c') and (jeu2 == 'f')){
            score1 = score1 + 1;
            std::cout<<"1 point pour "+nom1<<std::endl;
        }

    }

    if (score1 > score2){
        std::cout<<"Victoire pour "+nom1<<std::endl;
        std::cout<<"Défaite pour "+nom2<<std::endl;
    }
    else {
        std::cout<<"Victoire pour "+nom2<<std::endl;
        std::cout<<"Défaite pour "+nom1<<std::endl;
    }

    std::cout<<"fin"<<std::endl;

    return 0;
}