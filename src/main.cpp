#include <iostream>
#include <fstream>
#include "gerar_pal.h"
#include "ler_txt.h"

/*
*TODO:
* [ ] - Adicionar Dicionario:
*    caso a pessoa queira que a mesma palavra
*    continue tendo a mesma tradução, ela poderá
*    utilizar um dicionario salvo por ela.
*    Tambem será necessario adicionar uma maneira
*    de adicionar palavras a um dicionario ja criado
*    EXEMPLO: a palavra "Amendoin" pode se tornar
*    "Calebo", desse modo, caso a pessoa queira
*    utilizar outro texto que contenha a palavra
*    amendoin, com esse mesmo dicionario, a palavra
*    "Amendoin" se tornará "Calebo".
*
*/


void help(){
    std::cout<<"\n--Bem vindo ao gerador de lingua--\n";
    std::cout<<"\n\n\nLEMBRE-SE, ao executar o programa em uma pasta diferente\n";
    std::cout<<"é necessario que o arquivo \"silabas.txt\" esteja na mesma pasta\n\n\n";
    std::cout<<"\n -i <nome_do_arquivo> \t usado para traduzir um arquivo";
    std::cout<<" gerando um dicionario e o arquivo traduzido\n";
    std::cout<<"\n -silaba \t inicia o gerador no modo de adicionar mais ";
    std::cout<<"silabas ao arquivo silabas.txt";
    std::cout<<"\n -d \t força o uso de um dicionario especifico";
    std::cout<<"\n --overwrite \t Faz com que o dicionario ja criado";
    std::cout<<" anteriormente seja reescrito, caso não seja passada";
    std::cout<<" essa opção, o programa apenas acrescentará informação";
    std::cout<<" à um dicionario ja existente, caso exista\n";
}


int main(int argc, char** argv){

    bool argumentos = false, salvar = false, rewrite = false;
    int op;
            //Decide o que vai ser feito
            //1: lê um txt
            //2: adiciona silaba
            //3: (TODO)adiciona/salva/usa dicionario
    std::string input, output="DEFAULT", nome, dicionario = "DEFAULT";
    std::vector<std::string> palavrasG;
    gerarPal ger;
    LerTxt ler;

    if(argc > 1){
    for(int i = 0; i<argc; i++){
        std::string _arg = argv[i];
        if(_arg == "-i"){input = argv[i+1]; op = 1;}
        else if(_arg == "-o") output = argv[i+1];
        else if(_arg == "-nome") nome = argv[i+1];
        else if(_arg == "-silaba") op = 3;
        else if(_arg == "-d") {dicionario = argv[i+1]; op+=1;}
        else if(_arg == "--help") help();
        else if(_arg == "--rewrite") rewrite = true;
    }
        switch(op){
        case 1:
            ler.gerar(input, rewrite);
            break;
        case 2:
            ler.dicionario(input, dicionario);
            break;

        default:
            break;
        }
    }
    else{
        while(!salvar){
            ger.gerar(false);
            std::cout<<"Voce deseja salvar as palavras geradas ate agora?\n[1]-sim\n[2]-nao\n> ";
            int esc;
            std::cin>>esc;
            if(esc == 1)
                salvar = true;
        }
        ger.salvar();

    }


    return 0;
}
