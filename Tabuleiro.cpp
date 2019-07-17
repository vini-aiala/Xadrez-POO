#include "Tabuleiro.h"
Tabuleiro::Tabuleiro()
{
	int i, j;
	for (i = 0; i < 8; i = i + 1)
		for (j = 0; j < 8; j = j + 1)
			casas[i][j] = new Posicao(i, j + 'a');
}

bool Tabuleiro::verificaPeca(int origemL, int origemC, bool cor)
{
	if(origemL < 8 && origemL >= 0 && origemC < 8 && origemC >= 0 && casas[origemL][origemC]->getPeca() && casas[origemL][origemC]->getPecaCor() == cor)
		return true;
	else
		return false;
}

bool Tabuleiro::checaMovimento(int origemL, int origemC, int destinoL, int destinoC)
{
	bool flag = false;
	if (casas[origemL][origemC]->checaMovimento(origemL, origemC, destinoL, destinoC) && destinoL < 8 && destinoL >= 0 && destinoC < 8 && destinoC >= 0)
	{
		if (casas[origemL][origemC]->desenhaPeca() == 't' || casas[origemL][origemC]->desenhaPeca() == 'T')
		{
			flag = colisaoMais(origemL, origemC, destinoL, destinoC);
		}
		else if (casas[origemL][origemC]->desenhaPeca() == 'c' || casas[origemL][origemC]->desenhaPeca() == 'C')
		{
			if (casas[destinoL][destinoC]->getPeca() == 0)
			{
				flag = true;
			}
			else if (casas[destinoL][destinoC]->getPeca() != 0 && casas[origemL][origemC]->getPeca()->getCor() != casas[destinoL][destinoC]->getPeca()->getCor())
			{
				casas[destinoL][destinoC]->getPeca()->comida();
				flag = true;
			}
			else
			{
				return false;
			}
		}
		else if (casas[origemL][origemC]->desenhaPeca() == 'b' || casas[origemL][origemC]->desenhaPeca() == 'B')
		{
			flag = colisaoDiagonal(origemL, origemC, destinoL, destinoC);
		}
		else if (casas[origemL][origemC]->desenhaPeca() == 'r' || casas[origemL][origemC]->desenhaPeca() == 'R')
		{
			if (origemL == destinoL || origemC == destinoC)
			{
				flag = colisaoMais(origemL, origemC, destinoL, destinoC);
			}
			else
			{
				flag = colisaoDiagonal(origemL, origemC, destinoL, destinoC);
			}
		}
		else if (casas[origemL][origemC]->desenhaPeca() == 'd' || casas[origemL][origemC]->desenhaPeca() == 'D')
		{
			if (origemL == destinoL || origemC == destinoC)
			{
				flag = colisaoMais(origemL, origemC, destinoL, destinoC);
			}
			else
			{
				flag = colisaoDiagonal(origemL, origemC, destinoL, destinoC);
			}
		}
		else if (casas[origemL][origemC]->desenhaPeca() == 'p' || casas[origemL][origemC]->desenhaPeca() == 'P')
		{
			if (origemC == destinoC)
			{
				if (casas[destinoL][destinoC]->getPeca() != 0)
				{
					flag = false;
				}
				else
				{
					flag = true;
				}
			}
			else
			{
				if (casas[destinoL][destinoC]->getPeca() != 0 && casas[destinoL][destinoC]->getPeca()->getCor() != casas[origemL][origemC]->getPeca()->getCor())
				{
					flag = true;
					casas[destinoL][destinoC]->getPeca()->comida();
				}
				else
				{
					flag = false;
				}
			}
		}
	}
	return flag;
}

bool Tabuleiro::colisaoDiagonal(int origemL, int origemC, int destinoL, int destinoC)
{
	int passoL, passoC;
	if (origemL - destinoL < 0)
	{
		passoL = 1;
	}
	else
	{
		passoL = -1;//
	}

	if (origemC - destinoC < 0)
	{
		passoC = 1;//
	}
	else
	{
		passoC = -1;
	}

	int i = passoL, j = passoC;
	while (origemL + i != destinoL)
	{
		if (casas[origemL + i][origemC + j]->getPeca() != 0)
		{
			return false;
		}
		i = i + passoL;
		j = j + passoC;
	}

	if (casas[destinoL][destinoC]->getPeca() != 0 && casas[destinoL][destinoC]->getPeca()->getCor() != casas[origemL][origemC]->getPeca()->getCor())
	{
		casas[destinoL][destinoC]->getPeca()->comida();
		return true;
	}
	else if (casas[destinoL][destinoC]->getPeca() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Tabuleiro::colisaoMais(int origemL, int origemC, int destinoL, int destinoC)
{
	if (origemL == destinoL)
	{
		int passo;
		if (origemC - destinoC < 0)
		{
			passo = 1;
		}
		else
		{
			passo = -1;
		}
		int i;
		for (i = passo; origemC + i != destinoC; i = i + passo)
		{
			if (casas[origemL][origemC + i]->getPeca() != 0)
				return false;
		}

		if (casas[destinoL][destinoC]->getPeca() != 0 && casas[destinoL ][destinoC]->getPeca()->getCor() != casas[origemL][origemC]->getPeca()->getCor())
		{
			casas[destinoL][destinoC]->getPeca()->comida();
			return true;
		}
		else if(casas[destinoL][destinoC]->getPeca() == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		int passo;
		if (origemL - destinoL < 0)
		{
			passo = 1;
		}
		else
		{
			passo = -1;
		}

		int i;
		for (i = passo; origemL + i != destinoL; i = i + passo)
		{
			if (casas[origemL + i][origemC]->getPeca() != 0)
				return false;
		}

		if (casas[destinoL][destinoC]->getPeca() != 0 && casas[destinoL][destinoC]->getPeca()->getCor() != casas[origemL][origemC]->getPeca()->getCor())
		{
			return true;
			casas[destinoL][destinoC]->getPeca()->comida();
		}
		else if(casas[destinoL][destinoC]->getPeca() == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return true;
}

void Tabuleiro::movimentaPeca(int origemL, int origemC, int destinoL, int destinoC)
{
	casas[destinoL][destinoC]->setPeca(casas[origemL][origemC]->getPeca());
	casas[origemL][origemC]->setPeca(0);
}

void Tabuleiro::adicionarPeca(Peca *peca, int posicaoInt, int posicaoChar)
{
	casas[posicaoInt][posicaoChar]->setPeca(peca);
}

Peca *Tabuleiro::getPeca(int origemL, int origemC)
{
	return casas[origemL][origemC]->getPeca();
}

void Tabuleiro::exibirTabuleiro()
{
	std::cout << "      1     2     3     4     5     6     7     8     \n";
	//                      1                                        2                                        3                                        4                                        5                                        6                                        7                                        8
	std::cout << "   _________________________________________________  \n";
	std::cout << "   |     |     |     |     |     |     |     |     |  " << std::endl;
	std::cout << " A |  " << casas[0][0]->desenhaPeca() << "  |  " << casas[0][1]->desenhaPeca() << "  |  " << casas[0][2]->desenhaPeca() << "  |  " << casas[0][3]->desenhaPeca() << "  |  " << casas[0][4]->desenhaPeca() << "  |  " << casas[0][5]->desenhaPeca() << "  |  " << casas[0][6]->desenhaPeca() << "  |  " << casas[0][7]->desenhaPeca() << "  |  " << std::endl;
	std::cout << "   |_____|_____|_____|_____|_____|_____|_____|_____|  " << std::endl;
	std::cout << "   |     |     |     |     |     |     |     |     |  " << std::endl;
	std::cout << " B |  " << casas[1][0]->desenhaPeca() << "  |  " << casas[1][1]->desenhaPeca() << "  |  " << casas[1][2]->desenhaPeca() << "  |  " << casas[1][3]->desenhaPeca() << "  |  " << casas[1][4]->desenhaPeca() << "  |  " << casas[1][5]->desenhaPeca() << "  |  " << casas[1][6]->desenhaPeca() << "  |  " << casas[1][7]->desenhaPeca() << "  |  " << std::endl;
	std::cout << "   |_____|_____|_____|_____|_____|_____|_____|_____|  " << std::endl;
	std::cout << "   |     |     |     |     |     |     |     |     |  " << std::endl;
	std::cout << " C |  " << casas[2][0]->desenhaPeca() << "  |  " << casas[2][1]->desenhaPeca() << "  |  " << casas[2][2]->desenhaPeca() << "  |  " << casas[2][3]->desenhaPeca() << "  |  " << casas[2][4]->desenhaPeca() << "  |  " << casas[2][5]->desenhaPeca() << "  |  " << casas[2][6]->desenhaPeca() << "  |  " << casas[2][7]->desenhaPeca() << "  |  " << std::endl;
	std::cout << "   |_____|_____|_____|_____|_____|_____|_____|_____|  " << std::endl;
	std::cout << "   |     |     |     |     |     |     |     |     |  " << std::endl;
	std::cout << " D |  " << casas[3][0]->desenhaPeca() << "  |  " << casas[3][1]->desenhaPeca() << "  |  " << casas[3][2]->desenhaPeca() << "  |  " << casas[3][3]->desenhaPeca() << "  |  " << casas[3][4]->desenhaPeca() << "  |  " << casas[3][5]->desenhaPeca() << "  |  " << casas[3][6]->desenhaPeca() << "  |  " << casas[3][7]->desenhaPeca() << "  |  " << std::endl;
	std::cout << "   |_____|_____|_____|_____|_____|_____|_____|_____|  " << std::endl;
	std::cout << "   |     |     |     |     |     |     |     |     |  " << std::endl;
	std::cout << " E |  " << casas[4][0]->desenhaPeca() << "  |  " << casas[4][1]->desenhaPeca() << "  |  " << casas[4][2]->desenhaPeca() << "  |  " << casas[4][3]->desenhaPeca() << "  |  " << casas[4][4]->desenhaPeca() << "  |  " << casas[4][5]->desenhaPeca() << "  |  " << casas[4][6]->desenhaPeca() << "  |  " << casas[4][7]->desenhaPeca() << "  |  " << std::endl;
	std::cout << "   |_____|_____|_____|_____|_____|_____|_____|_____|  " << std::endl;
	std::cout << "   |     |     |     |     |     |     |     |     |  " << std::endl;
	std::cout << " F |  " << casas[5][0]->desenhaPeca() << "  |  " << casas[5][1]->desenhaPeca() << "  |  " << casas[5][2]->desenhaPeca() << "  |  " << casas[5][3]->desenhaPeca() << "  |  " << casas[5][4]->desenhaPeca() << "  |  " << casas[5][5]->desenhaPeca() << "  |  " << casas[5][6]->desenhaPeca() << "  |  " << casas[5][7]->desenhaPeca() << "  |  " << std::endl;
	std::cout << "   |_____|_____|_____|_____|_____|_____|_____|_____|  " << std::endl;
	std::cout << "   |     |     |     |     |     |     |     |     |  " << std::endl;
	std::cout << " G |  " << casas[6][0]->desenhaPeca() << "  |  " << casas[6][1]->desenhaPeca() << "  |  " << casas[6][2]->desenhaPeca() << "  |  " << casas[6][3]->desenhaPeca() << "  |  " << casas[6][4]->desenhaPeca() << "  |  " << casas[6][5]->desenhaPeca() << "  |  " << casas[6][6]->desenhaPeca() << "  |  " << casas[6][7]->desenhaPeca() << "  |  " << std::endl;
	std::cout << "   |_____|_____|_____|_____|_____|_____|_____|_____|  " << std::endl;
	std::cout << "   |     |     |     |     |     |     |     |     |  " << std::endl;
	std::cout << " H |  " << casas[7][0]->desenhaPeca() << "  |  " << casas[7][1]->desenhaPeca() << "  |  " << casas[7][2]->desenhaPeca() << "  |  " << casas[7][3]->desenhaPeca() << "  |  " << casas[7][4]->desenhaPeca() << "  |  " << casas[7][5]->desenhaPeca() << "  |  " << casas[7][6]->desenhaPeca() << "  |  " << casas[7][7]->desenhaPeca() << "  |  " << std::endl;
	std::cout << "   |_____|_____|_____|_____|_____|_____|_____|_____|  " << std::endl;
}