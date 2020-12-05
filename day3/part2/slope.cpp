#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>

using std::string, std::vector, std::ifstream, std::cout, std::endl;

class slope {
public:
  int right;
  int down;
  slope(int r, int d): right(r), down(d){}
};

int main()
{
  ifstream fin("input.txt");
  vector<string> mountain;
  string cur_line;
  while (getline(fin, cur_line)) mountain.push_back(cur_line);
  fin.close();
  int len = mountain[0].length();
  vector<slope> slopes{slope(1,1), slope(3,1), slope(5,1), slope(7,1), slope(1,2)};
  vector<int> tree_list;
  for (auto slope : slopes)
  {
    int x = 0;
    int trees = 0;
    for (auto y = 0; y < mountain.size(); y += slope.down)
    {
      trees += (mountain[y][x] == '#');
      x+=slope.right;
      x%=len;
    }
  tree_list.push_back(trees);
  }
  unsigned long product = std::accumulate(tree_list.begin(), tree_list.end(), 1, std::multiplies<int>());
  cout << product << endl;
}
