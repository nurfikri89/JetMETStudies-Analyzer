#define NanoV12Selector_cxx
// The class definition in NanoV12Selector.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.


// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// root> T->Process("NanoV12Selector.C")
// root> T->Process("NanoV12Selector.C","some options")
// root> T->Process("NanoV12Selector.C+")
//


#include "NanoV12Selector.h"
#include <TH2.h>
#include <TStyle.h>
#include <Math/Vector4D.h>

void NanoV12Selector::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
}

void NanoV12Selector::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

   m_histosMap["h_LHE_HT_unWeight"]   = new TH1D("h_LHE_HT_unWeight",      ";LHE HT [GeV]",  14000, 0., 14000.);
   m_histosMap["h_LHE_HT_genWeight"]  = new TH1D("h_LHE_HT_genWeight",     ";LHE HT [GeV]",  14000, 0., 14000.);
   m_histosMap["h_LHE_HT_normWeight"] = new TH1D("h_LHE_HT_normWeight",    ";LHE HT [GeV]",  14000, 0., 14000.);
   m_histosMap["h_LHE_HT_eventWeight"] = new TH1D("h_LHE_HT_eventWeight",  ";LHE HT [GeV]",  14000, 0., 14000.);

   m_histosMap["h_genjet0_pt"]   = new TH1D("h_genjet0_pt",  ";Leading AK4 GenJet pT [GeV]", 700,  0., 7000.);
   m_histosMap["h_genjet0_eta"]  = new TH1D("h_genjet0_eta", ";Leading AK4 GenJet Eta",      600, -6.,    6.);
   m_histosMap["h_genjet0_phi"]  = new TH1D("h_genjet0_phi", ";Leading AK4 GenJet Phi",      400, -4.,    4.);
   m_histosMap["h_genjet0_mass"] = new TH1D("h_genjet0_mass", ";Leading AK4 GenJet Mass [GeV]", 600,  0., 600.);

   m_histosMap["h_genjet1_pt"]   = new TH1D("h_genjet1_pt",  ";Sub-Leading AK4 GenJet pT [GeV]", 700,  0., 7000.);
   m_histosMap["h_genjet1_eta"]  = new TH1D("h_genjet1_eta", ";Sub-Leading AK4 GenJet Eta",      600, -6.,    6.);
   m_histosMap["h_genjet1_phi"]  = new TH1D("h_genjet1_phi", ";Sub-Leading AK4 GenJet Phi",      400, -4.,    4.);
   m_histosMap["h_genjet1_mass"] = new TH1D("h_genjet1_mass",";Sub-Leading AK4 GenJet Mass [GeV]", 600,  0., 600.);

   m_histosMap["h_gen_mjj"]  = new TH1D("h_gen_mjj",  ";Gen mjj [GeV]", 700,  0., 7000.);

   m_histosMap["h_log_genWeight"] = new TH1D("h_log_genWeight",  "log(genWeight)",  2000, 0., 20.);


   for ( auto h = m_histosMap.begin(); h != m_histosMap.end(); h++){
      GetOutputList()->Add(h->second);
   }
}

Bool_t NanoV12Selector::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // When processing keyed objects with PROOF, the object is already loaded
   // and is available via the fObject pointer.
   //
   // This function should contain the \"body\" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.

   fReader.SetLocalEntry(entry);

   float normWeight  = m_xsec/m_sumW;
   float eventWeight = (*genWeight) * normWeight;

   m_histosMap["h_LHE_HT_unWeight"]    ->Fill(*LHE_HT);
   m_histosMap["h_LHE_HT_genWeight"]   ->Fill(*LHE_HT, *genWeight);
   m_histosMap["h_LHE_HT_normWeight"]  ->Fill(*LHE_HT, normWeight);
   m_histosMap["h_LHE_HT_eventWeight"] ->Fill(*LHE_HT, eventWeight);
   if (*nGenJet >= 1){
      m_histosMap["h_genjet0_pt"]->Fill(GenJet_pt[0],   eventWeight);
      m_histosMap["h_genjet0_eta"]->Fill(GenJet_eta[0], eventWeight);
      m_histosMap["h_genjet0_phi"]->Fill(GenJet_phi[0], eventWeight);
      m_histosMap["h_genjet0_mass"]->Fill(GenJet_mass[0], eventWeight);
   }
   if(*nGenJet >= 2){
      m_histosMap["h_genjet1_pt"]->Fill(GenJet_pt[1],   eventWeight);
      m_histosMap["h_genjet1_eta"]->Fill(GenJet_eta[1], eventWeight);
      m_histosMap["h_genjet1_phi"]->Fill(GenJet_phi[1], eventWeight);
      m_histosMap["h_genjet1_mass"]->Fill(GenJet_mass[1], eventWeight);
      ROOT::Math::PtEtaPhiMVector genjet0_p4 = ROOT::Math::PtEtaPhiMVector(GenJet_pt[0],GenJet_eta[0],GenJet_phi[0],GenJet_mass[0]);
      ROOT::Math::PtEtaPhiMVector genjet1_p4 = ROOT::Math::PtEtaPhiMVector(GenJet_pt[1],GenJet_eta[1],GenJet_phi[1],GenJet_mass[1]);
      auto jj_p4 = genjet0_p4+genjet1_p4;
      m_histosMap["h_gen_mjj"]->Fill(jj_p4.M(), eventWeight);
   }
   m_histosMap["h_log_genWeight"]->Fill(log10(*genWeight));

   return kTRUE;
}

void NanoV12Selector::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void NanoV12Selector::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.
  TFile* m_outHistoFile = new TFile("./histos/Histos_"+m_sampleName+".root","RECREATE");
  m_outHistoFile->cd("");
  for ( auto h = m_histosMap.begin(); h != m_histosMap.end(); h++){
    h->second->Write();
  }
  m_outHistoFile->Close();

}