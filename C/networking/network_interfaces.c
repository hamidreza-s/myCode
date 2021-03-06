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
  int rc;
  
  getifaddrs(&ifap);
  for(ifa = ifap; ifa; ifa = ifa->ifa_next) {

    if(ifa->ifa_addr->sa_family == AF_INET) {

      sa = (struct sockaddr_in *) ifa->ifa_addr;
      sa_addr = inet_ntoa(sa->sin_addr);
 
      bc = (struct sockaddr_in *) /* ifa->ifa_dstaddr; */ ifa->ifa_broadaddr;
      bc_addr = inet_ntoa(bc->sin_addr);

      if(rc = (strncmp(ifa->ifa_name, "en0", 3) == 0)) {
	printf("rc: %d\n", rc);
      	printf("Interface: %s\t\t\tAddress: %s", ifa->ifa_name, sa_addr);
	printf("\t\t\tBroadcast: %s\n", bc_addr);
	break;
      }
      
    }

  }

  freeifaddrs(ifap);
  return 0;
}
