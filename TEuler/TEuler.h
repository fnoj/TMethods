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

class TEuler{

 private:
  TFormula *function;
  TLegend *flegend;
  Double_t fxo;   //x inicial
  Double_t fxf;   //x final   
  Double_t fyo;   //y inicial
  Double_t fx;
  Double_t fy;
  Int_t fn;    
  Double_t fh;    
  Char_t *ff;
  Double_t *fX,*fY;
  void Init();
  Double_t Eval(Double_t x, Double_t t);

 public:
  TEuler(Char_t *func,Double_t xo, Double_t yo, Double_t xf, Double_t n);
  TEuler(Char_t *func,Double_t xo, Double_t yo, Double_t xf);
  TEuler();
   
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

TEuler::TEuler(Char_t *func,Double_t xo,Double_t yo ,Double_t xf, Double_t n){
  fxo=0; fyo=0; fxf=0; fn=1000; fh=0.1; ff="0";
  TEuler::Calculate();
}

TEuler::TEuler(Char_t *func,Double_t xo,Double_t yo ,Double_t xf, Double_t n){
  fxo=xo; fyo=yo; fxf=xf; fn=n; fh=(fxf-fxo)/fn; ff=func;
  TEuler::Calculate();
}

TEuler::TEuler(Char_t *func,Double_t xo,Double_t yo ,Double_t xf){
  fxo=xo; fyo=yo; fxf=xf; fn=1000; fh=(fxf-fxo)/fn; ff=func;
  TEuler::Calculate();
}

void TEuler::Calculate(){
  fX = new Double_t[fn+2];
  fY = new Double_t[fn+2];
  function = new  TFormula("function",ff); 
  fx=fxo; fy=fyo;
  fX[0]=fx;  
  fY[0]=fy;
  for (Int_t i=0; i<=fn;i++){
    fx=fxo+(i*fh);
    fy=fy+(TEuler::Eval(fx,fy)*fh); 
    fX[i+1]=fx;
    fY[i+1]=fy;    

  }
}

Double_t TEuler::Eval(Double_t x,Double_t y){ 
  return function->Eval(x,y);
}

void TEuler::Draw(){
  graph = new TGraph(fn+1,fX,fY);                              
  graph->SetTitle("Euler's Method");
  graph->Draw("AC");
  flegend = new TLegend(0, 0, 0.2, 0.1,ff, "ndc");
  flegend->Draw("");
}

void TEuler::DrawInv(){
  graph = new TGraph(fn+1,fY,fX);                             
  graph->SetTitle("Euler's Method");
  graph->Draw("AC");
  flegend = new TLegend(0, 0, 0.2, 0.1,ff, "ndc");
  flegend->Draw("");
}

void TEuler::Print(){
  for(int j=0;j<=fn;j++){
    cout << fX[j] <<"\t"<< fY[j]<<endl;
  }
}

void TEuler::PrintFile(Char_t *namefile){
  ofstream outfile (namefile);
  for(int j=0;j<=fn;j++){
    outfile<<fX[j]<<"\t"<<fY[j]<<endl;
  }
}
