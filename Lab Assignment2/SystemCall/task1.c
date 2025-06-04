#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
int inp;
char arr[100];


inp = open(argv[1], O_WRONLY | O_CREAT , 0644);

if (inp<0){
perror("Error opening/creating file");
return -1;
}

printf("Enter strings to write to the file, enter -1 to stop:\n");
int i =1;
while(1){
printf("%d.", i);
fgets(arr, sizeof(arr), stdin);
i++;
//arr[]=0;
if (strcmp(arr, "-1\n")==0){
break;
}

write(inp, arr, strlen(arr));
}
close(inp);
printf("File written succesfully\n");
return 0;
}
