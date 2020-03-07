#pragma once
#include<iostream>
#include<string>
#include<Windows.h>

using namespace std;

namespace final_calculator
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // Using the SetConsoleTextAttribute()

	void DisplayTitle(string title)
	{
		string m_title = title;
		short length = m_title.length();
		cout << "\t";
		for (short i = 0; i < length; i++)
		{
			cout << (char)toupper(m_title[i]);
		}
		cout << "\n\t";
		for (short i = 0; i < length; i++)
		{
			cout << "-";
		}
		cout << "\n";
	}

	void DisplayName()
	{
		cout << "\tby Jin Min Chen\n";
		cout << "\t---------------\n\n";
	}

	void DisplaySubtitle(string subtitle)
	{
		DisplayTitle(subtitle);
		cout << "\n";
	}

	void DisplayMenu()
	{
		SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout << "1 - Addition\n";
		
		SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "2 - Division\n";
		
		SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "3 - Substraction\n";
		
		SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "4 - Multiplication\n";

		SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "5 - Quit\n\n";
	}

	short ReadChoice(short minRange, short maxRange)
	{
		SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		short choice;
		do {
			cout << "Enter your choice (" << minRange << "-" << maxRange << "): ";
			cin >> choice;
		} while (choice < minRange || choice > maxRange );
		return choice;
	}

	short ReadOperationTimes(string operation, short min, short max)
	{		
		short ot;
		do {
			cout << "Enter the number of values to " << operation << ": ";
			cin >> ot;
		} while (ot < min || ot > max);
		return ot;
	}

	float ReadSingleNumber(short id)
	{
		float number;
		cout << "Value " << id + 1 << ": ";
		cin >> number;
		return number;
	}

	float ReadNumber(string text)
	{
		float number;
		cout << text;
		cin >> number;
		return number;
	}

	float CalculateAddition(short times)
	{
		float res = 0;
		for (short i = 0; i < times; i++)
		{
			res += ReadSingleNumber(i);
		}
		return res;
	}

	void DisplayResult(string text, float value)
	{
		SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << text << value << endl;
	}

	char ConfirmSelection(string text)
	{
		SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		char sel;
		cout << text;
		cin >> sel;
		return sel;
	}

	float ValidateNumber(float value)
	{
		while (value == 0) {
			value = ReadNumber("You can't divide by 0, type the DIVIDER again: ");
		}
		return value;
	}

	float CalculateDivision(float number1, float number2)
	{
		return number1 / number2;
	}

	float CalculateSubstraction(float number1, float number2)
	{
		return number1 - number2;
	}

	float CalculateMultiplication(short times)
	{
		float res = 1;
		for (short i = 0; i < times; i++)
		{
			res *= ReadSingleNumber(i);
		}
		return res;
	}

	void ProcessSum()
	{
		char selection;
		short timesOp;
		do {
			system("cls");
			SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_INTENSITY);
			DisplayTitle("calculator");
			SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			DisplaySubtitle("addition");
			SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			timesOp = ReadOperationTimes("add", 2, 100);			
			DisplayResult("The result is ", CalculateAddition(timesOp));			
			selection = ConfirmSelection("Would you like to do another addition? (y/n)");
		} while (toupper(selection) == 'Y');
	}

	void ProcessDivision()
	{
		float number1, number2;
		char selection;
		do {
			system("cls");
			SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_INTENSITY);
			DisplayTitle("calculator");
			SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			DisplaySubtitle("division");
			SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			number1 = ReadNumber("Enter value to divide: ");			
			number2 = ValidateNumber(ReadNumber("Enter the divider: "));			
			DisplayResult("The result of the division is: ", CalculateDivision(number1, number2));			
			selection = ConfirmSelection("Would you like to do another division? (y/n): ");
		} while (toupper(selection) == 'Y');
	}

	void ProcessSubstraction()
	{
		float number1, number2;
		char selection;
		do {
			system("cls");
			SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_INTENSITY);
			DisplayTitle("calculator");
			SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			DisplaySubtitle("substraction");
			SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			number1 = ReadNumber("Enter the value to substract: ");
			number2 = ReadNumber("Enter the sustracter: ");
			DisplayResult("The result of the division is: ", CalculateSubstraction(number1, number2));
			selection = ConfirmSelection("Would you like to do another substraction? (y/n): ");
		} while (toupper(selection) == 'Y');
	}

	void ProcessMultiplation()
	{
		short timesOp;
		char selection;
		do {
			system("cls");
			SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_INTENSITY);
			DisplayTitle("calculator");
			SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
			DisplaySubtitle("multiplication");
			SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			timesOp = ReadOperationTimes("multiply ", 2, 100);
			DisplayResult("The result of the multiplication is ", CalculateMultiplication(timesOp));
			selection = ConfirmSelection("Would you like to do another multiplication? (y/n): ");
		} while (toupper(selection) == 'Y');
	}

	void MenuController()
	{
		short choice;
		char selection;
		//Starting operations
		do {
			system("cls");
			SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_INTENSITY);
			DisplayTitle("calculator");
			SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			DisplayName();
			DisplayMenu();
			choice = ReadChoice(1, 5);
			switch (choice) {
			case 1:
				ProcessSum();
				break;
			case 2:
				ProcessDivision();
				break;
			case 3:
				ProcessSubstraction();
				break;
			case 4:
				ProcessMultiplation();
				break;
			case 5:
				break;
			}
		} while (choice != 5);
	}
}