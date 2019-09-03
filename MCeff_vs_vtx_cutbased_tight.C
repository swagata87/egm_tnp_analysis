#include "TLegend.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TH1.h"
#include "TNtuple.h"
#include <iostream>
#include <fstream>
#include "TGraph.h"
#include "TGraphErrors.h"
#include <vector>

void MCeff_vs_vtx_cutbased_tight() {

  TFile* outputFile = new TFile("Eff_vs_VTX_cutbased_tight.root","RECREATE");
  outputFile->cd();

  const   Int_t n = 5;
  

  Double_t y_Barrel_eff_run2[n] ={
    0.694,
    0.687,
    0.682,
    0.664,
    0.654,
    //    0.571,
  };

  Double_t y_Barrel_eff_run2_err[n] ={
    0.003,
    0.006,
    0.013,
    0.030,
    0.093,
    //  0.132,
  };

    Double_t y_Barrel_eff_run3_2023[n] ={
      0.670,
      0.664,
      0.655,
      0.655,
      0.657,
    };

    Double_t y_Barrel_eff_run3_err_2023[n] ={
      0.003,
      0.003,
      0.003,
      0.003,
      0.006,
   };

  //Barrel 2021
   Double_t y_Barrel_eff_run3_2021[n] ={
     0.682,
     0.679,
     0.674,
     0.671,
     0.682,
   };

    Double_t y_Barrel_eff_run3_err_2021[n] ={
      0.002,
      0.002,
      0.002,
      0.002,
      0.005
   };

  ///
  //Barrel 2024
  Double_t y_Barrel_eff_run3_2024[n] ={
    0.653,
    0.655,
    0.647,
    0.646,
    0.644,
  };

  Double_t y_Barrel_eff_run3_err_2024[n] ={
    0.003,
    0.003,
    0.003,
    0.003,
    0.006,
  };

  //Endcap 
   Double_t y_Endcap_eff_run2[n] ={
     0.584,
     0.547,
     0.556,
     0.593,
     0.667,
     //  0.500,
   };

   Double_t y_Endcap_eff_run2_err[n] ={
     0.005,
     0.010,
     0.022,
     0.053,
     0.157,
     //     0.158
   };

  //
   Double_t y_Endcap_eff_run3_2023[n] ={
     0.560,
     0.548,
     0.547,
     0.541,
     0.557,
   };

    Double_t y_Endcap_eff_run3_err_2023[n] ={
      0.004,
      0.004,
      0.004,
      0.005,
      0.010
   };

  //endcap 2021
  Double_t y_Endcap_eff_run3_2021[n] ={
    0.618,
    0.611,
    0.604,
    0.607,
    0.578,
  };

  Double_t y_Endcap_eff_run3_err_2021[n] ={
    0.004,
    0.004,
    0.004,
    0.004,
    0.009
   };

  //
  //endcap 2024
  Double_t y_Endcap_eff_run3_2024[n] ={
    0.548,
    0.543,
    0.526,
    0.516,
    0.503,
  };

  Double_t y_Endcap_eff_run3_err_2024[n] ={
    0.004,
    0.005,
    0.005,
    0.005,
    0.011,
  };

  Double_t x_vtx[n] ={
    (55+60)/2.0,
    (60+65)/2.0,
    (65+70)/2.0,
    (70+75)/2.0,
    (75+80)/2.0,
  };

  Double_t x_vtx_err[n] ={
    (60-55)/2.0,
    (65-60)/2.0,
    (70-65)/2.0,
    (75-70)/2.0,
    (80-75)/2.0,
  };

  TCanvas *c1 = new TCanvas("c1","eff", 200,10,600,400);

  
  TGraphErrors *gr1 = new TGraphErrors (n, x_vtx, y_Barrel_eff_run2, x_vtx_err, y_Barrel_eff_run2_err);
  gr1->SetTitle("Electron TnP efficiency, DYtoEE Powheg");
  gr1->SetMarkerColor(2);
  gr1->SetLineColor(2);
  gr1->SetMarkerStyle(21);
  gr1->Draw("ALP");
  gr1->GetYaxis()->SetTitle("Signal Efficiency");
  gr1->GetXaxis()->SetTitle("Number of true PU");
  gr1->GetHistogram()->SetMaximum(0.85);   // along                                                                                                               
  gr1->GetHistogram()->SetMinimum(0.15);  //   Y                                                                                                                  
  gr1->Write("BarrelEffRun2");
  
  
 TGraphErrors *gr2 = new TGraphErrors (n, x_vtx, y_Barrel_eff_run3_2023, x_vtx_err, y_Barrel_eff_run3_err_2023);
  gr2->SetMarkerColor(4);
  gr2->SetLineColor(4);
  gr2->SetMarkerStyle(22);
  gr2->Draw("LP:SAME");
  gr2->Write("BarrelEffRun3");
  
  TGraphErrors *gr2_2021 = new TGraphErrors (n, x_vtx, y_Barrel_eff_run3_2021, x_vtx_err, y_Barrel_eff_run3_err_2021);
  gr2_2021->SetMarkerColor(8);
  gr2_2021->SetLineColor(8);
  gr2_2021->SetMarkerStyle(20);
  gr2_2021->Draw("LP:SAME");
  gr2_2021->Write("BarrelEffRun3_2021");
  

  TGraphErrors *gr2_2024 = new TGraphErrors (n, x_vtx, y_Barrel_eff_run3_2024, x_vtx_err, y_Barrel_eff_run3_err_2024);
  gr2_2024->SetMarkerColor(1);
  gr2_2024->SetLineColor(1);
  gr2_2024->SetMarkerStyle(33);
  gr2_2024->Draw("LP:same");
  gr2_2024->Write("BarrelEffRun3_2024");

  TLegend *leg_example = new TLegend(0.4,0.10,0.9,0.35);
  leg_example->SetHeader("Barrel, passingTight94XV2","C"); // option "C" allows to center the header                                                             
  leg_example->SetFillColor(0);
  leg_example->SetTextFont(42);
  leg_example->SetBorderSize(0);
  leg_example->AddEntry(gr1, "Run2 (2018)","pl");
  leg_example->AddEntry(gr2, "Run3 (2023)","pl");
  leg_example->AddEntry(gr2_2021, "Run3 (2021)","pl");
  leg_example->AddEntry(gr2_2024, "Run3 (2024)","pl");
  leg_example->Draw("same");

  c1->SetGrid();

  c1->SaveAs("BarrelEff_cut_tight_VTX.png");

  ////
  ///endcap
  ////
  TCanvas *c2 = new TCanvas("c2","eff2", 200,10,600,400);

  
  TGraphErrors *gr3 = new TGraphErrors (n, x_vtx, y_Endcap_eff_run2, x_vtx_err, y_Endcap_eff_run2_err);
  gr3->SetTitle("Electron TnP efficiency, DYtoEE Powheg");
  gr3->SetMarkerColor(2);
  gr3->SetLineColor(2);
  gr3->SetMarkerStyle(21);
  gr3->Draw("ALP");
  gr3->GetYaxis()->SetTitle("Signal Efficiency");
  gr3->GetXaxis()->SetTitle("Number of true PU");
  gr3->GetHistogram()->SetMaximum(0.85);   // along                                                                                                           
  gr3->GetHistogram()->SetMinimum(0.15);  //   Y                                                                                                                
  gr3->Write("EndcapEffRun2");
  

 
  TGraphErrors *gr4 = new TGraphErrors (n, x_vtx, y_Endcap_eff_run3_2023, x_vtx_err, y_Endcap_eff_run3_err_2023);
  gr4->SetMarkerColor(4);
  gr4->SetLineColor(4);
  gr4->SetMarkerStyle(22);
  gr4->Draw("LP:SAME");
  gr4->Write("EndcapEffRun3");
  
  TGraphErrors *gr4_2021 = new TGraphErrors (n, x_vtx, y_Endcap_eff_run3_2021, x_vtx_err, y_Endcap_eff_run3_err_2021);
  gr4_2021->SetMarkerColor(8);
  gr4_2021->SetLineColor(8);
  gr4_2021->SetMarkerStyle(20);
  gr4_2021->Draw("LP:SAME");
  gr4_2021->Write("EndcapEffRun3_2021");
 

  TGraphErrors *gr4_2024 = new TGraphErrors (n, x_vtx, y_Endcap_eff_run3_2024, x_vtx_err, y_Endcap_eff_run3_err_2024);
  gr4_2024->SetMarkerColor(1);
  gr4_2024->SetLineColor(1);
  gr4_2024->SetMarkerStyle(33);
  gr4_2024->Draw("LP:same");
  gr4_2024->Write("EndcapEffRun3_2024");

  TLegend *leg_example_2 = new TLegend(0.4,0.10,0.9,0.35);
  leg_example_2->SetHeader("Endcap, passingTight94XV2","C"); // option "C" allows to center the header                                                             
  leg_example_2->SetFillColor(0);
  leg_example_2->SetTextFont(42);
  leg_example_2->SetBorderSize(0);
  leg_example_2->AddEntry(gr1, "Run2 (2018)","pl");
  leg_example_2->AddEntry(gr2, "Run3 (2023)","pl");
  leg_example_2->AddEntry(gr2_2021, "Run3 (2021)","pl");
  leg_example_2->AddEntry(gr2_2024, "Run3 (2024)","pl");
  leg_example_2->Draw("same");

  c2->SetGrid();

  c2->SaveAs("EndcapEff_cut_tight_VTX.png");


}
