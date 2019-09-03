#define BkgEff_cxx
#include "BkgEff.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <TH1.h>


void BkgEff::Loop()
{
  TFile *fout = new TFile("histo_bkgEff_for_roc.root","RECREATE");

  TH1F *pt_bkg_den_pu_55_to_60_barrel = new TH1F("den_55_60_barrel","bkg", 100,0,500);
  TH1F *pt_bkg_den_pu_30_to_35_barrel = new TH1F("den_30_35_barrel","bkg", 100,0,500);

  TH1F *pt_bkg_num_passingTight94XV2_pu_55_to_60_barrel = new TH1F("num_passingTight94XV2_pu_55_to_60_barrel","bkg", 100,0,500);
  TH1F *pt_bkg_num_passingMedium94XV2_pu_55_to_60_barrel = new TH1F("num_passingMedium94XV2_pu_55_to_60_barrel","bkg", 100,0,500);
  TH1F *pt_bkg_num_passingLoose94XV2_pu_55_to_60_barrel = new TH1F("num_passingLoose94XV2_pu_55_to_60_barrel","bkg", 100,0,500);
  TH1F *pt_bkg_num_passingVeto94XV2_pu_55_to_60_barrel = new TH1F("num_passingVeto94XV2_pu_55_to_60_barrel","bkg", 100,0,500);

  TH1F *pt_bkg_num_passingTight94XV2_pu_30_to_35_barrel = new TH1F("num_passingTight94XV2_pu_30_to_35_barrel","bkg", 100,0,500);
  TH1F *pt_bkg_num_passingMedium94XV2_pu_30_to_35_barrel = new TH1F("num_passingMedium94XV2_pu_30_to_35_barrel","bkg", 100,0,500);
  TH1F *pt_bkg_num_passingLoose94XV2_pu_30_to_35_barrel = new TH1F("num_passingLoose94XV2_pu_30_to_35_barrel","bkg", 100,0,500);
  TH1F *pt_bkg_num_passingVeto94XV2_pu_30_to_35_barrel = new TH1F("num_passingVeto94XV2_pu_30_to_35_barrel","bkg", 100,0,500);

  TH1F *pt_bkg_den_pu_55_to_60_endcap = new TH1F("den_55_60_endcap","bkg", 100,0,500);
  TH1F *pt_bkg_den_pu_30_to_35_endcap = new TH1F("den_30_35_endcap","bkg", 100,0,500);

  TH1F *pt_bkg_num_passingTight94XV2_pu_55_to_60_endcap = new TH1F("num_passingTight94XV2_pu_55_to_60_endcap","bkg", 100,0,500);
  TH1F *pt_bkg_num_passingMedium94XV2_pu_55_to_60_endcap = new TH1F("num_passingMedium94XV2_pu_55_to_60_endcap","bkg", 100,0,500);
  TH1F *pt_bkg_num_passingLoose94XV2_pu_55_to_60_endcap = new TH1F("num_passingLoose94XV2_pu_55_to_60_endcap","bkg", 100,0,500);
  TH1F *pt_bkg_num_passingVeto94XV2_pu_55_to_60_endcap = new TH1F("num_passingVeto94XV2_pu_55_to_60_endcap","bkg", 100,0,500);

  TH1F *pt_bkg_num_passingTight94XV2_pu_30_to_35_endcap = new TH1F("num_passingTight94XV2_pu_30_to_35_endcap","bkg", 100,0,500);
  TH1F *pt_bkg_num_passingMedium94XV2_pu_30_to_35_endcap = new TH1F("num_passingMedium94XV2_pu_30_to_35_endcap","bkg", 100,0,500);
  TH1F *pt_bkg_num_passingLoose94XV2_pu_30_to_35_endcap = new TH1F("num_passingLoose94XV2_pu_30_to_35_endcap","bkg", 100,0,500);
  TH1F *pt_bkg_num_passingVeto94XV2_pu_30_to_35_endcap = new TH1F("num_passingVeto94XV2_pu_30_to_35_endcap","bkg", 100,0,500);

//   In a ROOT session, you can do:
//      root> .L BkgEff.C
//      root> BkgEff t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;
   std::cout << &fChain << std::endl;
   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
     // std::cout << "\nEvt " << jentry << std::endl;
     Long64_t ientry = LoadTree(jentry);
     if (ientry < 0) break;
     nb = fChain->GetEntry(jentry);   nbytes += nb;
     // if (Cut(ientry) < 0) continue;
     
  
     //Denominator barrel 55-60
     if ( (el_et>30) && (fabs(el_sc_eta)<1.4) && (truePU>=55) && (truePU<60) && (mcTrue==0) ) {
       pt_bkg_den_pu_55_to_60_barrel->Fill(el_et);
       //Numerator barrel 55-60
       if (passingTight94XV2==1) pt_bkg_num_passingTight94XV2_pu_55_to_60_barrel->Fill(el_et);
       if (passingMedium94XV2==1) pt_bkg_num_passingMedium94XV2_pu_55_to_60_barrel->Fill(el_et);
       if (passingLoose94XV2==1) pt_bkg_num_passingLoose94XV2_pu_55_to_60_barrel->Fill(el_et);
       if (passingVeto94XV2==1) pt_bkg_num_passingVeto94XV2_pu_55_to_60_barrel->Fill(el_et);	 
     }

     //Denominator endcap 55-60
     if ( (el_et>30) && (fabs(el_sc_eta)<2.5) && (fabs(el_sc_eta)>1.4) && (truePU>=55) && (truePU<60) && (mcTrue==0) ) {
       pt_bkg_den_pu_55_to_60_endcap->Fill(el_et);
       //Numerator endcap 55-60
       if (passingTight94XV2==1) pt_bkg_num_passingTight94XV2_pu_55_to_60_endcap->Fill(el_et);
       if (passingMedium94XV2==1) pt_bkg_num_passingMedium94XV2_pu_55_to_60_endcap->Fill(el_et);
       if (passingLoose94XV2==1) pt_bkg_num_passingLoose94XV2_pu_55_to_60_endcap->Fill(el_et);
       if (passingVeto94XV2==1) pt_bkg_num_passingVeto94XV2_pu_55_to_60_endcap->Fill(el_et);	 
     }


     //Denominator barrel 30-35
     if ( (el_et>30) && (fabs(el_sc_eta)<1.4) && (truePU>=30) && (truePU<35) && (mcTrue==0) ) {
       pt_bkg_den_pu_30_to_35_barrel->Fill(el_et);
       //Numerator barrel 30-35
       if (passingTight94XV2==1) pt_bkg_num_passingTight94XV2_pu_30_to_35_barrel->Fill(el_et);
       if (passingMedium94XV2==1) pt_bkg_num_passingMedium94XV2_pu_30_to_35_barrel->Fill(el_et);
       if (passingLoose94XV2==1) pt_bkg_num_passingLoose94XV2_pu_30_to_35_barrel->Fill(el_et);
       if (passingVeto94XV2==1) pt_bkg_num_passingVeto94XV2_pu_30_to_35_barrel->Fill(el_et);	 
     }

     //Denominator endcap 30-35
     if ( (el_et>30) && (fabs(el_sc_eta)<2.5) && (fabs(el_sc_eta)>1.4) && (truePU>=30) && (truePU<35) && (mcTrue==0) ) {
       pt_bkg_den_pu_30_to_35_endcap->Fill(el_et);
       //Numerator endcap 30-35
       if (passingTight94XV2==1) pt_bkg_num_passingTight94XV2_pu_30_to_35_endcap->Fill(el_et);
       if (passingMedium94XV2==1) pt_bkg_num_passingMedium94XV2_pu_30_to_35_endcap->Fill(el_et);
       if (passingLoose94XV2==1) pt_bkg_num_passingLoose94XV2_pu_30_to_35_endcap->Fill(el_et);
       if (passingVeto94XV2==1) pt_bkg_num_passingVeto94XV2_pu_30_to_35_endcap->Fill(el_et);	 
     }



     // }
   }

   fout->cd();

   pt_bkg_den_pu_55_to_60_barrel->Write();
   pt_bkg_den_pu_30_to_35_barrel->Write();
   pt_bkg_num_passingTight94XV2_pu_55_to_60_barrel->Write();
   pt_bkg_num_passingMedium94XV2_pu_55_to_60_barrel->Write();
   pt_bkg_num_passingLoose94XV2_pu_55_to_60_barrel->Write();
   pt_bkg_num_passingVeto94XV2_pu_55_to_60_barrel->Write();
   pt_bkg_num_passingTight94XV2_pu_30_to_35_barrel->Write();
   pt_bkg_num_passingMedium94XV2_pu_30_to_35_barrel->Write();
   pt_bkg_num_passingLoose94XV2_pu_30_to_35_barrel->Write();
   pt_bkg_num_passingVeto94XV2_pu_30_to_35_barrel->Write();
   pt_bkg_den_pu_55_to_60_endcap->Write();
   pt_bkg_den_pu_30_to_35_endcap->Write();
   pt_bkg_num_passingTight94XV2_pu_55_to_60_endcap->Write();
   pt_bkg_num_passingMedium94XV2_pu_55_to_60_endcap->Write();
   pt_bkg_num_passingLoose94XV2_pu_55_to_60_endcap->Write();
   pt_bkg_num_passingVeto94XV2_pu_55_to_60_endcap->Write();
   pt_bkg_num_passingTight94XV2_pu_30_to_35_endcap->Write();
   pt_bkg_num_passingMedium94XV2_pu_30_to_35_endcap->Write();
   pt_bkg_num_passingLoose94XV2_pu_30_to_35_endcap->Write();
   pt_bkg_num_passingVeto94XV2_pu_30_to_35_endcap->Write();

   /*
   pt_bkg_den_pu_55_to_60_barrel->Draw();
   pt_bkg_den_pu_30_to_35_barrel->Draw();
   pt_bkg_num_passingTight94XV2_pu_55_to_60_barrel->Draw();
   pt_bkg_num_passingMedium94XV2_pu_55_to_60_barrel->Draw();
   pt_bkg_num_passingLoose94XV2_pu_55_to_60_barrel->Draw();
   pt_bkg_num_passingVeto94XV2_pu_55_to_60_barrel->Draw();
   pt_bkg_num_passingTight94XV2_pu_30_to_35_barrel->Draw();
   pt_bkg_num_passingMedium94XV2_pu_30_to_35_barrel->Draw();
   pt_bkg_num_passingLoose94XV2_pu_30_to_35_barrel->Draw();
   pt_bkg_num_passingVeto94XV2_pu_30_to_35_barrel->Draw();
   pt_bkg_den_pu_55_to_60_endcap->Draw();
   pt_bkg_den_pu_30_to_35_endcap->Draw();
   pt_bkg_num_passingTight94XV2_pu_55_to_60_endcap->Draw();
   pt_bkg_num_passingMedium94XV2_pu_55_to_60_endcap->Draw();
   pt_bkg_num_passingLoose94XV2_pu_55_to_60_endcap->Draw();
   pt_bkg_num_passingVeto94XV2_pu_55_to_60_endcap->Draw();
   pt_bkg_num_passingTight94XV2_pu_30_to_35_endcap->Draw();
   pt_bkg_num_passingMedium94XV2_pu_30_to_35_endcap->Draw();
   pt_bkg_num_passingLoose94XV2_pu_30_to_35_endcap->Draw();
   pt_bkg_num_passingVeto94XV2_pu_30_to_35_endcap->Draw();
   */
   //   fout->Write();

   std::cout << "--- Barrel --- [55-60] \n" ;
   std::cout << "passingTight94XV2 " << pt_bkg_num_passingTight94XV2_pu_55_to_60_barrel->GetEntries()/pt_bkg_den_pu_55_to_60_barrel->GetEntries() << std::endl;
   std::cout << "passingMedium94XV2 " << pt_bkg_num_passingMedium94XV2_pu_55_to_60_barrel->GetEntries()/pt_bkg_den_pu_55_to_60_barrel->GetEntries() << std::endl;
   std::cout << "passingLoose94XV2 " << pt_bkg_num_passingLoose94XV2_pu_55_to_60_barrel->GetEntries()/pt_bkg_den_pu_55_to_60_barrel->GetEntries() << std::endl;
   std::cout << "passingVeto94XV2 " << pt_bkg_num_passingVeto94XV2_pu_55_to_60_barrel->GetEntries()/pt_bkg_den_pu_55_to_60_barrel->GetEntries() << std::endl;

   std::cout << "\n--- Endcap --- [55-60] \n" ;
   std::cout << "passingTight94XV2 " << pt_bkg_num_passingTight94XV2_pu_55_to_60_endcap->GetEntries()/pt_bkg_den_pu_55_to_60_endcap->GetEntries() << std::endl;
   std::cout << "passingMedium94XV2 " << pt_bkg_num_passingMedium94XV2_pu_55_to_60_endcap->GetEntries()/pt_bkg_den_pu_55_to_60_endcap->GetEntries() << std::endl;
   std::cout << "passingLoose94XV2 " << pt_bkg_num_passingLoose94XV2_pu_55_to_60_endcap->GetEntries()/pt_bkg_den_pu_55_to_60_endcap->GetEntries() << std::endl;
   std::cout << "passingVeto94XV2 " << pt_bkg_num_passingVeto94XV2_pu_55_to_60_endcap->GetEntries()/pt_bkg_den_pu_55_to_60_endcap->GetEntries() << std::endl;

   std::cout << "\n--- Barrel --- [30-35] \n" ;
   std::cout << "passingTight94XV2 " << pt_bkg_num_passingTight94XV2_pu_30_to_35_barrel->GetEntries()/pt_bkg_den_pu_30_to_35_barrel->GetEntries() << std::endl;
   std::cout << "passingMedium94XV2 " << pt_bkg_num_passingMedium94XV2_pu_30_to_35_barrel->GetEntries()/pt_bkg_den_pu_30_to_35_barrel->GetEntries() << std::endl;
   std::cout << "passingLoose94XV2 " << pt_bkg_num_passingLoose94XV2_pu_30_to_35_barrel->GetEntries()/pt_bkg_den_pu_30_to_35_barrel->GetEntries() << std::endl;
   std::cout << "passingVeto94XV2 " << pt_bkg_num_passingVeto94XV2_pu_30_to_35_barrel->GetEntries()/pt_bkg_den_pu_30_to_35_barrel->GetEntries() << std::endl;

   std::cout << "\n--- Endcap --- [30-35] \n" ;
   std::cout << "passingTight94XV2 " << pt_bkg_num_passingTight94XV2_pu_30_to_35_endcap->GetEntries()/pt_bkg_den_pu_30_to_35_endcap->GetEntries() << std::endl;
   std::cout << "passingMedium94XV2 " << pt_bkg_num_passingMedium94XV2_pu_30_to_35_endcap->GetEntries()/pt_bkg_den_pu_30_to_35_endcap->GetEntries() << std::endl;
   std::cout << "passingLoose94XV2 " << pt_bkg_num_passingLoose94XV2_pu_30_to_35_endcap->GetEntries()/pt_bkg_den_pu_30_to_35_endcap->GetEntries() << std::endl;
   std::cout << "passingVeto94XV2 " << pt_bkg_num_passingVeto94XV2_pu_30_to_35_endcap->GetEntries()/pt_bkg_den_pu_30_to_35_endcap->GetEntries() << std::endl;

   fout->Close();

}
