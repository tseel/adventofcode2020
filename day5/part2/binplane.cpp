#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

int bin_partition(int low, int high, std::string command);
int find_my_seat(std::vector<int>& seat_vector);

int main()
{
  std::fstream fin("input.txt");
  std::string instr;
  std::vector<int> seat_vector;
  while (std::getline(fin, instr))
  {
    int row = bin_partition(0, 127, instr.substr(0, 7));
    int col = bin_partition(0, 7, instr.substr(7));
    int seat_id = row * 8 + col;
    seat_vector.push_back(seat_id);
  }
  std::cout << find_my_seat(seat_vector) << std::endl;
}


int bin_partition(int low, int high, std::string command)
{
  if (!command.size())
    return low;
  int size = high - low + 1;
  if (command[0] == 'R' || command[0] == 'B')
  {
    return bin_partition(low + size/2, high, command.substr(1));
  }
  else if (command[0] == 'L' || command[0] == 'F')
  {
    return bin_partition(low, high - size/2, command.substr(1));
  }
  return -1;
}

int find_my_seat(std::vector<int>& seat_vector)
{
  std::sort(seat_vector.begin(), seat_vector.end());
  for (int i = 0; i < seat_vector.size(); i++)
  {
    if (seat_vector[i]+2 == seat_vector[i+1]) return seat_vector[i]+1;
  }
  return -1;
}
