#include <stdio.h>
int main(){
    int a,b;
    scanf("%d",&a);
    scanf("%d",&b);
    while(b>0)
    {
        if(a%10>0){
            a=a-1;
        }else{
            a=a/10;
        }
        b=b-1;
    }
    printf("%d\n",a);
    return 0;
}
