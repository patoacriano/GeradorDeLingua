#include <iostream>
#include <fstream>
using namespace std;

int main(){

  while(1 == 1){
    string linhas;
    int qntlinhas = 0;
    ifstream read;
    read.open("silabas.txt");
    while(getline(read,linhas)){
        qntlinhas ++;
    }
    read.close();
    int nmr = 0;
    string silabas[qntlinhas] = {};
    ifstream arq;
    arq.open("silabas.txt");
    while(!arq.eof()){
      string pal;
      arq>>pal;
      silabas[nmr] = pal;
      nmr++;
    }
    arq.close();
    string silabaN;
    int exst = 0;
    cout<<"\n\nEscreva a silaba que voce deseja adicionar: ";
    cin>>silabaN;
    for(int i = 0; i < qntlinhas;i++){
      if(silabas[i] == silabaN){
        exst = 1;
      }
    }
    if(exst == 0){
      ofstream input;
      input.open("silabas.txt",ios::app);
      input<<endl<<silabaN;
      cout<<"Silaba adicionada\n\n";
    }
    else if(exst == 1){
      cout<<"Essa silaba ja existe, tente outra\n";
    }
  }


  return 0;
}
