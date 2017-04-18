/**
   @file testarteASCII.cpp
   @brief lee imagenes/gio.pgm y la convierte en ascii con los caracteres "@%#*+=-:. "
   @author MP-DGIM - Grupo A

**/
#include<iostream>
#include<imagen.h>
#include<fstream>
#include<cstring>

using namespace std;

int main(){
	 const int MAX=4500;
    char grises[] = "@#%xo;:,. ";
    char arteASCII[MAX+1]; // 4500 + el \0
    char imagen1[]="data/gio.pgm";
    Imagen origen;

		//Lectura
		const int MAX_NOMBRE = 180;
		char fichero[MAX_NOMBRE], gris[MAX_NOMBRE], salida[MAX_NOMBRE];
		int lineas_grises;

		cout << "Introduzca nombre de la imagen: ";
		cin.getline(fichero, MAX_NOMBRE);
		cout << "Introduzca el fichero de grises: ";
		cin.getline(gris, MAX_NOMBRE);
		cout << "Introduzca el fichero de salida: ";
		cin.getline(salida, MAX_NOMBRE);

		cout << fichero << " " << gris << " " << salida;

		ifstream fentrada;
		fentrada.open(gris);
		if (fentrada){
			fentrada >> lineas_grises;
			for (int i = 0; i < lineas_grises; i++){
				fentrada >> gris;

				if (!origen.leerImagen(fichero)){
			   cerr << "error leyendo "<< imagen1 << endl;
			   return 1;
		    }
				//Falta manehar errores de la escritura.
				if(origen.aArteASCII(gris, arteASCII, MAX)){
						cout << "arteASCII con la escala de grises número " << i << endl;
						ofstream fsalida;
						fsalida.open(salida, ios::app);
						fsalida << "arteASCII con la escala de grises número " << lineas_grises << endl;
						fsalida << arteASCII << endl;
						fsalida.close();
				}
				else
						cerr << "La conversión no ha sido posible" << endl;

			}

			fentrada.close();
		}
		else{
			cerr << "Error de lectura del fichero. \n";
		}


		/*

    // Leer la imagen gio.pgm
    if (!origen.leerImagen(imagen1)){
	   cerr << "error leyendo "<< imagen1 << endl;
	   return 1;
    }

    cout << "\nLa imagen en arte ASCII es:\n";
    if(origen.aArteASCII(grises, arteASCII, MAX))
        cout << arteASCII;
    else
        cout << "La conversión no ha sido posible" << endl;

    cout << "Ahora Forzamos que no quepa. Debe aparecer un mensaje de error\n";
    if(origen.aArteASCII(grises, arteASCII, MAX/10))
        cout << arteASCII;
    else
        cout << "La conversión no ha sido posible" << endl;
		*/
}
