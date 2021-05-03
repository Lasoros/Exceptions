/*
Thomas Wimer
5/2/2021
Exceptions
Langley
CIS 1202.NR1
*/


#include <iostream>
#include <vector>
#include <algorithm>


#define _CRT_SECURE_NO_WARNINGS //must use this if using cstrings

using namespace std;


//void Validate(char start, int offset)
//{
//
//	string invalidCharacterException = "Error: 'Start' is not a letter (A-Z, a-z) . . .";
//
//	char invalidRangeException[] = { "Error: 'Target' is not a letter . . ." };
//
//
//	if (start != 'a' > 'z' || 'A' > 'Z')
//	{
//		throw invalidCharacterException;
//	}
//	else if (offset != 'a' > 'z' || 'A' > 'Z')
//	{
//		throw invalidCharacterException;
//	}
//
//}

void ValidateStart(char start)
{

	string invalidCharacterException = "Error: 'Start' is not a letter (A-Z, a-z) . . . ";

	if (!isalpha(start)) // 'a' > 'z' || 'a' > 'z'
	{
		throw invalidCharacterException;
	}

}

void ValidateOffset(int offset)
{
	char invalidRangeException[] = { "Error: 'Target' is not a letter . . . " };

	if (!isdigit(offset)) //offset !=  0 > 10 || -10 > 0
	{
	throw invalidRangeException;
	}

	

}

char Character(char start, int offset)
{

	char lettersCap1[] = { "ABCDEFGHIJ" };
	char lettersCap2[] = { "KLMNOPQRST" };
	char lettersCap3[] = { "UVWXYZ" };

	char keys1[] = { "ABCDEFGHIJ" }; //1234567890
	char keys2[] = { "KLMNOPQRST" }; //1234567890
	char keys3[] = { "UVWXYZ" };  //123456 //seperated the alphabet into 3 keys 10+10+6 as to compare for letter and return value
	char lettersLow[] = { "abcdefghijklmnopqrstuvwxyz" };

	int letter1, letter2, letter3;

	strchr(lettersCap1, start);
	strchr(lettersCap2, start);
	strchr(lettersCap3, start);
	
	letter1 = strcspn(lettersCap1, keys1);

	letter2 = strcspn(lettersCap2, keys2);

	letter3 = strcspn(lettersCap3, keys3);

	if (strchr(lettersCap1, start))
	{
		letter1 = strcspn(lettersCap1, keys1);
		cout << "\nNew letter is found at " << letter1 + 1;
	}
	else if (strchr(lettersCap2, start))
	{
		letter2 = strcspn(lettersCap2, keys2);
		cout << "\nNew letter is found at " << letter2 + 1;
	}
	else if (letter3 = strcspn(lettersCap3, keys3))
	{
		letter3 = strcspn(lettersCap3, keys3);
		cout << "\nNew letter is found at " << letter3 + 1;
		return letter3;
	}
	

	


}

void Driver(char start, int offset)
{
	bool again = 1;

	char i = 'w';

	while (again)
	{
		try
		{

			cout << "\nEnter starting letter . . . ";
			cin >> start;

			cout << "\nEnter the offset from starting letter, +X or -X . . .";
			cin >> offset;

			toupper(start);

			ValidateStart(start);
			//ValidateOffset(offset);

			Character(start, offset);


		}
		catch (string invalidCharacterException)
		{
			cout << invalidCharacterException;
		}
		catch (char invalidRangeException[])
		{
			cout << invalidRangeException;
		}
		


		//return i;

		cout << "\nEnter 1 to continue else enter 0 . . .";
		cin >> again;
	}


	

}









int main()
{

	

	//use c-string make entered value cap or lower no need for two c-strings of upper and lower

	Driver(' ' , ' ');
	//Character('a', -1);
	//Character('Z', -1);
	//Character('?', 5);



	cout << endl << endl;
	system("pause");
	return 0;
}