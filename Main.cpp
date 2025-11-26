#include <iostream>
#include <string>
#include <list>
using namespace std;
//used to check if any of the values in two arrays are the same
bool anyinarray(const string arr[], int arrsize,
	const string ref[], int refsize)
{
	for (int i = 0; i < arrsize; i++)
	{
		for (int j = 0; j < refsize; j++)
		{
			if (arr[i] == ref[j]) 
			{
				return true;
			}
		}
		
	}
	return false;
}

//used to print an array, loops through all the values of an array and prints them when called
//void so it can be called anywhere
void printarray(string r[], int size)
{
	for (int i = 0; i < size; i++) {
		cout << r[i] << " "<<endl;
	}
	cout << endl;
}
int main()
{	//defines ing (used for user input) and its size is kept open so its size can be called 
	const int size = 3;
	string ing[size];

	//define recipies and size
	string rpho[] = { "chicken","broth","noodles","noodle","five" };
	int phosize = 5;
	string rtaco_bowl[] = { "beef","noodles","rice","beef" };
	int taco_bowlsize = 4;
	string rporkbelly[] = { "porkbelly","noodles","rice","chips","twenty" };
	int porkbellysize = 5;
	string rcandvstirfry[] = { "chicken","brocoli","Broccoli","Carrots","peppers","Soy sauce","garlic"};
	int candvstirfrysize = 7;
	string rturkeyrap[]={"turkey","lettuce","onion","hoisin sauce"};
	int turkeyrapsaize = 4;


	cout << "what three things have we got?" << endl;
//taes user input and saves it as ing
	for (int i = 0; i < size; i++)
	{
		cin >> ing[i];
	}
	//defines boolean match[i] and checks if any of the values in 2 arrays of 2 sizes are the same 
	bool matchpho = anyinarray(ing, size, rpho, phosize);
	bool matchtaco_bowl = anyinarray(ing, size, rtaco_bowl, taco_bowlsize);
	bool matchporkbelly = anyinarray(ing, size, rporkbelly, porkbellysize);
	bool matchcandvstirfry = anyinarray(ing, size, rcandvstirfry, candvstirfrysize);
	bool matchturkeyrap = anyinarray(ing, size, rturkeyrap, turkeyrapsaize);
	
	//check if the match is true and prints a prompt pluss the ingredients 
	if (matchpho) {
		cout << "pho\n-------\nyoull need:\n";
		printarray(rpho, phosize);
	}
	if (matchtaco_bowl) {
		cout << "taco bowls\n-------\nyoull need:\n";
		printarray(rtaco_bowl, taco_bowlsize);
	}
	if (matchporkbelly) {
		cout << "Pork belly\n-------\nyoull need:\n";
		printarray(rporkbelly, porkbellysize);
	}
	if (matchcandvstirfry) {
		cout << "chicken and veg stirfry\n-------\nyoull need:\n";
		printarray(rcandvstirfry, candvstirfrysize);
	}
	if (matchturkeyrap) {
		cout << "Turkey wraps\n-------\nyoull need:";
		printarray(rturkeyrap, turkeyrapsaize);
	}




	//print if it doesnt match any of the recipies( needs work, i dont like that i have to input it here every time)
	if (!matchpho && !matchporkbelly && !matchtaco_bowl && !matchcandvstirfry)
		cout << "fail";

			
	return 0;
	
}