#include <iostream>
#include "morpion/morpion.cpp"
#include "pendu/pendu.cpp"
#include "pfc/pfc.cpp"

void launcher(){
    int choice;
    bool good = true;

    std::cout<<"\x1B[32m"<<"__  ____  __     _ "<<std::endl;                 
    std::cout<<"\\ \\/ /\\ \\/ /    | |  ___   _   _  __  __ "<<std::endl; 
    std::cout<<" \\  /  \\  /  _  | | / _ \\ | | | | \\ \\/ /"<<std::endl; 
    std::cout<<" /  \\  /  \\ \\ |_| | | __/ | |_| |  >  < "<<std::endl; 
    std::cout<<"/_/\\_\\/_/\\_\\ \\___/  \\___| \\_____/ /_/\\_\\"<<"\x1B[0m"<<std::endl; 

    std::cout<<std::endl;

    std::cout<<"Bonjour a quels jeux voulait vous jouer"<<std::endl;

    while(good){
        std::cout<<"1: Morpion"<<std::endl;
        std::cout<<"2: Pendu"<<std::endl;
        std::cout<<"3: pierre feuille ciseaux"<<std::endl;
        std::cin>>choice;

        if(choice >= 1 && choice <= 3){
            good = false;
        }else{
            std::cout<<"Ce chiffre ne correspond pas a un jeu"<<std::endl;
        }
    }

    switch(choice){
        case 1: morpion(); break;
        case 2: pendu(); break;
        case 3: pfc(); break;
    }
}

int main(){
    launcher();

    return 0;
}                            
