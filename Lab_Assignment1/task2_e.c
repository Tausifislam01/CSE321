#include <stdio.h>
#include <string.h>

int main(){

char arr[50];
int start, end;

printf("Enter a string to check palindrome: ");
scanf("%s", arr);

start = 0;
end = strlen(arr)-1;

while (start<end){
if (arr[start] != arr[end]){
printf("Not Palindrome\n");
return 0;
}
start++;
end--;
}
printf("Palindrome\n");

return 0;
} 
