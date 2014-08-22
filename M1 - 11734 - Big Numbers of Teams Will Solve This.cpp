#include <iostream>
#include <string>
#include <cstddef>  
using namespace std;


string replaceAll(string str, const string& from, const string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
    return str;
}

int main ()
{
	string team;
	string judges;
	string temp;
	int cases;
	
	cin >> cases;
	getline (cin, temp);
	
	
	for (int i = 1; i <= cases; i++)
	{
		getline (cin, team);
		getline (cin, judges);
		
		//cout << team << endl;
		//cout << judges << endl;
		
		if (team.compare(judges) ==0)
		{
			cout << "Case " << i << ": Yes"<< endl;
		}
		else
		{
			 size_t found = team.find_first_of(" ");
			 if (found!=std::string::npos)
			 {
			 	team = replaceAll (team, " ", "");			   		
			  	//cout << team<<endl;
			  	
			  	if (team.compare(judges) ==0)
			  		cout << "Case " << i << ": Output Format Error"<< endl;
			  	else 
			  		cout << "Case " << i << ": Wrong Answer"<< endl;
			 }
			 else 
			  		cout << "Case " << i << ": Wrong Answer"<< endl;
		}
	}
}
