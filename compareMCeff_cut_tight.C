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

//Only Run2 means 2023

void compareMCeff_cut_tight() {

  TFile* outputFile = new TFile("MCeff_cut_tight.root","RECREATE");
  outputFile->cd();

  const   Int_t n = 6;
  

  Double_t y_Barrel_eff_run2[n] ={
    0.395,
    0.626,
    0.753,
    0.810,
    0.883,
    0.899,
  };

  Double_t y_Barrel_eff_run2_err[n] ={
    0.003,
    0.001,
    0.001,
    0.001,
    0.005,
    0.011,
  };

  Double_t y_Barrel_eff_run3[n] ={
    0.201,
    0.539,
    0.711,
    0.787,
    0.859,
    0.889,
  };

  Double_t y_Barrel_eff_run3_err[n] ={
    0.007,
    0.003,
    0.002,
    0.004,
    0.019,
    0.023,
  };

  //Barrel 2021
  Double_t y_Barrel_eff_run3_2021[n] ={
    0.336,
    0.581,
    0.714,
    0.771,
    0.830,
    0.888,
  };

  Double_t y_Barrel_eff_run3_err_2021[n] ={
    0.008,
    0.003,
    0.001,
    0.003,
    0.018,
    0.022
  };
  ///
  //Barrel 2024
  Double_t y_Barrel_eff_run3_2024[n] ={
    0.176,
    0.513,
    0.706,
    0.786,
    0.856,
    0.883,
  };

  Double_t y_Barrel_eff_run3_err_2024[n] ={
    0.007,
    0.003,
    0.002,
    0.004,
    0.020,
    0.027,
  };

  //Endcap 
  Double_t y_Endcap_eff_run2[n] ={
    0.364,
    0.561,
    0.694,
    0.757,
    0.833,
    0.880,
  };

  Double_t y_Endcap_eff_run2_err[n] ={
    0.003,
    0.001,
    0.001,
    0.002,
    0.011,
    0.021,
  };

  //
  Double_t y_Endcap_eff_run3[n] ={
    0.230,
    0.465,
    0.618,
    0.672,
    0.806,
    0.900,
  };


  Double_t y_Endcap_eff_run3_err[n] ={
    0.009,
    0.004,
    0.003,
    0.007,
    0.039,
    0.047,
  };

  //endcap 2021
  Double_t y_Endcap_eff_run3_2021[n] ={
    0.302,
    0.534,
    0.666,
    0.721,
    0.792,
    0.784,
  };

  Double_t y_Endcap_eff_run3_err_2021[n] ={
    0.009,
    0.004,
    0.002,
    0.005,
    0.033,
    0.058,
  };

  //
  //endcap 2024
  Double_t y_Endcap_eff_run3_2024[n] ={
    0.212,
    0.451,
    0.604,
    0.675,
    0.654,
    0.930,
  };

  Double_t y_Endcap_eff_run3_err_2024[n] ={
    0.009,
    0.004,
    0.003,
    0.008,
    0.057,
    0.039,
  };

  Double_t x_pt[n] ={
    (10+20)/2.0,
    (20+35)/2.0,
    (35+50)/2.0,
    (50+100)/2.0,
    (100+200)/2.0,
    (200+500)/2.0,
  };

  Double_t x_pt_err[n] ={
    (20-10)/2.0,
    (35-20)/2.0,
    (50-35)/2.0,
    (100-50)/2.0,
    (200-100)/2.0,
    (500-200)/2.0,
  };

  TCanvas *c1 = new TCanvas("c1","eff", 200,10,600,400);

  TGraphErrors *gr1 = new TGraphErrors (n, x_pt, y_Barrel_eff_run2, x_pt_err, y_Barrel_eff_run2_err);
  gr1->SetTitle("Electron TnP efficiency, DYtoEE Powheg");
  gr1->SetMarkerColor(2);
  gr1->SetLineColor(2);
  gr1->SetMarkerStyle(21);
  gr1->Draw("ALP");
  gr1->GetYaxis()->SetTitle("Efficiency");
  gr1->GetXaxis()->SetTitle("p_{T} of electron in GeV");
  gr1->GetHistogram()->SetMaximum(1.05);   // along                                                                                                                   
  gr1->GetHistogram()->SetMinimum(0.05);  //   Y                                                                                                                       
  gr1->Write("BarrelEffRun2");

  TGraphErrors *gr2 = new TGraphErrors (n, x_pt, y_Barrel_eff_run3, x_pt_err, y_Barrel_eff_run3_err);
  gr2->SetMarkerColor(4);
  gr2->SetLineColor(4);
  gr2->SetMarkerStyle(22);
  gr2->Draw("LP:SAME");
  gr2->Write("BarrelEffRun3");

  TGraphErrors *gr2_2021 = new TGraphErrors (n, x_pt, y_Barrel_eff_run3_2021, x_pt_err, y_Barrel_eff_run3_err_2021);
  gr2_2021->SetMarkerColor(8);
  gr2_2021->SetLineColor(8);
  gr2_2021->SetMarkerStyle(20);
  gr2_2021->Draw("LP:SAME");
  gr2_2021->Write("BarrelEffRun3_2021");

  TGraphErrors *gr2_2024 = new TGraphErrors (n, x_pt, y_Barrel_eff_run3_2024, x_pt_err, y_Barrel_eff_run3_err_2024);
  gr2_2024->SetMarkerColor(1);
  gr2_2024->SetLineColor(1);
  gr2_2024->SetMarkerStyle(33);
  gr2_2024->Draw("LP:SAME");
  gr2_2024->Write("BarrelEffRun3_2024");

  TLegend *leg_example = new TLegend(0.4,0.10,0.9,0.5);
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

  c1->SaveAs("BarrelEff_cut_tight.png");

  ////
  ///endcap
  ////
  TCanvas *c2 = new TCanvas("c2","eff2", 200,10,600,400);

  TGraphErrors *gr3 = new TGraphErrors (n, x_pt, y_Endcap_eff_run2, x_pt_err, y_Endcap_eff_run2_err);
  gr3->SetTitle("Electron TnP efficiency, DYtoEE Powheg");
  gr3->SetMarkerColor(2);
  gr3->SetLineColor(2);
  gr3->SetMarkerStyle(21);
  gr3->Draw("ALP");
  gr3->GetYaxis()->SetTitle("Efficiency");
  gr3->GetXaxis()->SetTitle("p_{T} of electron in GeV");
  gr3->GetHistogram()->SetMaximum(1.05);   // along                                                                                                                   
  gr3->GetHistogram()->SetMinimum(0.05);  //   Y                                                                                                                       
  gr3->Write("EndcapEffRun2");

  TGraphErrors *gr4 = new TGraphErrors (n, x_pt, y_Endcap_eff_run3, x_pt_err, y_Endcap_eff_run3_err);
  gr4->SetMarkerColor(4);
  gr4->SetLineColor(4);
  gr4->SetMarkerStyle(22);
  gr4->Draw("LP:SAME");
  gr4->Write("EndcapEffRun3");

  TGraphErrors *gr4_2021 = new TGraphErrors (n, x_pt, y_Endcap_eff_run3_2021, x_pt_err, y_Endcap_eff_run3_err_2021);
  gr4_2021->SetMarkerColor(8);
  gr4_2021->SetLineColor(8);
  gr4_2021->SetMarkerStyle(20);
  gr4_2021->Draw("LP:SAME");
  gr4_2021->Write("EndcapEffRun3_2021");

  TGraphErrors *gr4_2024 = new TGraphErrors (n, x_pt, y_Endcap_eff_run3_2024, x_pt_err, y_Endcap_eff_run3_err_2024);
  gr4_2024->SetMarkerColor(1);
  gr4_2024->SetLineColor(1);
  gr4_2024->SetMarkerStyle(33);
  gr4_2024->Draw("LP:SAME");
  gr4_2024->Write("EndcapEffRun3_2024");

  TLegend *leg_example_2 = new TLegend(0.4,0.10,0.9,0.5);
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

  c2->SaveAs("EndcapEff_cut_tight.png");


}
