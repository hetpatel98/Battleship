//BattleShipGame.cpp
//Coded By Het Patel and Connor Atkinson
//
//This is a complete two play textual based Battle Ship game
//Submitted On January 22, 2015

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

//Declare prototypes
using namespace std;
char board[10][10];
char boardPl2[10][10];
char boardAttack[10][10];
char boardPl2Attack[10][10];
void displayBoard (char gameboard[10][10]);
void initializeBoard();
void displayBoardPl2 (char gameboardPl2[10][10]);
void initializeBoardPl2();
void displayBoardAttack (char gameboardAttack[10][10]);
void initializeBoardAttack();
void displayBoardPl2Attack (char gameboardPl2Attack[10][10]);
void initializeBoardPl2Attack();
bool Pl1WinCheck();
bool Pl2WinCheck();


int main()
{
    initializeBoard();
    displayBoard(board);
    char letAc1;
    while (true) //Create loop that will keep going if the incorrect input is entered
    {
        cout << "User1: Please enter the first letter coordinate of your Aircraft Carrier (make  sure its in the gameboard)---> " ;
        cin >> letAc1;
        letAc1 = toupper(letAc1);//Convert input to a upper letter
        cout << endl;
        {
            if (letAc1>='A' && letAc1<='J')//Exit the loop if the letter is in the boundaries
                break;
        }
    }
    int numAc1 = 0;

    while (numAc1<= 0|| numAc1>=11 )//Create loop that keep exit if the input is in between 1 and 10
    {
        cout << "User1: Please enter the first number coordinate of your Aircraft Carrier(make  sure its in the gameboard)---> " ;
        cin >> numAc1;
        cout << endl;
    }
    cout << endl;
    char letAc2;
    while (true)//Have user enter second letter coordinate
    {
        cout << "User1: Please enter the second letter coordinate of your Aircraft Carrier (make sure its 5 spaces away and horizontal/vertical only)---> " ;
        cin >> letAc2;
        cout << endl;
        letAc2 = toupper(letAc2);
        if (letAc2>='A' && letAc2<='J')
        {
            break;
        }
    }
    if (letAc1!=letAc2)//initiate If statement if the second letter is not equal to the first letter
    {

        while (true)
        {

            if (letAc1==letAc2)
            {
                break;
            }
            if (letAc2==(letAc1+4))//If the input is 5 spaces away from the previous input then break the loop
            {
                break;
            }
            if (letAc2==(letAc1-4))//If the input is 5 spaces away from the previous input then break the loop
            {
                break;
            }
            cout << "User1: Please Make Sure That The Input Is Corresponding To The Correct Length (5) Please Enter The Second Letter Again---> " ;
            cin >> letAc2;
            letAc2 = toupper(letAc2);


        }
    }
    int numAc2 = 0;
    while (numAc2<=0|| numAc2>=11)
    {
        cout << "User1: Please enter the second number coordinate of your Aircraft Carrier(make sure its 5 spaces away and horizontal/vertical only)---> " ;
        cin >> numAc2;
        cout << endl;
    }

    while(true)
    {
        if (letAc1==letAc2)//Initiate if statement if the first letter entered is equal to the second letter entered
        {

            if (numAc2==(numAc1+4))//Make sure the number entered is 5 spaces away from the previous entry
            {
                break;
            }
            if (numAc2==(numAc1-4)&& (numAc2>0|| numAc2<11))//Make sure the number entered is 5 spaces away from the previous entry
            {
                break;
            }
        }
        if (letAc1!=letAc2) //If statement that will exit the loop as long as the numbers are even if the letters are not the same
        {
            if (numAc1==numAc2)
            {
                break;
            }
        }
        cout << endl;
        cout << "User1: Please Make Sure That The Input Is Corresponding To The Correct Length (5) Please Enter The Second Number Again---> " ;
        cin >> numAc2;

    }

    cout<<endl;
    //...............................................Placing Ships.........................................................

    char Pos1='A';
    char Pos2='A';
    int letPos;
    int letPos2;
    letPos = letAc1-'A';
    letPos2 = letAc2-'A';
    board[letPos][numAc1-1]= Pos1;
    board[letPos2][numAc2-1]= Pos2;
    if (letAc1==letAc2)
    {
        if (numAc1<numAc2)//Determines which number is larger so user can place ships backwards
        {
            for (int x=numAc1-1; x<=numAc2-1; x++)
            {
                board[letPos][x]='A';//Places an 'A' at the given coordinates
            }
        }

        if (numAc2<numAc1)
        {
            for (int x=numAc2-1; x<=numAc1-1; x++)
            {
                board[letPos][x]='A';//Places an 'A' at the next given coordinates
            }
        }
        cout << endl;
    }

    if (numAc1 == numAc2)
    {
        if (letPos<letPos2)
        {


            for (int y=letPos; y<=letPos2; y++)//Connects the ship from coordinate 1 - coordinate 2
            {
                board[y][numAc1-1]='A';
                cout << endl;
            }
        }
        if (letPos2<letPos)
        {
            for (int y=letPos2; y<=letPos; y++)
            {
                board[y][numAc1-1]='A';
                cout << endl;
            }
        }
    }

    displayBoard(board);
//..........................................Placing BattleShip........................................................

    char letBs1;
    while (true)
    {
        cout << "User1: Please enter the first letter coordinate of your Battle Ship (make  sure its in the gameboard)---> " ;
        cin >> letBs1;
        cout << endl;
        letBs1 = toupper(letBs1);
        {
            if (letBs1>='A' && letBs1<='J')//stop user from entering anything outside of the boundaries
                break;
        }
    }

    int numBs1 = 0;

    while (numBs1<= 0|| numBs1>=11 )//stop user from entering anything outside of the boundaries
    {
        cout << "User1: Please enter the first number coordinate of your Battle Ship(make sure its 4 spaces away and horizontal/vertical only)---> " ;
        cin >> numBs1;
        cout << endl;
    }
    cout << endl;
loop:
    for (;;)//infinite loop
    {

        if (board[letBs1-'A'][numBs1-1] == 'O')//create this loop to check and stop user from entering a coordinate that is already hosting a ship
        {
            break;
        }

        for (;;)
        {
            cout << "Coordinate Already Used OR Coordinate not on the Gameboard...Please enter the following again" << endl;
            cout << "User1: Please enter the first letter coordinate of your Battle Ship (make  sure its in the gameboard)---> " ;
            cin >> letBs1;
            letBs1 = toupper(letBs1);
            if (letBs1>='A' && letBs1<='J')
            {
                break;
            }
        }
        for (;;)
        {
            cout << "User1: Please enter the first number coordinate of your Battle Ship(make sure its 4 spaces away and horizontal/vertical only)---> " ;
            cin >> numBs1;
            cout << endl;
            if (numBs1>=1 && numBs1<=10)
            {
                break;
            }
        }
        if (board[letBs1-'A'][numBs1-1] == 'O')//if the spot is occupied by an 'O' then break out of the loop
        {
            break;
        }
        else
        {
            goto loop;//if it has anything else, go back to the start of the loop
        }

    }

    char letBs2;
    while (true)//enter second coordinate
    {
        cout << "User1: Please enter the second letter coordinate of your Battle Ship (make  sure its in the gameboard)---> " ;
        cin >> letBs2;
        cout << endl;
        letBs2 = toupper(letBs2);
        if (letBs2>='A' && letBs2<='J')
        {
            break;
        }
    }

    if (letBs1!=letBs2)//assure user is entering the ships in the correct spaces from each other
    {
        if (letBs2 != letBs1 || letBs2!= letBs2)
        {

            while (true)
            {

                if (letBs1==letBs2)
                {
                    break;
                }
                if (letBs2==(letBs1+3))
                {
                    break;
                }
                if (letBs2==(letBs1-3))
                {
                    break;
                }
                cout << "User1: Please enter the second letter coordinate of your Battle Ship (make  sure its in the gameboard)---> " ;
                cin >> letBs2;
                letBs2 = toupper(letBs2);


            }
        }

    }
    int numBs2 = 0;
    while (numBs2<=0|| numBs2>=11 )
    {
        cout << "User1: Please enter the second number coordinate of your Battle Ship(make sure its 4 spaces away and horizontal/vertical only)---> " ;
        cin >> numBs2;
    }
    cout<<endl;
loop2://create another loop that stops users from entering the second coordinate on an already occupied coordinate
    for (;;)
    {

        if (board[letBs2-'A'][numBs2-1] == 'O')//allows user to place ship is the coordinate is empty
        {
            break;
        }

        for (;;)
        {
            cout << "Coordinate Already Used OR Coordinate not on the Gameboard...Please enter the following again" << endl;
            cout << "User1: Please enter the second letter coordinate of your Battle Ship (make  sure its in the gameboard)---> " ;
            cin >> letBs2;
            cout << endl;
            letBs2 = toupper(letBs2);
            if (letBs2>='A' && letBs2<='J')
            {
                break;
            }
        }
        for (;;)
        {
            cout << "User1: Please enter the second number coordinate of your Battle Ship(make sure its 4 spaces away and horizontal/vertical only)---> " ;
            cin >> numBs2;
            cout << endl;
            if (numBs2>=1 && numBs2<=10)
            {
                break;
            }
        }
        if (board[letBs2-'A'][numBs2-1] == 'O')//allows user to place ship is the coordinate is empty
        {
            break;
        }
        else
        {
            goto loop2;//if it is not empty, go back to the start of the loop
        }

    }

    while(true)//make sure that the coordinate entered is the correct amount of spaces away from the first coordinate
    {
        if (letBs1==letBs2)
        {

            if (numBs2==(numBs1+3))
            {
                break;
            }
            if (numBs2==(numBs1-3)&& (numBs2>0|| numBs2<11))
            {
                break;
            }
        }
        if (letBs1!=letBs2)
        {
            if (numBs1==numBs2)
            {
                break;
            }
        }
        cout << endl;
        cout << "User1: Please Make Sure That The Input Is Corresponding To The Correct Length (4) Please Enter The Second Number Again---> " ;
        cin >> numBs2;
        cout << endl;

    }

    char Pos1a='B';
    char Pos2a='B';
    int letBsPos;
    int letBsPos2;
    letBsPos = letBs1-'A';
    letBsPos2 = letBs2-'A';
    board[letBsPos][numBs1-1]= Pos1a;
    board[letBsPos2][numBs2-1]= Pos2a;
    if (letBs1==letBs2)//place the ship on the board and display it
    {
        if (numBs1<numBs2)
        {
            for (int x1=numBs1-1; x1<=numBs2-1; x1++)
            {
                board[letBsPos][x1]='B';//display 'B' to represent 'Battleship'
            }
        }

        if (numBs2<numBs1)
        {
            for (int x1=numBs2-1; x1<=numBs1-1; x1++)
            {
                board[letBsPos][x1]='B';
            }
        }
        cout << endl;
    }

    if (numBs1 == numBs2)
    {
        if (letBsPos<letBsPos2)
        {


            for (int y1=letBsPos; y1<=letBsPos2; y1++)
            {
                board[y1][numBs1-1]='B';
                cout << endl;
            }
        }
        if (letBsPos2<letBsPos)
        {
            for (int y1=letBsPos2; y1<=letBsPos; y1++)
            {
                board[y1][numBs1-1]='B';
                cout << endl;
            }
        }
    }




    displayBoard(board);
//...........................................Placing Submarine........................................................
    char letSm1;
    while (true)
    {
        cout << "User1: Please enter the first letter coordinate of your Submarine (make  sure its in the gameboard)---> " ;
        cin >> letSm1;
        cout << endl;
        letSm1 = toupper(letSm1);//convert letter to an uppercase
        {
            if (letSm1>='A' && letSm1<='J')//assure the letter is in the boundaries
                break;
        }
    }
    int numSm1 = 0;

    while (numSm1<= 0|| numSm1>=11 )//assure the number is in the boundaries
    {
        cout << "User1: Please enter the first number coordinate of your Submarine(make sure its 3 spaces away and horizontal/vertical only)---> " ;
        cin >> numSm1;
        cout << endl;
    }
loop3:
    for (;;)//create loop to make sure the user is not placing a ship ontop of another
    {

        if (board[letSm1-'A'][numSm1-1] == 'O')//check if the space is occupied
        {
            break;//if not exit the loop
        }

        for (;;)
        {
            cout << "Coordinate Already Used OR Coordinate not on the Gameboard...Please enter the following again" << endl;
            cout << "User1: Please enter the first letter coordinate of your Submarine (make  sure its in the gameboard)---> " ;
            cin >> letSm1;
            cout << endl;
            letSm1 = toupper(letSm1);
            if (letSm1>='A' && letSm1<='J')
            {
                break;
            }
        }
        for (;;)
        {
            cout << "User1: Please enter the first number coordinate of your Submarine(make sure its 3 spaces away and horizontal/vertical only)---> " ;
            cin >> numSm1;
            cout << endl;
            if (numSm1>=1 && numSm1<=10)
            {
                break;
            }
        }
        if (board[letSm1-'A'][numSm1-1] == 'O')//check if new coordinate entered is taken
        {
            break;
        }
        else
        {
            goto loop3;//if it is occupied then go back to the start of the loop
        }

    }
    char letSm2;
    while (true)
    {
        cout << "User1: Please enter the second letter coordinate of your Submarine (make  sure its in the gameboard)---> " ;
        cin >> letSm2;
        cout << endl;
        letSm2 = toupper(letSm2);//convert second letter to uppercase
        if (letSm2>='A' && letSm2<='J')
        {
            break;
        }
    }
    if (letSm1!=letSm2)//make sure the second coordinate is the appropriate length away from the first
    {

        while (true)
        {

            if (letSm1==letSm2)
            {
                break;
            }
            if (letSm2==(letSm1+2))
            {
                break;
            }
            if (letSm2==(letSm1-2))
            {
                break;
            }
            cout << "User1: Please enter the second letter coordinate of your Submarine(make  sure its in the gameboard)---> " ;
            cin >> letSm2;
            cout << endl;
            letSm2 = toupper(letSm2);


        }
    }



    int numSm2 = 0;
    while (numSm2<=0|| numSm2>=11 )//make sure the second number is in the boundaries
    {
        cout << "User1: Please enter the second number coordinate of your Submarine(make sure its 3 spaces away and horizontal/vertical only)---> " ;
        cin >> numSm2;
        cout << endl;
    }
    cout<<endl;
loop4://create loop that makes sure the ships do not overlap
    for (;;)
    {

        if (board[letSm2-'A'][numSm2-1] == 'O')//check if the space is empty
        {
            break;
        }

        for (;;)
        {
            cout << "Coordinate Already Used OR Coordinate not on the Gameboard...Please enter the following again" << endl;
            cout << "User1: Please enter the second letter coordinate of your Submarine (make  sure its in the gameboard)---> " ;
            cin >> letSm2;
            cout << endl;
            letSm2 = toupper(letSm2);
            if (letSm2>='A' && letSm2<='J')
            {
                break;
            }
        }
        for (;;)
        {
            cout << "User1: Please enter the second number coordinate of your Submarine(make sure its 3 spaces away and horizontal/vertical only)---> " ;
            cin >> numSm2;
            cout << endl;
            if (numSm2>=1 && numSm2<=10)
            {
                break;
            }
        }
        if (board[letSm2-'A'][numSm2-1] == 'O')
        {
            break;
        }
        else
        {
            goto loop4;//if space is occupied then return to the beginning of the loop
        }

    }
    while(true)//make sure the new coordinate is the appropriate length away from the other one
    {
        if (letSm1==letSm2)
        {

            if (numSm2==(numSm1+2))
            {
                break;
            }
            if (numSm2==(numSm1-2)&& (numSm2>0|| numSm2<11))
            {
                break;
            }
        }
        if (letSm1!=letSm2)
        {
            if (numSm1==numSm2)
            {
                break;
            }
        }

        cout << "User1: Please Make Sure That The Input Is Corresponding To The Correct Length (3) Please Enter The Second Number Again---> " ;
        cin >> numSm2;
        cout << endl;

    }

    char Pos1b='S';
    char Pos2b='S';
    int letSmPos;
    int letSmPos2;
    letSmPos = letSm1-'A';
    letSmPos2 = letSm2-'A';
    board[letSmPos][numSm1-1]= Pos1b;
    board[letSmPos2][numSm2-1]= Pos2b;
    if (letSm1==letSm2)//place ship
    {
        if (numSm1<numSm2)
        {
            for (int x2=numSm1-1; x2<=numSm2-1; x2++)
            {
                board[letSmPos][x2]='S';//Place an 'S' for submarine
            }
        }

        if (numSm2<numSm1)
        {
            for (int x2=numSm2-1; x2<=numSm1-1; x2++)
            {
                board[letSmPos][x2]='S';
            }
        }
        cout << endl;
    }

    if (numSm1 == numSm2)
    {
        if (letSmPos<letSmPos2)
        {


            for (int y2=letSmPos; y2<=letSmPos2; y2++)
            {
                board[y2][numSm1-1]='S';
                cout << endl;
            }
        }
        if (letSmPos2<letSmPos)
        {
            for (int y2=letSmPos2; y2<=letSmPos; y2++)
            {
                board[y2][numSm1-1]='S';
                cout << endl;
            }
        }
    }

    displayBoard(board);
//..........................................Placing Cruiser...................................................................

    char letCr1;
    while (true)
    {
        cout << "User1: Please enter the first letter coordinate of your Cruiser(make  sure its in the gameboard)---> " ;
        cin >> letCr1;
        cout << endl;
        letCr1 = toupper(letCr1);//convert letter to uppercase
        {
            if (letCr1>='A' && letCr1<='J')//make sure the letter is in the boundaries
                break;
        }
    }
    int numCr1 = 0;

    while (numCr1<= 0|| numCr1>=11 )//make sure the number is in the boundaries
    {
        cout << "User1: Please enter the first number coordinate of your Cruiser(make sure its 3 spaces away and horizontal/vertical only)---> " ;
        cin >> numCr1;
        cout << endl;
    }
loop5://create loop that will stop ships from stacking
    for (;;)
    {

        if (board[letCr1-'A'][numCr1-1] == 'O')//check if space entered is empty
        {
            break;
        }

        for (;;)
        {
            cout << "Coordinate Already Used OR Coordinate not on the Gameboard...Please enter the following again" << endl;
            cout << "User1: Please enter the first letter coordinate of your Cruiser (make  sure its in the gameboard)---> " ;
            cin >> letCr1;
            cout << endl;
            letCr1 = toupper(letCr1);
            if (letCr1>='A' && letCr1<='J')
            {
                break;
            }
        }
        for (;;)
        {
            cout << "User1: Please enter the first number coordinate of your Cruiser(make sure its 3 spaces away and horizontal/vertical only)---> " ;
            cin >> numCr1;
            cout << endl;
            if (numCr1>=1 && numCr1<=10)
            {
                break;
            }
        }
        if (board[letCr1-'A'][numCr1-1] == 'O')
        {
            break;
        }
        else
        {
            goto loop5;//if space is taken return to the beginning of the loop
        }

    }
    char letCr2;
    while (true)
    {
        cout << "User1: Please enter the second letter coordinate of your Cruiser(make  sure its in the gameboard)---> " ;
        cin >> letCr2;
        cout << endl;
        letCr2 = toupper(letCr2);
        if (letCr2>='A' && letCr2<='J')
        {
            break;
        }
    }
    if (letCr1!=letCr2)//make sure the ship is the correct length
    {
        if (letCr2 != letCr1 || letCr2!= letCr2)
        {

            while (true)
            {

                if (letCr1==letCr2)
                {
                    break;
                }
                if (letCr2==(letCr1+2))
                {
                    break;
                }
                if (letCr2==(letCr1-2))
                {
                    break;
                }
                cout << "User1: Please enter the second letter coordinate of your Cruiser(make  sure its in the gameboard)---> " ;
                cin >> letCr2;
                letCr2 = toupper(letCr2);


            }
        }

    }
    int numCr2 = 0;
    while (numCr2<=0|| numCr2>=11 )
    {
        cout << "User1: Please enter the second number coordinate of your Cruiser(make sure its 3 spaces away and horizontal/vertical only)---> " ;
        cin >> numCr2;
        cout << endl;
    }
    cout<<endl;
loop6://create loop that will stop ships from stacking
    for (;;)
    {

        if (board[letCr2-'A'][numCr2-1] == 'O')//check if space is taken
        {
            break;
        }

        for (;;)
        {
            cout << "Coordinate Already Used OR Coordinate not on the Gameboard...Please enter the following again" << endl;
            cout << "User1: Please enter the second letter coordinate of your Cruiser (make  sure its in the gameboard)---> " ;
            cin >> letCr2;
            letCr2 = toupper(letCr2);
            if (letCr2>='A' && letCr2<='J')
            {
                break;
            }
        }
        for (;;)
        {
            cout << "User1: Please enter the second number coordinate of your Cruiser(make sure its 3 spaces away and horizontal/vertical only)---> " ;
            cin >> numCr2;
            if (numCr2>=1 && numCr2<=10)
            {
                break;
            }
        }
        if (board[letCr2-'A'][numCr2-1] == 'O')
        {
            break;
        }
        else
        {
            goto loop6;//return to beginning of loop if space is taken
        }

    }
    while(true)
    {
        if (letCr1==letCr2)//check if ship is correct length
        {

            if (numCr2==(numCr1+2))
            {
                break;
            }
            if (numCr2==(numCr1-2)&& (numCr2>0|| numCr2<11))
            {
                break;
            }
        }
        if (letCr1!=letCr2)
        {
            if (numCr1==numCr2)
            {
                break;
            }
        }

        cout << "User1: Please Make Sure That The Input Is Corresponding To The Correct Length (3) Please Enter The Second Number Again---> " ;
        cin >> numCr2;

    }

    char Pos1c='C';
    char Pos2c='C';
    int letCrPos;
    int letCrPos2;
    letCrPos = letCr1-'A';
    letCrPos2 = letCr2-'A';
    board[letCrPos][numCr1-1]= Pos1c;
    board[letCrPos2][numCr2-1]= Pos2c;
    if (letCr1==letCr2)//place ship on board
    {
        if (numCr1<numCr2)
        {
            for (int x3=numCr1-1; x3<=numCr2-1; x3++)//create loop that will connect the 2 coordinates
            {
                board[letCrPos][x3]='C';//display 'C' for cruiser
            }
        }

        if (numCr2<numCr1)
        {
            for (int x3=numCr2-1; x3<=numCr1-1; x3++)
            {
                board[letCrPos][x3]='C';
            }
        }
        cout << endl;
    }
    if (numCr1 == numCr2)
    {
        if (letCrPos<letCrPos2)
        {


            for (int y3=letCrPos; y3<=letCrPos2; y3++)
            {
                board[y3][numCr1-1]='C';
                cout << endl;
            }
        }
        if (letCrPos2<letCrPos)
        {
            for (int y3=letCrPos2; y3<=letCrPos; y3++)
            {
                board[y3][numCr1-1]='C';
                cout << endl;
            }
        }
    }

    displayBoard(board);
//.....................................................Placing Destroyer.............................................
    char letDs1;
    while (true)
    {
        cout << "User1: Please enter the first letter coordinate of your Destroyer (make  sure its in the gameboard)---> " ;
        cin >> letDs1;
        cout << endl;
        letDs1 = toupper(letDs1);//convert letter to uppercase
        {
            if (letDs1>='A' && letDs1<='J')//make sure letter is in boundaries
                break;
        }
    }
    int numDs1 = 0;

    while (numDs1<= 0|| numDs1>=11 )//make sure number is in boundaries
    {
        cout << "User1: Please enter the first number coordinate of your Destroyer(make sure its 2 spaces away and horizontal/vertical only)---> " ;
        cin >> numDs1;
        cout << endl;
    }
    cout << endl;
loop7://create loop that will stop ships from stacking
    for (;;)
    {

        if (board[letDs1-'A'][numDs1-1] == 'O')//check if spot is empty
        {
            break;
        }

        for (;;)
        {
            cout << "Coordinate Already Used OR Coordinate not on the Gameboard...Please enter the following again" << endl;
            cout << "User1: Please enter the first letter coordinate of your Destroyer (make  sure its in the gameboard)---> " ;
            cin >> letDs1;
            cout << endl;
            letDs1 = toupper(letDs1);
            if (letDs1>='A' && letDs1<='J')
            {
                break;
            }
        }
        for (;;)
        {
            cout << "User1: Please enter the first number coordinate of your Destroyer(make sure its 2 spaces away and horizontal/vertical only)---> " ;
            cin >> numDs1;
            cout << endl;
            if (numDs1>=1 && numDs1<=10)
            {
                break;
            }
        }
        if (board[letDs1-'A'][numDs1-1] == 'O')//check if new spot is taken
        {
            break;
        }
        else
        {
            goto loop7;//if it is return to the beginning of the loop
        }

    }
    char letDs2;
    while (true)
    {
        cout << "User1: Please enter the second letter coordinate of your Destroyer (make  sure its in the gameboard)---> " ;
        cin >> letDs2;
        cout << endl;
        letDs2 = toupper(letDs2);//convert second letter to uppercase
        if (letDs2>='A' && letDs2<='J')//check if it is in the boundaries
        {
            break;
        }
    }
    if (letDs1!=letDs2)//check if second number is in the boundaries
    {


        while (true)//make sure the ship is the correct length
        {

            if (letDs1==letDs2)
            {
                break;
            }
            if (letDs2==(letDs1+1))
            {
                break;
            }
            if (letDs2==(letDs1-1))
            {
                break;
            }
            cout << "User1: Please enter the second letter coordinate of your Destroyer(make  sure its in the gameboard)---> " ;
            cin >> letDs2;
            cout << endl;
            letDs2 = toupper(letDs2);//convert letter to uppercase


        }


    }
    int numDs2 = 0;
    while (numDs2<=0|| numDs2>=11 )//make sure the number is in the boundaries
    {
        cout << "User1: Please enter the second number coordinate of your Destroyer(make sure its 2 spaces away and horizontal/vertical only)---> " ;
        cin >> numDs2;
        cout << endl;
    }
    cout<<endl;
loop8://create loop that will stop ships from stacking
    for (;;)
    {

        if (board[letDs2-'A'][numDs2-1] == 'O')//check if spot is taken
        {
            break;
        }

        for (;;)
        {
            cout << "Coordinate Already Used OR Coordinate not on the Gameboard...Please enter the following again" << endl;
            cout << "User1: Please enter the second letter coordinate of your Destroyer(make  sure its in the gameboard)---> " ;
            cin >> letDs2;
            cout << endl;
            letDs2 = toupper(letDs2);
            if (letDs2>='A' && letDs2<='J')
            {
                break;
            }
        }
        for (;;)
        {
            cout << "User1: Please enter the second number coordinate of your Destroyer(make sure its 2 spaces away and horizontal/vertical only)---> " ;
            cin >> numDs2;
            cout << endl;
            if (numDs2>=1 && numDs2<=10)
            {
                break;
            }
        }
        if (board[letDs2-'A'][numDs2-1] == 'O')//check if spot is open
        {
            break;
        }
        else
        {
            goto loop8;//if spot is taken return to the beginning of the loop
        }

    }
    while(true)//make sure the ship is the correct length
    {
        if (letDs1==letDs2)
        {

            if (numDs2==(numDs1+1))
            {
                break;
            }
            if (numDs2==(numDs1-1)&& (numDs2>0|| numDs2<11))
            {
                break;
            }
        }
        if (letDs1!=letDs2)
        {
            if (numDs1==numDs2)
            {
                break;
            }
        }
        cout << endl;
        cout << "User1: Please Make Sure That The Input Is Corresponding To The Correct Length (2) Please Enter The Second Number Again---> " ;
        cin >> numDs2;
        cout << endl;

    }


    char Pos1d='D';
    char Pos2d='D';
    int letDsPos;
    int letDsPos2;
    letDsPos = letDs1-'A';
    letDsPos2 = letDs2-'A';
    board[letDsPos][numDs1-1]= Pos1d;
    board[letDsPos2][numDs2-1]= Pos2d;
    if (letDs1==letDs2)//place ship
    {
        if (numDs1<numDs2)
        {
            for (int x4=numDs1-1; x4<=numDs2-1; x4++)//create loop that will connect the 2 coordinates entered
            {
                board[letDsPos][x4]='D';//place 'D' for Destroyer
            }
        }

        if (numDs2<numDs1)
        {
            for (int x4=numDs2-1; x4<=numDs1-1; x4++)
            {
                board[letDsPos][x4]='D';
            }
        }
        cout << endl;
    }
    if (numDs1 == numDs2)
    {
        if (letDsPos<letDsPos2)
        {


            for (int y4=letDsPos; y4<=letDsPos2; y4++)
            {
                board[y4][numDs1-1]='D';
                cout << endl;
            }
        }
        if (letDsPos2<letDsPos)
        {
            for (int y4=letDsPos2; y4<=letDsPos; y4++)
            {
                board[y4][numDs1-1]='D';
                cout << endl;
            }
        }
    }

    displayBoard(board);//display final board
    cout << "This is your board";
    cout<< endl;
    cout<< endl;
    cout<< endl;
    cout << "Now it is Player 2's turn to place their ships. Player 1, please look away."<< endl;//revert to user 2's gameboard
    cout<< endl;
    cout<< endl;
    cout<< endl;
    cout<< endl;
    cout << "Please enter any character to continue --> ";
    char input;
    cin >> input;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;


//....................................................USER 2..........................................................
//.................................................Placing Aircraft Carrier...........................................
    initializeBoardPl2();
    displayBoardPl2(boardPl2);//display player 2's board
    char Pl2letAc1;
    while (true)
    {
        cout << "User2: Please enter the first letter coordinate of your Aircraft Carrier (make  sure its in the gameboard)---> " ;
        cin >> Pl2letAc1;//Get first letter
        cout << endl;
        Pl2letAc1 = toupper(Pl2letAc1);//convert letter to uppercase
        {
            if (Pl2letAc1>='A' && Pl2letAc1<='J')//make sure the letter is in the boundaries
                break;
        }
    }
    int Pl2numAc1 = 0;

    while (Pl2numAc1<= 0|| Pl2numAc1>=11 )//make sure the number entered is in the boundaries
    {
        cout << "User2: Please enter the first number coordinate of your Aircraft Carrier(make sure its 5 spaces away and horizontal/vertical only)---> " ;
        cin >> Pl2numAc1;//get second number
        cout << endl;
    }
loop9:// this bit of code is unecessary, as it will check if the coordinate is empty
    for (;;)
    {

        if (boardPl2[Pl2letAc1-'A'][Pl2numAc1-1] == 'O')
        {
            break;
        }

        for (;;)
        {
            cout << "Coordinate Already Used OR Coordinate not on the Gameboard...Please enter the following again" << endl;
            cout << "User2: Please enter the first letter coordinate of your Aircraft Carrier (make  sure its in the gameboard)---> " ;
            cin >> Pl2letAc1;
            Pl2letAc1 = toupper(Pl2letAc1);
            if (Pl2letAc1>='A' && Pl2letAc1<='J')
            {
                break;
            }
        }
        cout << endl;
        for (;;)
        {
            cout << "User2: Please enter the first number coordinate of your Aircraft Carrier(make sure its 5 spaces away and horizontal/vertical only)---> " ;
            cin >> Pl2numAc1;
            if (Pl2numAc1>=1 && Pl2numAc1<=10)
            {
                break;
            }
        }
        if (boardPl2[Pl2letAc1-'A'][Pl2numAc1-1] == 'O')
        {
            break;
        }
        else
        {
            goto loop9;
        }

    }

    char Pl2letAc2;
    while (true)
    {
        cout << "User2: Please enter the second letter coordinate of your Aircraft Carrier (make  sure its in the gameboard)---> " ;
        cin >> Pl2letAc2;//get second letter
        cout << endl;
        Pl2letAc2 = toupper(Pl2letAc2);//convert letter to uppercase letter
        if (Pl2letAc2>='A' && Pl2letAc2<='J')//make sure the letter is in the boundaries
        {
            break;
        }
    }
    if (Pl2letAc1!=Pl2letAc2)//make sure the letter is 5 spaces away if the user enters a different letter
    {
        while (true)
        {

            if (Pl2letAc1==Pl2letAc2)
            {
                break;
            }
            if (Pl2letAc2==(Pl2letAc1+4))
            {
                break;
            }
            if (Pl2letAc2==(Pl2letAc1-4))

            {
                break;
            }
            cout << "User2: Please enter the second letter coordinate of your Aircraft Carrier (make  sure its in the gameboard)---> " ;
            cin >> Pl2letAc2;
            cout << endl;
            Pl2letAc2 = toupper(Pl2letAc2);


        }


    }
    int Pl2numAc2 = 0;
    while (Pl2numAc2<=0|| Pl2numAc2>=11 )//make sure the number entered is withing the boundaries
    {
        cout << "User2: Please enter the second number coordinate of your Aircraft Carrier(make sure its 5 spaces away and horizontal/vertical only)---> " ;
        cin >> Pl2numAc2;//get second number
        cout << endl;
    }
    cout<<endl;
loop10://create loop that will check if the coordinate is taken
    for (;;)
    {

        if (boardPl2[Pl2letAc2-'A'][Pl2numAc2-1] == 'O')//if the spot has an 'O' in it then it is free
        {
            break;
        }

        for (;;)
        {
            cout << "Coordinate Already Used OR Coordinate not on the Gameboard...Please enter the following again" << endl;
            cout << "User2: Please enter the second letter coordinate of your Aircraft Carrier (make  sure its in the gameboard)---> " ;
            cin >> Pl2letAc2;
            cout << endl;
            Pl2letAc2 = toupper(Pl2letAc2);
            if (Pl2letAc2>='A' && Pl2letAc2<='J')
            {
                break;
            }
        }
        for (;;)
        {
            cout << "User2: Please enter the second number coordinate of your Aircraft Carrier (make sure its 5 spaces away and horizontal/vertical only)---> " ;
            cin >> Pl2numAc2;
            cout << endl;
            if (Pl2numAc2>=1 && Pl2numAc2<=10)
            {
                break;
            }
        }
        if (boardPl2[Pl2letAc2-'A'][Pl2numAc2-1] == 'O')
        {
            break;
        }
        else
        {
            goto loop10;//if cout << endl;the spot is taken, return to the beginning of the loop
        }

    }
    while(true)
    {
        if (Pl2letAc1==Pl2letAc2)//if the letters are the same, make sure the numbers are 5 spaces away
        {

            if (Pl2numAc2==(Pl2numAc1+4))
            {
                break;
            }
            if (Pl2numAc2==(Pl2numAc1-4)&& (Pl2numAc2>0|| Pl2numAc2<11))
            {
                break;
            }
        }
        if (Pl2letAc1!=Pl2letAc2)
        {
            if (Pl2numAc1==Pl2numAc2)
            {
                break;
            }
        }

        cout << "User2: Please Make Sure That The Input Is Corresponding To The Correct Length (5) Please Enter The Second Number Again---> " ;
        cin >> Pl2numAc2;
        cout << endl;

    }


    char Pl2Pos1='A';
    char Pl2Pos2='A';
    int Pl2letPos;
    int Pl2letPos2;
    Pl2letPos = Pl2letAc1-'A';
    Pl2letPos2 = Pl2letAc2-'A';
    boardPl2[Pl2letPos][Pl2numAc1-1]= Pl2Pos1;
    boardPl2[Pl2letPos2][Pl2numAc2-1]= Pl2Pos2;
    if (Pl2letAc1==Pl2letAc2)//place ship
    {
        if (Pl2numAc1<Pl2numAc2)
        {
            for (int Pl2x=Pl2numAc1-1; Pl2x<=Pl2numAc2-1; Pl2x++)//loop that will connect the 2 coordinates together
            {
                boardPl2[Pl2letPos][Pl2x]='A';//Place 'A' for Aircraft Carrier
            }
        }

        if (Pl2numAc2<Pl2numAc1)
        {
            for (int Pl2x=Pl2numAc2-1; Pl2x<=Pl2numAc1-1; Pl2x++)
            {
                boardPl2[Pl2letPos][Pl2x]='A';
            }
        }
        cout << endl;
    }

    if (Pl2numAc1 == Pl2numAc2)
    {
        if (Pl2letPos<Pl2letPos2)
        {


            for (int Pl2y=Pl2letPos; Pl2y<=Pl2letPos2; Pl2y++)
            {
                boardPl2[Pl2y][Pl2numAc1-1]='A';
                cout << endl;
            }
        }
        if (Pl2letPos2<Pl2letPos)//make sure the user can enter the coordinates in any order they like
        {
            for (int Pl2y=Pl2letPos2; Pl2y<=Pl2letPos; Pl2y++)
            {
                boardPl2[Pl2y][Pl2numAc1-1]='A';
                cout << endl;
            }
        }
    }

    displayBoardPl2(boardPl2);//display board with ship on it
//..........................................Placing BattleShip........................................................

    char Pl2letBs1;
    while (true)
    {
        cout << "User2: Please enter the first letter coordinate of your Battle Ship (make  sure its in the gameboard)---> " ;
        cin >> Pl2letBs1;//get first letter coordinate
        cout << endl;
        Pl2letBs1 = toupper(Pl2letBs1);//convert letter to uppercase
        {
            if (Pl2letBs1>='A' && Pl2letBs1<='J')//make sure letter entered is in the boundaries
                break;
        }
    }
    int Pl2numBs1 = 0;

    while (Pl2numBs1<= 0|| Pl2numBs1>=11 )//make sure the number is in the correct boundaries
    {
        cout << "User2: Please enter the first number coordinate of your Battle Ship(make sure its 4 spaces away and horizontal/vertical only)---> " ;
        cin >> Pl2numBs1;//get first number
        cout << endl;
    }
loop11://create loop that stops user from entering an already taken coordinate
    for (;;)
    {

        if (boardPl2[Pl2letBs1-'A'][Pl2numBs1-1] == 'O')//check if spot is taken
        {
            break;
        }

        for (;;)
        {
            cout << "Coordinate Already Used OR Coordinate not on the Gameboard...Please enter the following again" << endl;
            cout << "User2: Please enter the first letter coordinate of your Battle Ship (make  sure its in the gameboard)---> " ;
            cin >> Pl2letBs1;
            cout << endl;
            Pl2letBs1 = toupper(Pl2letBs1);
            if (Pl2letBs1>='A' && Pl2letBs1<='J')
            {
                break;
            }
        }
        for (;;)
        {
            cout << "User2: Please enter the first number coordinate of your Battle Ship(make sure its 4 spaces away and horizontal/vertical only)---> " ;
            cin >> Pl2numBs1;
            cout << endl;
            if (Pl2numBs1>=1 && Pl2numBs1<=10)
            {
                break;
            }
        }
        if (boardPl2[Pl2letBs1-'A'][Pl2numBs1-1] == 'O')//check if new coordinate is taken
        {
            break;
        }
        else
        {
            goto loop11;//if coordinate is taken, return to beginning of loop
        }

    }
    char Pl2letBs2;
    while (true)
    {
        cout << "User2: Please enter the second letter coordinate of your Battle Ship (make  sure its in the gameboard)---> " ;
        cin >> Pl2letBs2;//get second letter
        cout << endl;
        Pl2letBs2 = toupper(Pl2letBs2);//convert it to uppercase
        if (Pl2letBs2>='A' && Pl2letBs2<='J')//make sure its in the boundaries
        {
            break;
        }
    }
    if (Pl2letBs1!=Pl2letBs2)//if the letters are different, make sure the numbers are the same
    {


        while (true)
        {

            if (Pl2letBs1==Pl2letBs2)
            {
                break;
            }
            if (Pl2letBs2==(Pl2letBs1+3))//make sure the numbers are the correct length away
            {
                break;
            }
            if (Pl2letBs2==(Pl2letBs1-3))

            {
                break;
            }
            cout << "User2: Please enter the second letter coordinate of your Battle Ship (make  sure its in the gameboard)---> " ;
            cin >> Pl2letBs2;
            cout << endl;
            Pl2letBs2 = toupper(Pl2letBs2);


        }


    }
    int Pl2numBs2 = 0;
    while (Pl2numBs2<=0|| Pl2numBs2>=11 )//make sure second letter is in the range
    {
        cout << "User2: Please enter the second number coordinate of your Battle Ship(make sure its 4 spaces away and horizontal/vertical only)---> " ;
        cin >> Pl2numBs2;
        cout << endl;
    }
    cout<<endl;
loop12://create loop that will stop user from entering a taken coordinate
    for (;;)
    {

        if (boardPl2[Pl2letBs2-'A'][Pl2numBs2-1] == 'O')//check if location is empty
        {
            break;
        }

        for (;;)
        {
            cout << "Coordinate Already Used OR Coordinate not on the Gameboard...Please enter the following again" << endl;
            cout << "User2: Please enter the second letter coordinate of your Battle Ship (make  sure its in the gameboard)---> " ;
            cin >> Pl2letBs2;
            cout << endl;
            Pl2letBs2 = toupper(Pl2letBs2);
            if (Pl2letBs2>='A' && Pl2letBs2<='J')
            {
                break;
            }
        }
        for (;;)
        {
            cout << "User2: Please enter the second number coordinate of your Battle Ship(make sure its 4 spaces away and horizontal/vertical only)---> " ;
            cin >> Pl2numBs2;
            cout << endl;
            if (Pl2numBs2>=1 && Pl2numBs2<=10)
            {
                break;
            }
        }
        if (boardPl2[Pl2letBs2-'A'][Pl2numBs2-1] == 'O')
        {
            break;
        }
        else
        {
            goto loop12;//if spot is taken go to the beginning of the loop
        }

    }
    while(true)
    {
        if (Pl2letBs1==Pl2letBs2)//if letters are equal make sure numbers are different
        {

            if (Pl2numBs2==(Pl2numBs1+3))//make sure the numbers are the appropriate length away
            {
                break;
            }
            if (Pl2numBs2==(Pl2numBs1-3)&& (Pl2numBs2>0|| Pl2numBs2<11))
            {
                break;
            }
        }
        if (Pl2letBs1!=Pl2letBs2)
        {
            if (Pl2numBs1==Pl2numBs2)
            {
                break;
            }
        }
        cout << endl;
        cout << "User2: Please Make Sure That The Input Is Corresponding To The Correct Length (4) Please Enter The Second Number Again---> " ;
        cin >> Pl2numBs2;
        cout << endl;

    }



    char Pl2Pos1a='B';
    char Pl2Pos2a='B';
    int Pl2letBsPos;
    int Pl2letBsPos2;
    Pl2letBsPos = Pl2letBs1-'A';
    Pl2letBsPos2 = Pl2letBs2-'A';
    boardPl2[Pl2letBsPos][Pl2numBs1-1]= Pl2Pos1a;
    boardPl2[Pl2letBsPos2][Pl2numBs2-1]= Pl2Pos2a;
    if (Pl2letBs1==Pl2letBs2)//place ship
    {
        if (Pl2numBs1<Pl2numBs2)
        {
            for (int Pl2x1=Pl2numBs1-1; Pl2x1<=Pl2numBs2-1; Pl2x1++)//loop that will connect the 2 coordinates together
            {
                boardPl2[Pl2letBsPos][Pl2x1]='B';//display 'B' for battleship
            }
        }

        if (Pl2numBs2<Pl2numBs1)
        {
            for (int Pl2x1=Pl2numBs2-1; Pl2x1<=Pl2numBs1-1; Pl2x1++)
            {
                boardPl2[Pl2letBsPos][Pl2x1]='B';
            }
        }
        cout << endl;
    }

    if (Pl2numBs1 == Pl2numBs2)//if numbers are equal make sure letters are different
    {
        if (Pl2letBsPos<Pl2letBsPos2)
        {


            for (int Pl2y1=Pl2letBsPos; Pl2y1<=Pl2letBsPos2; Pl2y1++)
            {
                boardPl2[Pl2y1][Pl2numBs1-1]='B';
                cout << endl;
            }
        }
        if (Pl2letBsPos2<Pl2letBsPos)
        {
            for (int Pl2y1=Pl2letBsPos2; Pl2y1<=Pl2letBsPos; Pl2y1++)
            {
                boardPl2[Pl2y1][Pl2numBs1-1]='B';
                cout << endl;
            }
        }
    }




    displayBoardPl2(boardPl2);
//...........................................Placing Submarine........................................................
    char Pl2letSm1;
    while (true)
    {
        cout << "User2: Please enter the first letter coordinate of your Submarine (make  sure its in the gameboard)---> " ;
        cin >> Pl2letSm1;//get first letter
        cout << endl;
        Pl2letSm1 = toupper(Pl2letSm1);//convert letter to uppercase
        {
            if (Pl2letSm1>='A' && Pl2letSm1<='J')//make sure letters are within boundaries
                break;
        }
    }
    int Pl2numSm1 = 0;

    while (Pl2numSm1<= 0|| Pl2numSm1>=11 )//make sure number is within boundaries
    {
        cout << "User2: Please enter the first number coordinate of your Submarine(make sure its 3 spaces away and horizontal/vertical only)---> " ;
        cin >> Pl2numSm1;//get second number
        cout << endl;
    }
loop13://create loop that will stop user from entering a taken coordinate
    for (;;)
    {

        if (boardPl2[Pl2letSm1-'A'][Pl2numSm1-1] == 'O')//check if spot is taken
        {
            break;
        }

        for (;;)
        {
            cout << "Coordinate Already Used OR Coordinate not on the Gameboard...Please enter the following again" << endl;
            cout << "User2: Please enter the first letter coordinate of your Submarine (make  sure its in the gameboard)---> " ;
            cin >> Pl2letSm1;
            cout << endl;
            Pl2letSm1 = toupper(Pl2letSm1);
            if (Pl2letSm1>='A' && Pl2letSm1<='J')
            {
                break;
            }
        }
        for (;;)
        {
            cout << "User2: Please enter the first number coordinate of your Submarine (make sure its 3 spaces away and horizontal/vertical only)---> " ;
            cin >> Pl2numSm1;
            cout << endl;
            if (Pl2numSm1>=1 && Pl2numSm1<=10)
            {
                break;
            }
        }
        if (boardPl2[Pl2letSm1-'A'][Pl2numSm1-1] == 'O')
        {
            break;
        }
        else
        {
            goto loop13;//return to beginning if spot is not taken
        }

    }
    char Pl2letSm2;
    while (true)
    {
        cout << "User2: Please enter the second letter coordinate of your Submarine (make  sure its in the gameboard)---> " ;
        cin >> Pl2letSm2;//get second letter
        cout << endl;
        Pl2letSm2 = toupper(Pl2letSm2);//convert letter to uppercase
        if (Pl2letSm2>='A' && Pl2letSm2<='J')//make sure letter is within boundaries
        {
            break;
        }
    }
    if (Pl2letSm1!=Pl2letSm2)//if letters are different numbers must be the same
    {

        while (true)
        {

            if (Pl2letSm1==Pl2letSm2)
            {
                break;
            }
            if (Pl2letSm2==(Pl2letSm1+2))//make sure the numbers are the correct distance away
            {
                break;
            }
            if (Pl2letSm2==(Pl2letSm1-2))

            {
                break;
            }
            cout << "User2: Please enter the second letter coordinate of your Submarine (make  sure its in the gameboard)---> " ;
            cin >> Pl2letSm2;
            cout << endl;
            Pl2letSm2 = toupper(Pl2letSm2);


        }


    }
    int Pl2numSm2 = 0;
    while (Pl2numSm2<=0|| Pl2numSm2>=11 )//make sure number is within the correct boundaries
    {
        cout << "User2: Please enter the second number coordinate of your Submarine(make sure its 3 spaces away and horizontal/vertical only)---> " ;
        cin >> Pl2numSm2;
        cout << endl;
    }
    cout<<endl;
loop14://create loop that will stop user from entering a taken coordinate
    for (;;)
    {

        if (boardPl2[Pl2letSm2-'A'][Pl2numSm2-1] == 'O')//check if spot is taken
        {
            break;
        }

        for (;;)
        {
            cout << "Coordinate Already Used OR Coordinate not on the Gameboard...Please enter the following again" << endl;
            cout << "User2: Please enter the second letter coordinate of your Submarine (make  sure its in the gameboard)---> " ;
            cin >> Pl2letSm2;
            cout << endl;
            Pl2letSm2 = toupper(Pl2letSm2);
            if (Pl2letSm2>='A' && Pl2letSm2<='J')
            {
                break;
            }
        }
        for (;;)
        {
            cout << "User2: Please enter the second number coordinate of your Submarine(make sure its 3 spaces away and horizontal/vertical only)---> " ;
            cin >> Pl2numSm2;
            cout << endl;
            if (Pl2numSm2>=1 && Pl2numSm2<=10)
            {
                break;
            }
        }
        if (boardPl2[Pl2letSm2-'A'][Pl2numSm2-1] == 'O')
        {
            break;
        }
        else
        {
            goto loop14;// return to beginning of loop if spot is occupied
        }

    }
    while(true)
    {
        if (Pl2letSm1==Pl2letSm2)//if letters are the same then numbers have to be different
        {

            if (Pl2numSm2==(Pl2numSm1+2))//make sure the numbers are the correct distance away
            {
                break;
            }
            if (Pl2numSm2==(Pl2numSm1-2)&& (Pl2numSm2>0|| Pl2numSm2<11))
            {
                break;
            }
        }
        if (Pl2letSm1!=Pl2letSm2)
        {
            if (Pl2numSm1==Pl2numSm2)
            {
                break;
            }
        }
        cout << endl;
        cout << "User2: Please Make Sure That The Input Is Corresponding To The Correct Length (3) Please Enter The Second Number Again---> " ;
        cin >> Pl2numSm2;
        cout << endl;

    }



    char Pl2Pos1b='S';
    char Pl2Pos2b='S';
    int Pl2letSmPos;
    int Pl2letSmPos2;
    Pl2letSmPos = Pl2letSm1-'A';
    Pl2letSmPos2 = Pl2letSm2-'A';
    boardPl2[Pl2letSmPos][Pl2numSm1-1]= Pl2Pos1b;
    boardPl2[Pl2letSmPos2][Pl2numSm2-1]= Pl2Pos2b;
    if (Pl2letSm1==Pl2letSm2)//place ship
    {
        if (Pl2numSm1<Pl2numSm2)
        {
            for (int Pl2x2=Pl2numSm1-1; Pl2x2<=Pl2numSm2-1; Pl2x2++)//loop that will connect the 2 coordinates
            {
                boardPl2[Pl2letSmPos][Pl2x2]='S';//place 'S' for Submarine
            }
        }

        if (Pl2numSm2<Pl2numSm1)
        {
            for (int Pl2x2=Pl2numSm2-1; Pl2x2<=Pl2numSm1-1; Pl2x2++)
            {
                boardPl2[Pl2letSmPos][Pl2x2]='S';
            }
        }
        cout << endl;
    }

    if (Pl2numSm1 == Pl2numSm2)
    {
        if (Pl2letSmPos<Pl2letSmPos2)
        {


            for (int Pl2y2=Pl2letSmPos; Pl2y2<=Pl2letSmPos2; Pl2y2++)
            {
                boardPl2[Pl2y2][Pl2numSm1-1]='S';
                cout << endl;
            }
        }
        if (Pl2letSmPos2<Pl2letSmPos)
        {
            for (int Pl2y2=letSmPos2; Pl2y2<=Pl2letSmPos; Pl2y2++)
            {
                boardPl2[Pl2y2][Pl2numSm1-1]='S';
                cout << endl;
            }
        }
    }

    displayBoardPl2(boardPl2);//display board
//..........................................Placing Cruiser...................................................................

    char Pl2letCr1;
    while (true)
    {
        cout << "User2: Please enter the first letter coordinate of your Cruiser(make  sure its in the gameboard)---> " ;
        cin >> Pl2letCr1;//get first letter
        cout << endl;
        Pl2letCr1 = toupper(Pl2letCr1);//convert letter to uppercase
        {
            if (Pl2letCr1>='A' && Pl2letCr1<='J')//make sure letters are in the boundaries
                break;
        }
    }
    int Pl2numCr1 = 0;

    while (Pl2numCr1<= 0||Pl2numCr1>=11 )//make sure the numbers are in the boundaries
    {
        cout << "User2: Please enter the first number coordinate of your Cruiser(make sure its 3 spaces away and horizontal/vertical only)---> " ;
        cin >> Pl2numCr1;//get second letter
        cout << endl;
    }
loop15://create loop that will stop user from entering a taken coordinate
    for (;;)
    {

        if (boardPl2[Pl2letCr1-'A'][Pl2numCr1-1] == 'O')//check if spot is taken
        {
            break;
        }

        for (;;)
        {
            cout << "Coordinate Already Used OR Coordinate not on the Gameboard...Please enter the following again" << endl;
            cout << "User2: Please enter the first letter coordinate of your Cruiser (make  sure its in the gameboard)---> " ;
            cin >> Pl2letCr1;
            cout << endl;
            Pl2letCr1 = toupper(Pl2letCr1);
            if (Pl2letCr1>='A' && Pl2letCr1<='J')
            {
                break;
            }
        }
        for (;;)
        {
            cout << "User2: Please enter the first number coordinate of your Cruiser(make sure its 3 spaces away and horizontal/vertical only)---> " ;
            cin >> Pl2numCr1;
            cout << endl;
            if (Pl2numCr1>=1 && Pl2numCr1<=10)
            {
                break;
            }
        }
        if (boardPl2[Pl2letCr1-'A'][Pl2numCr1-1] == 'O')
        {
            break;
        }
        else
        {
            goto loop15;//return to beginning of loop if occupied
        }

    }
    char Pl2letCr2;
    while (true)
    {
        cout << "User2: Please enter the second letter coordinate of your Cruiser(make  sure its in the gameboard)---> " ;
        cin >> Pl2letCr2;//get second letter
        cout << endl;
        Pl2letCr2 = toupper(Pl2letCr2);//convert to uppercase
        if (Pl2letCr2>='A' && Pl2letCr2<='J')//make sure letter is in boundaries
        {
            break;
        }
    }
    if (Pl2letCr1!=Pl2letCr2)//if the letter is not the same as the previous letter
    {

            while (true)
            {

                if (Pl2letCr1==Pl2letCr2)
                {
                    break;
                }
                if (Pl2letCr2==(Pl2letCr1+2))//make sure the letter is the correct distance away
                {
                    break;
                }
                if (Pl2letCr2==(Pl2letCr1-2))

                {
                    break;
                }
                cout << "User1: Please enter the second letter coordinate of your Cruiser (make  sure its in the gameboard)---> " ;
                cin >> Pl2letCr2;
                cout << endl;
                Pl2letCr2 = toupper(Pl2letCr2);


            }


    }
    int Pl2numCr2 = 0;
    while (Pl2numCr2<=0|| Pl2numCr2>=11 )//make sure second number is in the boundaries
    {
        cout << "User2: Please enter the second number coordinate of your Cruiser(make sure its 3 spaces away and horizontal/vertical only)---> " ;
        cin >> Pl2numCr2;//get second letter
        cout << endl;
    }
    cout<<endl;
loop16://create loop that will stop user from entering a taken coordinate
    for (;;)
    {

        if (boardPl2[Pl2letCr2-'A'][Pl2numCr2-1] == 'O')//check if spot is taken
        {
            break;
        }

        for (;;)
        {
            cout << "Coordinate Already Used OR Coordinate not on the Gameboard...Please enter the following again" << endl;
            cout << "User2: Please enter the second letter coordinate of your Cruiser (make  sure its in the gameboard)---> " ;
            cin >> Pl2letCr2;
            cout << endl;
            Pl2letCr2 = toupper(Pl2letCr2);
            if (Pl2letCr2>='A' && Pl2letCr2<='J')
            {
                break;
            }
        }
        for (;;)
        {
            cout << "User2: Please enter the second number coordinate of your Cruiser(make sure its 3 spaces away and horizontal/vertical only)---> " ;
            cin >> Pl2numCr2;
            cout << endl;
            if (Pl2numCr2>=1 && Pl2numCr2<=10)
            {
                break;
            }
        }
        if (boardPl2[Pl2letCr2-'A'][Pl2numCr2-1] == 'O')
        {
            break;
        }
        else
        {
            goto loop16;//return to beginning if spot is taken
        }

    }
    while(true)
    {
        if (Pl2letCr1==Pl2letCr2)//if letters are the same then numbers need to be different
        {

            if (Pl2numCr2==(Pl2numCr1+2))//make sure numbers are correct distance away
            {
                break;
            }
            if (Pl2numCr2==(Pl2numCr1-2)&& (Pl2numCr2>0|| Pl2numCr2<11))
            {
                break;
            }
        }
        if (Pl2letCr1!=Pl2letCr2)
        {
            if (Pl2numCr1==Pl2numCr2)
            {
                break;
            }
        }
        cout << endl;
        cout << "User2: Please Make Sure That The Input Is Corresponding To The Correct Length (3) Please Enter The Second Number Again---> " ;
        cin >> Pl2numCr2;
        cout << endl;

    }

    char Pl2Pos1c='C';
    char Pl2Pos2c='C';
    int Pl2letCrPos;
    int Pl2letCrPos2;
    Pl2letCrPos = Pl2letCr1-'A';
    Pl2letCrPos2 = Pl2letCr2-'A';
    boardPl2[Pl2letCrPos][Pl2numCr1-1]= Pl2Pos1c;
    boardPl2[Pl2letCrPos2][Pl2numCr2-1]= Pl2Pos2c;
    if (Pl2letCr1==Pl2letCr2)//place ship
    {
        if (Pl2numCr1<Pl2numCr2)
        {
            for (int Pl2x3=Pl2numCr1-1; Pl2x3<=Pl2numCr2-1; Pl2x3++)//loop will connect the 2 coordinates
            {
                boardPl2[Pl2letCrPos][Pl2x3]='C';// display 'C' for Cruiser
            }
        }

        if (Pl2numCr2<Pl2numCr1)
        {
            for (int Pl2x3=Pl2numCr2-1; Pl2x3<=Pl2numCr1-1; Pl2x3++)
            {
                boardPl2[Pl2letCrPos][Pl2x3]='C';
            }
        }
        cout << endl;
    }
    if (Pl2numCr1 == Pl2numCr2)
    {
        if (Pl2letCrPos<Pl2letCrPos2)
        {


            for (int Pl2y3=Pl2letCrPos; Pl2y3<=Pl2letCrPos2; Pl2y3++)
            {
                boardPl2[Pl2y3][Pl2numCr1-1]='C';
                cout << endl;
            }
        }
        if (Pl2letCrPos2<Pl2letCrPos)
        {
            for (int Pl2y3=Pl2letCrPos2; Pl2y3<=Pl2letCrPos; Pl2y3++)
            {
                board[Pl2y3][Pl2numCr1-1]='C';
                cout << endl;
            }
        }
    }

    displayBoardPl2(boardPl2);//display board
//.....................................................Placing Destroyer.............................................
    char Pl2letDs1;
    while (true)
    {
        cout << "User2: Please enter the first letter coordinate of your Destroyer (make  sure its in the gameboard)---> " ;
        cin >> Pl2letDs1;//get first letter
        cout << endl;
        Pl2letDs1 = toupper(Pl2letDs1);// convert letter to uppercase
        {
            if (Pl2letDs1>='A' && Pl2letDs1<='J')//make sure letter is in the boundaries
                break;
        }
    }
    int Pl2numDs1 = 0;

    while (Pl2numDs1<= 0|| Pl2numDs1>=11 )//make sure number is in boundaries
    {
        cout << "User2: Please enter the first number coordinate of your Destroyer(make sure its 2 spaces away and horizontal/vertical only)---> " ;
        cin >> Pl2numDs1;//get first number
        cout << endl;
    }
    cout << endl;
loop17://create loop that will stop user from entering a taken coordinate
    for (;;)
    {

        if (boardPl2[Pl2letDs1-'A'][Pl2numDs1-1] == 'O')//check if spot is taken
        {
            break;
        }

        for (;;)
        {
            cout << "Coordinate Already Used OR Coordinate not on the Gameboard...Please enter the following again" << endl;
            cout << "User2: Please enter the first letter coordinate of your Destroyer (make  sure its in the gameboard)---> " ;
            cin >> Pl2letDs1;
            cout << endl;
            Pl2letDs1 = toupper(Pl2letDs1);
            if (Pl2letDs1>='A' && Pl2letDs1<='J')
            {
                break;
            }
        }
        for (;;)
        {
            cout << "User2: Please enter the first number coordinate of your Destroyer (make sure its 2 spaces away and horizontal/vertical only)---> " ;
            cin >> Pl2numDs1;
            cout << endl;
            if (Pl2numDs1>=1 && Pl2numDs1<=10)
            {
                break;
            }
        }
        if (boardPl2[Pl2letDs1-'A'][Pl2numDs1-1] == 'O')
        {
            break;
        }
        else
        {
            goto loop17;//return to beginning of loop if spot is occupied
        }

    }
    char Pl2letDs2;
    while (true)
    {
        cout << "User2: Please enter the second letter coordinate of your Destroyer (make  sure its in the gameboard)---> " ;
        cin >> Pl2letDs2;//get second letter
        cout << endl;
        Pl2letDs2 = toupper(Pl2letDs2);//convert to uppercase
        if (Pl2letDs2>='A' && Pl2letDs2<='J')//make sure the letters are int he boundaries
        {
            break;
        }
    }
    if (Pl2letDs1!=Pl2letDs2)//if letters are different numbers have to be the same
    {


            while (true)
            {

                if (Pl2letDs1==Pl2letDs2)
                {
                    break;
                }
                if (Pl2letDs2==(Pl2letDs1+1))//make sure numbers are the correct length away
                {
                    break;
                }
                if (Pl2letDs2==(Pl2letDs1-1))

                {
                    break;
                }
                cout << "User2: Please enter the second letter coordinate of your Destroyer (make  sure its in the gameboard)---> " ;
                cin >> Pl2letDs2;
                cout << endl;
                Pl2letDs2 = toupper(Pl2letDs2);


            }


    }
    int Pl2numDs2 = 0;
    while (Pl2numDs2<=0|| Pl2numDs2>=11 )//make sure input is the the correct boundaries
    {
        cout << "User2: Please enter the second number coordinate of your Destroyer(make sure its 2 spaces away and horizontal/vertical only)---> " ;
        cin >> Pl2numDs2;//get second number
        cout << endl;
    }
    cout<<endl;
loop18://create loop that will stop user from entering a taken coordinate
    for (;;)
    {

        if (boardPl2[Pl2letDs2-'A'][Pl2numDs2-1] == 'O')//check if spot is taken
        {
            break;
        }

        for (;;)
        {
            cout << "Coordinate Already Used OR Coordinate not on the Gameboard...Please enter the following again" << endl;
            cout << "User2: Please enter the second letter coordinate of your Destroyer (make  sure its in the gameboard)---> " ;
            cin >> Pl2letDs2;
            cout << endl;
            Pl2letDs2 = toupper(Pl2letDs2);
            if (Pl2letDs2>='A' && Pl2letDs2<='J')
            {
                break;
            }
        }
        for (;;)
        {
            cout << "User2: Please enter the second number coordinate of your Destroyer(make sure its 2 spaces away and horizontal/vertical only)---> " ;
            cin >> Pl2numDs2;
            cout << endl;
            if (Pl2numDs2>=1 && Pl2numDs2<=10)
            {
                break;
            }
        }
        if (boardPl2[Pl2letDs2-'A'][Pl2numDs2-1] == 'O')
        {
            break;
        }
        else
        {
            goto loop18;//return to beginning if spot is taken
        }

    }
    while(true)
    {
        if (Pl2letDs1==Pl2letDs2)// if letters are the same, numbers have to be different
        {

            if (Pl2numDs2==(Pl2numDs1+1))//make sure numbers are the correct distance away
            {
                break;
            }
            if (Pl2numDs2==(Pl2numDs1-1)&& (Pl2numDs2>0|| Pl2numDs2<11))
            {
                break;
            }
        }
        if (Pl2letDs1!=Pl2letDs2)
        {
            if (Pl2numDs1==Pl2numDs2)
            {
                break;
            }
        }
        cout << endl;
        cout << "User2: Please Make Sure That The Input Is Corresponding To The Correct Length (2) Please Enter The Second Number Again---> " ;
        cin >> Pl2numDs2;
        cout << endl;

    }


    char Pl2Pos1d='D';
    char Pl2Pos2d='D';
    int Pl2letDsPos;
    int Pl2letDsPos2;
    Pl2letDsPos = Pl2letDs1-'A';
    Pl2letDsPos2 = Pl2letDs2-'A';
    boardPl2[Pl2letDsPos][Pl2numDs1-1]= Pl2Pos1d;
    boardPl2[Pl2letDsPos2][Pl2numDs2-1]= Pl2Pos2d;
    if (Pl2letDs1==Pl2letDs2)//place ship
    {
        if (Pl2numDs1<Pl2numDs2)
        {
            for (int Pl2x4=Pl2numDs1-1; Pl2x4<=Pl2numDs2-1; Pl2x4++)//create loop that will connect the 2 coordinates
            {
                boardPl2[Pl2letDsPos][Pl2x4]='D';//display 'D' for Destroyer
            }
        }

        if (Pl2numDs2<Pl2numDs1)
        {
            for (int Pl2x4=Pl2numDs2-1; Pl2x4<=Pl2numDs1-1; Pl2x4++)
            {
                boardPl2[Pl2letDsPos][Pl2x4]='D';
            }
        }
        cout << endl;
    }
    if (Pl2numDs1 == Pl2numDs2)
    {
        if (Pl2letDsPos<Pl2letDsPos2)
        {


            for (int Pl2y4=Pl2letDsPos; Pl2y4<=Pl2letDsPos2; Pl2y4++)
            {
                boardPl2[Pl2y4][Pl2numDs1-1]='D';
                cout << endl;
            }
        }
        if (Pl2letDsPos2<Pl2letDsPos)
        {
            for (int Pl2y4=Pl2letDsPos2; Pl2y4<=Pl2letDsPos; Pl2y4++)
            {
                boardPl2[Pl2y4][Pl2numDs1-1]='D';
                cout << endl;
            }
        }
    }

    displayBoardPl2(boardPl2);//display final board
//........................................Player 1 attack............................................................
    initializeBoardAttack();
    initializeBoardPl2Attack();
    for(;;)
    {
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout << " User1: Now Its your turn to Attack. This is your gameboard:" << endl;
        displayBoardAttack(boardAttack);//display blank board to keep track of hits and misses
        cout << endl;
        displayBoard(board);//Display board with ships on it
        char Pl1letAttack1;
        while (true)
        {
            cout << "User1: Please enter the letter coordinate of your Attack---> " ;
            cin >> Pl1letAttack1;
            Pl1letAttack1 = toupper(Pl1letAttack1);
            {
                if (Pl1letAttack1>='A' && Pl1letAttack1<='J')//make sure input is within the range
                    break;
            }
        }
        int Pl1numAttack1 = 0;

        while (Pl1numAttack1<= 0|| Pl1numAttack1>=11 )//make sure input is within the range
        {
            cout << "User1: Please enter the number coordinate of your Attack---> " ;
            cin >> Pl1numAttack1;
            cout << endl;
        }
        char Pl1PosAttack1='O';
        int Pl1letAttackPos;
        Pl1letAttackPos = Pl1letAttack1-'A';
        if (boardPl2[Pl1letAttackPos][Pl1numAttack1-1]!=Pl1PosAttack1)
        {
            boardAttack[Pl1letAttackPos][Pl1numAttack1-1]='X';//If it is a hit, mark it with an x
            boardPl2[Pl1letAttackPos][Pl1numAttack1-1]='X';
            cout<<endl;
            cout <<"It's a Hit!!" << endl;
        }
        else
        {
            boardAttack[Pl1letAttackPos][Pl1numAttack1-1]='!';//if its not a hit mark it with an '!'
            boardPl2[Pl1letAttackPos][Pl1numAttack1-1]='!';
            cout <<"Not a hit" << endl;
        }


        displayBoardAttack(boardAttack);//display new board
        cout << endl;
        displayBoard(board);
        if (Pl1WinCheck()==true)//check if player 1 has won
        {
            cout<< endl;
            cout << "Player 1, You Have Won!" << endl;
            break;
        }

        cout<<endl;
        cout << "Please enter any character to continue --> ";
        char c;
        cin>> c;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;

//...............................................Player 2 Attack......................................................
        cout << " User 2: Now Its your turn to Attack. This is your gameboard:" << endl;

        displayBoardPl2Attack(boardPl2Attack);//display blank board to mark hits and misses
        cout << endl;
        displayBoardPl2(boardPl2);//display board with ship
        char Pl2letAttack2;
        while (true)
        {
            cout << "User2: Please enter the letter coordinate of your Attack---> " ;
            cin >> Pl2letAttack2;
            Pl2letAttack2 = toupper(Pl2letAttack2);//convert letter to uppercase
            {
                if (Pl2letAttack2>='A' && Pl2letAttack2<='J')//make sure input is within the range
                    break;
            }
        }
        int Pl2numAttack2 = 0;

        while (Pl2numAttack2<= 0|| Pl2numAttack2>=11 )//make sure input is within the range
        {
            cout << "User2: Please enter the number coordinate of your Attack---> " ;
            cin >> Pl2numAttack2;
        }
        char Pl2PosAttack2='O';
        int Pl2letAttackPos;
        Pl2letAttackPos = Pl2letAttack2-'A';
        if (board[Pl2letAttackPos][Pl2numAttack2-1]!=Pl2PosAttack2)
        {
            boardPl2Attack[Pl2letAttackPos][Pl2numAttack2-1]='X';//mark a hit with an x
            board[Pl2letAttackPos][Pl2numAttack2-1]='X';
            cout<<endl;
            cout <<"It's a Hit!!" << endl;
        }
        else
        {
            boardPl2Attack[Pl2letAttackPos][Pl2numAttack2-1]='!';//mark a miss with an !
            board[Pl2letAttackPos][Pl2numAttack2-1]='!';
            cout <<"Not a hit" << endl;
        }

        displayBoardPl2Attack(boardPl2Attack);//display the boards
        cout << endl;
        displayBoardPl2(boardPl2);
        if (Pl2WinCheck()==true)//check if player 2 has won
        {
            cout << endl;
            cout << "Player 2, You Have Won!" << endl;
            break;
        }
        cout<<endl;
        cout << "Please enter any character to continue --> ";
        char d;
        cin>> d;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;

    }
    return 0;

}
void initializeBoard()//to initialize board for pl1
{
    for(int x=0; x<10 ; x++)
    {
        for (int y=0; y<10; y++)
        {
            board[x][y]= 'O';
        }
    }
}
void displayBoard (char gameboard[10][10])//loop to display the gameboard for pl1
{
    cout << " " ;
    for (int col1=1 ; col1<=10; col1++)
    {

        cout << setw(4) << col1;
    }
    cout<<endl;
    for (int row =0 ; row<10; row++)
    {
        cout << (char) ('A'+row);
        for (int col=0; col<10; col++)
        {
            cout << setw(4) << gameboard[row][col];
        }
        cout << endl;
    }
}
void initializeBoardPl2()//to initialize board for pl2
{
    for(int x=0; x<10 ; x++)
    {
        for (int y=0; y<10; y++)
        {
            boardPl2[x][y]= 'O';
        }
    }
}
void displayBoardPl2 (char gameboardPl2[10][10])//display gameboard for pl2
{
    cout << " " ;
    for (int col1=1 ; col1<=10; col1++)
    {

        cout << setw(4) << col1;
    }
    cout<<endl;
    for (int row =0 ; row<10; row++)
    {
        cout << (char) ('A'+row);
        for (int col=0; col<10; col++)
        {
            cout << setw(4) << gameboardPl2[row][col];
        }
        cout << endl;
    }
}
void initializeBoardAttack()//to initialize board for pl1 attack
{
    for(int x=0; x<10 ; x++)
    {
        for (int y=0; y<10; y++)
        {
            boardAttack[x][y]= 'O';
        }
    }
}
void displayBoardAttack(char gameboardAttack[10][10])//display pl1 attack board
{
    cout << " " ;
    for (int col1=1 ; col1<=10; col1++)
    {

        cout << setw(4) << col1;
    }
    cout<<endl;
    for (int row =0 ; row<10; row++)
    {
        cout << (char) ('A'+row);
        for (int col=0; col<10; col++)
        {
            cout << setw(4) << gameboardAttack[row][col];
        }
        cout << endl;
    }
}
void initializeBoardPl2Attack()//to initialize board for pl2 attack
{
    for(int x=0; x<10 ; x++)
    {
        for (int y=0; y<10; y++)
        {
            boardPl2Attack[x][y]= 'O';
        }
    }
}
void displayBoardPl2Attack (char gameboardPl2Attack[10][10])//display attack board for pl2
{
    cout << " " ;
    for (int col1=1 ; col1<=10; col1++)
    {

        cout << setw(4) << col1;
    }
    cout<<endl;
    for (int row =0 ; row<10; row++)
    {
        cout << (char) ('A'+row);
        for (int col=0; col<10; col++)
        {
            cout << setw(4) << gameboardPl2Attack[row][col];
        }
        cout << endl;
    }
}


bool Pl1WinCheck()//create function that will scan the entire board
{
    int counter=0;
    for (int col=0; col<10; col++)
    {
        for (int row=0; row<10; row++)
        {
            if (boardPl2[col][row]=='X')//detects if there are any 'x' 's on the board
            {
                counter++;
                if (counter==17)//if the counter equals 17 then player 1 has won
                {
                    return true;
                }
            }

        }

    }
}
bool Pl2WinCheck()//create function that will scan the entire board
{
    int counter2=0;
    for (int col2=0; col2<10; col2++)
    {
        for (int row2=0; row2<10; row2++)
        {
            if (board[col2][row2]=='X')//detects if there are any 'x' 's on the board
            {
                counter2++;//counts the amount of x's
                if (counter2==17)//if the counter equals 17 then player 1 has won
                {
                    return true;
                }
            }

        }

    }
}

