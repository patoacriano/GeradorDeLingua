#include <iostream>
#include <fstream>



int main(int argc, char** argv){
    std::string input, output;

    std::string help = "Para usar esse comando, use:\n -i para o arquivo de input\n -o para o arquivo de output\n -nome para o nome da lingua\n exemplo: ./GeradorLingua -i ArquivoEmPT-BR.txt -o ArquivoEmMinhaLingua.txt\n";

    for(int i = 0; i<argc; i++){
        std::string _arg = argv[i];
        if(_arg == "-i") input = argv[i+1];
        else if(_arg == "-o") output = argv[i+1];
        else if(_arg == "--help" || _arg == "-h") std::cout<<help;
    }


    return 0;
}
