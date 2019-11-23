#include<iostream>
#include"HockeyUtils.h"

using namespace hockey;

void mainHockey()
{
	Player tabPlayers[20];
	short choice;
	short nbPlayers = 0;

	do
	{
		DisplayTitle("national hockey league");
		DisplayMenu();

		choice = ReadOption();
		switch (choice)
		{
		case 1:			
			nbPlayers = ReadNBPlayers(1, 20);
			ReadAllPlayers(tabPlayers, nbPlayers);
			choice = ReadOption();
			break;
		case 2:
			FindPlayersByPosition(tabPlayers, nbPlayers);
			choice = ReadOption();
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		default:
			break;
		}
	} 
	while (choice > 1 && choice < 5);
	system("pause");
}