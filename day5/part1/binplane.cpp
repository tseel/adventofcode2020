#include <iostream>
#include <fstream>

int bin_partition(int low, int high, std::string command);

int main()
{
  std::fstream fin("input.txt");
  std::string instr;
  int max_seat = -1;
  while (std::getline(fin, instr))
  {
    int row = bin_partition(0, 127, instr.substr(0, 7));
    int col = bin_partition(0, 7, instr.substr(7));
    int seat_id = row * 8 + col;
    std::cout << instr << " " << row << " " << col << " " << seat_id << std::endl;
    max_seat = max_seat < seat_id ? seat_id : max_seat;
  }
  std::cout << max_seat << std::endl;
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
