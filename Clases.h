//
// Created by nicolaslopez on 12/7/21.
//

#ifndef RECUPERATORIOPARCIAL1_CLASES_H
#define RECUPERATORIOPARCIAL1_CLASES_H


#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <cstring>

using namespace std;

/** Clase Socio */
class Socio{

private:
    int dni;
    char nombre[30];
    char apellido[30];
    char email[40];
    char telefono[20];
    int tipo, localidad;
    bool estado;

public:
    Socio(){}
    Socio(int documento, const char *firstName = "NombreDefault", const char *lastName = "NombreDefault",
          const char *email = "EmailDefault",  const char *tel = "telefonoDefault", int type = 0, int loc = 0, int e = true){
        dni = documento;
        strcpy(nombre, firstName);
        strcpy(apellido, lastName);
        strcpy(telefono, tel);
        tipo = type;
        localidad = loc;
        estado = e;
    }
    void cargar();
    void mostrar();
    bool leerDeDisco(int);
    bool grabarEnDisco();

    int getDni() const {
        return dni;
    }

    const char *getNombre() const {
        return nombre;
    }

    const char *getApellido() const {
        return apellido;
    }

    const char *getEmail() const {
        return email;
    }

    const char *getTelefono() const {
        return telefono;
    }

    int getTipo() const {
        return tipo;
    }

    int getLocalidad() const {
        return localidad;
    }

    bool isEstado() const {
        return estado;
    }

    void setDni(int dni) {
        Socio::dni = dni;
    }

    void setTipo(int tipo) {
        Socio::tipo = tipo;
    }

    void setLocalidad(int localidad) {
        Socio::localidad = localidad;
    }

    void setEstado(bool estado) {
        Socio::estado = estado;
    }
};

bool Socio::leerDeDisco(int pos) {
    FILE *file;
    file = fopen("Socios.dat", "rb");
    if(file == NULL)exit(1);
    fseek(file, sizeof(Socio)*pos, 0);
    bool leyo = fread(this, sizeof *this, 1, file);
    fclose(file);
    return leyo;
}

bool Socio::grabarEnDisco(){
    FILE *file;
    file = fopen("Socios.dat", "ab");
    if(file == NULL) return false;
    bool grabo = fwrite(this, sizeof *this, 1, file);
    fclose(file);
    return grabo;
}

void Socio::cargar(){
    cout << "INGRESE EL DNI: ";
    cin >> dni;
    cout << "INGRESE LA NOMBRE: ";
    cin >> nombre;
    cout << "INGRESE EL APELLIDO: ";
    cin >> apellido;
    cout << "INGRESE EL TELEFONO: ";
    cin >> telefono;
    cout << "INGRESE EL TIPO: ";
    cin >> tipo;
    cout << "INGRESE EL LOCALIDAD: ";
    cin >> localidad;
    estado = true;
}

void Socio::mostrar(){
    if(estado == true){
        cout << "DNI: ";
        cout << dni << endl;
        cout << "NOMBRE: ";
        cout << nombre << endl;
        cout << "APELLIDO: ";
        cout << apellido << endl;
        cout << "EMAIL: ";
        cout << email << endl;
        cout << "TELEFONO: ";
        cout << telefono << endl;
        cout << "TIPO: ";
        cout << tipo << endl;
        cout << "LOCALIDAD: ";
        cout << localidad << endl;
        cout << "ESTADO: ";
        cout << estado << endl;
        cout << endl;
    }
}

/** Clase Club */
class Club{

private:
    int numero;
    int disciplina, anio, localidad;
    char nombre[45];
    int dniPresidente;
    bool estado;

public:
    Club(){}
    Club(int number = -1, int discipline = -1, int year = -1, int loc = -1, const char *name = "NombreDefault", int dniPresident = -1, bool estate = true ){
        numero = number;
        disciplina = discipline;
        anio = year;
        localidad = loc;
        strcpy(nombre, name);
        dniPresidente = dniPresident;
        estado = estate;
    }
    void cargar();
    void mostrar();
    bool leerDeDisco(int);
    bool grabarEnDisco();

    int getNumero() const {
        return numero;
    }

    int getDisciplina() const {
        return disciplina;
    }

    int getAnio() const {
        return anio;
    }

    int getLocalidad() const {
        return localidad;
    }

    const char *getNombre() const {
        return nombre;
    }

    int getDniPresidente() const {
        return dniPresidente;
    }

    bool isEstado() const {
        return estado;
    }

    void setNumero(int numero) {
        Club::numero = numero;
    }

    void setDisciplina(int disciplina) {
        Club::disciplina = disciplina;
    }

    void setAnio(int anio) {
        Club::anio = anio;
    }

    void setLocalidad(int localidad) {
        Club::localidad = localidad;
    }

    void setDniPresidente(int dniPresidente) {
        Club::dniPresidente = dniPresidente;
    }

    void setEstado(bool estado) {
        Club::estado = estado;
    }
};

bool Club::leerDeDisco(int pos) {
    FILE *file;
    file = fopen("Clubes.dat", "rb");
    if(file == NULL)exit(1);
    fseek(file, sizeof(Club)*pos, 0);
    bool leyo = fread(this, sizeof *this, 1, file);
    fclose(file);
    return leyo;
}

bool Club::grabarEnDisco(){
    FILE *file;
    file = fopen("Clubes.dat", "ab");
    if(file == NULL) return false;
    bool grabo = fwrite(this, sizeof *this, 1, file);
    fclose(file);
    return grabo;
}

void Club::cargar(){
    cout << "INGRESE EL NUMERO: ";
    cin >> numero;
    cout << "INGRESE LA DISCIPLINA: ";
    cin >> disciplina;
    cout << "INGRESE EL ANIO: ";
    cin >> anio;
    cout << "INGRESE EL LOCALIDAD: ";
    cin >> localidad;
    cout << "INGRESE EL NOMBRE: ";
    cin >> nombre;
    cout << "INGRESE EL DNI-PRESIDENTE: ";
    cin >> dniPresidente;
    estado = true;
}

void Club::mostrar(){
    if(estado == true){
        cout << "NUMERO: ";
        cout << numero << endl;
        cout << "DISCIPLINA: ";
        cout << disciplina << endl;
        cout << "ANIO: ";
        cout << anio << endl;
        cout << "LOCALIDAD: ";
        cout << localidad << endl;
        cout << "NOMBRE: ";
        cout << nombre << endl;
        cout << "DNI-PRESIDENTE: ";
        cout << dniPresidente << endl;
        cout << "ESTADO: ";
        cout << estado << endl;
        cout << endl;
    }
}

class Presidente{
private:
    int dni;
    char nombre[30];
    char apellido[30];
    bool estado;

public:
    Presidente(){}

    Presidente(int documento, const char *firstName = "NombreDefault", const char *lastName = "NombreDefault", int e = true){
        dni = documento;
        strcpy(nombre, firstName);
        strcpy(apellido, lastName);
        estado = e;
    }

    int getDni() const;

    const char *getNombre() const;

    const char *getApellido() const;

    bool isEstado() const;

    void setDni(int dni);

    bool grabarEnDisco();

    void mostrar();



};

bool Presidente::grabarEnDisco(){
    FILE *file;
    file = fopen("Presidentes.dat", "ab");
    if(file == NULL) return false;
    bool grabo = fwrite(this, sizeof *this, 1, file);
    fclose(file);
    return grabo;
}

int Presidente::getDni() const {
    return dni;
}

const char *Presidente::getNombre() const {
    return nombre;
}

const char *Presidente::getApellido() const {
    return apellido;
}

void Presidente::setDni(int dni) {
    Presidente::dni = dni;
}

bool Presidente::isEstado() const {
    return estado;
}

void Presidente::mostrar(){
    if(estado == true){
        cout << "DNI-PRESIDENTE: ";
        cout << dni << endl;
        cout << "NOMBRE: ";
        cout << nombre << endl;
        cout << "APELLIDO: ";
        cout << apellido << endl;
        cout << "ESTADO: ";
        cout << estado << endl;
        cout << endl;
    }
}

#endif //RECUPERATORIOPARCIAL1_CLASES_H
