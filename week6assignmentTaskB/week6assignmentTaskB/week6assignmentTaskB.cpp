#include <iostream>
using namespace std;

void DNAreplacement(string S, string L, string R, string Y, string X)
{
	int indexY = 0; //initialise index of Y to 0

	//get the length of each string and store in an int
	int SLength = S.length();
	int LLength = L.length();
	int RLength = R.length();
	int YLength = Y.length();
	int XLength = X.length();

	for (int i = 0; i <= SLength - YLength; i++)
	{
		indexY = S.find(Y, i); //find y in the string

		//condition
		if (indexY >= LLength && (S.substr(indexY - LLength, LLength) == L) && (S.substr(indexY + YLength, RLength) != R))
		{
			string SNew = S; //set the new string to string S
			SNew.replace(indexY, XLength, X); //replace Y with X
			cout << SNew << endl; //print the modified string
			i = i + indexY; //move index to the next value
		}
	}
}

int main()
{
	//initialise strings
	string S = "ATATATATGTATATATGTA"; 
	string L = "A";
	string R = "GT";
	string Y = "TAT";
	string X = "GG";

	//call function replace
	DNAreplacement(S, L, R, Y, X);
}
