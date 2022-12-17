#include <iostream>

const int maxTry = 14;

int animation(int frame){

    switch(frame){
        
        case 0:
            std::cout<<" __________"<<std::endl;
            std::cout<<" | /" <<std::endl;
            std::cout<<" |/ "<<std::endl;
            std::cout<<" |  "<<std::endl;
            std::cout<<" |  "<<std::endl;
            std::cout<<" |  "<<std::endl;
            std::cout<<"/ \\"<<std::endl;
        break;

        case 1:
            std::cout<<" __________"<<std::endl;
            std::cout<<" | /           " <<std::endl;
            std::cout<<" |/           "<<std::endl;
            std::cout<<" |          "<<std::endl;
            std::cout<<" |       _____                               O"<<std::endl;
            std::cout<<" |       |   |__                            /|\\"<<std::endl;
            std::cout<<"/ \\      |      |                           / \\"<<std::endl;
        break;

        case 2:
            std::cout<<" __________"<<std::endl;
            std::cout<<" | /           " <<std::endl;
            std::cout<<" |/            "<<std::endl;
            std::cout<<" |          "<<std::endl;
            std::cout<<" |       _____                              O"<<std::endl;
            std::cout<<" |       |   |__                           /|\\"<<std::endl;
            std::cout<<"/ \\      |      |                          / \\"<<std::endl;
        break;

        case 3:
            std::cout<<" __________"<<std::endl;
            std::cout<<" | /           " <<std::endl;
            std::cout<<" |/            "<<std::endl;
            std::cout<<" |          "<<std::endl;
            std::cout<<" |       _____                      O"<<std::endl;
            std::cout<<" |       |   |__                   /|\\"<<std::endl;
            std::cout<<"/ \\      |      |                  / \\"<<std::endl;
        break;

        case 4:
            std::cout<<" __________"<<std::endl;
            std::cout<<" | /           " <<std::endl;
            std::cout<<" |/            "<<std::endl;
            std::cout<<" |          "<<std::endl;
            std::cout<<" |       _____                   O"<<std::endl;
            std::cout<<" |       |   |__                /|\\"<<std::endl;
            std::cout<<"/ \\      |      |               / \\"<<std::endl;
        break;

        case 5:
            std::cout<<" __________"<<std::endl;
            std::cout<<" | /          " <<std::endl;
            std::cout<<" |/            "<<std::endl;
            std::cout<<" |          "<<std::endl;
            std::cout<<" |       _____              O"<<std::endl;
            std::cout<<" |       |   |__           /|\\"<<std::endl;
            std::cout<<"/ \\      |      |          / \\"<<std::endl;
        break;

        case 6:
            std::cout<<" __________"<<std::endl;
            std::cout<<" | /           " <<std::endl;
            std::cout<<" |/            "<<std::endl;
            std::cout<<" |          "<<std::endl;
            std::cout<<" |       _____            O"<<std::endl;
            std::cout<<" |       |   |__         /|\\"<<std::endl;
            std::cout<<"/ \\      |      |        / \\"<<std::endl;
        break;

        case 7:
            std::cout<<" __________"<<std::endl;
            std::cout<<" | /           " <<std::endl;
            std::cout<<" |/            "<<std::endl;
            std::cout<<" |          "<<std::endl;
            std::cout<<" |       _____           O"<<std::endl;
            std::cout<<" |       |   |__        /|\\"<<std::endl;
            std::cout<<"/ \\      |      |       / \\"<<std::endl;
        break;

        case 8:
            std::cout<<" __________"<<std::endl;
            std::cout<<" | /          " <<std::endl;
            std::cout<<" |/           "<<std::endl;
            std::cout<<" |          "<<std::endl;
            std::cout<<" |       _____        O"<<std::endl;
            std::cout<<" |       |   |__     /|\\"<<std::endl;
            std::cout<<"/ \\      |      |    / \\"<<std::endl;
        break;

        case 9:
            std::cout<<" __________"<<std::endl;
            std::cout<<" | /          " <<std::endl;
            std::cout<<" |/           "<<std::endl;
            std::cout<<" |          "<<std::endl;
            std::cout<<" |       _____      /o\\"<<std::endl;
            std::cout<<" |       |   |__     |"<<std::endl;
            std::cout<<"/ \\      |      |   / \\"<<std::endl;
        break;

        case 10:
            std::cout<<" _________"<<std::endl;
            std::cout<<" | /                    "<<std::endl;
            std::cout<<" |/                   "<<std::endl;
            std::cout<<" |             O            "<<std::endl;
            std::cout<<" |       _____/|\\           "<<std::endl;
            std::cout<<" |       |   |/ \\             "<<std::endl;
            std::cout<<"/ \\      |      |            "<<std::endl;
        break;

        case 11:
            std::cout<<" __________"<<std::endl;
            std::cout<<" | /      O      |3|    "<<std::endl;
            std::cout<<" |/      /|\\       "<<std::endl;
            std::cout<<" |       / \\        "<<std::endl;
            std::cout<<" |       _____           " <<std::endl;
            std::cout<<" |       |   |__     " <<std::endl;
            std::cout<<"/ \\      |      | "<<std::endl;
        break;

        case 12:
            std::cout<<" __________"<<std::endl;
            std::cout<<" | /      O      |2|"<<std::endl;
            std::cout<<" |/      /|\\"<<std::endl;
            std::cout<<" |       / \\"<<std::endl;
            std::cout<<" |          "<<std::endl;
            std::cout<<" |          "<<std::endl;
            std::cout<<"/ \\        "<<std::endl;
        break;

        case 13:
            std::cout<<" __________"<<std::endl;
            std::cout<<" | /      |       |1|    "<<std::endl;
            std::cout<<" |/       O      DEAD     "<<std::endl;
            std::cout<<" |       /|\\         "<<std::endl;
            std::cout<<" |       / \\         "<<std::endl;
            std::cout<<" |          "<<std::endl;
            std::cout<<"/ \\                "<<std::endl;
        break;
    }
}