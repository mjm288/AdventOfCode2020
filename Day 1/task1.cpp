#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
int main() 
{
    vector<int> entries;
    map<int, int> values;
    string line;
    ifstream myfile ("data.txt");
    if (myfile.is_open()) //reading the file with the input data
    {
        while ( getline (myfile,line) )
        {
        entries.push_back(stoi(line)); //sends data into vector
        }
        myfile.close();
    }
    else cout << "Unable to open file"; 

    for (int i=0;i<entries.size();i++) //loops through vector
    { //uses hashmap to check for a matching element that sums to 2020
        if (values.find(2020 - entries[i]) != values.end()) 
        {
            cout << (2020 - entries[i]) * entries[i];
        }
        values[entries[i]] = i; //adds vector element to hashmap
    }
    return 0;
}