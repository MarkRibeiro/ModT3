#include "BAR.H"
#include "PECA.H"
#include "LISTA.H"

int main(){
    int aux;
    BAR_CriarBAR();

    BAR_Inserir('p');
    BAR_Inserir('p');

    BAR_NPecas('p', &aux);
    printf("Peças pretas capturadas: %d\n", aux);
}