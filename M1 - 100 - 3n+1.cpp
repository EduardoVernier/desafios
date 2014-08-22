#include <iostream>
using namespace std;

int main ()
{		
	long a, b;
	while (cin >> a >> b)
	{		
		long max = -1;
		bool reverse = false;
		
		if (a > b)
		{
			int c = b;
			b = a;
			a = c; 
			reverse = true;
		}
			
		
		for (long i = a; i <= b; i++)
		{
			long n = i;
			int cicles = 1;			
			
			while (n > 1)
			{
				cicles++;
				if (n % 2 == 1)
					n = 3*n+1;
				else 
					n = n/2; 
			}		
			
			if (cicles > max)
				max = cicles;		
		}		
		if (reverse == false)			
			cout << a << " " << b << " " << max << endl;	
		else 
			cout << b << " " << a << " " << max << endl;
	}
}
