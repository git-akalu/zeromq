
//compile as: gcc server.c -o server -lczmq

#include <czmq.h>

int main(int argc, char **argv){


    zsock_t *responder = zsock_new(ZMQ_REP);
    int r = zsock_bind(responder, "tcp://*:1111");
    if (r != 5555){
        printf("faild port");

    }

    while(true){
        char *msg = zstr_recv(responder);
        if(!strcmp(msg,"ZeroMq"))
        {
            zstr_send(responder, "That's right");
        }

        free(msg);
    }

zsock_destroy(&responder);
return 0;

}
