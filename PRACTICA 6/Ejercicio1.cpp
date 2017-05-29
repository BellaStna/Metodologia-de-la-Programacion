#include <iostream>
// #include <cstring> -> system("cls")
using namespace std;

class Barquitos{
private:
    int filas;
    int columnas;
    int** tablero;
public:
  Barquitos(int tfil, int tcol):filas(tfil), columnas(tcol){
    tablero = new int*[filas];
    for(int j = 0; j < filas; j++){
      tablero[j] = new int[columnas];
      for(int i = 0; i < columnas; i++){
        tablero[j][i] = 9;
      }
    }
  }

  ~Barquitos(){
    for(int i = 0; i < filas; i++){
      delete[] tablero[i];
    }
    delete[] tablero;
  }

  Barquitos(const Barquitos& b){
    filas     = b.filas;
    columnas  = b.columnas;

    tablero = new int*[filas];
    for(int j = 0; j < filas; j++){
      tablero[j] = new int[columnas];
      for(int i = 0; i < columnas; i++){
        tablero[j][i] = b.get(i, j);
      }
    }
  }

  bool get(int i, int j) const{ return estaDentro(i, j) ? tablero[j][i] : 0; }

  bool estaDentro(int i, int j) const{ return ((i >= 0 && i < columnas) && (j >= 0 && j < filas)); }

  void mostrar() const{
    cout << "  ";
    for(int i = 0; i < columnas; i++){
        cout << i << " ";
    }
    cout << endl;
    for (int j = 0 ; j < filas; j++){
      cout << (char)('A' + j) << " ";
      for (int i = 0 ; i < columnas; i++){
        if (tablero[j][i] > 0){
          cout << ((tablero[j][i] == 9) ? '~' : (char)('0' + tablero[j][i])) << " ";
        }else{
          cout << ((tablero[j][i] == -9) ? 'o' : 'x') << " ";
        }
      }
      cout << endl;
    }
    cout << endl << "~ Agua O Tocado Agua X Tocado " << endl;
  }

  bool golpear(int i, int j){
    if(tablero[j][i] < 0){
      return false;
    }else{
      tablero[j][i] *= -1;
      return true;
    }
  }

  bool posicionaBarco(int i, int j, int s, char o){
    bool agua = true;
    if( toupper(o) == 'H' && s + i < columnas ){
      for(int a = i; a < i + s && agua; a++){
        if (tablero[j][a] != 9){
          agua = false;
        }
      }

      for (int a = i; a < i + s && agua; a++){
        tablero[j][a] = s;
      }
    }else if( toupper(o) == 'V' && s + j < filas ){
      for(int a = j; a < j + s && agua; a++){
        if (tablero[a][i] != 9){
          agua = false;
        }
      }

      for (int a = j; a < j + s && agua; a++){
        tablero[a][i] = s;
      }
    }
  }
};

int main(){
  Barquitos nuevoTablero(10, 10);
  nuevoTablero.posicionaBarco(8, 4, 4, 'V');
  nuevoTablero.mostrar();
}
