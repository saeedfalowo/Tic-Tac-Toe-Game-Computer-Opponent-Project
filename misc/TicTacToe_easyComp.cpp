#include <iostream>
#include <list>
using namespace std;

char square[10] = {'o','1','2','3','4','5','6','7','8','9'};


int checkwin();
void board();
char chosenSquare(char mark, int choice, int player);
char comPlay1(std::list<int> numberList);
std::list<int> updateList(std::list<int> numberList, int number);

int main()
{
    // construct the number list
    int numList[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::list<int> numberList(numList, numList + sizeof(numList)/sizeof(int));

    int player = 1,i,choice;
    char mark;

    do
    {
        board();
        player=(player%2)?1:2;
        if (player == 1)
        {
            cout << "Player " << player << ", enter a number:  ";
            cin >> choice;
            numberList = updateList(numberList, choice);
        }
        else
        {
            
            choice = comPlay1(numberList);
            numberList = updateList(numberList, choice);
        }

        mark=(player == 1) ? 'X' : 'O';
        chosenSquare(mark, choice, player);
        

        i=checkwin();

        player++;
    }while(i==-1);
    board();
    if(i==1)
    {
        if (--player==1)
            cout <<"==>\aPlayer1 wins! ";
        else
            cout << "==>\aComputer wins! ";
    }
    else
        cout<<"==>\aGame draw";

    cin.ignore();
    cin.get();
    return 0;
}

/*********************************************
    FUNCTION TO RETURN GAME STATUS
    1 FOR GAME IS OVER WITH RESULT
    -1 FOR GAME IS IN PROGRESS
    O GAME IS OVER AND NO RESULT
**********************************************/

int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])

        return 1;
    else if (square[4] == square[5] && square[5] == square[6])

        return 1;
    else if (square[7] == square[8] && square[8] == square[9])

        return 1;
    else if (square[1] == square[4] && square[4] == square[7])

        return 1;
    else if (square[2] == square[5] && square[5] == square[8])

        return 1;
    else if (square[3] == square[6] && square[6] == square[9])

        return 1;
    else if (square[1] == square[5] && square[5] == square[9])

        return 1;
    else if (square[3] == square[5] && square[5] == square[7])

        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' 
                    && square[4] != '4' && square[5] != '5' && square[6] != '6' 
                  && square[7] != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return -1;
}


/*******************************************************************
     FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
********************************************************************/


void board()
{
    system("cls");
    cout << "\n\n\tTic Tac Toe\n\n";

    cout << "Player 1 (X)  -  Computer (O)" << endl << endl;
    cout << endl;

    cout << "     |     |     " << endl;
    cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

    cout << "     |     |     " << endl << endl;
}

char chosenSquare(char mark, int choice, int player)
{
    if (choice == 1 && square[1] == '1')
        return square[1] = mark;

    else if (choice == 2 && square[2] == '2')
        return square[2] = mark;

    else if (choice == 3 && square[3] == '3')
        return square[3] = mark;

    else if (choice == 4 && square[4] == '4')
        return square[4] = mark;

    else if (choice == 5 && square[5] == '5')
        return square[5] = mark;

    else if (choice == 6 && square[6] == '6')
        return square[6] = mark;

    else if (choice == 7 && square[7] == '7')
        return square[7] = mark;

    else if (choice == 8 && square[8] == '8')
        return square[8] = mark;

    else if (choice == 9 && square[9] == '9')
        return square[9] = mark;

    else
    {
        cout<<"Invalid move ";

        player--;
        cin.ignore();
        cin.get();
        //return 0;
    }
}

/*
######################################################
##                COMPUTER FUNCTIONS                ##
######################################################
*/
char comPlay1(std::list<int> numberList)

{

    int comNum;
    comNum = numberList.front();
    
    return comNum;
}

std::list<int> updateList(std::list<int> numberList, int number)
{
    numberList.remove(number);
    
    return numberList;
            
}

/*******************************************************************
                END OF PROJECT
********************************************************************/