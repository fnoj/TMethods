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

#include "TRk4.h" 

void Rk4(){
  c1 = new TCanvas("c1","Rk4 Method's",800,800);
  c1->Range(-20,-20,20,20);
  c1->SetGrid();

  e1 = new TRk4("x",-4,4,4,1000);
  e1->Draw();

  // e1 = new TRk4();
  // e1->SetFunction("x");
  // e1->SetXo(-10);
  // e1->SetYo(-1000);
  // e1->SetXf(10);
  // e1->SetN(100);
  // e1->SetH((e1->GetXf()-e1->GetXo())/(e1->GetN()));
  // e1->Calculate();
  // e1->Draw();

  Double_t *fx = e1->GetX();
  Double_t *fy = e1->GetY();

  // for(int j=0;j<=e1->GetN();j++){
  //   cout << fx[j] <<"\t"<< fy[j]<<endl;
  // }

  gPad->Update();
}
