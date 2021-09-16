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
//* https://github.com/Alex-Fortes/LojaRoupa/tree/master
//*******************************************************
//* Cria��o de Bibliotecas
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
	#include <cstring>
	#include <ctime>
	#include <windows.h>
	// Biblioteca de C++
	#include <string>     
	#include <iostream>   
	#include <iomanip>   
using namespace std; 

//**********************************************
//*  Fun��o "pausa()"
//*    Entradas: n�o tem.
//*    Saida(s): n�o tem.
//**********************************************
		void pausa()
		{
		cout<< "Prima qualquer tecla para continuar ... ";
		cin.get(); 
		} // Fim da fun��o "pausa()".


//*************************************************
//*  Fun��o "sairDoPrograma()"
//*   Entrada(s): queroSair (bool) 
//*   Saida(s): queroSair (bool)
//*************************************************
	bool sairDoPrograma(bool queroSair)
		{
		char resposta = '\0';
			fflush(stdin);
			cout<<"Tem a certeza (S/N)? ";
		    cin>>resposta; cin.ignore();	
				if (resposta == 'S'  ||  resposta == 's')
			   	queroSair = true;	
	return queroSair;	
} // Fim da fun��o "sairDoPrograma()".


//**************************************************
//* Fun��o "escolhaInvalida()"
//*  Entrada(s): n�o tem.
//*  Saida(s): n�o tem.
//**************************************************
//**************************************************
//* Fun��o escolhaInvalida()
//***************************************************
	void escolhaInvalida(int numOp)
	{
		char ultimaOp = (char)(64 + numOp);  // 68 -> 'D'
		cout<<"Escolha inv�lida! Escolha deve ser de A a "<<ultimaOp;
		cout<<"."<<endl;
	pausa();	
} // Fim da fun��o "escolhaInvalida()".

//**************************************************
//* Fun��o "escolhaInvalida()"
//*  Entrada(s): n�o tem.
//*  Saida(s): n�o tem.
//**************************************************
	void escolhaInvalida()
		{
		  cout<<"Escolha inv�lida!\n"; system("pause");	
	} // Fim da fun��o "escolhaInvalida()".

//***************************************************
//*  Fun��o "despedida()"
//*   Entrada(s): n�o tem.
//*   Saida(s): n�o tem.
//***************************************************
	void despedida()
		{
		cout<<"Obrigado por ter utilizado o nosso \"software\"!\n";
		cout<< "Prima qualquer tecla para continuar ... ";
		cin.get(); 	
	} // Fim da fun��o "despedida()".


	class DataEHoras {
		
		public:
			
		static const std::string currentDate() {
		    time_t     now = time(0);
		    struct tm  tstruct;
		    char       buf[80];
		    tstruct = *localtime(&now);
		    strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct);
		return buf;
}

	static const std::string currentTime() {
		    time_t     now = time(0);
		    struct tm  tstruct;
		    char       buf[80];
		    tstruct = *localtime(&now);
		    strftime(buf, sizeof(buf), "%H:%M:%S", &tstruct);
		return buf;
}

//***********************************************************
//* Obten��o dos elementos de uma data e hora - Vers�o C/C++
//**********************************************************
	static int obtemAno(string data)
	    {                                  // 01234567
	    string infoAno = data.substr(0,4); // YYYY-MM-DD
		int ano = atoi(infoAno.c_str());  	
    return ano;	
}  

	static int obtemMes(string data)
	    {                                  // 01234567
	    string infoMes = data.substr(5,2); // YYYY-MM-DD
		int mes = atoi(infoMes.c_str());  	
	    return mes;	
	}  

	static int obtemDia(string data)
	    {                                  // 012345678
	    string infoDia = data.substr(8,2); // YYYY-MM-DD
		int dia = atoi(infoDia.c_str());  	
    return dia;	
	}  

	static int obtemHoras(string tempo)
	    {
	    string infoHoras = tempo.substr(0,2);  // HH:MM:SS
	        // substr(posi��o inicial, num. carcateres)
			int numHoras = atoi(infoHoras.c_str()); 
			    // ascii to integer    	
				// "c_str()" - c_STRING() - 
				// transforma uma "string" num array
				// de caracteres.
    return numHoras;	
	}   

	static int obtemMinutos(string tempo)
	    {                                       // 01234567
	    string infoMinutos = tempo.substr(3,2); // HH:MM:SS
		int numMinutos = atoi(infoMinutos.c_str());  	
    return numMinutos;	
}  

//***********************************************************
//* Obten��o dos elementos de uma data e hora - Vers�o C++
//**********************************************************
	static int obtemAnoV2(string data)
	    {                                  // 01234567
	    string infoAno = data.substr(0,4); // YYYY-MM-DD
		int ano = stoi(infoAno,nullptr,10);  	
    return ano;	
	}  

	static int obtemMesV2(string data)
	    {                                  // 01234567
	    string infoMes = data.substr(5,2); // YYYY-MM-DD
		int mes = stoi(infoMes,nullptr,10);  	
    return mes;	
	}  

	static int obtemDiaV2(string data)
	    {                                  // 01234567
	    string infoDia = data.substr(8,2); // YYYY-MM-DD
		int dia = stoi(infoDia,nullptr,10);  	
    return dia;	
	}  
	
	static int obtemHorasV2(string tempo)
	    {                                   // 01234567
	    string infoHoras = tempo.substr(0,2); // HH:MM:SS
		int horas = stoi(infoHoras,nullptr,10);  	
    return horas;	
	}  	

	static int obtemMinutosV2(string tempo)
	    {                                     // 01234567
	    string infoMinutos = tempo.substr(0,2); // HH:MM:SS
		int minutos = stoi(infoMinutos,nullptr,10);  	
    return minutos;	
	} 	
};



	




	
