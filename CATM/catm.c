#include <stdio.h>

int main ()
{
	int m,n,t;
	int mi, mj, c1i, c1j, c2i, c2j;

	scanf("%d", &m);
	scanf("%d", &n);

	scanf("%d", &t);

	while(t--)
	{
		scanf("%d%d%d%d%d%d", &mi, &mj, &c1i, &c1j, &c2i, &c2j);
		
		if(((mi+mj == c1i+c1j) && (mi+mj == c2i+c2j) && ((c1i < mi && c2i > mi) || (c1i > mi && c2i < mi))) || ((mi-mj == c1i-c1j) && (mi-mj == c2i-c2j) && ( (c1i < mi && c2i > mi) || (c1i > mi && c2i < mi) )))
			printf("NO\n");
		else
			printf("YES\n");
	}

	return 0;
}
