//
// Created by nicolaslopez on 12/7/21.
//

#ifndef RECUPERATORIOPARCIAL1_FUNCIONES_H
#define RECUPERATORIOPARCIAL1_FUNCIONES_H

#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

bool listarPresidenteRegistros(){
    Presidente reg;

    FILE *pFile;

    pFile = fopen("Presidentes.dat", "rb");
    if(pFile == NULL){ return false; }
    while(fread(&reg, sizeof reg, 1, pFile) == 1){
        reg.mostrar();
    }
    fclose(pFile);
    return true;
}

void listarArchivoPresidentes(){
    if(listarPresidenteRegistros()){
        cout << "Hay registros Presidentes a mostrar." << endl;
    }else{
        cout << "NO Hay registros Presidentes a mostrar." << endl;
    }
}

map<int, Socio> convertArchivoAMap(){
    map<int, Socio> socioMap;
    Socio reg;
    FILE *pFile;

    pFile = fopen("Socios.dat", "rb");
    if(pFile == NULL){ return socioMap; }
    while(fread(&reg, sizeof reg, 1, pFile) == 1){
        //reg.mostrar();
        socioMap.insert(make_pair(reg.getDni(), reg));
    }
    fclose(pFile);

    for (auto itr = socioMap.begin(); itr != socioMap.end(); ++itr) {
        cout << "Key: " << itr->first << '\n'
             << "Values: " << '\n'
             << '\t' << itr->second.getDni() << '\n'
             << '\t' << itr->second.getNombre() << '\n'
             << '\t' << itr->second.getApellido() << '\n';
    }

    return socioMap;
}

void sociosInyector(){
    vector<Socio> sociosVector;
    sociosVector.push_back(Socio(29873249, "Nicolas", "Lopez", "nicolas@gmail.com", "73610311", 1, 2, true));
    sociosVector.push_back(Socio(30111222, "Daniela", "Altube", "Daniela@gmail.com", "08101980", 2, 3, true));
    sociosVector.push_back(Socio(32888777, "Bianca", "Xavier", "Bianca@gmail.com", "05102015", 1, 4, true));
    sociosVector.push_back(Socio(40999221, "Belkis", "Lopez", "Belkis@gmail.com", "17021956", 3, 2, true));
    sociosVector.push_back(Socio(45765234, "Hugo", "Lopez", "Hugo@gmail.com", "20111951", 1, 1, true));
    sociosVector.push_back(Socio(87361512, "Sabrina", "Lopez", "Sabrina@gmail.com", "15071894", 1, 1, true));
    sociosVector.push_back(Socio(64729127, "Thiago", "Xavier", "Thiago@gmail.com", "04042004", 4, 2, true));
    sociosVector.push_back(Socio(84720231, "Damian", "Xavier", "Damian@gmail.com", "11041981", 4, 3, true));

    vector<Socio>::iterator it = sociosVector.begin();
    while(it != sociosVector.end())
    {
        it->grabarEnDisco();
        it++;
    }
}

void clubesInyector(){
    vector<Club> clubVector;
    clubVector.push_back(Club(11, 1, 1910, 3 , "RiverPlate", 29873249, true));
    clubVector.push_back(Club(22, 2, 1933, 2, "Bayer Munich", 32888777, true));
    clubVector.push_back(Club(33, 3, 1934, 4, "Barcelona", 87361512, true));
    clubVector.push_back(Club(44, 4, 1901, 3, "Manchester City", 89340231, true));
    clubVector.push_back(Club(55, 1, 1945, 1, "Palmeiras", 569387665, true));
    clubVector.push_back(Club(66, 2, 1947, 2, "Velez", 768323313, true));

    vector<Club>::iterator it = clubVector.begin();
    while(it != clubVector.end())
    {
        it->grabarEnDisco();
        it++;
    }
    if(listarPresidenteRegistros()){
        cout << "Hay registros Presidentes a mostrar." << endl;
    }else{
        cout << "NO Hay registros Presidentes a mostrar." << endl;
    }
}

#endif //RECUPERATORIOPARCIAL1_FUNCIONES_H
