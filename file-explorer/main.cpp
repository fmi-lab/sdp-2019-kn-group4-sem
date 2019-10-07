#include <iostream>
#
#include "FileExplorer.h"
using namespace std;

int main()
{
    FileExplorer explorer;
    int command;
    do
    {
        cin >> command;
        switch(command) {
        case 1: // open
        case 2: // more
        case 3: // go back
        case 4: // go forward
            default: // exit
                cout << "Unknown command";
        }
    } while (command <= 4);
    return 0;
}
