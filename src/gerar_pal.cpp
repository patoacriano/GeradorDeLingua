#include <fstream>
#include <iostream>
#include <vector>

#include "gerar_pal.h"

void gerarPal::gerar(bool arquivo){
    //Pegar quantidade de linhas que silabas.txt tem.
    std::string linhas;
    int qntLinhas = 0;
    std::fstream arq("silabas.txt");
    while(getline(arq,linhas)) qntLinhas++;
    arq.close();

    //Adiciona as silabas a um vetor de strings
    std::ifstream input;
    input.open("silabas.txt");
    if(input.is_open()){
    while(!input.eof()){
        std::string pal;
        input>>pal;
        silabas.push_back(pal);
    } input.close();
    }

    std::string palP, palG; //String da pessoa e da palavra gerada
    int tmnP, tmnG;

    if(!arquivo){
        std::cout<<"Digite a palavra que voce deseja mudar (palavra em pt-br)\n>";
        std::cin>>palP;
        palavrasP.push_back(palP);
        if(palP.length()>6){
            if(palP.length()%2==0)
                tmnP = palP.length()/2;
            else
                tmnP = (palP.length()+1)/2;
        }
        else
            tmnP = palP.length();

        srand(time(NULL));
        tmnG = rand()%tmnP+1;
        while(tmnG<2)
            tmnG = rand()%tmnP+1;


        for(int i = 0; i<tmnG; i++){
            int _rand = rand()%silabas.size()+1;
            std::string rand_sil = silabas[_rand];
            palG += rand_sil;
        }
        palavrasG.push_back(palG);
        std::cout<<"A nova palavra gerada a partir de \""<<palP<<"\" é "<<palG<<"\n";
    }

}

void gerarPal::salvar(){
    std::string lingua, abrev;
    std::cout<<"Dê um nome à sua lingua (obs.: nao coloque espaços no nome)\n> ";
    std::cin>>lingua;
    std::cout<<"Dê uma abreviação à a sua lingua (EX: PT-BR, EN, FR, ES, nao pode conter espaços)\n >";
    std::cin>>abrev;

    std::ofstream save;
    save.open(lingua+".txt", std::ios::app);
    if(save.is_open()){
    for(int i = 0; i<palavrasG.size(); i++){
        save<<"\nBR: "<<palavrasP[i]<<" | "<<abrev<<": "<<palavrasG[i]<<"\n";
    }
    }
    else
        std::cout<<"ERRO";
    save.close();

}

std::vector<std::string> gerarPal::getPalavrasG(){return palavrasG;}
