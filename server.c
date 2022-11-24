#include <czmq.h>

int main(int argc, char **argv){


    zsock_t *responder = zsock_new(ZMQ_REP);
    int r = zsock_bind(responder, "tcp://*:5555");
    if (r != 5555){
        printf("faild port");

    }

    while(true){
        char *msg = zstr_recv(responder);
        if(!strcmp(msg,"Low Level"))
        {
            zstr_send(responder, "Hi");
        }

        free(msg);
    }

zsock_destroy(&responder);
return 0;

}