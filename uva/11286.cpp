#include <bits/stdc++.h> //to include all necessary modules

// using namespace std;

int main(int argc, char const *argv[]) {

    std::iostream::sync_with_stdio(false);

    int n;

    while(std::cin >> n and n != 0)
    {
        std::map<std::set<int>, int> combinations;

        for (int i = 0; i < n; i++)
        {
            std::set<int> courses;

            for (int j = 0; j < 5; j++)
            {
                int course; std::cin >> course;
                courses.insert(course);
            }

            combinations[courses]++;
        }

        int max = 0;
        int conform = 0;

        for (auto elem : combinations)
        {
            if (elem.second > max)
            {
                max = elem.second;
            }
        }

        for (auto elem: combinations)
        {
            if (elem.second == max)
            {
                conform++;
            }
        }

        std::cout << max*conform << std::endl;
    }

    return 0;
}
