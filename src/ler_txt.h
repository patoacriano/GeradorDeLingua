#pragma once
#include <iostream>
#include <vector>

class LerTxt{
public:
  void gerar(std::string input);
private:
  std::vector<std::string> palavrasTxt;
  std::vector<std::string> palavrasG;
  std::vector<std::string> silabas;
};
