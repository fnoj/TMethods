///////////////////////////////////////////////////////////////////////////
//                                                                       //
// NOTICE OF COPYRIGHT                                                   //
//                                                                       //
//        Copyright (C) 2013   John Suárez - Diego Vasquez              //
//                                                                       //
//                                                                       //
// This program is free software; you can redistribute it and/or modify  //
// it under the terms of the GNU General Public License as published by  //
// the Free Software Foundation; either version 2 of the License, or     //
// (at your option) any later version.                                   //
//                                                                       //
// This program is distributed in the hope that it will be useful,       //
// but WITHOUT ANY WARRANTY; without even the implied warranty of        //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         //
// GNU General Public License for more details:                          //
//                                                                       //
//          http://www.gnu.org/copyleft/gpl.html                         //
//                                                                       //
///////////////////////////////////////////////////////////////////////////

#include <TFunction.h>
#include <TLegend.h>

class TRk4{

 private:
  TFormula *function;
  TLegend *flegend;
  Double_t fxo;   //x inicial
  Double_t fxf;  //xfinal   
  Double_t fyo;   //y inicial
  Double_t fx;
  Double_t fy;
  Int_t fn;  //Número de Puntos 
  Double_t fh;  //Paso 
  Char_t *ff;
  Double_t *fX,*fY;
  Double_t k1;
  Double_t k2;
  Double_t k3;
  Double_t k4; 

  Double_t Eval(Double_t x, Double_t t);
  
  
 public:
  TRk4(Char_t *func,Double_t xo, Double_t yo, Double_t xf, Double_t n);
  TRk4(Char_t *func,Double_t xo, Double_t yo, Double_t xf);
  TRk4();
  
  void SetXo(Double_t Xo){fxo=Xo;}
  void SetXf(Double_t Xf){fxf=Xf;}
  void SetYo(Double_t Yo){fyo=Yo;}
  void SetN(Int_t N){fn=N;}
  void SetH(Double_t H){fh=H;}
  void SetFunction(Char_t *f){ff=f;}              
  Double_t GetXo(){return fxo;}
  Double_t GetXf(){return fxf;}
  Double_t GetYo(){return fyo;}
  Int_t GetN(){return fn;}
  Double_t GetH(){return fh;}
  Double_t GetX(){return fX;}
  Double_t GetY(){return fY;}
  Char_t *GetFunction(){return ff;}               

  void Calculate();
  void Draw();
  void DrawInv();
  void Print();
  void PrintFile(Char_t *namefile);

};

TRk4::TRk4(){
  fxo=0; fyo=0; fxf=0; fn=1000; fh=0.1; ff="x";
  TRk4::Calculate();
}

TRk4::TRk4(Char_t *func,Double_t xo,Double_t yo ,Double_t xf, Double_t n){
  fxo=xo; fyo=yo; fxf=xf; fn=n; fh=(fxf-fxo)/fn; ff=func;
  TRk4::Calculate();
}

TRk4::TRk4(Char_t *func,Double_t xo,Double_t yo ,Double_t xf){
  fxo=xo; fyo=yo; fxf=xf; fn=1000; fh=(fxf-fxo)/fn; ff=func;
  TRk4::Calculate();
}

void TRk4::Calculate(){
  fX = new Double_t[fn+2];
  fY = new Double_t[fn+2];
  function = new  TFormula("function",ff);  
  fx=fxo; fy=fyo;
  fX[0]=fx;  
  fY[0]=fy;
  for (Int_t i = 0; i < fn; i++){
    fX[i+1] = fX[i] + fh;
    k1 = TRk4::Eval(fX[i],fY[i]);
    k2 = TRk4::Eval(fX[i] + fh/2,fY[i] + k1/2);
    k3 = TRk4::Eval(fX[i] + fh/2,fY[i] + k2/2);
    k4 = TRk4::Eval(fX[i] + fh,fY[i] + k3);
    fY[i+1] = fY[i] + fh*(k1 + 2*k2 + 2*k3 + k4)/6;
  }
}

Double_t TRk4::Eval(Double_t x,Double_t y){ 
  return function->Eval(x,y);
}

void TRk4::Draw(){
  graph = new TGraph(fn+1,fX,fY);                              
  graph->SetTitle("Rk4's Method");
  graph->Draw("AC");
  flegend = new TLegend(0, 0, 0.2, 0.1,ff, "ndc");
  flegend->Draw("");
}

void TRk4::DrawInv(){
  graph = new TGraph(fn+1,fY,fX);                             
  graph->SetTitle("Rk4's Method");
  graph->Draw("AC");
  flegend = new TLegend(0, 0, 0.2, 0.1,ff, "ndc");
  flegend->Draw("");
}

void TRk4::Print(){
  for(int j=0;j<=fn;j++){
    cout << fX[j] <<"\t"<< fY[j]<<endl;
  }
}

void TRk4::PrintFile(Char_t *namefile){
  ofstream outfile (namefile);
  for(int j=0;j<=fn;j++){
    outfile<<fX[j]<<"\t"<<fY[j]<<endl;
  }
}
