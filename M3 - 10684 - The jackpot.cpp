#include <iostream>
#include <climits>
using namespace std;

long long vector[10001];
int main()
{
	int n;
	while (cin >> n && n != 0)
	{

		for (int i = 0; i < n; ++i)
		{
			cin >> vector[i];
			
		}
		
		long long sum = vector[0];
		for (int i = 1; i < n; ++i)
		{
			if (vector[i-1] > 0)
			{
				vector[i] += vector[i-1];
				sum = max(sum, vector[i]);
			}
		}

		if (sum <= 0)
		{
			cout << "Losing streak." << endl;
		}
		else cout << "The maximum winning streak is " << sum << "." << endl;
		
	}
}
