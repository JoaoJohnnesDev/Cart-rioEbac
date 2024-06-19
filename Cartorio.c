#include <stdio.h> // Biblioteca de Comunica��o com o usu�rio 
#include <stdlib.h> // Biblioteca de Aloca��o de espa�o em Mem�ria
#include <locale.h> // Biblioteca de Aloca��o de texto por Regi�o
#include <string.h> // Biblioteca Respons�vel por cuidar das Strings
// Primeiro Projeto de muitos :D 

// fun��es e instru��es
int Registro() 
{
	
	setlocale(LC_ALL, "portuguese"); // Definindo a Linguagem
	
	// Declarando as Strings com nome das Vari�veis(40) a serem armazenadas no Banco de Dados
    char Arquivo[40];
    char CPF[40];
	char Nome[40];
	char Sobrenome[40];
	char Cargo[40];

    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", CPF);
    
    strcpy(Arquivo, CPF);          // Respons�vel por Igualar os dados das Vari�veis nas strings
    
    FILE *file;                   // Cria o Arquivo de Bloco de Notas na Pasta do Sistema
    
    file = fopen(Arquivo, "w");                           // Cria "w" e abre o Bloco de notas 
    fprintf(file, "CPF: ");                        // Define como "CPF:" um nome antes da Vari�vel CPF
    fprintf(file,CPF);                      // Salva o Valor da vari�vel dentro do arquivo
    fclose(file);                 // Fecha o Arquivo
    
    file = fopen(Arquivo, "a");                           // Abre o Arquivo novamente e atualiza uma informa��o "a"
    fprintf(file,"\nNome: ");                      // Define como "Nome:" um nome antes da Variavel Nome
    fclose(file);                           // fecha o arquivo

    printf("\nDigite o Nome a ser cadastrado: ");         // Sistema pede ao cliente um nome a ser cadastrado
    scanf("%s", Nome);                             // Sistema Armazena esse nome na Vari�vel "Nome" 
    
    file = fopen(Arquivo, "a");                          // Abre o Arquivo e atualiza
    fprintf(file,Nome);                           // Salva o valor da vari�vel Nome dentro do arquivo
    fclose(file);                          // Fecha o arquivo
    
    file = fopen(Arquivo, "a");                          // Abre o arquivo e atualiza
    fprintf(file, "\nSobrenome: ");              // Define como "Sobrenome:" um nome antes da Vari�vel Sobrenome
    fclose(file);                         // Fecha o arquivo
    
    printf("\nDigite o Sobrenome a ser cadastrado: ");   // Sistema pede ao cliente um Sobrenome a ser cadastrado
    scanf("%s", Sobrenome);                     // Sistema armazena esse Sobrenome na vari�vel "Sobrenome"
    
    file = fopen(Arquivo, "a");                          // Abre o arquivo e atualiza
    fprintf(file,Sobrenome);                    // Salva o valor da vari�vel Sobrenome dentro do arquivo
    fclose(file);                        // Fecha o arquivo
    
    file = fopen(Arquivo, "a");                          // Abre o arquivo e atualiza
    fprintf(file, "\nCargo: ");                // Define como "Cargo:" um nome antes da Vari�vel Cargo
    fclose(file);                        // Fecha o arquivo
    
    printf("\nDigite o Cargo a ser cadastrado: ");        // Sistema pede ao Cliente um Cargo a ser cadastrado
    scanf("%s", Cargo);                        // Sistema armazena esse Cargo na vari�vel "Cargo"
    printf("\n");                       // Da um espa�o entre 1 linha para a mensagem "Pressione qualquer tecla para continuar..
    
    file = fopen(Arquivo, "a");                          // Abre o arquivo e atualiza
    fprintf(file,Cargo);                      // Salva o valor da vari�vel Cargo dentro do arquivo
    fprintf(file,"\n\n");              // Da um espa�o de 2 linhas para mensagem "Pressione qualquer tecla para continuar..
    fclose(file);              // Fecha o arquivo
    
    
    system("pause");              // Pause o sistema entre as op��es
	
	return 0;                     
}

int Consulta()
{
	
	setlocale(LC_ALL, "portuguese"); // Definindo a Linguagem
	
	// Declarando as Strings com nome das Vari�veis(40) a serem armazenadas no Banco de Dados
	
	char CPF[40];
	char Conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");            // Sistema pede ao cliente o CPF a ser consultado
	scanf("%s",CPF);                               // Sistema armazena o CPF na vari�vel CPF
	
	FILE *file;                                          // Cria o Arquivo de Bloco de Notas na Pasta do Sistema
	file = fopen(CPF, "r");                              // Abre o CPF que est� salvo previamente com informa��es e atribui a fun��o "LER"  "r"                      
	
	if(file == NULL)                                    // Se o arquivo for igual a Nulo (NULL) 
	{
		printf("\nCPF n�o cadastrado no sistema.\n\n"); // Imprima na tela: "CPF n�o cadastrado no sistema."
		}
	else                                               // Se n�o
	    printf("\nEssas s�o as Informa��es do Usu�rio: \n\n");	// Imprima na tela: "Essas s�o as Informa��es do Usu�rio:"
	
	
	while(fgets(Conteudo, 200, file) != NULL)          // Enquanto(while) a busca (fgets) por Conteudo, 200, dentro do aquivo (file) for diferente(!=) de Nulo(NULL)
	{
		printf("%s", Conteudo);                        // Imprema na tela: " as informa��es do usu�rio como CPF, Nome, Sobrenome e Cargo."
	}
	
    fclose(file);		                            // Fecha o arquivo
	system("pause");                                  // Pausa do Sistema ao fim da Fun��o
	
	return 0;                              
}

int Deletar()
{
	
	setlocale(LC_ALL, "portuguese");        // Definindo a Linguagem por Regi�o
	
	
	// Declarando as Strings com nome das Vari�veis a serem armazenadas no Banco de Dados
	
    char CPF[40]; 
    char Conteudo[200];
    
    printf("Digite o CPF a ser deletado: "); // Sistema pede ao cliente o CPF a ser deletado
    scanf("%s",CPF);                    // Sistema armazena o CPF na vari�vel CPF
    
    FILE *file;                          // Cria o Arquivo de Bloco de Notas na Pasta do Sistema
    file = fopen(CPF, "r");                    // Abre o CPF que est� salvo previamente com informa��es e atribui a fun��o "LER"  "r"   
    
    if(file == NULL)                            // Se o arquivo for igual a Nulo (NULL) 
    {
    	printf("\nCPF n�o consta no sistema\n\n");          // Imprima na tela: "CPF n�o consta no sistema."
    	system("pause");                           // Pausa do Sistema ao fim da Fun��o
    	return 0;                       // Retorne em 0 para indicar sucesso
	}
	
	else                      // Se n�o
	{
	printf("\nCPF exclu�do com sucesso!!!\n\n");           // Imprima na tela: "CPF exclu�do com sucesso!!!"
	printf("Dados Deletados:\n\n");                         // Mensagem de dados deletados
	}
	
	while(fgets(Conteudo, 200, file) != NULL)             // Enquanto(while) a busca (fgets) por Conteudo, 200, dentro do aquivo (file) for diferente(!=) de Nulo(NULL)
         {
    	    printf("%s", Conteudo);           // Imprema na tela: " as informa��es do usu�rio como CPF, Nome, Sobrenome e Cargo."
	      }   
	      
	fclose(file);       // Fecha o Arquivo
	remove(CPF);      //Comando de remo��o sobre informa��es dentro da vari�vel CPF
	
	      
    system("pause"); 	 // Pausa do Sistema ao fim da Fun��o
	return 0;         // Retorne em 0 para indicar sucesso
}  	
	    

int main () // Fun��o Principal vinculada ao Menu
{
	setlocale (LC_ALL, "Portuguese");
	
	int opcao=0; // Definindo Vari�veis
	int laco=1;             // Vari�vel laco que ser� usada na fun��o "For" usando repeti��es
	char Nome[20]="a";              // Nome do login de Administrador
	char Senha[20];             // Senha do Administrador
	int comparacao;         // Vari�vel compara��o
	
	printf("\t### Cart�rio da EBAC ###\n\n");               // Boas vindas 
	printf("\tLogin de Administrador!!!\n\n\tDigite seu Nome e Senha:\n\n ");       // Aviso de login de administrador 
	printf("Nome: ");            // Digite o Nome
	scanf("%s",Nome);          // armazenando o Nome
	printf("\n Senha: ");       // Digite a Senha
	scanf("%s",Senha);        // armazenando a Senha
	
	
	                                             // "strcmp" Compara��o de Strings
	comparacao = strcmp(Nome,"Joao");    // Comparando usando a vari�vel "comparacao" usando strcmp � vari�vel "Nome" e atribuindo seu nome definida.
	comparacao = strcmp(Senha,"123");  //  Comparando usando a vari�vel "comparacao" usando strcmp � vari�vel "Senha" e atribuindo sua senha definida.
	 
	 
	 
	if(comparacao == 0)  // Se compara��o for igual a 0 fa�a...
	{
	        system("cls");
	
        	for(laco=1;laco=1;) // Definindo Repeti��es
    	   {
	
    	      system("cls"); // Limpa os texto
    	    
        	  setlocale(LC_ALL, "portuguese"); // Definindo a Linguagem 
	
        	  printf("### Cart�rio da EBAC ###\n\n"); // In�cio do Menu
      	      printf("Escolha a op��o desejada do Menu:\n\n");
        	  printf("\t1 - Registrar Nomes\n\n");
        	  printf("\t2 - Consultar Nomes\n\n");
        	  printf("\t3 - Deletar Nomes\n\n"); 
        	  printf("\t4 - Sair do Sistema\n\n");
        	  printf("Opc�o: "); // Fim do Menu
	          scanf("%d", &opcao); // Armazenando a Escolha do Usu�rio
	
        	  system("cls"); // Limpa os textos ao final do Menu
	  
	  
	  
        	switch(opcao) // Maneira Simplificada de Encadeamento dos If's
	            {
	       	
         	  	case 1: // In�cio das Chamadas Das Fun��es e os casos(case)
	     		Registro();
        	    break;
		 
    	    	case 2:
    		 	Consulta();
    		    break;
		 
    		    case 3:
    		 	Deletar();
    		    break;
		    
    		    case 4:
	    	    printf("\t Obrigado por utilizar o sistema!!!\n");
    		    return 0;
    	 	    break;
		 
    	  	    default:  // Fim da Sele��o
    		 	printf("\t Op��o Indispon�vel !!!  \n\n");
    	        system("pause"); // Pausa do sistema entre as op��es
    	        break;
	            }
	
	        } 
	  
	  return 0;
    }
      
      
      else  	  	  // Se n�o..
          printf("\nNome e Senha Incorretos!!!\n\n");      
          return 0;
}






