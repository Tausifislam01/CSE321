#include <stdio.h>

int main(){
FILE *inp, *out;
char ch, prev = ' ';

inp = fopen("input.txt","r");
out = fopen("output.txt","w");

while ((ch = fgetc(inp)) !=EOF){

if (ch==' ' && prev==' '){
continue;
}
fputc(ch, out);
prev = ch;
}

fclose(inp);
fclose(out);
return 0;
}
