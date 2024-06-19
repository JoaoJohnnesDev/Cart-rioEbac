#include <stdio.h> // Biblioteca de Comunicação com o usuário 
#include <stdlib.h> // Biblioteca de Alocação de espaço em Memória
#include <locale.h> // Biblioteca de Alocação de texto por Região
#include <string.h> // Biblioteca Responsável por cuidar das Strings
// Primeiro Projeto de muitos :D 

// funções e instruções
int Registro() 
{
	
	setlocale(LC_ALL, "portuguese"); // Definindo a Linguagem
	
	// Declarando as Strings com nome das Variáveis(40) a serem armazenadas no Banco de Dados
    char Arquivo[40];
    char CPF[40];
	char Nome[40];
	char Sobrenome[40];
	char Cargo[40];

    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", CPF);
    
    strcpy(Arquivo, CPF);          // Responsável por Igualar os dados das Variáveis nas strings
    
    FILE *file;                   // Cria o Arquivo de Bloco de Notas na Pasta do Sistema
    
    file = fopen(Arquivo, "w");                           // Cria "w" e abre o Bloco de notas 
    fprintf(file, "CPF: ");                        // Define como "CPF:" um nome antes da Variável CPF
    fprintf(file,CPF);                      // Salva o Valor da variável dentro do arquivo
    fclose(file);                 // Fecha o Arquivo
    
    file = fopen(Arquivo, "a");                           // Abre o Arquivo novamente e atualiza uma informação "a"
    fprintf(file,"\nNome: ");                      // Define como "Nome:" um nome antes da Variavel Nome
    fclose(file);                           // fecha o arquivo

    printf("\nDigite o Nome a ser cadastrado: ");         // Sistema pede ao cliente um nome a ser cadastrado
    scanf("%s", Nome);                             // Sistema Armazena esse nome na Variável "Nome" 
    
    file = fopen(Arquivo, "a");                          // Abre o Arquivo e atualiza
    fprintf(file,Nome);                           // Salva o valor da variável Nome dentro do arquivo
    fclose(file);                          // Fecha o arquivo
    
    file = fopen(Arquivo, "a");                          // Abre o arquivo e atualiza
    fprintf(file, "\nSobrenome: ");              // Define como "Sobrenome:" um nome antes da Variável Sobrenome
    fclose(file);                         // Fecha o arquivo
    
    printf("\nDigite o Sobrenome a ser cadastrado: ");   // Sistema pede ao cliente um Sobrenome a ser cadastrado
    scanf("%s", Sobrenome);                     // Sistema armazena esse Sobrenome na variável "Sobrenome"
    
    file = fopen(Arquivo, "a");                          // Abre o arquivo e atualiza
    fprintf(file,Sobrenome);                    // Salva o valor da variável Sobrenome dentro do arquivo
    fclose(file);                        // Fecha o arquivo
    
    file = fopen(Arquivo, "a");                          // Abre o arquivo e atualiza
    fprintf(file, "\nCargo: ");                // Define como "Cargo:" um nome antes da Variável Cargo
    fclose(file);                        // Fecha o arquivo
    
    printf("\nDigite o Cargo a ser cadastrado: ");        // Sistema pede ao Cliente um Cargo a ser cadastrado
    scanf("%s", Cargo);                        // Sistema armazena esse Cargo na variável "Cargo"
    printf("\n");                       // Da um espaço entre 1 linha para a mensagem "Pressione qualquer tecla para continuar..
    
    file = fopen(Arquivo, "a");                          // Abre o arquivo e atualiza
    fprintf(file,Cargo);                      // Salva o valor da variável Cargo dentro do arquivo
    fprintf(file,"\n\n");              // Da um espaço de 2 linhas para mensagem "Pressione qualquer tecla para continuar..
    fclose(file);              // Fecha o arquivo
    
    
    system("pause");              // Pause o sistema entre as opções
	
	return 0;                     
}

int Consulta()
{
	
	setlocale(LC_ALL, "portuguese"); // Definindo a Linguagem
	
	// Declarando as Strings com nome das Variáveis(40) a serem armazenadas no Banco de Dados
	
	char CPF[40];
	char Conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");            // Sistema pede ao cliente o CPF a ser consultado
	scanf("%s",CPF);                               // Sistema armazena o CPF na variável CPF
	
	FILE *file;                                          // Cria o Arquivo de Bloco de Notas na Pasta do Sistema
	file = fopen(CPF, "r");                              // Abre o CPF que está salvo previamente com informações e atribui a função "LER"  "r"                      
	
	if(file == NULL)                                    // Se o arquivo for igual a Nulo (NULL) 
	{
		printf("\nCPF não cadastrado no sistema.\n\n"); // Imprima na tela: "CPF não cadastrado no sistema."
		}
	else                                               // Se não
	    printf("\nEssas são as Informações do Usuário: \n\n");	// Imprima na tela: "Essas são as Informações do Usuário:"
	
	
	while(fgets(Conteudo, 200, file) != NULL)          // Enquanto(while) a busca (fgets) por Conteudo, 200, dentro do aquivo (file) for diferente(!=) de Nulo(NULL)
	{
		printf("%s", Conteudo);                        // Imprema na tela: " as informações do usuário como CPF, Nome, Sobrenome e Cargo."
	}
	
    fclose(file);		                            // Fecha o arquivo
	system("pause");                                  // Pausa do Sistema ao fim da Função
	
	return 0;                              
}

int Deletar()
{
	
	setlocale(LC_ALL, "portuguese");        // Definindo a Linguagem por Região
	
	
	// Declarando as Strings com nome das Variáveis a serem armazenadas no Banco de Dados
	
    char CPF[40]; 
    char Conteudo[200];
    
    printf("Digite o CPF a ser deletado: "); // Sistema pede ao cliente o CPF a ser deletado
    scanf("%s",CPF);                    // Sistema armazena o CPF na variável CPF
    
    FILE *file;                          // Cria o Arquivo de Bloco de Notas na Pasta do Sistema
    file = fopen(CPF, "r");                    // Abre o CPF que está salvo previamente com informações e atribui a função "LER"  "r"   
    
    if(file == NULL)                            // Se o arquivo for igual a Nulo (NULL) 
    {
    	printf("\nCPF não consta no sistema\n\n");          // Imprima na tela: "CPF não consta no sistema."
    	system("pause");                           // Pausa do Sistema ao fim da Função
    	return 0;                       // Retorne em 0 para indicar sucesso
	}
	
	else                      // Se não
	{
	printf("\nCPF excluído com sucesso!!!\n\n");           // Imprima na tela: "CPF excluído com sucesso!!!"
	printf("Dados Deletados:\n\n");                         // Mensagem de dados deletados
	}
	
	while(fgets(Conteudo, 200, file) != NULL)             // Enquanto(while) a busca (fgets) por Conteudo, 200, dentro do aquivo (file) for diferente(!=) de Nulo(NULL)
         {
    	    printf("%s", Conteudo);           // Imprema na tela: " as informações do usuário como CPF, Nome, Sobrenome e Cargo."
	      }   
	      
	fclose(file);       // Fecha o Arquivo
	remove(CPF);      //Comando de remoção sobre informações dentro da variável CPF
	
	      
    system("pause"); 	 // Pausa do Sistema ao fim da Função
	return 0;         // Retorne em 0 para indicar sucesso
}  	
	    

int main () // Função Principal vinculada ao Menu
{
	setlocale (LC_ALL, "Portuguese");
	
	int opcao=0; // Definindo Variáveis
	int laco=1;             // Variável laco que será usada na função "For" usando repetições
	char Nome[20]="a";              // Nome do login de Administrador
	char Senha[20];             // Senha do Administrador
	int comparacao;         // Variável comparação
	
	printf("\t### Cartório da EBAC ###\n\n");               // Boas vindas 
	printf("\tLogin de Administrador!!!\n\n\tDigite seu Nome e Senha:\n\n ");       // Aviso de login de administrador 
	printf("Nome: ");            // Digite o Nome
	scanf("%s",Nome);          // armazenando o Nome
	printf("\n Senha: ");       // Digite a Senha
	scanf("%s",Senha);        // armazenando a Senha
	
	
	                                             // "strcmp" Comparação de Strings
	comparacao = strcmp(Nome,"Joao");    // Comparando usando a variável "comparacao" usando strcmp à variável "Nome" e atribuindo seu nome definida.
	comparacao = strcmp(Senha,"123");  //  Comparando usando a variável "comparacao" usando strcmp à variável "Senha" e atribuindo sua senha definida.
	 
	 
	 
	if(comparacao == 0)  // Se comparação for igual a 0 faça...
	{
	        system("cls");
	
        	for(laco=1;laco=1;) // Definindo Repetições
    	   {
	
    	      system("cls"); // Limpa os texto
    	    
        	  setlocale(LC_ALL, "portuguese"); // Definindo a Linguagem 
	
        	  printf("### Cartório da EBAC ###\n\n"); // Início do Menu
      	      printf("Escolha a opção desejada do Menu:\n\n");
        	  printf("\t1 - Registrar Nomes\n\n");
        	  printf("\t2 - Consultar Nomes\n\n");
        	  printf("\t3 - Deletar Nomes\n\n"); 
        	  printf("\t4 - Sair do Sistema\n\n");
        	  printf("Opcão: "); // Fim do Menu
	          scanf("%d", &opcao); // Armazenando a Escolha do Usuário
	
        	  system("cls"); // Limpa os textos ao final do Menu
	  
	  
	  
        	switch(opcao) // Maneira Simplificada de Encadeamento dos If's
	            {
	       	
         	  	case 1: // Início das Chamadas Das Funções e os casos(case)
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
		 
    	  	    default:  // Fim da Seleção
    		 	printf("\t Opção Indisponível !!!  \n\n");
    	        system("pause"); // Pausa do sistema entre as opções
    	        break;
	            }
	
	        } 
	  
	  return 0;
    }
      
      
      else  	  	  // Se não..
          printf("\nNome e Senha Incorretos!!!\n\n");      
          return 0;
}






