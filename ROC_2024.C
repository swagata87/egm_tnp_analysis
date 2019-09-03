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



void ROC_2024() {

  TFile* outputFile = new TFile("ROC_2024_new.root","RECREATE");
  outputFile->cd();

  const   Int_t n = 4; // Veto, Loose, Medium, Tight
  
  //Barrel 2024
  Double_t y_Barrel_BkgRej_run3_2024_pt1[n] ={
     0.031,
     0.014,
     0.007,
     0.005,
    //  0.108,
    //  0.089,
    //  0.064,
    //  0.057,
  };

  Double_t x_Barrel_SigEff_run3_2024_pt1[n] ={
    0.915,
    0.857,
    0.762,
    0.655,
    // 0.920,
    // 0.866,
    // 0.772,
    // 0.665,
  };

  //
  Double_t y_Endcap_BkgRej_run3_2024_pt1[n] ={
     0.061,
     0.037,
     0.020,
     0.005,
    //  0.116,
    //  0.070,
    //  0.047,
    //  0.047,
  };

  Double_t x_Endcap_SigEff_run3_2024_pt1[n] ={
    0.852,
    0.787,
    0.669,
    0.543,
    // 0.920,
    // 0.866,
    // 0.772,
    // 0.665,
  };

  /// 2018
  Double_t y_Barrel_BkgRej_run2_2018_pt1[n] ={
     0.027,
     0.012,
     0.005,
     0.003,
  };

  Double_t x_Barrel_SigEff_run2_2018_pt1[n] ={
    0.945,
    0.907,
    0.823,
    0.724,
  };
  //
  Double_t y_Endcap_BkgRej_run2_2018_pt1[n] ={
     0.060,
     0.031,
     0.015,
     0.007,
  };

  Double_t x_Endcap_SigEff_run2_2018_pt1[n] ={
    0.910,
    0.865,
    0.765,
    0.652,
  };

  // // 2023
  TCanvas *c1 = new TCanvas("c1","eff", 200,10,600,400);
  TGraph *gr1 = new TGraph (n, x_Barrel_SigEff_run3_2024_pt1, y_Barrel_BkgRej_run3_2024_pt1);
  gr1->SetTitle("Electron ID ROC, DYtoEE(sig) and TTbar(bkg)");
  gr1->SetMarkerColor(2);
  gr1->SetLineColor(2);
  gr1->SetMarkerStyle(21);
  gr1->Draw("ALP");
  gr1->GetYaxis()->SetTitle("Background Efficiency");
  gr1->GetXaxis()->SetTitle("Signal Efficiency");
  gr1->GetHistogram()->SetMaximum(0.07);   // along                                                                                                                   
  gr1->GetHistogram()->SetMinimum(0.00);  //   Y                                                                                                                      
  gr1->GetXaxis()->SetLimits(0.5,0.99);
  gr1->Write("BarrelEffRun3_roc");

  TGraph *gr2 = new TGraph (n, x_Barrel_SigEff_run2_2018_pt1, y_Barrel_BkgRej_run2_2018_pt1);
  gr2->SetMarkerColor(4);
  gr2->SetLineColor(4);
  gr2->SetMarkerStyle(22);
  gr2->Draw("LP:SAME");
  gr2->Write("BarrelEffRun2_roc");

  TLegend *leg_example = new TLegend(0.15,0.5,0.5,0.8);
  leg_example->SetHeader("Barrel, Cut based ID","C"); // option "C" allows to center the header                                                             
  leg_example->SetFillColor(0);
  leg_example->SetTextFont(42);
  leg_example->SetBorderSize(0);
  leg_example->AddEntry(gr1, "Run3 (2024)","pl");
  leg_example->AddEntry(gr2, "Run2 (2018)","pl");
  leg_example->Draw("same");

  c1->SetGrid();
  c1->SaveAs("BarrelROC_cutbased_pt1_new.png");

  ////
  ///endcap
  ////
  TCanvas *c2 = new TCanvas("c2","eff", 200,10,600,400);

  TGraph *gr1_1 = new TGraph (n, x_Endcap_SigEff_run3_2024_pt1, y_Endcap_BkgRej_run3_2024_pt1);
  gr1_1->SetTitle("Electron ID ROC, DYtoEE(sig) and TTbar(bkg)");
  gr1_1->SetMarkerColor(2);
  gr1_1->SetLineColor(2);
  gr1_1->SetMarkerStyle(21);
  gr1_1->Draw("ALP");
  gr1_1->GetYaxis()->SetTitle("Background Efficiency");
  gr1_1->GetXaxis()->SetTitle("Signal Efficiency");
  gr1_1->GetHistogram()->SetMaximum(0.07);   // along                                                                                                                   
  gr1_1->GetHistogram()->SetMinimum(0.00);  //   Y                                                                                                                 
  gr1_1->GetXaxis()->SetLimits(0.5,0.99);
  gr1_1->Write("EndcapEffRun3_roc");

  TGraph *gr2_1 = new TGraph (n, x_Endcap_SigEff_run2_2018_pt1, y_Endcap_BkgRej_run2_2018_pt1);
  gr2_1->SetMarkerColor(4);
  gr2_1->SetLineColor(4);
  gr2_1->SetMarkerStyle(22);
  gr2_1->Draw("LP:SAME");
  gr2_1->Write("EndcapEffRun2_roc");

  TLegend *leg_example_1 = new TLegend(0.15,0.5,0.5,0.8);
  leg_example_1->SetHeader("Endcap, Cut based ID","C"); // option "C" allows to center the header                                                             
  leg_example_1->SetFillColor(0);
  leg_example_1->SetTextFont(42);
  leg_example_1->SetBorderSize(0);
  leg_example_1->AddEntry(gr1, "Run3 (2024)","pl");
  leg_example_1->AddEntry(gr2_1, "Run2 (2018)","pl");
  leg_example_1->Draw("same");

  c2->SetGrid();

  c2->SaveAs("EndcapROC_cutbased_pt1_new.png");
  ///



}
