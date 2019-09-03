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

//Only Run2 means 2024

void vertex_ROC() {

  TFile* outputFile = new TFile("vertex_ROC.root","RECREATE");
  outputFile->cd();

  const   Int_t n = 4; // Veto, Loose, Medium, Tight
  
  //Barrel 2021
   Double_t y_Barrel_BkgRej_run3_2021_pt1[n] ={
     0.0388842,// 0.027,
     0.0143702,// 0.014,
     0.00422654,// 0.008,
     0.00338123,// 0.008,
  };

    Double_t x_Barrel_SigEff_run3_2021_pt1[n] ={
      0.925,
      0.879,
      0.787,
      0.682,
   };
  //
    Double_t y_Endcap_BkgRej_run3_2021_pt1[n] ={
      0.0990338, //0.092,
      0.0458937,//0.056,
      0.0193237,//0.029,
      0.00966184,//0.009,
   };

   Double_t x_Endcap_SigEff_run3_2021_pt1[n] ={
     0.869,
     0.825,
     0.731,
     0.618,
   };

   //2023 barrel 

   Double_t y_Barrel_BkgRej_run3_2023_pt1[n] ={
     0.0390105, //0.026,
     0.0161751, //0.009,
     0.00666032, //0.005,
     0.0038059, //0.003,
   };
   
   Double_t x_Barrel_SigEff_run3_2023_pt1[n] ={
     0.920,
     0.867,
     0.776,
     0.670,
   };
  //
    Double_t y_Endcap_BkgRej_run3_2023_pt1[n] ={
      0.0890805, //0.076,
      0.0517241, //0.037,
      0.0172414, //0.024,
      0.0172414, //0.009,
   };

   Double_t x_Endcap_SigEff_run3_2023_pt1[n] ={
     0.856,
     0.796,
     0.684,
     0.560,
   };

   ////2024
   Double_t y_Barrel_BkgRej_run3_2024_pt1[n] ={
     0.034,//0.027,
     0.015,//0.007,
     0.007,//0.005,
     0.004,//0.003,
  };

    Double_t x_Barrel_SigEff_run3_2024_pt1[n] ={
      0.920,
      0.867,
      0.776,
      0.653,
   };
  //
    Double_t y_Endcap_BkgRej_run3_2024_pt1[n] ={
      0.0960265,//0.082,
      0.0463576,//0.054,
      0.0198675,//0.021,
      0.00331126,//0.000,
   };

   Double_t x_Endcap_SigEff_run3_2024_pt1[n] ={
     0.856,
     0.796,
     0.684,
     0.548,
   };

  /// 2018
   Double_t y_Barrel_BkgRej_run2_2018_pt1[n] ={
     0.0437201,//0.033,
     0.0189324,//0.015,
     0.00829511,//0.008,
     0.00517225,//0.004,
   };

    Double_t x_Barrel_SigEff_run2_2018_pt1[n] ={
      0.924,
      0.880,
      0.797,
      0.694
   };

  //
    Double_t y_Endcap_BkgRej_run2_2018_pt1[n] ={
      0.0947722,// 0.090,
      0.046128,// 0.054,
      0.0176125,// 0.025,
      0.0103439,// 0.009,
   };

   Double_t x_Endcap_SigEff_run2_2018_pt1[n] ={
     0.874,
     0.818,
     0.700,
     0.584,
   };
   ////2018 low pu

   Double_t y_Barrel_BkgRej_run2_2018_pt1_lowpu[n] ={
     0.0357521, // 0.026,
     0.0135534,// 0.012,
     0.00515254,// 0.005,
     0.00281048,// 0.003,
   };

    Double_t x_Barrel_SigEff_run2_2018_pt1_lowpu[n] ={
      0.943,
      0.905,
      0.822,
      0.724,
   };

  //
    Double_t y_Endcap_BkgRej_run2_2018_pt1_lowpu[n] ={
      0.0727326, //  0.078,
      0.0334217,//  0.044,
      0.0138104,//  0.021,
      0.00633098,//  0.010,
   };

   Double_t x_Endcap_SigEff_run2_2018_pt1_lowpu[n] ={
     0.903,
     0.858,
     0.757,
     0.645,
   };


  // // 2018
  TCanvas *c1 = new TCanvas("c1","eff", 200,10,600,400);
  TGraph *gr1 = new TGraph (n, x_Barrel_SigEff_run2_2018_pt1, y_Barrel_BkgRej_run2_2018_pt1);
  gr1->SetTitle("Electron ID ROC, DYtoEE(sig) and TTbar(bkg)");
  gr1->SetMarkerColor(2);
  gr1->SetLineColor(2);
  gr1->SetMarkerStyle(21);
  gr1->Draw("ALP");
  gr1->GetYaxis()->SetTitle("Background Efficiency");
  gr1->GetXaxis()->SetTitle("Signal Efficiency");
  gr1->GetHistogram()->SetMaximum(0.045);   // along                                                                                                               
  gr1->GetHistogram()->SetMinimum(0.00);  //   Y                                                                                                                  
  gr1->GetXaxis()->SetLimits(0.5,0.95);
  gr1->Write("BarrelEffRun2_2018_roc");


  TGraph *gr2 = new TGraph (n, x_Barrel_SigEff_run3_2024_pt1, y_Barrel_BkgRej_run3_2024_pt1);
  gr2->SetMarkerColor(4);
  gr2->SetLineColor(4);
  gr2->SetMarkerStyle(22);
  gr2->Draw("LP:SAME");
  gr2->Write("BarrelEffRun2_roc_2024");

  TGraph *gr3 = new TGraph (n, x_Barrel_SigEff_run3_2021_pt1, y_Barrel_BkgRej_run3_2021_pt1);
  gr3->SetMarkerColor(3);
  gr3->SetLineColor(3);
  gr3->SetMarkerStyle(23);
  gr3->Draw("LP:SAME");
  gr3->Write("BarrelEffRun2_roc_2021");

  TGraph *gr4 = new TGraph (n, x_Barrel_SigEff_run3_2023_pt1, y_Barrel_BkgRej_run3_2023_pt1);
  gr4->SetMarkerColor(6);
  gr4->SetLineColor(6);
  gr4->SetMarkerStyle(25);
  gr4->Draw("LP:SAME");
  gr4->Write("BarrelEffRun2_roc_2023");

  TGraph *gr5 = new TGraph (n, x_Barrel_SigEff_run2_2018_pt1_lowpu, y_Barrel_BkgRej_run2_2018_pt1_lowpu);
  gr5->SetMarkerColor(1);
  gr5->SetLineColor(1);
  gr5->SetMarkerStyle(21);
  gr5->Draw("LP:SAME");
  gr5->Write("BarrelEffRun2_roc_2018_lowpu");

  TLegend *leg_example = new TLegend(0.2,0.5,0.5,0.8);
  leg_example->SetHeader("Barrel","C"); // option "C" allows to center the header                                                             
  leg_example->SetFillColor(0);
  leg_example->SetTextFont(42);
  leg_example->SetBorderSize(0);
  leg_example->AddEntry(gr5, "2018, PU:[30-35]","pl");
  leg_example->AddEntry(gr1, "2018, PU:[55-60]","pl");
  leg_example->AddEntry(gr3, "2021, PU:[55-60]","pl");
  leg_example->AddEntry(gr4, "2023, PU:[55-60]","pl");
  leg_example->AddEntry(gr2, "2024, PU:[55-60]","pl");
  leg_example->Draw("same");

  c1->SetGrid();
  c1->SaveAs("BarrelROC_cutbased_pt1_vertex.png");

  ////
  ///endcap
  ////

  
  TCanvas *c2 = new TCanvas("c2","eff", 200,10,600,400);

  TGraph *gr1_1 = new TGraph (n, x_Endcap_SigEff_run2_2018_pt1, y_Endcap_BkgRej_run2_2018_pt1);
  gr1_1->SetTitle("Electron ID ROC, DYtoEE(sig) and TTbar(bkg)");
  gr1_1->SetMarkerColor(2);
  gr1_1->SetLineColor(2);
  gr1_1->SetMarkerStyle(21);
  gr1_1->Draw("ALP");
  gr1_1->GetYaxis()->SetTitle("Background Efficiency");
  gr1_1->GetXaxis()->SetTitle("Signal Efficiency");
  gr1_1->GetHistogram()->SetMaximum(0.11);   // along                                                                                                             
  gr1_1->GetHistogram()->SetMinimum(0.00);  //   Y                                                                                                                 
  gr1_1->GetXaxis()->SetLimits(0.5,0.95);
  gr1_1->Write("EndcapEffRun2_2018_roc_vtx");

  TGraph *gr2_1 = new TGraph (n, x_Endcap_SigEff_run3_2024_pt1, y_Endcap_BkgRej_run3_2024_pt1);
  gr2_1->SetMarkerColor(4);
  gr2_1->SetLineColor(4);
  gr2_1->SetMarkerStyle(22);
  gr2_1->Draw("LP:SAME");
  gr2_1->Write("EndcapEffRun2_roc_vtx");

  TGraph *gr3_1 = new TGraph (n, x_Endcap_SigEff_run3_2021_pt1, y_Endcap_BkgRej_run3_2021_pt1);
  gr3_1->SetMarkerColor(3);
  gr3_1->SetLineColor(3);
  gr3_1->SetMarkerStyle(23);
  gr3_1->Draw("LP:SAME");
  gr3_1->Write("EndcapEffRun2_roc_vtx_2021");

  TGraph *gr4_1 = new TGraph (n, x_Endcap_SigEff_run3_2023_pt1, y_Endcap_BkgRej_run3_2023_pt1);
  gr4_1->SetMarkerColor(6);
  gr4_1->SetLineColor(6);
  gr4_1->SetMarkerStyle(25);
  gr4_1->Draw("LP:SAME");
  gr4_1->Write("EndcapEffRun2_roc_vtx_2021");

  TGraph *gr5_1 = new TGraph (n, x_Endcap_SigEff_run2_2018_pt1_lowpu, y_Endcap_BkgRej_run2_2018_pt1_lowpu);
  gr5_1->SetMarkerColor(1);
  gr5_1->SetLineColor(1);
  gr5_1->SetMarkerStyle(21);
  gr5_1->Draw("LP:SAME");
  gr5_1->Write("EndcapEffRun2_roc_vtx_2018_lowpu");

  TLegend *leg_example_1 = new TLegend(0.2,0.5,0.5,0.8);
  leg_example_1->SetHeader("Endcap","C"); // option "C" allows to center the header                                                             
  leg_example_1->SetFillColor(0);
  leg_example_1->SetTextFont(42);
  leg_example_1->SetBorderSize(0);
  leg_example_1->AddEntry(gr5_1, "2018, PU:[30-35]","pl");
  leg_example_1->AddEntry(gr1_1, "2018, PU:[55-60]","pl");
  leg_example_1->AddEntry(gr3_1, "2021, PU:[55-60]","pl");
  leg_example_1->AddEntry(gr4_1, "2023, PU:[55-60]","pl");
  leg_example_1->AddEntry(gr2_1, "2024, PU:[55-60]","pl");
  leg_example_1->Draw("same");

  c2->SetGrid();

  c2->SaveAs("EndcapROC_cutbased_pt1_vertex.png");
  ///



}
