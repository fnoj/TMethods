///////////////////////////////////////////////////////////////////////////
//                                                                       //
// NOTICE OF COPYRIGHT                                                   //
//                                                                       //
//        Copyright (C) 2013   John Suárez - Diego Velasquez             //
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

class TVerlet{

 private:
  TFormula *function;
  TLegend *flegend;
  Double_t fxo;
  Double_t fx1;   //x inicial
  Double_t fxf;
  Double_t fy1;//xfinal   
  Double_t fyo;   //y inicial
  Double_t fyf;  //yfinal
  Double_t fx;
  Double_t fy;
  Int_t fn;  //Número de Puntos 
  Double_t fh;  //Paso 
  Char_t *ff;
  Double_t *fX,*fY;
  void Init();
  Double_t Eval(Double_t x, Double_t t);


 public:
  TVerlet(Char_t *func,Double_t xo, Double_t yo,,Double_t x1,Double_t y1, Double_t xf, Double_t yf, Double_t n);
   
  void SetXo(Double_t Xo){fxo=Xo;}
  void SetXf(Double_t Xf){fxf=Xf;}
  void SetYo(Double_t Yo){fyo=Yo;}
  void SetYf(Double_t Yf){fyf=Yf;}
  void SetX1(Double_t X1){fx1=X1;}
  void SetY1(Double_t Y1){fy1=Y1;}
  void SetN(Int_t N){fn=N;}
  Double_t GetXo(){return fxo;}
  Double_t GetXf(){return fxf;}
  Double_t GetYo(){return fyo;}
  Double_t GetYf(){return fyf;}
  Int_t GetN(){return fn;}
  Double_t GetH(){return fh;}
  Double_t GetX(){return fX;}
  Double_t GetY(){return fY;}

  // void SetFunction(string f){ffunct=f;}                 //Revisar 
  //  string GetFunction(){return ffunct;}                ///Revisar

  void Draw();
  void DrawInv();
  void Print();
  void PrintFile(Char_t *namefile);

};

TVerlet::TVerlet(Char_t *func,Double_t xo,Double_t yo,Double_t x1,Double_t y1 ,Double_t xf, Double_t yf, Double_t n){
  fxo=xo; fyo=yo; fxf=xf; fyf=yf; fn=n; fh=(fxf-fxo)/fn; ff=func; fx1=x1; fy1=y1;
  TVerlet::Init();
}

void TVerlet::Init(){
  fX = new Double_t[fn+2];
  fY = new Double_t[fn+2];
  function = new  TFormula("function",ff);  //funciona bien pero tocaría sin los métodos GetFunction ni SetFunction.
  fx=fxo; fy=fyo;
  fX[0]=fx;//pero = ud no me paso la clase final 
  fY[0]=fy;
  fX[1]=fx1;//pero = ud no me paso la clase final 
  fY[1]=fy1;
  
 for (Int_t i=0; i<=fn;i++){
    fX[i+2]=fxo+(i*fh);
    fY[i+2]=2*fY[i+1]-fY[i]+(TVerlet::Eval(fX[i+1],fy)*fh*fh); 

    // cout <<fX[i]<<"\t"<<fY[i]<<endl;
  }
}



Double_t TVerlet::Eval(Double_t x,Double_t y){ 
  return function->Eval(x,y);
}

void TVerlet::Draw(){
  graph = new TGraph(fn+1,fX,fY);                              
  graph->SetTitle("Verlet's Method");
  graph->Draw("AC");
  flegend = new TLegend(0, 0, 0.2, 0.1,ff, "ndc");
  flegend->Draw("");
}

void TVerlet::DrawInv(){
  graph = new TGraph(fn+1,fY,fX);                             
  graph->SetTitle("Verlet's Method");
  graph->Draw("AC");
  flegend = new TLegend(0, 0, 0.2, 0.1,ff, "ndc");
  flegend->Draw("");
}

void TVerlet::Print(){
  for(int j=0;j<=fn;j++){
    cout << fX[j] <<"\t"<< fY[j]<<endl;
  }
}

void TVerlet::PrintFile(Char_t *namefile){
  ofstream outfile (namefile);
  for(int j=0;j<=fn;j++){
    outfile<<fX[j]<<"\t"<<fY[j]<<endl;
  }
}
