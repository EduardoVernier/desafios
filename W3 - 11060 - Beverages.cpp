#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

vector < vector<int> > g;
vector <string> beverages;
vector <string> toposorted;
vector <int> inDeg;
int nNodes;

int keepGoing ()
{
	int x = 0;
	for (int i = 0; i < nNodes; i++)
		if (inDeg[i]!=-1)
			return true;
	
	return false;
}


int main ()
{
	int CASE = 1;

	while (cin.good())
	{

		int nEdges;

		if (cin >> nNodes)
			;
		else return 0;


		g.clear();
        g.resize(nNodes);
		beverages.clear();
		beverages.resize(nNodes);
		toposorted.clear();
		inDeg.clear();
		inDeg.resize(nNodes);
		inDeg.assign(nNodes,0);

		for (int i = 0; i < nNodes; i++ )
		{
			string name;
			cin >> name;
			if (cin.bad())
				return 0;

			beverages[i] = name;
		}

		cin >> nEdges;
		for (int i = 0; i < nEdges; i++ )
		{
			string b1, b2;
			cin >> b1 >> b2;

			int b1Index, b2Index;

			for (int j = 0; j < nNodes; j++)
			{
				if (beverages [j] == b1)
					b1Index = j;
				if (beverages [j] == b2)
					b2Index = j;
			}

			g[b1Index].push_back(b2Index);
			inDeg[b2Index]++;
		}

		for (int i = 0; i < nNodes; i++)
            sort(g[i].begin(),g[i].end());


		int y;
		while(keepGoing ())
		{
			for (int i = 0; i < nNodes; i++)
			{
				if (inDeg[i] == 0)
				{
					inDeg[i]--;
					//cout << beverages[i] << "  ";
					toposorted.push_back(beverages[i]);
					for (int j = 0; j < g[i].size(); j++)
					{
						y = g[i][j];
						inDeg[y]--;
					}
					break;
				}

			}
        }

        cout << "Case #" << CASE << ": Dilbert should drink beverages in this order: ";
		for (int i = 0; i < toposorted.size() -1; ++i)
			cout << toposorted[i] << " ";
		cout << toposorted[toposorted.size()-1] << "."  << endl;
		cout << endl;
		CASE++;

	}
}
