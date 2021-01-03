#include "ler_txt.h"
#include <fstream>

void LerTxt::gerar(std::string input){
    //Lê arquivo linha por linha
    std::fstream inp;
    inp.open(input);
    std::string pal;
    if(inp.is_open()){
    while(inp >> pal){
        //adicionar cada palavra ao vetor palavrasTxt
        int contem = 0;
        //verificar se a palavra ja existe no vetor
        //se ja exisitir, nao adiciona palavras repetidas
        for(int i = 0; i<palavrasTxt.size(); i++){
            if(pal == palavrasTxt[i]) contem++;
        }
        if(contem == 0)
            palavrasTxt.push_back(pal);
    }
    }
    else
        std::cout<<"Nao foi possivel abrir o arquivo :(\n";
    inp.close();

    //pega as silabas
    std::ifstream sil;
    sil.open("silabas.txt");
    while(!sil.eof()){
        std::string _pal;
        sil>>pal;
        silabas.push_back(pal);
    }
    sil.close();

    //gera uma palavra aleatoria para cada palavra em palavrasTxt
    srand(time(NULL));
    for(int i = 0; i<palavrasTxt.size(); i++){
        int tmnP, tmnG;
        std::string palG;
        if(palavrasTxt[i].length()>6){
            if(palavrasTxt[i].length()%2==0)
                tmnP = palavrasTxt[i].length()/2;
            else
                tmnP = (palavrasTxt[i].length()+1)/2;
        }
        else
            tmnP = palavrasTxt[i].length();

        tmnG = rand()%tmnP+1;
        while(tmnG<tmnP)
            tmnG = rand()%tmnP+1;

        for(int i = 0; i<tmnG; i++){
            int _rand = rand()%silabas.size()+1;
            std::string rand_sil = silabas[_rand];
            palG += rand_sil;
        }
        palavrasG.push_back(palG);
    }

    //Lê o arquivo linha por linha, e substitui as palavras que existirem em palavrasTxt por palavrasG
    std::ifstream _inp;
    _inp.open(input);

    std::ofstream save;
    save.open(input+"TRADUZIDO.txt");

    std::string _pal, _pal2;
    while(std::getline(_inp,_pal)){
        int id = -1;
        //passa por palavra por palavra dessa linha
        for(long unsigned int i = 0; i<=_pal.length(); i++){
            if(!isspace(_pal[i]) && i!=_pal.length()) _pal2 += _pal[i];
            else{
                for(long unsigned int j = 0; j<palavrasTxt.size(); j++){
                    if(_pal2 == palavrasTxt[j]){ id=j; _pal2 = ""; }
                }
            }
            //std::cout<<_pal2<<"\n";
            if(id != -1){
                std::cout<<palavrasG[id]<<" ";
                save<<palavrasG[id]<<" ";
                id = -1;
            }
        }

        std::cout<<"\n";
        save<<"\n";
        _pal2 = "";
    }
    _inp.close();
    save.close();

    std::ofstream dicionario;
    dicionario.open(input+"DICIONARIO.txt");
    for(int i = 0; i<palavrasTxt.size(); i++){
        dicionario<<palavrasTxt[i]<<" = "<<palavrasG[i]<<"\n";
    }


}
