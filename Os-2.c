#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
int main(){
 int pipefds[2];
 int msgw[2];
 int msgr[2];
 int ret = pipe(pipefds);
 if (ret == -1) {
 printf("pipe error\n");
 return -1;
 }
 if (fork()==0) {
 read(pipefds[0], msgr, sizeof(msgr));
 printf("Child receive a message: %s\n", msgr);
 //check the number is amstrong or not
 int sum = 0;
 int n = atoi(msgr);
 int temp = n;
 while(n>0)
 {
 int r = n%10;
 sum += r*r*r;
 n /= 10;
 }
 if(temp == sum)
 printf("%d is amstrong number\n", temp);
 else
 printf("%d is not amstrong number\n", temp);
 
 }
 else
 {
 
 printf("Parent send a message: ");
 scanf("%s", msgw);
 write(pipefds[1], msgw, sizeof(msgw));
 
 }
}
