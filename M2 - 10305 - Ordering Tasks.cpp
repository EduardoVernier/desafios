#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

vector <vector <int > >  g;
vector <int> inDeg;
vector <int> sorted;
int main ()
{
	while (1)
	{
		int nNodes, nEdges;
		cin >> nNodes >> nEdges;
		inDeg.assign(nNodes+1, 0);
		g.clear();
		g.resize(nNodes+1);
		sorted.clear();
		
		if (nNodes == 0) return 0;
		
		for (int i = 0; i < nEdges; i++)
		{
			int a, b;
			cin >> a >> b;

			g[a].push_back(b);
			inDeg[b]++;
		}

		queue <int> zeroIn;
		for (int i = 1; i <= nNodes; i++)
		{
			if (inDeg[i] == 0)
				zeroIn.push(i);
		}

		int j = 0;
		int x, y;


		while (!zeroIn.empty())
		{
			j++;
			x = zeroIn.front(); zeroIn.pop();

			sorted.push_back(x);
			for (int i = 0; i < g[x].size(); i++)
			{
				y = g[x][i];
				inDeg[y]--;
				if (inDeg[y] == 0)
					zeroIn.push(y);
			}
		}
		
		
		for (int i = 0; i < nNodes-1; i++)
			cout << sorted[i] << " ";
		cout << sorted [sorted.size()-1];
		cout<<endl;
	}

}
