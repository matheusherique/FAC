#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int DELETE_DOT_SLASH = 2;
    int BINARY_NAME = 1;

    printf("# de parametros: %i\n", argc - BINARY_NAME);
    printf("Nome do executavel: %s\n", argv[0] + DELETE_DOT_SLASH);


    for (int i = 1; i < argc; i++) {
      printf("Parametro #%d: %s\n", i, argv[i]);
    }

    return 0;
}
