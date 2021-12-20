#pragma once
#include <iostream>
#include<vector>
#include<iomanip>
#include<string>
#include<ctime>
#include"single room.h"

using namespace std;

vector<int>room_available, assign;
int room_selected[20];

void add_room();
void check_room();
int assign_room();

void add_room() {
	for (int i = 0; i < 20; i++)
	{
		room_available.push_back(i + 1);
	}
	int random{ 0 };
	for (int i = 0; i < 10; i++) {
		random = 1 + rand() % 20;
		room_selected[random - 1] = random;

	}
}
void check_room() {

	cout << endl;
	for (int i = 0; i < 20; i++)
	{
		if (room_available.at(i) == room_selected[i])
		{
			cout << setw(30) << "The room " << room_available.at(i) << " is not available." << endl;
		}
		else
		{
			cout << setw(65) << "The room " << room_available.at(i) << " is available." << endl;
		}
	}
	cout << endl;
}
int assign_room()
{
	int selected, random{ 2 };
	cout << "\nPlease choose an available room between 1-20: ";
start:
	cin >> selected;
	cout << endl;
	if (selected > 20 || selected <= 0)
	{
		cout << "Please enter a room between 1-20.\nThank you" << endl << endl;
		goto start;
	}
	else if (selected == room_selected[selected - 1])
	{
		cout << setw(60) << "The room " << selected << " is reserved." << endl << endl;
		random = 1;
	}
	else
	{
		cout << setw(60) << "The room " << selected << " is available." << endl << endl;
		room_selected[selected - 1] = selected;
		assign.push_back(selected);
		random = 0;
	}
	return random;
}
void eliminate_selected_room(int eliminate)
{
	if (room_selected[eliminate - 1] == eliminate)
	{
		room_selected[eliminate - 1] = 0;
	}

}


void single_cost()
{
	string name;
	int duration;
	const int single_room{ 100 };
	int cost_single_room, new_cost_single_room;
	cout << setw(60) << "You have chosen room/rooms: ";
	for (int i = 0; i < assign.size(); i++)
	{
		cout << assign.at(i) << " ";
	}
	cout << endl;


	cout << "How long would you like to stay: ";
	cin >> duration;
	cout << endl << duration << " day/days." << endl;
	cost_single_room = single_room * duration * assign.size();
	cout << "Please enter your full name: " << endl;
	cin.ignore();
	getline(cin, name);
	cout << endl;
	if (cost_single_room > 1000)
	{
		new_cost_single_room = cost_single_room * 0.3;
		cout << "You will have 30% discount with us, since your cost is: " << cost_single_room << endl;
	}
	else if (cost_single_room > 500)
	{
		new_cost_single_room = cost_single_room * 0.1;
		cout << "You will have 10% discount with us, since your cost is: " << cost_single_room << endl;
	}
	new_cost_single_room = cost_single_room - new_cost_single_room;
	cout << endl;
	cout << "-------------------------------------------------" << endl;
	cout << "Price:\n\tSingle room: 100euro/night." << endl;
	cout << endl;
	cout << "Your reservation" << endl;
	cout << "Full name: " << name << endl;
	cout << "Your room: ";
	for (int i = 0; i < assign.size(); i++)
	{
		cout << assign.at(i) << " ";
	}
	cout << endl;
	cout << "You will stay in our hotel: " << duration << " day/days." << endl;
	cout << "Total cost is: " << new_cost_single_room << " euro" << endl << endl;

	cout << "---------------------------------------------------------------------------" << endl;
	cout << "\tThank you and have nice time to stay with us." << endl << endl;
}








