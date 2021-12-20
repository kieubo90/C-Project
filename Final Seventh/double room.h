#pragma once
#include <iostream>
#include<vector>
#include<iomanip>
#include<string>
#include<ctime>
#include"assign double room.h"

using namespace std;


void double_room()
{

	int choose, case_choose, random{ 2 }, eliminate, payment, i{ 0 };

	cout << endl;
	do {
		cout << endl;
		cout << "Select 1 to check room status:" << endl;
		cout << "Select 2 to assign/unassign a room:" << endl;
		cout << "Select any number besides 1,2 to main lobby:" << endl;

		cin >> choose;
		switch (choose)
		{
		case 1:
			check_double_room();
			break;
		case 2:

			do {
				cout << "\nEnter 1 to assign a room: " << endl;
				cout << "Enter 2 to unassign a room: " << endl;
				cout << "Enter 3 to check rooms status and see room/rooms you have chosen: " << endl << endl;
				cout << "If you want to check room status or playing around" << endl;
				cout << "Enter any number besides 1,2,3 to go back: " << endl;
				cin >> case_choose;
				switch (case_choose)
				{
				case 1:
					random = assign_double_room();
					i++;
					if (random == 0)
					{
						cout << "You have chosen room/rooms: ";
						for (int i = 0; i < double_assign.size(); i++)
						{
							cout << double_assign.at(i) << " ";
						}
						cout << endl;
						cout << "Type 1 to payment: " << endl;
						cout << "Type anything to come back:  ";
						cin >> payment;
						switch (payment)
						{
						case 1:
							double_cost();

						default:
							break;
						}

						break;
					}
					else
					{
						break;
					}
					break;
				case 2:
					if (i > 0)
					{
						cout << "You have chosen room/rooms: ";
						for (int i = 0; i < double_assign.size(); i++)
						{
							cout << double_assign.at(i) << " ";
						}
						cout << endl;
						cout << "Type any room you want to unassign: ";
						cin >> eliminate;
						if (eliminate == 0 || eliminate > 20)
						{
							cout << right << "\nPlease choose a valid number between 1-20. Thank you\n";
						}

						else if (double_room_selected[eliminate - 1] == eliminate)
						{
							eliminate_selected_double_room(eliminate);
							remove(double_assign.begin(), double_assign.end(), eliminate);
							double_assign.pop_back();
							i--;
						}
					}
					else
					{
						cout << endl << "\nYou have not selected any room yet.\nPlease select a room.\n\n";
					}
					break;
				case 3:
					check_double_room();
					cout << endl;
					cout << setw(50) << "You have chosen room/rooms: ";
					for (int i = 0; i < double_assign.size(); i++)
					{
						cout << double_assign.at(i) << " ";
					}
					cout << endl;
					break;


				default:

					case_choose = 4;
					break;
				}

			} while (case_choose != 4);
			cout << endl;
			break;

		default:
			choose = 3;
			break;
		}
	} while (choose != 3);
}



