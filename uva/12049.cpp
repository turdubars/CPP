#include <bits/stdc++.h> //to include all necessary modules

// using namespace std;

int main(int argc, char const *argv[]) {

    std::iostream::sync_with_stdio(false);

    int t; std::cin >> t;

    for(int i = 0; i < t; i++)
    {
        int n; std::cin >> n;
        int m; std::cin >> m;

        std::unordered_map<int, int> first_list;
        // std::unordered_map<int, int> second_list;

        for (int j = 0; j < n; j++)
        {
            int num; std::cin >> num;
            first_list[num]++;
        }

        for (int j = 0; j < m; j++)
        {
            int num; std::cin >> num;
            first_list[num]--;
        }

        int counter = 0;

        for (auto x : first_list)
        {
            // std::cout << "x.first = " << x.first << std::endl;
            // std::cout << "x.second = " << x.second << std::endl;

            if (x.second != 0)
            {
                counter += abs(x.second);
            }
        }

        std::cout << counter << std::endl;
    }

    return 0;
}
