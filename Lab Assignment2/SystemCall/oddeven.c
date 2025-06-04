#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){

int count = argc -1;
int arr1[count];

for (int i =0; i <count; i++){
arr1[i] = atoi(argv[i+1]); // from geekforgeeks c-program-char-to-int-conversion
}

for (int i = 0; i<count;i++){
if (arr1[i]%2==0){
printf("%d is an even number\n",arr1[i]);
}
else {
printf("%d is an odd number\n", arr1[i]);
}
}
return 0;
}
