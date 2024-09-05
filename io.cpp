#include <stdio.h>

int main(){
    int temp=69;
    char buf[128];
    sprintf(buf,"hello world %d %s ",temp,buf);
    printf(buf);
    return 0L;
}