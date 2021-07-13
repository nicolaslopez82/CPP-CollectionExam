#include <iostream>
#include "Clases.h"
#include "Funciones.h"

using namespace std;

/**
 * Punto 1:
- Crear un Array/Vector/Map con la cantidad de localidades totales.
- Cada codigo localidad como index/key (en caso de maps).
- Recorrer el archivo Socios.dat validando que sea socio vitalicio (codigo 1). Si es socio vitalicio, sumo el valor en 1 la cantidad.
 */
void mostrarArray(int *v){
    int tam = sizeof(v) / sizeof(v[0]); //Determino el tamanio del array.
    for(int i = 0; i < tam; i++){
        int localidad = i+1;
        cout << "Localidad: " << localidad << " - Tiene " << v[i] << " cantidad de Socios Vitalicios" << endl;
    }
}

void punto1(){
    Socio socio;
    int posicion = 0;
    int aLocalidades[135] = {0}; //Inicializo todo el array en 0.
    while(socio.leerDeDisco(posicion++)){
        if(socio.getTipo() == 1 && socio.isEstado() == true){ // Si el socio es vitalicio y esta activo.
            aLocalidades[socio.getLocalidad() - 1]++; //Incremento en 1 la cantidad de socios vitalicios para la localidad/index indicado.
        }
    }
    mostrarArray(aLocalidades);
}


/**
 * Punto 2:
 *
 * Recorro el archivo Socios.dat y lo guardo en un map<int, Socio> en el cual uso el dni como key para recorrer
 * tan solo una vez el archivo Socios.dat.
 * Luego al momento de recorrer el archivo Clubes.dat (que se supone seria mas pequenio)
 * utilizo la busqueda en el map en tiempo  O(log n) en el peor de los casos, o O(1) en el mejor de los casos.
 *
 * Una vez encontrado el Socio en el map, asigno los valores a la clase Presidente que se usara para generar el archivo.
 */

void punto2(){
    map<int, Socio> archivoSociosMap = convertArchivoAMap();
    Club club(00, 1, 1900, 3 , "Independiente", 29873250, false);
    int posicion = 0;
    while(club.leerDeDisco(posicion++)){
        auto it = archivoSociosMap.find(club.getDniPresidente()); //Busca el DNI del presidente en el map de socios.
        if( it != archivoSociosMap.end()){ //Si encuentra el DNI del presidente en el map de socios, asigna los valores al objeto presidente para que sea guardado.
            Presidente presidente(it -> second.getDni(), it -> second.getNombre(), it -> second.getApellido(), it -> second.isEstado());
            presidente.grabarEnDisco();
        }
    }

}

int main() {
    int opc;
    while(1){
        system("cls");
        cout<<" MENU Recuperatorio Parcial 1"<<endl;
        cout<<"--------------------------------"<<endl;
        cout<<" 1. Punto-1."<<endl;
        cout<<" 2. Punto-2."<<endl;
        cout<<" 3. Inyector Socios."<<endl;
        cout<<" 4. Inyector Clubes"<<endl;
        cout<<" 5. Listar Archivo Presidentes"<<endl;
        cout<<" 0. SALIR DEL PROGRAMA"<<endl;
        cout<<"---------------------------------"<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: punto1();
                break;

            case 2: punto2();
                break;
            case 3: sociosInyector();
                break;
            case 4: clubesInyector();
                break;
            case 5: listarArchivoPresidentes();
                break;

            case 0: return 0;
        }
        cout<<endl;
        system("pause");
    }
    return 0;
}
