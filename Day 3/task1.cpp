#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int main() 
{
    vector<string> lines; //stores each line of the file
    string line;
    ifstream myfile ("data.txt");
    if (myfile.is_open()) //reading the file with the input data
    {

        while ( getline (myfile,line) )
        {
            lines.push_back(line); //sends data into vectosr
        }
        int treeCount = 0; //number of trees

        int tindex = 0;

        for (int i=0;i<lines.size();i++) //when stepping 1 down
        {
            //checks for match with tree
            if (lines[i][tindex] == '#')
            {
                treeCount++;
            }

            tindex = (tindex + 3) % lines[i].length(); //move 3 right
        }
        cout << treeCount << endl;
        myfile.close();
    }
    else cout << "Unable to open file"; 
    return 0;
}