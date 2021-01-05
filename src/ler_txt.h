#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class LerTxt{
public:
  void gerar(std::string input);
private:
  std::vector<std::string> palavrasTxt;
  std::vector<std::string> palavrasG;
  std::vector<std::string> silabas;
};
