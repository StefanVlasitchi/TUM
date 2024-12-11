#include <stdio.h>

int n, a[105][105];

void citire()
{
	freopen("royfloyd.in","r",stdin);
	freopen("royfloyd.out","w",stdout);

	int i, j;
	scanf("%d",&n);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++) scanf("%d",&a[i][j]);
}

void roy_floyd()
{
	int i, j, k;
	for (k = 1; k <= n; k++)
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				if (a[i][k] && a[k][j] && (a[i][j] > a[i][k] + a[k][j] || !a[i][j]) && i != j) a[i][j] = a[i][k] + a[k][j];
}

void afis()
{
	int i, j;
	for (i = 1; i <= n; i++) 
	{
		for (j = 1; j <= n; j++) printf("%d ",a[i][j]);
		printf("\n");
	}
}


int main()
{
	citire();
	roy_floyd();
	afis();
	return 0;
}
