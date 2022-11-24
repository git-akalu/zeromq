
//compile as:client.c -o client -lczmq


#include <czmq.h>

int main(int argc, char **argv){

    zsock_t *requester = zsock_new(ZMQ_REQ);
    zsock_connect(requester, "tcp://localhost:1111");

    zstr_send(requester, "ZeroMq");

    sleep(1);
    char *str = zstr_recv(requester);
    printf("%s\n",str);

    zsock_destroy(&requester);
    return 0;
}
