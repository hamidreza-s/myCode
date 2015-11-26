#include <stdio.h> /* printf */
#include <string.h> /* memset */
#include <stdlib.h> /* exit */
#include <unistd.h> /* close */
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUFLEN 512 /* max length of buffer */
#define PORT 8888 /* the port on which to listen for incoming data */

void die(char *s)
{
  perror(s);
  exit(1);
}

int main(void)
{
  struct sockaddr_in si_me, si_other;
  int sock, i, recv_len;
  char buf[BUFLEN];
  socklen_t sock_len = sizeof(si_other);

  /* create a UDP sock */
  if((sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1) {
    die("socket");
  }

  /* zero out the structure */
  memset((char *) &si_me, 0, sizeof(si_me));

  /* populate the structure */
  si_me.sin_family = AF_INET;
  si_me.sin_port = htons(PORT);
  si_me.sin_addr.s_addr = htonl(INADDR_ANY);
  
  /* bind socket to port */
  if(bind(sock, (struct sockaddr *) &si_me, sizeof(si_me)) == -1) {
    die("bind");
  }

  /* keep listening for data  */
  for(;;)
    {
      printf("Waiting for data ...\n");
      fflush(stdout);
      
      /* try to receive data in blocking mode */
      if((recv_len = recvfrom(sock, buf, BUFLEN, 0,
			      (struct sockaddr *) &si_other, &sock_len)) == -1) {
	die("recvfrom");
      }

      /* print details of the client and the data received */
      printf("Received packet from %s:%d\n",
	     inet_ntoa(si_other.sin_addr),
	     ntohs(si_other.sin_port));
      printf("Data: %s\n", buf);
      printf("-----------------\n");
      
      /* now reply the client with the same data */
      if(sendto(sock, buf, recv_len, 0, (struct sockaddr *) &si_other, sock_len) == -1) {
	die("sendto");
      }  
    }

  close(sock);
  return 0;
}
