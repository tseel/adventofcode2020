#include <unordered_set>
#include <iostream>
#include <fstream>
#include <cctype>

int main()
{
  std::ifstream fin("input.txt");
  std::string line;
  int sum_answers = 0;
  while (std::getline(fin, line))
  {
    std::unordered_set<int> answers;
    while (line != "")
    {
      for (char c : line)
      {
        if (std::isalpha(c))
        {
          answers.insert(c);
        }
      }
      std::getline(fin, line);
    }
    sum_answers += answers.size();
  }

 std::cout << sum_answers << '\n';
  fin.close();

}
