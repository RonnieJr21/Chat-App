/*
 @author : Ronnie Huggins

*/
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    char *ip_addr = (char *)malloc(16);
    int *port_num = (int *)malloc(4);
    strcpy(ip_addr, argv[1]);
    *port_num = atoi(argv[2]);

    /* Create the socket IPv4 address struct and fill in the required data */
    struct sockaddr_in client_address;
    inet_pton(AF_INET, ip_addr, &client_address.sin_addr.s_addr);
    client_address.sin_port = *port_num;
    client_address.sin_family = AF_INET;
    // client_address.sin_zero = memset()

    /* create a socket uses IPv4 and TCP/IP stream for communication */
    int clientServer_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (clientServer_fd == -1)
        perror("There was an error creating the socket...");
    if (connect(clientServer_fd, (struct sockaddr *)&client_address, sizeof(client_address)) == -1)
        perror("There was an error connecting");
    printf("ip -> %s - port -> %d", ip_addr, *port_num);

    free(ip_addr);
    free(port_num);
    return 0;
}