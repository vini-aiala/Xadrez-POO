/*
 * Arquivo: main.cpp
 * Autor: Lucas Henrique de Araújo (R.A.: 759521), Rafael Pincinato Toledo (R.A.: 743590), Vinícius Pereira Aiala(R.A.: 759544).
 * Turma: A
 * Descrição: Este arquivo contém a função principal para o funcionamento do jogo de xadrez.
 * Concluído em: 27 de Junho de 2019.
 */

#include <iostream>
#include <fstream>
#include "Jogo.h"

int x = 3;

int main()
{
	char confirmacao;
	Jogo* jogo;

	std::ifstream salvo("jogo.txt");

	if (!salvo)
	{
		std::cout << "Não foi encontrado arquivos de jogo!" << std::endl << "Iniciando um novo..." << std::endl;
		jogo = new Jogo();
	}
	else {
		salvo >> jogo;
		salvo.close();
	}
	
	
	jogo->ExibirTabuleiro();


	while (jogo->Movimentar())
	{
		jogo->ExibirTabuleiro();
	}

	std::cout << "Deseja salvar o jogo?" << std::endl;
	std::cin >> confirmacao;
	if (confirmacao == 'y' || confirmacao == 's')
	{
		std::ofstream arquivo("jogo.txt");
		if (!arquivo)
			return 0;
		arquivo << jogo;
		arquivo.close();
	}
    return 0;
}
