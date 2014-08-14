/*
    1061 - Consanguine Calculations
    13/08/2014
*/

#include <iostream>
#include <string>
#include <list>
using namespace std;
 
void getPossibleChild   (string p1, char p1Rh, string p2, char p2Rh);
string findOutParent    (string p, char pRh, string child, char childRh);
 
string ABOTable [4][4][4] =
{{ {"O"},       {"A", "O"},             {"B", "O"},             {"A", "B"}        },
 { {"A", "O"},  {"A", "O"},             {"A", "B", "AB", "O"},  {"A", "B", "AB"}  },
 { {"B", "O"},  {"A", "B", "AB", "O"},  {"B", "O"},             {"A", "B", "AB"}  },
 { {"A", "B"},  {"A", "B", "AB"},       {"A", "B", "AB"},       {"A", "B", "AB"}  }};    


enum ABOType
{
   O,
   A,
   B,
   AB
}; 
 
int main ()
{    
    int caseIndex = 1;
    while (cin.good())
    {
        string p1;
        char p1Rh;
        string p2;
        char p2Rh;
        string child;
        char childRh;        
       
        cin >> p1;
        cin >> p2;
        cin >> child;
       
        if (p1 == "E") // end of stream
            return 0;       
        
        cout << "Case " << caseIndex << ": ";
        caseIndex++;
       
       
        if (p1 != "?")
        {
            p1Rh = p1.at(p1.size()-1); // getRh char        
            p1 = p1.erase (p1.size()-1); // remove Rh from string
        }
       
        if (p2 != "?")
        {
            p2Rh = p2.at(p2.size()-1);        
            p2 = p2.erase (p2.size()-1);
        }
       
        if (child != "?")
        {
            childRh = child.at(child.size()-1);        
            child = child.erase (child.size()-1);
        }
        //cout << p1 << " ";
        //cout << p1Rh << endl;  
       
        if (child == "?")
        {
            cout << p1 << p1Rh << " "<< p2 << p2Rh << " ";
            getPossibleChild (p1, p1Rh, p2, p2Rh);
        }
        else { 
            if (p1 == "?")
            {
                cout << findOutParent (p2, p2Rh, child, childRh) <<" "<< p2 << p2Rh <<" "<< child << childRh << endl;
            }
            else 
            {
                if (p2 == "?")
                {
                    cout << p1 << p1Rh <<" "<< findOutParent (p1, p1Rh, child, childRh) <<" " << child << childRh<<endl;
                }
            }
        }
    }
}
 
 
 
void getPossibleChild(string p1, char p1Rh, string p2, char p2Rh)
{
    int p1Index;
    int p2Index;
    list <string> solution;
    string output = "";
    // getting indexes
    if (p1 == "O")
        p1Index = O;
    else
        if (p1 == "A")
            p1Index = A;
        else
            if (p1 == "B")
                 p1Index = B;
            else
                if (p1 == "AB")
                    p1Index = AB;                   
   
    if (p2 == "O")
        p2Index = O;
    else
        if (p2 == "A")
            p2Index = A;
        else
            if (p2 == "B")
                p2Index = B;
            else
                if (p2 == "AB")
                    p2Index = AB;
                    
     
     
     if (p1Rh == '-' && p2Rh == '-' )
     {

            int i = 0;              
            while (ABOTable [p1Index][p2Index][i] != "")
            {
                    string temp = "";
                    temp.append(ABOTable [p1Index][p2Index][i]);
                    temp.append("-");
                    solution.push_back(temp);
                    i++;
            }
     }     
     else
     {      
        int i = 0;              
        while (ABOTable [p1Index][p2Index][i] != "")
        {
            string temp = "";
            temp.append(ABOTable [p1Index][p2Index][i]);
            temp.append("-");
            solution.push_back(temp);
            string temp2 = "";
            temp2.append(ABOTable [p1Index][p2Index][i]);
            temp2.append("+");
            solution.push_back(temp2);
                       
            i++;
        }    
    }     
     
     solution.sort();
     solution.unique();
     
     if (solution.size() == 1)
            output.append(solution.front());
        else
        {
            output = "{";
            while (!solution.empty())
            {
                output.append(solution.front());
                solution.pop_front();
                if (solution.size()!=0)
                    output.append(", ");
            }
            output.append("}");
        }
     
     cout << output;
     cout << endl;
     return ;    
}

string findOutParent (string p, char pRh, string child, char childRh)
{   
    int pIndex;
    string output;
    list <string> solution;

    if (p == "O")
        pIndex = O;
    else
        if (p == "A")
            pIndex = A;
        else
            if (p == "B")
                 pIndex = B;
            else
                if (p == "AB")
                    pIndex = AB;     

    if (pRh == '-' && childRh == '+')
    {
        int i = 0;              
        while (ABOTable [pIndex][O][i] != "")
        {                          
            if (ABOTable [pIndex][O][i] == child)
            {
                //cout << "O-";
                solution.push_back("O+");           
            }
            i++;
        }
        
        i=0;
        while (ABOTable [pIndex][A][i] != "")
        {                          
            if (ABOTable [pIndex][A][i] == child)
            {
                //cout << "A-";   
                solution.push_back("A+");        
            }
            i++;
        }
        
        i=0;
        while (ABOTable [pIndex][B][i] != "")
        {                          
            if (ABOTable [pIndex][B][i] == child)
            {
                //cout << "B-"; 
                solution.push_back("B+");          
            }
            i++;
        }
        
        i=0;
        while (ABOTable [pIndex][AB][i] != "")
        {                          
            if (ABOTable [pIndex][AB][i] == child)
            {
                //cout << "AB-";           
                solution.push_back("AB+");
            }
            i++;
        }    
    }
    else 
    {
        int i = 0;              
        while (ABOTable [pIndex][O][i] != "")
        {                          
            if (ABOTable [pIndex][O][i] == child)
            {
                //cout << "O-";
                solution.push_back("O-"); 
                solution.push_back("O+");           
            }
            i++;
        }
        
        i=0;
        while (ABOTable [pIndex][A][i] != "")
        {                          
            if (ABOTable [pIndex][A][i] == child)
            {
                //cout << "A-";   
                solution.push_back("A-");
                solution.push_back("A+");         
            }
            i++;
        }
        
        i=0;
        while (ABOTable [pIndex][B][i] != "")
        {                          
            if (ABOTable [pIndex][B][i] == child)
            {
                //cout << "B-"; 
                solution.push_back("B-");
                solution.push_back("B+");           
            }
            i++;
        }
        
        i=0;
        while (ABOTable [pIndex][AB][i] != "")
        {                          
            if (ABOTable [pIndex][AB][i] == child)
            {
                //cout << "AB-";
                           
                solution.push_back("AB-");
                solution.push_back("AB+"); 
            }
            i++;
        } 
    
    }
    solution.sort();
    solution.unique();
    
    if (solution.size() == 0)
        output = "IMPOSSIBLE";   
    else
        if (solution.size() == 1)
            output.append(solution.front());
        else
        {
            output = "{";
            while (!solution.empty())
            {
                output.append(solution.front());
                solution.pop_front();
                if (solution.size()!=0)
                    output.append(", ");
            }
            output.append("}");
        }
    
    return output;
}







