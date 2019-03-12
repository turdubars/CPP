#include <bits/stdc++.h> //to include all necessary modules

// using namespace std;

bool is_battle_finished(std::multiset<int> first, std::multiset<int> second)
{
    auto it_first = first.begin();
    auto it_second = second.begin();

    if (*it_first == 0 or *it_second == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(int argc, char const *argv[]) {

    std::iostream::sync_with_stdio(false);

    std::multiset<int> greens;
    std::multiset<int> blues;

    int n; std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        int battlefields, sg, sb;
        std::cin >> battlefields >> sg >> sb;

        for (int j = 0; j < sg; j++)
        {
            int temp; std::cin >> temp;
            greens.insert(temp);
        }

        for (int j = 0; j < sb; j++)
        {
            int temp; std::cin >> temp;
            blues.insert(temp);
        }

        int min = std::min(greens.size(), blues.size());
        int active_battlefields = std::min(min, battlefields);

        while (is_battle_finished(greens, blues))
        {
            std::vector<int> winners;

            auto it_g = greens.begin();
            auto it_b = blues.begin();
            for (int j = 0; j < active_battlefields; j++)
            {
                int winner = *it_g - *it_b;

                winners.push_back(winner);

                greens.erase(it_g);
                blues.erase(it_b);

                it_g++;
                it_b++;
            }

            for (int j = 0; j < winners.size(); j++)
            {
                if (winners[j] > 0)
                {
                    greens.insert(winners[j]);
                    blues.insert(0);
                }
                else if (winners[j] < 0)
                {
                    greens.insert(0);
                    blues.insert(abs(winners[j]));
                }
                else
                {
                    greens.insert(0);
                    blues.insert(0);
                }
            }
        }


        for (auto elem : greens)
        {
            std::cout << elem << std::endl;
        }

        for (auto elem : blues)
        {
            std::cout << elem << std::endl;
        }
    }

    return 0;
}
