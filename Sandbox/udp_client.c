#include <stdio.h>
#include <string.h>

#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

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
* int sendto(int socket, const void *buffer, size_t length, int flags,
*   const struct sockaddr *dest_addr, socklen_t dest_len);
*/
int main()
{
  /*
  * optionally, the client may bind to a specific interface and port
  */
  int sd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  if(sd == -1)
  {
    perror("socket");
    return 1;
  }

  /*
  * prepare server struct
  */
  struct sockaddr_in server;
  memset(&server, 0, sizeof server);
  server.sin_family = AF_INET;
  server.sin_port = htons(5000);
  inet_pton(server.sin_family, "172.31.72.10", &server.sin_addr);
  socklen_t server_size = sizeof server;

  /*
  * send message
  */
  char msg[BUFFER_SIZE + 1] = "This is a test message.";
  ssize_t n = sendto(sd, msg, strlen(msg), 0, (struct sockaddr*) &server, sizeof server);
  if(n < 0)
  {
    perror("sendto");
    return 1;
  }

  /*
  * receive response
  */
  n = recvfrom(sd, msg, BUFFER_SIZE, 0, (struct sockaddr *) &server, &server_size);
  if(n == -1)
  {
    perror("recvfrom");
    return 1;
  }

  /*
  * print server address
  */
  msg[n] = '\0';
  printf("%s\n", msg);
  print_address(&server.sin_addr, server.sin_family);

  return 0;
}
