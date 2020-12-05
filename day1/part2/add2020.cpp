#include <vector>
#include <iostream>
#include <fstream>
#include <utility>

int get_ans(const std::vector<int>);
int distinct(const int, const int, const int);

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
      for (int k : nums)
      {
        if (distinct(i,j,k) && 2020==i+j+k)
        {
          return i*j*k;
        }
      }
    }
  }
  return -1;
}

int distinct(const int i, const int j, const int k)
{
  return i!=j && j!=k && i!=k;
}
