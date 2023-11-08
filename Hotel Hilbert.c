#include "TAD.h"

/*Declaracion de variables*/
tLista* lista;								
tElem dato;
FILE* archivo;


//Variables globales para el corte de control
int codigoPisoAnt,totHuespedes;
int totHombrePiso,totHombre;
int totMujerPiso,totMujer;
int totOtroPiso,totOtros;
int totPlan1Piso,totPlan1;
int totPlan2Piso,totPlan2;
float totMonto1Piso,totMonto1;
float totMonto2Piso,totMonto2;		

int pasadas=0;								//Se utilizara para el titulo del .txt

//Declaracion de prototipo de funciones
void principio();							//Se inicializan las estructuras de pila y lista
void menu();
void menuLista();
void infoPlanes();
void ingresarDatos();
void reporte();


/*Etapa 4: Corte de control y manejo de archivos*/
void informeDeDatos();
void inicializar();
void procesoCorte();
void finalizar();
void principioCorte();
void unDoc();
void finCorte();
void iniciarSesion();
void leerArchivo();
void grabarArchivo();


int main(){
	principio();
	menu();
	
	return 0;
}

void principio(){
	codigoPisoAnt=0,totHuespedes=0;
	totHombrePiso=0,totHombre=0;
	totMujerPiso=0,totMujer=0;
	totOtroPiso=0,totOtros=0;
	totPlan1Piso=0,totPlan1=0;
	totPlan2Piso=0,totPlan2=0;
	totMonto1Piso=0,totMonto1=0;
	totMonto2Piso=0,totMonto2=0;
	
	inicializarLista(&lista);
}

void menu(){
	int res;
	
	
	do{
		printf("\t %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
		printf("\n\t*%c\t\t\t    %c*",186,186);
		printf("\n\t*%c\tHILBERT HOTEL\t    %c*",186,186);
		printf("\n\t*%c\t\t\t    %c*",186,186);
		printf("\n\t %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
		
		printf("\n\tBIENVENIDO: [OPCION]");
		printf("\n\t%c%c%c%c%c%c%c%c%c%c",223,223,223,223,223,223,223,223,223,223);
		printf("\n\t0%c Salir\n\t1%c Grabar \t\t   [ARCHIVO]\n\t2%c Huespedes \t\t   [LISTA]\n\t3%c Historial de huespedes  [CORTE CONTROL]\n\t4%c Informacion de planes",175,175,175,175,175,175,175);
		printf("\n\n\tSeleccione opcion: [ ]\b\b");
		scanf("%d",&res);
		
		switch(res){
			case 0:{
				printf("\n\tSaliendo, espere un momento...");
				sleep(1);	
				break;
			}
			
			case 1: {
				system("cls");
				
				ingresarDatos();
		
				break;
			}
			
			case 2: {
				system("cls");
				menuLista();
				
				break;
			}
			
			case 3: {
				system("cls");
				ordenarLista(lista);
				grabarArchivo(lista);
				printf("\n\t\t\t\t\t==> HISTORIAL DE HUESPEDES <==\n\n");				
				informeDeDatos();
				printf("\n\n");
				system("pause");
				
				break;
			}
			
			case 4: {
				system("cls");
				printf("\n\t\t\t\t\t==> PLANES Y PRECIO <==\n\n");
				infoPlanes();
				break;
			}
			
			default: {
				printf("\n\tIngreso una opcion incorrecta, vuelva a ingresar");
				break;
			}
		}
		system("cls");
		
	}while(res!=0);
}

/*ETAPA 3*/
void menuLista(){
	int respuesta,posicion;
	
	do {
		printf("\t %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
		printf("\n\t*%c\t\t\t    %c*",186,186);
		printf("\n\t*%c\tHILBERT HOTEL\t    %c*",186,186);
		printf("\n\t*%c\t\t\t    %c*",186,186);
		printf("\n\t %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
				
		printf("\n\tBIENVENIDO: [LISTA]");
		printf("\n\t%c%c%c%c%c%c%c%c%c%c",223,223,223,223,223,223,223,223,223,223);
		printf("\n\t0%c Salir\n\t1%c Visualizar huespedes\n\t2%c Desocupar",175,175,175,175);
		printf("\n\n\tSeleccionar opcion: [ ]\b\b");
		scanf("%d",&respuesta);
		
		
		switch(respuesta){
			case 0: {
				printf("\n\tSaliendo, espere un momento...");
				sleep(1);
				
				break;
			}
			
			case 1: {
				printf("\n\t\t\t==> MOSTRAR HUESPEDES <==\n");
				int res;
				if(listaVacia(lista)){
					printf("\n\tNo hay huespedes por mostrar");
					getch();
				}else{
					visualizarElementos(lista);
					printf("\n\tDesea guardar el reporte en un archivo de texto (1.Si-2.No): ");
					scanf("%d",&res);
				
					if(res==1){
						reporte();
					}		
				}
				
				break;
			}
			
			case 2: {
				printf("\n\t\t\t==> DESOCUPAR HABITACION <==\n");
				if(!listaVacia(lista)){
					tLista* auxi;
					auxi=lista;
					int i=0;
					
					printf("\n\t\t| Habitaciones ocupadas |");
					printf("\n\t\t\tPISO \t HABITACION\n");
					while(auxi!=NULL){
						printf("\t Posicion: %d |  %d \t %d  \n",i+1,auxi->elem.piso,auxi->elem.habitacion);
						i++;
						auxi=auxi->siguiente;
					}
					
					printf("\n\n\tIngresar la posicion  de la habitacion a desocupar: ");
					scanf("%d",&posicion);
					eliminarEnPos(posicion,&lista);	
					pasadas--;			
				} else{
					printf("\n\tNo hay huespedes en las habitaciones");
				}
				getch();
				break;
			}

			
			default: printf("\nIngreso una opcion incorrecta, vuelva a ingresar");
		}
		system("cls");
		
	} while(respuesta!=0);	
}

/*ETAPA 4*/
void grabarArchivo(tLista* pLista)
{
	tLista* auxiliar;
	auxiliar=pLista;
	archivo=fopen("Huespedes.dat","wb");
	while(auxiliar!=NULL)
	{
		fwrite(&auxiliar->elem,sizeof(tElem),1,archivo);
		auxiliar=auxiliar->siguiente;
	}
	
	fclose(archivo);
}

void informeDeDatos(){
	inicializar();
	procesoCorte();
	finalizar();	
}

void inicializar(){
	archivo=fopen("Huespedes.dat","rb");
	
	if(archivo==NULL){
		perror("\tError al abrir el archivo");
		printf("\n\t");
		system("pause");
		system("cls");
		menu();
	} else{
		fread(&dato,sizeof(tElem),1,archivo);
		totHuespedes=0;
		totHombre=0;
		totMujer=0;
		totOtros=0;
		totMonto1=0;
		totMonto2=0;
		totPlan1=0;
		totPlan2=0;
		codigoPisoAnt=dato.piso;
		printf("\tPISO\tHABITACION\tGENERO\tPLAN\tEMAIL\t\t\tNOMBRE Y APELLIDO");
	}
}

void procesoCorte(){
	while(!feof(archivo)){
		principioCorte();
		
		while(!feof(archivo)&&codigoPisoAnt==dato.piso){
			unDoc();
			fread(&dato,sizeof(tElem),1,archivo);
		}
		
		finCorte();
	}
}

void principioCorte(){
	totHombrePiso=0;
	totMujerPiso=0;
	totOtroPiso=0;
	totMonto1Piso=0;
	totMonto2Piso=0;
	totPlan1Piso=0;
	totPlan2Piso=0;
}

void unDoc(){
	totHuespedes++;
	
	if(dato.genero==1){
		totHombrePiso++;
		totHombre++;		
	}
	
	if(dato.genero==2){
		totMujerPiso++;
		totMujer++;
	}
	
	if(dato.genero==3){
		totOtroPiso++;
		totOtros++;
	}
	
	if(dato.plan==1){
		totPlan1Piso++;
		totPlan1++;
		totMonto1Piso+=3500;
		totMonto1+=3500;
	}
	
	if(dato.plan==2){
		totPlan2Piso++;
		totPlan2++;		
		totMonto2Piso+=8000;
		totMonto2+=8000;
	}
	
	printf("\n\t%d\t%d\t\t%s\t%s\t%s\t%s",dato.piso,dato.habitacion,tGenero[dato.genero-1],tPlanes[dato.plan-1],dato.email,dato.nombre);
}

void finCorte(){
	printf("\n\t----------------------------------------------------------------------------------------------------------");
	printf("\n\tTOTALES EN PISO %d:",codigoPisoAnt);
	printf("\n\t Mujeres [%d] / Hombres [%d] / Otro [%d] ",totMujerPiso,totHombrePiso,totOtroPiso);
	printf("\n\t Plan: Basico [%d] Total: $%.2f - Premium [%d] Total: $%.2f ",totPlan1Piso,totMonto1Piso,totPlan2Piso,totMonto2Piso);
	printf("\n\t------------------------------------------------------------------------------------------------------------");
	codigoPisoAnt=dato.piso;
}

void finalizar(){
	float montorRecaudado=totMonto1+totMonto2;
	
	printf("\n\t\t***TOTAL GENERAL***");
	printf("\n\tTOTAL Huespedes -----------> %d",totHuespedes);
	printf("\n\t---------------------------------------------------------");
	printf("\n\tTOTAL Mujeres -------------> %d",totMujer);
	printf("\n\tTOTAL Hombres -------------> %d",totHombre);
	printf("\n\tTOTAL Otro ----------------> %d",totOtros);
	printf("\n\t---------------------------------------------------------");
	printf("\n\tTOTAL Basico --------------> %d",totPlan1);
	printf("\n\tTOTAL Premium -------------> %d",totPlan2);	
	printf("\n\tTOTAL Recaudado -----------> $%.2f",montorRecaudado);

	fclose(archivo);
}







void ingresarDatos(){
	int continuar;
	bool repetido=false;
	do{
		printf("\n\t\t\t\t\t==> AGREGAR HUESPEDES <==\n");
		
		printf("\n\tIngresar: \n");
		printf("\n\t\tNumero de piso:                             ");
		scanf("%d",&dato.piso);
		
		printf("\n\t\tNumero de habitacion:                       ");
		scanf("%d",&dato.habitacion);
		
		repetido=elementoRepetido(lista,dato); 						//Verifica elemento que ingresa si esta repetido
		
		if(repetido==true)
		{
			printf("\n\tERROR - Piso %d / Habitacion %d ya ocupado, ingrese nuevamente!",dato.piso,dato.habitacion);	
			
			printf("\n\n\tDesea seguir grabando huespedes (1.Si-0.No): ");
			scanf("%d",&continuar);	
		}
		
		if(repetido==false)
		{
		printf("\n\t\tApellido y nombre:                          ");
		fflush(stdin);
		scanf("%[^\n]s",&dato.nombre);
		
		printf("\n\t\tEmail:                                      ");
		fflush(stdin);
		scanf("%[^\n]s",&dato.email);
		
		printf("\n\t\tGenero(1.Hombre/2.Mujer/3.Otro):            ");
		scanf("%d",&dato.genero);
		
		printf("\n\t\tSeleccionar plan (1.Basico/2.Premium):      ");
		scanf("%d",&dato.plan);	
		
		insertarElemento(dato,&lista);
		
		printf("\n\n\tDesea grabar huespedes (1.Si-0.No): ");
		scanf("%d",&continuar);
		}
		
		
		system("cls");	
	}while(continuar!=0);	
}

void reporte(){
	tLista* aux;
	aux= lista;
	time_t tiempoAhora;
	
	archivo = fopen("reporte.txt", "a");
	
	pasadas++;
	
	time(&tiempoAhora);
	
	if(pasadas==1){
		fprintf(archivo, "\n\t\t    ==> LISTADO DE HUESPEDES REGISTRADOS <==   Fecha actualizacion: %s\n",ctime(&tiempoAhora));
		fprintf(archivo, " -------------------------------------------------------------------------------------------------------\n");
		fprintf(archivo, "\nPISO\tHABITACION\tGENERO\t\tPlan\t\tEMAIL\t\t\tNOMBRE Y APELLIDO");
		fprintf(archivo, " -------------------------------------------------------------------------------------------------------\n");
		while(aux!=NULL){
			fprintf(archivo,"\n%d\t%d\t\t%s\t\t%s\t%s\t\t%s",aux->elem.piso,aux->elem.habitacion,tGenero[aux->elem.genero-1],tPlanes[aux->elem.plan-1],aux->elem.email,aux->elem.nombre);
			aux=aux->siguiente;
		}
	} else{
		fprintf(archivo, " -------------------------------------------------------------------------------------------------------\n");
		fprintf(archivo, "\n Fecha actualizacion: %s \n",ctime(&tiempoAhora));
		while(aux!=NULL){
			fprintf(archivo,"\n%d\t%d\t\t%s\t\t%s\t%s\t\t%s",aux->elem.piso,aux->elem.habitacion,tGenero[aux->elem.genero-1],tPlanes[aux->elem.plan-1],aux->elem.email,aux->elem.nombre);
			aux=aux->siguiente;
		}	
	}
			
		
	fclose(archivo);
}

void infoPlanes(){
	printf("\t %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
	printf("--------------------------------------------------");
	printf("\n\t %c    BASICO: PLAN AR (Plan Argentino)\t%c",186,186);
	printf("\tPRECIO: 3.500 ARS al dia + Extras");	
	printf("\n\t %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
	printf("--------------------------------------------------");
	printf("\n\t %cPaga:            Alojamiento y Extras %c",186,186);
	printf("\tCOMIDAS: ---");
	printf("\n\t %cServicio:        A Cargo Del Huesped  %c",186,186);
	printf("\tSERVICIO: ---");
	printf("\n\t %cComidas:         No Incluye\t\t%c",186,186);
	printf("\tMANTENIMIENTO: ---");
	printf("\n\t %cMantenimiento:   A Cargo Del Huesped  %c",186,186);
	printf("\tEXTRAS: Luz, Agua, Internet");
	printf("\n\t %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
	printf("--------------------------------------------------");
	
	printf("\n\t %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
	printf("--------------------------------------------------");	
	printf("\n\t %c  PREMIUM: PLAN T.I (Todo Incluido)\t%c",186,186);
	printf("\tPRECIO: 8.000 ARS al dia");
	printf("\n\t %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
	printf("--------------------------------------------------");
	printf("\n\t %cPaga:            Solo Alojamiento\t%c",186,186);
	printf("\tCOMIDAS: Desayuno, Almuerzo, Cena");	
	printf("\n\t %cServicio:        Atencion 24/7 \t%c",186,186);
	printf("\tSERVICIO: 8:00hs | 18:00hs | 21:00hs");	
	printf("\n\t %cComidas:         Incluido\t\t%c",186,186);
	printf("\tMANTENIMIENTO: 12:00hs | 00:00hs");		
	printf("\n\t %cMantenimiento:   Atencion 24/7\t%c",186,186);
	printf("\tEXTRAS: ---");	
	printf("\n\t %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
	printf("--------------------------------------------------");
	
	printf("\n\n\t");
	system("pause");	
}



