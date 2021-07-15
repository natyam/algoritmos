//============================================================================
// Name        : 64.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstring>
#include <iostream>
using namespace std;
struct Alumno{
	int legajo;
	int nota1;
	int nota2;
};

void mostrarAlumno(Alumno []);
int main() {
	cout<<"ej 64"<<endl;
	Alumno a[5]={{1234,1,2},{234,2,3},{111,4,5},{1234,6,7},{111,5,9}};

	Alumno b;
	 FILE* f=fopen("curso.txt","wt");
		//int cont=0;
		for(int i=0;i<5;i++){
			fwrite( &a[i],sizeof(b),1,f);

		}
	fclose(f);
	cout<<"termino de escribir arch uno"<<endl;
	int codMatBuscado;
	cout<<"Ingrese cod de materia a buscar: ";
	cin>>codMatBuscado;
	FILE *f1=fopen("curso.txt","rt");
	FILE *f2=fopen("cursoNuevo.txt","wt");
	cout<<"volvi a abrir dos arch ";
	Alumno a2;
	int cont=0;
	fread(&a2,sizeof(a2),1,f1);
	while(!feof(f1)){
		if(a2.legajo==codMatBuscado){
			fwrite(&a2,sizeof(a2),1,f2);
			cont++;
		}
		fread(&a2,sizeof(a2),1,f1);
	}

	fclose(f1);
	fclose(f2);
	//cout<<"cierro los dos arch ";

	cout<<"HAY "<<cont<<" cantidad de legajos repetidos";
	FILE *f5=fopen("cursoNuevo.txt","rt");
	//me paro al inicio
	//fseek(f5,0,SEEK_SET);
	cout<<"Mostrar ALUMNOS EN EL ARCHIVO:"<<endl;
	int i2=0;
		fread(&a2,sizeof(a2),1,f5);
		while(!feof(f5)){
	//while(fread(&a2,sizeof(a2),1,f5)){
			cout<<"alumno "<<i2<<" legajo: "<<a2.legajo<<" nota1: "<<a2.nota1<<" nota 2: "<<a2.nota2;
			cout<<endl;
			i2++;
			cout<<"lectura en f5";
			fread(&a2,sizeof(a2),1,f5);
		}

		fclose(f5);
		cout<<"Mostrar ALUMNOS EN EL vector:"<<endl;

	mostrarAlumno(a);
	return 0;
}
void mostrarAlumno(Alumno a[]){
	cout<<"Mostrar alumnos"<<endl;
	for(int i=0; i<5 ;i++){
		cout<<"alumno "<<i<<" legajo: "<<a[i].legajo<<" nota1: "<<a[i].nota1<<" nota 2: "<<a[i].nota2;
		cout<<endl;
	}

return ;
}
