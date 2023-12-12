#include <stdio.h>
#include <stdlib.h>

#define ELEMS 3
//trabajamos con estructura
typedef struct clientes{
char nombre[50];
char dir[50];
char cd[20];
char fechaNac[11];
char fechaAdd[11];
int id;
}CLIENTES;

int main(){
CLIENTES cli[ELEMS];//con esto trabajaremos arrays de estructuras
int menu=0, opci=0, pos=0, key, count;
do{
printf("Welcome to Mictlán\n");
printf("Que deseas hacer?\n");
printf("1-Add\n2-Search\n3-Edit\n4-Delete\n5-Display\n6-Exit\n");
scanf("%i",&menu);
printf("Escogiste: %i \n",menu);
if(menu==1){
printf("\nIngresa nombre: ");
scanf("%49s",cli[pos].nombre);
printf("\nIngresa la Direccion: ");
scanf("%49s",cli[pos].dir);
printf("\nIngresa la Ciudad donde vive: ");
scanf("%19s",cli[pos].cd);
printf("\nIngresa su fecha de nac. (dd/mm/aaaa): ");
scanf("%10s",cli[pos].fechaNac);
printf("\nIngresa la fecha de registro: ");
scanf("%10s",cli[pos].fechaAdd);
cli[pos].id=pos;
printf("\nSu id es: %d\n",pos);
pos=pos+1;
}//end if Add
else if(menu==2){
printf("\nIngresa Id(clave) a buscar: ");
scanf("%d",&key);
bool ban;
for(count=0;count<pos;count++){
if(key==cli[count].id){
printf("\nNombre: %s",cli[key].nombre);
printf("\nDireccion: %s",cli[key].dir);
printf("\nCiudad: %s",cli[key].cd);
printf("\nFecha Nacimiento: %s",cli[key].fechaNac);
printf("\nFecha de Ingreso: %s",cli[key].fechaAdd);
printf("\nId: %d\n",cli[key].id);
ban=true;
break;
}
}
if(ban==false)printf("\nError: El cliente que busca no existe.\n");
}//end if search
else if(menu==3){
printf("\nIngresa Id(clave) a buscar: ");
scanf("%d",&key);
bool ban;
for(count=0;count<pos;count++){
if(key==cli[count].id){
printf("Modificaras al siguiente usuario: ");
printf("\nNombre: %s",cli[key].nombre);
printf("\nIngresa nombre nuevo: ");
scanf("%49s",cli[key].nombre);
printf("\nDireccion: %s",cli[key].dir);
printf("\nIngresa la Direccion nueva: ");
scanf("%49s",cli[key].dir);
printf("\nCiudad: %s",cli[key].cd);
printf("\nIngresa la Ciudad nueva: ");
scanf("%19s",cli[key].cd);
printf("\nFecha Nacimiento: %s",cli[key].fechaNac);
printf("\nIngresa su fecha de nac. (dd/mm/aaaa) Nueva: ");
scanf("%10s",cli[key].fechaNac);
printf("\nFecha de Ingreso: %s",cli[key].fechaAdd);
printf("\nIngresa la fecha de registro nueva: ");
scanf("%10s",cli[key].fechaAdd);
cli[key].id=key;
printf("\nSu id es: %d\n",key);
ban=true;
break;
}
}
if(ban==false)printf("\nError: El cliente que busca no existe.\n");
}//end if edit
else if(menu==4){
printf("\nIngresa Id(clave) a buscar para matarlo al mendigo ");
scanf("%d",&key);
bool ban;
for(count=0;count<pos;count++){
if(key==cli[count].id){
int count2;
for(count2=count+1;count2<pos;count2++){
//sobreescribimos el registro siguiente para eliminar los registros
cli[count2-1]=cli[count2];
//así mismo sobreescribimos el id que disminuye en 1
cli[count2-1].id=cli[count2-1].id-1;
}//end for
//eliminamos una posicion
pos=pos-1;
ban=true;
printf("\nSe elimino al registro con exito\n");
break;
}//end if
}//end for
if(ban==false)printf("\nError: El cliente que busca no existe.\n");
}//end if delete
else if(menu==5){
printf("\nId\tNombre\tDireccion\tCiudad\tFechaNac\tFechaAdd");
for(count=0;count<pos;count++){
printf("\n %d",cli[count].id);
printf("\t%s",cli[count].nombre);
printf("\t%s",cli[count].dir);
printf("\t%s",cli[count].cd);
printf("\t%s",cli[count].fechaNac);
printf("\t%s\n",cli[count].fechaAdd);
}//end for
}//end if display
}while(menu<6);
return 0;
}

