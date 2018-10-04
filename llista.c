
#include "llista.h"

Node ElementIndefinit(){
  Node aux;
  int i;

  for (i=0;i<MAX_NOM;i++){
    aux.pj.nom[i]='\0'
  }

  aux.pj.punts = 0;
  aux.seg = NULL;
  return ( aux );
}

LlistaBiOrd LLISTABIORD_crea(){
  LlistaBiOrd l;
  Node *aux;

  aux = (NodeORD *)malloc(sizeof(NodeORD));
  if (aux == NULL) {
    printf("Error en reservar memoria al crear la llista")
  } else {
    *aux = ElementIndefinit();
    l.pri = aux;
    l.ant = aux;
    l.ult = aux;
  }
}

void LLISTABIORD_inserirOrdenat(LlistaBiOrd *l, Jugador p){
  NodeORD *aux, *tmp;

	//Es reserva un espai de memoria per a inserir l'element a la llista
	aux = (NodeORD *)malloc(sizeof(NodeORD));
	//Si hi ha un error amb el mallos, es mostra l'error i es salta la resta del procediment
	if(aux == NULL){
		printf("Error en reservar memòria");
	}else{
		//Si no, se li assigna al espai del jugador el element passat per paràmetre
		(*aux).pj = p;
		//Es col·loca el PDI d'aquell moment en una variable auxiliar per a mantenir la posició al final
		tmp = (*l).ant;

		//Es va al inici i es comença una comprovació amb un bucle, de manera que s'avanca fins que s'arriva al final o
		//la puntuació es més gran que la de l'element a inserir
		LLISTA_BIORD_vesInici(l);
		while (((*(*l).ant).seg != NULL) && ((*(*(*l).ant).seg).pj.punts < e.punts)){
			LLISTA_BIORD_avanca(l);
		}

		//Una vegada arribat al punt pertinent, es col·loca aux en la posició
		(*aux).seg = (*(*l).ant).seg;
		(*(*l).ant).seg = aux;
		//El PDI es col·loca en la posició que tenía a l'inici
		(*l).ant = tmp;

		if ((*(*l).ant).seg == aux){
			(*l).ant = aux;
		}
  }
}

void LLISTABIORD_vesInici(LlistaBiOrd *l){
  (*l).ant = (*l).pri;
}

void LLISTABIORD_vesfi(LlistaBiOrd *l){
  (*l).ant = (*l).ult;
}


void LLISTABIORD_avanca(LlistaBiOrd *l){
    (*l).ant = (*(*(*l).ant).seg).seg;
}

void LLISTABIORD_enrera(LlistaBiOrd *l){
  (*l).ant = (*(*l).ant).ant;
}

Jugador LLISTABIORD_consulta(LlistaBiOrd *l){
  Jugador e = ElementIndefinit();

  //Es comprova si la posició apuntada es nul·la o no
  if ((*(l).ant).seg != NULL){
      //Si no, es copia la informació a la variable a retornar
  		e = (*(*(l).ant).seg).jugador;
  	}else{
      //Si ho es, es retorna un error
  		printf("Error, llista buida o PDI fora de rang");
  	}
  	return (e);
}

void LLISTABIORD_esborra(LlistaBiOrd *l){
  NodeORD *aux;

  if ((*(*l).ant).seg == NULL){
    printf("Error al borrar, llista buida o PDI fora de rang");
  }else{
    //apuntem aux a la posició a la que apunta el punt de interés
    aux = (*(*l).ant).seg;
    //Treiem aux de la llista, cambiant l'enllaç de següent al següent element
    (*(*l).ant).seg = (*aux).seg
    //Alliberem la posició de memoria a la que apunta aux
    free(aux);
  }
}

void LLISTABIORD_fi(LlistaBiOrd *l){

}

void LLISTABIORD_buida(LlistaBiOrd *l){

}

void LLISTABIORD_destrueix(LlistaBiOrd *l){

}
