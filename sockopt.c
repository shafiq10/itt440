#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>


int main()
{

   int s; 
   
   struct sockaddr_in server;

   if ((s = socket(AF_INET, SOCK_STREAM, 0)) == -1)
   {
     perror("socket error !!!");
     exit(-1);
   }

   server.sin_family = AF_INET;
   server.sin_port = htons(1040);
   server.sin_addr.s_addr = INADDR_ANY;

   unsigned int len; 
   len = sizeof(struct sockaddr_in);
   
   if ((bind(s, (struct sockaddr *)&server, len)) == -1)
   {
     perror("bind error!!!");
     exit(-1);
   }

   if((listen(s, 8)) == -1)
   {
     perror("listen error!!!");
     exit(-1);
   }

   if((accept(s, (struct sockaddr*)&server, &len)) == -1)
   {
     perror("accept error!!!");
     exit(-1);
   }
     int val, retr, on;
     retr = sizeof(val);

     retr = getsockopt(s, SOL_SOCKET, SO_DONTROUTE, (void *)&val, &len);
     printf("so_dontroute =%d\n", on);
     printf("so_keeplive set %d\n", on);

     on = 1;

     retr = setsockopt(s, SOL_SOCKET, SO_DONTROUTE, (void *)&on, sizeof(on));
     printf("so_keeplive set = %d \n,on");
     printf("on status = %d \n\n",on);

     close(s);
     return 0;
}
