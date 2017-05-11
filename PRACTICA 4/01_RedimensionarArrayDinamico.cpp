#include <iostream>
#include <cstdlib>
using namespace std;
const int TAM_BLOQUE = 2;
enum Tiporedimension { DeUnoEnUno, EnBloques, Duplicado };

void Redimensiona (int *p, Tiporedimension tipo, int& tamanio){
  int aum;
  if(tipo == DeUnoEnUno){
    aum = 1;
  }else if (tipo == EnBloques){
    aum = TAM_BLOQUE;
  } else if (tipo == Duplicado){
    aum = tamanio;
  } else{
    cerr << "ERROR EN EL TIPO DE REDIMENSION" << endl;
  }

  int *redim = new int[tamanio + aum];
  for(int i = 0; i < tamanio; i++){
      *(redim + i) = *(p + i);
  }

  tamanio += aum;
}

void Mostrar(const int *cadena, int total){
	for(int i = 0; i < total; i++){
		cout << *(cadena + i) << " ";
	}
	cout << endl;
}

int main(int totalArgumentos, char **argumentos){
  int TAM = 0, actual = 0, tipo, *dinamico = new int[TAM];
  Tiporedimension redimension;

  if(totalArgumentos == 1){
    redimension = DeUnoEnUno;
  } else if (totalArgumentos == 2){
    tipo = atoi( *(argumentos +1) );
    switch(atoi (*(argumentos + 1))){
      case 1: redimension = DeUnoEnUno;
      case 2: redimension = EnBloques;
      case 3: redimension = Duplicado;
      default: redimension = DeUnoEnUno;
    }
  } else{
    cerr << "ERROR EN EL NUMERO DE ARGUMENTOS INTRODUCIDOS" << endl;
    return 0;
  }

  cout << "**INTRODUZCA VALORES PARA EL ARRAY **"<< endl;
  int valor = 0;
  cin >> valor;
  while (valor != 0){
    dinamico[actual] = valor;
    actual++;

    if (actual > TAM){
      Redimensiona(dinamico, redimension, TAM);
    }

    cin >> valor;
  }

  cout << "**VECTOR DINAMICO **"<< endl;
  Mostrar (dinamico, TAM);
}
