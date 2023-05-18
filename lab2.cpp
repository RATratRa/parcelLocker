#include <iostream>
#include <iomanip>
#include "skrzynka.h"
#include <conio.h>

using namespace std;


int main()
{
    paczkomat paczkomat;
    int choose;
    int main_ID, main_WYS, main_SZER, main_rozm_skr;
    system("color 02");
    cout << "\n\t\tAPLIKACJA PACZKOMAT\n" << endl;
    
    while (true)
    {
        cout << "1. Zobach wrzyscy skrzynce.\n"
             << "2. Wloz paczke\n"
             << "3. Wyjmij paczke\n"
             << "0. Zamknij\n" << endl;
        cout << "Wybierz opcje: "; cin >> choose;
        switch (choose)
        {
        case 1:
            paczkomat.zobacz();
            break;
        case 2:
            cout << "Mala skrzynka - (100 x 90)\n" 
                 << "Srednia skrzynka - (200 x 150)\n" 
                 << "Duza skrzynka - (400 x 300)\n"  << endl;
            cout << "\tWprowadz - ID_SKRZYNKI, WYSOKOSC, SZEROKOSC | N.P(1 90 90): "; cin >> main_ID; cin >> main_WYS; cin >> main_SZER;
            paczkomat.wloz_paczke(main_ID, main_WYS, main_SZER);
            break;
        case 3:
            cout << "Mala skrzynka - 1\n"
                << "Srednia skrzynka - 2\n"
                << "Duza skrzynka - 3\n" << endl;
            cout << "\tWprowadz - ID_SKRZYNKI, ROZMIAR_SKRZYNKI | N.P(0 1): "; cin >> main_ID; cin >> main_rozm_skr;
            paczkomat.wyjmij(main_ID, main_rozm_skr);
            break;
        case 0:
            return 0;
            break;
        default:
            cout << "\n\tWybierz poprawne opcje!\n" << endl;
            break;
        }
    }

    return 0;
}