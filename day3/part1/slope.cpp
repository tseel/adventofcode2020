#include <iostream>
#include <fstream>
#include <vector>

using std::string, std::vector, std::ifstream, std::cout, std::endl;

int main()
{
  ifstream fin("input.txt");
  vector<string> mountain;
  string cur_line;
  while (getline(fin, cur_line)) mountain.push_back(cur_line);
  fin.close();
  int len = mountain[0].length();
  int trees = 0;
  int x = 0;
  for (string line : mountain)
  {
    trees += (line[x] == '#');
    x+=3;
    x%=len;
  }
  cout << trees << endl;
}
