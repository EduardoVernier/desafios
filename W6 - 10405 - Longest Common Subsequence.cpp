#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int> >  M;

int main ()
{
	while (1)
	{
		string tA, tB;
		getline(cin, tA);
		getline(cin, tB);

		if (tB.size() == 0)
			break;

		string A, B;
		A.append("0"); A.append(tA);
		B.append("0"); B.append(tB);

		int sizeA = A.size();
		int sizeB = B.size();

		M.clear();
		M.resize(sizeA, vector<int>(sizeB));

		//cout << A << " - "<< B << endl;

		/* Initialization */
		for (int i=0; i < sizeA; i++)
			M[i][0] = 0;

		for (int j=0; j < sizeB; j++)
			M[0][j] = 0;

		/* DP */
		for (int i=1; i < sizeA; i++)
			for (int j=1; j < sizeB; j++)
			{
				if (A[i] == B[j])	
					M[i][j] = M[i-1][j-1] + 1;
				else
					M[i][j] = max(M[i-1][j], M[i][j-1]);
			}

		
		cout << M[sizeA-1][sizeB-1] << endl;
	}
}
