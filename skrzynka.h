#include <iostream>
#include <iomanip>


using namespace std;

class skrzynka {
private:
    int wysokosc;
    int szerokosc;
    bool czy_pelna;

public:
    skrzynka(int wys, int szer) {
        wysokosc = wys;
        szerokosc = szer;
        czy_pelna = false;
    }

    bool wloz_paczke(int wys_paczki, int szer_paczki);
};

class paczkomat {
private:
    const static int liczba_skrzynek_malych = 15;
    const static int liczba_skrzynek_srednich = 10;
    const static int liczba_skrzynek_duzych = 5;

    skrzynka* wsk_skr_mala[liczba_skrzynek_malych];
    skrzynka* wsk_skr_srednia[liczba_skrzynek_srednich];
    skrzynka* wsk_skr_duza[liczba_skrzynek_duzych];

    int wys_skr_mala = 100;
    int szer_skr_mala = 90;

    int wys_skr_srednia = 200;
    int szer_skr_srednia = 150;

    int wys_skr_duza = 400;
    int szer_skr_duza = 300;


public:
    paczkomat() {
        for (int i = 0; i < liczba_skrzynek_malych; i++) {
            wsk_skr_mala[i] = NULL;
        }
        for (int i = 0; i < liczba_skrzynek_srednich; i++) {
            wsk_skr_srednia[i] = NULL;
        }
        for (int i = 0; i < liczba_skrzynek_duzych; i++) {
            wsk_skr_duza[i] = NULL;
        }
    }
    ~paczkomat() {
        for (int i = 0; i < liczba_skrzynek_malych; i++) {
            delete[] wsk_skr_mala[i];
            wsk_skr_mala[i] = NULL;
        }
        for (int i = 0; i < liczba_skrzynek_srednich; i++) {
            delete[] wsk_skr_srednia[i];
            wsk_skr_srednia[i] = NULL;
        }
        for (int i = 0; i < liczba_skrzynek_duzych; i++) {
            delete[] wsk_skr_duza[i];
            wsk_skr_duza[i] = NULL;
        }
    }
    void wloz_paczke(int ID, int wys, int sz);
    void zobacz();
    void wyjmij(int ID, int jaka_skrzynka);

};