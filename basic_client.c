#include "pipe_networking.h"


int main() {

    int to_server;
    int from_server;

    from_server = client_handshake( &to_server );

    while (1) {
        printf("Enter input: ");
        char buf[1000];
        fgets(buf, 1000, stdin);
        write(to_server, buf, 1000);
        for (int i = 0; i < 1000; i++) buf[i]=0;
        read(from_server, buf, 1000);
        printf("Output: %s\n", buf);
    }
}
