#include <iostream>
#include <map>
#include <set>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    map<string, set<int>> m;
    
    int nLines = 0;
    string line;
    while (getline(cin, line))
    {
        ++nLines;
        istringstream sinp(line);
        string w;
        while (sinp >> w)
        {
            m[w].insert(nLines);
        }
    }
    
    for (const auto& p: m)
    {
        cout << p.first << ":";
        for (const auto& i: p.second)
        {
            cout << " " << i;
        }
        cout << endl;
    }        
}
