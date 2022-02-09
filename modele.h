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


/** génère un Plateau de dimension 4*4 ne contenant que des 0
 *  @return un Plateau vide
 **/
Plateau plateauVide(); /*implantée par Gloire LINVANI


/** génère deux nombres sur des cases aléatoires d'un Plateau vide
 *  @return un Plateau en début de jeu
 **/
Plateau plateauInitial(); /*implantée par Gloire LINVANI


/** génè aléatoirement un 2 ou un 4 avec des probabilités respectives de 9/10 et 1/10
 *  @return 2 ou 4
 **/
int tireDeuxOuQuatre(); /*implantée par Gloire LINVANI


/** déplace les tuiles d'un Plateau vers la gauche et les combine si possible
 *  @param plateau le Plateau
 *  @return le Plateau une fois déplacé vers la gauche
 **/
Plateau deplacementGauche(Plateau plateau); /*implantée par Huy NGUYEN


/** déplace les tuiles d'un Plateau vers la droite et les combine si possible
 *  @param plateau le Plateau
 *  @return le Plateau une fois déplacé vers la droite
 **/
Plateau deplacementDroite(Plateau plateau); /*implantée par Huy NGUYEN


/** déplace les tuiles d'un Plateau vers le haut et les combine si possible
 *  @param plateau le Plateau
 *  @return le Plateau une fois déplacé vers le haut
 **/
Plateau deplacementHaut(Plateau plateau); /*implantée par Huy NGUYEN


/** déplace les tuiles d'un Plateau vers le bas et les combine si possible
 *  @param plateau le Plateau
 *  @return le Plateau une fois déplacé vers le bas
 **/
Plateau deplacementBas(Plateau plateau); /*implantée par Huy NGUYEN


/** déplace les tuiles d'un Plateau dans la direction donnée et génère une nouvelle tuile si le deplacement est valide
 *  @param plateau le Plateau
 *  @param direction la direction
 *  @return le Plateau déplacé dans la direction
 **/
Plateau deplacement(Plateau plateau, int direction); /*implantée par Huy NGUYEN


/** affiche un Plateau
 * @param p le Plateau
 **/
string dessine(Plateau p); /*implantée par Gloire LINVANI


/** permet de savoir si une partie est terminée
 *  @param plateau un Plateau
 *  @return true si le plateau est terminée, false sinon
 **/
bool estTermine(Plateau plateau); /*implantée par Gloire LINVANI


/** permet de savoir si une partie est gagnée
 * @param plateau un Plateau
 * @return true si le plateau contient un 2048, false sinon
 **/
bool estGagnant(Plateau plateau); /*implantée par Gloire LINVANI


/** renvoyer le score du plateau
 * @param plat un Plateau
 * @return le score du plateau
 **/
int score(Plateau plat); /*implantée par Huy NGUYEN


/** permet de savoir si le dernier déplacement était réussi
 * @param last le plateau avant le déplacement
 * @param plat le plateau après le deplacement
 * @return true si le plateau n'a pas été déplacé, false sinon
 **/
bool notmoved(Plateau last, Plateau plat); /*implantée par Huy NGUYEN


/** ajouter un nouveau bloc sur le plateau (2 ou 4). Si le jouer avait gagné, ajoute des blocs plus grands.
 * @param plateau un Plateau
 * @return le plateau après avoir ajouté un nouveau bloc
 **/
Plateau addblock(Plateau plat); /*implantée par Huy NGUYEN


/** Calculer i tel que 2^i = c
 * @param c un entier
 * @return i
 **/
int repow(int c); /*implantée par Gloire LINVANI

/** afficher le plateau en couleurs
 * @param plat le Plateau
 **/
void dessinecolor(Plateau plat); /*implantée par Gloire LINVANI


/** le code pour démarrer le jeu 
 **/
void joue();
#endif // MODELE_H_INCLUDED
