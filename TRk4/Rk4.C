#include "TRk4.h" 

void Rk4(){
  c1 = new TCanvas("c1","Rk4 Method's",800,800);
  c1->Range(-20,-20,20,20);
  c1->SetGrid();

  e1 = new TRk4("-x/sqrt(16-x*x)",-4,4,4,4,100);
  e1->Draw();

  Double_t *fx = e1->GetX();
  Double_t *fy = e1->GetY();

  //  cout << e1->GetN()<<endl;

  for(int j=0;j<=e1->GetN();j++){
    cout << fx[j] <<"\t"<< fy[j]<<endl;
  }

  gPad->Update();
}
