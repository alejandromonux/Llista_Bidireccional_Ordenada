/***********************************************
*
* @Proposit: Crear el codi de la llista bidireccional ordenada
* @Autor/s: Alejandro Moñux Bernal
* @Data creacio: 1 de octubre de 2018
* @Data ultima modificacio: 06/10/2018
*
************************************************/

#include "llista.h"


/***********************************************
*
*@Finalitat:Crea un element per a fer de fantasma
*@Parametres: ----.
*@Retorn: Un cursor buit.
*
************************************************/
Rank ELEMENT_indefinitORD(){
	Rank r;

	r.nom_j[0] = '\0';
	r.puntuacio = 0;
	return (r);
}

/***********************************************
*
*@Finalitat: Crear una llista bidireccional amb pdi buida amb fantasma.
*@Parametres:	----.
*@Retorn: La llista amb un Punt de interés creada al procediment.
*
************************************************/
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
		//Tant següent com anterior es declaren com a nuls
		(*(l).pri).seg = NULL;
    (*(l).pri).ante = NULL;
		l.ant = l.pri;
	}
	return(l);//Es retorna la llista amb el fantasma.
}

/***********************************************
*
*@Finalitat: Posar un element a la llista bidireccional, a la posició on apunta  el Punt de Interés.
*@Parametres:	l: La llista on es deu inserir el element
* 				e: El element a inserir dins la llista
*@Retorn: ---.
*
************************************************/
void LLISTABIORD_insereixOrdenat(LlistaBIORD *l, Rank e){
	NodeORD *aux, *tmp;

	//Es reserva un espai de memoria per a inserir l'element a la llista
	aux= (NodeORD *)malloc(sizeof(NodeORD));
	//Si hi ha un error amb el malloc, es mostra un error i es salta el procediment
	if(aux == NULL){
		printf("Error en reservar memòria");
	}else{
		//Si no, se li assigna al espai del jugador el element passat
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
		//En cas de no estar al final, es col·loca l'anterior del següent a ell
    if(!LLISTABIORD_fi(*l)){
      (*(*(*l).ant).seg).ante = aux;
    }
    (*(*l).ant).seg = aux;

		//Si es troba al final, se li assigna ult
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
/***********************************************
*
*@Finalitat: Posar el PDI de la llista bidireccional al inici
*@Parametres:	l: La llista en que el PDI es deu retornar al inici
*@Retorn: ---.
*
************************************************/
void LLISTABIORD_vesInici(LlistaBIORD *l){
	(*l).ant=(*l).pri;
}

/***********************************************
*
*@Finalitat: Posar el PDI de la llista bidireccional al final
*@Parametres:	l: La llista en que el PDI es deu col·locar al final
*@Retorn: ---.
*
************************************************/
void LLISTABIORD_vesfi(LlistaBIORD *l){
  (*l).ant = (*l).ult;
}
/***********************************************
*
*@Finalitat: avançar el PDI de la llista bidireccional una posicio
*@Parametres:	l: La llista en que el PDI es deu avançar
*@Retorn: ---.
*
************************************************/
void LLISTABIORD_avanca(LlistaBIORD *l){
	//Si no es troba al fi de la llista, es passa el PDI al element següent.
	if ((*(*l).ant).seg==NULL){
		printf("Error en avançar\n");
	}else{
		(*l).ant=(*(*l).ant).seg;
	}
}

/***********************************************
*
*@Finalitat: moure el PDI de la llista bidireccional una posició cap a enrere
*@Parametres:	l: La llista en que el PDI es deu moure cap a enrera
*@Retorn: ---.
*
************************************************/
void LLISTABIORD_enrera(LlistaBIORD *l){
  if ((*(*l).ant).ante!=NULL){
    (*l).ant = (*(*l).ant).ante;
  }else{
    printf("Error en anar enrera");
  }
}

/***********************************************
*
*@Finalitat: Consultar el element de la llista a la qual apunta el PDI
*@Parametres:	l: La llista en que es vol consultar l'element
*@Retorn: L'element a consultar, que es guardarà en una variable.
*
************************************************/
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


/***********************************************
*
*@Finalitat: Esborrar el node de la llista al que apunta el PDI
*@Parametres:	l: La llista en que es vol esborrar
*@Retorn: ---.
*
************************************************/
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

/***********************************************
*
*@Finalitat: Comprovar si ens trobem o no al final de llista
*@Parametres:	l: La llista en que volem mirar si ens trobem al final
*@Retorn: Retorna un 1 si ens trobem al final i un 0 si no.
*
************************************************/
int LLISTABIORD_fi(LlistaBIORD l){
	return((*(l).ant).seg==NULL);
}

/***********************************************
*
*@Finalitat: Comprovar si la llista es o no es buida.
*@Parametres:	l: La llista en que volem mirar si  és buida
*@Retorn: Retorna un 1 si está buida i un 0 si no
*
************************************************/
int LLISTABIORD_buida(LlistaBIORD l){
	return((*(l).pri).seg==NULL);
}

/***********************************************
*
*@Finalitat: Comprovar si estem al principi de la llista
*@Parametres:	l: La llista en que volem mirar si estem al principi o si no
*@Retorn: Retorna un 1 si ens trobem al principi, un 0 si no
*
************************************************/
int LLISTABIORD_principi(LlistaBIORD *l){
  return((*(*l).ant).ante==NULL);
}

/***********************************************
*
*@Finalitat: Destruir la llista i alliberar memoria d'aquesta manera
*@Parametres:	l: la llista a destruir
*@Retorn: ----.
*
************************************************/
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
