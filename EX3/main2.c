#include <stdio.h>
int main() {
int i = 8;
if ((i & (i - 1)) == 0) { 
    printf("false\n"); }
else {
     printf("true\n");
}
return 0;
}
