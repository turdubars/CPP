#include <bits/stdc++.h> //to include all necessary modules

// using namespace std;

char convert_to_space(char ch)
{
    if (isalpha(ch) != 0 or ch == '-')
    {
        return ch;
    }
    return ' ';
}

int main(int argc, char const *argv[]) {

    std::iostream::sync_with_stdio(false);

    std::set<std::string> words;

    std::string line;
    std::string parsed_word;

    std::string pre_word;
    bool is_continued = false;

    while (getline(std::cin, line))
    {
        std::transform(line.begin(), line.end(), line.begin(), convert_to_space);
        std::transform(line.begin(), line.end(), line.begin(), ::tolower);
        // parsed_word = boost::algorithm::to_lower(parsed_word);

        std::istringstream sinp(line);

        while(sinp >> parsed_word)
        {
            if (is_continued)
            {
                is_continued = false;
                parsed_word = pre_word + parsed_word;
            }
            if (parsed_word.back() == '-' and sinp.eof())
            {
                parsed_word.pop_back();
                pre_word = parsed_word;
                is_continued = true;
            }
            if (!is_continued)
            {
                words.insert(parsed_word);
            }
        }
    }

    for (const auto &elem : words)
    {
        std::cout << elem << std::endl;
    }

    // std::cout << "line_counter = " << line_counter << std::endl;
    // std::cout << "You are here" << std::endl;

    return 0;
}
