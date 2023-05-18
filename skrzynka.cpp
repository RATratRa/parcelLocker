
#include "skrzynka.h"

bool skrzynka::wloz_paczke(int wys_paczki, int szer_paczki) {
    if (czy_pelna || wys_paczki > wysokosc || szer_paczki > szerokosc) {
        cout << "\tSkrzynka jest zajeta, albo rozmiary zawielki!" << endl;
        return false;
    }
    else {
        czy_pelna = true;
        return true;
    }
}

void paczkomat::wloz_paczke(int ID, int wys, int sz) {
    int jaka_skrzynka;
    if (wys <= 100 && sz <= 90) {
        jaka_skrzynka = 1;

    }
    else if ((wys > 100 && wys <= 200) || (sz > 90 && sz <= 150)) {
        jaka_skrzynka = 2;

    }
    else if ((wys > 200 && wys <= 400) || (sz > 150 && sz <= 300)) {
        jaka_skrzynka = 3;

    }
    else {
        jaka_skrzynka = 0;
    }

    switch (jaka_skrzynka)
    {
    case 1:
        if (!wsk_skr_mala[ID] && ID < liczba_skrzynek_malych) {
            wsk_skr_mala[ID] = new skrzynka(wys_skr_mala, szer_skr_mala);
            if (wsk_skr_mala[ID]->wloz_paczke(wys, sz)) {
                cout << "\tWlozylem do skrzynki Malej! " << "Skrzynka Nr: " << ID << "\n" << endl;
            }
            else {
                delete[] wsk_skr_mala[ID];
                wsk_skr_mala[ID] = NULL;
            }
        }
        else {
            cout << "\tERROR!" << endl;
        }
        break;
    case 2:
        if (!wsk_skr_srednia[ID] && ID < liczba_skrzynek_srednich) {
            wsk_skr_srednia[ID] = new skrzynka(wys_skr_srednia, szer_skr_srednia);
            if (wsk_skr_srednia[ID]->wloz_paczke(wys, sz)) {
                cout << "\tWlozylem do skrzynki Sredniej! " << "Skrzynka Nr: " << ID << "\n" << endl;
            }
            else {
                delete[] wsk_skr_srednia[ID];
                wsk_skr_srednia[ID] = NULL;
            }
        }
        else {
            cout << "\tERROR!" << endl;
        }
        break;
    case 3:
        if (!wsk_skr_duza[ID] && ID < liczba_skrzynek_duzych) {
            wsk_skr_duza[ID] = new skrzynka(wys_skr_duza, szer_skr_duza);
            if (wsk_skr_duza[ID]->wloz_paczke(wys, sz)) {
                cout << "\tWlozylem do skrzynki Duzej! " << "Skrzynka Nr: " << ID << "\n" << endl;
            }
            else {
                delete[] wsk_skr_duza[ID];
                wsk_skr_duza[ID] = NULL;
            }
        }
        else {
            cout << "\tERROR!" << endl;
        }
        break;
    case 0:
        cout << "ERROR!" << endl;
        break;
    default:
        cout << "ERROR!" << endl;
        break;
    }


}
void paczkomat::zobacz() {
    string status_skrzyniek_malych[15];
    string status_skrzyniek_srednich[15];
    string status_skrzyniek_duzych[15];
    for (int i = 0; i < 15; i++) {
        if (!wsk_skr_mala[i]) {
            status_skrzyniek_malych[i] = "PUSTA!";
        }
        else {
            status_skrzyniek_malych[i] = "ZAJETA!";
        }

        if (!wsk_skr_srednia[i]) {
            status_skrzyniek_srednich[i] = "PUSTA!";
            if (i >= 10) {
                status_skrzyniek_srednich[i] = "-----";
            }
        }
        else if (i >= 10) {
            status_skrzyniek_srednich[i] = "-----";
        }
        else {
            status_skrzyniek_srednich[i] = "ZAJETA!";
        }

        if (!wsk_skr_duza[i]) {
            status_skrzyniek_duzych[i] = "PUSTA!";

        }
        else if (i >= 4) {
            status_skrzyniek_duzych[i] = "-----";
        }
        else {
            status_skrzyniek_duzych[i] = "ZAJETA!";
        }
    }

    cout << "\tNR        Mala         Srednia         Duza" << endl;
    cout.setf(ios::fixed | ios::right);
    for (int i = 0; i < 15; i++) {
        cout << "\t"
            << setw(2) << i << "    "
            << setw(10) << setprecision(2) << status_skrzyniek_malych[i] << "    "
            << setw(10) << setprecision(2) << status_skrzyniek_srednich[i] << "    "
            << setw(10) << setprecision(1) << status_skrzyniek_duzych[i] << endl;
    }

}
void paczkomat::wyjmij(int ID, int jaka_skrzynka) {
    switch (jaka_skrzynka)
    {
    case 1:
        if (wsk_skr_mala[ID] && ID < liczba_skrzynek_malych) {
            delete[] wsk_skr_mala[ID];
            wsk_skr_mala[ID] = NULL;
            cout << "\n\tPaczka wyjeta! Skrzynka zostala pusta!\n" << endl;
        }
        else {
            cout << "\n\tSkrzynka pusta, albo nie istnieje\n" << endl;
        }

        break;
    case 2:
        if (wsk_skr_srednia[ID] && ID < liczba_skrzynek_srednich) {
            delete[] wsk_skr_srednia[ID];
            wsk_skr_srednia[ID] = NULL;
            cout << "\n\tPaczka wyjeta! Skrzynka zostala pusta!\n" << endl;
        }
        else {
            cout << "\n\tSkrzynka pusta, albo nie istnieje\n" << endl;
        }
        break;
    case 3:
        if (wsk_skr_duza[ID] && ID < liczba_skrzynek_duzych) {
            delete[] wsk_skr_duza[ID];
            wsk_skr_duza[ID] = NULL;
            cout << "\n\tPaczka wyjeta! Skrzynka zostala pusta!\n" << endl;
        }
        else {
            cout << "\n\tSkrzynka pusta, albo nie istnieje\n" << endl;
        }
        break;
    default:
        cout << "\n\tSkrzynka pusta, albo nie istnieje\n" << endl;
        break;
    }

}