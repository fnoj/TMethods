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

void Euler2(){
  c1 = new TCanvas("c1","Euler2's Method",800,800);
  c1->Range(-20,-20,20,20);
  c1->SetGrid();
  
  Double_t x;
  Double_t y;
  
  // e1 = new TEuler2();
  // e1->SetXo(-10);
  // e1->SetYo(-1000);
  // e1->SetXf(10);
  // e1->SetU(300);
  // e1->SetN(100);
  // e1->SetH((e1->GetXf()-e1->GetXo())/(e1->GetN()));
  // e1->Calculate();
  
  e1 = new TEuler2("-y",0,1,4*TMath::Pi(),0,1000);
  
  for(Int_t i=0;i<=1000;i++){
    e1->CalculatePoint(i);
    x=e1->GetXp();
    y=e1->GetYp();
    cout<<x<<"\t"<<y<<endl;
  }
  // cout << x[0]<<"\t"<<y[0]<<endl;
  // cout << x[1]<<"\t"<<y[1]<<endl;
  e1->Draw();
  //e1->PrintFile("euler2.dat");
  // cout<<  e1->GetFunction()<<endl;
    
}
