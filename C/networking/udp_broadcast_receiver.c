#include <stdio.h>       /* for printf() and fprintf() */
#include <sys/socket.h>  /* for socket(), connect(), sendto() and recvfrom() */
#include <arpa/inet.h>   /* for struct sockaddr_in and inet_addr() */
#include <stdlib.h>      /* for atoi() and exit() */
#include <string.h>      /* for memset() */
#include <unistd.h>      /* for close() */

#define MAX_RECV_STR 255 /* longest string to receive */

void die(char *str)
{
  perror(str);
  exit(1);
}

int main(int argc, char *argv[])
{
  int sock;                            /* socket */
  struct sockaddr_in broadcast_addr;   /* broadcast address */
  unsigned short broadcast_port;       /* broadcast port */
  char recv_str[MAX_RECV_STR + 1];     /* buffer fro received string */
  int recv_str_len;                    /* length of received string */

  if(argc != 2) {
    fprintf(stderr, "Usage: %s <broadcast port>\n", argv[0]);
    exit(1);
  }

  broadcast_port = atoi(argv[1]);       /* first arg: broadcast port */

  /* create a best-effort datagram socket using UDP */
  if((sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
    die("socket");

  /* construct bind structure */
  memset(&broadcast_addr, 0, sizeof(broadcast_addr));  /* zero out structure */
  broadcast_addr.sin_family = AF_INET;                 /* internet address family */
  broadcast_addr.sin_addr.s_addr = htonl(INADDR_ANY);  /* any incoming interface */
  broadcast_addr.sin_port = htons(broadcast_port);     /* broadcast port */

  /* bind to the broadcast port */
  if(bind(sock, (struct sockaddr *) &broadcast_addr, sizeof(broadcast_addr)) < 0)
    die("bind");

  printf("Binded to %d ...\n", broadcast_port);
  
  for(;;)
    {
      /* receive a single datagram */
      if((recv_str_len = recvfrom(sock, recv_str, MAX_RECV_STR, 0, NULL, 0)) < 0)
	die("recvfrom");

      recv_str[recv_str_len] = '\0';
      printf("Received: %s\n", recv_str);
    }

  close(sock);
  return 0;
}

