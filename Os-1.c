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
 printf("child send a message: ");
 scanf("%s", msgw);
 write(pipefds[1], msgw, sizeof(msgw));
 }
 else
 {
 read(pipefds[0], msgr, sizeof(msgr));
 printf("parent receive a message: %s\n", msgr);
 char str[100];
 strcpy(str, msgr);
 int i = 0;
 int j = strlen(str)-1;
 while(i<j)
 {
 char temp = str[i];
 str[i] = str[j];
 str[j] = temp;
 i++;
 j--;
 }
 printf("Reverse of string is : %s\n", str);
 }
}
