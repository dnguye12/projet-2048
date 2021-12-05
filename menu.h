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

/** afficher le premier menu du jeux
 **/
void openmenu();


/** initialize les colours pour ncurses
**/
void initcolor();


/** afficher le game menu
 * @param plat le Plateau
 * @param ai l'etat de ai(true ou false)
 **/
void gamemenu(Plateau plat, bool ai);



/** afficher le menu quand le jouer a perdu
* @param plat le Plateau
**/
void endmenu(Plateau plat)

#endif // MENU_H_INCLUDED
