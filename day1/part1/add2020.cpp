#include <vector>
#include <iostream>
#include <fstream>
#include <utility>

int get_ans(const std::vector<int>);

int main()
{
  std::fstream fin("input.txt");
  std::vector<int> nums;
  int num;
  while (fin >> num) nums.push_back(num);
  fin.close();
  std::cout << get_ans(nums) << std::endl;
  return 0;
}

int get_ans(const std::vector<int> nums)
{
  for (int i: nums)
  {
    for (int j : nums)
    {
      if (i != j && 2020==i+j)
      {
        return i*j;
      }
    }
  }
  return -1;
}
