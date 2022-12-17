#include <iostream>
#include <ctype.h>
#include <string.h>
#include <windows.h>

//---------------------------\\
//                           \\
//    Par: Richard Perrier   \\
//    Le: 09/11/2022         \\
//                           \\
//---------------------------\\

const char morpion_player1 = 'X'; //Symbole du joueur 1
const char morpion_player2 = 'O'; //Symbole du joueur 2

const char* morpion_color1 = "\x1B[94m"; //Couleur du joueur 1: blue
const char* morpion_color2 = "\x1B[91m"; //Couleur du joueur 2: red

int select(int player){ //Recupere le chiffre que le joueur rentre
    char n[255] = {};
    int number = 0;
    bool good = false;

    while(!good){
        n[255] = {};
        number = 0;

        std::cout<<"Joueur "<<(player + 1)<<" votre signe ";
        if(player == 0) { std::cout<<morpion_player1<<std::endl; }else { std::cout<<morpion_player2<<std::endl; }
        std::cin>>n;

        int j = 0;
        for(int i = 0; i < sizeof(n); i++){
            if(isdigit(n[i])){
                number = (int(n[i]) - 48) + (number * (j * 10)); //On transforme les caracteres en chiffre
                j++;
            }
        }

        if(number > 0){
            return number - 1; //On fait -1 car notre tableau commence a 0
        }
    }

    return number - 1; //On fait -1 car notre tableau commence a 0
}

bool verification(char gameTable[], int gridSize){ //On verifie l'alignement des pions
    int maxLength = 0;
    bool changed = false;

    if(gridSize == 3){ maxLength = gridSize; } //Si la taille de notre grille est a 3 alors on doit aligner 3 pions
    if(gridSize > 3){ //Si la taille de la grille est superieur a 3 alors on doit aligner la taille de la grille - 1
        maxLength = gridSize - 1;
        changed = true;
    }

    for(int i = 0; i < gridSize * 2; i++){ //On parcours les 2 premiers ligne du morpions 
        int player = 0;
        if(gameTable[i] == morpion_player1) { player = 0; }else{ player = 1; }

        int n = 0;
        for(int j = 0; j < maxLength; j++){ //On verifie tout les posibilite vertical des 2 joueurs
            if(gameTable[i] == morpion_player1){
                if(gameTable[j * gridSize + i] == morpion_player1){ //Si c'est le joueur 1
                    n++;
                }
            }else{
                if(gameTable[j * gridSize + i] == morpion_player2){ //Si c'est le joueur 2
                    n++;
                }
            }
            if(n == maxLength){ //Si la longeur demander pour gagne et egale au nombre de pion aligner
                std::cout<<"Le joueur "<<(player + 1)<<" a gagne en vertical"<<std::endl; //On dit le joueur qui a gagne et comment
                return true;
            }
        }

        if(i == 0 || (changed && (i == 1 || i == gridSize || i == gridSize + 1))){ //Que si on est dans le coin gauche dans les 4 cases
            int n = 0;
            for(int j = 0; j < maxLength; j++){ //On verifie tout les posibilite en diagonal de gauche a droite des 2 joueurs
                if(gameTable[i] == morpion_player1){
                    if(gameTable[j * gridSize + j + i] == morpion_player1){ //Si c'est le joueur 1
                        n++;
                    }
                }else{
                    if(gameTable[j * gridSize + j + i] == morpion_player2){ //Si c'est le joueur 2
                        n++;
                    }
                }

                if(n == maxLength){ //Si la longeur demander pour gagne et egale au nombre de pion aligner
                    std::cout<<"Le joueur "<<(player + 1)<<" a gagne en digonal 1"<<std::endl; //On dit le joueur qui a gagne et comment
                    return true;
                }
            }
        }

        if(i == gridSize - 1 || (changed && (i == gridSize - 2 || i == gridSize * 2 - 1 || i == gridSize * 2 - 2))){ //Que si on est dans le coin droite dans les 4 cases
            int n = 0;
            for(int j = 0; j < maxLength; j++){ //On verifie tout les posibilite en diagonal de droite a gauche des 2 joueurs
                if(gameTable[i] == morpion_player1){
                    if(gameTable[j * gridSize - j + i] == morpion_player1){ //Si c'est le joueur 1
                        n++;
                    }
                }else{
                    if(gameTable[j * gridSize - j + i] == morpion_player2){ //Si c'est le joueur 2
                        n++;
                    }
                }

                if(n == maxLength){ //Si la longeur demander pour gagne et egale au nombre de pion aligner
                    std::cout<<"Le joueur "<<(player + 1)<<" a gagne en digonal 2"<<std::endl; //On dit le joueur qui a gagne et comment
                    return true;
                }
            }
        }
    }

    for(int i = 0; i < gridSize * 2; i++){ //On parcours les 2 premiers colonne du morpion 
        int player = 0;
        if(gameTable[i] == morpion_player1) { player = 0; }else{ player = 1; }

        int n = 0;
        for(int j = 0; j < maxLength; j++){ //On verifie tout les posibilite en horizontal des 2 joueurs
            
            int ii = 0;

            if(i / gridSize >= 1){
                ii = (i - gridSize) * gridSize + 1;
            }else{
                ii = i * gridSize;
            }

            if(gameTable[ii] == morpion_player1){
                if(gameTable[ii + j] == morpion_player1){ //Si c'est le joueur 1
                    n++;
                }
           }else{
                if(gameTable[ii + j] == morpion_player2){ //Si c'est le joueur 2
                    n++;
                }
           }

           if(n == maxLength){ //Si la longeur demander pour gagne et egale au nombre de pion aligner
                std::cout<<"Le joueur "<<(player + 1)<<" a gagne en horizontal"<<std::endl; //On dit le joueur qui a gagne et comment
                return true;
            }
        }
    }

    return false;
}

void logo(){
    const char* text_color = "\x1B[32m";
    const char* text_end = "\x1B[0m";

    std::cout<<text_color<<" __  __   ______   _____   _____  _____  ______   _   _ "<<text_end<<std::endl;
    std::cout<<text_color<<"|  \\/  | /  __  \\ |  __ \\ |  __ \\ \\_ _/ /  __  \\ | \\ | |"<<text_end<<std::endl; 
    std::cout<<text_color<<"| \\  / | | |  | | | |__)  | |__) | | |  | |  | | |  \\| |"<<text_end<<std::endl; 
    std::cout<<text_color<<"| |\\/| | | |  | | |  _  / |  ___/  | |  | |  | | |     |"<<text_end<<std::endl; 
    std::cout<<text_color<<"| |  | | | |__| | | | \\ \\ | |     _| |_ | |__| | | |\\  |"<<text_end<<std::endl; 
    std::cout<<text_color<<"|_|  |_| \\______/ |_|  \\_ \\_|    |_____|\\______/ |_| \\_|"<<text_end<<std::endl;

    std::cout<<std::endl;
}

void clear(){ //Permet d'effacer la console
    system("clear");
}

void render(char gameTable[], int gridSize){ //On fait le rendu de la grille de morpion
    logo(); //On afficher le "logo" du jeu

    for(int y = 0; y < gridSize; y++){
        for(int x = 0; x < gridSize - 1; x++){  //-1 = Decoration
            std::cout<<"       |"; 
        }
        std::cout<<""<<std::endl;

        for(int x = 0; x < gridSize; x++){
            int n = (y * gridSize + x + 1);
            if(n < 10){
                if(gameTable[n - 1] != '\0'){ 
                    const char* color;

                    if(gameTable[n - 1] == morpion_player1) { color = morpion_color1; }
                    else{ color = morpion_color2; }

                    if(x == gridSize - 1){ //Decoration
                        std::cout<<"   "<<color<<gameTable[n - 1]<<"\033[0m";
                    }else{
                        std::cout<<"   "<<color<<gameTable[n - 1]<<"\033[0m"<<"   |";
                    }
                }else{ 
                    if(x == gridSize - 1){ //Decoration
                        std::cout<<"   "<<n; 
                    }else{
                        std::cout<<"   "<<n<<"   |"; 
                    }
                }
            }else{
                if(gameTable[n - 1] != '\0'){ 
                    const char* color;

                    if(gameTable[n - 1] == morpion_player1) { color = morpion_color1; }
                    else{ color = morpion_color2; }

                    if(x == gridSize - 1){ //Decoration
                        std::cout<<"   "<<color<<gameTable[n - 1]<<"\033[0m"; 
                    }else{
                        std::cout<<"   "<<color<<gameTable[n - 1]<<"\033[0m"<<"   |"; 
                    }
                }else{ 
                    if(x == gridSize - 1){ //Decoration
                        std::cout<<"   "<<n;
                    }else{
                        std::cout<<"   "<<n<<"  |";
                    } 
                }
            }
        }
        std::cout<<""<<std::endl;

        if(y == gridSize - 1){ //-1 = Decoration
            for(int x = 0; x < gridSize - 1; x++){//-1 = Decoration
                std::cout<<"       |";
            }
            std::cout<<""<<std::endl;
        }else{
            for(int x = 0; x < gridSize; x++){
                if(x == gridSize - 1){
                    std::cout<<"________";
                }else{
                    std::cout<<"_______|";
                }
            }
            std::cout<<""<<std::endl;
        }
    }
    std::cout<<""<<std::endl;
}

int morpion(){ //Contient le coeur du jeu

    clear(); //On efface la console
    logo(); //On afficher le "logo" du jeu

    int gridSize, tempSize = 0;
    
    bool goodSize = false;
    while(!goodSize){ //On demande la taille de la grille avec un min de 3 et un max de 10
        std::cout<<"La taille de la grille ? min: 3 et max: 10"<<std::endl;
        std::cin>>tempSize;

        if(tempSize >= 3 && tempSize <= 10){ //On verifie que la taille rentre est correcte
            goodSize = true;
            gridSize = tempSize;
        }
    }

    char gameTable[gridSize * gridSize] = {}; //On cree le tableau de notre jeu

    int round = 0;
    int finish = false;

    while(!finish){ //On cree notre boucle de jeu principale

        clear(); //On efface la console

        int player = round % 2;
        bool isValid = false;

        render(gameTable, gridSize); //On affiche la grille du morpion

        while(!isValid){ //Tant que le chiffre du joueur correspond a une case de la grille
            int cases = select(player); //On demande le chiffre au joueur

            if(cases >= 0 && cases <= gridSize * gridSize + 1){ //On verifie si la case indiquer et bonne
                if(gameTable[cases] == '\0'){//On attribue le pion si la case est vide
                    if(player == 0) { gameTable[cases] = morpion_player1; }else { gameTable[cases] = morpion_player2; }
                    isValid = true;
                }
            }
        }

        round++;

        if(round >= gridSize * gridSize){ //Si le nombre de round et egale au nombre de case dans la grille alors tout les cases sont utilise
            finish = true;
            clear(); //On efface la console
            render(gameTable, gridSize); //On reafiche la grille
            std::cout<<"Egalite"<<std::endl; //On ecrit qu'il y a egalite
        }

        if(verification(gameTable, gridSize)){ //On verifie la grille pour savoir si un joueur a gagne
            finish = true;
            clear(); //On efface la console
            render(gameTable, gridSize); //On reafiche la grille
            verification(gameTable, gridSize); //On dit quelle joueur a gagne est comment
        }

    }

    return 0;
}