#include <iostream>
#include "sculptor.h"

int main()
{
   Sculptor teste(61, 61, 61);

   teste.setColor(255, 255, 255, 1);
   teste.putBox(0, 15, 0, 15, 0 ,15);
   teste.putSphere(32, 32, 32, 6);
   teste.putEllipsoid(52, 32, 32, 6, 7, 9);

   teste.writeOFF("C:/Users/elvan/OneDrive/Área de Trabalho/ProjetoEsculto/teste.off");



   Sculptor hollow(61, 101, 61);

   hollow.setColor(255, 255, 255, 1);
   hollow.putEllipsoid(30, 30, 30, 24, 26, 20);
   hollow.setColor(0, 0, 1, 1);
   hollow.putEllipsoid(30, 30, 30, 23, 25, 19);
   hollow.cutBox(0,60,46,59,0,59);

   //olhos
   hollow.cutEllipsoid(21, 27, 43, 8, 9, 8);//direito
   hollow.cutEllipsoid(39, 27, 43, 8, 9, 8);//esquerdo

   //chifres
   hollow.setColor(255, 255, 255, 1);
   hollow.putEllipsoid(15, 62, 30, 13, 25, 3);
   hollow.cutEllipsoid(20, 62, 30, 13, 22, 3);
   hollow.setColor(255, 255, 255, 1);
   hollow.putEllipsoid(45, 62, 30, 13, 25, 3);
   hollow.cutEllipsoid(40, 62, 30, 13, 22, 3);


   //complemento cabeça
   hollow.putEllipsoid(30, 46, 30, 19, 4, 16);
   hollow.cutBox(0,60,0,11,0,59);
   hollow.putEllipsoid(30, 11, 30, 17, 4, 14);

   hollow.writeOFF("C:/Users/elvan/OneDrive/Área de Trabalho/ProjetoEsculto/hollowKnight.off");

   return 0;
}
