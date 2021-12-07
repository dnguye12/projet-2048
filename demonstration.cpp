#include "modele.h"

int main()
{
    Plateau plat = plateauInitial();
    Plateau last = plateauVide();
    //int ch;
    bool ai{false};
    system("cls");
    cout << dessine(plat);

    while(true)
    {
        char ch;
        last = plat;
        system("cls");
        cout << "\n  Appuyez sur Q pour quitter le jeux ";
        cout << "\n\t     Score: ";
        cout << to_string(score(plat)) << "\n\n";
        cout << dessine(plat);
        cout << "Entre votre commande:";
        cin >> ch;
        if(ch == 'h')
    {
        plat = deplacementHaut(plat);
        }
        if(ch == 'g')
    {
        plat = deplacementGauche(plat);
        }
        if(ch == 'd')
    {
        plat = deplacementDroite(plat);
        }
        if(ch == 'b')
    {
        plat = deplacementBas(plat);
        }
        if(ch == 'q')
    {
        break;
    }
    if(!nomoved(last, plat)) {
        plat = addblock(plat);
    }

    if(estTermine(plat)) {
        break;
    }
}
system("cls");
        cout << "\n  Appuyez sur Q pour quitter le jeux ";
        cout << "\n\t     Score: ";
        cout << to_string(score(plat)) << "\n\n";
        cout << dessine(plat);
        cout << "Vouz avez perdu";
return 0;
}
