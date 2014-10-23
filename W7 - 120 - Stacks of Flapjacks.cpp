#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool decSort (int i, int j) { return i>j;}


int main ()
{
	string line;
	while (getline(cin, line))
	{
		stringstream s(line);

		stack <int> mStack;
		stack <int> aux1;
		stack <int> aux2;
		vector <int> printVector;
		vector <int> auxV;
		vector <int> answer;
		int x;


		while (s >> x)
		{
			aux1.push(x);
			auxV.push_back(x);
			printVector.push_back(x);
		}


		while (!aux1.empty())
	    {
	 		mStack.push(aux1.top());
	 		aux1.pop();
	    }

		int sSize = mStack.size();

	    sort (auxV.begin(), auxV.end(), decSort);
	    int nSorted = 0;
	    for (std::vector<int>::iterator it=auxV.begin(); it!=auxV.end(); ++it, ++nSorted)
	    {
		    int biggest = int(*it);
		    //	cout<< biggest << "  ";

			int partialAnswer  = -1;
		    while (!mStack.empty())
		    {
		    	partialAnswer++;

		    	if (mStack.top()!=biggest)
		    	{
			  		aux1.push(mStack.top());
				  	mStack.pop();
		    	}
		    	else
		    	{
		    	  aux1.push(mStack.top());
					  mStack.pop();
					  break;
          }
		    }
		    if (sSize - partialAnswer != sSize)
		    	answer.push_back(sSize - partialAnswer);


		    while (!aux1.empty())
		    {
		    	aux2.push(aux1.top());
		    	aux1.pop();
		    }
		    while (!aux2.empty())
		    {
		    	mStack.push(aux2.top());
		    	aux2.pop();
		    }

			bool print = false;
			for (int i = 0; i < sSize - nSorted; i++)
			{
				aux1.push(mStack.top());
				mStack.pop();

			}

			while (!aux1.empty())
		    {
		    	aux2.push(aux1.top());
		    	aux1.pop();
		    }
		    while (!aux2.empty())
		    {
		    	mStack.push(aux2.top());
		    	aux2.pop();
		    }

			answer.push_back(nSorted + 1);

/*
			// Print stack
		    while (!mStack.empty())
			{
			std::cout << ' ' << mStack.top();
			mStack.pop();
			}
			cout << endl;
*/
		}

		    for (std::vector<int>::iterator it=printVector.begin(); it!=printVector.end()-1; ++it)
				cout << *it << ' ';
			cout << printVector[printVector.size()-1];
			cout << endl;

			for (std::vector<int>::iterator it=answer.begin(); it!=answer.end(); ++it)
				if (*it == *(it+1))
				{
					*it = -1; *(it+1) = -1;
				}

			for (std::vector<int>::iterator it=answer.begin(); it!=answer.end(); ++it)
				if (*it != -1)
					if(*it != sSize)
						cout << *it << " ";
			cout << "0";
			cout << endl;
	}
}
