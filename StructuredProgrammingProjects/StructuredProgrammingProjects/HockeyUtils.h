#pragma once
#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

namespace hockey
{
	struct Date
	{
		short day;
		short month;
		short year;
	};

	struct Player
	{
		string name;
		string position;
		Date birthday;
	};

	void DisplayTitle(string anyTitle)
	{
		short length = anyTitle.length();
		cout << "\t";
		for (short i = 0; i < length; i++)
		{
			cout << (char)toupper(anyTitle[i]);
		}
		cout << "\n\t";
		for (short i = 0; i < length; i++)
		{
			cout << "-";
		}
		cout << "\n\n";
	}

	void DisplayMenu() //This can be optimized using one function to add different options
	{
		system("cls");
		cout << "1 - Enter players\n";
		cout << "2 - Find players by position\n";
		cout << "3 - Display all players by normal order\n";
		cout << "4 - Display all players by reverse order\n";
		cout << "5 - Quit\n";
	}

	short ValidateNumber(string txt, short minRange, short maxRange)
	{
		short nb;
		do
		{
			cout << txt;
			cin >> nb;
		} while (nb < minRange || nb > maxRange);
		return nb;
	}

	short ReadOption()
	{
		return ValidateNumber("Enter your choice: ", 1, 5);
	}

	short ReadNBPlayers(short minRange, short maxRange)
	{
		short nb;
		nb = ValidateNumber("Enter the number of players (max 20): ", minRange, maxRange);
		return nb;
	}

	string ReadName()
	{
		string n;
		do
		{
			cout << "\tName:";
			getline(cin, n);
		} while (n != "");
		return n;
	}

	string ValidatePosition(short pos)
	{
		switch (pos)
		{
		case 1:
			return "Goalie";
		case 2:
			return "Defense";
		case 3:
			return "Center";
		case 4:
			return "Forward";
		default:
			return "";
		}
	}

	string ReadPosition()
	{
		short nb = ValidateNumber("\tPosition (1-Goalie, 2-Defense, 3-Center, 4-Forward): ", 1, 4);
		return ValidatePosition(nb);
	}

	Date ReadBirtday()
	{
		cout << "\tBirthday\n";
		Date b;
		b.day = ValidateNumber("\t\tDay: ", 1, 31);
		b.month = ValidateNumber("\t\tMonth: ", 1, 12);
		b.year = ValidateNumber("\t\tYear: ", 1900, 2019);
		return b;
	}

	Player ReadOnePlayer()
	{
		Player p;
		p.name = ReadName();
		p.position = ReadPosition();
		p.birthday = ReadBirtday();
		return p;
	}

	void ReadAllPlayers(Player tab[], short cnt)
	{
		for (short i = 0; i < cnt; i++)
		{
			cout << "Player " << i + 1 << endl;
			tab[i] = ReadOnePlayer();
		}
	}

	void DisplayOnePlayer(Player player)
	{
		cout << left << setw(50) << player.name
			<< setw(10) << player.position
			<< setw(11) << player.birthday.day << "/" << player.birthday.month << "/" << player.birthday.year;
	}

	void FindPlayersByPosition(Player tab[], short cnt)
	{
		cout << "Available positions(1-Goalie, 2-Defense, 3-Center, 4-Forward\n";
		short ch = ValidateNumber("Enter your choice", 1, 4);
		string pos = ValidatePosition(ch);
		for (short i = 0; i < cnt; i++)
		{
			Player player = tab[i];
			if (player.position == pos)
			{
				DisplayOnePlayer(player);
			}
		}
	}

	void DisplayAllPlayers(Player tab[], short start, short end)
	{
		if (start < end)
		{
			cout << "Players by normal order\n";
			for (short i = start; i < end; i++)
			{
				DisplayOnePlayer(tab[i]);
			}
		}
		else
		{
			cout << "Players by reverse order\n";
			for (short i = end; i < start; i--)
			{
				DisplayOnePlayer(tab[i]);
			}
		}
	}
}