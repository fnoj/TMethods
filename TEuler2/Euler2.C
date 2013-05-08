#include "TEuler2.h" 

void Euler2(){
  c1 = new TCanvas("c1","Euler2's Method",800,800);
  c1->Range(-20,-20,20,20);

  e1 = new TEuler2("6*x",-10,-1000,10,300,10);
  e1->Draw();
    e1->Print();
  //e1->PrintFile("euler2.dat");
}
