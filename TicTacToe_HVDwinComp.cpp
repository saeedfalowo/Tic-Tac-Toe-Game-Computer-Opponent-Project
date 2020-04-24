#include <iostream>
#include <list>
using namespace std;

char square[10] = {'o','1','2','3','4','5','6','7','8','9'};


int checkwin();
void board();
char chosenSquare(char mark, int choice, int player);
bool ismember_list(std::list<int> numberList, int num);
char comPlay1(std::list<int> numberList);
char complay_Next(std::list<int> numberList);
char complay_Horz_Vert_Diag_Block(std::list<int> human_play_nums, std::list<int> com_play_nums, int ComHorzVertDiagArr[8][3], std::list<int> numberList);
char complay_LastElemInRoute(std::list<int> play_nums, std::list<int> playable_routes, int ComHorzVertDiagArr[8][3]);
std::list<int> updateList(std::list<int> numberList, int number);
// std::list<int> updateList(std::list<int> numberList, int num);
//char winRoute();

int main()
{
    // construct the number list
    // int numberList[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int ComHorzVertDiagArr[8][3] = {{1,2,3},{4,5,6},{7,8,9},{1,4,7},{2,5,8},{3,6,9},{1,5,9},{3,5,7}};

    // std::list<int> numberList(numberList, numberList + sizeof(numberList)/sizeof(int));
    std::list<int> numberList({1, 2, 3, 4, 5, 6, 7, 8, 9});
    std::list<int> compNumplay;
    std::list<int> human_play_nums, com_play_nums;

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
            if (ismember_list(numberList, choice) == false)
                {
                    do
                    {
                        // cout << "\r" << " \n Invalid entry! \n Enter a valid number: ";
                        cout << "Invalid entry! Enter a valid number: ";
                        cin >> choice;
                        // cout << endl;
                    } while (ismember_list(numberList, choice) == false);
                }
            human_play_nums.push_back(choice);
            numberList = updateList(numberList, choice);
        }
        else
        {
            
            // choice = comPlay1(numberList);
            choice = complay_Horz_Vert_Diag_Block(human_play_nums, com_play_nums, ComHorzVertDiagArr, numberList);
            com_play_nums.push_back(choice);
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

/*
##################################################################################################
##                  COMPUTER HORIZONTAL VERITICAL DIAGONAL AND BLOCKER PLAY                     ##
##################################################################################################
*/
char complay_Horz_Vert_Diag_Block(std::list<int> human_play_nums, std::list<int> com_play_nums, int ComHorzVertDiagArr[8][3], std::list<int> numberList)
{
    /*
    Here, the computer will look at the human_play_nums, com_play_nums, and ComHorzVertDiagArr

    It will look at each win route in ComHorzVertDiagArr, to find if any of the numbers exist within human_play_nums list
    If at least one number in all the routes within ComHorzVertDiagArr exist within human_play_nums,
    i.e. all the winning routes have been blocked,
    It will just call complay_Next to play the round instead

    As for the blocker function, the algorithm will look at all possible winning route the human player can take from his
    initial play.
    Then it will look at the rest of the numbers within those routes that have not been played yet
    Then it will look for those numbers within the computer's winning routes
    The computer will then play from those winning routes in other to block at least of of the human player's winning route!
    */

    // Declare and initialize the variables that will be used in this function
    std::list<int> playable_routes_comp, playable_routes_human, playable_nums;
    int cnt=0, rec_cnt=0, is_not_com=0, is_not_human=0, is_same=0, play_indx, prev_path_indx, path[3], path_is_updated=0, ret;
    // counter integers
    int i, j, k;

    // look into each of the 8 winning routes
    for (i=0; i<8; i++)
    {
        // look into each element in the current win route
        for (j=0; j<3; j++)
        {
            // find the element that has already been played by the human, i.e. exists within human_play_nums list
            // and then raise the is_not_com flag when found
            if (ismember_list(human_play_nums, ComHorzVertDiagArr[i][j])==true)
            {
                is_not_com = 1;
                // find out if the current route has computer played elements as well
                for (k=0; k<3; k++)
                    if (ismember_list(com_play_nums, ComHorzVertDiagArr[i][k])==true)
                    {
                        is_not_human = 1;
                        break;
                    }
                break;
            }
            // find the element that has already been played by the computer, i.e. exists within com_play_nums list
            // and then raise the is_not_human flag when found
            if (ismember_list(com_play_nums, ComHorzVertDiagArr[i][j])==true)
            {
                is_not_human = 1;
                // find out if the current route has human played elements as well
                for (k=0; k<3; k++)
                    if (ismember_list(human_play_nums, ComHorzVertDiagArr[i][k])==true)
                    {
                        is_not_com = 1;
                        break;
                    }
                break;
            }
        }

        // If the human player has not played any of the numbers in the current win route,
        // add this win route index to playable_routes_comp
        if (is_not_com==0)
        { 
            if (playable_routes_comp.empty()==true)
                playable_routes_comp.assign(1,i);
            else
                playable_routes_comp.push_back(i);
        }
        else if (is_not_human==0)// collect the playable routes for the human as well.
        { 
            if (playable_routes_human.empty()==true)
                playable_routes_human.assign(1,i);
            else
                playable_routes_human.push_back(i);
        }

        is_not_com = 0; is_not_human = 0;
    }

    // print out the playable routes for both the human player and the computer
    // cout << "The human playable routes are: \n";
    // print_list(playable_routes_human);
    // cout << "The computer playable routes are: \n";
    // print_list(playable_routes_comp);


    // if playable_routes_comp is empty, i.e. there are no winning routes left, call complay_Next
    if (playable_routes_comp.empty()==true)
        return complay_Next(numberList);

    // if this is the computer's first turn
    else if (com_play_nums.empty()==true)
    {
        // if  the human has not played 5
        auto human_first_play = std::next(human_play_nums.begin(), 0);
        if (human_play_nums.size()==1 && *human_first_play!=5)
            return 5;
        // look within the playable_routes_comp and the playable_routes_human lists for shared elements
        // first, create individual iterator for both lists
        for (i=0; i<playable_routes_comp.size(); i++)
        {
            auto playable_route_comp = std::next(playable_routes_comp.begin(), i);

            for (j=0; j<playable_routes_human.size(); j++)
            {
                auto playable_route_human = std::next(playable_routes_human.begin(), j);
                // if both playable routes share an element
                if (ComHorzVertDiagArr[*playable_route_comp][i] == ComHorzVertDiagArr[*playable_route_human][j])
                    return ComHorzVertDiagArr[*playable_route_comp][i];
            }
        }
        // play the first element from the first playable route
        play_indx = playable_routes_comp.front();
        return ComHorzVertDiagArr[play_indx][0];
    }

    else // play numbers from the first playable route
    {
        // check if the computer has already played two elements in a winning route
        // complay_LastElemInRoute(play_nums, playable_routes, ComHorzVertDiagArr);
        ret = complay_LastElemInRoute(com_play_nums, playable_routes_comp, ComHorzVertDiagArr);
        if (ret!=0)
            return ret;

        // check if the human has already played two elements in a winning route
        // complay_LastElemInRoute(play_nums, playable_routes, ComHorzVertDiagArr);
        ret = complay_LastElemInRoute(human_play_nums, playable_routes_human, ComHorzVertDiagArr);
        if (ret!=0)
            return ret;

        // check which of the routes in the playable route has the computer already played for
        if (com_play_nums.empty()==false) // if the computer has indeed had a turn prior to its current turn
        {
            cnt = 0; // reset the counter

            // look through each of the playable winning routes to find the routes with one or more
            // elements that has already been played by the computer
            for (i=0; i<playable_routes_comp.size(); i++)
            {
                // extract the winning route index from playable routes
                auto playable_route_comp = std::next(playable_routes_comp.begin(), i); // shift the iterator (playable_route) from playable_routes_comp.begin() by i
                // look through each element in the current playable route
                for (j=0; j<3; j++)
                {
                    // if the current element has already been played by the computer, increase the counter value by 1
                    if (ismember_list(com_play_nums, ComHorzVertDiagArr[*playable_route_comp][j])==true)
                    {
                        // cout << "Computer has played: " << ComHorzVertDiagArr[*playable_route_comp][j] << endl;
                        cnt++;
                    }
                }

                // if max number of instances found in the current route is greater than 1, then just one more will win the game
                if (cnt>1) 
                {
                    // update the desired path array with the winning path with the most
                    // number computer played elements
                    for (j=0; j<3; j++)
                    {
                        // extract the winning route index from playable routes
                        auto it = std::next(playable_routes_comp.begin(), i); // shift the iterator (it) from playable_routes_comp.begin() by i
                        // store the playable winning route element in one of the three array slots in path
                        path[j] = ComHorzVertDiagArr[*it][j];
                    }

                    // check which numbers have already been played by the computer
                    for (k=0; k<3; k++)
                    {
                        if (ismember_list(com_play_nums, path[k])==false)
                            return path[k];
                    }
                }
                else if (cnt==1)
                {
                    // look within the playable_routes_comp and the playable_routes_human lists for shared elements
                    // first, create individual iterator for both lists
                    auto playable_route_comp = std::next(playable_routes_comp.begin(), i);

                    for (j=0; j<playable_routes_human.size(); j++)
                    {
                        auto playable_route_human = std::next(playable_routes_human.begin(), j);
                        // if both playable routes share an element
                        if (ComHorzVertDiagArr[*playable_route_comp][j] == ComHorzVertDiagArr[*playable_route_human][j])
                            is_same = 1; // raise the flag to indicate that a common element has been found in both computer and human playable route
                    }

                    if (is_same==1)
                    {
                        for (j=0; j<3; j++)
                            path[j] = ComHorzVertDiagArr[*playable_route_comp][j];

                        path_is_updated = 1; // raise the flag to indicate that path has been updated/filled
                    }

                    rec_cnt=cnt; // update rec_cnt
                    
                }
                cnt = 0; // reset the counter
            }

            // If path was never filled or updated
            if (path_is_updated==0)
            {
                // choose the very first playable route index
                play_indx = playable_routes_comp.front();
                // update path with the contents of the first playable route
                for (i=0; i<3; i++)
                    path[i] = ComHorzVertDiagArr[play_indx][i];
            }
        }

        // if the computer has not had a turn yet
        else 
        {
            // else, just play the very first path, playable_routes_comp.front();
            play_indx = playable_routes_comp.front();
            // update path with the contents of the first playable route
            for (i=0; i<3; i++)
                path[i] = ComHorzVertDiagArr[play_indx][i];

        }
        
        // check which numbers have already been played by the computer
        for (i=0; i<3; i++)
        {
            if (ismember_list(com_play_nums, path[i])==false)
                return path[i];
        }
    }
}

char complay_Next(std::list<int> numberList)
{
    int comNum = numberList.front();
    // cout << "The computer has played: " << comNum << endl;
    return comNum;
}

char complay_LastElemInRoute(std::list<int> play_nums, std::list<int> playable_routes, int ComHorzVertDiagArr[8][3])
{
    int cnt=0, i, j;
    // check if two elements have already been played in a winning route
    for (i=0; i<playable_routes.size(); i++)
    {
        cnt=0;
        // extract the winning route index from playable routes
        auto playable_route = std::next(playable_routes.begin(), i); // shift the iterator (playable_route) from playable_routes.begin() by i
        // look through each element in the current playable route
        for (j=0; j<3; j++)
        {
            // if the current element has already been played by the computer, increase the counter value by 1
            if (ismember_list(play_nums, ComHorzVertDiagArr[*playable_route][j])==true)
            {
                // cout << "Human has played: " << ComHorzVertDiagArr[*playable_route][j] << endl;
                cnt++;
            }
        }
        // if max number of instances found in the current route is greater than 1, then just one more will win the game
        if (cnt>1) 
        {
            // update the desired path array with the winning path with the most
            // number computer played elements
            for (j=0; j<3; j++)
            {
                if (ismember_list(play_nums, ComHorzVertDiagArr[*playable_route][j])==false)
                {
                    return ComHorzVertDiagArr[*playable_route][j];
                }
            }
        }
        
    }
    return 0;
}

bool ismember_list(std::list<int> numberList, int num)
{
    for (int i = 1; i <= numberList.size(); i = i+1)
    {
        auto it = std::next(numberList.begin(), i-1);
        //std::cout << "Element: " << i << " = " << *it << "\n" << endl;

        if (num == *it)
            return true;
    }
    return false;
}

// std::list<int> updateList(std::list<int> numberList, int num)
// {
//     numberList.remove(num);
//     return numberList;
// }

/*******************************************************************
                END OF PROJECT
********************************************************************/