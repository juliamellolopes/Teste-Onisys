#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

using namespace std;

void menu(){
    cout << "Informe um numero inteiro: ";
}


void preencher(int n, int **T) {
  int i,j;

  T[0][0] = 1;
  for (i = 1; i < n; i++) {
    T[i][0] = 1;
    T[i][i] = 1;
    for (j = 1; j < i; j++) {
      T[i][j] = T[i-1][j] + T[i-1][j-1];
    }
  }

  return;
}

void imprimir(int n, int **T) {
  int i,j;

  for (i = 0; i < n; i++) {
    for (j = 0; j <= i; j++) {
      printf("%5d ", T[i][j]);
    }
    printf("\n");
  }

  return;
}

int main() {
  int nLinhas,i,j,**T;

  menu();
  cin >> nLinhas;

  T = (int **) malloc(nLinhas*sizeof(int *));
  if (T == NULL) {
    printf("Falhou\n");
    return(-1);
  }
  
  for (i = 0; i < nLinhas; i++) {
    T[i] = (int *) malloc((i+1)*sizeof(int));
    
    if (T[i] == NULL) {
      printf("Falhou\n");
      return(-1);
    }
  }

  if (nLinhas <= 0) { return(1); }

  preencher(nLinhas,T);
  imprimir(nLinhas,T);

  return(0);
}