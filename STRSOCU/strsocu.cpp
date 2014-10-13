#include <iostream>
#include <stdio.h>
#include <string.h>

int GetNumOfSubStr (char * A, char * B, int K);

#define MAX_SRING_SIZE 8001

int main ()
{
	int T;
	char A[MAX_SRING_SIZE];
	char B[MAX_SRING_SIZE];
	int K;
	int i=0;

	scanf ("%d", &T);

	while (i++ <= T) {

		scanf ("%s", A);
		scanf ("%s", B);
		scanf ("%d", &K);

		printf ("Case #%d\n", i);
		printf ("%d\n", GetNumOfSubStr (A, B, K));
	}

	return 0;
}

int countSubStr (char * A, char * B, int start, int end)
{
	bool flag;
	int count = 0;

	for (int i=0; i<= strlen (B)-(end-start); i++)
	{
		flag = true;

		for (int j=start,k=i;j<end;j++,k++) {

			if(A[j]!=B[k]) {
				flag = false;
				break;
			}
		}

		if(flag == true)
		{
			count++;
		}
	}

	return count;
}


int GetNumOfSubStr (char * A, char * B, int K)
{
	int la = strlen (A);
	int lb = strlen (B);
	int count = 0;
	int currcount = 0;
	int selfcount = 0;

	for (int size=1; size<=lb; size++)
	{
		currcount = 0;

		for (int i=0;i<=la-size;i++)
		{
			currcount = countSubStr (A, A, i, i+size)-1;

			if (countSubStr (A, B, i, i+size) == K) 
			{
				selfcount+=currcount;
				count ++;
			}
		}
	}

	return (count-(selfcount/2));
}
