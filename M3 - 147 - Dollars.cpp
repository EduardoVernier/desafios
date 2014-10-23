#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int coins[] = { 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};

long long int pd[30001][11] = {0};

int main()
{
	for (int c = 0; c < 11; ++c)
	{
		for (int j = 0; j <= 30000; ++j)
		{
			if (c == 0) pd[j][c] = 1;
			else if (j >= coins[c])
			{
				pd[j][c] = pd[j][c-1] + pd[j-coins[c]][c];
			}
			else
			{
				pd[j][c] = pd[j][c-1];
			}
		}
	}
	
	float amt;
	while (cin >> amt && amt != 0.0)
	{
		int x = round(amt*100);
		printf("%6.2f%17lld\n", amt, pd[x][10]);
	}

}
