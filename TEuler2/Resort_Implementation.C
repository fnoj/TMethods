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

#include "TEuler2.h" 
#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include<unistd.h>
#include <iomanip>

TCanvas *c1;
TCurlyLine *curlyline; 
TEllipse *ellipse;
TTimer *Count;
TEuler2 *e1;
Double_t x;
Double_t y;
Int_t i=0;

void Resort_Implementation(){
  c1 = new TCanvas("c1","Euler2's Method",800,800);
  //c1->Range(-10,-10,10,10);
  //c1->SetGrid();

  e1 = new TEuler2("-y",0,1,15*TMath::Pi(),0,1000);
  Count = new TTimer(10);
  Count->Connect("Timeout()","R","","Run()");
  Run();
}

void Run(){
  Count->Add();
  // x=e1->GetX();
  // y=e1->GetY();
  // cout << x[0]<<"\t"<<y[0]<<endl;
  // cout << x[1]<<"\t"<<y[1]<<endl;
  //  e1->Draw();
  e1->CalculatePoint(i);
  x=e1->GetXp();
  y=e1->GetYp();
  
  curlyline = new TCurlyLine(0.1, 0.5, 0.2*y + 0.6, 0.5, 0.02,0.02);
  curlyline->Draw();
  ellipse = new TEllipse(0.2*y + 0.6, 0.5 , 0.04, 0.05, 0, 360, 0);
  ellipse->Draw();
  ellipse->SetFillColor(2);
  
  line = new TLine(0.1, 0.2, 0.1, 0.9);
  line->Draw();
  c1->Update();
  c1->Modified();
  
  delete curlyline;
  delete ellipse;
  i++;
  //e1->PrintFile("euler2.dat");
  // cout<<  e1->GetFunction()<<endl;
}
