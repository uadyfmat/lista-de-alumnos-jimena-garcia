#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Alumno {	
	char nombre[100];
	int creditos;
	int semestre;
	
};

struct Nodo{
	struct Alumno alumno;
	struct Nodo *siguiente;
	
};

struct Alumno crearAlumno(char nombre[], int creditos, int semestre);
void imprimirAlumno(struct Alumno alumno);
struct Nodo *crearNodo(struct Alumno alumno);
int insertarNodoOrdenadoCreditos(struct Nodo **lista, struct Nodo *nuevoNodo);
void imprimirLista(struct Nodo *lista);

int main() {
	
	struct Alumno alumno1 = crearAlumno("Juan Perez Gomez", 120, 5);
	struct Alumno alumno2 = crearAlumno("Maria Lopez Sanchez", 90, 4);
	struct Alumno alumno3 = crearAlumno("Carlos Gomez Zapata", 150, 6);
	struct Alumno alumno4 = crearAlumno("Ana Rodriguez Villanueva", 80, 3);
	struct Alumno alumno5 = crearAlumno("Luis Martinez Chay", 110, 5);
	struct Nodo *lista = NULL;
	
	insertarNodoOrdenadoCreditos(&lista, crearNodo(alumno1));
	insertarNodoOrdenadoCreditos(&lista, crearNodo(alumno2));
	insertarNodoOrdenadoCreditos(&lista, crearNodo(alumno3));
	insertarNodoOrdenadoCreditos(&lista, crearNodo(alumno4));
	insertarNodoOrdenadoCreditos(&lista, crearNodo(alumno5));
	
	imprimirLista(lista);
	return 0;	
}
struct Alumno crearAlumno(char nombre[], int creditos, int semestre) {
	struct Alumno alumno;
	strcpy(alumno.nombre, nombre);
	alumno.creditos = creditos;
	alumno.semestre = semestre;
	return alumno;
}
void imprimirAlumno(struct Alumno alumno) {	
	printf("Nombre: %s, Creditos: %d, Semestre: %d", alumno.nombre, alumno.creditos, alumno.semestre);	
	printf("\n");
}

struct Nodo *crearNodo(struct Alumno alumno) {	
	struct Nodo *nuevoNodo = (struct Nodo *)malloc(sizeof(struct Nodo));	
	nuevoNodo->alumno = alumno;	
	nuevoNodo->siguiente = NULL;	
	return nuevoNodo;	
}

int insertarNodoOrdenadoCreditos(struct Nodo **lista, struct Nodo *nuevoNodo) {
	if (*lista == NULL || nuevoNodo->alumno.creditos >= (*lista)->alumno.creditos) {	
		nuevoNodo->siguiente = *lista;		
		*lista = nuevoNodo;		
		return 1;	
	}
	
	struct Nodo *actual = *lista;	
	while (actual->siguiente != NULL && actual->siguiente->alumno.creditos > nuevoNodo->alumno.creditos) {		
		actual = actual->siguiente;		
	}
	
	nuevoNodo->siguiente = actual->siguiente;
	actual->siguiente = nuevoNodo;	
	return 1;
	
}

void imprimirLista(struct Nodo *lista) {	
	struct Nodo *actual = lista;	
	while (actual != NULL) {		
		imprimirAlumno(actual->alumno);		
		actual = actual->siguiente;		
	}	
}