 #include "llista.h"

 void main() {
   LlistaBIORD l;
   Rank pj;

   printf("\nCreant el registre...\n");
   l = LLISTABIORD_crea();


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

   printf ("\nMostrant els jugadors de més petit a més gran\n");
   LLISTABIORD_vesInici(&l);

   while (!LLISTABIORD_fi(l)) {
     pj=LLISTABIORD_consulta(l);
     printf("%s : %d\n", pj.nom_j, pj.puntuacio);
     LLISTABIORD_avanca(&l);
   }

   printf("\nBorrant a Nicasia per infraccio de la normativa\n");
   LLISTABIORD_vesInici(&l);
   LLISTABIORD_avanca(&l);
   LLISTABIORD_avanca(&l);
   LLISTABIORD_esborra(&l);

   printf("Mostrant els jugadors de més gran a més petit\n");
   LLISTABIORD_vesfi(&l);
   while (!LLISTABIORD_principi(&l)) {
     pj=LLISTABIORD_consulta(l);
     printf("%s : %d\n", pj.nom_j, pj.puntuacio);
     LLISTABIORD_enrera(&l);
   }

   printf("\nReiniciant registre...\n");
   LLISTABIORD_destrueix(&l);
 }
