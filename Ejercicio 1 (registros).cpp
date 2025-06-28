#include <iostream>
#include <string>
using namespace std;

struct contactoEmail{
	string nombre, sexo, email, nacionalidad;
	int edad, telefono;
};

int main(){
	int opcion;
	do{
		cout<<" --- Menu --- "<<endl;
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
				//agregar();
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
