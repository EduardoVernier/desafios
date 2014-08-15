/*
    10935 - Throwing cards away I
    15/08/2014
*/

#include <iostream>
#include <deque>

using namespace std;

int main () 
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            return 0;
        
        deque <int> D;        
        
        for (int i = 1; i<=n; i++)
            D.push_back(i);        
        
        //cout << "Initial Deque: ";
        //for (std::deque<int>::iterator it = D.begin(); it!=D.end(); ++it)
        //    std::cout << ' ' << *it;
        //cout << endl;
        
        cout << "Discarded cards:";
        while (D.size()>1)
        {
            cout <<" "<< D.front();
            D.pop_front();
            int swap = D.front();
            D.pop_front();
            D.push_back(swap);
            
            if (D.size()!=1)
                cout << ","; 
        }
        cout << endl;
        cout << "Remaining card: "<< D.front() << endl; //last
    }
}
