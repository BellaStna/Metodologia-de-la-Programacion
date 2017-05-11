#include <iostream>
#include <cstring>

using namespace std;

////////////////////////////////////////
void lee_linea( char c[], int tamano )
{
     do{
         cin.getline(c, tamano);
     } while (c[0] == '\0'); 
}

////////////////////////////////////////
char * LeerNombre()
{
     char cadena[300];
     char *p;
     
     lee_linea (cadena, 300);

     p = new char [ strlen (cadena) + 1 ];
     
     strcpy( p, cadena );
     
     return p;
}

 
