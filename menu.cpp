#include "modele.h"

void openmenu()
{
    initscr();
    start_color();
    clear();
    noecho();
    curs_set(0);
    keypad(stdscr, 1);
    string l1 =  R"(
				     _______  ________  ___   ___  ________
				    /  ___  \|\   __  \|\  \ |\  \|\   __  \
				   /__/|_/  /\ \  \|\  \ \  \\_\  \ \  \|\  \
				   |__|//  / /\ \  \\\  \ \______  \ \   __  \
				       /  /_/__\ \  \\\  \|_____|\  \ \  \|\  \
				      |\________\ \_______\     \ \__\ \_______\
				       \|_______|\|_______|      \|__|\|_______|


)";
    init_pair(10, 10, COLOR_BLACK);
    attron(COLOR_PAIR(10));
    printw(l1.c_str());
    attroff(COLOR_PAIR(10));
    printw("\n\n\n");
    printw("\t\t\t\t  Appuyez sur n'importe quelle touche pour continuer");
    getch();
    refresh();
    endwin();
}


void initcolor() {
    init_pair(1, 1, COLOR_BLACK);
    init_pair(2, 2, COLOR_BLACK);
    init_pair(3, 3, COLOR_BLACK);
    init_pair(4, 4, COLOR_BLACK);
    init_pair(5, 5, COLOR_BLACK);
    init_pair(6, 6, COLOR_BLACK);
    init_pair(7, 7, COLOR_BLACK);
    init_pair(8, 9, COLOR_BLACK);
    init_pair(9, 10, COLOR_BLACK);
    init_pair(10, 11, COLOR_BLACK);
    init_pair(11, 12, COLOR_BLACK);
    init_pair(12, 13, COLOR_BLACK);
    init_pair(13, 14, COLOR_BLACK);
}

void gamemenu(Plateau plat, bool ai) {
    start_color();
    initcolor();

        string l2 =R"(			       			       COMMANDES
	        		       ,---,                            ,---,
	        		       | H |                            | ^ |
	    			   ,---,---,---,	 ,---,      ,---,---,---,
	    			   | G | B | D |	 | A |      | < | v | > |
	    			   '---'---'---'	 '---'      '---'---'---')";
    printw("\n");
    printw("\t\t\t\t\t  Appuyez sur Esc pour quitter le jeux ");
    printw("\n\t\t\t\t\t\t\tScore: ");
    printw(to_string(score(plat)).c_str());
    printw("\n");
    if(ai)
    {
        attron(COLOR_PAIR(9));
        printw("\t\t\t\t\t\t     AI activated!");
        attroff(COLOR_PAIR(9));
    }
    else
    {
        attron(COLOR_PAIR(8));
        printw("\t\t\t\t\t\t     AI deactivate!");
        attroff(COLOR_PAIR(8));
    }
    printw("\n\n\n");
    dessinecolor(plat);
    printw("\n");
    printw(l2.c_str());
}

void endmenu(Plateau plat)
{
    int ch;
    initscr();
    start_color();
    initcolor();
    string gameover = R"(
		 ________  ________  _____ ______   _______           ________  ___      ___ _______   ________
		|\   ____\|\   __  \|\   _ \  _   \|\  ___ \         |\   __  \|\  \    /  /|\  ___ \ |\   __  \
		\ \  \___|\ \  \|\  \ \  \\\__\ \  \ \   __/|        \ \  \|\  \ \  \  /  / | \   __/|\ \  \|\  \
		 \ \  \  __\ \   __  \ \  \\|__| \  \ \  \_|/__       \ \  \\\  \ \  \/  / / \ \  \_|/_\ \   _  _\
		  \ \  \|\  \ \  \ \  \ \  \    \ \  \ \  \_|\ \       \ \  \\\  \ \    / /   \ \  \_|\ \ \  \\  \|
		   \ \_______\ \__\ \__\ \__\    \ \__\ \_______\       \ \_______\ \__/ /     \ \_______\ \__\\ _\
		    \|_______|\|__|\|__|\|__|     \|__|\|_______|        \|_______|\|__|/       \|_______|\|__|\|__|



)";
    printw("\n");
    attron(COLOR_PAIR(8));
    printw("\t\t\t\t\t  Appuyez sur Esc pour quitter le jeux ");
    attroff(COLOR_PAIR(8));
    printw("\n\t\t\t\t\t\t\tScore: ");
    printw(to_string(score(plat)).c_str());
    printw("\n\n\n");
    dessinecolor(plat);
    printw("\n");
    attron(COLOR_PAIR(8));
    printw(gameover.c_str());
    attroff(COLOR_PAIR(8));
    while(true) {
        ch = getch();
        if(ch == 27) {
            endwin();
            break;
        }
    }
}




