#include "pipe_networking.h"

char sparkle[] = {0xE2, 0x9C, 0xA8, '\0'};

static void sighandler(int signo) {
    if (signo==SIGINT) {
        printf("\n%s Thank you for coming %s\n", sparkle, sparkle);
        exit(0);
    }
}

int main() {
    signal(SIGINT, sighandler);

    int to_server;
    int from_server;

    printf("%s Capitalization Tool %s\n", sparkle, sparkle);

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
