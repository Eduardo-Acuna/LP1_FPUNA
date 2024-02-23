# include <stdio.h>
int main(){
    int i, k, resp;
    resp=0;
    for (k=3 ; k<=5 ; k++){
        for ( i=2 ; i<=5 ; i ++){
            resp+=5*i*k;
        }
    }
    printf("Resp: %d",resp);
    return 0;
}
