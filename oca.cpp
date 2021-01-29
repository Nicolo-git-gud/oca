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
    A.name = "Nicolò";
    Giocatore B;
    B.name = "Antonio";
    while (1 > 0)
    {
        conditions(A, B);
        if (A.totale == 63)
        {
            std::cout << "Vince A" << std::endl;
            break;
        }
        conditions(B, A);
        if (B.totale == 63)
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
    if (g.totale == 63)
        return;
    std::cout << g.name << " Fai la tua mossa" << std::endl;
    std::cin >> g.mossa;
    g.totale += g.mossa;
    if (g.totale > 63)
    { //Torno indietro di quanto sforo il 63
        g.totale = (63 - (g.totale - 63));
        std::cout << " Sei sopra al 63 , torni alla casella " << g.totale << std::endl;
        if (g.totale == 54)
        {
            g.totale -= g.mossa;
            std::cout << "Sei su una casella oca, ti sposti indietro del valore della mossa che ti ha condotto qui " << std::endl;
            std::cout << "Finisci sulla casella " << g.totale << std::endl;
        }
    }
    else
        std::cout << "Ti trovi nella casella " << g.totale << std::endl;

    if (g.totale == 5) //Iniziano le caselle oca
    {
        g.totale += g.mossa;
        std::cout << "Sei su una casella oca, ti sposti del valore della mossa che ti ha condotto qui " << std::endl;
        std::cout << "Finisci sulla casella " << g.totale << std::endl;
    }
    if (g.totale == 6)
    {
        g.totale += g.mossa;
        std::cout << "Sei su una casella oca, ti sposti del valore della mossa che ti ha condotto qui " << std::endl;
        std::cout << "Finisci sulla casella " << g.totale << std::endl;
    }
    if (g.totale == 9)
    {
        if (g.mossa == 9)
        { //Se uno come primo tiro fa 9 ha vinto
            g.totale = 63;
            return;
        }
        g.totale += g.mossa;
        std::cout << "Sei su una casella oca, ti sposti del valore della mossa che ti ha condotto qui " << std::endl;
        std::cout << "Finisci sulla casella " << g.totale << std::endl;
    }
    if (g.totale == 18)

    {
        g.totale += g.mossa;
        std::cout << "Sei su una casella oca, ti sposti del valore della mossa che ti ha condotto qui " << std::endl;
        std::cout << "Finisci sulla casella " << g.totale << std::endl;
    }
    if (g.totale == 27)
    {
        g.totale += g.mossa;
        std::cout << "Sei su una casella oca, ti sposti del valore della mossa che ti ha condotto qui " << std::endl;
        std::cout << "Finisci sulla casella " << g.totale << std::endl;
    }
    if (g.totale == 36)
    {
        g.totale += g.mossa;
        std::cout << "Sei su una casella oca, ti sposti del valore della mossa che ti ha condotto qui " << std::endl;
        std::cout << "Finisci sulla casella " << g.totale << std::endl;
    }
    if (g.totale == 45)
    {
        g.totale += g.mossa;
        std::cout << "Sei su una casella oca, ti sposti del valore della mossa che ti ha condotto qui " << std::endl;
        std::cout << "Finisci sulla casella " << g.totale << std::endl;
    }
    if (g.totale == 54)
    {
        g.totale += g.mossa;
        std::cout << "Sei su una casella oca, ti sposti del valore della mossa che ti ha condotto qui " << std::endl;
        std::cout << "Finisci sulla casella " << g.totale << std::endl;
    }
    if (g.totale == 19)
    { //Fermo l'utente per 3 turni, per come sono fatte le chiamate mi basta fermare due turni quando entra
        g.fermo = 2;
        std::cout << g.name << " Sei fermo per tre turni" << std::endl;
    }

    if (g.totale == 31)
    { //Casella di blocco
        g.bloccato = 1;
        std::cout << g.name << "Ti trovi in prigione" << std::endl;
    }

    if (g.totale == 52) //Casella di blocco
    {
        std::cout << g.name << "Ti trovi in prigione" << std::endl;
        g.bloccato = 1;
    }

    if (g.totale == 42)
    { //Da 42 torni a 39
        g.totale = 39;
        std::cout << " Torni alla casella 39" << std::endl;
    }
    if (g.totale == 58)
    { // da 58 torni a 1
        g.totale = 1;
        std::cout << g.name << " Torni alla casella 1" << std::endl;
    }
    if (g.totale == 63) //Vittoria
        return;
}
