
#include <iostream>
#include <vector>
using namespace std;

vector < vector<int> > graph;
vector <int> color;

#define UNVISITED 0
#define RED 1
#define BLUE 2

bool dfs(int u) {

    bool ret = true;
    for(int i = 0; i < graph[u].size(); i++) {
        int neighbor = graph[u][i];
        if(color[neighbor] != UNVISITED && color[neighbor] == color[u]) {
            return false;
        }
        if(color[neighbor] == UNVISITED) {
            color[neighbor] = (color[u] == RED? BLUE : RED);
            ret = ret & dfs(neighbor);
        }
    }
    return ret;

}

int main ()
{
	while (cin.good())
	{
		int nNodes,nEdges;
		cin >> nNodes;
		cin >> nEdges;
		if (nNodes==0) break;

		graph.clear();
        graph.resize(nNodes);
        color.assign(nNodes, 0);

		for (int i = 0; i < nEdges; i++ )
		{
			int a, b;
			cin >> a >> b;

			graph[a].push_back (b);
			graph[b].push_back (a);
		}

		/*
		for (int i = 0; i < nNodes; i++ )
		{
			for (int j = 0; j < (graph[i]).size(); j++)
			{
				cout << graph[i][j] << " ";
			}
			cout << endl;
		}
		*/
		color[0] = RED;
		if(dfs (0))
            cout << "BICOLORABLE." << endl;
        else
            cout << "NOT BICOLORABLE." << endl;

	}
}

