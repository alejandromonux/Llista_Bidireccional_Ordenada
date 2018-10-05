 #include "llista.h"

 void main() {
   LlistaBiOrd l;
   Jugador pj;

   printf("\nCreant el registre...\n")
   l = LLISTABIORD_crea();

   printf("\nEntrant jugadors al registre")
   pj.nom = "Kaz Brekker\0";
   pj.punts = 145;
   LLISTABIORD_inserirOrdenat(&l, pj);
   printf("Entrat Kaz Brekker, amb 145 punts");

   pj.nom = "Joseph Joestar\0";
   pj.punts = 15;
   LLISTABIORD_inserirOrdenat(&l, pj);
   printf("\nEntrat Joseph Joestar, amb 15 punts");

   pj.nom = "Peter Parker\0";
   pj.punts = 540;
   LLISTABIORD_inserirOrdenat(&l, pj);
   printf("\nEntrat Peter Parker, amb 540 punts");

   pj.nom = "Nicasia\0";
   pj.punts = 230;
   LLISTABIORD_inserirOrdenat(&l, pj);
   printf("\nEntrat Nicasia, amb 230 punts");

   printf ("\nMostrant els jugadors de més petit a més gran\n");
   LLISTABIORD_vesInici(&l);

   while (!LLISTABIORD_fi(l)) {
     pj=LLISTABIORD_consulta(l);
     LLISTABIORD_avanca(&l);
   }

   printf("Borrant a Nicasia per infraccio de la normativa\n");
   LLISTABIORD_esborra(&l);

   printf("Mostrant els jugadors de més gran a més petit\n");
   LLISTABIORD_vesfi(&l);
   while (!LLISTABIORD_inici(l)) {
     pj=LLISTABIORD_consulta(l);
     LLISTABIORD_enrera(&l);
   }

   printf("Reiniciant registre...");
   LLISTABIORD_destrueix(&l);
   printf("Comprovant que el registre s'hagi reiniciat correctament...\n");
   if(LLISTABIORD_buida(l)){
     printf("Registre reiniciat correctament. Tancant programa\n");
   } else {
     printf("Error en reiniciar el registre\n");
   }
 }
