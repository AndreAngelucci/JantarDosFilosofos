#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
#include <locale.h>

int retornaFilosofoEsquerda(int pFilosofo){
    int vFilosofoEsquerda;
    vFilosofoEsquerda = pFilosofo - 1;
    if (vFilosofoEsquerda < 0)
        vFilosofoEsquerda = 4;
    return vFilosofoEsquerda;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    /* Vetor que determina os nomes dos filósofos. */
    char *vNomesFilosofos[5];
    /* Vetor que determina se o hashi está em uso ou ocioso. */
    bool vSituacaohashi[5];

    int cQuantidadehashis = 5;
    int vFilosofoCorrente;

    vNomesFilosofos[0] = "Douglas";
    vNomesFilosofos[1] = "Platão";
    vNomesFilosofos[2] = "René";
    vNomesFilosofos[3] = "Sócrates";
    vNomesFilosofos[4] = "Aristóteles";

    /* Desocupa todos os hashis. */
    vSituacaohashi[0] = true;
    vSituacaohashi[1] = true;
    vSituacaohashi[2] = true;
    vSituacaohashi[3] = true;
    vSituacaohashi[4] = true;

    printf("************************************************************\n");
    printf("************************************************************\n");
    printf("**                                                        **\n");
    printf("**                                                        **\n");
    printf("**       J A N T A R    D O S    F I L O S O F O S        **\n");
    printf("**                                                        **\n");
    printf("**                                                        **\n");
    printf("************************************************************\n");
    printf("************************************************************\n\n");


    while (true){
        for (vFilosofoCorrente = 0; vFilosofoCorrente <= cQuantidadehashis - 1; vFilosofoCorrente++){
            if (!(vSituacaohashi[vFilosofoCorrente]) && !(vSituacaohashi[retornaFilosofoEsquerda(vFilosofoCorrente)])){
                printf("Filósofo %s desocupou os hashis e está pensando.\n", vNomesFilosofos[vFilosofoCorrente], vFilosofoCorrente);
                vSituacaohashi[vFilosofoCorrente] = true;
                vSituacaohashi[retornaFilosofoEsquerda(vFilosofoCorrente)] = true;
            } else
                if (((vSituacaohashi[vFilosofoCorrente]) && (vSituacaohashi[retornaFilosofoEsquerda(vFilosofoCorrente)]))){
                    /* Ocupa os dois hashis. */
                    printf("Filósofo %s pegou os hashi e está comendo.\n", vNomesFilosofos[vFilosofoCorrente], vFilosofoCorrente);
                    vSituacaohashi[vFilosofoCorrente] = false;
                    vSituacaohashi[retornaFilosofoEsquerda(vFilosofoCorrente)] = false;
                } else
                    printf("Filósofo %s está pensando.\n", vNomesFilosofos[vFilosofoCorrente], vFilosofoCorrente);
            Sleep(1000);
        }
    }
    return 0;
}
