#include <bits/stdc++.h> //to include all necessary modules

using namespace std;

int main(int argc, char const *argv[]) {

    iostream::sync_with_stdio(false);

    string line;
    while (getline(cin, line))
    {
        list<char> text;
        auto current = text.begin();

        for (char c: line)
        {
            if (c == '[')
            {
                current = text.begin();
            }
            else if (c == ']')
            {
                current = text.end();
            }
            else
            {
                text.insert(current, c);
            }
        }

        cout << string(text.begin(), text.end()) << endl;
    }

    return 0;
}
