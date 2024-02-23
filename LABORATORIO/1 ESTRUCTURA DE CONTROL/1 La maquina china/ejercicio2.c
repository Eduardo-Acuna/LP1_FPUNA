#include <stdio.h>

int main()
{
    int i,a,b,c,SI,NO;
    scanf("%d", &a);
    SI=0;
    NO=0;
    c=a-1;
    for(i=0;i<a;i++){
        scanf("%d", &b);
        if(b==1)
            SI=SI+1;
        else
            NO=NO+1;
    }
    if(NO==1){
        printf("SI\n");
    }else{
        if (c==NO)
            printf("SI\n");
        else
            printf("NO\n");
    }
    return 0;
}
