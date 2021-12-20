#include <iostream>
#include<vector>
#include<iomanip>
#include<string>
#include<ctime>
#include"single room.h"
#include"assign room.h"
#include"double room.h"
#include"assign double room.h"

using namespace std;
void add_room();
void add_double_room();
int main()
{
    add_room();
    add_double_room();
    int choose;
    cout << "-------------------------------------------------" << endl;
    cout << "\t    Welcome to hotel Hell" << endl << endl;
    do {
        cout << "\nMain lobby:" << endl;
        cout << endl;
        cout << "Please choose 1 for single room:" << endl;
        cout << "Please choose 2 for double room:" << endl;
        cout << "Enter any number besides 1 and 2 to exit:  ";
        cin >> choose;
        switch (choose)
        {
        case 1:
            single_room();
            break;
        case 2:
            double_room();
            break;

        default:
            cout << "\n--------------------------------------------------------------------\n";
            cout << "\tThank you for visiting us, we hope to see you again." << endl;
            choose = 3;
            break;
        }

    } while (choose != 3);



    return 0;
}

