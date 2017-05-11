#include <iostream>
#include <cstdlib>
using namespace std;
const int TAM_BLOQUE = 2;
enum Tiporedimension { DeUnoEnUno, EnBloques, Duplicado };

void Mostrar(const int *cadena, int total){
	for(int i = 0; i < total; i++){
		cout << *(cadena + i) << " ";
	}
	cout << endl;
}

void Redimensiona (int *p, Tiporedimension tipo, int& tamanio){
  int aum;
  switch(tipo){
    case DeUnoEnUno: aum = 1; break;
    case EnBloques: aum = TAM_BLOQUE; break;
    case Duplicado: aum = tamanio; break;
    default: cerr << "ERROR EN EL TIPO DE REDIMENSION" << endl;
  }
  int *redim = new int[tamanio + aum];
  for(int i = 0; i < tamanio; i++){
    *(redim + i) = *(p + i);
  }
  cout << &redim << endl;
  tamanio += aum;
  delete[] redim;
  p = redim;
}

int main(int totalArgumentos, char **argumentos){
  int TAM = 1, actual = 0, tipo, *dinamico = new int[TAM];
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
    if (actual >= TAM){
      Redimensiona(dinamico, redimension, TAM);
    }
    cout << &dinamico << endl;

    dinamico[actual] = valor;
    actual++;

    cin >> valor;
  }

  cout << "**VECTOR DINAMICO **"<< endl;
  Mostrar (dinamico, TAM);
}
