#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_set>
#include <map>

bool is_valid_passport(std::string passport);
bool is_valid_color(std::string color);
bool is_valid_height(std::string ht);

 int main() {
  std::ifstream fin("input.txt");
  std::string line;
  int valid_count = 0;
  while (std::getline(fin, line))
  {
    std::stringstream passport;
    while (line != "")
    {
      // need to replace colons with spaces to facilitate putting into map later
      std::replace(line.begin(), line.end(), ':', ' ');
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
  std::stringstream passstream(passport);
  std::map<std::string, std::string> passmap;
  std::string tempkey, tempval;
  while(passstream >> tempkey >> tempval)
  {
    passmap[tempkey] = tempval;
  }
  // return false if not all of the necessary fields exist
  auto mapcontains = [passmap](std::string s){return passmap.find(s) != passmap.end();};
  if (!mapcontains("byr") || !mapcontains("iyr") || !mapcontains("eyr") || !mapcontains("hcl") || !mapcontains("hgt") || !mapcontains("ecl") || !mapcontains("pid"))
    return false;

  bool valid = true;

  int birthyear = std::stoi(passmap["byr"]);
  valid = valid && (birthyear >= 1920 && birthyear <= 2002);

  int issueyear = std::stoi(passmap["iyr"]);
  valid = valid && (issueyear >= 2010 && issueyear <= 2020);

  int expyear = std::stoi(passmap["eyr"]);
  valid = valid && (expyear >= 2020 && expyear <= 2030);

  valid = valid && is_valid_height(passmap["hgt"]);

  valid = valid && is_valid_color(passmap["hcl"]);

  std::unordered_set<std::string> valid_eye_color {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
  valid = valid && valid_eye_color.find(passmap["ecl"]) != valid_eye_color.end();

  valid = valid && passmap["pid"].size() == 9;

  return valid;
}

bool is_valid_color(std::string color)
{
  bool valid = true;
  valid = valid && color.size() == 7;
  valid = valid && color[0] == '#';
  for (int i = 1; i < color.size(); i++)
  {
    valid = valid && ((color[i] >= 'a' && color[i] <= 'f') || (color[i] >= '0' && color[i] <= '9'));
  }
  return valid;
}

bool is_valid_height(std::string ht)
{
  int unit_loc = ht.size()-2;
  std::string unit = ht.substr(unit_loc);
  int height = std::stoi(ht.substr(0, unit_loc));

  if (unit == "cm")
  {
    return height >= 150 && height <= 193;
  }
  else if (unit == "in")
  {
    return height >= 59 && height <= 76;
  }
  return false;
}
