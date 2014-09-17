#include <iostream>
#include <set>
#include <vector>
#include <cstdio>

using namespace std;
 
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
 
const int MAX = 20000;
const int MAXINT = 1000000000;
 

vvii G(MAX);
vi D(MAX, MAXINT);
 
void Dijkstra(int s)
{
    set<ii> Q;

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

	int nTests;
	cin >> nTests;	
	
	
	for (int c = 1; c <= nTests; c++)
	{
		int n, m, s, t;
		cin >> n >> m >> s >> t;		
		
	 	G.clear();
		G.resize(n);
	 	int ret = 0;
		for (int i = 0; i < m; i++)
		{
		    int a, b, w;
		    cin >> a >> b >> w;
		    G[a].push_back(ii(b, w));
		    G[b].push_back(ii(a, w));
		}
		D.assign(n,MAXINT);
		Dijkstra(s);		
		
		if (D[t] != MAXINT)		
			printf("Case #%d: %d\n", c, D[t]);
		else
			printf("Case #%d: unreachable\n", c);
	
	}	
    

    return 0;
}
