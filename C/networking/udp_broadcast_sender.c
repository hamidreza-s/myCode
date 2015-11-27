#include <stdio.h>       /* for printf() and fprintf() */
#include <sys/socket.h>  /* for socket() and bind() */
#include <arpa/inet.h>   /* for struct sockaddr_in */
#include <stdlib.h>      /* for atoi() and exit() */
#include <string.h>      /* for memset() */
#include <unistd.h>      /* for close() */

void die(char *str)
{
  perror(str);
  exit(1);
}

int main(int argc, char *argv[])
{
  int sock;                            /* socket */
  struct sockaddr_in broadcast_addr;   /* broadcast address */
  char *broadcast_ip;                  /* broadcast ip */
  unsigned short broadcast_port;       /* broadcast port */
  char *send_str;                      /* string for broadcast */
  int broadcast_permission;            /* socket opt for broadcast permission */
  unsigned int send_str_len;           /* lenght of string for broadcast */

  if(argc < 4) {
    fprintf(stderr, "Usage: %s <ip address> <port> <send string>\n", argv[0]);
    exit(1);
  }

  broadcast_ip = argv[1];          /* first arg: broadcast ip */
  broadcast_port = atoi(argv[2]);  /* second arg: broadcast port */
  send_str = argv[3];              /* third arg: string for broadcast */

  /* create socket for sending/receiving datagrams */
  if((sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
    die("socket");

  /* set socket to allow broadcast */
  broadcast_permission = 1;
  if(setsockopt(sock, SOL_SOCKET, SO_BROADCAST,
		(void *) &broadcast_permission,
		sizeof(broadcast_permission)) < 0)
    die("setsockopt");

  /* construct local address structure */
  memset(&broadcast_addr, 0, sizeof(broadcast_addr));        /* zero out structure */
  broadcast_addr.sin_family = AF_INET;                       /* interent address family */
  broadcast_addr.sin_addr.s_addr = inet_addr(broadcast_ip);  /* broadcast ip address */
  broadcast_addr.sin_port = htons(broadcast_port);           /* broadcast port */

  send_str_len = strlen(send_str);

  /* broadcast send_str in datagram */
  if(sendto(sock, send_str, send_str_len, 0,
	    (struct sockaddr *) &broadcast_addr,
	    sizeof(broadcast_addr)) != send_str_len)
    die("sendto");

  puts("sent");
  return 0;
}
