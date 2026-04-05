#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <cstring>

using namespace std;

int main(){

    int fd=open("pipe_db",O_WRONLY);
    if (fd == -1) {
        cout<<"Erro ao abrir o pipe. O servidor esta rodando?"<<endl;
        return 1;
    }

    char comando[100];

    while(true){
        cout<<"Digite comando (ou SAIR para encerrar):"<<endl;
        cout<<"INSERT id nome | SELECT id | DELETE id | UPDATE id nome"<<endl<<endl;

        cin.getline(comando,100);
        if(strcmp(comando, "SAIR") == 0) break;

        write(fd,comando,strlen(comando)+1);
    }

    close(fd);

    return 0;
}
