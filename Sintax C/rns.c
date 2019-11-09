#include <stdio.h>
#include <stdlib.h>

char *readLine();
int *readNumbers();

int main(){

    int *arrInt = readNumbers();

    return 0;
}


char *readLine(){

    int count = 0;
    char c = getchar();

    if(c == EOF){
        return NULL;
    }

    //dimensione iniziale array dinamico
    int size = 10;
    //inizializzazione puntatore per conservare caratteri digitati in input
    char *line = malloc(size * sizeof(char));

    while(c != EOF && c != '\n' ){

        line[count] = c;
        c = getchar();

        if(++count == size){
            size *= 2;
            line = realloc(line, size*sizeof(char));
        }

    }

    line[count] = 0;

    return line;

}

int *readNumbers(){

    //dimensione iniziale array dinamico
    int size = 10;
    //inizializzazione puntatore per conservare numeri presenti nella stringa letta in input
    int *arrInt = malloc(size * sizeof(int));

    //puntatore alla stringa da analizzare
    char *p = readLine();

    //controllo che testo immesso venga correttamente salvato(non necessario)
    //printf("Testo immesso: \"%s\"\n", p);

    int index = 0;

    //numero di caratteri letti durate sscanf
    int count = 0;
     
    while(sscanf(p, "%d%n", arrInt + index, &count ) == 1){

        //sposto il puntatore in base a quanti caratteri ho letto
        p += count;

        if(++index == size){
            size *= 2;
            arrInt = realloc(arrInt, size*sizeof(int));
        }

    }

    //controllo che tutti i valori siano stati inseriti 
    for (int i = 0 ; i < index; i++){
        printf("arrInt[%d] = %d\n", i, arrInt[i]);
    }

    return arrInt;

}