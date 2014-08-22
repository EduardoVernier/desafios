#include <iostream>
using namespace std;

int main ()
{
	int ang;
	while (cin >> ang)
	{
		if (ang % 6 == 0)
			cout << "Y" <<endl;
		else
			cout << "N" <<endl;
	}
}
