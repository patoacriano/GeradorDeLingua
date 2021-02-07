#pragma once
#include <vector>
#include <iostream>

class gerarPal{
public:
  void gerar(bool arquivo);
  std::vector<std::string> getPalavrasG();
  void salvar();

private:
  std::vector<std::string> silabas;
  std::vector<std::string> palavrasG;//Caso a pessoa decida salvar a palavra
  std::vector<std::string> palavrasP;
};
