#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int **Apartado_A(int filas, int columnas){
  //CREAR MATRIZ VACIA
  int **matriz;
  matriz = new int *[filas];
  for (int i = 0; i < filas ; i++) { matriz[i] = new int [columnas]; }

  return matriz;
}

void Apartado_B(int filas, int **matriz){
  //LIBERAR MEMEORIA DE LA MATRIZ
  for(int i  = 0; i < filas ; i++){
    delete [] matriz[i];
  }
}

int **Apartado_C(int filas, int columnas){
  //CREAR MATRIZ LLENA CON VALORES A ELEGIR
  int **matriz = Apartado_A(filas, columnas);
  cout << "Introduzcalos valores de la matriz" << endl;
  for (int i = 0; i < filas; i++){
    for (int j = 0; j < columnas; j++){
      cin >> matriz[i][j];
    }
  }
  return matriz;
}

int **Apartado_D(int filas, int columnas){
  //CREAR MATRIZ LLENA CON VALORES ALEATORIOS
  srand(time(NULL));
  int **matriz = Apartado_A(filas, columnas);
  for (int i = 0; i < filas; i++){
    for (int j = 0; j < columnas; j++){
      matriz[i][j] =  1 + rand() % (10 - 1);;
    }
  }
  return matriz;
}

void Apartado_E(int filas, int columnas, int **matriz){
  //MUESTRA MATRIZ
  cout << endl;
  for (int i = 0; i < filas; i++){
    for (int j = 0; j < columnas; j++){
      cout << matriz[i][j] << "  " ;
    }
    cout << endl;
  }
}

int **Apartado_F(int filas, int columnas, int **matriz){
  //COPIAR MATRIZ
  int **copia = Apartado_A(filas,columnas);
  for (int i = 0; i < filas; i++){
    for (int j = 0; j < columnas; j++){
      copia[i][j] = matriz[i][j];
    }
  }
  return copia;
}

int **Apartado_G(int filas,int columnas, int **matriz, int in_filas, int fin_filas, int in_colum, int fin_colum){
  //GENERA SUBMATRIZ
  int **submatriz = Apartado_A(fin_filas - in_filas + 1, fin_colum - in_colum + 1);
  for (int i = in_filas; i <= fin_filas; i++){
    for (int j = in_colum; j <= fin_colum; j++){
      submatriz[i - in_filas][j - in_colum] = matriz[i][j];
    }
  }
  return submatriz;
}

int **Apartado_H(int filas,int columnas, int borrar,int **matriz){
  //ELIMINA FILA
  int a = 0;
  int **sin_fila = Apartado_A(filas - 1, columnas);
  for(int i = 0; i<filas; i++){
    if(borrar != filas){
      for(int j=0; j<columnas; j++){
        sin_fila[a][j] = matriz[i][j];
      }
      a++;
    }else{
      i++;
    }
  }
  return sin_fila;
}

int **Apartado_I(int filas,int columnas, int borrar, int **matriz){
  //ELIMINA, COLUMNA
  int b = 0;
  int **sin_columna = Apartado_A(filas, columnas - 1);
  for (int i = 0; i < filas; i++){
    for (int j = 0; j < columnas; j++){
      if(borrar == j) b++;
      sin_columna[i][j] = matriz[i][j - b];
    }
  }
  return sin_columna;
}

int **Apartado_J(int filas, int columnas, int **matriz){
  //MATRIZ TRASPUESTA
  int **traspuesta = Apartado_A(columnas, filas);
  for (int i = 0; i < filas; i++){
    for (int j = 0; j < columnas; j++){
      traspuesta[j][i] = matriz[i][j];
    }
  }
  return traspuesta;
}

int **Apartado_K(int filas, int columnas, int **matriz){
  //MATRIZ INVERTIDA
  int **invertida = Apartado_A(filas,columnas);
  for (int i = 0; i < filas; i++){
    for (int j = 0; j < columnas; j++){
      invertida[i][j] = matriz[filas - i][j];
    }
  }
  return invertida;
}

int main (){

  int filasA, columnasA;
  cout << "APARTADO A: CREAR MATRIZ VACIA"<< endl << "Introduzca las filas y columnas :"<< endl;
  cin >> filasA >> columnasA;
  int **A = Apartado_A(filasA, columnasA);
  Apartado_E(filasA, columnasA, A);

  cout << endl<< "APARTADO B: LIBERAR MEMEORIA DE LA MATRIZ"<< endl;

  int filasC, columnasC;
  cout << endl << "APARTADO C: CREAR MATRIZ LLENA CON VALORES A ELEGIR"<< endl << "Introduzca las filas y columnas :"<< endl;
  cin >> filasC >> columnasC;
  int **C = Apartado_C(filasC, columnasC);
  Apartado_E(filasC, columnasC, C);

  int filasD, columnasD;
  cout << endl << "APARTADO D: CREAR MATRIZ LLENA CON VALORES ALEATORIOS"<< endl << "Introduzca las filas y columnas :"<< endl;
  cin >> filasD >> columnasD;
  int **D = Apartado_D(filasD, columnasD);
  Apartado_E(filasD, columnasD, D);

  cout << endl <<"APARTADO E: MUESTRA MATRIZ"<< endl;
  Apartado_E(filasD, columnasD, D);

  cout << endl << "APARTADO F: COPIAR MATRIZ"<< endl;
  int **F = Apartado_F(filasD, columnasD, D);
  Apartado_E(filasD, columnasD, F);

  int in_fil, in_col, fin_fil, fin_col;
  cout << endl << "APARTADO G: GENERA SUBMATRIZ"<< endl << "Introduzca el inicio y final de filas: ";
  cin >> in_fil >> fin_fil;
  cout << endl << "Introduzca el inicio y final de columnas: ";
  cin >> in_col >> fin_col;
  int **G = Apartado_G(filasD, columnasD, D, in_fil, fin_fil, in_col, fin_col);
  Apartado_E(fin_fil - in_fil + 1, fin_col - in_col + 1, G);

  int eliminar;
  cout << endl << "APARTADO H: ELIMINA FILA"<< endl << "Introduzca la fila a eliminar: ";
  cin >> eliminar;
  int **H = Apartado_H(filasD,columnasD, eliminar,D);
  Apartado_E(filasD - 1, columnasD, H);

  cout << endl << "APARTADO I: ELIMINA COLUMNA"<< endl << "Introduzca la  docolumna a eliminar: ";
  cin >> eliminar;
  int **I = Apartado_I(filasD,columnasD, eliminar,D);
  Apartado_E(filasD, columnasD - 1, I);

  cout << endl << "APARTADO J: MATRIZ TRASPUESTA"<< endl;
  int **J = Apartado_J(filasD,columnasD, D);
  Apartado_E( columnasD, filasD, J);

  cout << endl << "APARTADO K: MATRIZ INVERTIDA"<< endl;
  int **K = Apartado_K(filasD, columnasD, D);
  Apartado_E(filasD, columnasD, K);
}
