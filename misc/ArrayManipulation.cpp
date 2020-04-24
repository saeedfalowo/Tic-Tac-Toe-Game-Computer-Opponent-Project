#include <iostream>
#include <array>
#include <list>
#include <iterator>
using namespace std;

// Declare our functions
char menu();
// int arr_len(int num_array[], int num, int len);
void print_array(int num_array[], int len);
int update_array(int num_array[], int num, int len);

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
	// define an array called num_list
	int num_array[20];
	num_array = {0,1,2,3,4,5,6,7,8,9};
	int num;
	int len_num_array;

	char user_in;
	do
	{
		user_in = menu();

		switch(user_in)
		{
			case '1': //cout << "\n You have chosen 'Play a number' \n \n";
				cout << "\n Enter a number: ";
				cin >> num;
				for (int i=0, int j=0; i<len; i++)
					if (num_array != num)

				// len_num_array = sizeof(num_array)/sizeof(num_array[0]);
				// update_array(num_array, num, len_num_array);
				break;

			case '2': cout << "\n You have chosen 'Print played number' \n \n";
				break;

			case '3': //cout << "\n You have chosen 'Print Number List' \n \n";
				len_num_array = sizeof(num_array)/sizeof(num_array[0]);
				print_array(num_array, len_num_array);
				// cout << "The length of the array: " << len_num_array << endl;
				// for (int i=0; i<len_num_array; i++)
				// 	cout << num_array[i] << " ";
				// cout << endl;
				break;
		}
	}while (user_in!='4'); // Exit at user input == 4
}

void print_array(int num_array[], int len)
{
	// int len_num_array = sizeof(num_array)/sizeof(num_array[0]);
	cout << "The length of the array: " << len << endl;

	for (int i=0; i<len; i++)
	{
		cout << num_array[i] << " ";
		// cout << i << " ";
	}
	cout << endl;
}

// int update_array(int num_array[], int num, int len)
// {
// 	int up_num_array[]={};
// 	int cnt = 1;

// 	for (int i=0; i<len; i++)
// 	{
// 		int num_i = num_array[i];
// 		if (num_i != num)
// 		{
// 			int up_num_array[cnt] = num_i;
// 			cnt++;
// 		}
// 	}
// 	return up_num_array;
// }