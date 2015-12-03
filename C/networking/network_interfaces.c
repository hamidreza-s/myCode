#include <arpa/inet.h>
#include <sys/socket.h>
#include <ifaddrs.h>
#include <stdio.h>

/* 
   @NOTE:
   The code was just tested on OSX
*/

int main(void)
{
  struct ifaddrs *ifap, *ifa;
  struct sockaddr_in *sa;
  struct sockaddr_in *bc;
  char *sa_addr;
  char *bc_addr;

  getifaddrs(&ifap);
  for(ifa = ifap; ifa; ifa = ifa->ifa_next) {

    if(ifa->ifa_addr->sa_family == AF_INET) {

      sa = (struct sockaddr_in *) ifa->ifa_addr;
      sa_addr = inet_ntoa(sa->sin_addr);
      printf("Interface: %s\t\tAddress: %s", ifa->ifa_name, sa_addr);

      bc = (struct sockaddr_in *) ifa->ifa_dstaddr;
      bc_addr = inet_ntoa(bc->sin_addr);
      printf("\t\tBroadcast: %s\n", bc_addr);
      
    }

  }

  freeifaddrs(ifap);
  return 0;
}
