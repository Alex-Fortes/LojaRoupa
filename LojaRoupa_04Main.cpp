//* 0784 Projeto Final - Alexander Fortes
//
//* Programa que gere uma loja de roupa.
//*    Especifica��es:
//*     Op��es do menu:   
//*       -> 
//*        - Inserir produto      - Apagar produto
//*        - Pesquisar produto    - Listar produto
//*        - Repor produto        - Vender produto
//*        - Sair do programa.
//*
		//*  Dados dos vestu�rios:		
		//*   - c�digo do vestu�rio
		//*   - categoria (homem, mulher, crian�a)
		//*   - tipo de roupa (vestido, cal�as, t-shirts...)
		//*   - cor do vestu�rio
		//*   - mat�ria-prima do vestu�rio
		//*   - pre�o do vestu�rio
		//*   - tamanho do vestu�rio
		//*   - n�mero do arm�rio onde est� guardado;
		//*   - letra da prateleira.
//*
//**********************************************************
//*   - Vetores din�micos; classes derivadas; ficheiros
//*   - Operadores; Linguagem orientada a objetos - conceitos 
//*   - Bibliotecas. Base de Dados. 
//************************************************************
//* Vers�o 01 
//*   - Vetores est�ticos - locais
//* Vers�o 02 
//*   - Vetores din�micos - globais
//* Vers�o 03 
//*   - Vetores din�micos - globais
//* Vers�o 04 
//*   - Vetores din�micos - locais
//* Vers�o 05 
//*   - Vetores din�micos - locais
//* Vers�o 06 
//*   - Vetores din�micos - locais
//* Vers�o 07 
//*   - Vetores din�micos - Ficheiros
//* Vers�o 08 
//*   - Vetores din�micos - Ficheiros - Libraries
//* Vers�o 09 
//*   - Vetores din�micos - Ficheiros - Libraries - Encripta��o
//************************************************************
//*  Ordem de trabalhos:
//*   - Classe: dados, construtores, setters, getters, 
//*             leitura e escrita. 
//*   - Menu: op��es do menu.
//*
//************************************************************
//* Todos os ficheiros do programa e as suas vers�es podem 
//* 	ser encontrados no meu reposit�rio no github 
//* https://github.com/Alex-Fortes/LojaRoupa/tree/master
//*******************************************************
//* 	Cria��o de Bibliotecas
//*******************************************************
//* Se der o erro do "nullptr"
//* acrescentar em 
//* Menu Tools -> Compiler Options -> Separador Programs
//*  inserir:
//* gcc.exe -std=c++0x
//* g++.exe -std=c++11
//*******************************************************
//********************************************************
//* Este ficheiro cont�m todas as fun��es que 
//* implementam as op��es do menu.
//********************************************************
// Bibliotecas de C
#include <cstdio>
#include <cstdlib>
#include <clocale>
// Biblioteca de C++
#include <string>     
#include <iostream>   
#include <iomanip>    
#include <vector>
#include "LojaRoupa_01FComuns.cpp" 
              // Inclus�o das fun��es comuns
#include "LojaRoupa_02ClassePecaRoupa.cpp"
              // Inclus�o do ficheiro de classe
#include "LojaRoupa_03Menu.cpp"
              // Inclus�o das fun��es da Loja de roupa
using namespace std; 

	// Declara��o e inicializa��o dos dados estaticos
		int Vestuario::numVestuarios = 0;

	// Dados globais
	const int MAXOPCOES = 8;
	extern vector<Vestuario> vestuarios;

    // Vetor de "Vestuario", ou seja composto por 
	//  objetos da classe Vestuario.
	// Nome do vetor: vestuarios.

//****************************************************
//* Fun��o principal
//****************************************************
int main() 
	{
	setlocale(LC_ALL, "Portuguese");
	
	// 1. Dados
	vector<Vestuario> vestuarios;
	
	char escolha = '\0';
	bool queroSair = false;
	const int NUMOPCOES = 8;
	// 2. Programa principal
	lerFicheiro(&vestuarios);
	do 
		{
		mostraMenu();
		escolha = obtemEscolha(escolha, NUMOPCOES);
		queroSair = processaEscolha(&vestuarios, escolha, queroSair, NUMOPCOES);							
		} while(!queroSair);
	despedida();
return 0;
} // Fim da fun��o "main()"
