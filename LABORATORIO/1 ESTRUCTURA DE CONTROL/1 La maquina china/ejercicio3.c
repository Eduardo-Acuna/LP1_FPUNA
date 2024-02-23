#include <stdio.h>

int main()
{
    int n,a,x,b,y,i,estacion,D,V;
    estacion=0;

    scanf("%d",&n);
    scanf("%d %d",&a,&x);
    scanf("%d %d",&b,&y);

    for(i=0;i<n;i++){
        if(a==b){
            estacion=1;
            break;
        }
        if(a==x){
            D=1;
        }
        if(b==y){
            V=1;
        }
        if(D&&V){
            estacion=1;
            break;
        }
        a=(a%n)+1;
        if(b==1){
            b=n;
        }else{
            b=b-1;
        }
    }
    if(estacion){
        printf("SI\n");
    } else {
        printf("NO\n");
    }
    return 0;
}



