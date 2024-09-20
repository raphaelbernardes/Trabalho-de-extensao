/*###################################################################
# AUTOR: RAPHAEL ADILSON BERNARDES ##################################
# EMAIL: raphaelbernardes.dev@gmail.com #############################
# GIT: https://github.com/raphaelbernardes/Trabalho-de-extensao.git #
###################################################################*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

// Protótipo da função dostuff
void dostuff(int); 

// Função para lidar com mensagens de erro
void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno, clilen, pid;
    struct sockaddr_in serv_addr, cli_addr;

    /* Verifica se o número da porta foi fornecido como argumento
    if (argc < 2) {
        fprintf(stderr, "ERRO, porta nao fornecida\n");
        exit(1);
    }*/

    // Criação do socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERRO ao abrir o socket");

    // Zera a estrutura do endereço do servidor
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = 567;
    //portno = atoi(argv[1]); // Converte o número da porta de string para inteiro
    serv_addr.sin_family = AF_INET; // Define a família de endereços
    serv_addr.sin_addr.s_addr = INADDR_ANY; // Aceita conexões de qualquer endereco IP
    serv_addr.sin_port = htons(portno); // Define o número da porta

    // Associa o socket a um endereço (IP e porta)
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
        error("ERRO ao associar");

    // Escuta por conexões, com uma fila de espera de ate 10 conexões
    listen(sockfd, 10);
    clilen = sizeof(cli_addr);


    // Alteração feita: Loop infinito para aceitar conexões
    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) 
            error("ERRO na aceitacao");

        // Criação de um novo processo para cada conexaão
        pid = fork();
        if (pid < 0)
            error("ERRO na criacao do fork");

        // Processo-filho
        if (pid == 0)  {
            close(sockfd); // Fecha o socket original no processo-filho
            dostuff(newsockfd); // Chama a função dostuff para lidar com a conexão
            exit(0); // Encerra o processo-filho
        } else {
            close(newsockfd); // Processo-pai fecha o novo socket
        }
    } /* fim do while */
    return 0; /* nunca chegamos aqui */
}

// Há uma instância separada dessa função para cada conexão. 
// Ela lida com toda a comunicação uma vez que uma conexão tenha sido estabelecida.
void dostuff (int sock)
{
    int n;
    char buffer[1000];
    
    bzero(buffer, 1000); // Zera o buffer
    n = read(sock, buffer, 1000); // Lê dados do socket
    if (n < 0) error("ERRO ao ler do socket");
    
    arquivar(buffer);// arquiva em arquivo o buffer recebido do cliente
    
    printf("Mensagem recebida do cliente: %s\n", buffer); // Exibe a mensagem recebida
    n = write(sock, "OK", 2); // Envia resposta para o cliente
    if (n < 0) error("ERRO ao escrever no socket");
} 


void arquivar(char str_recebida[1000]){
	
	char cpf[15];//nome do arquivo gerado
	
	strncpy(cpf, str_recebida, 11); //obtem o cpf que será a primeira informação recebida do cliente
	strcat(cpf,".txt");//constroi dinamicamente o nome do arquivo
	
	FILE *arq_txt;
	arq_txt = fopen( cpf ,"a+");
	fprintf(arq_txt, "%s\n",str_recebida);
	fclose(arq_txt);
} 
