#include "TEuler2.h" 

void res(){
  c1 = new TCanvas("c1","Method's Euler",800,800);
  c1->Range(-20,-20,20,20);

  // e1 = new TEuler2("6*x",0,1,10,0,0,5000);
//   e1->Draw();

  float A=0.1;
  float k=14,m=0.5;
 
  e1 = new TEuler2("2*cos(2*x)",0,0,4*TMath::Pi(),0,0,100000);
  e1->Draw();


  Double_t *fx = e1->GetX();
  Double_t *fy = e1->GetY();

  for(int j=0;j<=e1->GetN();j++){
    cout << fx[j] <<"\t"<< fy[j]<<endl;
  }

}
