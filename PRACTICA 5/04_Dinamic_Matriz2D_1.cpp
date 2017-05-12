#include <iostream>
#include <stdlib.h>
#include <time.h>
using namaespace std;

void Apartado_A(int filas, int columnas){
  //CREAR MATRIZ VACIA
  int **matriz;
  matriz = new int *[filas];
  for (int i = 0; i < filas ; i++) { matriz[i] = new int [columnas]; }
}

void Apartado_B(int filas, int **matriz){
  //LIBERAR MEMEORIA DE LA MATRIZ
  for(int i  = 0; i < filas ; i++){
    delete [] matriz[i];
  }
}

void Apartado_C(int filas, int columnas){
  //CREAR MATRIZ LLENA CON VALORES A ELEGIR
  Apartado_A(filas, columnas);
  cout << "INTRODUZCA LOS VALORES DE LA MATRIZ" << endl;
  for (int i = 0; i < filas; i++){
    for (int j = 0; j < columnas; j++){
      cin >> matriz[i][j];
      cout << "  "
    }
    cout << endl;
  }
}

void Apartado_D(int filas, int columnas){
  //CREAR MATRIZ LLENA CON VALORES ALEATORIOS
  srand(time(NULL));
  Apartado_A(filas, columnas);
  for (int i = 0; i < filas; i++){
    for (int j = 0; j < columnas; j++){
      matriz[i][j] =  1 + rand() % (11 - 1);;
    }
  }
}

void Apartado_E(int filas, int columnas, int **matriz){
  //MUESTRA MATRIZ
  for (int i = 0; i < filas; i++){
    for (int j = 0; j < columnas; j++){
      cout << matriz[i][j] << "  " ;
    }
    cout << endl;
  }
}

void Apartado_F(int filas, int columnas, int **matriz){
  //COPIAR MATRIZ
  int **copia = Apartado_A(filas,columnas);
  for (int i = 0; i < filas; i++){
    for (int j = 0; j < columnas; j++){
      copia[i][j] = matriz[i][j];
    }
  }
}

void Apartado_G(){}

void Apartado_H(){}

void Apartado_I(){}

void Apartado_J(){}

void Apartado_K(){}

int main (){

}
