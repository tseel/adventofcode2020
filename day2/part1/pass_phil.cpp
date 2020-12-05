#include <iostream>
#include <fstream>
#include <algorithm>

using std::ifstream, std::cout, std::endl, std::string;

int main()
{
  int lines;
  ifstream fin("input.txt");
  int valid = 0;
  while (!fin.eof())
  {
    int mini, maxi;
    char c;
    string pass;
    fin >> mini;
    fin.ignore(1,'-');
    fin >> maxi;
    fin >> c;
    fin.ignore(1,':');
    fin >> pass;
    int char_count = std::count(pass.begin(), pass.end(), c);
    valid += (char_count >= mini && char_count <= maxi);
  }
  fin.close();
  cout << valid << endl;
  return 0;
}
