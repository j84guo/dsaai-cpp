#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_ipv4(unsigned char* s)
{
  if(strlen((const char*) s) < 4)
    return;

  printf("%d.%d.%d.%d\n", s[0], s[1], s[2], s[3]);
}

int main()
{
  struct hostent *host;
  char *hostname = "www.google.ca";

  host = gethostbyname(hostname);
  if(!host)
  {
    printf("gethostbyname: could not find host %s\n", hostname);
    return 0;
  }

  for(int i=0; host->h_addr_list[i] != NULL; ++i)
  {
    printf("iterating...\n");
    print_ipv4((unsigned char*) host->h_addr_list[i]);
  }

  return 0;
}
