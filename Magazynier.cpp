#include "Engine.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    bool developer;
   
    if (argc == 2)
    {
        int dev = atoi(argv[1]);
        if (dev == 1)
            developer = true;
        else
            developer = false;
    }
    else if (argc == 1)
        developer = false;
    else if (argc > 2)
    {
        cout << "Podano zla ilosc argumentow aby dowiedziec sie wiecej skontaktuj sie z autorem" << endl;
        return -1;
    }
    Engine* e = new Engine(developer);
    cout << "stop" << endl;
    return 0;
}
