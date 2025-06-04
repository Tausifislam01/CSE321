#include <stdio.h>

int perfect(int num){
int sum = 0;
for (int i=1; i<=num/2; i++){
if (num%i ==0){
sum+=i;
}
}
return sum==num;
}

int main(){
int lower, upper;

printf("Enter the lower limti: ");
scanf("%d", &lower);

printf("Enter the upper limti: ");
scanf("%d", &upper);

printf("Perfect numbers between %d and %d:\n", lower, upper);

for (int i = lower; i<=upper; i++){
if (perfect(i)){
printf("%d\n", i);
}
}

return 0;
}
