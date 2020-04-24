#include <iostream>
#include <list>
#include <iterator>
#include <vector>
using namespace std;

// Declare our functions
char menu();
// int arr_len(int NumList[], int num, int len);
void print_list(std::list<int> NumList);
int update_list(std::list<int> NumList, int num, int len);
std::list<int> updateList(std::list<int> NumList, int num);
bool ismember_list(std::list<int> NumList, int num);
char complay_Next(std::list<int> NumList);
char complay_Horz(std::list<int> human_play_nums, std::list<int> com_play_nums, int ComHorzArr[3][3], std::list<int> NumList);
char complay_Horz_Vert(std::list<int> human_play_nums, std::list<int> com_play_nums, int ComHorzVertArr[6][3], std::list<int> NumList);
char complay_Horz_Vert_Diag(std::list<int> human_play_nums, std::list<int> com_play_nums, int ComHorzVertDiagArr[8][3], std::list<int> NumList);
char complay_Horz_Vert_Diag_Block(std::list<int> human_play_nums, std::list<int> com_play_nums, int ComHorzVertDiagArr[8][3], std::list<int> NumList);
void print_comwinlist(int ComHorzArr[3][3]);
bool ismember_arr(int arr[3], int num);
char complay_LastElemInRoute(std::list<int> play_nums, std::list<int> playable_routes, int ComHorzVertDiagArr[8][3]);

char menu()
{
	char user_in;
	cout << "_-_-_- MENU -_-_-_\n";
	cout << "1 Play a number! \n";
	cout << "2 Print played Number! \n";
	cout << "3 Print Number List! \n";
	cout << "4 Exit! \n\n";
	cout << "Choose from the menu: ";
	cin >> user_in;
	return user_in;
}

int main()
{
	// construct the number list
	std::list<int> NumList({1, 2, 3, 4, 5, 6, 7, 8, 9});

	int ComHorzArr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	int ComHorzVertArr[6][3] = {{1,2,3},{4,5,6},{7,8,9},{1,4,7},{2,5,8},{3,6,9}};
	int ComHorzVertDiagArr[8][3] = {{1,2,3},{4,5,6},{7,8,9},{1,4,7},{2,5,8},{3,6,9},{1,5,9},{3,5,7}};
	
	std::list<int> human_play_nums, com_play_nums;
	
	int num, len;
	char user_in;
	do
	{
		user_in = menu();

		switch(user_in)
		{
			case '1': //cout << "\n You have chosen 'Play a number' \n \n";
				cout << "\n Enter a number: ";
				cin >> num;
				if (ismember_list(NumList, num) == false)
				{
					do
					{
						cout << "\n Invalid entry! \n Enter a number: ";
						cin >> num;
					} while (ismember_list(NumList, num) == false);
				}
				cout << " Human's played numbers: \n";
				human_play_nums.push_back(num);
				print_list(human_play_nums);
				NumList = updateList(NumList, num);

				// The computer will now play its number
				if (NumList.empty() == true)
					cout << " There are no more numbers for the computer to play!" << endl;
				else
				{
					// num = complay_Next(NumList);
					// num = complay_Horz(human_play_nums, com_play_nums, ComHorzArr, NumList);
					// num = complay_Horz_Vert(human_play_nums, com_play_nums, ComHorzVertArr, NumList);
					// num = complay_Horz_Vert_Diag(human_play_nums, com_play_nums, ComHorzVertDiagArr, NumList);
					num = complay_Horz_Vert_Diag_Block(human_play_nums, com_play_nums, ComHorzVertDiagArr, NumList);
					cout << " Computer's played numbers: \n";
					com_play_nums.push_back(num);
					print_list(com_play_nums);
					NumList = updateList(NumList, num);
				}

				break;

			case '2': cout << "\n You have chosen 'Print played number' \n \n";
				print_comwinlist(ComHorzArr);
				break;

			case '3': //cout << "\n You have chosen 'Print Number List' \n \n";
				cout << "The contents of NumList are: ";
				print_list(NumList);
				break;
		}
	}while (user_in!='4'); // Exit at user input == 4
}


/*
##################################################
##					FUNCTIONS 					##
##################################################
*/

void print_list(std::list<int> NumList)
{

	// std::cout << "The contents of NumList are: ";
	for (std::list<int>::iterator it = NumList.begin();
		it != NumList.end();
		it++)
	{
		std::cout << *it << ' ';
		std::cout << ' '; //\n';
		int list_size = NumList.size();
	}

	cout << endl << endl;

	//cout << "And the list size is = " << list_size << "\n";
}

std::list<int> updateList(std::list<int> NumList, int num)
{
	NumList.remove(num);
	return NumList;
}

bool ismember_list(std::list<int> NumList, int num)
{
	for (int i = 1; i <= NumList.size(); i = i+1)
	{
		auto it = std::next(NumList.begin(), i-1);
		//std::cout << "Element: " << i << " = " << *it << "\n" << endl;

		if (num == *it)
			return true;
	}
	return false;
}

bool ismember_arr(int arr[3], int num)
{
	for (int i=0; i<3; i=i++)
	{
		if (num == arr[i])
			return true;
	}
	return false;
}

char complay_Next(std::list<int> NumList)
{
	int comNum = NumList.front();
	cout << "The computer has played: " << comNum << endl;
    return comNum;
}


/*
##################################################################
##					COMPUTER HORIZONTAL PLAY 					##
##################################################################
*/
char complay_Horz(std::list<int> human_play_nums, std::list<int> com_play_nums, int ComHorzArr[3][3], std::list<int> NumList)
{
	/*
	Here, the computer will look at the human_play_nums, com_play_nums, and ComHorzArr

	It will look at each row of ComHorzArr, to find if any of the numbers exist within human_play_nums
	If at least one number in all the rows within ComHorzArr exist within human_play_nums,
	It will just call complay_Next to play the round instead
	*/

	// std::list<int> playable_routes;
	std::list<int> playable_routes, playable_nums;
	int cnt=0, is_found=0, play_indx;

	// look into eac row
	for (int i=0; i<3; i++)
	{
		// look into each element in the row
		for (int j=0; j<3; j++)
		{
			// find the element that has already been played by the human, i.e. exists within human_play_nums list
			if (ismember_list(human_play_nums, ComHorzArr[i][j])==false)
				is_found = 0;
			else
			{
				// raise flag when is_found and break out of the element for loop
				is_found = 1;
				break;
			}
		}
		if (is_found==0)
		{ 
			if (playable_routes.empty()==true)
			{
				// cout << "playable_routes is empty!\n";
				playable_routes.assign(1,i);
			}
			else
			{
				// cout << "playable_routes is not empty!\n";
				playable_routes.push_back(i);
			}
		}
	}
	// if playable_routes is empty, call complay_Next
	if (playable_routes.empty()==true)
		return complay_Next(NumList);

	// if this is the computer's first turn
	else if (com_play_nums.empty()==true)
	{
		// play from the first playable row
		play_indx = playable_routes.front();
		return ComHorzArr[play_indx][0];
	}

	else // play numbers from the first playable row
	{
		play_indx = playable_routes.front();
		// check which numbers have already been played by the computer
		for (int i=0; i<3; i++)
		{
			if (ismember_list(com_play_nums, ComHorzArr[play_indx][i])==false)
			{
				if (playable_nums.empty()==true)
					playable_nums.assign(1,ComHorzArr[play_indx][i]);
				else
					playable_nums.push_back(ComHorzArr[play_indx][i]);
			}
		}
		return playable_nums.front();
	}
}
/*
##############################################################################
##					COMPUTER HORIZONTAL AND VERITICAL PLAY 					##
##############################################################################
*/
char complay_Horz_Vert(std::list<int> human_play_nums, std::list<int> com_play_nums, int ComHorzVertArr[6][3], std::list<int> NumList)
{
	/*
	Here, the computer will look at the human_play_nums, com_play_nums, and ComHorzVertArr

	It will look at each row of ComHorzVertArr, to find if any of the numbers exist within human_play_nums
	If at least one number in all the rows within ComHorzVertArr exist within human_play_nums,
	It will just call complay_Next to play the round instead
	*/

	// std::list<int> playable_routes;
	std::list<int> playable_routes, playable_nums;
	int cnt=0, rec_cnt=0, is_found=0, play_indx, prev_path_indx, path[3], path_is_updated=0;

	// look into each row
	for (int i=0; i<6; i++)
	{
		// look into each element in the row
		for (int j=0; j<3; j++)
		{
			// find the element that has already been played by the human, i.e. exists within human_play_nums list
			if (ismember_list(human_play_nums, ComHorzVertArr[i][j])==false)
				is_found = 0;
			else
			{
				// raise flag when is_found and break out of the element for loop
				is_found = 1;
				break;
			}
		}
		if (is_found==0)
		{ 
			if (playable_routes.empty()==true)
			{
				// cout << "playable_routes is empty!\n";
				playable_routes.assign(1,i);
			}
			else
			{
				// cout << "playable_routes is not empty!\n";
				playable_routes.push_back(i);
			}
		}
	}

	// print_list(playable_routes);

	// if playable_routes is empty, call complay_Next
	if (playable_routes.empty()==true)
		return complay_Next(NumList);

	// if this is the computer's first turn
	else if (com_play_nums.empty()==true)
	{
		// play from the first playable row
		play_indx = playable_routes.front();
		return ComHorzVertArr[play_indx][0];
	}

	else // play numbers from the first playable row
	{
		// check which paths has the computer already played for
		if (com_play_nums.empty()==false)
		{
			cnt = 0;
			cout << "playable rows size: " << playable_routes.size() << endl;
			for (int i=0; i<playable_routes.size(); i++)
			{
				for (int j=0; j<3; j++)
				{
					if (ismember_list(com_play_nums, ComHorzVertArr[i][j])==true)
					{
						cout << "Computer has played: " << ComHorzVertArr[i][j] << endl;
						cnt++;
						cout << "cnt == " << cnt << endl;
					}
				}
				// if max number of instances is_found in a route is greater than the previous max number of instances is_found in a route
				if (cnt>rec_cnt) 
				{
					for (int j=0; j<3; j++)
					{
						auto it = std::next(playable_routes.begin(), i);
						// Advance the iterator by i positions,
						// std::advance(it, i);
						cout << "I index: " << i << endl;
						std::cout << "playable_routes index: " << *it << endl;
						// path[j] = ComHorzVertArr[i][j];
						path[j] = ComHorzVertArr[*it][j];
					}

					prev_path_indx = i;
					rec_cnt=cnt;
					path_is_updated = 1;
				}
				cnt = 0;
			}
			if (path_is_updated==0)
			{
				play_indx = playable_routes.front();
				for (int i=0; i<3; i++)
					path[i] = ComHorzVertArr[play_indx][i];
				cout << "Entered path_is_updated statement!\n";
			}
			// then first try to complete the path with the two played elements first
			// Then play paths with one played element
			// since i starts from 0, the shift should be index + 1, i.e. prev_path_indx+1
			// It returns a new iterator pointing to n position after the
			auto it = std::next(playable_routes.begin(), prev_path_indx);//+1);
			cout << "The playable_routes are: \n";
			print_list(playable_routes);
			cout << "The chosen playable path is: \n";
			for (int i=0; i<3; i++)
				cout << path[i] << " ";

			// cout << "prev_path_indx: " << prev_path_indx << endl;
			// cout << "The playable_routes index: " << *it << endl;
			// play_indx = *it;
			// play_indx = prev_path_indx;
		}
		else
		{
			// else, just play the very first path, playable_routes.front();
			play_indx = playable_routes.front();
			for (int i=0; i<3; i++)
				path[i] = ComHorzVertArr[play_indx][i];

		}
		
		// check which numbers have already been played by the computer
		for (int i=0; i<3; i++)
		{
			if (ismember_list(com_play_nums, path[i])==false)
			{
				return path[i];
			// 	if (playable_nums.empty()==true)
			// 		playable_nums.assign(1,ComHorzVertArr[play_indx][i]);
			// 	else
			// 		playable_nums.push_back(ComHorzVertArr[play_indx][i]);
			}
		}
		// return playable_nums.front();
	}
}
/*
##########################################################################################
##					COMPUTER HORIZONTAL VERITICAL AND DIAGONAL PLAY 					##
##########################################################################################
*/
char complay_Horz_Vert_Diag(std::list<int> human_play_nums, std::list<int> com_play_nums, int ComHorzVertDiagArr[8][3], std::list<int> NumList)
{
	/*
	Here, the computer will look at the human_play_nums, com_play_nums, and ComHorzVertDiagArr

	It will look at each win route in ComHorzVertDiagArr, to find if any of the numbers exist within human_play_nums list
	If at least one number in all the routes within ComHorzVertDiagArr exist within human_play_nums,
	i.e. all the winning routes have been blocked,
	It will just call complay_Next to play the round instead
	*/

	// Declare and initialize the variables that will be used in this function
	std::list<int> playable_routes, playable_nums;
	int cnt=0, rec_cnt=0, is_found=0, play_indx, prev_path_indx, path[3], path_is_updated=0;
	// counter integers
	int i, j, k;

	// look into each of the 8 winning routes
	for (i=0; i<8; i++)
	{
		// look into each element in the current win route
		for (j=0; j<3; j++)
		{
			// find the element that has already been played by the human, i.e. exists within human_play_nums list
			// and then raise the is_found flag when found
			if (ismember_list(human_play_nums, ComHorzVertDiagArr[i][j])==false)
				is_found = 0;
			else
			{
				// raise flag when element is found within human_play_nums list
				// and then break out of the element for-loop
				is_found = 1;
				break;
			}
		}

		// If the human player has not played any of the numbers in the current win route,
		// add this win route index to playable_routes
		if (is_found==0)
		{ 
			if (playable_routes.empty()==true)
				playable_routes.assign(1,i);
			else
				playable_routes.push_back(i);
		}
	}

	// if playable_routes is empty, i.e. there are no winning routes left, call complay_Next
	if (playable_routes.empty()==true)
		return complay_Next(NumList);

	// if this is the computer's first turn
	else if (com_play_nums.empty()==true)
	{
		// play the first element from the first playable route
		play_indx = playable_routes.front();
		return ComHorzVertDiagArr[play_indx][0];
	}

	else // play numbers from the first playable route
	{
		// check which of the routes in the playable route has the computer already played for
		if (com_play_nums.empty()==false) // if the computer has indeed had a turn prior to its current turn
		{
			cnt = 0; // reset the counter

			// look through each of the playable winning routes to find the routes with one or more
			// elements that has already been played by the computer
			for (i=0; i<playable_routes.size(); i++)
			{
				// extract the winning route index from playable routes
				auto playable_route_comp = std::next(playable_routes.begin(), i); // shift the iterator (playable_route) from playable_routes.begin() by i
				// look through each element in the current playable route
				for (j=0; j<3; j++)
				{
					// if the current element has already been played by the computer, increase the counter value by 1
					if (ismember_list(com_play_nums, ComHorzVertDiagArr[*playable_route_comp][j])==true)
					{
						cout << "Computer has played: " << ComHorzVertDiagArr[*playable_route_comp][j] << endl;
						cnt++;
					}
				}

				// if max number of instances found in the current route is greater than
				// the previous max number of instances found in previous routes
				if (cnt>rec_cnt) 
				{
					// update the desired path array with the winning path with the most
					// number computer played elements
					for (j=0; j<3; j++)
					{
						// extract the winning route index from playable routes
						auto it = std::next(playable_routes.begin(), i); // shift the iterator (it) from playable_routes.begin() by i
						cout << "I index: " << i << endl;
						std::cout << "playable_routes index: " << *it << endl;
						// store the playable winning route element in one of the three array slots in path
						path[j] = ComHorzVertDiagArr[*it][j];
					}

					rec_cnt=cnt; // update rec_cnt
					path_is_updated = 1; // raise the flag to indicate that path has been updated/filled
				}
				cnt = 0; // reset the counter
			}

			// If path was never filled or updated
			if (path_is_updated==0)
			{
				// choose the very first playable route index
				play_indx = playable_routes.front();
				// update path with the contents of the first playable route
				for (i=0; i<3; i++)
					path[i] = ComHorzVertDiagArr[play_indx][i];

				// print to show that the progam has executed this if statement
				cout << "Entered path_is_updated if statement!\n";
			}

			// print to monitor program execution
			cout << "The playable_routes are: \n";
			print_list(playable_routes);
			cout << "The chosen playable path is: \n";
			for (i=0; i<3; i++)
				cout << path[i] << " ";
		}

		// if the computer has not had a turn yet
		else 
		{
			// else, just play the very first path, playable_routes.front();
			play_indx = playable_routes.front();
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
/*
##################################################################################################
##					COMPUTER HORIZONTAL VERITICAL DIAGONAL AND BLOCKER PLAY 					##
##################################################################################################
*/
char complay_Horz_Vert_Diag_Block(std::list<int> human_play_nums, std::list<int> com_play_nums, int ComHorzVertDiagArr[8][3], std::list<int> NumList)
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
	cout << "The human playable routes are: \n";
	print_list(playable_routes_human);
	cout << "The computer playable routes are: \n";
	print_list(playable_routes_comp);


	// if playable_routes_comp is empty, i.e. there are no winning routes left, call complay_Next
	if (playable_routes_comp.empty()==true)
		return complay_Next(NumList);

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

void print_comwinlist(int ComHorzVertArr[3][3])
{
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			cout << ComHorzVertArr[i][j] << " ";
			// if (ismember_list(std::list<int> NumList, ComHorzVertArr[i][j]))
		}
		cout << endl;
	}
	cout << endl;
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