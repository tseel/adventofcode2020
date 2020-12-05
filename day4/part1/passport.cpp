#include <fstream>
#include <iostream>
#include <sstream>

bool is_valid_passport(std::string passport);

 int main() {
  std::ifstream fin("input.txt");
  std::string line;
  int valid_count;
  while (std::getline(fin, line))
  {
    std::stringstream passport;
    while (line != "")
    {
      passport << line << " ";
      std::getline(fin, line);
    }
    valid_count += is_valid_passport(passport.str());
  }
  fin.close();
  std::cout << valid_count << std::endl;
}

bool is_valid_passport(std::string passport)
{
  std::cout << passport << std::endl;
  return passport.find("byr:") != std::string::npos &&
         passport.find("iyr:") != std::string::npos &&
         passport.find("eyr:") != std::string::npos &&
         passport.find("hgt:") != std::string::npos &&
         passport.find("hcl:") != std::string::npos &&
         passport.find("ecl:") != std::string::npos &&
         passport.find("pid:") != std::string::npos;
}
