#include <iostream>
#include <string>
#include <stdlib.h>

//Pieces are described as integer values
//make the pieces constant

const int pawn = 100;
const int bishop = 305;
const int knight = 300;
const int rook = 500;
const int queen = 900;
const int king = 2000;

//time to make the board
//board data type should match the pieces data type
//this board will be 8x8 size

int board[8][8];

//board[rank][file]
//rank = 0-7 & file = 0-7(a-h)

const int startup[8][8] = {rook, knight, bishop,
						   queen, king, bishop,
						   knight, rook, pawn,
						   pawn, pawn, pawn, pawn,
						   pawn, pawn, pawn, 0, 0,
						   0, 0, 0, 0, 0, 0, 0, 0,
						   0, 0, 0, 0, 0, 0, 0, 0,
						   0, 0, 0, 0, 0, 0, 0, 0,
						   0, 0, 0, 0, 0, 0, -pawn,
						   -pawn, -pawn, -pawn, -pawn,
						   -pawn, -pawn, -pawn, -rook,
						   -knight, -bishop, -queen,
						   -king, -bishop, -knight, -rook};

/*startup const contains the standard starting position
of all chess games*/
//each side has 8 pieces and 8 pawns
//black pieces are defined by -piecetype (negative)

void setup(void)
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			//setup startup position
			board[i][j] = startup[i][j];
		}
	}
}

/*two for loops run through all the iterans of
  the 8x8 array and copy the starting position
  to the real board*/

/*A function needs to be created that will display
  the board some way either graphics or text*/

//black pieces are lower case, white pieces are upper

void printBoard(void)
{
	//added so strings can be used
	using namespace std;
	int a, b;
	string piece;
	//iterate ranks down from 7 - 0
	//otherwise board will be upside down
	for (a = 7; a > -1; a--)
	{
		cout << endl;
		for (b = 0; b < 8; b++)
		{
			switch (board[a][b])
			{
			case 0:
				piece = "-";
				break;
			case pawn:
				piece = "P";
				break;
			case knight:
				piece = "N";
				break;
			case bishop:
				piece = "B";
				break;
			case rook:
				piece = "R";
				break;
			case queen:
				piece = "Q";
				break;
			case king:
				piece = "K";
				break;
			case -pawn:
				piece = "p";
				break;
			case -knight:
				piece = "n";
				break;
			case -bishop:
				piece = "b";
				break;
			case -rook:
				piece = "r";
				break;
			case -queen:
				piece = "q";
				break;
			case -king:
				piece = "k";
				break;
			}
			cout << " " << piece << " ";
		}
	}
	cout << endl << endl;
}

//main driver function
int main(void)
{
	using namespace std;
	//tell user about the program and how to use it

	cout << "Welcome to chess!" << endl
		<< "Created by TechGeek" << endl << endl;
	cout << "Please enter your moves in 4 letter algebraic"
		<< endl << "ie e2e4 in lower case only" << endl;
	cout << "Commands: exit = quit, abort = quit, print = displays the board,"
		<< endl << "new = new game" << endl << endl;

	//this is the string that contains info from the user
	string passd;
	//setup initial position
	setup();

	//loop always runs until break occurs
	while (1)
	{
		//ask user to input what they want the app to do
		getline(cin, passd);

		if (passd.substr(0, 4) == "exit" || passd.substr(0, 5) == "abort" || passd.substr(0, 4) == "quit")
		{
			break;
		}
		if (passd.substr(0, 5) == "print")
		{
			//display the board
			printBoard();
		}
		if (passd.substr(0, 3) == "new")
		{
			//ask for new game
			setup();
		}
		if (passd.substr(0, 1) >= "a" && passd.substr(0, 1) <= "h"
			&& passd.substr(1, 1) >= "1" &&
			passd.substr(1, 1) <= "8" &&
			passd.substr(2, 1) >= "a" &&
			passd.substr(2, 1) <= "h" &&
			passd.substr(3, 1) >= "1" &&
			passd.substr(3, 1) <= "8")
		{
			//makes sure both squares are on the chess board
			//execute move
			//display new board position
			int a, b, c, d;
			a = passd[0] - 'a';
			b = passd[1] - '1';
			c = passd[2] - 'a';
			d = passd[3] - '1';

			//executes if its on the board
			board[d][c] = board[b][a];
			board[b][a] = 0;

			printBoard();
		}
	}
}
