/*
    10172 - The Lonesome Cargo Distributor
    19/08/2014
*/

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

int main ()
{
    int nOfSets;
    cin >> nOfSets;

    for (int i = 0; i < nOfSets; i++)
    {
        int nOfStations, carrierCapacity, stationMax;
        cin >> nOfStations >> carrierCapacity >> stationMax;

        vector <queue<int> > ABCDEF;
        ABCDEF.push_back(queue<int>());  // index 0

        for (int s = 1; s <= nOfStations; s++)
        {
            ABCDEF.push_back(queue<int>());
            int nOfCargoesInB;
            cin >> nOfCargoesInB;
            for (int k = 0; k < nOfCargoesInB; k++)
            {
                int temp;
                cin >> temp;
                (ABCDEF[s]).push(temp);
            }
        }

        int totalTime = 0;
        stack<int> carrier;
        int currentStation = 1;

        while (true)
        {
            // Try to unload
            while (!carrier.empty())
            {
                if (carrier.top() == currentStation)
                {
                    carrier.pop();
                    totalTime++;
                }
                else
                    if (ABCDEF[currentStation].size() < stationMax)
                    {
                        ABCDEF[currentStation].push(carrier.top());
                        carrier.pop();
                        totalTime++;
                    }
                    else break;
            }

            // Try to load
            while ( ABCDEF[currentStation].size() > 0 && carrier.size() < carrierCapacity)
            {
                carrier.push(ABCDEF[currentStation].front());
                ABCDEF[currentStation].pop();
                totalTime++;
            }


            bool retorna = carrier.empty();
			for (int i = 0; i < nOfStations; i++) {
				retorna &= ABCDEF[i].empty();
			}
			if (retorna)
				break;
			
			
            totalTime += 2;
            currentStation++;
            if (currentStation == nOfStations+1)
                currentStation = 1;

        }
        
        cout << totalTime << endl; 
    }
}
