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
		#include <vector>
		using namespace std; 

	// DESLOCAMENTO ENCRIPTA��O
	const int DESLOCAMENTO = 3;


	// Defini��o da classe
	class Vestuario
	{
	 private:   
		    // Dados devem ser privados	
		    //*   - c�digo do vestuario -> posi��o no vetor
		    string categoria;
		    string tipo;
		    string cor;
		    string materiaPrima;
		    float preco;
		    string tamanho;
		    int numSecao;
		    char letraPrateleira;
		    int numUnidades;
		    int indiceQuebra;
    
  
//****************************************************
//* Fun��o encripta()
//****************************************************
	string  encripta(string mensagemO, int desl)
		{
		const int MaxChars = 100;	
		char mensagem[MaxChars];
		for(int cLetra=0; cLetra<MaxChars; cLetra++) 
		                         mensagem[cLetra]='\0';
		                         
		strcpy(mensagem,mensagemO.c_str());
						 	
// for(int cLetra=0; cLetra< mensagemO.length(); cLetra++)
//    mensagem[cLetra]=toupper(mensagem[cLetra]);

	for(int cLetra=0; cLetra< mensagemO.length(); cLetra++)	
	   {
	   	int valor = (int)mensagem[cLetra] + desl;
		   	if ( ((valor) > 90 && isupper(mensagem[cLetra]))
			    || ((valor) > 122 && islower(mensagem[cLetra]))
			   )
			   valor = valor - 26;
				if (mensagem[cLetra]=='.')
				   mensagem[cLetra] ='.';
			else   
		   	   mensagem[cLetra] = valor; 
  		}
	//cout<<mensagem;	
	return mensagem;	
}

//****************************************************
//* Fun��o desencripta()
//****************************************************
	string  desencripta(string mensagemE, int desl)
		{
		const int MaxChars = 100;	
		char mensagem[MaxChars];
		for(int cLetra=0; cLetra<MaxChars; cLetra++) 
		                         mensagem[cLetra]='\0';
		                         
		strcpy(mensagem,mensagemE.c_str());
						 	
//for(int cLetra=0; cLetra< mensagemO.length(); cLetra++)
//    mensagem[cLetra]=toupper(mensagem[cLetra]);

	for(int cLetra=0; cLetra< mensagemE.length(); cLetra++)	
	   {
	   	int valor = (int)mensagem[cLetra] - desl;
	   	if ( ((valor) < 65 && isupper(mensagem[cLetra]))
		    || ((valor) < 97 && islower(mensagem[cLetra]))
		   )
		   
	   	   valor = valor + 26;
			if (mensagem[cLetra]=='.')
			   mensagem[cLetra] ='.';
			else   
		   	   mensagem[cLetra] = valor; 	
	   }
	//cout<<mensagem;	
	return mensagem;	
}

//****************************************************
//* Fun��o desencripta()
//****************************************************
	char*  desencriptaII(char mensagemE[], int desl)
		{
		const int MaxChars = 100;	
		char mensagem[MaxChars];
		for(int cLetra=0; cLetra<MaxChars; cLetra++) 
		                         mensagem[cLetra]='\0';
		                         
		strcpy(mensagem,mensagemE);
						 	
//for(int cLetra=0; cLetra< mensagemO.length(); cLetra++)
//    mensagem[cLetra]=toupper(mensagem[cLetra]);

	for(int cLetra=0; cLetra< strlen(mensagemE); cLetra++)	
	   {
	   	int valor = (int)mensagem[cLetra] - desl;
	   	if ( ((valor) < 65 && isupper(mensagem[cLetra]))
		    || ((valor) < 97 && islower(mensagem[cLetra]))
		   )
		   
	   	   valor = valor + 26;
			if (mensagem[cLetra]=='.')
			   mensagem[cLetra] ='.';
		else   
		   	mensagem[cLetra] = valor; 	
   }
//cout<<mensagem;	
return mensagem;	
}    


//****************************************************
//* Fun��o desencripta()
//****************************************************
	void  desencriptaIII(char mensagemE[], int desl,char mensagemO[])
		{
		const int MaxChars = 100;	
		char mensagem[MaxChars];
		for(int cLetra=0; cLetra<MaxChars; cLetra++) 
		                         mensagem[cLetra]='\0';
		                         
		strcpy(mensagem,mensagemE);
						 	
//for(int cLetra=0; cLetra< mensagemO.length(); cLetra++)
//    mensagem[cLetra]=toupper(mensagem[cLetra]);

	for(int cLetra=0; cLetra< strlen(mensagemE); cLetra++)	
	   {
	   	int valor = (int)mensagem[cLetra] - desl;
	   	if ( ((valor) < 65 && isupper(mensagem[cLetra]))
		    || ((valor) < 97 && islower(mensagem[cLetra]))
		   )
		   
	   	   valor = valor + 26;
			if (mensagem[cLetra]=='.')
			   mensagem[cLetra] ='.';
		else   
	   	   mensagem[cLetra] = valor; 	
   }
//cout<<mensagem;	
strcpy(mensagemO,mensagem);	
}    

	public:    // Fun��es devem ser p�blicas 
    // Dados est�ticos
    static int numVestuarios;
    
    // 2. Fun��es
    // 2.0 Fun��es de inicializa��o
    void inicializaVestuario()
	     {
	     categoria =""; tipo =""; cor =""; materiaPrima =""; preco=0; tamanho="";
	     numSecao =0; letraPrateleira = '\0';numUnidades = 0;
		 indiceQuebra = 0;
	 }
    
    // 2.1  Fun��es construtoras
    //      Servem para inicializar os dados de cada objeto.
    // 2.1.1 Construtor sem argumentos
    Vestuario()
	     {
	     categoria =""; tipo=""; cor="";materiaPrima=""; preco=0; tamanho="";
	     numSecao =0; letraPrateleira = '\0'; numUnidades = 0; 
		 indiceQuebra = 0;	
	 }
	 
	// 2.1.2 Construtor com argumentos
	Vestuario(string aut, string tit) 
		 {
	     categoria.assign(aut); tipo=tit; cor.assign(aut); materiaPrima.assign(aut); preco=0; tamanho="";
	     numSecao =0; letraPrateleira = '\0';
		 numUnidades = 0; indiceQuebra = 0; 	
	 }
  
    // 2.1.3 Construtor com argumentos II
	Vestuario(string aut, string tit, int numA, char letraP) 
		 {
	     categoria.assign(aut); tipo=tit; cor.assign(aut); materiaPrima.assign(aut); preco=0; tamanho="";
	     numSecao =numA; letraPrateleira = letraP;
		 numUnidades = 0; 	indiceQuebra = 0;
	 }    
	 
	// 2.2 Destrutor
	//     C�digo que � executado antes de um objeto
	//     sair de mem�ria.
    ~Vestuario() {
	         }
	
	// 2.3 Setters
	//     Permitem a atribui��o de valores a cada 
	//     dado de um objeto.
	void setCategoria  (string a)  { categoria = a;}
	void setTipo (string t)  { tipo = t;}
	void setCor(string a)  { cor = a;}
	void setMateriaPrima(string a)  { materiaPrima = a;}
	void setTamanho    (string a)     { tamanho = a;}
	void setPreco  (float p)   { preco = p;}
	void setNumSecao(int na) { numSecao = na;}
	void setLetraPrateleira  (char lp)   
	                           { letraPrateleira = lp;}
	void setNumUnidades(int nu)   
	                           { numUnidades = nu;}	
	void setIndiceQuebra(int iq)   
	                           { indiceQuebra = iq;}							   	
	         
	// 2.4 Getters
	//     Permitem a obten��o do valor de  cada 
	//     dado de um objeto.
	string getCategoria  ()       	{ return categoria;}
	string getTipo ()       		{ return tipo;}
	string getCor()       			{ return cor;}
	string getMateriaPrima()       	{ return materiaPrima;}
	string getTamanho    ()         { return tamanho;}
	float getPreco  ()        		{ return preco;}
	int getNumSecao()       		{ return numSecao;}
	char getLetraPrateleira() 		{ return letraPrateleira;}
	int getNumUnidades()      		{ return numUnidades;}
	int getIndiceQuebra()     		{ return indiceQuebra;}
	
	// 2.5 Fun��es de Leitura
	void leCategoria()
	  {
	  const int MaxChars = 40;	
	  char letras[MaxChars];
	  for (int cLetra=0; cLetra<MaxChars; cLetra++)
	                      letras[cLetra]='\0';
						  	
	  cout<<"Qual o categoria do vestu�rio?(homem/mulher/cria�a) ";
	  cin.getline(letras, sizeof(letras),'\n');
	  setCategoria(string(letras));
      }
	  	
	void leTipo()
	  {
	  const int MaxChars = 40;	
	  char letras[MaxChars];
	  for (int cLetra=0; cLetra<MaxChars; cLetra++)
	                      letras[cLetra]='\0';
						  	
	  cout<<"Qual o tipo do vestu�rio? ";
	  cin.getline(letras, sizeof(letras),'\n');
	  setTipo(string(letras));
      }
	  	
	void leCor()
	  {
	  const int MaxChars = 40;	
	  char letras[MaxChars];
	  for (int cLetra=0; cLetra<MaxChars; cLetra++)
	                      letras[cLetra]='\0';
						  	
	  cout<<"Qual a cor do vestu�rio? ";
	  cin.getline(letras, sizeof(letras),'\n');
	  setCor(string(letras));
      }
    void leMateriaPrima()
	  {
	  const int MaxChars = 40;	
	  char letras[MaxChars];
	  for (int cLetra=0; cLetra<MaxChars; cLetra++)
	                      letras[cLetra]='\0';
						  	
	  cout<<"Qual foi a mat�ria-prima usada? ";
	  cin.getline(letras, sizeof(letras),'\n');
	  setCor(string(letras));
      }
	  	
	void leTamanho()
	  {
	  const int MaxChars = 40;	
	  char letras[MaxChars];
	  for (int cLetra=0; cLetra<MaxChars; cLetra++)
	                      letras[cLetra]='\0';				  	
	  cout<<"Qual o tamanho do vestu�rio? ";
	  cin.getline(letras, sizeof(letras),'\n');
	  setTamanho(string(letras));  
	}
	  	
	void lePreco()
	  {
	  const int MaxChars = 40;	
	  char letras[MaxChars];
	  for (int cLetra=0; cLetra<MaxChars; cLetra++)
	                      letras[cLetra]='\0';				  	
	  cout<<"Qual o pre�o do vestu�rio? ";
	  cin.getline(letras, sizeof(letras),'\n');
	  setPreco(atof(letras));
	      // atof() - ascii to float- converte 
	      //          array de chars para float
      }	  	  	  	
	  		  	
	void leNumSecao()
	  {
	  const int MaxChars = 40;	
	  char letras[MaxChars];
	  for (int cLetra=0; cLetra<MaxChars; cLetra++)
	                      letras[cLetra]='\0';				  	
	  cout<<"Qual o n�mero da se��o onde o vestu�rio est�? ";
	  cin.getline(letras, sizeof(letras),'\n');
	  setNumSecao(atoi(letras));
      }	  	
	  
	void leLetraPrateleira()
	  {
      char letra = '\0';	
	  cout<<"Qual a letra da estante? ";
	  cin>>letra; 	  
	  if (isalpha(letra)) letra=toupper(letra); 
	  cin.ignore();  // fflush(stdin);
	  setLetraPrateleira(letra);
      }			

	void leNumUnidades()
	  {
	  const int MaxChars = 40;	
	  char letras[MaxChars];
	  for (int cLetra=0; cLetra<MaxChars; cLetra++)
	                      letras[cLetra]='\0';				  	
	  cout<<"Quantas unidades existem deste vestu�rio? ";
	  cin.getline(letras, sizeof(letras),'\n');
	  setNumUnidades(atoi(letras));
      }	 
	  
	void leIndiceQuebra()
	  {
	  const int MaxChars = 40;	
	  char letras[MaxChars];
	  for (int cLetra=0; cLetra<MaxChars; cLetra++)
	                      letras[cLetra]='\0';				  	
	  cout<<"Qual o �ndice de quebra? ";
	  cin.getline(letras, sizeof(letras),'\n');
	  setIndiceQuebra(atoi(letras));
      }	 	  	
	
	void leTudoVestuario()
	  {
	  leCategoria(); leTipo(); leCor(); leMateriaPrima();
	  leTamanho(); lePreco(); leNumSecao();
	  leLetraPrateleira(); leNumUnidades();	
	  leIndiceQuebra();
	  }
	  
	// 2.6 Fun��es de Escrita
	void mostraCategoria()
	   { cout<< "Categoria: "<<getCategoria()<<"."<<endl; }  

	void mostraTipo()
	   { cout<< "Tipo: "<<getTipo()<<"."<<endl; } 
	   
	void mostraCor()
	   { cout<< "Cor: "<<getCor()<<"."<<endl; }  
	   
	void mostraMateriaPrima()
	   { cout<< "Mat�ria-Prima: "<<getMateriaPrima()<<"."<<endl; } 
	    
	void mostraTamanho()
	   { cout<< "Tamanho: "<<getTamanho()<<"."<<endl; } 

	void mostraPreco()
	   { 
	   cout<<fixed<<setprecision(2);
	   cout<< "Pre�o s/IVA: "<<getPreco()<<" euros."<<endl;
	   cout<< "Pre�o c/IVA: "<<obtemPrecoComIVA(getPreco());
	   cout<<" euros."<<endl;
	   } 

	void mostraNumSecao()
	{ cout<< "N.� Se��o: "<<getNumSecao()<<"."<<endl; } 

	void mostraLetraPrateleira()
	{ cout<<"Estante: "<<getLetraPrateleira()<<"."<<endl;}

	void mostraNumUnidades()
	{ cout<<"N.� Unidades: "<<getNumUnidades()<<"."<<endl; } 

	void mostraIndiceQuebra()
	{ cout<<"�ndice quebra: "<<getIndiceQuebra()<<"."<<endl;} 

    void mostraTudoVestuario()
       { mostraCategoria(); mostraTipo(); mostraCor();
         mostraTamanho(); mostraPreco(); mostraNumSecao();
         mostraLetraPrateleira(); mostraNumUnidades();
         mostraIndiceQuebra();
       }
       
    // Outras Fun��es
	static float obtemPrecoComIVA(float psi)
	  {
	  const float IvaVestuario = 0.23;
	  return (psi*(1+IvaVestuario));	
	  }
	   
	static float obtemPrecoSemIVA(float pci)
	  {
	  const float IvaVestuario = 0.23;
	  return (pci/(1+IvaVestuario));	
	  }  
	  
//*************************************************************************************
//* Redefini��o do operador ">>"
//**************************************************************************************
	friend istream& operator>> (istream& is, Vestuario& liv)
	    {
	  	char letra='\0';
			
	    { 
		const int MaxNome = 40; char texto[MaxNome];
		for(int cLetra= 0; cLetra < MaxNome; cLetra++) 
		                            texto[cLetra]= '\0';
		is.getline(texto, MaxNome, '\n');
		liv.setTipo(liv.desencripta(string(texto),DESLOCAMENTO)); 
	    }
		
		{ 
		const int MaxNome = 40; char texto[MaxNome];
		for(int cLetra= 0; cLetra<MaxNome;cLetra++) texto[cLetra]= '\0';
		is.getline(texto, MaxNome, '\n');
		liv.setCategoria(liv.desencripta(string(texto),DESLOCAMENTO));
		}
	
		{ 
		const int MaxNome = 40; char texto[MaxNome];
		for(int cLetra= 0; cLetra<MaxNome;cLetra++) texto[cLetra]= '\0';
		is.getline(texto, MaxNome, '\n');
		liv.setCor(liv.desencripta(string(texto),DESLOCAMENTO));
	    }
		
		{ 
		const int MaxNome = 40; char texto[MaxNome];
		for(int cLetra= 0; cLetra<MaxNome;cLetra++) texto[cLetra]= '\0';
		is.getline(texto, MaxNome, '\n');
		liv.setMateriaPrima(liv.desencripta(string(texto),DESLOCAMENTO));
	    }
	    
	    { 
		const int MaxNome = 40; char texto[MaxNome];
		for(int cLetra= 0; cLetra<MaxNome;cLetra++)
		                                     texto[cLetra]= '\0';
		is.getline(texto, MaxNome, '\n');
		liv.setTamanho(liv.desencripta(string(texto),DESLOCAMENTO));
	    }
	   
		{ 
		const int MaxNome = 40; char texto[MaxNome];
		for(int cLetra= 0; cLetra<MaxNome;cLetra++) texto[cLetra]= '\0';
		is.getline(texto, MaxNome, '\n');
		strcpy(texto,liv.desencriptaII(texto,DESLOCAMENTO) );
	    liv.setPreco(atof(texto));
		}                   
		 
						
		{ 
		const int MaxNome = 40; char texto[MaxNome];
		for(int cLetra= 0; cLetra<MaxNome;cLetra++)
		                                     texto[cLetra]= '\0';
		is.getline(texto, MaxNome, '\n');
		strcpy(texto,liv.desencriptaII(texto,DESLOCAMENTO) );
	    liv.setNumUnidades(atoi(texto));
		}										 	
	     
		{ 
		const int MaxNome = 40; char texto[MaxNome];
		for(int cLetra= 0; cLetra<MaxNome;cLetra++)
		                                     texto[cLetra]= '\0';
		is.getline(texto, MaxNome, '\n');
		strcpy(texto,liv.desencriptaII(texto,DESLOCAMENTO) );
	    liv.setIndiceQuebra(atoi(texto));
		}	                 
						  
		{ 
		const int MaxNome = 40; char texto[MaxNome];
		for(int cLetra= 0; cLetra<MaxNome;cLetra++)
		                                     texto[cLetra]= '\0';
		is.getline(texto, MaxNome, '\n');
		strcpy(texto,liv.desencriptaII(texto,DESLOCAMENTO) );
	    liv.setNumSecao(atoi(texto));
		}					  
						  		
		{ 
		const int MaxNome = 40; char texto[MaxNome];
		for(int cLetra= 0; cLetra<MaxNome;cLetra++)
		                                     texto[cLetra]= '\0';
		is.getline(texto, MaxNome, '\n');
		strcpy(texto,liv.desencriptaII(texto,DESLOCAMENTO) );
	    liv.setLetraPrateleira(atoi(texto));
		}	  
		
	    is.ignore(); 	
	    return is;
}


//*************************************************************************************
//* Redefini��o do operador "<<"
//**************************************************************************************
	friend ostream& operator<< (ostream& os, Vestuario& liv)
		{
		
			os << liv.encripta(liv.getTipo(),DESLOCAMENTO)<<endl;  	
			os << liv.encripta(liv.getCategoria(),DESLOCAMENTO)<<endl;
			os << liv.encripta(liv.getCor(),DESLOCAMENTO)<<endl;
			os << liv.encripta(liv.getMateriaPrima(),DESLOCAMENTO)<<endl;
			os << liv.encripta(liv.getTamanho(),DESLOCAMENTO)<<endl;  	
			os << liv.encripta(to_string(liv.getPreco()),DESLOCAMENTO)<<endl;
			os << liv.encripta(to_string(liv.getNumUnidades()),DESLOCAMENTO)<<endl;
			os << liv.encripta(to_string(liv.getIndiceQuebra()),DESLOCAMENTO)<<endl;
			os << liv.encripta(to_string(liv.getNumSecao()),DESLOCAMENTO)<<endl;  	
			os << liv.encripta(to_string(liv.getLetraPrateleira()),DESLOCAMENTO)<<endl;
			os << endl;	  	
    return os;
	}     
}; // Fim da classe
