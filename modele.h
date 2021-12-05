#ifndef MODELE_H_INCLUDED
#define MODELE_H_INCLUDED

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

typedef vector<vector<int> > Plateau;

map<string, int> score_list;


/** g�n�re un Plateau de dimensions 4*4 ne contenant que des 0
 *  @return un Plateau vide
 **/
Plateau plateauVide();


/** g�n�re deux nombres sur des cases al�atoires d'un Plateau vide
 *  @return un Plateau en d�but de jeu
 **/
Plateau plateauInitial();


/** g�n�re al�atoirement un 2 ou un 4 avec des probabilit�s respectives de 9/10 et 1/10
 *  @return 2 ou 4
 **/
int tireDeuxOuQuatre();


/** d�place les tuiles d'un Plateau vers la gauche et les combine si possible
 *  @param plateau le Plateau
 *  @return le Plateau une fois d�plac� vers la gauche
 **/
Plateau deplacementGauche(Plateau plateau);


/** d�place les tuiles d'un Plateau vers la droite et les combine si possible
 *  @param plateau le Plateau
 *  @return le Plateau une fois d�plac� vers la droite
 **/
Plateau deplacementDroite(Plateau plateau);


/** d�place les tuiles d'un Plateau vers le haut et les combine si possible
 *  @param plateau le Plateau
 *  @return le Plateau une fois d�plac� vers le haut
 **/
Plateau deplacementHaut(Plateau plateau);


/** d�place les tuiles d'un Plateau vers le bas et les combine si possible
 *  @param plateau le Plateau
 *  @return le Plateau une fois d�plac� vers le bas
 **/
Plateau deplacementBas(Plateau plateau);


/** d�place les tuiles d'un Plateau dans la direction donn�e et g�n�re une nouvelle tuile si le d�placement est valide
 *  @param plateau le Plateau
 *  @param direction la direction
 *  @return le Plateau d�plac� dans la direction
 **/
Plateau deplacement(Plateau plateau, int direction);


/** affiche un Plateau
 * @param p le Plateau
 **/
string dessine(Plateau p);


/** permet de savoir si une partie est termin�e
 *  @param plateau un Plateau
 *  @return true si le plateau est vide, false sinon
 **/
bool estTermine(Plateau plateau);


/** permet de savoir si une partie est gagn�e
 * @param plateau un Plateau
 * @return true si le plateau contient un 2048, false sinon
 **/
bool estGagnant(Plateau plateau);


//Custom fonctions


/** retourner le score du plateau
 * @param plateau un Plateau
 * @return le score du plateau
 **/
int score(Plateau plat);


/** permet de savoir si le dernier deplacement etait reussir
 * @param last le plateau avant le deplacement
 * @param plat le plateau apres le deplacement
 * @return true si le plateau ne deplace pas, false sinon
 **/
bool nomoved(Plateau last, Plateau plat);


/** ajouter un nouveau bloc sur le plateau (2 ou 4). Si le jouer etait gagnent, ajoute des blocs plus grands.
 * @param plateau un Plateau
 * @return le plateau apres on a ajoute un nouveau bloc
 **/
Plateau addblock(Plateau plat);


/** Calculer i pour que 2^i = c
 * @param c un integer
 * @return i
 **/
int repow(int c);


/** afficher le plateau en couleur
 * @param plat le Plateau
 **/
void dessinecolor(Plateau plat);


/** le code pour faire le jeux functionnel
 **/
void joue();
#endif // MODELE_H_INCLUDED
