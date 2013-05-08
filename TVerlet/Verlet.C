#include "TVerlet.h" 

void Verlet(){
  c1 = new TCanvas("c1","Verlet's Method",800,800);
  c1->Range(-20,-20,20,20);
  
  e1 = new TVerlet("2*cos(2*x)",-0.001256,-0.0000000022,0,0,4*TMath::Pi(),4,1000);
  e1->Draw();
}
