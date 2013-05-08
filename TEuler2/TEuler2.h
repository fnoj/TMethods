#include <TFunction.h>
#include <TLegend.h>

class TEuler2{

 private:
  TFormula *function;
  TLegend *flegend;
  Double_t fxo;   //x inicial
  Double_t fxf;  //xfinal   
  Double_t fyo;   //y inicial
  Double_t fyf;  //yfinal
  Double_t fuo;  //y prima inicial
  Double_t fx;
  Double_t fy;
  Double_t fu;
  Int_t fn;  //Número de Puntos 
  Double_t fh;  //Paso 
  Char_t *ff;
  Double_t *fX,*fY, *fU;
  void Init();
  Double_t Eval(Double_t x, Double_t t);


 public:
  TEuler2(Char_t *func,Double_t xo, Double_t xf, Double_t u, Double_t n);
   
  void SetXo(Double_t Xo){fxo=Xo;}
  void SetXf(Double_t Xf){fxf=Xf;}
  void SetYo(Double_t Yo){fyo=Yo;}
  void SetYf(Double_t Yf){fyf=Yf;}
  void SetU(Double_t U){fuo=U;}
  void SetN(Int_t N){fn=N;}
  void SetFunction(Char_t *f){ff=f;}                 //Revisar 
  Double_t GetXo(){return fxo;}
  Double_t GetXf(){return fxf;}
  Double_t GetYo(){return fyo;}
  Double_t GetYf(){return fyf;}
  Double_t GetU(){return fuo;}
  Int_t GetN(){return fn;}
  Double_t GetH(){return fh;}
  Double_t GetX(){return fX;}
  Double_t GetY(){return fY;}
  Double_t GetU(){return fU;}
  Char_t *GetFunction(){return ff;}                ///Revisar

  void Draw();
  void DrawInv();
  void Print();
  void PrintFile(Char_t *namefile);

};

TEuler2::TEuler2(Char_t *func,Double_t xo, Double_t xf,Double_t u, Double_t n){
  fxo=xo; fxf=xf; fn=n; fh=(fxf-fxo)/fn; ff=func; fu=u;
  TEuler2::Init();
}

void TEuler2::Init(){
  fX = new Double_t[fn+3];
  fY = new Double_t[fn+3];
  fU = new Double_t[fn+3]    ;
  function = new  TFormula("function",ff);  
  fx=fxo; fy=function->Eval(fxo); fu=fuo;
  fX[0]=fx; 
  fY[0]=fy;
  fU[0]=fu;
  for (Int_t i=0;i<=fn+1;i++){
    fx=fxo+(i*fh);
    fu=fu+(TEuler2::Eval(fx,fy)*fh);
    fy=fy+(fu*fh); 
    fX[i+1]=fx;
    fY[i+1]=fy;    
    fU[i+1]=fu;
  }
}

Double_t TEuler2::Eval(Double_t x,Double_t y){ 
  return function->Eval(x,y);
}

void TEuler2::Draw(){
  graph = new TGraph(fn+1,fX,fY);                              
  graph->SetTitle("Euler2's Method");
  graph->Draw("AC");
  flegend = new TLegend(0, 0, 0.2, 0.1,ff, "ndc");
  flegend->Draw("");
}

void TEuler2::DrawInv(){
  graph = new TGraph(fn+1,fY,fX);                             
  graph->SetTitle("Euler2's Method");
  graph->Draw("AC");
  flegend = new TLegend(0, 0, 0.2, 0.1,ff, "ndc");
  flegend->Draw("");
}

void TEuler2::Print(){
  for(int j=0;j<=fn;j++){
    cout << fX[j] <<"\t"<< fY[j]<<endl;
  }
}

void TEuler2::PrintFile(Char_t *namefile){
  ofstream outfile (namefile);
  for(int j=0;j<=fn;j++){
    outfile<<fX[j]<<"\t"<<fY[j]<<endl;
  }
}

