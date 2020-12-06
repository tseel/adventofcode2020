#include <vector>
#include <iostream>
#include <fstream>
#include <cctype>

int common_answers(std::vector<std::string> ans);

bool is_common_answer(std::vector<std::string> ans, char a);


int main()
{
  std::ifstream fin("input.txt");
  std::string line;
  int sum_answers = 0;
  while (std::getline(fin, line))
  {
    std::vector<std::string> answers;
    while (line != "")
    {
      answers.push_back(line);
      std::getline(fin, line);
    }
    sum_answers += common_answers(answers);
  }
  std::cout << sum_answers << '\n';
  fin.close();
}

int common_answers(std::vector<std::string> ans)
{
  int common = 0;
  for (char c : ans[0])
  {
    common += is_common_answer(ans, c);
  }
  return common;
}

bool is_common_answer(std::vector<std::string> ans, char a)
{
  for (int i = 1; i < ans.size(); i++)
  {
    if (ans[i].find(a) == std::string::npos) return false;
  }
  return true;
}
