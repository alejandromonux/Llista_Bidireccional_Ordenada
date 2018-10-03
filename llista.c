
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

  aux=(Node *)mallox(sizeof(Node));
  *aux= ElementIndefinit();

  l.pri = aux;
  l.ant = aux;
  l.ult = aux;
}

void LLISTABIORD_inserirOrdenat(LlistaBiOrd *l, Jugador p){

}

void LLISTABIORD_vesInici(LlistaBiOrd *l){
  l.ant = l.pri;
}

void LLISTABIORD_avanca(LlistaBiOrd *l){
    l.ant = (*(*(l).ant).seg).seg;
}

void LLISTABIORD_enrera(LlistaBiOrd *l){

}

Jugador LLISTABIORD_consulta(LlistaBiOrd *l){

}

void LLISTABIORD_esborra(LlistaBiOrd *l){

}

void LLISTABIORD_fi(LlistaBiOrd *l){}

}

void LLISTABIORD_buida(LlistaBiOrd *l){

}

void LLISTABIORD_destrueix(LlistaBiOrd *l){

}
