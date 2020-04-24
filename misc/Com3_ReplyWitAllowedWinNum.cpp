#include <iostream>
#include <list>
#include <iterator>
using namespace std;

// Declare a struct named node
// this will refer to the each element in the list

struct node
{
  int number;
  // declare a pointer to the next node in the list
  node *next;
};

/*
#####################################
## DATA INPUT AND ACQUISITION FCNs ##
#####################################
*/

// Declare your function prototypes
bool isEmpty(node *head); // head == 1st elem in the list
char menu();
void showList(node *current);
void insert(node *&head, node *&last, int number);
void insertfirst(node *&head, node *&last, int number);
void removeElem(node *&head, node *&last);

// Construct your functions
bool isEmpty(node *head)
{
  if (head == NULL)
    return true;
  else
    return false;
}

char menu()
{
  char choice;
  cout << "MENU \n";
  cout << "1. Add an elem. \n";
  cout << "2. Print list. \n";
  cout << "3. Remove elem from list. \n";
  cout << "4. Delete list. \n";
  cout << "5. EXIT! \n";
  cin >> choice;
  return choice;
}

void showList(node *current)
{
  // Check if list is empty
  if (isEmpty(current))
    cout << "The list is empty. \n";
  else
  {
    cout << "The list contains: \n";
    while (current !=NULL)
    {
      cout << current -> number << endl;
      current = current -> next;
    }
  }
}

void insertfirst(node *&head, node *&last, int number)
{
  // First, create a temporary node
  node *temp = new node;
  // dereference the number part
  // i.e. assigning the data field of the elem a value
  // assign the input argument, number, to the number part of our temp node
  temp -> number = number;
  // do a similar thing to the next pointer
  // assign the next part of the temp node to NULL
  // Because the input argument, number is the only elem in the node
  temp -> next = NULL;
  // insert temp as the first value in the list
  // set the last value as temp as well
  last = temp;
}

void insert(node *&head, node *&last, int number)
{
  // Check if list is empty
  if (isEmpty(head))
    insertfirst(head, last, number);
  else
  {
    node *temp = new node;
    temp -> number = number;
    temp -> next = NULL;
    // Set the previous last value's "next" to the temp node
    last -> next = temp;
    // this step links all the elements in the list
    // update last to temp as well
    last = temp;
  }
}

void removeElem(node *&head, node *&last)
{
  // Check if the list is empty
  if (isEmpty(head))
    cout << "The list is empty, no elements to remove. \n";
    // if there is only one element in the list
  else if (head == last)
  {
    delete head;
    head = NULL;
    last = NULL;
  }
  // If there is more than one element in the list
  else
  {
    // Create a temporary node and assign head to it
    node *temp = head;
    // Then move head onto the next element in the list
    head = head -> next;
    delete temp;
  }
}

/*
##################################
##        COM INPUT FCNs        ##
##################################
*/

// The goal is to make the COM iterate through the list
char com(int number);
void printIntList(std::list<int> numberList);
bool ismember(std::list<int> numberList, int number);
std::list<int> updateList(std::list<int> numberList, int number);

char com(std::list<int> numberList, int number)
{
  int comNum;
  if (numberList.front() == NULL)
    cout << "Com ran out of numbers to play." << endl;
  else
  {
    comNum = numberList.front();
    cout << "The computer has played " << comNum << " \n";
    return comNum;
  }
}

void printIntList(std::list<int> numberList)
{
  std::cout << "The contents of numberList are: ";
  for (std::list<int>::iterator it = numberList.begin();
    it != numberList.end();
    it++)
  {
    std::cout << *it << ' ';
    std::cout << '\n';
    int list_size = numberList.size();
  }
  //cout << "And the list size is = " << list_size << "\n";
}

bool ismember(std::list<int> numberList, int number)
{
  /*
  // Create iterator pointing to first element
  std::list<int>::iterator it = numberList.begin();
  for (int i = 1; i <= numberList.size(); i = i+1)
  {
    std::cout << "Element: " << i << " = " << *it << "\n" << endl;
    // Advance the iterator by 1
    std::advance(it, 1);
  }
  */

  // OR

  for (int i = 1; i <= numberList.size(); i = i+1)
  {
    auto it = std::next(numberList.begin(), i-1);
    // numberList.front() points to the first element in the list
    //std::cout << "Element: " << i << " = " << *it << "\n" << endl;

    if (number == *it)
    {
      return true;
    }
  }
  return false;
}

std::list<int> updateList(std::list<int> numberList, int number)
{
  numberList.remove(number);
  //cout << "The number " << number << " has been removed from list." << endl;
  //cout << "Updated list = " << endl;
  //printIntList(numberList);
  return numberList;

}

/*

################################
##          MAIN CODE         ##
################################

*/



int main ()
{
  // construct the number list
  int numList[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::list<int> numberList(numList, numList + sizeof(numList)/sizeof(int));
  // declare and initialize your pointers
  node *head = NULL;
  node *last = NULL;
  char choice;
  int number, comNum;

  do
  {
    choice = menu();
    switch(choice)
    {
      case '1' : do
        {
          if (numberList.empty() == true)
          {
            cout << "There are no more numbers to play for MENU choice 1." << endl;
            break;
          }

          cout << "Please enter a number: ";
          cin >> number;
        }

        while(ismember(numberList, number) == false);
          insert(head, last, number);

        if (ismember(numberList, number) == true)
        {
          cout << "The input: " << number << " exists in the list!" << endl;
          numberList = updateList(numberList, number);
        }
        else
        {
          cout << "The input: " << number << " does not exist in the list!" << endl;
        }
        //cout << "1st elem in numList = " << numberList.front() << endl;
        if (numberList.empty() == false)
        {
          comNum = com(numberList, number);
          insert(head, last, comNum);
          numberList = updateList(numberList, comNum);
          printIntList(numberList);
        }
        else
          cout << "There are no more numbers for com to play!" << endl;
          break;

      case '2':  showList(head);
        break;

      case '3':  removeElem(head, last);
        break;

      case '4':  head = NULL;
        last = NULL;
        cout << "List cleared! \n";
        break;

      default:   //printIntList(numberList);
        //ismember(numberList, number);
        cout << "System exit! \n";

            
    }
  }while (choice !='5');
}