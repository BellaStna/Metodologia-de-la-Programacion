#include <iostream>
#include <cstdlib>
using namespace std;

const int TAM_NOMBRE = 80;

struct RegAlumno{
	double *notas;
	char *apellido_nombre;
  char *DNI;

	RegAlumno()
	{
			apellido_nombre = new char[TAM_NOMBRE];
			DNI = new char[10];
	}
	~RegAlumno()
	{
		delete apellido_nombre;
		delete DNI;
	}
};

void Mostrar18(const double *media,RegAlumno *alumno,int inicio, int total, int num_not){
	for(int i = 0; i < total; i++){
		if ( *(media + i) >= inicio && *(media + i) <= total){
			cout << alumno[i].apellido_nombre << " DNI : "<< alumno[i].DNI << "  Media: " ;
			cout << *(media + i) << endl;
		}
	}
}

void Media (double peso[], double medias[], RegAlumno *alumnos, int util, int num_not){
	for(int i = 0; i < util; i++){
		for (int j = 0; j < num_not; j++){
			medias[i] += (alumnos[i].notas[j]) * (peso[j] / 100.0);
		}
	}
}

bool PesoCorrecto (double vector[],int num_not){
	int i;
	double suma = 0;
	for(i = 0; i < num_not; i++) suma += vector[i];
	return (suma == 100.0);
}

void Ordena(double *vec, RegAlumno *vec2, int final){
	for (int j = 0; j < final-1; j++){
		int big = j;
		for(int i = j + 1; i < final; i++){
			if(*(vec + i) < *(vec + big)){
				big = i;
			}
		}
		int aux 		= *(vec + big);
		*(vec + big) 	= *(vec + j);
		*(vec + j) 		= aux;

		RegAlumno alg 	= *(vec2 + big);
		*(vec2 + big) 	= *(vec2 + j);
		*(vec2 + j) 	= alg;
	}

}

/*void Redimensiona02 (int *p, Tiporedimension tipo, int& tamanio){
  if(tamanio < actual)


  int *redim = new int[tamanio + aum];
  for(int i = 0; i < tamanio; i++){
      *(redim + i) = *(p + i);
  }

  tamanio += aum;
}*/

int main(int totalArgumentos, char **argumentos){
  int num_notas  = 0;
	int TAM = 10;
	int inicio = 0, a = 0;
  RegAlumno alumnos[TAM];
  double *medias 	= new double[TAM];
	double *peso 		= new double[TAM];

  cout << "Introduzca el numero de notas :" ;
  cin >> num_notas;
  cout << "Introduzca el peso de cada examen." << endl;
	for(int i = 0; i < num_notas; i++){
		cin >> peso[i];
	}
  if (! PesoCorrecto(peso,num_notas) ){
		cerr << "Error";
	} else {
		int util = 0;
		cin.ignore();
		cout << "Introduzca el DNI(* para terminar): ";
    cin.getline(alumnos[a].DNI, TAM_NOMBRE);
		cout << "Introduzca el nombre y apellidos: ";
		cin.getline(alumnos[a].apellido_nombre, TAM_NOMBRE);

		while (alumnos[a].DNI[0] != '*'){
			for(int j = 0; j < num_notas; j++){
				cout << j + 1 << " Nota : " ;
				cin >> alumnos[a].notas[j];
			}
			util++;
			cout << "Introduzca el DNI: ";
			cin.ignore();
	    cin.getline(alumnos[a].DNI, TAM_NOMBRE);
			cout << "Introduzca el nombre y apellidos: ";
			cin.getline(alumnos[a].apellido_nombre, TAM_NOMBRE);
		}

	Media(peso, medias , alumnos, util,num_notas);
	Ordena(medias, alumnos, util);
	if (totalArgumentos >=1) {inicio = atoi( *(argumentos + 1) ); }
	if (totalArgumentos == 2) {util = atoi( *(argumentos + 1) ); }
	Mostrar18(medias,alumnos,inicio, util,num_notas);
	};
}
