#include <iostream>
#include <string>
using namespace std;

struct contactoEmail{
	string nombre, sexo, email, nacionalidad;
	int edad, telefono;
};

const int TAM=100;
contactoEmail contactos[TAM];
int cantidad=0;

void agregar(){
	if(cantidad>=TAM){
		cout<<"No se pueden agregar mas contactos";
		return;
	}
	
	contactoEmail nuevo;
    cout<<"Ingrese el nombre completo: ";
    getline(cin, nuevo.nombre);
    cout<<"Ingrese el sexo (M/F): ";
    getline(cin, nuevo.sexo);
    cout<<"Ingrese la edad: ";
    cin>>nuevo.edad;
    cout<<"Ingrese el telefono: ";
    cin>>nuevo.telefono;
    cin.ignore();
    cout<<"Ingrese el email: ";
    getline(cin, nuevo.email);
    cout<<"Ingrese la nacionalidad: ";
    getline(cin, nuevo.nacionalidad);
    
    contactos[cantidad]=nuevo;
    cantidad=cantidad+1;
}

int main(){
	int opcion;
	do{
		cout<<endl<<" --- Menu --- "<<endl;
		cout<<"1. Agregar contacto"<<endl;
		cout<<"2. Eliminar contacto"<<endl;
		cout<<"3. Mostrar lista general de contactos"<<endl;
		cout<<"4. Mostrar contactos ordenados por correo"<<endl;
		cout<<"5. Salir del programa"<<endl;
		cout<<"Seleccione una opcion"<<endl;
		cin>>opcion;
		cin.ignore();
		switch(opcion){
			case 1:
				agregar();
				break;
			case 2:
				//eliminar();
				break;
			case 3:
				//mostrar();
				break;
			case 4:
				//orden();
				break;
			case 5:
				cout<<"Saliendo..."<<endl;
				break;
			default:
				cout<<"Opcion invalida"<<endl;
				break;			
		}
	} while(opcion!=5);
	return 0;
}
