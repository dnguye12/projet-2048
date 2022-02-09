#include <math.h>
#include <vector>
#include <iostream>
#include <map>
#include <chrono>
#include <thread>

#define GET_VARIABLE_NAME(Variable) (#Variable)

using namespace std;

typedef vector<vector<int> > Plateau;

map<string, int> score_list;



int tireDeuxOuQuatre()
{
    int tire{0};
    srand(time(0));
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

Plateau plateauVide()
{
    Plateau plat = vector<vector<int>>(4);
    for(int i =0; i < 4; i++)
    {
        plat[i] = {0, 0, 0, 0};
    }
    return plat;
}


Plateau plateauInitial()
{
    Plateau plat = plateauVide();
    int i1, i2, j1, j2;
    srand(time(0));
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
    plat[i1][j1] = tireDeuxOuQuatre();
    plat[i2][j2] = 2;
    return plat;
}


Plateau deplacementGauche(Plateau plat)
{
    string nom = GET_VARIABLE_NAME(plat);
    int i,j;
    int hi, hj;
    for(i=0; i<4; i++)
    {
        hi=i,hj=0;
        for(j=1; j<4; j++)
        {
            if(plat[i][j]!=0)
            {
                if(plat[i][j-1]==0 || plat[i][j-1]==plat[i][j])
                {
                    if(plat[hi][hj]==plat[i][j])
                    {
                        plat[hi][hj]*=2;
                        plat[i][j]=0;
                        score_list.at(nom) += plat[hi][hj];
                    }
                    else
                    {
                        if(plat[hi][hj]==0)
                        {
                            plat[hi][hj]=plat[i][j];
                            plat[i][j]=0;
                        }
                        else
                        {
                            plat[hi][hj+1]=plat[i][j];
                            plat[i][j]=0;
                        }
                    }
                }
                else hj++;
            }
        }
    }
    return plat;
}


Plateau deplacementDroite(Plateau plat)
{
    string nom = GET_VARIABLE_NAME(plat);
    int i,j;
    int hi, hj;
    for(i=0; i<4; i++)
    {
        hi=i,hj=3;
        for(j=2; j>=0; j--)
        {
            if(plat[i][j]!=0)
            {
                if(plat[i][j+1]==0 || plat[i][j+1]==plat[i][j])
                {
                    if(plat[hi][hj]==plat[i][j])
                    {
                        plat[hi][hj]*=2;
                        plat[i][j]=0;
                        score_list.at(nom) += plat[hi][hj];
                    }
                    else
                    {
                        if(plat[hi][hj]==0)
                        {
                            plat[hi][hj]=plat[i][j];
                            plat[i][j]=0;
                        }
                        else
                        {
                            plat[hi][hj-1]=plat[i][j];
                            plat[i][j]=0;
                        }
                    }
                }
                else hj--;
            }
        }
    }

    return plat;
}

Plateau deplacementHaut(Plateau plat)
{
    string nom = GET_VARIABLE_NAME(plat);
    int i,j;
    int hi, hj;
    for(j=0; j<4; j++)
    {
        hi=0,hj=j;
        for(i=1; i<4; i++)
        {
            if(plat[i][j]!=0)
            {
                if(plat[i-1][j]==0 || plat[i-1][j]==plat[i][j])
                {
                    if(plat[hi][hj]==plat[i][j])
                    {
                        plat[hi][hj]*=2;
                        plat[i][j]=0;
                        score_list.at(nom) += plat[hi][hj];
                    }
                    else
                    {
                        if(plat[hi][hj]==0)
                        {
                            plat[hi][hj]=plat[i][j];
                            plat[i][j]=0;
                        }
                        else
                        {
                            plat[hi+1][hj]=plat[i][j];
                            plat[i][j]=0;
                        }
                    }
                }
                else hi++;
            }
        }
    }

    return plat;
}


Plateau deplacementBas(Plateau plat)
{
    string nom = GET_VARIABLE_NAME(plat);
    int i,j;
    int hi, hj;
    for(j=0; j<4; j++)
    {
        hi=3,hj=j;
        for(i=2; i>=0; i--)
        {
            if(plat[i][j]!=0)
            {
                if(plat[i+1][j]==0 || plat[i+1][j]==plat[i][j])
                {
                    if(plat[hi][hj]==plat[i][j])
                    {
                        plat[hi][hj]*=2;
                        plat[i][j]=0;
                        score_list.at(nom) += plat[hi][hj];
                    }
                    else
                    {
                        if(plat[hi][hj]==0)
                        {
                            plat[hi][hj]=plat[i][j];
                            plat[i][j]=0;
                        }
                        else
                        {
                            plat[hi-1][hj]=plat[i][j];
                            plat[i][j]=0;
                        }
                    }
                }
                else hi--;
            }
        }
    }

    return plat;
}

string dessine(Plateau plat)
{
    string des = "";
    string l1 = "*****************************************\n";
    des += l1;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(plat[i][j] == 0)
            {
                des += "*         ";
            }
            else
            {
                des += "*";
                string helper = to_string(plat[i][j]);
                int index = (11/2) - (helper.size()/2);
                for(int c = 1; c < 11; c++)
                {
                    if(c < index || c > index + helper.size())
                    {
                        des += " ";
                    }
                    if(c == index)
                    {
                        des += helper;
                    }
                }
            }
        }
        des += "*\n";
        des += l1;
    }
    return des;
}

bool estGagnant(Plateau plat)
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j <4; j++)
        {
            if(plat[i][j] >= 2048)
            {
                return true;
            }
        }

    }
    return false;
}


bool estTermine(Plateau plat)
{
    int check1{1};
    int check2{1};
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j <4; j++)
        {
            if(plat[i][j] == 0)
            {
                check1 = 0;
                break;
            }
        }

    }
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j <3; j++)
        {
            if(plat[i][j] == plat[i + 1][j] || plat[i][j] == plat[i][j + 1])
            {
                check2 = 0;
                break;
            }
        }

    }

    for(int i = 0; i < 3; i++)
    {
        if(plat[i][3] == plat[i + 1][3] || plat[3][i] == plat[3][i + 1])
        {
            check2= 0;
            break;
        }
    }

    if(check1 == 1 && check2 == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int score(Plateau plat)
{
    string nom = GET_VARIABLE_NAME(plat);
    if(score_list.count(nom))
    {
        return score_list.at(nom);
    }
    else
    {
        score_list.insert(pair<string, int>(nom,0));
        return 0;
    }

}

bool nomoved(Plateau last, Plateau plat)
{
    int i,j;
    for(i=0; i<4; i++)
        for(j=0; j<4; j++)
            if(last[i][j]!=plat[i][j])
            {
                return false;

            }
    return true;
}



int repow(int c)
{
    int i;
    for(i = 1; i <= c; i++)
    {
        if(pow(2, i) == c)
        {
            return i;
        }
    }
    return i;
}

Plateau addblock(Plateau plat)
{
    int i,j;
    srand(time(0));
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
                    srand(time(0));
                    plat[i][j] = pow(2, (rand()%(a - 8) + 1));
                    break;
                }

            }
        }
    }
    return plat;
}


int main()
{
    Plateau plat = plateauInitial();
    Plateau last = plateauVide();
    system("cls");

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
