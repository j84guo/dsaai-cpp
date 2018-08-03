#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define PORT 5000
#define BUFFER_SIZE 65535

/*
* struct in_addr or struct in6_addr
*/
void print_address(void *addr, sa_family_t family)
{
  char buffer[INET6_ADDRSTRLEN];

  if(inet_ntop(family, addr, buffer, sizeof buffer) == NULL)
  {
    perror("inet_ntop");
    return;
  }

  printf("%s\n", buffer);
}

/*
* #include <sys/types.h>
* #include <sys/socket.h>
*
* // note that the socket should have called bind() with an address and port
* int recvfrom(int socket, void* buffer, size_t length, int flags,
*   struct sockaddr *src_addr, socklen_t *src_len);
*/
int main()
{
  /*
  * prepare server
  */
  int sd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  if(sd == -1)
  {
    perror("socket");
    return 1;
  }

  struct sockaddr_in server;
  memset(&server, 0, sizeof server);

  server.sin_family = AF_INET;
  server.sin_port = htons(PORT);
  server.sin_addr.s_addr = htonl(INADDR_ANY);

  /*
  * bind to address and port
  */
  if(bind(sd, (struct sockaddr *) &server, sizeof server) == -1)
  {
    perror("bind");
    return 1;
  }

  /*
  * prepare client struct
  */
  struct sockaddr_in client;
  memset(&client, 0, sizeof client);
  socklen_t client_size = sizeof(client);

  char buffer[BUFFER_SIZE + 1];

  while(1)
  {
    /*
    * receive message
    */
    printf("waiting on port: %d\n", PORT);
    ssize_t n = recvfrom(sd, buffer, BUFFER_SIZE, 0, (struct sockaddr *) &client, &client_size);
    if(n == -1)
    {
      perror("recvfrom");
      return 1;
    }

    /*
    * print message and client address
    */
    buffer[n] = 0;
    printf("received: %zd bytes\n", n);
    printf("received message: %s\n", buffer);
    print_address(&client.sin_addr, client.sin_family);

    /*
    * send reply
    */
    n = sendto(sd, buffer, n, 0, (struct sockaddr *) &client, client_size);
    if(n == -1)
    {
      perror("sendto");
      return 1;
    }
  }
}
