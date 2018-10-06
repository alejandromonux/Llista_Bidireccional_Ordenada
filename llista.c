

#include "llista.h"


Rank ELEMENT_indefinitORD(){
	Rank r;

	r.nom_j[0] = '\0';
	r.puntuacio = 0;
	return (r);
}

LlistaBIORD LLISTABIORD_crea(){
	LlistaBIORD l;
	NodeORD *aux;

	//Es demana un espai de memoria per al node que farà de fantasma
	aux=(NodeORD *)malloc(sizeof(NodeORD));
	if (aux == NULL){
		printf("Error en reservar memòria");
	}else{
		//En cas que hi hagi hagut èxit, s'assigna a la posició un element indefinit i es coloca el fantasma al principi
		(*aux).jugador = ELEMENT_indefinitORD();
		l.pri = aux;
		(*(l).pri).seg = NULL;
    (*(l).pri).ante = NULL;
		l.ant = l.pri;
	}
	return(l);//Es retorna la llista amb el fantasma.
}

void LLISTABIORD_insereixOrdenat(LlistaBIORD *l, Rank e){
	NodeORD *aux, *tmp;

	//Es reserva un espai de memoria per a inserir l'element a la llista
	aux= (NodeORD *)malloc(sizeof(NodeORD));
	//Si hi ha un error amb el mallos, es mostra l'error i es salta la resta del procediment
	if(aux == NULL){
		printf("Error en reservar memòria");
	}else{
		//Si no, se li assigna al espai del jugador el element passat per paràmetre
		(*aux).jugador = e;
		//Es col·loca el PDI d'aquell moment en una variable auxiliar per a mantenir la posició al final
		tmp = (*l).ant;

		//Es va al inici i es comença una comprovació amb un bucle, de manera que s'avanca fins que s'arriva al final o
		//la puntuació es més gran que la de l'element a inserir
		LLISTABIORD_vesInici(l);
		while (((*(*l).ant).seg != NULL) && ((*(*(*l).ant).seg).jugador.puntuacio < e.puntuacio)){
			LLISTABIORD_avanca(l);
		}

		//Una vegada arribat al punt pertinent, es col·loca aux en la posició
		(*aux).seg = (*(*l).ant).seg;
    (*aux).ante = (*l).ant;
    if(!LLISTABIORD_fi(*l)){
      (*(*(*l).ant).seg).ante = aux;
    }
    (*(*l).ant).seg = aux;

    if (((*(*(*l).ant).seg).seg) == NULL){
      (*l).ult = (*l).ant;
    }

		//El PDI es col·loca en la posició que tenía a l'inici
		(*l).ant = tmp;

		if ((*(*l).ant).seg == aux){
			(*l).ant = aux;
		}

	}
}

void LLISTABIORD_vesInici(LlistaBIORD *l){
	(*l).ant=(*l).pri;
}

void LLISTABIORD_vesfi(LlistaBIORD *l){
  (*l).ant = (*l).ult;
}

void LLISTABIORD_avanca(LlistaBIORD *l){
	//Si no es troba al fi de la llista, es passa el PDI al element següent.
	if ((*(*l).ant).seg==NULL){
		printf("Error en avançar\n");
	}else{
		(*l).ant=(*(*l).ant).seg;
	}
}

void LLISTABIORD_enrera(LlistaBIORD *l){
  if ((*(*l).ant).ante!=NULL){
    (*l).ant = (*(*l).ant).ante;
  }else{
    printf("Error en anar enrera");
  }
}

Rank LLISTABIORD_consulta(LlistaBIORD l) {
	Rank e = ELEMENT_indefinitORD();

	//Es comprova que la llista estigui buida o no, i en cas que no, es copia l'element que apunta el PDI en una variable auxiliar
	if ((*(l).ant).seg != NULL){
		e = (*(*(l).ant).seg).jugador;
	}else{
		printf("Error, llista buida o PDI fora de rang");
	}
	return (e); //Es retorna l'element
}


void LLISTABIORD_esborra(LlistaBIORD *l){
	NodeORD *aux;

	//Abans de  res esc comprovem que la llista no sigui buida
	if ((*(*l).pri).seg==NULL){
		printf ("Error, llista buida");
	}else{
		//Si no ho es, s'assigna a aux el element al que apunta el PDI
		aux = (*(*l).ant).seg;
		//Es col·loca el PDI al següent al que apunta aux, es a dir, on pertocaria
		(*(*l).ant).seg = (*aux).seg;
    (*(*aux).seg).ante = (*l).ant;
		//Es llibera l'espai de memoria a que apunta aux
		free(aux);
	}
}

int LLISTABIORD_fi(LlistaBIORD l){
	return((*(l).ant).seg==NULL);
}

int LLISTABIORD_buida(LlistaBIORD l){
	return((*(l).pri).seg==NULL);
}

int LLISTABIORD_principi(LlistaBIORD *l){
  return((*(*l).ant).ante==NULL);
}

void LLISTABIORD_destrueix(LlistaBIORD *l){
	NodeORD *aux;

	//Fins que el primer element sigui nul, s'asigna a aux el primer element, es passa el primer al següent del primer i es llibera el primer de tots.
	while ((*l).pri != NULL){
		aux = (*l).pri;
		(*l).pri = (*(*l).pri).seg;
		free(aux);
	}
	(*l).ant = NULL;
  (*l).pri = NULL;
}
