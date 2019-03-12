#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
	unordered_map<string, string> slogans;

	int n, q;
	string input, firstPart, secondPart;

	getline(cin, input);
	n = stoi(input);

	for(int i = 0; i < n; ++i)
	{
		getline(cin, firstPart);
		getline(cin, secondPart);

		slogans[firstPart] = secondPart;
	}

	getline(cin, input);
	q = stoi(input);

	for(int i = 0; i < q; ++i)
	{
		getline(cin, input);
		cout << slogans[input] << endl;
	}

	return 0;
}
