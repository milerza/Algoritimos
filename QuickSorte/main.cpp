#include <string>
#include <iostream>

void quickSort(std::string *vetor, int esquerda, int direita)
{
    int i = esquerda;
    int j = direita;
    std::string pivo = vetor[(i + j) / 2];
    std::string aux;

    while (i <= j)
    {
        while (vetor[i] < pivo)
            i++;
        while (vetor[j] > pivo)
            j--;
        if (i <= j)
        {
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i++;
            j--;
        }
    }
    if (j > esquerda)
        quickSort(vetor, esquerda, j);
    if (i < direita)
        quickSort(vetor, i, direita);
}


int main() {
    int linhas;
    int tamanho;
    int caracteresNaoModificados;

    while (std::cin >> linhas) {
        std::string *listaTefonica = new std::string[linhas];

        caracteresNaoModificados = 0;

        for (int i = 0; i < linhas; i++) {
            std::cin >> listaTefonica[i];
        }
        
        tamanho = listaTefonica[0].length();
        
        if(tamanho >200){
            delete[] listaTefonica;
            break;
        }

        quickSort(listaTefonica, 0, linhas - 1);

        for (int i = 0; i < linhas - 1; i++) {
            for (int j = 0; j < tamanho; j++) {
                if (listaTefonica[i][j] == listaTefonica[i+1][j])
                caracteresNaoModificados++;
                else
                j = tamanho;
            }
        }

        std::cout << caracteresNaoModificados << std::endl;

        delete[] listaTefonica;
    }

  return 0;
}