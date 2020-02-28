#include <iostream>
#include <fstream>
using namespace std;

int esc,qntR = 0,salv;
bool rodando = true;
void gerarPal();
string palIn[] = {}, palGer[] = {},lingua,abrev;
void salvar();

int main(){
  cout<<endl<<"Seja bem vindo! Esse programa consiste basicamente em voce fornecer uma palavra da lingua portuguesa e o programa irá criar uma nova palavra, de acordo com as silabas que estaão no arquivo \"silabas.txt\", que corresponderá à palavra que você forneceu em português.\nCaso voce deseje adicionar uma nova silaba, você pode adicionar manualmente no arquivo (Nesse caso, tenha certeza que a ultima linha não é uma linha vazia, isso pode causar bugs no programa), ou compilar e rodar o arquivo \"AdicionarSilabas.cpp\", ao compilar e rodar esse arquivo, você poderá adicionar silabas mais facilmente e ele verificará se a silaba fornecida já foi adicionada.\n\nTenha bom proveito do programa\n\n";
  cout<<"Voce desejará salvar essa lingua em um arquivo txt?\n[1]-Sim\n[2]-Não\n>";
  cin>>salv;
  if(salv == 1){

    cout<<endl<<"Dê um nome à sua lingua\n>";
    cin.ignore();
    getline(cin,lingua);
    cout<<endl<<"Dê uma abreviação para sua lingua. Ex.: PT-BR, FR, ING...\n>";
    cin>>abrev;
  }
  while(rodando == true){
    cout<<"\t[1]-Gerar palavra\n\t[3]-Sair\n\t>";
    cin>>esc;
    if(esc == 1){
      gerarPal();
    }
    if(esc == 3)
      rodando = false;
    }


  return 0;
}



void gerarPal(){
  //Pega a quantidade de linhas que o arquivo silabas.txt vai ter.
  string linhas;
  int qntlinhas = 0;
  ifstream arq;
  arq.open("silabas.txt");
  while(getline(arq,linhas))
    qntlinhas+=1;
  arq.close();
  //adiciona as silabas do arquivo a uma array.

  string silabas[qntlinhas] = {};
  int nmr = 0;
  ifstream input;
  input.open("silabas.txt");
  while(!input.eof()){
    string pal;
    input>>pal;
    silabas[nmr] = pal;
    nmr++;
  }
  input.close();


  // for(int i = 0; i < qntlinhas; i ++){
  //   cout<<silabas[i]<<" ";
  // }
  // cout<<endl;
  string palP,palG;//palavra da pessoa e palavra gerada
  int tmnP,tmnG;

  cout<<"Digite a palavra que voce deseja mudar: ";
  cin>>palP;
  if(palP.length()>5)
    tmnP = palP.length()/2;
  if(palP.length()<=4)
    tmnP = palP.length();

  srand(time(NULL));
  tmnG = rand()%tmnP+1;
  while(tmnP>3 && tmnG<2){
    tmnG = rand()%tmnP+1;
  }
  string silabasG[tmnG] = {};
  for(int i = 0;i < tmnG;i++){
    silabasG[i] = silabas[rand()%qntlinhas+1];
    palG += silabasG[i];
  }
  cout<<"A nova palavra gerada a partir de \" "<<palP<<" \" é: "<<palG<<endl;
  if(salv == 1){
    ofstream save;
    save.open(lingua+".txt",ios::app);
    save<<"\nBR: "<<palP<<" | "<<abrev<<": "<<palG<<endl;
    save.close();

  }

}
