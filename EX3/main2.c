#include <stdio.h>

int main() {
int i = 1;
if (i>1 && (i & (i - 1)) == 0) { 
printf("ture\n"); }
else {
printf("false\n");
}
return 0;
}
