#include <assert.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <stdio.h>
#include <nanomsg/nn.h>
#include <nanomsg/reqrep.h>

#define NODE0 "node0"
#define NODE1 "node1"
#define DATE "DATE"

/* --- date --- */
char *date(void) {

  time_t current_time;
  char *c_time_string;

  current_time = time(NULL);
  c_time_string = ctime(&current_time);

  return c_time_string;
}

/* --- server --- */
int node0(const char *url) {

  int sz_date = strlen(DATE) + 1;
  int sock = nn_socket(AF_SP, NN_REP);

  assert(sock >= 0);
  assert(nn_bind(sock, url) >= 0);

  while(1) {
    char *buf = NULL;
    int bytes = nn_recv(sock, &buf, NN_MSG, 0);
    assert(bytes >= 0);
    if(strncmp(DATE, buf, sz_date) == 0) {
      printf("NODE0: RECEIVED DATE REQUEST\n");
      char *st_date = date();
      int sz_date = strlen(st_date) + 1;
      printf("NODE0: SENDING DATE %s\n", st_date);
      bytes = nn_send(sock, st_date, sz_date, 0);
      assert(bytes == sz_date);
    }
    nn_freemsg(buf);
  }

  return nn_shutdown(sock, 0);
}

/* --- client --- */
int node1(const char *url) {

  int sz_date = strlen(DATE) + 1;
  char *buf = NULL;
  int bytes;
  int sock = nn_socket(AF_SP, NN_REQ);

  assert(sock >= 0);
  assert(nn_connect(sock, url) >= 0);

  /* send */
  printf("NODE1: SENDING DATE REQUEST %s\n", DATE);
  bytes = nn_send(sock, DATE, sz_date, 0);
  assert(bytes == sz_date);
  
  /* receive */
  bytes = nn_recv(sock, &buf, NN_MSG, 0);
  assert(bytes >= 0);
  printf("NODE1: RECEIVED DATE %s\n", buf);
  nn_freemsg(buf);

  return nn_shutdown(sock, 0);  
}

/* --- main --- */
int main(const int argc, const char **argv) {

  if(strncmp(NODE0, argv[1], strlen(NODE0)) == 0 && argc > 1) {
    return node0(argv[2]);
  } else if(strncmp(NODE1, argv[1], strlen(NODE1)) == 0 && argc > 2) {
    return node1(argv[2]);
  } else {
    fprintf(stderr, "Usage: reqrep %s|%s <URL> <ARG> ...'\n",
	    NODE0, NODE1);
    return 0;
  }
}
