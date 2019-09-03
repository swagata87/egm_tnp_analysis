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

void ROC_mva() {

  TFile* outputFile = new TFile("ROC_mva.root","RECREATE");
  outputFile->cd();

  const   Int_t n = 4; // Veto, Loose, Medium, Tight
  
  //Barrel 2023
  Double_t y_Barrel_BkgRej_run3_2023_pt1[n] ={
    1-0.038,
    1-0.070,
    1-0.121,
    1-0.197,
  };

  Double_t x_Barrel_SigEff_run3_2023_pt1[n] ={
    0.671,
    0.830,
    0.969,
    0.992,
  };
  //
  Double_t y_Endcap_BkgRej_run3_2023_pt1[n] ={
    1-0.070,
    1-0.116,
    1-0.116,
    1-0.140,
  };

  Double_t x_Endcap_SigEff_run3_2023_pt1[n] ={
    0.682,
    0.823,
    0.952,
    0.977,
  };

  /// 2018
  Double_t y_Barrel_BkgRej_run2_2018_pt1[n] ={
    1-0.009,
    1-0.019,
    1-0.055,
    1-0.140,
  };

  Double_t x_Barrel_SigEff_run2_2018_pt1[n] ={
    0.780,
    0.893,
    0.981,
    0.996,
  };
  //
  Double_t y_Endcap_BkgRej_run2_2018_pt1[n] ={
    1-0.018,
    1-0.037,
    1-0.065,
    1-0.105,
  };

  Double_t x_Endcap_SigEff_run2_2018_pt1[n] ={
    0.790,
    0.897,
    0.976,
    0.989,
  };

  // // 2023
  TCanvas *c1 = new TCanvas("c1","eff", 200,10,600,400);
  TGraph *gr1 = new TGraph (n, x_Barrel_SigEff_run3_2023_pt1, y_Barrel_BkgRej_run3_2023_pt1);
  gr1->SetTitle("Electron ID ROC, DYtoEE(sig) and TTbar(bkg)");
  gr1->SetMarkerColor(2);
  gr1->SetLineColor(2);
  gr1->SetMarkerStyle(21);
  gr1->Draw("ALP");
  gr1->GetYaxis()->SetTitle("Background Rejection");
  gr1->GetXaxis()->SetTitle("Signal Efficiency");
  gr1->GetHistogram()->SetMaximum(1.15);   // along                                                                                                                   
  gr1->GetHistogram()->SetMinimum(0.00);  //   Y                                                                                                                      
  gr1->GetXaxis()->SetLimits(0.6,1.05);
  gr1->Write("BarrelEffRun3_roc");

  TGraph *gr2 = new TGraph (n, x_Barrel_SigEff_run2_2018_pt1, y_Barrel_BkgRej_run2_2018_pt1);
  gr2->SetMarkerColor(4);
  gr2->SetLineColor(4);
  gr2->SetMarkerStyle(22);
  gr2->Draw("LP:SAME");
  gr2->Write("BarrelEffRun2_roc");

  TLegend *leg_example = new TLegend(0.4,0.10,0.7,0.4);
  leg_example->SetHeader("Barrel, MVA ID","C"); // option "C" allows to center the header                                                             
  leg_example->SetFillColor(0);
  leg_example->SetTextFont(42);
  leg_example->SetBorderSize(0);
  leg_example->AddEntry(gr1, "Run3 (2023)","pl");
  leg_example->AddEntry(gr2, "Run2 (2018)","pl");
  leg_example->Draw("same");

  c1->SetGrid();
  c1->SaveAs("BarrelROC_mva_pt1.png");

  ////
  ///endcap
  ////
  TCanvas *c2 = new TCanvas("c2","eff", 200,10,600,400);

  TGraph *gr1_1 = new TGraph (n, x_Endcap_SigEff_run3_2023_pt1, y_Endcap_BkgRej_run3_2023_pt1);
  gr1_1->SetTitle("Electron ID ROC, DYtoEE(sig) and TTbar(bkg)");
  gr1_1->SetMarkerColor(2);
  gr1_1->SetLineColor(2);
  gr1_1->SetMarkerStyle(21);
  gr1_1->Draw("ALP");
  gr1_1->GetYaxis()->SetTitle("Background Rejection");
  gr1_1->GetXaxis()->SetTitle("Signal Efficiency");
  gr1_1->GetHistogram()->SetMaximum(1.15);   // along                                                                                                                   
  gr1_1->GetHistogram()->SetMinimum(0.00);  //   Y                                                                                                                 
  gr1_1->GetXaxis()->SetLimits(0.6,1.05);
  gr1_1->Write("EndcapEffRun3_roc");

  TGraph *gr2_1 = new TGraph (n, x_Endcap_SigEff_run2_2018_pt1, y_Endcap_BkgRej_run2_2018_pt1);
  gr2_1->SetMarkerColor(4);
  gr2_1->SetLineColor(4);
  gr2_1->SetMarkerStyle(22);
  gr2_1->Draw("LP:SAME");
  gr2_1->Write("EndcapEffRun2_roc");

  TLegend *leg_example_1 = new TLegend(0.4,0.10,0.7,0.4);
  leg_example_1->SetHeader("Endcap, MVA ID","C"); // option "C" allows to center the header                                                             
  leg_example_1->SetFillColor(0);
  leg_example_1->SetTextFont(42);
  leg_example_1->SetBorderSize(0);
  leg_example_1->AddEntry(gr1, "Run3 (2023)","pl");
  leg_example_1->AddEntry(gr2_1, "Run2 (2018)","pl");
  leg_example_1->Draw("same");

  c2->SetGrid();

  c2->SaveAs("EndcapROC_mva_pt1.png");
  ///



}
