#include <iomanip>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	map<string, int> treesMap;
	int numOfCase, totalTrees;
	string input;

	getline(cin, input);
	numOfCase = stoi(input);
	getline(cin, input); // ignore first empty line

	for(int i = 0; i < numOfCase; ++i)
	{
		totalTrees = 0;
		treesMap.clear();

		while(getline(cin, input) && input != "")
		{
			++treesMap[input];
			++totalTrees;
		}

		for(const auto& tree: treesMap)
		{
			double ratio = tree.second * 100.0 / totalTrees;
			cout << tree.first << " " << fixed << setprecision(4) << ratio << endl;
		}

		if(i != numOfCase-1)
			cout << endl;
	}

	return 0;
}
