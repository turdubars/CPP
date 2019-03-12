#include <bits/stdc++.h> //to include all necessary modules

// using namespace std;

int main(int argc, char const *argv[]) {

    std::iostream::sync_with_stdio(false);

    std::stack<int> stack_x;
    std::unordered_set<int> set_x;
    std::unordered_map<int, int> map_x;

    int x;

    while (std::cin >> x)
    {
        map_x[x]++;
        auto inserted_pair = set_x.insert(x);
        // std::cout << "inserted_pair = " << inserted_pair.second << std::endl;
        if (inserted_pair.second == true)
        {
            stack_x.push(x);
        }
    }

    // std::cout << set_x[0] << std::endl;

    // Printing content of stack
    while (!stack_x.empty()) {
        int temp = stack_x.top();
        // std::cout << temp << std::endl;
        stack_x.pop();
        std::cout << temp << " " << map_x[temp] << std::endl;
    }

    return 0;
}
