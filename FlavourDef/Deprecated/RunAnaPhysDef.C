//////////////////////////////////////////////////////////////////////////////////////////
// Creates a TChain to be used by the Analysis.C class
#include "TROOT.h"
#include "TChain.h"
#include "TFile.h"
#include "TProof.h"
#include <memory>
R__LOAD_LIBRARY(obj/AnaPhysDef_C.so)

void RunAnaPhysDef(){

  TChain* tChain = new TChain("Events");
  tChain->Add("root://xrootd-cms.infn.it//store/mc/RunIISummer20UL18NanoAODv9/DYJetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/NANOAODSIM/20UL18JMENano_106X_upgrade2018_realistic_v16_L1v1-v1/250000/C6054727-FA94-C146-8AAC-9FA14AE7510B.root");
  tChain->Add("root://xrootd-cms.infn.it//store/mc/RunIISummer20UL18NanoAODv9/DYJetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/NANOAODSIM/20UL18JMENano_106X_upgrade2018_realistic_v16_L1v1-v1/250000/082CFEB7-53F5-E841-87CC-FF519517F623.root");
  tChain->Add("root://xrootd-cms.infn.it//store/mc/RunIISummer20UL18NanoAODv9/DYJetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/NANOAODSIM/20UL18JMENano_106X_upgrade2018_realistic_v16_L1v1-v1/250000/2D361FB6-0591-644F-97F0-56EE0DCF6C46.root");

  TProof::Open("workers=2");
  AnaPhysDef* analyzer = new AnaPhysDef();
  analyzer->SetSampleName("Pythia");
  tChain->Process(analyzer);
  delete analyzer;
}