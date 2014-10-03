#include <iostream>
#include <vector>
using namespace std;

int value[] = {1,5,10,25,50};

int main ()
{
	int n;
	while (cin >> n)
	{
		vector <long long> V;
		V.assign (n+1, 1);
		
		
		for (int i=1; i < 5; i++)
			for (int j=1; j<=n; j++)			
				if (j - value[i] >= 0)
					V[j]+=V[j - value[i]];			
		
		
		if (V[n] > 1)
			cout <<"There are " << V[n] <<" ways to produce " 
				<< n << " cents change." << endl;	
		else
			cout << "There is only 1 way to produce " << n 
				<< " cents change." << endl;
	}
}
