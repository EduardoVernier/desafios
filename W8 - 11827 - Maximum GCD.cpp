#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

vector <long> v;
		
bool decSort (long i, long j) { return i>j;}

long gcd1(long p, long q)
{
	if (q > p) return (gcd1(q, p));
	if (q == 0) return p;
	return (gcd1(q, p%q));
}

int main ()
{
	int cnt;		
	cin >> cnt;
	cin.ignore();
	
	for (;cnt > 0; cnt--)
	{
		v.clear();
		string line;
		getline(cin, line);
		stringstream s(line);
			
		long x;
		while (s >> x)
			v.push_back(x);
		
		
		sort (v.begin(), v.end(), decSort);
		
		long biggestYet = -1;
		
		for (int i = 0; i < v.size(); i++)
		{
			for (int j = i+1; j < v.size(); j++)
			{
				if (v[j] <= biggestYet) break;
				long r = gcd1 (v[i],v[j]);
				
				biggestYet = (r > biggestYet)? r: biggestYet;

			}
		}
		
		cout << biggestYet << endl;	
	}
}
