#define AnaPhysDef_cxx
// The class definition in AnaPhysDef.h has been generated automatically
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
// root> T->Process("AnaPhysDef.C")
// root> T->Process("AnaPhysDef.C","some options")
// root> T->Process("AnaPhysDef.C+")
//
#include "AnaPhysDef.h"
using namespace ROOT::VecOps;
#include <TH2.h>
#include <TStyle.h>

template<typename T>
struct extract_type {
  using type = typename T::Type;
};

void AnaPhysDef::Begin(TTree * /*tree*/)
{
  // The Begin() function is called at the start of the query.
  // When running with PROOF Begin() is only called on the client.
  // The tree argument is deprecated (on PROOF 0 is passed).

  TString option = GetOption();
}

void AnaPhysDef::SlaveBegin(TTree * /*tree*/)
{
  // The SlaveBegin() function is called after the Begin() function.
  // When running with PROOF SlaveBegin() is called on each slave server.
  // The tree argument is deprecated (on PROOF 0 is passed).

  TString option = GetOption();

  m_histosMap["h_nevents"] = new TH1D("h_nevents","",  10, 0, 10);
  m_histosMap["h_njets"] = new TH1D("h_njets", "", 20, 0, 20);

  std::vector<TString> ptBinStrVec = {
    "pt20ToInf",
    "pt20To50",
    "pt50To100",
    "pt100To150",
    "pt150To200",
    "pt200To300",
    "pt300ToInf",
  };
  std::vector<TString> jetTypeStrVec = {
    "quarkjet",
    "gluonjet",
    "undefjet",
    "others",
  };

  m_histosMap["h_jet_pt"] = new TH1D("h_jet_pt","",   50,  0., 500.);
  m_histosMap["h_jet_eta"] = new TH1D("h_jet_eta","", 60, -6., 6.);

  for(auto& jetTypeStr : jetTypeStrVec){
    for(auto& ptBinStr : ptBinStrVec){
      m_histosMap["h_"+ptBinStr+"_"+jetTypeStr+"_pt"] = new TH1D("h_"+ptBinStr+"_"+jetTypeStr+"_pt","",  40, 0., 400.);
      m_histosMap["h_"+ptBinStr+"_"+jetTypeStr+"_eta"] = new TH1D("h_"+ptBinStr+"_"+jetTypeStr+"_eta","", 60, -6., 6.);
      m_histosMap["h_"+ptBinStr+"_"+jetTypeStr+"_qgl_ptD"]  = new TH1D("h_"+ptBinStr+"_"+jetTypeStr+"_qgl_ptD","",  100, 0., 1.);
      m_histosMap["h_"+ptBinStr+"_"+jetTypeStr+"_qgl_axis"] = new TH1D("h_"+ptBinStr+"_"+jetTypeStr+"_qgl_axis","", 50, 0., 0.2);
      m_histosMap["h_"+ptBinStr+"_"+jetTypeStr+"_qgl_mult"] = new TH1D("h_"+ptBinStr+"_"+jetTypeStr+"_qgl_mult","", 40, 0, 40);
      m_histosMap["h_"+ptBinStr+"_"+jetTypeStr+"_qgl_mult_v2"] = new TH1D("h_"+ptBinStr+"_"+jetTypeStr+"_qgl_mult_v2","", 80, 0, 80);
    }
  }


  for ( auto h = m_histosMap.begin(); h != m_histosMap.end(); h++){
   GetOutputList()->Add(h->second);
  }
}


Bool_t AnaPhysDef::Process(Long64_t entry)
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

  float eventWeight = *genWeight;

  m_histosMap["h_nevents"]->Fill(1,eventWeight);
  // using ObjTypeJetArea = typename std::decay<decltype(Jet_area)>::type;
  // RVec<ObjTypeJetArea> rv_Jet_area;
  // RVec<typename std::decay<decltype(Jet_area)>::type> rv_Jet_area;
  // using ParameterType = typename extract_type<decltype(Muon_pt)>::type;
  // RVec<ParameterType> rv_SelectedMuon_pt;

  size_t nSelectedMuon = 0;
  RVec<Float_t> rv_SelectedMuon_pt;
  RVec<Float_t> rv_SelectedMuon_eta;
  RVec<Float_t> rv_SelectedMuon_phi;

  size_t nSelectedPhoton = 0;
  RVec<Float_t> rv_SelectedPhoton_pt;
  RVec<Float_t> rv_SelectedPhoton_eta;
  RVec<Float_t> rv_SelectedPhoton_phi;

  if (m_doAnaZPlusJets){
    auto rv_Muon_pt      = MakeRVec(Muon_pt);
    auto rv_Muon_eta     = MakeRVec(Muon_eta);
    auto rv_Muon_phi     = MakeRVec(Muon_phi);
    auto rv_Muon_looseId = MakeRVec(Muon_looseId);

    //
    // https://root.cern/doc/master/vo006__IndexManipulation_8C.html
    //
    auto rv_Muon_IdxSortByPt =  Reverse(Argsort(rv_Muon_pt));
    auto rv_Muon_IdxSelect = Nonzero(rv_Muon_pt > 20.f && abs(rv_Muon_eta) < 2.5f && rv_Muon_looseId == true);
    // Get indices sorted by pt and
    auto rv_Muon_IdxSortSelect =  Intersect(rv_Muon_IdxSortByPt, rv_Muon_IdxSelect);

    nSelectedMuon = rv_Muon_IdxSortSelect.size();
    rv_SelectedMuon_pt  = Take(rv_Muon_pt,  rv_Muon_IdxSortSelect);
    rv_SelectedMuon_eta = Take(rv_Muon_eta, rv_Muon_IdxSortSelect);
    rv_SelectedMuon_phi = Take(rv_Muon_phi, rv_Muon_IdxSortSelect);

    if (nSelectedMuon != 2) return kTRUE;
  }
  else if (m_doAnaPhotonPlusJets){
    auto rv_Photon_pt      = MakeRVec(Photon_pt);
    auto rv_Photon_eta     = MakeRVec(Photon_eta);
    auto rv_Photon_phi     = MakeRVec(Photon_phi);
    auto rv_Photon_cutBased = MakeRVec(Photon_cutBased);

    auto rv_Photon_IdxSelect = Nonzero(rv_Photon_pt > 20.f && abs(rv_Photon_eta) < 2.5f && rv_Photon_cutBased >= 3);
    nSelectedPhoton = rv_Photon_IdxSelect.size();
    rv_SelectedPhoton_pt  = Take(rv_Photon_pt,  rv_Photon_IdxSelect);
    rv_SelectedPhoton_eta = Take(rv_Photon_eta, rv_Photon_IdxSelect);
    rv_SelectedPhoton_phi = Take(rv_Photon_phi, rv_Photon_IdxSelect);

    if (nSelectedPhoton != 1) return kTRUE;
  }

  m_histosMap["h_nevents"]->Fill(2,eventWeight);

  auto rv_Jet_pt   = MakeRVec(Jet_pt);
  auto rv_Jet_eta  = MakeRVec(Jet_eta);
  auto rv_Jet_phi  = MakeRVec(Jet_phi);
  auto rv_Jet_mass = MakeRVec(Jet_mass);
  auto rv_Jet_jetId = MakeRVec(Jet_jetId);
  auto rv_Jet_qgl_ptD    = MakeRVec(Jet_qgl_ptD);
  auto rv_Jet_qgl_axis2  = MakeRVec(Jet_qgl_axis2);
  auto rv_Jet_qgl_mult   = MakeRVec(Jet_qgl_mult);
  auto rv_Jet_genJetIdx  = MakeRVec(Jet_genJetIdx);
  auto rv_Jet_partonFlavour = MakeRVec(Jet_partonFlavour);

  //
  // Assume all jets does not overlap with anything first, the clean them with the "tag" objects for Z+jets and Photosn
  //
  RVec<Bool_t> rv_Jet_isClean(*nJet, true);

  if (m_doAnaZPlusJets){
    auto rv_Jet_Muon0Clean = DeltaR(rv_Jet_eta, RVec(rv_Jet_eta.size(),rv_SelectedMuon_eta[0]), rv_Jet_phi, RVec(rv_Jet_phi.size(),rv_SelectedMuon_phi[0])) > 0.4;
    auto rv_Jet_Muon1Clean = DeltaR(rv_Jet_eta, RVec(rv_Jet_eta.size(),rv_SelectedMuon_eta[1]), rv_Jet_phi, RVec(rv_Jet_phi.size(),rv_SelectedMuon_phi[1])) > 0.4;
    rv_Jet_isClean = rv_Jet_Muon0Clean && rv_Jet_Muon1Clean;
  } else if (m_doAnaPhotonPlusJets){
    auto rv_Jet_Photon0Clean = DeltaR(rv_Jet_eta, RVec(rv_Jet_eta.size(),rv_SelectedPhoton_eta[0]), rv_Jet_phi, RVec(rv_Jet_phi.size(),rv_SelectedPhoton_phi[0])) > 0.4;
    rv_Jet_isClean = rv_Jet_Photon0Clean;
  }

  //
  // pt > 20, passes jetId, does not overlap with the two leptons, matched to a genJet.
  //
  auto rv_Jet_isSignal = rv_Jet_pt > 20.f && (rv_Jet_jetId & (1<<1)) && rv_Jet_isClean && rv_Jet_genJetIdx > -1;
  auto rv_Jet_IdxSelectSignal = Nonzero(rv_Jet_isSignal);

  // for (std::size_t i=0; i < rv_Jet_isClean.size(); i++){
  //   std::cout << rv_Jet_isClean[i] << std::endl;
  // }

  //
  //
  //
  auto rv_SignalJet_pt = Take(rv_Jet_pt, rv_Jet_IdxSelectSignal);
  auto rv_SignalJet_eta = Take(rv_Jet_eta, rv_Jet_IdxSelectSignal);
  auto rv_SignalJet_phi = Take(rv_Jet_phi, rv_Jet_IdxSelectSignal);
  auto rv_SignalJet_mass = Take(rv_Jet_mass, rv_Jet_IdxSelectSignal);
  auto rv_SignalJet_partonFlavour = Take(rv_Jet_partonFlavour, rv_Jet_IdxSelectSignal);

  auto rv_SignalJet_qgl_ptD    = Take(rv_Jet_qgl_ptD,  rv_Jet_IdxSelectSignal);
  auto rv_SignalJet_qgl_axis2  = Take(rv_Jet_qgl_axis2, rv_Jet_IdxSelectSignal);
  auto rv_SignalJet_qgl_mult   = Take(rv_Jet_qgl_mult, rv_Jet_IdxSelectSignal);

  auto rv_SignalJet_isCentral = rv_SignalJet_eta > -2.0 && rv_SignalJet_eta < 2.0;

  m_histosMap["h_njets"]->Fill(rv_SignalJet_pt.size(),eventWeight);

  for (std::size_t i=0; i < rv_SignalJet_pt.size(); i++){
    if (!rv_SignalJet_isCentral[i]) continue;

    m_histosMap["h_jet_pt"]->Fill(rv_SignalJet_pt[i],eventWeight);
    m_histosMap["h_jet_eta"]->Fill(rv_SignalJet_eta[i],eventWeight);

    TString jetTypeStr("others");
    if (abs(rv_SignalJet_partonFlavour[i]) >= 1 && abs(rv_SignalJet_partonFlavour[i]) <= 5) jetTypeStr = "quarkjet";
    else if (rv_SignalJet_partonFlavour[i] == 21) jetTypeStr = "gluonjet";
    else if (rv_SignalJet_partonFlavour[i] == 0) jetTypeStr = "undefjet";

    TString ptBinStr("pt20To50");
    if (rv_SignalJet_pt[i] >= 20.f && rv_SignalJet_pt[i] < 50.f)        ptBinStr = "pt20To50";
    else if (rv_SignalJet_pt[i] >= 50.f && rv_SignalJet_pt[i] < 100.f)  ptBinStr = "pt50To100";
    else if (rv_SignalJet_pt[i] >= 100.f && rv_SignalJet_pt[i] < 150.f) ptBinStr = "pt100To150";
    else if (rv_SignalJet_pt[i] >= 150.f && rv_SignalJet_pt[i] < 200.f) ptBinStr = "pt150To200";
    else if (rv_SignalJet_pt[i] >= 200.f && rv_SignalJet_pt[i] < 300.f) ptBinStr = "pt200To300";
    else if (rv_SignalJet_pt[i] >= 300.f) ptBinStr = "pt300ToInf";

    m_histosMap["h_pt20ToInf_"+jetTypeStr+"_pt"]->Fill(rv_SignalJet_pt[i],eventWeight);
    m_histosMap["h_pt20ToInf_"+jetTypeStr+"_eta"]->Fill(rv_SignalJet_eta[i],eventWeight);
    m_histosMap["h_pt20ToInf_"+jetTypeStr+"_qgl_ptD"] ->Fill(rv_SignalJet_qgl_ptD[i],eventWeight);
    m_histosMap["h_pt20ToInf_"+jetTypeStr+"_qgl_axis"]->Fill(rv_SignalJet_qgl_axis2[i],eventWeight);
    m_histosMap["h_pt20ToInf_"+jetTypeStr+"_qgl_mult"]->Fill(rv_SignalJet_qgl_mult[i],eventWeight);
    m_histosMap["h_pt20ToInf_"+jetTypeStr+"_qgl_mult_v2"]->Fill(rv_SignalJet_qgl_mult[i],eventWeight);

    m_histosMap["h_"+ptBinStr+"_"+jetTypeStr+"_pt"]->Fill(rv_SignalJet_pt[i],eventWeight);
    m_histosMap["h_"+ptBinStr+"_"+jetTypeStr+"_eta"]->Fill(rv_SignalJet_eta[i],eventWeight);
    m_histosMap["h_"+ptBinStr+"_"+jetTypeStr+"_qgl_ptD"] ->Fill(rv_SignalJet_qgl_ptD[i],eventWeight);
    m_histosMap["h_"+ptBinStr+"_"+jetTypeStr+"_qgl_axis"]->Fill(rv_SignalJet_qgl_axis2[i],eventWeight);
    m_histosMap["h_"+ptBinStr+"_"+jetTypeStr+"_qgl_mult"]->Fill(rv_SignalJet_qgl_mult[i],eventWeight);
    m_histosMap["h_"+ptBinStr+"_"+jetTypeStr+"_qgl_mult_v2"]->Fill(rv_SignalJet_qgl_mult[i],eventWeight);
  }
  return kTRUE;
}


void AnaPhysDef::SlaveTerminate(){
  // The SlaveTerminate() function is called after all entries or objects
  // have been processed. When running with PROOF SlaveTerminate() is called
  // on each slave server.
}

void AnaPhysDef::Terminate()
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