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

void ROC_mva_2024() {

  TFile* outputFile = new TFile("ROC_mva.root","RECREATE");
  outputFile->cd();

  const   Int_t n = 4; // Veto, Loose, Medium, Tight
  
  //Barrel 2024
  Double_t y_Barrel_BkgRej_run3_2024_pt1[n] ={
     0.009,
     0.017,
     0.043,
     0.129,
    // 0.038,
    // 0.070,
    // 0.121,
    // 0.197,
  };

  Double_t x_Barrel_SigEff_run3_2024_pt1[n] ={
    0.643,
    0.814,
    0.965,
    0.991,
    //0.671,
    //0.830,
    //0.969,
    //0.992,
  };
  //
  Double_t y_Endcap_BkgRej_run3_2024_pt1[n] ={
     0.016,
     0.037,
     0.065,
     0.096,
    // 0.070,
    // 0.116,
    // 0.116,
    // 0.140,
  };

  Double_t x_Endcap_SigEff_run3_2024_pt1[n] ={
    0.653,
    0.804,
    0.946,
    0.975,
    //0.682,
    //0.823,
    //0.952,
    //0.977,
  };

  /// 2018
  Double_t y_Barrel_BkgRej_run2_2018_pt1[n] ={
     0.009,
     0.019,
     0.055,
     0.140,
  };

  Double_t x_Barrel_SigEff_run2_2018_pt1[n] ={
    0.780,
    0.893,
    0.981,
    0.996,
  };
  //
  Double_t y_Endcap_BkgRej_run2_2018_pt1[n] ={
     0.018,
     0.037,
     0.065,
     0.105,
  };

  Double_t x_Endcap_SigEff_run2_2018_pt1[n] ={
    0.790,
    0.897,
    0.976,
    0.989,
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
  gr1->GetHistogram()->SetMaximum(0.155);   // along                                                                                                                   
  gr1->GetHistogram()->SetMinimum(0.00);  //   Y                                                                                                                      
  gr1->GetXaxis()->SetLimits(0.6,1.05);
  gr1->Write("BarrelEffRun3_roc");

  TGraph *gr2 = new TGraph (n, x_Barrel_SigEff_run2_2018_pt1, y_Barrel_BkgRej_run2_2018_pt1);
  gr2->SetMarkerColor(4);
  gr2->SetLineColor(4);
  gr2->SetMarkerStyle(22);
  gr2->Draw("LP:SAME");
  gr2->Write("BarrelEffRun2_roc");

  TLegend *leg_example = new TLegend(0.2,0.5,0.5,0.8);
  leg_example->SetHeader("Barrel, MVA ID","C"); // option "C" allows to center the header                                                             
  leg_example->SetFillColor(0);
  leg_example->SetTextFont(42);
  leg_example->SetBorderSize(0);
  leg_example->AddEntry(gr1, "Run3 (2024)","pl");
  leg_example->AddEntry(gr2, "Run2 (2018)","pl");
  leg_example->Draw("same");

  c1->SetGrid();
  c1->SaveAs("BarrelROC_mva_pt1_new.png");

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
  gr1_1->GetHistogram()->SetMaximum(0.155);   // along                                                                                                                   
  gr1_1->GetHistogram()->SetMinimum(0.00);  //   Y                                                                                                                 
  gr1_1->GetXaxis()->SetLimits(0.6,1.05);
  gr1_1->Write("EndcapEffRun3_roc");

  TGraph *gr2_1 = new TGraph (n, x_Endcap_SigEff_run2_2018_pt1, y_Endcap_BkgRej_run2_2018_pt1);
  gr2_1->SetMarkerColor(4);
  gr2_1->SetLineColor(4);
  gr2_1->SetMarkerStyle(22);
  gr2_1->Draw("LP:SAME");
  gr2_1->Write("EndcapEffRun2_roc");

  TLegend *leg_example_1 = new TLegend(0.2,0.5,0.5,0.8);
  leg_example_1->SetHeader("Endcap, MVA ID","C"); // option "C" allows to center the header                                                             
  leg_example_1->SetFillColor(0);
  leg_example_1->SetTextFont(42);
  leg_example_1->SetBorderSize(0);
  leg_example_1->AddEntry(gr1, "Run3 (2024)","pl");
  leg_example_1->AddEntry(gr2_1, "Run2 (2018)","pl");
  leg_example_1->Draw("same");

  c2->SetGrid();

  c2->SaveAs("EndcapROC_mva_pt1_new.png");
  ///



}
