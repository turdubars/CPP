#include <bits/stdc++.h> //to include all necessary modules

// using namespace std;

int main(int argc, char const *argv[]) {

    std::iostream::sync_with_stdio(false);

    std::unordered_map<std::string, int> parties;

    int p, g;
    std::string line;

    getline(std::cin, line);
    std::istringstream sinp(line);

    sinp >> p >> g;

    for (int i = 0; i < p; i++)
    {
        getline(std::cin, line);
        std::istringstream sinp(line);

        std::string party; sinp >> party;
        float vote; sinp >> vote;

        parties[party] = (int)(vote * 10);
    }

    // for (auto elem : parties)
    // {
    //     std::cout << elem.first << " " << elem.second << std::endl;
    // }
    for (int i = 0; i < g; i++)
    {
        int total = 0;
        int comp = 0;

        bool guess = false;
        std::string token;

        getline(std::cin, line);
        std::istringstream sinp(line);

        while (sinp >> token)
        {
            if (token == "+")
            {
                continue;
            }
            if (token == "<")
            {
                sinp >> token;
                comp = stoi(token) * 10;
                guess = (total < comp);
                break;
            }
            else if (token == ">")
			{
				sinp >> token;
				comp = stoi(token) * 10;
				guess = (total > comp);
				break;
			}
			else if (token == "<=")
			{
				sinp >> token;
				comp = stoi(token) * 10;
				guess = (total <= comp);
				break;
			}
			else if (token == ">=")
			{
				sinp >> token;
				comp = stoi(token) * 10;
				guess = (total >= comp);
				break;
			}
			else if (token == "=")
			{
				sinp >> token;
				comp = stoi(token) * 10;
				guess = (total == comp);
				break;
			}
			else if (!sinp.eof())
			{
				total += parties[token];
			}
        }
        std::cout << "Guess #" << i+1 << " was " << (guess ? "correct." : "incorrect.") << std::endl;
    }

    return 0;
}
