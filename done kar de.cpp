#include<iostream>
#include<time.h>
#include<windows.h>
#include<fstream>
using namespace std;
int blocks[11][4] = { 0 };
void table();
bool cen();
bool check(int i);
void sec();
void cover();
int main_menu();
void choice(int);
int main()
{
	



	int cho;

	cover();
	cho=main_menu();
	choice(cho);

	sec();
	
	table();
	cen();

	
	system("pause");
}
void choice(int cho)
{
	ifstream in;
	in.open("score.txt");

	switch (cho)
	{
	case 1:
		system("cls");
		sec();
		break;
	case 2:
		system("cls");
		cout << "You Have 4 Hidden numbers in star( * )\n";
		cout << "Guess the Number from 0 to 4\n";
		cout << "( In Correct Position ) descibe that your guess number(any one) is in the correct position \n ";
		cout << " Number of Matches describe you that your guess number are same but not the position \n";
		for (int i = 0; i<10; i++)
		{
			Sleep(1300);
			
		}
		main_menu();
		break;
	case 3:
		
		if (!in)
		{
			cout << "File is not opening\n";
		}
		int num;
		while (!in.eof())
		{
			in >> num;
			cout << num << endl;
		}
		in.close();
		main_menu();
		break;
	case 4:
		exit(1);
		break;

	
	}



}
int main_menu()
{
	int play_game_choiceop;
	system("cls");
	system("color 0A");
	cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t***************************************\n\n\n\n";
	cout << "\t\t\t\t\t\t\t1.Start New Game	       \n\n\n";
	cout << "\t\t\t\t\t\t\t2.How To Play		       \n\n\n";
	cout << "\t\t\t\t\t\t\t3.High Score		      \n\n\n";
	cout << "\t\t\t\t\t\t\t4.Exit			      \n";
	cout << "\n\n\n\n\n\n\n\t\t\t\t\t\t***************************************\n";
	cin >> play_game_choiceop;
	cout << endl;
	return play_game_choiceop;
}




void cover()
{
	system("color 0A");
	cout << "\n\n\t\t\t*******************************************************" << endl;
	cout << "\t\t\t*******************************************************" << endl;
	cout << "\n\n\t\t\t\t\t  M"; Sleep(150); cout << "A"; Sleep(150); cout << "S"; Sleep(150); cout << "T"; Sleep(150); cout << "E"; Sleep(150); cout << "R"; Sleep(150);
	cout << " M"; Sleep(150); cout << "I"; Sleep(150); cout << "N"; Sleep(150); cout << "D"; Sleep(150);
	cout << "\n\n\t\t\t_______________________________________________________" << endl;
	cout << "\t\t\t_______________________________________________________" << endl;
	cout << "\n\n\n\t\t\tS"; Sleep(200); cout << "O"; Sleep(200); cout << "H"; Sleep(200); cout << "A"; Sleep(200); cout << "I"; Sleep(200); cout << "B \t"; Sleep(200);
	cout << "\n\n\n\t\t\t14f-"; Sleep(200); cout << "8"; Sleep(200); cout << "0"; Sleep(200); cout << "2"; Sleep(200); cout << "0\n";
	cout << "\n\n\n\t\t\tH"; Sleep(200); cout << "A"; Sleep(200); cout << "S"; Sleep(200); cout << "H"; Sleep(200); cout << "I"; Sleep(200); cout << "M \t"; Sleep(200);
	cout << "\n\n\n\t\t\t14f-"; Sleep(200); cout << "8"; Sleep(200); cout << "0"; Sleep(200); cout << "2"; Sleep(200); cout << "4\n";

	cout << "\n\n\n\t\t\t\t\tLOADING GAME";
	for (int i = 0; i<10; i++)
	{
		Sleep(300);
		cout << ".";
	}
	system("cls");

}
void sec()
{
	srand(time(NULL));

	for (int j = 0; j < 4; ++j)
	{
		blocks[0][j] =  rand() % 5;
	}
}
void table()
{
	

	system("color 6A");


	for (int i = 0; i < 11; ++i)
	{
		if (i != 0)
		{
			cout << "\t\t*" << 10 - i << "\t";
		}
		else
		{

			cout << "\t\t\t";

			cout << "*       *       *       *\n\n";
		}
		if (i != 0)
		{
			for (int j = 0; j < 4; ++j)
			{

				cout << blocks[i][j] << "       ";
			}
			cout << "\n\n";
		}
	}
}

bool cen()
{
	bool flag = true;

	for (int i = 10; i > 0 && flag ; i--)
	{
		cout << "Enter *" << 10-i << " index \n";
		for (int j = 0; j < 4; ++j)
		{
			cin >> blocks[i][j];
		}

		flag=check(i);
		
		
	}
	if (flag)
	{
		cout << "\t\t*************You lost***************\n\n";
		cout << "Hidden Number is \n";
		for (int j = 0; j < 4; ++j)
			cout << blocks[0][j] << "       ";
		cout << endl;
	}
	return true;

}

bool check(int i)
{
	int samePosition = 0;
	int match = 0;
	for (int j = 0; j < 4; ++j)
	{
		if (blocks[i][j] == blocks[0][j])
		{
			samePosition++;
		}
	}

	bool array[4] = { 1, 1, 1, 1 };
	bool array1[4] = { 1, 1, 1, 1 };

	for (int k = 0; k < 4; k++)
	{
		

		for (int j = 0; j < 4 ; j++)
		{
			
			 
			if (blocks[i][k] == blocks[0][j] && array[k] == 1 && array1[j] == 1)
			{
				match++;
				array[k] = 0;

				array1[j] = 0;
			}


		}
	}

	table();
	if (samePosition == 4)
	{
		cout << "\t\t*************You Won***************\n\n";
		return false;
	}
	
	cout << "In correct position = " << samePosition << "\n";
	cout << "Number of Matches   = " << match << "\n";
	return true;
}