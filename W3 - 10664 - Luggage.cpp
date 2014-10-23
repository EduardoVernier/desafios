#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


int main()
{
	int m;
	cin >> m;
	cin.ignore();
	for (int _m = 0; _m < m; ++_m)
	{
		string line;
		getline(cin, line);
		stringstream s(line);
		int x;
		vector<int> weights;
		int sum = 0;
		
		int helper = 0;
		
		while (s >> x)
		{
			weights.push_back(x);
			sum += x;
		}
		bool matriz[20][201] = {false};
		
		helper = weights[0];
		
		for (size_t i = 0; i < weights.size(); ++i)
		{
			for (int j = 0; j <= 200; ++j)
			{
				if (j == 0) matriz[i][j] = 1;
				if (j > helper)
				{
					helper += weights[i+1];
					break;
				}
				matriz[i][j] = (j == weights[i]) 
				|| (i>0 && j >= weights[i] && matriz[i-1][j-weights[i]]) 
				|| (i > 0 && matriz[i-1][j]);
			}
		}
		if (sum % 2 == 1)
		{
			cout << "NO" << endl;
		}
		else
		{
			if (matriz[weights.size()-1][sum/2])
				cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
}
