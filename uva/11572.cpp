#include <bits/stdc++.h> //to include all necessary modules

// using namespace std;

int main(int argc, char const *argv[]) {

    std::iostream::sync_with_stdio(false);

    int t; std::cin >> t;
    for (int i = 0; i < t; i++)
    {
        std::unordered_map<int, bool> packages;
        std::list<int> longest_pack;
        size_t max_unique = 0;

        int n; std::cin >> n;
        for (int j = 0; j < n; j++)
        {
            int snowflake; std::cin >> snowflake;

            if (packages[snowflake])
            {
                max_unique = std::max(max_unique, longest_pack.size());

                auto erase_until = find(longest_pack.begin(), longest_pack.end(), snowflake);
                erase_until++;

                for (auto it = longest_pack.begin(); it != longest_pack.end(); it++)
                {
                    packages[*it] = false;
                }

                longest_pack.erase(longest_pack.begin(), erase_until);
            }

            packages[snowflake] = true;
            longest_pack.push_back(snowflake);
        }

        std::cout << std::max(longest_pack.size(), max_unique) << std::endl;
    }

    return 0;
}
