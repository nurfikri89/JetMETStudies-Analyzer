#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

#include <TChain.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>

#include <Math/Vector4D.h>
#include <Math/PtEtaPhiE4D.h>
#include <Math/PtEtaPhiM4D.h>
#include <Math/LorentzVector.h>

using namespace std;
typedef ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > PtEtaPhiMLorentzVectorF;

void ProcessNano(vector<string>&);

//
// The first function which root will call.
// This is just a wrapper function.
//
void PFNanoQuickAna(){

  //
  // Open text file containing list of root files
  //
  string txtFileName = "./samples/MC23PreBPix_QCD_Flat2022_NoPU.txt";
  std::ifstream infile(txtFileName);

  //
  // Loop over the list and put each file in inputFiles vector.
  //
  vector<string> inputFiles;
  for(string line; std::getline( infile, line ); ){
    std::string fileName = line;
    inputFiles.emplace_back(fileName);
  }

  //
  // The number of input files can be long and usually you want to run over one file
  // or a few files. You can trim the vector by specifying the number of files you want 
  // to run on. Set this to -1 if you want to run all files.
  //
  int nFilesToRun = 1;
  if (nFilesToRun >= 1)
    inputFiles.erase(inputFiles.begin()+nFilesToRun, inputFiles.end());

  //
  // Give the inputFiles vector to ProcessNano() function which is defined below.
  //
  ProcessNano(inputFiles);
}

//
//
//
void ProcessNano(vector<string>& inputFiles){

  //==========================================
  //
  // Load TChain
  //
  //==========================================
  TChain inTree("Events");
  for (size_t i = 0; i < inputFiles.size(); i++){
    inTree.Add(inputFiles[i].c_str());
    cout << "Added file to TChain: " << inputFiles[i] << endl;
  }

  //==========================================
  //
  //
  //
  //
  //==========================================

  TTreeReader fReader(&inTree);

  //
  TTreeReaderValue<Int_t>   nPFCand = {fReader, "nPFCand"};
  TTreeReaderArray<Float_t> PFCand_pt = {fReader, "PFCand_pt"};
  TTreeReaderArray<Float_t> PFCand_eta = {fReader, "PFCand_eta"};
  TTreeReaderArray<Float_t> PFCand_phi = {fReader, "PFCand_phi"};
  TTreeReaderArray<Float_t> PFCand_mass = {fReader, "PFCand_mass"};
  TTreeReaderArray<Float_t> PFCand_energy = {fReader, "PFCand_energy"};
  TTreeReaderArray<Int_t>   PFCand_pdgId = {fReader, "PFCand_pdgId"};
  TTreeReaderArray<Float_t> PFCand_puppiWeight = {fReader, "PFCand_puppiWeight"};
  //
  TTreeReaderValue<Int_t>   nJet = {fReader, "nJet"};
  TTreeReaderArray<Float_t> Jet_pt = {fReader, "Jet_pt"};
  TTreeReaderArray<Float_t> Jet_eta = {fReader, "Jet_eta"};
  TTreeReaderArray<Float_t> Jet_phi = {fReader, "Jet_phi"};
  TTreeReaderArray<Float_t> Jet_mass = {fReader, "Jet_mass"};
  TTreeReaderArray<Float_t> Jet_rawFactor = {fReader, "Jet_rawFactor"};
  TTreeReaderArray<UChar_t> Jet_jetId = {fReader, "Jet_jetId"};
  TTreeReaderArray<UChar_t> Jet_nConstituents = {fReader, "Jet_nConstituents"};
  TTreeReaderArray<UChar_t> Jet_chMultiplicity = {fReader, "Jet_chMultiplicity"};
  TTreeReaderArray<UChar_t> Jet_neMultiplicity = {fReader, "Jet_neMultiplicity"};
  TTreeReaderArray<Short_t> Jet_chHadMultiplicity = {fReader, "Jet_chHadMultiplicity"};
  TTreeReaderArray<Short_t> Jet_neHadMultiplicity = {fReader, "Jet_neHadMultiplicity"};
  TTreeReaderArray<Short_t> Jet_elMultiplicity = {fReader, "Jet_elMultiplicity"};
  TTreeReaderArray<Short_t> Jet_phoMultiplicity = {fReader, "Jet_phoMultiplicity"};
  TTreeReaderArray<Short_t> Jet_muMultiplicity = {fReader, "Jet_muMultiplicity"};
  TTreeReaderArray<Short_t> Jet_hfHadMultiplicity = {fReader, "Jet_hfHadMultiplicity"};
  TTreeReaderArray<Short_t> Jet_hfEMMultiplicity = {fReader, "Jet_hfEMMultiplicity"};
  TTreeReaderArray<UChar_t> Jet_hadronFlavour = {fReader, "Jet_hadronFlavour"};
  TTreeReaderArray<Short_t> Jet_partonFlavour = {fReader, "Jet_partonFlavour"};
  TTreeReaderArray<Short_t> Jet_genJetIdx = {fReader, "Jet_genJetIdx"};
  //
  TTreeReaderValue<Int_t> nJetPFCand = {fReader, "nJetPFCand"};
  TTreeReaderArray<Int_t> JetPFCand_PFCandIdx = {fReader, "JetPFCand_PFCandIdx"};
  TTreeReaderArray<Int_t> JetPFCand_jetIdx = {fReader, "JetPFCand_jetIdx"};

  TTreeReaderValue<Int_t>   nGenPartCand = {fReader, "nGenPartCand"};
  TTreeReaderArray<Int_t>   GenPartCand_charge = {fReader, "GenPartCand_charge"};
  TTreeReaderArray<Int_t>   GenPartCand_pdgId = {fReader, "GenPartCand_pdgId"};
  TTreeReaderArray<Float_t> GenPartCand_eta = {fReader, "GenPartCand_eta"};
  TTreeReaderArray<Float_t> GenPartCand_mass = {fReader, "GenPartCand_mass"};
  TTreeReaderArray<Float_t> GenPartCand_phi = {fReader, "GenPartCand_phi"};
  TTreeReaderArray<Float_t> GenPartCand_pt = {fReader, "GenPartCand_pt"};

  TTreeReaderValue<Int_t>   nGenJet = {fReader, "nGenJet"};
  TTreeReaderArray<Float_t> GenJet_pt = {fReader, "GenJet_pt"};
  TTreeReaderArray<Float_t> GenJet_eta = {fReader, "GenJet_eta"};
  TTreeReaderArray<Float_t> GenJet_mass = {fReader, "GenJet_mass"};
  TTreeReaderArray<Float_t> GenJet_phi = {fReader, "GenJet_phi"};
  TTreeReaderArray<UChar_t> GenJet_hadronFlavour = {fReader, "GenJet_hadronFlavour"};
  TTreeReaderArray<Short_t> GenJet_partonFlavour = {fReader, "GenJet_partonFlavour"};

  TTreeReaderValue<Int_t> nGenJetGenPartCand = {fReader, "nGenJetGenPartCand"};
  TTreeReaderArray<Int_t> GenJetGenPartCand_GenPartCandIdx = {fReader, "GenJetGenPartCand_GenPartCandIdx"};
  TTreeReaderArray<Int_t> GenJetGenPartCand_genJetIdx = {fReader, "GenJetGenPartCand_genJetIdx"};

  //==========================================
  //
  // Loop over events
  //
  //==========================================
  auto nEntries = inTree.GetEntries();
  // nEntries = 100;

  for(long long int iEntry=0; iEntry < nEntries; iEntry++){
    if (iEntry % 1000 == 0){
      std::cout << iEntry << " / " << nEntries << std::endl;
    }
    fReader.SetLocalEntry(iEntry);

    //==========================================
    //
    // Map PFCands to reco jets
    //
    //==========================================
    vector<vector<int>> Jet_PFCandIdxVec(*nJet, vector<int>());
    for(int i = 0; i < *nJetPFCand; i++){
      int JetIdx = JetPFCand_jetIdx[i];
      int PFCandIdx = JetPFCand_PFCandIdx[i];
      Jet_PFCandIdxVec[JetIdx].emplace_back(PFCandIdx);
    }

    //==========================================
    //
    // Map GenPartCand to gen jets
    //
    //==========================================
    // vector<vector<int>> GenJet_GenPartCandIdxVec(*nGenJet, vector<int>());
    // for(int i = 0; i < *nGenJetGenPartCand; i++){
    //   int GenJetIdx = GenJetGenPartCand_genJetIdx[i];
    //   int GenPartCandIdx = GenJetGenPartCand_GenPartCandIdx[i];
    //   GenJet_GenPartCandIdxVec[GenJetIdx].emplace_back(GenPartCandIdx);
    // }

    //==========================================
    //
    // Loop over reco jets
    //
    //==========================================
    for (int iJet = 0; iJet < *nJet; iJet++){
      float recojet_pt        = Jet_pt[iJet];
      float recojet_eta       = Jet_eta[iJet];
      float recojet_phi       = Jet_phi[iJet];
      float recojet_mass      = Jet_mass[iJet];
      float recojet_rawFactor = Jet_rawFactor[iJet];
      float recojet_pt_raw = (1.f - recojet_rawFactor) * recojet_pt;

      int recojet_mult_chHad = Jet_chHadMultiplicity[iJet];
      int recojet_mult_neHad = Jet_neHadMultiplicity[iJet];
      int recojet_mult_el    = Jet_elMultiplicity[iJet];
      int recojet_mult_pho   = Jet_phoMultiplicity[iJet];
      int recojet_mult_mu    = Jet_muMultiplicity[iJet];
      int recojet_mult_hfHad = Jet_hfHadMultiplicity[iJet];
      int recojet_mult_hfEM  = Jet_hfEMMultiplicity[iJet];

      //
      // Use float here because the multiplicity are weighted.
      // Round up to 'int' later.
      //
      float tmp_mult_chHad  = 0.f;
      float tmp_mult_neHad  = 0.f;
      float tmp_mult_el     = 0.f;
      float tmp_mult_pho    = 0.f;
      float tmp_mult_mu     = 0.f;
      float tmp_mult_hfHad  = 0.f;
      float tmp_mult_hfEM   = 0.f;

      //==========================================
      //
      // Loop over PF candidates for this jet
      //
      //==========================================
      // Use to calculate the jet's raw p4 from PF candidates.
      PtEtaPhiMLorentzVectorF jet_raw_p4(0,0,0,0);

      for (size_t iPF = 0; iPF < Jet_PFCandIdxVec[iJet].size(); iPF++){
        int PFCandIdx = Jet_PFCandIdxVec[iJet][iPF];
        float cand_pt     = PFCand_pt[PFCandIdx];
        float cand_eta    = PFCand_eta[PFCandIdx];
        float cand_phi    = PFCand_phi[PFCandIdx];
        float cand_mass   = PFCand_mass[PFCandIdx];
        float cand_energy = PFCand_energy[PFCandIdx];
        float cand_puppiWeight = PFCand_puppiWeight[PFCandIdx];

        // Get p4 of candidates and add it to jet's raw p4
        PtEtaPhiMLorentzVectorF cand_p4(cand_puppiWeight * cand_pt, cand_eta, cand_phi, cand_puppiWeight * cand_mass);
        jet_raw_p4 += cand_p4;

        //
        // pdgId for PFCandidates: https://github.com/cms-sw/cmssw/blob/CMSSW_13_0_13/DataFormats/ParticleFlowCandidate/src/PFCandidate.cc#L254-L276
        // 211 (Charged Hadron)
        // 130 (Neutral Hadron)
        //  11 (Electron)
        //  13 (Muon)
        //  22 (Photon)
        //  1  (HF hadron)
        //  2  (HF EM)
        int cand_pdgId = PFCand_pdgId[PFCandIdx];
        if (abs(cand_pdgId) == 211)      tmp_mult_chHad += cand_puppiWeight;
        else if (abs(cand_pdgId) == 130) tmp_mult_neHad += cand_puppiWeight;
        else if (abs(cand_pdgId) == 11)  tmp_mult_el    += cand_puppiWeight;
        else if (abs(cand_pdgId) == 22)  tmp_mult_pho   += cand_puppiWeight;
        else if (abs(cand_pdgId) == 13)  tmp_mult_mu    += cand_puppiWeight;
        else if (abs(cand_pdgId) == 1)   tmp_mult_hfHad += cand_puppiWeight;
        else if (abs(cand_pdgId) == 2)   tmp_mult_hfEM  += cand_puppiWeight;
      }
      int mult_chHad  = std::round(tmp_mult_chHad);
      int mult_neHad  = std::round(tmp_mult_neHad);
      int mult_el     = std::round(tmp_mult_el);
      int mult_pho    = std::round(tmp_mult_pho);
      int mult_mu     = std::round(tmp_mult_mu);
      int mult_hfHad  = std::round(tmp_mult_hfHad);
      int mult_hfEM   = std::round(tmp_mult_hfEM);
    }
  }
}