#include "Fecha.h"
#include <iostream>

using namespace std;

Fecha::Fecha(){
    _dia = 0;
    _mes = 0;
    _anio = 0;
}

Fecha::Fecha(int dia, int mes, int anio){
    _dia = dia;
    _mes = mes;
    _anio = anio;
}

int Fecha::getDia(){
    return _dia;
}

int Fecha::getMes(){
    return _mes;
}

int Fecha::getAnio(){
    return _anio;
}

void Fecha::setDia(int dia){
    _dia = dia;
}

void Fecha::setMes(int mes){
    _mes = mes;
}

void Fecha::setAnio(int anio){
    _anio = anio;
}

string Fecha::toString(){
    return to_string(_dia) + "/" + to_string(_mes) + "/" + to_string(_anio);
}

void Fecha::cargar(){
    int d, m, a;
    std::cout<<"DIA ";
    std::cin>>d;
    setDia(d);
    std::cout<<"MES ";
    std::cin>>m;
    setMes(m);
    std::cout<<"ANIO ";
    std::cin>>a;
    setAnio(a);
}

void Fecha::mostrar(){
    std::cout<<_dia<<"/"<<_mes<<"/"<<_anio<<std::endl;
}
