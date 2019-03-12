#include <bits/stdc++.h> //to include all necessary modules

// using namespace std;

int main(int argc, char const *argv[]) {

    std::iostream::sync_with_stdio(false);

    int n;

    while(std::cin >> n)
    {
        if (n == 0)
        {
            break;
        }

        std::multiset<int> bills;
        
        long long total_amount = 0;

        for(int i = 0; i < n; i++)
        {
            int k; std::cin >> k;

            for (int j = 0; j < k; j++)
            {
                int bill; std::cin >> bill;
                bills.insert(bill);
            }

            auto lowest = bills.begin();
            auto highest = bills.end();
            highest--;

            total_amount += *highest - *lowest;

            bills.erase(lowest);
            bills.erase(highest);
        }

        std::cout << total_amount << std::endl;
    }

    return 0;
}
