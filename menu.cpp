#include "modele.h"
#include "var.h"

void menuaccueil()
{
    initscr();
    noecho();
    start_color();
    curs_set(0);

    int y, x;
    getmaxyx(stdscr, y, x);

    string choices[3] = {"1. Classique",
                         "2. Deux Tables",
                         "3. Quitter"};
    int choice;
    int highlight{0};

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
    printw("\n\n\n\n\n");
    printw(l1.c_str());
    attroff(COLOR_PAIR(10));

    WINDOW * menu = newwin(5, x - 107, y - 53, 50);
    refresh();
    wrefresh(menu);

    keypad(menu, 1);


    while(1)
    {
        for(int i = 0; i < 3; i++)
        {
            if(i == highlight)
            {
                wattron(menu, A_REVERSE);}
                mvwprintw(menu, i+1, 1, choices[i].c_str());
                wattroff(menu, A_REVERSE);

        }
        choice = wgetch(menu);
        switch(choice) {
        case KEY_UP:
            highlight--;
            if(highlight < 0) {
                highlight = 2;
            }
            break;
        case KEY_DOWN:
            highlight++;
            if(highlight > 2) {
                highlight = 0;
            }
            break;
        default:
            break;
        }

        if(choice == 10) {
            if(highlight == 0) {
                joue();
                endwin();
                break;
            }
            if(highlight == 1) {
                joue_var();
                endwin();
                break;
            }
            if(highlight == 2) {
                endwin();
                break;
            }
        }
    }
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

void menudejeu(Plateau plat, bool ai) {
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
    printw(to_string(score(plat) -16).c_str());
    printw("\n");
    if(ai)
    {
        attron(COLOR_PAIR(9));
        printw("\t\t\t\t\t\t     IA activée");
        attroff(COLOR_PAIR(9));
    }
    else
    {
        attron(COLOR_PAIR(8));
        printw("\t\t\t\t\t\t     IA désactivée");
        attroff(COLOR_PAIR(8));
    }
    printw("\n\n\n");
    dessinecolor(plat);
    printw("\n");
    printw(l2.c_str());
}

void findepartie(Plateau plat)
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
    printw(to_string(score(plat) - 16).c_str());
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



