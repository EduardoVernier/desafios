/*
    11332 - Summing Digits
    08/08/2014
*/

#include <iostream>

using namespace std;

int sumDigits (int n)
{
    int sumSoFar=0;
    while (n > 0)
    {
         sumSoFar+=n%10;
         n = n/10;
    }
    return sumSoFar;
}


int main ()
{
    int n;
    while (cin >> n)
    {      
        if (n == 0)
            return 0;
        else 
        {
            while (n > 9)
            {
                n = sumDigits(n);
            }            
            cout << n << endl;
        }            
    }    
}
