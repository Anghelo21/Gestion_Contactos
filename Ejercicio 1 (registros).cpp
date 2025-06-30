#include <iostream>
#include <string>
using namespace std;

struct contactoEmail{
	string nombre;
	string sexo;
	int edad;
	string telefono;
	string email;
	string nacionalidad; 
};

const int TAM=100;
contactoEmail contactos[TAM] = {
	{"Anghelo Calderon", "M", 18, "940 399 215", "an@gmail.com", "Peruano"},
	{"Carl Einstein", "M", 23, "956 235 453", "ce@gmail.com", "Checoslovaco"}
};
int cantidad=2;

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
    cin.ignore();
    cout<<"Ingrese el telefono: ";
    getline(cin, nuevo.telefono);
    cout<<"Ingrese el email: ";
    getline(cin, nuevo.email);
    cout<<"Ingrese la nacionalidad: ";
    getline(cin, nuevo.nacionalidad);
    
    contactos[cantidad]=nuevo;
    cantidad=cantidad+1;
}

void eliminar(){
	int indice;
    cout<<"Ingrese el indice del contacto a eliminar(1 - "<<cantidad<<"): ";
    cin>>indice;
    cin.ignore();
    if(indice>0 && indice<=cantidad){
    	for(int i=indice-1; i<cantidad-1; i++){
        contactos[i]=contactos[i+1];
    	}
    	cantidad--;
    	cout<<"Contacto eliminado"<<endl;
	} else{
		cout<<"indice no valido"<<endl;
	}
}

void mostrar(){
    for(int i=0; i<cantidad; i++){
        cout<<endl<<"Contacto "<<(i + 1)<<": "<<endl;
        cout<<"Nombre: "<<contactos[i].nombre<<endl;
        cout<<"Sexo: "<<contactos[i].sexo<<endl;
        cout<<"Edad: "<<contactos[i].edad<<endl;
        cout<<"Telefono: "<<contactos[i].telefono<<endl;
        cout<<"Email: "<<contactos[i].email<<endl;
        cout<<"Nacionalidad: "<<contactos[i].nacionalidad<<endl;
    }
}

string buscar(const string &email){
    int posi=-1;
    for (int i=0; email[i]!='\0'; i++){
        if(email[i]=='@'){
            posi=i;
            break;
        }
    }
    string dominio="";
    if(posi!=-1){
        for(int i=posi+1; email[i]!='\0'; i++){
            dominio=dominio+email[i];
        }
    }
    return dominio;
}

void orden(){
    for(int i=0; i<cantidad-1; i++){
        for (int j=0; j<cantidad-i-1; j++){
            if (buscar(contactos[j].email)>buscar(contactos[j+1].email)){
                contactoEmail aux=contactos[j];
                contactos[j]=contactos[j+1];
                contactos[j+1]=aux;
            }
        }
    }
    cout<<endl<<"Contactos agrupados por dominio de correo:"<<endl;
    mostrar();
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
		cout<<"Seleccione una opcion: ";
		cin>>opcion;
		cin.ignore();
		switch(opcion){
			case 1:
				agregar();
				break;
			case 2:
				eliminar();
				break;
			case 3:
				mostrar();
				break;
			case 4:
				orden();
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
