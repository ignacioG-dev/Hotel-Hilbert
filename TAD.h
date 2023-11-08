#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define MAXV 50

/*Declaracion tipo de datos personalizados*/

typedef char tString[50];

tString tGenero[3]={"Hombre","Mujer","Otro"};	 
tString tPlanes[2]={"Basico","Premium"};

/*Declaracion de estructura de datos de los huespedes*/
typedef struct{
	int piso;
	int habitacion;
	tString nombre;
	tString email;
	int genero;
	int plan;
}tElem;

/*Estructura tipo lista*/
typedef struct nodo{
	tElem elem;
	struct nodo* siguiente;
}tLista;





/* Parte pública: INTERFAZ */

/*Prototipo de funciones*/

/*Etapa 3: Estructuras compuestas enlazadas (implementación dinámica mediante listas enlazadas)*/
void inicializarLista(tLista**);
bool listaVacia(tLista*);
void insertarElemento(tElem,tLista**);
void eliminarPrimero(tLista **);
void eliminarEnPos(int,tLista**);
int cantidadNodos(tLista*);
void ordenarLista(tLista*);
void visualizarElementos(tLista*);
bool elementoRepetido(tLista*,tElem);

//Funciones extras
bool login(tString,tString); 		 			//Pasamos como parametro lo que queremos que sea usuario y contraseña
void sleep(time_t seconds);						//Funcion que nos permite pausar por determiando tiempo la consola






/* Parte Privada: IMPLEMENTACIÓN */

/*Etapa 3: Lista*/
void inicializarLista(tLista** pLista){
	(*pLista)=NULL;
}

bool listaVacia(tLista* pLista){
	return pLista==NULL;
}

void insertarElemento(tElem pElem,tLista** pLista){
	tLista * nuevoNodo;

	nuevoNodo = ( tLista * ) malloc(sizeof(tLista));

	nuevoNodo->elem = pElem;
	
	nuevoNodo->siguiente = *pLista;
	
	*pLista = nuevoNodo;
	
	printf("\n\tHuesped a%cadido a la lista>> NOMBRE [%s]  >> HABITACION [%d]",164,pElem.nombre,pElem.habitacion);	
}

void eliminarEnPos(int pos,tLista** pLista){
	int i, cantNodos;
	tLista * aux, * nodoSuprimir;
	
	cantNodos = cantidadNodos( *pLista );
	
	if( pos <= cantNodos && pos > 0 ) {
		
		if( pos == 1 ) {
			eliminarPrimero( &(*pLista ));
		} else {
			aux = *pLista;
			
			for(i=1; i<pos-1; i++ ) {
				aux = aux->siguiente;
			}
			
			nodoSuprimir = aux->siguiente;
			
			aux->siguiente = nodoSuprimir->siguiente;
			
			printf("\nHabitacion desocupada >> Opcion: %d >> Piso: %d >> HABITACION %d",pos,nodoSuprimir->elem.piso,nodoSuprimir->elem.habitacion);
			
			free(nodoSuprimir);
			
			nodoSuprimir = NULL;
		}	
	} else {
		printf("\nERROR - No hay huespedes en posicion ingresada\n");
	}		
}

void eliminarPrimero( tLista ** pLista ) {
	if ( listaVacia( *pLista ) ) {
		printf("ERROR - No hay huespedes en el hotel\n");
	} else {
		tLista * nodoSuprimir = *pLista;
		
		*pLista = (*pLista)->siguiente;
		
		printf("\nHabitacion desocupada >> Opcion: 1 >> Piso: %d >> HABITACION %d",nodoSuprimir->elem.piso,nodoSuprimir->elem.habitacion);	
		
		free(nodoSuprimir);
		
		nodoSuprimir = NULL;
	}
	
}

int cantidadNodos(tLista* pLista){
	tLista * aux;
	aux = pLista;
	
	if( aux != NULL ) {
		return 1+cantidadNodos(aux->siguiente);			
	} else{
		return 0;	
	}
}

void visualizarElementos(tLista* pLista){
	tLista * aux;
	aux = pLista;
	
	if( !listaVacia(aux) ) {
		printf("\n\t***Huespedes en el hotel***");
		printf("\n\t--------------------------------------------------");
		while(aux != NULL) {
			printf("\n\t\t\tHUESPED");
			printf("\n\t--------------------------------------------------");
			printf("\n\tPiso:               %d",aux->elem.piso);
			printf("\n\tHabitacion:         %d",aux->elem.habitacion);
			printf("\n\tNombre:             %s",aux->elem.nombre);
			printf("\n\tE-Mail:             %s",aux->elem.email);
			printf("\n\tGenero:             %s",tGenero[aux->elem.genero-1]);
			printf("\n\tPlan acreditado:    %s",tPlanes[aux->elem.plan-1]);
			printf("\n\t--------------------------------------------------");
			aux=aux->siguiente;
		}
		
	} else {
		printf("ERROR - No hay huespedes en el hotel\n");
	}	
}

void ordenarLista(tLista* pLista)
{
	tLista* t;
	tLista* s;
	tElem aux;
	t=pLista;
	
	while(t!=NULL)
	{
		s=t->siguiente;
		while(s!=NULL)
		{
			if(t->elem.piso > s->elem.piso)
			{
				aux=t->elem;
				t->elem=s->elem;
				s->elem=aux;
			}
			s= s->siguiente;
		}
		t=t->siguiente;
	}
	t=pLista;
}

bool elementoRepetido(tLista* pLista,tElem pElem)
{
	tLista* auxiliar;
	auxiliar=pLista;
	while(auxiliar!=NULL)
	{
		if(auxiliar->elem.piso== pElem.piso && auxiliar->elem.habitacion== pElem.habitacion)
		{	
			return true;
		}
		auxiliar=auxiliar->siguiente;
	}
	return false;
}





/*Funcion extra*/
bool login(tString user, tString pass) 				
{
	time_t tiempoAhora;
    tString user1,pass1;
    bool acceso = false;
    int a=0;
    while(a!=4)
    {
        system("cls");

        printf("\n\t\t%c%cINICIAR SESI%cN%c%c",175,175,224,174,174);
        
        printf("\n\n\tIngresar USUARIO: \t");
        scanf("%s",&user1);

        printf("\n\tIngresar CONTRASE%cA: \t",165);
        scanf("%s",&pass1);

        if(strcmp(user1,user)==0 && strcmp(pass1,pass)==0)
        {
            printf("\n\tSesion inicidada, espere un momento %c%c%c",254,254,254);
            sleep(1);
            printf("%c%c%c",254,254,254);
            acceso=true;
            
       		time(&tiempoAhora);
			printf("\n%s",ctime(&tiempoAhora));
			
            return acceso;
        }
        else{
        	if(strcmp(user1,user)!=0){
        		printf("\n\tUsuario");
        		
        		if(strcmp(pass1,pass)!=0){
        			printf(" y contrase%ca",164);
				}
				
				printf(" incorrecto");
			} else{
				printf("\n\tContrase%ca incorrecta",164);
			}
			
        	a++;
        	printf("\n\n\tIntento (%d/3)",a);
        	printf("\n\tEspere un momento...");
        	sleep(2);
        	
        	if(a==3){
       			return acceso;
   			}
        }
    }
}
























