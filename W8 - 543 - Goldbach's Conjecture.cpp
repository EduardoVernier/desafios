#include <cstring>
#include <iostream>
using namespace std;

bool sieve [1000001];

int main ()
{
	memset (sieve, true, 1000001);
	
	for (int i = 2; i < 1000001; i++)
	{
		if (!sieve[i])
			continue;
			
		for (int j = i+i; j < 1000001; j = j +i)		
			sieve[j] = false;
	}
	
	//for (int i = 2; i < 200; i++)
	//	cout << i << ' ' << sieve[i] << endl;
		
	
	while (1)
	{
		int n;
		cin >> n;
		if (n == 0) return 0;
		
		for (int b = n - 2; b > 0; b--)		
			if (sieve[b] && sieve[n-b])
			{
				cout << n<< " = " << n-b << " + " << b << endl;
				break;				
			}		
	}	
}
