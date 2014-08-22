#include <iostream>
using namespace std;

int main ()
{
	int cases;
	while (cin >> cases)
	{	

		if (cases == 0) return 0;		

		int divX, divY;
		cin >> divX >> divY;
		
		for (int i = 0; i < cases; i++)
		{
			int x,y;
			cin >> x >> y;
			
			if (x == divX || y == divY)
				cout << "divisa" << endl;
			else
				if (y > divY)
				{
					// north
					if (x > divX)
						cout << "NE" << endl;
					else 
						cout << "NO" << endl;
				}
				else
				{
					if (x > divX)
						cout << "SE" << endl;
					else 
						cout << "SO" << endl;
				}
		}
	
	}
}
