/***********************************************
*
* @Proposit: Proveir la llibreria per a la llista bidireccional ordenada
* @Autor/s: Alejandro Moñux Bernal
* @Data creacio: 1 de octubre de 2018
* @Data ultima modificacio: 06/10/2018
*
************************************************/

#ifndef _LLISTA_ORD_H_
#define _LLISTA_ORD_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_NOMS 30

//Tipus que serveix per crear i modificar el ranking de jugadors ordenat
typedef struct{
	char nom_j[MAX_NOMS]; //Nom del jugador
	int puntuacio;				//Puntuació conseguida
}Rank;


typedef struct M {
	Rank jugador;		//Variable jugador de ripus Rank, guarda les dades del jugador
	struct M *seg;	//Punter que apunta al següent node
  struct M *ante;	//Punter que apunt al node anterior
}NodeORD;

typedef struct{
	NodeORD *pri;	//Punter que apunt al primer node
	NodeORD *ant;	//Punter que va movent-se, es el punt de interés
  NodeORD *ult;	//Punter que apunt al últim node.
}LlistaBIORD;

/***********************************************
*
*@Finalitat:Crea un element per a fer de fantasma
*@Parametres: ----.
*@Retorn: Un cursor buit.
*
************************************************/
Rank ELEMENT_indefinitORD();

/***********************************************
*
*@Finalitat: Crear una llista bidireccional amb pdi buida amb fantasma.
*@Parametres:	----.
*@Retorn: La llista amb un Punt de interés creada al procediment.
*
************************************************/
LlistaBIORD LLISTABIORD_crea();

/***********************************************
*
*@Finalitat: Posar un element a la llista bidireccional, a la posició on apunta  el Punt de Interés.
*@Parametres:	l: La llista on es deu inserir el element
* 				e: El element a inserir dins la llista
*@Retorn: ---.
*
************************************************/
void LLISTABIORD_insereixOrdenat(LlistaBIORD *l, Rank e);

/***********************************************
*
*@Finalitat: Posar el PDI de la llista bidireccional al final
*@Parametres:	l: La llista en que el PDI es deu col·locar al final
*@Retorn: ---.
*
************************************************/
void LLISTABIORD_vesInici(LlistaBIORD *l);

/***********************************************
*
*@Finalitat: Posar el PDI de la llista bidireccional al final
*@Parametres:	l: La llista en que el PDI es deu col·locar al final
*@Retorn: ---.
*
************************************************/
void LLISTABIORD_vesfi(LlistaBIORD *l);

/***********************************************
*
*@Finalitat: avançar el PDI de la llista bidireccional una posicio
*@Parametres:	l: La llista en que el PDI es deu avançar
*@Retorn: ---.
*
************************************************/
void LLISTABIORD_avanca(LlistaBIORD *l);

/***********************************************
*
*@Finalitat: moure el PDI de la llista bidireccional una posició cap a enrere
*@Parametres:	l: La llista en que el PDI es deu moure cap a enrera
*@Retorn: ---.
*
************************************************/
void LLISTABIORD_enrera(LlistaBIORD *l);

/***********************************************
*
*@Finalitat: Consultar el element de la llista a la qual apunta el PDI
*@Parametres:	l: La llista en que es vol consultar l'element
*@Retorn: L'element a consultar, que es guardarà en una variable.
*
************************************************/
Rank LLISTABIORD_consulta(LlistaBIORD l);

/***********************************************
*
*@Finalitat: Esborrar el node de la llista al que apunta el PDI
*@Parametres:	l: La llista en que es vol esborrar
*@Retorn: ---.
*
************************************************/
void LLISTABIORD_esborra(LlistaBIORD *l);

/***********************************************
*
*@Finalitat: Comprovar si ens trobem o no al final de llista
*@Parametres:	l: La llista en que volem mirar si ens trobem al final
*@Retorn: Retorna un 1 si ens trobem al final i un 0 si no.
*
************************************************/
int LLISTABIORD_fi(LlistaBIORD l);

/***********************************************
*
*@Finalitat: Comprovar si estem al principi de la llista
*@Parametres:	l: La llista en que volem mirar si estem al principi o si no
*@Retorn: Retorna un 1 si ens trobem al principi, un 0 si no
*
************************************************/
int LLISTABIORD_principi(LlistaBIORD *l);

/***********************************************
*
*@Finalitat: Comprovar si la llista es o no es buida.
*@Parametres:	l: La llista en que volem mirar si  és buida
*@Retorn: Retorna un 1 si está buida i un 0 si no
*
************************************************/
int LLISTABIORD_buida(LlistaBIORD l);

/***********************************************
*
*@Finalitat: Destruir la llista i alliberar memoria d'aquesta manera
*@Parametres:	l: la llista a destruir
*@Retorn: ----.
*
************************************************/
void LLISTABIORD_destrueix(LlistaBIORD *l);

#endif
