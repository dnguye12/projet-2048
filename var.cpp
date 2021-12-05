
void gamemenu_var(Plateau plat1, Plateau plat2, bool ai)
{
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
    printw(to_string(score(plat1)/2 + score(plat2)/2).c_str());
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
    dessinecolor(plat1);
    printw("\n\n");
    dessinecolor(plat2);
    printw("\n");
    printw(l2.c_str());
}

void endmenu_var(Plateau plat1, Plateau plat2, bool ai)
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
    printw(to_string(score(plat1)/2 + score(plat2)/2).c_str());
    printw("\n");
    attron(COLOR_PAIR(8));
    printw("\t\t\t\t\t\t     AI deactivate!");
    attroff(COLOR_PAIR(8));
    printw("\n\n\n");
    dessinecolor(plat1);
    printw("\n\n");
    dessinecolor(plat2);
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

int tireDeuxOuQuatre_var()
{
    int tire{0};
    int helper = rand()%1000;
    srand(helper);
    int x{rand()%10};
    if(x == 9)
    {
        tire = 4;
    }
    else
    {
        tire  = 2;
    }
    return tire;
}

Plateau plateauInitial_var()
{
    Plateau plat = plateauVide();
    int i1, i2, j1, j2;
    int helper = rand()%1000;
    srand(helper);
    while(1)
    {
        i1 = rand()%4;
        j1 = rand()%4;
        i2 = rand()%4;
        j2 = rand()%4;
        if(i1 != i2 || j1 != j2)
        {
            break;
        }
    }
    plat[i1][j1] = tireDeuxOuQuatre_var();
    plat[i2][j2] = 2;
    return plat;
}

Plateau addblock_var(Plateau plat)
{
    int i,j;
    srand(1);
    while(1)
    {
        i=rand()%4;
        j=rand()%4;
        if(plat[i][j]==0)
        {
            if(!estGagnant(plat))
            {
                plat[i][j]= tireDeuxOuQuatre();
                break;
            }
            else
            {

                int maxblock{2048};
                for(int x = 0; x < 3; x++)
                {
                    for(int y = 0; y < 3; y++)
                    {
                        if(plat[x][y] >= maxblock)
                        {
                            maxblock = plat[x][y];
                        }
                    }
                }
                int a = repow(maxblock);
                int b = tireDeuxOuQuatre();
                if(b == 2)
                {
                    plat[i][j]= tireDeuxOuQuatre();
                    break;
                }
                else
                {
                    srand(1);
                    plat[i][j] = pow(2, (rand()%(a - 8) + 1));
                    break;
                }

            }
        }
    }
    return plat;
}


void joue_var()
{
    Plateau plat1 = plateauInitial();
    Plateau plat2 = plateauInitial_var();
    Plateau last1 = plateauVide();
    Plateau last2 = plateauVide();
    int ch;
    bool ai{false};
    initscr();
    clear();
    noecho();
    curs_set(0);
    keypad(stdscr, 1);
    nodelay(stdscr, 1);
    gamemenu_var(plat1, plat2, ai);
    refresh();

    while (true)
    {
        ch = getch();
        if(ai == true)
        {
            if(ch == 'a')
            {
                ai = false;
                continue;
            }
            if(ch == 27)
            {
                break;
            }
            sleep_for(nanoseconds(250000000));
            erase();
            gamemenu_var(plat1, plat2, ai);

            if(estTermine(plat1) || estTermine(plat2))
            {
                clear();
                endwin();
                endmenu_var(plat1,plat2, ai);
                break;

            }

            if(estGagnant(plat1) || estGagnant(plat2))
            {
                attron(COLOR_PAIR(10));
                printw("\n\n\t\t\t\t\t\tVous avez atteint");
                attroff(COLOR_PAIR(10));
                attron(COLOR_PAIR(11));
                printw(" 2048");
                attroff(COLOR_PAIR(11));
                attron(COLOR_PAIR(10));
                printw("!!!");
                attroff(COLOR_PAIR(10));

            }

            last1 = plat1;
            last2 = plat2;
            if(ch == 'a')
            {
                ai = false;
                continue;
            }
            if(ch == 27)
            {
                break;
            }
            if(ai == true)
            {
                if(nomoved(last1, plat1))
                {
                    plat1 = deplacementBas(plat1);
                }

                if(nomoved(last1, plat1))
                {
                    plat1 = deplacementDroite(plat1);
                }

                if(nomoved(last1, plat1))
                {
                    plat1 = deplacementGauche(plat1);
                }

                if(nomoved(last1, plat1))
                {
                    plat1 = deplacementHaut(plat1);
                }
                plat1 = addblock(plat1);

                if(nomoved(last2, plat2))
                {
                    plat2 = deplacementBas(plat2);
                }

                if(nomoved(last2, plat2))
                {
                    plat2 = deplacementDroite(plat2);
                }

                if(nomoved(last2, plat2))
                {
                    plat2 = deplacementGauche(plat2);
                }

                if(nomoved(last2, plat2))
                {
                    plat2 = deplacementHaut(plat2);
                }
                plat2 = addblock_var(plat2);
            }

            refresh();
        }else
        {
            if(ch == 'a')
            {
                ai = true;
                continue;
            }
            if(ch == 27)
            {
                break;
            }
            sleep_for(nanoseconds(250000000));
            erase();
            gamemenu_var(plat1, plat2, ai);

            if(estTermine(plat1) || estTermine(plat2))
            {
                clear();
                endwin();
                endmenu_var(plat1,plat2, ai);
                break;

            }

            if(estGagnant(plat1) || estGagnant(plat2))
            {
                attron(COLOR_PAIR(10));
                printw("\n\n\t\t\t\t\t\tVous avez atteint");
                attroff(COLOR_PAIR(10));
                attron(COLOR_PAIR(11));
                printw(" 2048");
                attroff(COLOR_PAIR(11));
                attron(COLOR_PAIR(10));
                printw("!!!");
                attroff(COLOR_PAIR(10));

            }

            last1 = plat1;
            last2 = plat2;
            if(ch == 'a')
            {
                ai = true;
                continue;
            }
            if(ch == 27)
            {
                break;
            }
            plat1 = deplacement(plat1, ch);
            plat2 = deplacement(plat2, ch);

            if(!nomoved(last1, plat1))
            {
                plat1 = addblock(plat1);
            }

            if(!nomoved(last2, plat2))
            {
                plat2 = addblock_var(plat2);
            }

            refresh();
        }

    }

    endwin();

}
