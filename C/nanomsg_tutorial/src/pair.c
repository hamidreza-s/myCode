#include <stdio.h>
#include <assert.h>
#include <sys/select.h>
#include <nanomsg/nn.h>
#include <nanomsg/pair.h>

typedef struct sock_info {
  int sock_sp;
  int sock_fd;
} sock_info;

int sock_bind(const char *url) {
  int sock = nn_socket(AF_SP, NN_PAIR);
  assert(sock >= 0);
  assert(nn_bind(sock, url) >= 0);
  return sock;
}

int get_rec_sockfd(int sock) {
  int rcvfd;
  size_t rcvfd_sz = sizeof(rcvfd);
  nn_getsockopt(sock, NN_SOL_SOCKET, NN_RCVFD, &rcvfd, &rcvfd_sz);
  return rcvfd;
}

int main(void) {
  int sock1 = sock_bind("tcp://127.0.0.1:9991");
  int sock2 = sock_bind("tcp://127.0.0.1:9992");

  int sockfd1 = get_rec_sockfd(sock1);
  int sockfd2 = get_rec_sockfd(sock2);

  sock_info sockinfo[] = {
    {sock1, sockfd1},
    {sock2, sockfd2}
  };
  
  printf("sock1: %d - sockfd1: %d\n", sock1, sockfd1);
  printf("sock2: %d - sockfd2: %d\n", sock2, sockfd2);

  fd_set readfds;
  int maxfds = sockfd2;
  int select_rc;
  char *buf = NULL;
  int i, j;
  int go = 1;
  
  for(;;) {

    go = 1;
    FD_ZERO(&readfds);
    FD_SET(sockfd1, &readfds);
    FD_SET(sockfd2, &readfds);
    
    printf("inside loop\n");
    select_rc = select(maxfds+1, &readfds, NULL, NULL, NULL);
    printf("select was returned with: %d\n", select_rc);

    for(i = 0; i <= maxfds && go; i++) {

      if(FD_ISSET(i, &readfds)) {

	printf("is set: %d\n", i);

	for(j = 0; j < 2 && go; j++) {

	  if(sockinfo[j].sock_fd == i) {
	    nn_recv(sockinfo[j].sock_sp, &buf, NN_MSG, 0);
	    printf("recevied msg: %s\n", buf);
	    go = 0;
	  }
	  
	}

      }

    }

    printf("for-done!\n");
    
  }
  
  return 0;
}
