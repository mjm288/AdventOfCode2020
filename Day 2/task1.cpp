#include <iostream>
#include <vector>
#include <fstream>
#include <regex>
using namespace std;
int main() 
{
    vector<string> pwds; //stores each password in the file
    string line;
    ifstream myfile ("data.txt");
    if (myfile.is_open()) //reading the file with the input data
    {
        while ( getline (myfile,line) )
        {
        pwds.push_back(line); //sends data into vector
        }
        myfile.close();
    }
    else cout << "Unable to open file"; 

    //smatch m;
    int validCount = 0;

    for (int i=0;i<pwds.size();i++) //loops through vector
    { 
        regex e("\\s"); //regular expression to find spaces
        smatch m;
        regex_search(pwds[i], m, e);
        string policy = pwds[i].substr(0, m.position()); //password policy
        //cout << policy << endl;
        char letter = pwds[i].substr(m.position() + 1, m.position() + 2)[0];
        string pwd = pwds[i].substr(m.position() + 4); //password itself
        regex f("-"); //regular expression finds lower and upper bound from policy
        regex_search(policy, m, f);
        int lower = stoi(policy.substr(0, m.position()));
        int upper = stoi(policy.substr(m.position() + 1));
        int count = 0;
        for (auto x: pwd) //loops through characters in the password
        {
            if (x == letter) //if the letter is in the password then increment count by 1
            {
                count++;
            }
        }
        if ((count >= lower) && (count <= upper)) {validCount++;} //if the number of letters is within the valid range then the password is valid
    }
    cout << validCount;
    return 0;
}