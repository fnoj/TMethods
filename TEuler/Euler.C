#include "TEuler.h" 

void Euler(){
  c1 = new TCanvas("c1","Euler's Method",800,800);
  c1->Range(-20,-20,20,20);
  c1->SetGrid();

  e1 = new TEuler("-x/sqrt(16-x*x)",-4,4,4,4,100);
  e1->Draw();

  Double_t *fx = e1->GetX();
  Double_t *fy = e1->GetY();

  //  e1->Print();
  //  e1->PrintFile("dat.dat");

  gPad->Update();
}
