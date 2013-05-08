#include "TEuler.h" 

void Euler(){
  c1 = new TCanvas("c1","Method's Euler",800,800);
  c1->Range(-20,-20,20,20);
  float A=0.1;
  float k=14,m=0.5;
 
  e1 = new TEuler("-(14/0.5)*x",0,0.1,4,4,1000);
  e1->Draw();

  Double_t *fx = e1->GetX();
  Double_t *fy = e1->GetY();

  //  cout << e1->GetN()<<endl;

  for(int j=0;j<=e1->GetN();j++){
    cout << fx[j] <<"\t"<< fy[j]<<endl;
  }

}
