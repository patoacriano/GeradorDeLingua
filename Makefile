all:
	g++ src/*.cpp -o Gerador

adicionar:
	g++ src\ antigo/AdicionarSilabas.cpp -o Adicionar


clean:
	rm Gerador

install:
	g++ src/*.cpp -o Gerador
	cp Gerador ~/.local/bin/
