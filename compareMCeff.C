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

void compareMCeff() {

  TFile* outputFile = new TFile("MCeff.root","RECREATE");
  outputFile->cd();

  const   Int_t n = 6;
  
  //Barrel 2023
  Double_t y_Barrel_eff_run2[n] ={
    0.647,
    0.845,
    0.929,
    0.951,
    0.963,
    0.966,
  };

  Double_t y_Barrel_eff_run2_err[n] ={
    0.003,
    0.001,
    0.001,
    0.001,
    0.003,
    0.006,
  };

  //Barrel 2021
  Double_t y_Barrel_eff_run3_2021[n] ={
    0.578,
    0.808,
    0.906,
    0.933,
    0.942,
    0.958,
  };

  Double_t y_Barrel_eff_run3_err_2021[n] ={
    0.008,
    0.002,
    0.001,
    0.002,
    0.011,
    0.014
  };
  ///
  //Barrel 2024
  Double_t y_Barrel_eff_run3_2024[n] ={
    0.355,
    0.763,
    0.900,
    0.932,
    0.939,
    0.952,
  };

  Double_t y_Barrel_eff_run3_err_2024[n] ={
    0.009,
    0.003,
    0.001,
    0.002,
    0.014,
    0.018,
  };


  Double_t y_Endcap_eff_run2[n] ={
    0.655,
    0.806,
    0.897,
    0.922,
    0.941,
    0.940
  };

  Double_t y_Endcap_eff_run2_err[n] ={
    0.003,
    0.001,
    0.001,
    0.001,
    0.007,
    0.016
  };

  Double_t y_Barrel_eff_run3[n] ={
    0.401,
    0.783,
    0.903,
    0.940,
    0.952,
    0.932,
  };

  Double_t y_Barrel_eff_run3_err[n] ={
    0.009,
    0.002,
    0.001,
    0.002,
    0.012,
    0.018,
  };

  //endcap 2021
  Double_t y_Endcap_eff_run3_2021[n] ={
    0.596,
    0.778,
    0.868,
    0.891,
    0.913,
    0.941,
  };

  Double_t y_Endcap_eff_run3_err_2021[n] ={
    0.010,
    0.003,
    0.002,
    0.004,
    0.023,
    0.033,
  };

  //
  //endcap 2024
  Double_t y_Endcap_eff_run3_2024[n] ={
    0.509,
    0.725,
    0.834,
    0.869,
    0.854,
    0.930,
  };

  Double_t y_Endcap_eff_run3_err_2024[n] ={
    0.011,
    0.004,
    0.002,
    0.006,
    0.043,
    0.039
  };

  //

  Double_t y_Endcap_eff_run3[n] ={
    0.512,
    0.729,
    0.844,
    0.874,
    0.932,
    0.950
  };


  Double_t y_Endcap_eff_run3_err[n] ={
    0.011,
    0.004,
    0.002,
    0.005,
    0.025,
    0.034,
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
  gr1->GetHistogram()->SetMinimum(0.25);  //   Y                                                                                                                       
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
  leg_example->SetHeader("Barrel, passingLoose94XV2","C"); // option "C" allows to center the header                                                             
  leg_example->SetFillColor(0);
  leg_example->SetTextFont(42);
  leg_example->SetBorderSize(0);
  leg_example->AddEntry(gr1, "Run2 (2018)","pl");
  leg_example->AddEntry(gr2, "Run3 (2023)","pl");
  leg_example->AddEntry(gr2_2021, "Run3 (2021)","pl");
  leg_example->AddEntry(gr2_2024, "Run3 (2024)","pl");
  leg_example->Draw("same");

  c1->SetGrid();

  c1->SaveAs("BarrelEff.png");

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
  gr3->GetHistogram()->SetMinimum(0.25);  //   Y                                                                                                                       
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
  leg_example_2->SetHeader("Endcap, passingLoose94XV2","C"); // option "C" allows to center the header                                                             
  leg_example_2->SetFillColor(0);
  leg_example_2->SetTextFont(42);
  leg_example_2->SetBorderSize(0);
  leg_example_2->AddEntry(gr1, "Run2 (2018)","pl");
  leg_example_2->AddEntry(gr2, "Run3 (2023)","pl");
  leg_example_2->AddEntry(gr2_2021, "Run3 (2021)","pl");
  leg_example_2->AddEntry(gr2_2024, "Run3 (2024)","pl");
  leg_example_2->Draw("same");

  c2->SetGrid();

  c2->SaveAs("EndcapEff.png");


}
