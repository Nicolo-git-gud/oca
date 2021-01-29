#include <string>
struct Giocatore
{
    std::string name;
    int turno = 0;
    int fermo = 0;
    int mossa = 0;
    int totale = 0;
    int bloccato = 0;
};

#include <iostream>
#include <string>
void conditions(Giocatore &g, Giocatore &g2);

int main()
{
    Giocatore A;
    A.name = "Giocatore 1";
    Giocatore B;
    B.name = "Giocatore 2";
    while (1 > 0)
    {
        conditions(A, B);
        if (A.totale == 60)
        {
            std::cout << "Vince A" << std::endl;
            break;
        }
        conditions(B, A);
        if (B.totale == 60)
        {
            std::cout << "Vince B" << std::endl;
            break;
        }
    }
}

void conditions(Giocatore &g, Giocatore &g2)
{
    if (g.totale == 31 && g2.totale == 52)
    {
        g.bloccato = 0;
        g2.bloccato = 0;
        return;
    }
    if (g.bloccato > 0)
    {
        if (g.totale == 31 && g2.totale == 31)
        {
            g.bloccato = 0;
            return;
        }
        else if (g.totale == 52 && g2.totale == 52)
        {
            g.bloccato = 0;
            return;
        }
        return;
    }

    if (g.fermo > 0)
    {
        g.fermo--;
        return;
    }
     if (g.totale == 60)
        return;
    std::cout << g.name << " Fai la tua mossa" << std::endl;
    std::cin >> g.mossa;
    g.totale += g.mossa;

    if (g.totale == 5 || g.totale == 6 || g.totale == 9 || g.totale == 18 || g.totale == 27 || g.totale == 36 || g.totale == 45 || g.totale == 54)
    {
        g.totale += g.mossa;
    }

    if (g.totale == 19)
        g.fermo = 2;
    
    if (g.totale == 31)
        g.bloccato = 1;

    if (g.totale == 52)
    {
        g.bloccato = 1;
    }

    if (g.totale == 42)
        g.totale = 39;
    if (g.totale == 58)
        g.totale = 1;
 if (g.totale == 60)
        return;
    if (g.totale > 60)
        g.totale = (60 - (g.totale - 60));
}