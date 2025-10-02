#include <stdio.h>

int main() {
int i = 10;
if ((i & (i - 1)) == 0) { 
printf("ture\n"); }
else {
printf("false\n");
}
return 0;
}

