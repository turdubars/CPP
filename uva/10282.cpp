#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
	unordered_map<string, string> dictionary;

	string input;

	while(getline(cin, input) && input != "")
	{
		istringstream sinp(input);
		string eng; sinp >> eng;
		string dia; sinp >> dia;

		dictionary[dia] = eng;
	}

	while(getline(cin, input))
	{
		cout << ((dictionary[input] == "") ? "eh" : dictionary[input]) << endl;
	}

	return 0;
}
