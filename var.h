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

void gamemenu_var(Plateau plat1, Plateau plat2, bool ai);


void endmenu_var(Plateau plat1, Plateau plat2, bool ai);


int tireDeuxOuQuatre_var();


Plateau plateauInitial_var();


Plateau addblock_var(Plateau plat);


void joue_var();
#endif // VAR_H_INCLUDED
