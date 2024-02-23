# include <stdio.h>

int main(){
    int n,k;
    int ganadores,diplomas,certificados,noGanadores;

    scanf("%d %d",&n,&k);

    if ( n>=1 && k<=10000000000000){

        printf("entro");
        ganadores=n/(2*(k+1));

        diplomas=ganadores;

        certificados=ganadores*k;

        noGanadores=n-(diplomas+certificados);

    }else{
        return 1;
    }

    printf("%d %d %d\n", diplomas, certificados, noGanadores);


    return 0;
}
