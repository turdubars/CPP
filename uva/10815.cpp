#include <algorithm>
#include <cctype>
#include <iostream>
#include <set>
#include <sstream>
#include <string>

using namespace std;

// http://stackoverflow.com/questions/313970/how-to-convert-stdstring-to-lower-case

char symToSpace(char in)
{
	if(isalpha(in) != 0)
		return in;
	return ' ';
}

int main()
{
	string line;
	set<string> words;

	while(getline(cin, line))
	{
		transform(line.begin(), line.end(), line.begin(), symToSpace);
		transform(line.begin(), line.end(), line.begin(), ::tolower);

		istringstream sinp(line);
		string word;
		while(sinp >> word)
		{
			words.insert(word);
		}
	}

	for(auto w: words)
	{
		cout << w << endl;
	}

	return 0;
}
