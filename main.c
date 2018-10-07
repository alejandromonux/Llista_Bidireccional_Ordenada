/***********************************************
*
* @Proposit: Mostrar el correcte funcionament de la llista bidireccional ordenada
* @Autor/s: Alejandro Moñux Bernal
* @Data creacio: 5 de octubre de 2018
* @Data ultima modificacio: 06/10/2018
*
************************************************/

 #include "llista.h"

 void main() {
   LlistaBIORD l;
   Rank pj;

   //Es crea la llista
   printf("\nCreant el registre...\n");
   l = LLISTABIORD_crea();

   //Es fa tres vegades el mateix procediment; es cambien els elements de la variable
  //a inserir i s'insereix a la llista per a tenir més d'un element
   strcpy(pj.nom_j, "Kaz Brekker\0");
   pj.puntuacio = 145;
   LLISTABIORD_insereixOrdenat(&l, pj);
   printf("\nEntrat Kaz Brekker, amb 145 punts");

   strcpy(pj.nom_j, "Joseph Joestar\0");
   pj.puntuacio = 15;
   LLISTABIORD_insereixOrdenat(&l, pj);
   printf("\nEntrat Joseph Joestar, amb 15 punts");

   strcpy(pj.nom_j, "Peter Parker\0");
   pj.puntuacio = 540;
   LLISTABIORD_insereixOrdenat(&l, pj);
   printf("\nEntrat Peter Parker, amb 540 punts");

   strcpy(pj.nom_j, "Nicasia\0");
   pj.puntuacio = 230;
   LLISTABIORD_insereixOrdenat(&l, pj);
   printf("\nEntrat Nicasia, amb 230 punts\n");

   //Es torna al inici de la llista per començar desde el principi
   printf ("\nMostrant els jugadors de més petit a més gran\n");
   LLISTABIORD_vesInici(&l);

   //Fins que no acabi la llista, es va consultant l'element al que apunta el PDI
   //I es mostra per pantalla
   while (!LLISTABIORD_fi(l)) {
     pj=LLISTABIORD_consulta(l);
     printf("%s : %d\n", pj.nom_j, pj.puntuacio);
     LLISTABIORD_avanca(&l);
   }

   //Es borra el tercer element per demostrar el funcionament de LLISTABIORD_esborra
   printf("\nBorrant a Nicasia per infraccio de la normativa\n");
   LLISTABIORD_vesInici(&l);
   LLISTABIORD_avanca(&l);
   LLISTABIORD_avanca(&l);
   LLISTABIORD_esborra(&l);

   //Es va al final i, fins que no s'arribi al principi, es va anant cap a enrera
   //mostrant els elements que queden a la llista
   printf("\nMostrant els jugadors de més gran a més petit\n");
   LLISTABIORD_vesfi(&l);
   pj=LLISTABIORD_consulta(l);
   printf("%s : %d\n", pj.nom_j, pj.puntuacio);
   while (!LLISTABIORD_principi(&l)) {
     LLISTABIORD_enrera(&l);
     pj=LLISTABIORD_consulta(l);
     printf("%s : %d\n", pj.nom_j, pj.puntuacio);
   }

   //Per últim, es destrueix la llista, alliberant memòria.
   printf("\nReiniciant registre...\n");
   LLISTABIORD_destrueix(&l);
 }
