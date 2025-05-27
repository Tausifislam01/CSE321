#include <stdio.h>
#include <string.h>

int main(){

char email[50];
printf("Enter the email address: ");
scanf("%s", email);

if (strstr(email, "@kaaj.com") != NULL){
printf("Email address is outdated\n");
}
else if (strstr(email, "@sheba.xyz") != NULL){
printf("Email address is okay\n");
}
else{
printf("Employee is not part of the company or invalid email address\n");
}
return 0;
}
