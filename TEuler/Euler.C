///////////////////////////////////////////////////////////////////////////
//                                                                       //
// NOTICE OF COPYRIGHT                                                   //
//                                                                       //
//        Copyright (C) 2013   John Suárez - Diego Vasquez               //
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

#include "TEuler.h" 

void Euler(){
  c1 = new TCanvas("c1","Euler's Method",800,800);
  c1->Range(-20,-20,20,20);
  c1->SetGrid();

  e1 = new TEuler("-x/sqrt(16-x*x)",-4,4,4,1000);
  //  e1->Draw();
  Double_t x=0;
  Double_t y=e1->GetYo();

  for(Int_t i=0;i<=1000;i++){
    e1->CalculatePoint(i,y);
    x=e1->GetXp();
    y=e1->GetYp();
    cout<<x<<"\t"<<y<<endl;
  }

  Double_t *fx = e1->GetX();
  Double_t *fy = e1->GetY();

  //e1->Print();
  //e1->PrintFile("dat.dat");

  gPad->Update();
}
