#include <stdio.h> /* printf */
#include <string.h> /* memset */
#include <stdlib.h> /* exit */
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define SERVER "127.0.0.1"
#define BUFLEN 512 /* max length of buffer */
#define PORT 8888

void die(char *s)
{
  perror(s);
  exit(1);
}

int main(void)
{
  struct sockaddr_in si_other;
  int sock, i;
  char buf[BUFLEN];
  char message[BUFLEN];
  socklen_t sock_len = sizeof(si_other);
  
  /* create a udp socket */
  if((sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1) {
    die("socket");
  }

  /* zero out the structure */
  memset((char *) &si_other, 0, sizeof(si_other));

  /* populate the structure */
  si_other.sin_family = AF_INET;
  si_other.sin_port = htons(PORT);

  /* interpret server address string to internet address */
  inet_aton(SERVER, &si_other.sin_addr);

  /* start send and receive loop */
  for(;;)
    {
      printf("Enter message: ");
      fgets(message, BUFLEN, stdin);

      /* send the message */
      if(sendto(sock, message, strlen(message), 0,
		(struct sockaddr *) &si_other, sock_len) == -1) {
	die("sendto");
      }

      /* clear the buffer bu filling null */
      memset(buf, '\0', BUFLEN);
      
      /* receive a reply and print it */
      if(recvfrom(sock, buf, BUFLEN, 0,
		  (struct sockaddr *) &si_other, &sock_len) == -1) {
	die("recvfrom");
      }

      puts(buf);
    }

  close(sock);
  return 0;
}
