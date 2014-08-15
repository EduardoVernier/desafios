/*
    11062 - Andy's Second Dictionary
    15/08/2014
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <ctype.h>
#include <sstream>      
#include <list>
using namespace std;
 
string removeNonAlpha (string text)
{
    string t = text;
    for (int i=0; t[i]!='\0'; i++)
    {
        if (!isalpha(t[i]) && t[i] !='-' && t[i] !='\n' && t[i] !=' ')
        {
            t.erase (i,1);
            i=i-1;
        }    
    }
    return t;
 
}

string replaceAll(string str, const string& from, const string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
    return str;
}

 
 
int main()
{
    string text = "";
    string newLine = "\n";
    while (cin.good())
    {
        string buffer;
        getline(cin, buffer);
       
        text.append(buffer);
        text.append(newLine);
    }
   

    text = replaceAll (text,"\'"," ");
    
    transform(text.begin(), text.end(), text.begin(),::tolower);  
    
    text = removeNonAlpha(text);
    
    text = replaceAll (text,string ({'-','\n'}),"");
   
    stringstream ss (text);
   
    list <string> result;
 
   
    while (ss.good())
    {
        string a;
        ss >> a;
        result.push_back(a);
    }
   
    result.sort();
    result.unique();   
 
    result.pop_front();
    while (!result.empty())
    {
         cout << (result.front())<<endl;
         result.pop_front();                
    }   
}
