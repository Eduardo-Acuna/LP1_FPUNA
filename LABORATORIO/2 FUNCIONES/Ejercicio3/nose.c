int juego(int h1, int a1, int c1, int h2, int a2){
    int cont;
    cont=0;

     do{
        if (a1>=h2 || a2>h1) {
            h2=h2-a1;
            cont++;
            printf("ATACAR\n");
        } else if (h1 <= a2) {
            h1=h1-c1;
            cont++;
            printf("CURAR\n");
        } else {
            h2=h2-a1;
            cont++;
            printf("ATACAR\n");
        }

        h1=h1-a2;

    }while(h2>0);

    return cont;
}
