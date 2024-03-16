#include "ROOT/RVec.hxx"

using namespace ROOT::VecOps;

// bool sort_from_highest(float x, float y){
//   return x > y;
// }

template<typename T> RVec<T> MakeRVec(TTreeReaderArray<T>& tta){
  return RVec<T>(tta.begin(),tta.end());
}

// RVec<int> IsOverlap(const RVec<float>& rv_eta, const RVec<float>& rv_phi, float& eta, float>& phi, float max=0.8)
// {
//   RVec<int> rvec_overlap(objs.size());
//   for (size_t i = 0; i < objs.size(); i++) {
//     rvec_overlap[i] = VectorUtil::DeltaR(objs[i],ref) < max;
//   }
//   return rvec_overlap;
// }

void Test(){
  TFile* inFile = TFile::Open("root://xrootd-cms.infn.it///store/mc/RunIISummer20UL18NanoAODv9/DY4JetsToLL_M-50_MatchEWPDG20_TuneCP5_13TeV-madgraphMLM-pythia8/NANOAODSIM/20UL18JMENano_106X_upgrade2018_realistic_v16_L1v1-v1/230000/138FD238-DEF4-CD4F-9706-E44C74842773.root");
  // TChain tree("Events");
  // tree.Add(inFile)

  TTreeReader fReader("Events",inFile);  //!the tree reader
  TTreeReaderValue<UInt_t> nMuon = {fReader, "nMuon"};
  TTreeReaderArray<Float_t> Muon_pt   = {fReader, "Muon_pt"};
  TTreeReaderArray<Float_t> Muon_eta  = {fReader, "Muon_eta"};
  TTreeReaderArray<Float_t> Muon_phi  = {fReader, "Muon_phi"};
  TTreeReaderArray<Float_t> Muon_mass = {fReader, "Muon_mass"};
  TTreeReaderArray<Bool_t> Muon_looseId = {fReader, "Muon_looseId"};

  TTreeReaderValue<UInt_t> nJet = {fReader, "nJet"};
  TTreeReaderArray<Float_t> Jet_pt = {fReader, "Jet_pt"};
  TTreeReaderArray<Float_t> Jet_eta = {fReader, "Jet_eta"};
  TTreeReaderArray<Float_t> Jet_phi = {fReader, "Jet_phi"};
  TTreeReaderArray<Float_t> Jet_mass = {fReader, "Jet_mass"};
  TTreeReaderArray<Int_t>   Jet_jetId = {fReader, "Jet_jetId"};
  TTreeReaderArray<Int_t> Jet_genJetIdx = {fReader, "Jet_genJetIdx"};
  TTreeReaderArray<Int_t> Jet_hadronFlavour = {fReader, "Jet_hadronFlavour"};
  TTreeReaderArray<Int_t> Jet_partonFlavour = {fReader, "Jet_partonFlavour"};
  TTreeReaderArray<Float_t> Jet_qgl_ptD = {fReader, "Jet_qgl_ptD"};
  TTreeReaderArray<Float_t> Jet_qgl_axis2 = {fReader, "Jet_qgl_axis2"};
  TTreeReaderArray<Int_t> Jet_qgl_mult = {fReader, "Jet_qgl_mult"};

  auto nEvents = fReader.GetTree()->GetEntries();

  TFile* outHistoFile = new TFile("./Histos.root","RECREATE");

  std::map<string, TH1D*> histosMap;
  histosMap["h_quarkjet_qgl_ptD"] = new TH1D("h_quarkjet_qgl_ptD","",   20, 0., 1.);
  histosMap["h_gluonjet_qgl_ptD"] = new TH1D("h_gluonjet_qgl_ptD","",   20, 0., 1.);
  histosMap["h_undefjet_qgl_ptD"] = new TH1D("h_undefjet_qgl_ptD","",   20, 0., 1.);

  histosMap["h_quarkjet_qgl_axis"] = new TH1D("h_quarkjet_qgl_axis","", 50, 0., 0.5);
  histosMap["h_gluonjet_qgl_axis"] = new TH1D("h_gluonjet_qgl_axis","", 50, 0., 0.5);
  histosMap["h_undefjet_qgl_axis"] = new TH1D("h_undefjet_qgl_axis","", 50, 0., 0.5);

  histosMap["h_quarkjet_qgl_mult"] = new TH1D("h_quarkjet_qgl_mult","", 40, 0, 80);
  histosMap["h_gluonjet_qgl_mult"] = new TH1D("h_gluonjet_qgl_mult","", 40, 0, 80);
  histosMap["h_undefjet_qgl_mult"] = new TH1D("h_undefjet_qgl_mult","", 40, 0, 80);
  for(auto iEvt=0; iEvt < nEvents; iEvt++){
    fReader.SetEntry(iEvt);

    if(iEvt%1000 == 0) cout << iEvt << endl;

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

    auto nSelectedMuon     = rv_Muon_IdxSortSelect.size();
    auto rv_SelectedMuon_pt   = Take(rv_Muon_pt,  rv_Muon_IdxSortSelect);
    auto rv_SelectedMuon_eta  = Take(rv_Muon_eta, rv_Muon_IdxSortSelect);
    auto rv_SelectedMuon_phi  = Take(rv_Muon_phi, rv_Muon_IdxSortSelect);

    // std::cout << nSelectedMuon << std::endl;
    if (nSelectedMuon != 2) continue;

    auto rv_Jet_pt   = MakeRVec(Jet_pt);
    auto rv_Jet_eta  = MakeRVec(Jet_eta);
    auto rv_Jet_phi  = MakeRVec(Jet_phi);
    auto rv_Jet_mass = MakeRVec(Jet_mass);
    auto rv_Jet_jetId = MakeRVec(Jet_jetId);
    auto rv_Jet_genJetIdx  = MakeRVec(Jet_genJetIdx);
    auto rv_Jet_partonFlavour = MakeRVec(Jet_partonFlavour);
    auto rv_Jet_qgl_ptD    = MakeRVec(Jet_qgl_ptD);
    auto rv_Jet_qgl_axis2  = MakeRVec(Jet_qgl_axis2);
    auto rv_Jet_qgl_mult   = MakeRVec(Jet_qgl_mult);

    //
    auto rv_Jet_Muon0Clean = DeltaR(rv_Jet_eta, RVec(rv_Jet_eta.size(),rv_SelectedMuon_eta[0]), rv_Jet_phi, RVec(rv_Jet_phi.size(),rv_SelectedMuon_phi[0])) > 0.4;
    auto rv_Jet_Muon1Clean = DeltaR(rv_Jet_eta, RVec(rv_Jet_eta.size(),rv_SelectedMuon_eta[1]), rv_Jet_phi, RVec(rv_Jet_phi.size(),rv_SelectedMuon_phi[1])) > 0.4;

    //
    // pt > 20, passes jetId, does not overlap with the two leptons, matched to a genJet.
    //
    auto rv_Jet_isSignal = rv_Jet_pt > 20.f && (rv_Jet_jetId & (1<<1)) && rv_Jet_Muon0Clean && rv_Jet_Muon1Clean && rv_Jet_genJetIdx > -1;
    auto rv_Jet_IdxSelectSignal = Nonzero(rv_Jet_isSignal);

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


    auto rv_SignalJet_isCentral = rv_SignalJet_eta  < 2.5;
    // auto rv_SignalJet_isForward = rv_SignalJet_eta >= 2.5;

    // auto rv_SignalJet_isQuark  = rv_SignalJet_partonFlavour >= 1 && rv_SignalJet_partonFlavour <= 5;
    // auto rv_SignalJet_isGluon  = rv_SignalJet_partonFlavour == 21;
    // auto rv_SignalJet_isUndef  = rv_SignalJet_partonFlavour == 0;


    for (auto i=0; i < rv_SignalJet_pt.size(); i++){
      if (!rv_SignalJet_isCentral[i]) continue;
      if (rv_SignalJet_pt[i] >= 50.f) continue;
      if (rv_SignalJet_partonFlavour[i] >= 1 && rv_SignalJet_partonFlavour[i] <= 5){
        histosMap["h_quarkjet_qgl_ptD"] ->Fill(rv_SignalJet_qgl_ptD[i]);
        histosMap["h_quarkjet_qgl_axis"]->Fill(rv_SignalJet_qgl_axis2[i]);
        histosMap["h_quarkjet_qgl_mult"]->Fill(rv_SignalJet_qgl_mult[i]);
      }
      else if (rv_SignalJet_partonFlavour[i] == 21){
        histosMap["h_gluonjet_qgl_ptD"] ->Fill(rv_SignalJet_qgl_ptD[i]);
        histosMap["h_gluonjet_qgl_axis"]->Fill(rv_SignalJet_qgl_axis2[i]);
        histosMap["h_gluonjet_qgl_mult"]->Fill(rv_SignalJet_qgl_mult[i]);
      }
      else if (rv_SignalJet_partonFlavour[i] == 0){
        histosMap["h_undefjet_qgl_ptD"] ->Fill(rv_SignalJet_qgl_ptD[i]);
        histosMap["h_undefjet_qgl_axis"]->Fill(rv_SignalJet_qgl_axis2[i]);
        histosMap["h_undefjet_qgl_mult"]->Fill(rv_SignalJet_qgl_mult[i]);
      }
    }
  }

  outHistoFile->cd("");
  for ( auto h = histosMap.begin(); h != histosMap.end(); h++){
    h->second->Write();
  }
  outHistoFile->Close();
}