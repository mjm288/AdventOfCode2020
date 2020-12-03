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
        long long treeCount = 0; //long because the end calculation is very large!
        int treeCount1 = 0;
        int treeCount2 = 0;
        int treeCount3 = 0;

        int tindex0 = 0;
        int tindex1 = 0;
        int tindex2 = 0;
        int tindex3 = 0;

        for (int i=0;i<lines.size();i++) //when stepping 1 down
        {
            //checks for match with tree
            if (lines[i][tindex0] == '#')
            {
                treeCount++;
            }
            if (lines[i][tindex1] == '#')
            {
                treeCount1++;
            }
            if (lines[i][tindex2] == '#')
            {
                treeCount2++;
            }
            if (lines[i][tindex3] == '#')
            {
                treeCount3++;
            }

            tindex0 = (tindex0 + 3) % lines[i].length(); //move 3 right
            tindex1 = (tindex1 + 1) % lines[i].length(); //move 1 right
            tindex2 = (tindex2 + 5) % lines[i].length(); //move 5 right
            tindex3 = (tindex3 + 7) % lines[i].length(); //move 7 right
        }


        int tindex4 = 0;
        int treeCount4 = 0;



        for (int i=0;i<(lines.size());i+=2)
        {
            //cout << pwds[i][tindex] << endl;
            //cout << i << pwds[i] << endl;
            //cout << i << endl;
            if (lines[i][tindex4] == '#')
            {
                //cout << i;
                treeCount4++;
            }
            tindex4 = (tindex4 + 1) % lines[i].length();

        }
        long long test1 = treeCount*treeCount1*treeCount2*treeCount3*treeCount4; //calculates products of each number of trees
        cout << test1 << endl;
        myfile.close();
    }
    else cout << "Unable to open file"; 
    return 0;
}