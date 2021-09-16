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
	#include <ctime>
	#include <windows.h>
	// Biblioteca de C++
	#include <string>     
	#include <iostream>   
	#include <iomanip>    
	#include <vector>
	#include <fstream>
	using namespace std; 


	//*******************
// DEclara��o de um vetor din�mico
vector<Vestuario> vestuarios;

// Prot�tipos das fun��es
// Declara��o das fun��es - Cabe�alhos das fun��es
		void mostraMenu();
		char obtemEscolha(char );
		bool processaEscolha(vector<Vestuario>*, char, bool,int );
		void despedida();
		
		void listarVestuarios(vector<Vestuario>);
		void inserirVestuario(vector<Vestuario>*);
		void apagarVestuario(vector<Vestuario>*);
		void pesquisarVestuario(vector<Vestuario>);
		void atualizarVestuario(vector<Vestuario>*);
		void venderVestuario(vector<Vestuario>*);
		void reporVestuario(vector<Vestuario>*);
		void guardaFicheiro(vector<Vestuario> vestuarios);
		void lerFicheiro(vector<Vestuario> *vestuarios);

//***********************************************
//* Fun��o "inicializaLojaRoupa()"
//* Entrada(s):  vestuarios.
//* Saida(s): n�o tem.
//************************************************
	void inicializaLojaRoupa()
	{
	} // Fim da fun��o "inicializaLojaRoupa()"

//*******************************************************
//* Fun��o "mostraMenu()".
//* Entrada(s): n�o tem.
//* Saida(s): n�o tem.
//*******************************************************
		void mostraMenu()
		{
		system("cls");   
		system("color A");
		cout<<"************************************"<<endl;
		cout<<"*                                  *"<<endl;
		cout<<"*       Loja de Roupa Moda         *"<<endl;
		cout<<"*                                  *"<<endl;
		cout<<"*    A. Inserir vestuario.         *"<<endl;
		cout<<"*    B. Apagar vestuario.          *"<<endl;
		cout<<"*    C. Pesquisar vestuario.       *"<<endl;
		cout<<"*    D. Atualizar vestuario.       *"<<endl;
		cout<<"*    E. Listar vestuario.          *"<<endl;
		cout<<"*    F. Vender vestuario.          *"<<endl;
		cout<<"*    G. Repor vestuario.           *"<<endl;
		cout<<"*    H. Sair do programa.          *"<<endl;
		cout<<"*                                  *"<<endl;
		cout<<"************************************"<<endl;
		cout<<endl;	
		} // Fim da fun��o "mostraMenu()".

//*********************************************
//* Fun��o "obtemEscolha()"
//* Entrada(s): char escolha 
//* Saida(s): char
//*********************************************
	char obtemEscolha(char escolha, int numOp)
		{
		char ultimaOp = (char)(numOp+64); // "A" - ASCII 65	
		cout<<"Qual a sua escolha (A-"<<ultimaOp<<")? ";
		cin>>escolha; cin.ignore();	
		return escolha;	
	} // Fim do "obtemEscolha()".


//**********************************************
//*  Fun��o processaEscolha()"
//*    Entradas: vector<Vestuario>& vestuarios, int numVestuarios,
//*              char escolha, bool queroSair.
//*    Saida(s): bool queroSair.
//**********************************************
	bool processaEscolha(vector<Vestuario> *vestuarios,
                        char escolha, bool queroSair, int numOp)
	{    
	 switch(escolha)
		 {
		  case 'A': case 'a': inserirVestuario(vestuarios);
		                      guardaFicheiro(*vestuarios);
		                      break;
		  case 'B': case 'b': apagarVestuario(vestuarios);
		                      guardaFicheiro(*vestuarios);
		                      break;
		  case 'C': case 'c': pesquisarVestuario(*vestuarios); 
		                      break;
		  case 'D': case 'd': atualizarVestuario(vestuarios);
		                      guardaFicheiro(*vestuarios);
		                      break;
		  case 'E': case 'e': listarVestuarios(*vestuarios);
		                      break;
		  case 'F': case 'f': venderVestuario(vestuarios);  
		                      guardaFicheiro(*vestuarios);
		                      break;			
		  case 'G': case 'g': reporVestuario(vestuarios);
		                      guardaFicheiro(*vestuarios);
		                      break;			  	 
		  case 'H': case 'h': queroSair = sairDoPrograma(queroSair);
		                      break;
	  default:	 
		  escolhaInvalida(numOp);
 } // Fim do "switch"

return queroSair;	
} // Fim da Fun��o "processaEscolha()".

//**********************************************
//*  Fun��o inserirVestuario()"
//*    Entradas: vector<Vestuario>& vestuarios, int numVestuarios.
//*    Saida(s): n�o tem.
//**********************************************
	void inserirVestuario(vector<Vestuario> *vestuarios)
	{		 
		Vestuario* vestuario;
		vestuario = new Vestuario;
		vestuario->leTudoVestuario();
		
		int nVestuarios = vestuarios->size();
		cout<<"N�mero de vestuarios: "<<nVestuarios<<"."<<endl;
		
		vestuarios->push_back(*vestuario); 
		Vestuario::numVestuarios++;
		//vestuarios.insert(vestuarios.begin()+nVestuarios, vestuario);
		vestuarios->at(nVestuarios).mostraTudoVestuario();
		nVestuarios = vestuarios->size();
		cout<<"N�mero de vestuarios: "<<nVestuarios<<"."<<endl;
		cout<< "Vestu�rio inserido com sucesso!"<<endl;
	pausa();
} // Fim da fun��o "Inserirvestuario()".

//**********************************************
//*  Fun��o apagarVestuario()"
//*    Entradas: vector<Vestuario>& vestuarios, int numVestuarios.
//*    Saida(s): n�o tem.
//**********************************************
	void apagarVestuario(vector<Vestuario> *vestuarios)
	{ 
		int nVestuario = 0;
		int nVestuarios = vestuarios->size();
		cout<<"N�mero de vestuarios: "<<nVestuarios<<"."<<endl;
		if (nVestuarios <= 0) 
		  {
		  cout<<"N�o existem vestuarios!"<<endl;
		  pausa();	
		  } 
		else
		  {
		  do {
		   cout<<"Qual o vestuario a apagar (1-"<<nVestuarios<<")? ";
		   cin>> nVestuario; cin.ignore();
		   if (nVestuario < 1 || nVestuario > nVestuarios)
		      {
		      cout<<"N�mero de vestuarios entre 1 e "<<nVestuarios<<"."<<endl;
		      cout<< "Prima qualquer tecla para continuar ... ";
		      cin.get(); 		
			  }
		  } while (nVestuario < 1 || nVestuario > nVestuarios);
		
		  vestuarios->erase(vestuarios->begin()+(nVestuario-1)); 
		  Vestuario::numVestuarios--;
		  cout<<"Vestuario apagado com sucesso!"<<endl;
	  pausa();
	  }
} // Fim da fun��o "apagarvestuario()".

//**********************************************
//*  Fun��o pesquisarVestuario()"
//*    Entradas: vector<Vestuario> *vestuarios, int numVestuarios.
//*    Saida(s): n�o tem.
//**********************************************
	void pesquisarVestuario(vector<Vestuario> vestuarios)
		{ 
		int nVestuario = 0;
		int nVestuarios = vestuarios.size();
		if (nVestuarios <= 0) 
		  {
		  cout<<"N�o existem vestuarios!"<<endl;
		  pausa();	
		  } 
		else
		  {
		do {
		   cout<<"Qual o vestuario a pesquisar (1-"<<nVestuarios<<")? ";
		   cin>> nVestuario; cin.ignore();
			   if (nVestuario < 1 || nVestuario > nVestuarios)
			      {
			      cout<<"N�mero de vestuarios entre 1 e "<<nVestuarios<<"."<<endl;
			      cout<< "Prima qualquer tecla para continuar ... ";
			      cin.get(); 		
				  }
			} while (nVestuario < 1 || nVestuario > nVestuarios);
		vestuarios[nVestuario-1].mostraTudoVestuario();  
	pausa();
	}
} // Fim da fun��o "pesquisarvestuario()".

//**********************************************
//*  Fun��o atualizarVestuario()"
//*    Entradas: vector<Vestuario> *vestuarios, int numVestuarios.
//*    Saida(s): n�o tem.
//**********************************************
	void atualizarVestuario(vector<Vestuario> *vestuarios)
	{ 
		int nVestuario = 0;
		int nVestuarios = vestuarios->size();
		if (nVestuarios <= 0) 
		  {
		  cout<<"N�o existem vestuarios!"<<endl;
		  pausa();	
		  } 
		else
		  {
		do {
		   cout<<"Qual o vestuario a atualizar (1-"<<nVestuarios<<")? ";
		   cin>> nVestuario; cin.ignore();
			   if (nVestuario < 1 || nVestuario > nVestuarios)
			      {
			      cout<<"N�mero de vestuarios entre 1 e "<<nVestuarios<<"."<<endl;
			      cout<< "Prima qualquer tecla para continuar ... ";
			      cin.get(); 		
			  }
		} while (nVestuario < 1 || nVestuario > nVestuarios);
		(*vestuarios)[nVestuario-1].mostraTudoVestuario();  
		cout<<"Insira o novo pre�o: "<<endl;
		(*vestuarios)[nVestuario-1].lePreco();
		(*vestuarios)[nVestuario-1].mostraTudoVestuario();
		cout<< "Atualiza��o efetuada com sucesso!"<<endl; 
	pausa();
	}
} // Fim da fun��o "atualizarvestuario()".

//**************************************************
//* Fun��o "listarVestuarios()"
//* Entrada(s): Vestuario vestuarios[], int numVestuarios
//* Saida(s): n�o tem.
//**************************************************
	void listarVestuarios(vector<Vestuario> vestuarios)
		{
		int nVestuarios = vestuarios.size();
		cout<<"N�mero de vestuarios: "<<nVestuarios<<"."<<endl;
		if (nVestuarios <= 0) 
		  {
		  cout<<"N�o existem vestuarios!"<<endl;
		  pausa();	
		  } 
		else
		  {
		cout<<"-> Listagem de vestuarios: \n";
			for(int cVestuario=0; cVestuario<nVestuarios; cVestuario++)
				{
				cout<<"Vestuario "<< cVestuario+1<<": "<<endl;	
			    cout<<" -> Tipo: "<<vestuarios[cVestuario].getTipo()<<endl;
			    cout<<" -> Categoria: "<<vestuarios[cVestuario].getCategoria()<<endl;
			//    cout<<" -> Mat�ria-prima: "<<vestuarios[cVestuario].getMateriaPrima()<<endl;
			    cout<<" -> Tamanho: "<<vestuarios[cVestuario].getTamanho()<<endl;
				cout<<" -> Pre�o: "<<vestuarios[cVestuario].getPreco()<<" euros"<<endl;
				cout<<" -> Unidades em stock: "<<vestuarios[cVestuario].getNumUnidades()<<endl;
			} 
	pausa();
	}
} // Fim da fun��o "listarVestuarioes()".

//**********************************************
//*  Fun��o venderVestuario()"
//*    Entradas: vector<Vestuario> *vestuarios, int numVestuarios.
//*    Saida(s): n�o tem.
//**********************************************
	void venderVestuario(vector<Vestuario> *vestuarios)
		{ 
		int nVestuario = 0;
		int nVestuarios = vestuarios->size();
		if (nVestuarios <= 0) 
		  {
		  cout<<"N�o existem vestuarios!"<<endl;
		  pausa();	
		  } 
		else
		  {
		do {
		   cout<<"Qual o vestuario a vender (1-"<<nVestuarios<<")? ";
		   cin>> nVestuario; cin.ignore();
		   if (nVestuario < 1 || nVestuario > nVestuarios)
			      {
			      cout<<"N�mero de vestuarios entre 1 e "<<nVestuarios<<"."<<endl;
			      cout<<"Prima qualquer tecla para continuar ... ";
			      cin.get(); 		
			  }
		} while (nVestuario < 1 || nVestuario > nVestuarios);
		
			(*vestuarios)[nVestuario-1].mostraTudoVestuario();  
			int uVendidas = 0, nUnidades=0;
			nUnidades = (*vestuarios)[nVestuario-1].getNumUnidades(); 
			cout<<"Quantas unidades vendeu? ";
			cin >> uVendidas; cin.ignore();
			nUnidades -= uVendidas;
			(*vestuarios)[nVestuario-1].setNumUnidades(nUnidades); 
			(*vestuarios)[nVestuario-1].mostraTudoVestuario(); 
			cout<< "Venda efetuada com sucesso!"<<endl;
	pausa();
	}
} // Fim da fun��o "vendervestuario()".

//**********************************************
//*  Fun��o reporVestuario()"
//*    Entradas: vector<Vestuario> *vestuarios, int numVestuarios.
//*    Saida(s): n�o tem.
//**********************************************
	void reporVestuario(vector<Vestuario> *vestuarios)
		{ 
		int nVestuario = 0;
		int nVestuarios = vestuarios->size();
		if (nVestuarios <= 0) 
		  {
		  cout<<"N�o existem vestuarios!"<<endl;
		  pausa();	
		  } 
		else
		  {
		do {
		   cout<<"Qual o vestuario a repor (1-"<<nVestuarios<<")? ";
		   cin>> nVestuario; cin.ignore();
		   if (nVestuario < 1 || nVestuario > nVestuarios)
			      {
			      cout<<"N�mero de vestuarios entre 1 e "<<nVestuarios<<"."<<endl;
			      cout<< "Prima qualquer tecla para continuar ... ";
			      cin.get(); 		
			  }
		} while (nVestuario < 1 || nVestuario > nVestuarios);
		
			(*vestuarios)[nVestuario-1].mostraTudoVestuario();  
			int uRepostas = 0, nUnidades=0;
			nUnidades = (*vestuarios)[nVestuario-1].getNumUnidades(); 
			cout<<"Quantas unidades vai repor? ";
			cin >> uRepostas; cin.ignore();
			nUnidades += uRepostas;
			(*vestuarios)[nVestuario-1].setNumUnidades(nUnidades); 
			(*vestuarios)[nVestuario-1].mostraTudoVestuario(); 
			cout<< "Reposi��o efetuada com sucesso!"<<endl;
	pausa();
	}
} // Fim da fun��o "vendervestuario()".



//****************************************************************
//* GravarFicheiro
//****************************************************************
	void guardaFicheiro(vector<Vestuario> vestuarios)
		{
		 string caminho="", nomeFicheiro="LojaRoupa.txt";
		 string nomeCompleto = caminho + nomeFicheiro;
		 cout<<"Nome do ficheiro: "<<nomeCompleto.c_str()<<"."<<endl;
		
		   // 4. Criar o objeto e abrir o ficheiro
		   //ofstream ficheiro4(nomeCompleto.c_str());
		   ofstream ficheiro;
		   ficheiro.open(nomeCompleto, ios::out); // | ios_base::binary
		    // Modos de abertura: "ios::out" -> escrita
		
		 if(!ficheiro)  {
		 	cout<<"Ficheiro n�o foi aberto!"<<endl; 
		 	pausa();
		 }
		 else {  
		   // 4. Escrever mensagem
		   int nVestuarios = vestuarios.size(); 
		   cout<<"N�mero de vestuarios: "<<nVestuarios<<"."<<endl;
			   if (nVestuarios <= 0) 
			      {
			      cout<<"N�o existem vestuarios!"<<endl;
			      pausa();	
			      } 
			   else
			      {
			      cout<<"-> Grava��o dos vestuarios: \n";
				      for(int cVestuario=0; cVestuario<nVestuarios; cVestuario++)
					     ficheiro<<vestuarios[cVestuario];
				   // 5. Fechar o ficheiro
				   ficheiro.close();
				   cout<<"Dados gravados com sucesso!"<<endl;  
		   pausa();
		  }
	}

} // Fim da fun��o "guardaFicheiro()".

//****************************************************************
//* LerFicheiro
//****************************************************************
	void lerFicheiro(vector<Vestuario> *vestuarios)
	{
	 string caminho="", nomeFicheiro="LojaRoupa.txt";
	 string nomeCompleto = caminho + nomeFicheiro;
	 cout<<"Nome do ficheiro: "<<nomeCompleto.c_str()<<"."<<endl;   
	
	 vestuarios->erase(vestuarios->begin(),vestuarios->end());
	
	 cout<<"-> Leitura dos vestuarios: \n";
	    // 3. Criar o objeto e abrir o ficheiro
	   //ofstream ficheiro4(nomeCompleto.c_str());
	   ifstream ficheiroL;
	   ficheiroL.open(nomeCompleto, ios::in); // | ios_base::binary
	
		 if (ficheiroL.is_open ()) {  
		
		   Vestuario vestuario;
		    // 4. Leitura dos objetos
		   int contaVestuarios = 0;
		   while(ficheiroL>>vestuario && !ficheiroL.eof() )
		    {
		   	vestuarios->push_back(vestuario);
		    contaVestuarios++;
		    cout<<"Vestuario "<<contaVestuarios<<": "<<endl;
		    }
		   // 5. Fechar o ficheiro
		   ficheiroL.close();
		   cout<<endl;
	    }
}
