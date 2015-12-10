#include <arpa/inet.h>
#include <sys/socket.h>
#include <ifaddrs.h>
#include <stdio.h>
#include <string.h>

/* 
   @NOTE:
   The code was just tested on OSX
*/

int main(void)
{
  struct ifaddrs *ifap, *ifa;
  struct sockaddr_in *sa;
  struct sockaddr_in *bc;
  int rc;

  getifaddrs(&ifap);
  for(ifa = ifap; ifa; ifa = ifa->ifa_next) {

    if(ifa->ifa_addr->sa_family == AF_INET) {
     
      bc = (struct sockaddr_in *) ifa->ifa_broadaddr;
      sa = (struct sockaddr_in *) ifa->ifa_addr;
      
      if((rc = strncmp(ifa->ifa_name, "en0", 3)) == 0) {
      	printf("Interface: %s\t\t\tAddress: %s", ifa->ifa_name, inet_ntoa(sa->sin_addr));
	printf("\t\t\tBroadcast: %s\n", inet_ntoa(bc->sin_addr));
	break;
      }
      
    }

  }

  freeifaddrs(ifap);
  return 0;
}
