#include <bits/stdc++.h> //to include all necessary modules

// using namespace std;

int main(int argc, char const *argv[]) {

    std::iostream::sync_with_stdio(false);

    std::set<std::string> words;
    std::set<std::string> compound_words;

    std::string line;
    while (getline(std::cin, line))
    {
        words.insert(line);
    }

    auto it = words.begin();

    for (; it != words.end(); it++)
    {
        auto iter = it;
        iter++;

        for (; iter != words.end(); iter++)
        {
            if ( (*it)[0] != (*iter)[0] ||
                 (*iter).substr(0, (*it).size()) != *it )
            {
                break;
            }

            std::string second_part = (*iter).substr((*it).size());
            // std::cout << "second_part = " << second_part << std::endl;

            if (words.find(second_part) != words.end())
            {
                compound_words.insert(*iter);
            }
        }
    }

    for (const auto &word : compound_words)
    {
        std::cout << word << std::endl;
    }

    return 0;
}
