/* realloc example: rememb-o-matic */
#include <stdio.h>      
#include <stdlib.h>  
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

std::string AcharGanhador(std::string * vetor, int tamanho){
    int posicao = 0;

    for(int i = 0; i < tamanho; i++){

        if(vetor[posicao].length() < vetor[i].length()){
            posicao = i;
        }
    }
    return vetor[posicao];
}

void Limpar(std::string * vetor, int tamanho){
    int posicao = 0;

    for(int i = 0; i < tamanho; i++){
        for(int j = i+1; j < tamanho; j++){
            if(vetor[i] == vetor[j]){
                vetor[j] = "";
            }
        }
    }
}


int main(){
    int input, n;
    int count1 = 0;
    int count2 = 0;

    std::string* amigos = nullptr;
    std::string* naoAmigos = nullptr;
    std::string nome, eAmigo, ganhador;

    amigos = new std::string[100];
    naoAmigos = new std::string[100];

    do {
        std::cin >> nome ;

        if(nome == "FIM")
            break;

        std::cin >> eAmigo;
        
        if(eAmigo == "YES"){
            count1++;
            amigos[count1 - 1] = nome;
        } 
        else{
            count2++;
            naoAmigos[count2 - 1] = nome;
        }
    } while (nome!="FIM");

    ganhador = AcharGanhador(amigos, count1);

    quickSort(amigos, 0, count1 - 1);

    Limpar(amigos, count1);

    quickSort(naoAmigos, 0, count2 - 1);

    Limpar(naoAmigos, count2);

    for(int i = 0; i< count1; i++){
        if(amigos[i] != ""){
            std::cout << amigos[i] << std::endl;
        }
    }

    for(int i = 0; i< count2; i++){
        if(naoAmigos[i] != ""){
            std::cout << naoAmigos[i]<< std::endl;
        }
    } 

    std::cout << "\n";
    std::cout << "Amigo do Habay:" << std::endl;
    std::cout << ganhador << std::endl;
    
}