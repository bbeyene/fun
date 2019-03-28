#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void setFirstRook(int& firstRook, bool firstRookRow[], bool firstRookCol[], int size);
void setSecondRook(int& firstRook, int& secondRook, bool secondRookRow[], bool secondRookCol[], int size);
bool attack(bool firstRookRow[], bool firstRookCol[], bool secondRookRow[], bool secondRookCol[], int size);

int main()
{
	srand(time(NULL));
	const int grid = 6;
	bool firstRookRow[grid];
	bool firstRookCol[grid];
	bool secondRookRow[grid];
	bool secondRookCol[grid];
	int firstRook = 0;
	int secondRook = 0;
	int attacked = 0;
	
	int runs = 1000;
	
	for (int i = 0; i < runs; i++) {		
		setFirstRook(firstRook, firstRookRow, firstRookCol, grid);
		setSecondRook(firstRook, secondRook, secondRookRow, secondRookCol, grid);
		
		if(attack(firstRookRow, firstRookCol, secondRookRow, secondRookCol, grid))
		 	attacked++;
	}
	
	cout << endl <<	"Runs = " << runs << endl;
	cout << "Attacked " << attacked << endl;
	cout << "Safe = " << runs - attacked << endl;
	cout << endl << ((double)(runs - attacked))/((double)runs) * 100 << "%" << endl;
		
	return 0;
}

void setFirstRook(int& firstRook, bool firstRookRow[], bool firstRookCol[], int size)
{
	firstRook = (rand() % (size*size) + 1) - 1;
	int placeCount = 0;

	for(int i = 0; i < size; i++) {
		firstRookRow[i] = false;
		firstRookCol[i] = false;	
	}
		
	for (int i = 0; i < size; i++)	{
		for (int j = 0; j < size; j++) {
			if (placeCount == firstRook) {
				firstRookRow[i] = true;
				firstRookCol[j] = true;
				return;
			}
			placeCount++;
		}
	}
}
void setSecondRook(int& firstRook, int& secondRook, bool secondRookRow[], bool secondRookCol[], int size)
{
	secondRook = (rand() % (size*size)) - 1;
	int placeCount = 0;
	
	if (firstRook == secondRook)
		secondRook++;
		
	for(int i = 0; i < size; i++) {
		secondRookRow[i] = false;
		secondRookCol[i] = false;	
	}
		
	for (int i = 0; i < size; i++)	{
		for (int j = 0; j < size; j++)	{
			if (placeCount == secondRook) {
				secondRookRow[i] = true;
				secondRookCol[j] = true;
				return;
			}
			placeCount++;
		}
	}
}
bool attack(bool firstRookRow[], bool firstRookCol[], bool secondRookRow[], bool secondRookCol[], int size)
{
	for(int i = 0; i < size; i++) {
		if((firstRookRow[i] && secondRookRow[i]) || (firstRookCol[i] && secondRookCol[i]))
			return true;
	}
	return false;
}
