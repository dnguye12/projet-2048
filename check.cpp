#include "modele.h"

#define CHECK(test) if ( !(test)) cout << "Test failed in file " \
<< __FILE__ << " line " << __LINE__ << ": " #test << endl

void tests() {
    vector<vector<int>> test{{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    CHECK(plateauVide() == test);

    test = {{0,1,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    CHECK(plateauVide() != test);



    CHECK(tireDeuxOuQuatre() == 2 or tireDeuxOuQuatre() == 4);


    test = {{2,0,0,0},{2,0,0,0},{2,0,0,0},{4,0,0,0}};
    CHECK(deplacementGauche({{0,0,2,0},{0,0,2,0},{2,0,0,0},{4,0,0,0}}) == test);


    test = {{0,0,0,2},{0,0,0,2},{0,0,0,2},{0,0,0,4}};
    CHECK(deplacementDroite({{0,0,2,0},{0,0,2,0},{2,0,0,0},{4,0,0,0}}) == test);


    Plateau helper = plateauInitial();
    CHECK(deplacement(helper, KEY_UP) == deplacementHaut(helper));
    CHECK(deplacement(helper, KEY_DOWN) == deplacementBas(helper));


    test = {{2,4,2,4},{4,2,4,2},{2,4,2,4},{4,2,4,2}};
    CHECK(estTermine(test));


    test = {{2048,2,2,2},{4,2,4,2},{2,4,2,4},{4,2,4,2}};
    CHECK(estGagnant(test));


    test = {{2,0,0,2},{2,0,0,0},{2,0,0,0},{4,0,0,4}};
    CHECK(score(test) == 0);
    CHECK(score(deplacementDroite(test)) == 12);


    CHECK(nomoved(test, test));
    CHECK(!nomoved(test, deplacementBas(test)));


    CHECK(repow(64) == 6);
}
