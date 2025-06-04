#include<stdio.h>
#include<stdlib.h>

void selection_sort(int arr[], int count){

for (int i = 0; i<count-1;i++){
int index = i;
for (int j = i+1; j<count;j++){
if (arr[j]>arr[index]){
index = j;
}
}
int temp = arr[i];
arr[i] = arr[index];
arr[index] = temp;
}
}

int main(int argc, char *argv[]){

int count = argc-1;
int arr[count];
for (int i = 0; i<count; i++){
arr[i]= atoi(argv[i+1]);  //from geekforgeeks/c-program-for-char-to-int-conversion
}

selection_sort(arr, count);
printf("Sorted Descending array: ");
int i=0;
for (i = 0; i<count-1; i++){
printf("%d, ", arr[i]);
}
printf("%d", arr[i]);
printf("\n");

FILE *file = fopen("sorted.txt", "w");
for (int i = 0; i<count; i++){
fprintf(file,"%d\n", arr[i]);
}
fclose(file);

return 0;
}
