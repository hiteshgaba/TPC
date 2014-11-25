#include <iostream>
#include <string.h>

bool AreAllNine (char * num, int n)
{
	for (int i=0; i<n ; i++)
		if (num [i] != '9')
			return false;

	return true;
}

void PrintArray (char * num, int n)
{
	for (int i = 0;i<n ;i++)
		std::cout<<num[i];
}

void GenerateNextPalindrome (char * num, int n)
{
	int mid = n/2;
	bool leftsmall = false;
	int i,j;

	//Need not to copy the left side to right side if the digits 
	//on left and right are the same
	for (i=mid-1, j = n%2 ? mid+1 : mid ; i>=0;  i--, j++) {
		if (num [i] != num [j])
			break;
	}
	
	//Left is smaller than right or number itself is a palindrome
	if (i<0 || num[i] < num[j])
		leftsmall = true;
	
	else {
		//Copy from left to right
		for (;i>=0; j++, i--) 
			num [j] = num [i];
	}

	//CASE : Where left side is smaller or equal
	if (leftsmall) {

		int carry = 1;

		//Propagate the carry from left to right and 
		//take the mirror alongside
		for (i = n%2 ? mid : mid-1, j = mid ; i>=0 ;) {
			
			num [i]= ((num [i]-48) + carry) + 48;
			carry = (num [i]-48)/10;
			num [i] = ((num[i]-48)%10)+48;

			num [j++] = num [i--];
		}
	}

	//Print the array which is modified
	PrintArray (num, n);
}

void NextPalindrome (char * num, int n)
{
	if (AreAllNine (num, n)) {
		
		std::cout << "1";
		for (int i=1;i<n; i++)
			std::cout << "0";
		std::cout << "1";
	} else {
		GenerateNextPalindrome (num, n);
	}
}

int main ()
{
	int T;

	std::cin>>T;

	while (T--) {
		
		int i = 0;

		char num [1000001]; 

		std::cin>>num;

		NextPalindrome (num, strlen (num));

		std::cout << "\n";
	}	

	return 0;
}