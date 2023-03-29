#include<iostream>
using namespace std;
const char *nombre_archivo = "archivo.dat";
struct Estudiante{
	int codidgo;
	char nombres [50];
	char apellidos[50];
	int telefono;	
};
void leer();
void crear();
main(){
	
	leer();
	crear();
	system("pause");
}
void leer(){
	system("cls");
	FILE* archivo = fopen(nombre_archivo,"rb");
	if(!archivo){
		archivo = fopen(nombre_archivo,"w+b");
	}
}
void crear(){
	FILE* archivo = fopen(nombre_archivo,"a+b");
    char res;
    Estudiante estudiante;
    do{
    	fflush(stdin);
    	cout<<"ingrese Codigo:";
    	cin>>estudiante.codidgo;
    	cin.ignore();
    	
    	cout<<"ingrese Nombre:";
    	cin.getline(estudiante.nombres,50); 
    	cout<<"ingrese Apellidos:";
    	cin.getline(estudiante.apellidos,50);
    	
    	cout<<"ingres telefono:";
    	cin>>estudiante.telefono;
    	
    	
    	
    	fwrite(&estudiante,sizeof(Estudiante),1,archivo);
    	cout<<"Desea ingresar otro estudiante(s/)";
    	cin>>res;
	}while(res == 's' || res=='S');
	fclose(archivo);
}

