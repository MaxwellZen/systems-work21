#include "pipe_networking.h"


int main() {

    int to_client;
    int from_client;

    while (1) {

        from_client = server_handshake( &to_client );

        char buf[1000];
        for (int i = 0; i < 1000; i++) buf[i]=0;

        while (read(from_client, buf, 1000) != 0) {
            for (int i = 0; buf[i]; i++) {
                if (buf[i] >= 'a' && buf[i] <= 'z') buf[i] = buf[i] - 'a' + 'A';
            }
            write(to_client, buf, 1000);
            for (int i = 0; buf[i]; i++) buf[i] = 0;
        }
    }
}
