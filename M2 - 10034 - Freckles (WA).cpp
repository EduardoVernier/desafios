#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

vector < vector< pair<double,int> > > g;
int n;

vector < pair <double,double> > points;

float prim()
{
	priority_queue< pair<double,int>, vector< pair<double,int> >, greater< pair<double,int> > > q;
	bool vis[n];
	for (int i = 0; i < n; i++)
	{
		vis[i] = 0;
	}
	
	//vector <int> vis;
	//vis.clear();
	//vis.assign(n,0);
	
	pair<double,int> p;
	int v;
	double w, ret = 0;
	q.push(make_pair(0,0));
	while(!q.empty())
	{
		p = q.top(); q.pop();
		v = p.second;
		w = p.first;
		if	(vis[v] != 0)
			continue;
		vis[v] = 1;
		ret += w;
		for	(int i = 0; i < g[v].size(); ++i)
			if ( !vis[ g[v][i].second ] )
			{
				q.push( make_pair( g[v][i].first, g[v][i].second ));
			}
	}
	return ret;
}

int main ()
{
	int nTest;
	cin >> nTest;

	for (int t = 0; t < nTest; t++)
	{
		cin >> n;
		g.clear();
		g.resize(n);
		points.clear();

		for (int j = 0; j < n; j++)
		{
			double a, b;
			cin >> a >> b;
			points.push_back(make_pair (a,b));
		}


		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (j!=i)
				{
					double x1, y1, x2, y2, weight;
					x1 = points[i].first;
					y1 = points[i].second;
					x2 = points[j].first;
					y2 = points[j].second;

					weight = sqrt ((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
					//cout << i << ", " << j<< " = "<< weight << endl;
					g[i].push_back(pair<double, int>(weight, j));
				}
			}
		}

		printf ("%.2lf\n", prim());
	}
}
