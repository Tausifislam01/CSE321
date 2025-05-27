#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

int main(){

char password[20];
bool lower = false, upper = false, digit = false, special = false;

printf("Enter the password: ");
scanf("%s", password);

for (int i =0; i<strlen(password); i++){

if islower(password[i]){
lower = true;
}

else if isupper(password[i]){
upper = true;
}

else if isdigit(password[i]){
digit = true;
}

if (strchr("_@$#",password[i])){
special = true;
}

}
if (!lower){
printf("Lowercase character missing, ");
}
if (!upper){
printf("Uppercase character missing, ");
}
if (!digit){
printf("Digit missing, ");
}
if (!special){
printf("Special character missing, ");
}
printf("\n");
if (lower && upper && digit && special){
printf("OK");
}

return 0;
}
