/*
  102 - Ecological Bin Packing
  08/08/2014
*/

#include <iostream>
#include <climits>
#include <string>
using namespace std;
 
int main ()
{ 
    while (cin)
    {       
        int bin [9];    
        int in;
        int totalSum = 0;
        int sumArray[6] = {0,0,0,0,0,0};
        
        for (int i = 0; i < 9; i++)
        {
            cin >> bin [i];
            if (cin.eof()) return 0;
            totalSum += bin[i];
        }
        // B G C  B G C B G 
        //BCG - 0 5 7
        sumArray[0] = totalSum - bin [0] - bin [5] - bin[7];
        
        //BGC - 0 4 8        
        sumArray[1] = totalSum - bin [0] - bin [4] - bin[8];
        
        //CBG - 2 3 7
        sumArray[2] = totalSum - bin [2] - bin [3] - bin[7];
       
        //CGB - 2 4 6
        sumArray[3] = totalSum - bin [2] - bin [4] - bin[6];
       
        //GBC - 1 3 8        
        sumArray[4] = totalSum - bin [1] - bin [3] - bin[8];
        
        //GCB - 1 5 6
        sumArray[5] = totalSum - bin [1] - bin [5] - bin[6];
       
        char arrayStrings [6][4] = {"BCG","BGC","CBG","CGB","GBC","GCB"};
        int min = INT_MAX;
        int minIndex=0;
        for (int i = 5; i >= 0; i--)
        {
            //cout << sumArray[i] << " ";
            if (min >= sumArray[i])
            {
                min = sumArray[i];
                minIndex = i;
            }            
        }
        //cout << endl;
        cout << arrayStrings [minIndex] << ' '<< min<<endl;
    }

}
