#include <iostream>
#include <set>
#include <vector>
#include <cstdio>

using namespace std;
 
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
 
const int MAX = 101;
const int MAXINT = 1000000000;
 
int n;
vvii G(MAX);
vi D(MAX, MAXINT);
 
void Dijkstra(int s)
{
    set<ii> Q;
    D.assign(MAX,MAXINT);
    D[s] = 0;
    Q.insert(ii(0,s));
 
    while(!Q.empty())
    {
        ii top = *Q.begin();
        Q.erase(Q.begin());
        int v = top.second;
        int d = top.first;
 
        for (vii::const_iterator it = G[v].begin(); it != G[v].end(); it++)
        {
            int v2 = it->first;
            int cost = it->second;
            if (D[v2] > D[v] + cost)
            {
                if (D[v2] != 1000000000)
                {
                    Q.erase(Q.find(ii(D[v2], v2)));
                }
                D[v2] = D[v] + cost;
                Q.insert(ii(D[v2], v2));
            }
        }
    }
}
 
int main()
{
	int Case = 1;
	while (true) {
	 	G.clear();
		G.resize(101);
	 	int ret = 0;
		for (;;)
		{
		    int a, b;
		    cin >> a;
			cin >> b; 
			if (a == 0 && b == 0)
				break;

		    G[a - 1].push_back(ii(b - 1, 1));
		    ret++;
		}
		
		if (ret == 0)
			break;
		
		float sum = 0;
		int nOfEdges = 0;
		
		for (int i = 0; i < MAX; i++)
		{
			if (G[i].size() > 0)
			{
				Dijkstra(i);
				//cout << endl << i << endl;
				for (int j = 0; j < MAX ; j++)
				{
					if (D[j] > 0 && D[j] < MAXINT)
					{
						sum += D[j];
						nOfEdges++;							
					}
				}
			}    	
		}
		
		float avg = sum / nOfEdges;
		
		printf("Case %d: average length between pages = %.3f clicks\n", Case, avg);
		Case++;
	
	}	
    

    return 0;
}
