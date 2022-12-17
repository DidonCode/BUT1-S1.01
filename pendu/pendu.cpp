#include <iostream>
#include <string>
#include <windows.h>

#include "pendu_animation.cpp"

#define MAX_NAME_LEN 60

const char autorized[] = "abcdefghijklmnopqrstuvxyw"; //Tous les caractères autorisée

char input(){ //Demande au joueur la lettre
    char letter;
    bool good = false;
    
    while(!good){ //Demande tant que le joueur ne saisie pas un bon caractère
        letter = '\0';

        std::cout<<"Votre lettre ?"<<std::endl;
        std::cin>>letter;

        for(int i = 0; i < sizeof(autorized); i++){ //Parcours tous le tableau "autorized"
            if(tolower(letter) == autorized[i]){
                good = true;
                return letter;
            }
        }

        std::cout<<"Ce caractere n'est pas accepter"<<std::endl; //Si le caractère ne correspond pas
    }
}

void render(char find[], int wordLength, int tryRound){ //Fait le rendu du jeu
    animation(tryRound); //Pour l'animation

    std::cout<<std::endl;

    for(int i = 0; i < wordLength; i++){
        if(find[i] == ' '){ //Pour les caractères non trouvé
            std::cout<<" _ ";

        }else if(find[i] == '_'){ //Pour les espaces
            std::cout<<"   ";

        }else{
            std::cout<<" "<<find[i]<<" "; //Pour les caractère touvé
        }
    }
    std::cout<<std::endl;
}

int pendu(){
    system("clear");

    bool respect = false;
    std::string wordChoice; //Contiendra le mot temporairement

    while(!respect){
        std::cout<<"Choisisez le mot a faire deviner ?"<<std::endl;
        std::getline(std::cin, wordChoice); //On recupère la line du mot a faire deviner

        if(wordChoice.length() > 0){
            respect = true;
        }

        system("clear");
    }

    char word[wordChoice.length()]; //Contiendra le mot dans un tableau char et non string
    for(int i = 0; i < wordChoice.length(); i++){ word[i] = wordChoice.at(i); } //Converti un string en char

    int wordSize = sizeof(word); //Contient la longueur du mot
    char find[wordSize] = {}; //Contiendra ce qui a été touvré dans le mot

    for(int i = 0; i < wordSize; i++){ //On code le mot pour l'affichage
        if(word[i] == ' '){
            find[i] = '_';
        }else{
            find[i] = ' ';
        } 
    }

    bool finish = false;
    int round = 0;
    int tryRound = 0;

    while(!finish){
        system("clear");

        render(find, wordSize, tryRound); //Affiche le jeu

        int coherency = 0;
        for(int i = 0; i < wordSize; i++){ //Donne le nombre de caractère qui se correspond
            if(tolower(word[i]) == tolower(find[i])){
                coherency++;
            }
        }

        if(coherency >= wordSize){ //Verification de victoire
            finish = true;
            std::cout<<"\n Vous avez gagne en "<<round<<" round"<<std::endl;
            return 0;
        }

        if(tryRound >= maxTry){ //Verification de défaite
            finish = true;
            std::cout<<"\n Vous avez perdu"<<std::endl;
            return 0;
        }

        std::cout<<std::endl;

        char letter = input(); //On demande le lettre au joueur

        for(int i = 0; i < wordSize; i++){ //Attribu les lettres qui aurons été trouvés
            if(tolower(word[i]) == tolower(letter)){
                find[i] = word[i];
            }
        }  

        int error = 0;
        for(int i = 0; i < wordSize; i++){ //Si cette lettre n'est pas dans le mot
            if(tolower(word[i]) != tolower(letter)){
                error++;
            }
        }

        if(error >= wordSize){ 
            tryRound++;
        }

        round++;
    }

    return 0;
}