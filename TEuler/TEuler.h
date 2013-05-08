#include <TFunction.h>
#include <TLegend.h>

class TEuler{

 private:
  TFormula *function;
  TLegend *flegend;
  Double_t fxo;   //x inicial
  Double_t fxf;  //xfinal   
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
  TEuler(Char_t *func,Double_t xo, Double_t yo, Double_t xf, Double_t yf, Double_t n);
   
  void SetXo(Double_t Xo){fxo=Xo;}
  void SetXf(Double_t Xf){fxf=Xf;}
  void SetYo(Double_t Yo){fyo=Yo;}
  void SetYf(Double_t Yf){fyf=Yf;}
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

TEuler::TEuler(Char_t *func,Double_t xo,Double_t yo ,Double_t xf, Double_t yf, Double_t n){
  fxo=xo; fyo=yo; fxf=xf; fyf=yf; fn=n; fh=(fxf-fxo)/fn; ff=func;
  TEuler::Init();
}

void TEuler::Init(){
  fX = new Double_t[fn+2];
  fY = new Double_t[fn+2];
  function = new  TFormula("function",ff);  //funciona bien pero tocaría sin los métodos GetFunction ni SetFunction.
  fx=fxo; fy=fyo;
  fX[0]=fx;  //pero = ud no me paso la clase final 
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
