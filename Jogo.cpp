#include "Jogo.h"

Jogo::Jogo()
{
	vez = 0;

	mesa = new Tabuleiro();

	//cria pecas brancas
	pecas[0] = new Bispo('B');
	pecas[1] = new Bispo('B');
	pecas[2] = new Torre('T');
	pecas[3] = new Torre('T');
	pecas[4] = new Cavalo('C');
	pecas[5] = new Cavalo('C');
	pecas[6] = new Rei('R');
	pecas[7] = new Dama('D');
	for (int i = 0; i < 8; i++)//cria 8 peoes
		pecas[8 + i] = new Peao('P');

	//cria pecas pretas
	pecas[16] = new Bispo('b');
	pecas[17] = new Bispo('b');
	pecas[18] = new Torre('t');
	pecas[19] = new Torre('t');
	pecas[20] = new Cavalo('c');
	pecas[21] = new Cavalo('c');
	pecas[22] = new Rei('r');
	pecas[23] = new Dama('d');
	for (int i = 0; i < 8; i++)//cria 8 peoes
		pecas[24 + i] = new Peao('p');

	//coloca as pecas em suas posicoes inciais
	mesa->adicionarPeca(pecas[0], 0, 2);
	mesa->adicionarPeca(pecas[1], 0, 5);
	mesa->adicionarPeca(pecas[2], 0, 0);
	mesa->adicionarPeca(pecas[3], 0, 7);
	mesa->adicionarPeca(pecas[4], 0, 1);
	mesa->adicionarPeca(pecas[5], 0, 6);
	mesa->adicionarPeca(pecas[6], 0, 3);
	mesa->adicionarPeca(pecas[7], 0, 4);
	for (int i = 0; i < 8; i++)
	{
		mesa->adicionarPeca(pecas[i + 8], 1, i);
	}

	mesa->adicionarPeca(pecas[16], 7, 2);
	mesa->adicionarPeca(pecas[17], 7, 5);
	mesa->adicionarPeca(pecas[18], 7, 0);
	mesa->adicionarPeca(pecas[19], 7, 7);
	mesa->adicionarPeca(pecas[20], 7, 1);
	mesa->adicionarPeca(pecas[21], 7, 6);
	mesa->adicionarPeca(pecas[22], 7, 3);
	mesa->adicionarPeca(pecas[23], 7, 4);
	for (int i = 0; i < 8; i++)
	{
		mesa->adicionarPeca(pecas[i + 24], 6, i);
	}

	std::string J;

	//recebe o nome do jogador 1 e cria
	std::cout << "Nome do Jogador 1: ";
	std::cin >> J;
	jogadores[0] = new Jogador(J, &pecas[0]);

	//recebe o nome do jogador 2 e cria
	std::cout << "Nome do Jogador 2: ";
	std::cin >> J;
	jogadores[1] = new Jogador(J, &pecas[16]);
}

Jogo::Jogo(std::string nome1, std::string nome2, int vez_atual)
{
	vez = vez_atual;

	mesa = new Tabuleiro();

	//cria pecas brancas
	pecas[0] = new Bispo('B');
	pecas[1] = new Bispo('B');
	pecas[2] = new Torre('T');
	pecas[3] = new Torre('T');
	pecas[4] = new Cavalo('C');
	pecas[5] = new Cavalo('C');
	pecas[6] = new Rei('R');
	pecas[7] = new Dama('D');
	for (int i = 0; i < 8; i++)//cria 8 peoes
		pecas[8 + i] = new Peao('P');

	//cria pecas pretas
	pecas[16] = new Bispo('b');
	pecas[17] = new Bispo('b');
	pecas[18] = new Torre('t');
	pecas[19] = new Torre('t');
	pecas[20] = new Cavalo('c');
	pecas[21] = new Cavalo('c');
	pecas[22] = new Rei('r');
	pecas[23] = new Dama('d');
	for (int i = 0; i < 8; i++)//cria 8 peoes
		pecas[24 + i] = new Peao('p');

	jogadores[0] = new Jogador(nome1, &pecas[0]);
	jogadores[1] = new Jogador(nome2, &pecas[16]);
}

bool Jogo::Movimentar()
{
	int origemL , destinoL, origemC, destinoC, aux;
	char origemCChar, destinoCChar;

	//se vez % 2 for 0 siginifica que é a vez do primeiro jogador, se for 1 siginifica que é a vez do segundo jogador
	std::cout << "Vez de " << jogadores[vez % 2]->getNome() << ": ";
	
	//recebe as coordenadas da peca e as coordenadas para onde pretende ir
	try {
		if (!(std::cin >> origemCChar && std::cin >> origemL && std::cin >> destinoCChar && std::cin >> destinoL))
		{
			throw 0;
		}

		origemCChar = tolower(origemCChar);
		destinoCChar = tolower(destinoCChar);

		origemL--;//o usuario digita de 1 a 8 mas usamos de 0 a 7
		destinoL--;
		origemC = origemCChar - 'a';
		destinoC = destinoCChar - 'a';

		if (origemCChar == 's' && destinoCChar == 'i' && origemL == 3 && destinoL == -1)
		{
			return 0;
		}

		aux = origemL;
		origemL = origemC;
		origemC = aux;

		aux = destinoL;
		destinoL = destinoC;
		destinoC = aux;

		if (origemCChar >= 'a' && origemCChar <= 'h' && origemL >= 0 && origemL <= 7 && destinoCChar >= 'a' && destinoCChar <= 'h' && destinoL >= 0 && destinoL <= 7)
		{
			if (mesa->verificaPeca(origemL, origemC, vez % 2))//verifica se a peca é do jogador
			{
				if (mesa->checaMovimento(origemL, origemC, destinoL, destinoC))//verifica se o movimento é valido
				{
					mesa->movimentaPeca(origemL, origemC, destinoL, destinoC);//mexe a peça
					vez++;
				}
				else
				{
					std::cout << "Movimento invalido." << std::endl;
				}
			}
			else
			{
				std::cout << "A peca selecionada nao te pertence." << std::endl;
			}

			if (verificaVitoria(pecas[6]))//verifica se o rei do jogador[0] esta no jogo
			{
				std::cout << jogadores[1]->getNome() << " venceu o jogo." << std::endl;
				return 0;
			}
			else if (verificaVitoria(pecas[22]))//verifica se o rei do jogador[1] esta no jogo
			{
				std::cout << jogadores[0]->getNome() << " venceu o jogo." << std::endl;
				return 0;
			}
		}
		else {
			std::cout << "Fora do limites do tabuleiro" << std::endl;
		}

		verificaXeque(pecas[6]);
		verificaXeque(pecas[22]);
	}
	catch (int a)
	{
		std::cout << "Digite na ordem correta: letra seguida de numero" << std::endl;
		std::cin.clear();//Limpa a flag de erro do cin
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//Limpa o buffer
	}
	return 1;
}

bool Jogo::verificaVitoria(Peca* rei)
{
	bool achado = false;
	for (int i = 0; i < 8 && !achado; i = i + 1)//varre todas as linhas
	{
		for (int j = 0; j < 8 && !achado; j = j + 1)//varre todas as colunas
		{
			if (mesa->getPeca(i, j) == rei)//compara o ponteiro do valor retornado com o do rei (pecas[6]) para saber se eh o rei
			{
				achado = true;
			}
		}
	}

	return !achado;
}

void Jogo::verificaXeque(Peca *rei)
{
	//acha a posicao do rei
	bool achado = false;
	int posicaoL, posicaoC;
	for (int i = 0; i < 8 && !achado; i = i + 1)//varre todas as linhas
	{
		for (int j = 0; j < 8 && !achado; j = j + 1)//varre todas as colunas
		{
			if (mesa->getPeca(i, j) == rei)//compara o ponteiro do valor retornado com o do rei (pecas[6]) para saber se eh o rei
			{
				achado = true;
				posicaoL = i;
				posicaoC = j;
			}
		}
	}

	achado = false;
	//acha a posicao das pecas bramcas e verifica se alguma põe o rei em xeque
	for (int i = 0; i < 8 && !achado; i = i + 1)//varre todas as linhas
	{
		for (int j = 0; j < 8 && !achado; j = j + 1)//varre todas as colunas
		{
			Peca *pecaAux = mesa->getPeca(i, j);
			if (pecaAux != 0 && pecaAux->getCor() != mesa->getPeca(posicaoL, posicaoC)->getCor())//verifica se existe peca na posicao e se a peca eh do adversario
			{
				if (mesa->checaMovimento(i, j, posicaoL, posicaoC))//verifica se a peca consegue ameacar o rei
				{
					achado = true;
				}
			}
		}
	}

	if (achado)
	{
		if (rei->getCor())
		{
			std::cout << "O rei branco esta em xeque." << std::endl;
		}
		else
		{
			std::cout << "O rei preto esta em xeque." << std::endl;
		}
	}
}

void Jogo::ExibirTabuleiro()
{
	mesa->exibirTabuleiro();
}

std::ifstream& operator >> (std::ifstream& in, Jogo*& j)
{
	std::string nome1, nome2;
	bool emjogo, jamexeu;
	int i, k;

	in >> i;
	in >> nome1 >> nome2;
	j = new Jogo(nome1, nome2, i);

	for (int i = 0; i < 32; i++)
	{
		in >> emjogo;
		if (emjogo == false)
		{
			(*j).pecas[i]->comida();
		}
		if ((i >= 8 && i <= 15) || (i > 24 && i < 31)) {
			in >> jamexeu;
			if (jamexeu == false)
			{
				(*j).pecas[i]->mexida();
			}
		}
	}

	for (int s = 0; s < 32; s++)
	{
		in >> i >> k;
		(*j).mesa->adicionarPeca((*j).pecas[s], i, k);
	}
	return in;
}

std::ofstream& operator << (std::ofstream& out, Jogo*& j)
{
	char desenho;
	int pos;
	char pecas[12] = {'B', 'T', 'C', 'R', 'D', 'P', 'b', 't', 'c', 'r', 'd', 'p'};

	out << (*j).vez << std::endl;

	for (int i = 0; i < 2; i++)
		out << (*j).jogadores[i]->getNome() << ' ';
	out << std::endl;

	for (int i = 0; i < 32; i++)
	{
		out << (*j).pecas[i]->getEmJogo() << ' ';
		if ((i >= 8 && i <= 15) || (i > 24 && i < 31)) {
			out << (*j).pecas[i]->getJaMexeu() << ' ';
		}
	}
	out << std::endl;

	for (int s = 0; s < 12; s++)
	{
		for (int i = 0; i < 8; i++)
		{
			for (int k = 0; k < 8; k++)
			{
				if ((*j).mesa->getPeca(i, k))
				{
					if ((*(*j).mesa->getPeca(i, k)).desenhaPeca() == pecas[s])
					{
						out << i << ' ' << k << std::endl;
					}
				}
			}
		}
	}

	return out;
}