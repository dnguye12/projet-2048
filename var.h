#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <math.h>
#include <vector>
#include <iostream>
#include<bits/stdc++.h>
#include <curses.h>
#include <map>
#include <chrono>
#include <thread>

#define GET_VARIABLE_NAME(Variable) (#Variable)

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

/**Affiche le menu quand on joue la variation
* @param Plateau plat1 le premier plateau
* @param Plateau plat2 le deuxieme plateau
* @param bool L'etat de AI
**/
void menudejeu_var(Plateau plat1, Plateau plat2, bool ai);


/**Affiche le menu de la variation quand le jouer a perdu
* @param Plateau plat1 le premier plateau
* @param Plateau plat2 le deuxieme plateau
* @param bool L'etat de AI
**/
void findepartie_var(Plateau plat1, Plateau plat2, bool ai);


/** la fonction tireDeuxOuQuatre pour la mode variation
* @return 2 ou 4
**/
int tireDeuxOuQuatre_var();


/** la fonction plateauInitial pour la mode variation
* @return un Plateau en début de jeu
**/
Plateau plateauInitial_var();


/** la fonction addblock pour la mode variation
 * @param plateau un Plateau
 * @return le plateau apres on a ajoute un nouveau bloc
 **/
Plateau addblock_var(Plateau plat);


/** le code pour faire la mode variation functionnel
 **/
void joue_var();
#endif // VAR_H_INCLUDED
