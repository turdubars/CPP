#include <bits/stdc++.h> //to include all necessary modules

// using namespace std;

int main(int argc, char const *argv[]) {

    std::iostream::sync_with_stdio(false);

    while (true)
    {
        int n; std::cin >> n;
        int m; std::cin >> m;

        if (n == 0 and m == 0)
        {
            break;
        }

        std::unordered_set<int> jack;
        // std::unordered_set<int> jill;
        int counter = 0;

        for(int i = 0; i < n; i++)
        {
            int disk; std::cin >> disk;
            jack.insert(disk);
        }

        for(int i = 0; i < m; i++)
        {
            int disk; std::cin >> disk;
            auto is_found = jack.find(disk);

            // std::cout << is_found << std::endl;

            if (is_found != jack.end())
            {
                counter++;
            }
        }

        std::cout << counter << std::endl;
    }


    return 0;
}
