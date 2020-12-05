#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>

using std::ifstream, std::cout, std::endl, std::string, std::stringstream;

int main()
{
  int lines;
  ifstream fin("input.txt");
  int valid = 0;
  int loops = 0;
  string instr;
  while (getline(fin, instr, '\n'))
  {
    stringstream ss(instr);
    int first, second;
    char c;
    string pass;
    ss >> first;
    ss.ignore(1,'-');
    ss >> second;
    ss >> c;
    ss.ignore(1,':');
    ss >> pass;
    valid += ((pass[first-1] == c) ^ (pass[second-1] == c));
  }
  fin.close();
  cout << valid << endl;
  return 0;
}
