//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sat Feb 24 22:37:39 2024 by ROOT version 6.30/04
// from TTree Events/Events
// found on file: root://xrootd-cms.infn.it//store/mc/Run3Summer23BPixNanoAODv12/QCD-4Jets_HT-2000_TuneCP5_13p6TeV_madgraphMLM-pythia8/NANOAODSIM/130X_mcRun3_2023_realistic_postBPix_v2-v4/2550000/d51d8505-901c-410f-91e8-a2fe948e3902.root
//////////////////////////////////////////////////////////

#ifndef NanoV12Selector_h
#define NanoV12Selector_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>
#include <TH1D.h>

// Headers needed by this particular selector


class NanoV12Selector : public TSelector {
public :
   TTreeReader     fReader;  //!the tree reader
   TTree          *fChain = 0;   //!pointer to the analyzed TTree or TChain

   // Readers to access the data (delete the ones you do not need).
   // TTreeReaderValue<UInt_t> run = {fReader, "run"};
   // TTreeReaderValue<UInt_t> luminosityBlock = {fReader, "luminosityBlock"};
   // TTreeReaderValue<ULong64_t> event = {fReader, "event"};
   // TTreeReaderValue<UInt_t> bunchCrossing = {fReader, "bunchCrossing"};
   // TTreeReaderValue<UChar_t> HTXS_njets25 = {fReader, "HTXS_njets25"};
   // TTreeReaderValue<UChar_t> HTXS_njets30 = {fReader, "HTXS_njets30"};
   // TTreeReaderValue<Int_t> HTXS_stage1_1_cat_pTjet25GeV = {fReader, "HTXS_stage1_1_cat_pTjet25GeV"};
   // TTreeReaderValue<Int_t> HTXS_stage1_1_cat_pTjet30GeV = {fReader, "HTXS_stage1_1_cat_pTjet30GeV"};
   // TTreeReaderValue<Int_t> HTXS_stage1_1_fine_cat_pTjet25GeV = {fReader, "HTXS_stage1_1_fine_cat_pTjet25GeV"};
   // TTreeReaderValue<Int_t> HTXS_stage1_1_fine_cat_pTjet30GeV = {fReader, "HTXS_stage1_1_fine_cat_pTjet30GeV"};
   // TTreeReaderValue<Int_t> HTXS_stage1_2_cat_pTjet25GeV = {fReader, "HTXS_stage1_2_cat_pTjet25GeV"};
   // TTreeReaderValue<Int_t> HTXS_stage1_2_cat_pTjet30GeV = {fReader, "HTXS_stage1_2_cat_pTjet30GeV"};
   // TTreeReaderValue<Int_t> HTXS_stage1_2_fine_cat_pTjet25GeV = {fReader, "HTXS_stage1_2_fine_cat_pTjet25GeV"};
   // TTreeReaderValue<Int_t> HTXS_stage1_2_fine_cat_pTjet30GeV = {fReader, "HTXS_stage1_2_fine_cat_pTjet30GeV"};
   // TTreeReaderValue<Int_t> HTXS_stage_0 = {fReader, "HTXS_stage_0"};
   // TTreeReaderValue<Int_t> HTXS_stage_1_pTjet25 = {fReader, "HTXS_stage_1_pTjet25"};
   // TTreeReaderValue<Int_t> HTXS_stage_1_pTjet30 = {fReader, "HTXS_stage_1_pTjet30"};
   // TTreeReaderValue<Float_t> HTXS_Higgs_pt = {fReader, "HTXS_Higgs_pt"};
   // TTreeReaderValue<Float_t> HTXS_Higgs_y = {fReader, "HTXS_Higgs_y"};
   // TTreeReaderValue<Char_t> BeamSpot_type = {fReader, "BeamSpot_type"};
   // TTreeReaderValue<Float_t> BeamSpot_sigmaZ = {fReader, "BeamSpot_sigmaZ"};
   // TTreeReaderValue<Float_t> BeamSpot_sigmaZError = {fReader, "BeamSpot_sigmaZError"};
   // TTreeReaderValue<Float_t> BeamSpot_z = {fReader, "BeamSpot_z"};
   // TTreeReaderValue<Float_t> BeamSpot_zError = {fReader, "BeamSpot_zError"};
   // TTreeReaderValue<Int_t> nboostedTau = {fReader, "nboostedTau"};
   // TTreeReaderArray<UChar_t> boostedTau_idAntiEle2018 = {fReader, "boostedTau_idAntiEle2018"};
   // TTreeReaderArray<UChar_t> boostedTau_idAntiMu = {fReader, "boostedTau_idAntiMu"};
   // TTreeReaderArray<UChar_t> boostedTau_idMVAnewDM2017v2 = {fReader, "boostedTau_idMVAnewDM2017v2"};
   // TTreeReaderArray<UChar_t> boostedTau_idMVAoldDM2017v2 = {fReader, "boostedTau_idMVAoldDM2017v2"};
   // TTreeReaderArray<Short_t> boostedTau_jetIdx = {fReader, "boostedTau_jetIdx"};
   // TTreeReaderArray<Short_t> boostedTau_rawAntiEleCat2018 = {fReader, "boostedTau_rawAntiEleCat2018"};
   // TTreeReaderArray<Int_t> boostedTau_charge = {fReader, "boostedTau_charge"};
   // TTreeReaderArray<Int_t> boostedTau_decayMode = {fReader, "boostedTau_decayMode"};
   // TTreeReaderArray<Float_t> boostedTau_chargedIso = {fReader, "boostedTau_chargedIso"};
   // TTreeReaderArray<Float_t> boostedTau_eta = {fReader, "boostedTau_eta"};
   // TTreeReaderArray<Float_t> boostedTau_leadTkDeltaEta = {fReader, "boostedTau_leadTkDeltaEta"};
   // TTreeReaderArray<Float_t> boostedTau_leadTkDeltaPhi = {fReader, "boostedTau_leadTkDeltaPhi"};
   // TTreeReaderArray<Float_t> boostedTau_leadTkPtOverTauPt = {fReader, "boostedTau_leadTkPtOverTauPt"};
   // TTreeReaderArray<Float_t> boostedTau_mass = {fReader, "boostedTau_mass"};
   // TTreeReaderArray<Float_t> boostedTau_neutralIso = {fReader, "boostedTau_neutralIso"};
   // TTreeReaderArray<Float_t> boostedTau_phi = {fReader, "boostedTau_phi"};
   // TTreeReaderArray<Float_t> boostedTau_photonsOutsideSignalCone = {fReader, "boostedTau_photonsOutsideSignalCone"};
   // TTreeReaderArray<Float_t> boostedTau_pt = {fReader, "boostedTau_pt"};
   // TTreeReaderArray<Float_t> boostedTau_puCorr = {fReader, "boostedTau_puCorr"};
   // TTreeReaderArray<Float_t> boostedTau_rawAntiEle2018 = {fReader, "boostedTau_rawAntiEle2018"};
   // TTreeReaderArray<Float_t> boostedTau_rawIso = {fReader, "boostedTau_rawIso"};
   // TTreeReaderArray<Float_t> boostedTau_rawIsodR03 = {fReader, "boostedTau_rawIsodR03"};
   // TTreeReaderArray<Float_t> boostedTau_rawMVAnewDM2017v2 = {fReader, "boostedTau_rawMVAnewDM2017v2"};
   // TTreeReaderArray<Float_t> boostedTau_rawMVAoldDM2017v2 = {fReader, "boostedTau_rawMVAoldDM2017v2"};
   // TTreeReaderValue<Float_t> CaloMET_phi = {fReader, "CaloMET_phi"};
   // TTreeReaderValue<Float_t> CaloMET_pt = {fReader, "CaloMET_pt"};
   // TTreeReaderValue<Float_t> CaloMET_sumEt = {fReader, "CaloMET_sumEt"};
   // TTreeReaderValue<Float_t> ChsMET_phi = {fReader, "ChsMET_phi"};
   // TTreeReaderValue<Float_t> ChsMET_pt = {fReader, "ChsMET_pt"};
   // TTreeReaderValue<Float_t> ChsMET_sumEt = {fReader, "ChsMET_sumEt"};
   // TTreeReaderValue<Int_t> nCorrT1METJet = {fReader, "nCorrT1METJet"};
   // TTreeReaderArray<Float_t> CorrT1METJet_area = {fReader, "CorrT1METJet_area"};
   // TTreeReaderArray<Float_t> CorrT1METJet_eta = {fReader, "CorrT1METJet_eta"};
   // TTreeReaderArray<Float_t> CorrT1METJet_muonSubtrFactor = {fReader, "CorrT1METJet_muonSubtrFactor"};
   // TTreeReaderArray<Float_t> CorrT1METJet_phi = {fReader, "CorrT1METJet_phi"};
   // TTreeReaderArray<Float_t> CorrT1METJet_rawPt = {fReader, "CorrT1METJet_rawPt"};
   // TTreeReaderValue<Float_t> DeepMETResolutionTune_phi = {fReader, "DeepMETResolutionTune_phi"};
   // TTreeReaderValue<Float_t> DeepMETResolutionTune_pt = {fReader, "DeepMETResolutionTune_pt"};
   // TTreeReaderValue<Float_t> DeepMETResponseTune_phi = {fReader, "DeepMETResponseTune_phi"};
   // TTreeReaderValue<Float_t> DeepMETResponseTune_pt = {fReader, "DeepMETResponseTune_pt"};
   // TTreeReaderValue<Int_t> nElectron = {fReader, "nElectron"};
   // TTreeReaderArray<Char_t> Electron_seediEtaOriX = {fReader, "Electron_seediEtaOriX"};
   // TTreeReaderArray<Bool_t> Electron_convVeto = {fReader, "Electron_convVeto"};
   // TTreeReaderArray<UChar_t> Electron_cutBased = {fReader, "Electron_cutBased"};
   // TTreeReaderArray<Bool_t> Electron_cutBased_HEEP = {fReader, "Electron_cutBased_HEEP"};
   // TTreeReaderArray<Bool_t> Electron_isPFcand = {fReader, "Electron_isPFcand"};
   // TTreeReaderArray<UChar_t> Electron_jetNDauCharged = {fReader, "Electron_jetNDauCharged"};
   // TTreeReaderArray<UChar_t> Electron_lostHits = {fReader, "Electron_lostHits"};
   // TTreeReaderArray<Bool_t> Electron_mvaIso_WP80 = {fReader, "Electron_mvaIso_WP80"};
   // TTreeReaderArray<Bool_t> Electron_mvaIso_WP90 = {fReader, "Electron_mvaIso_WP90"};
   // TTreeReaderArray<Bool_t> Electron_mvaNoIso_WP80 = {fReader, "Electron_mvaNoIso_WP80"};
   // TTreeReaderArray<Bool_t> Electron_mvaNoIso_WP90 = {fReader, "Electron_mvaNoIso_WP90"};
   // TTreeReaderArray<UChar_t> Electron_seedGain = {fReader, "Electron_seedGain"};
   // TTreeReaderArray<UChar_t> Electron_tightCharge = {fReader, "Electron_tightCharge"};
   // TTreeReaderArray<Short_t> Electron_jetIdx = {fReader, "Electron_jetIdx"};
   // TTreeReaderArray<Short_t> Electron_photonIdx = {fReader, "Electron_photonIdx"};
   // TTreeReaderArray<Short_t> Electron_svIdx = {fReader, "Electron_svIdx"};
   // TTreeReaderArray<Short_t> Electron_fsrPhotonIdx = {fReader, "Electron_fsrPhotonIdx"};
   // TTreeReaderArray<Int_t> Electron_charge = {fReader, "Electron_charge"};
   // TTreeReaderArray<Int_t> Electron_pdgId = {fReader, "Electron_pdgId"};
   // TTreeReaderArray<Int_t> Electron_seediPhiOriY = {fReader, "Electron_seediPhiOriY"};
   // TTreeReaderArray<Int_t> Electron_vidNestedWPBitmap = {fReader, "Electron_vidNestedWPBitmap"};
   // TTreeReaderArray<Int_t> Electron_vidNestedWPBitmapHEEP = {fReader, "Electron_vidNestedWPBitmapHEEP"};
   // TTreeReaderArray<Float_t> Electron_deltaEtaSC = {fReader, "Electron_deltaEtaSC"};
   // TTreeReaderArray<Float_t> Electron_dr03EcalRecHitSumEt = {fReader, "Electron_dr03EcalRecHitSumEt"};
   // TTreeReaderArray<Float_t> Electron_dr03HcalDepth1TowerSumEt = {fReader, "Electron_dr03HcalDepth1TowerSumEt"};
   // TTreeReaderArray<Float_t> Electron_dr03TkSumPt = {fReader, "Electron_dr03TkSumPt"};
   // TTreeReaderArray<Float_t> Electron_dr03TkSumPtHEEP = {fReader, "Electron_dr03TkSumPtHEEP"};
   // TTreeReaderArray<Float_t> Electron_dxy = {fReader, "Electron_dxy"};
   // TTreeReaderArray<Float_t> Electron_dxyErr = {fReader, "Electron_dxyErr"};
   // TTreeReaderArray<Float_t> Electron_dz = {fReader, "Electron_dz"};
   // TTreeReaderArray<Float_t> Electron_dzErr = {fReader, "Electron_dzErr"};
   // TTreeReaderArray<Float_t> Electron_eInvMinusPInv = {fReader, "Electron_eInvMinusPInv"};
   // TTreeReaderArray<Float_t> Electron_energyErr = {fReader, "Electron_energyErr"};
   // TTreeReaderArray<Float_t> Electron_eta = {fReader, "Electron_eta"};
   // TTreeReaderArray<Float_t> Electron_hoe = {fReader, "Electron_hoe"};
   // TTreeReaderArray<Float_t> Electron_ip3d = {fReader, "Electron_ip3d"};
   // TTreeReaderArray<Float_t> Electron_jetPtRelv2 = {fReader, "Electron_jetPtRelv2"};
   // TTreeReaderArray<Float_t> Electron_jetRelIso = {fReader, "Electron_jetRelIso"};
   // TTreeReaderArray<Float_t> Electron_mass = {fReader, "Electron_mass"};
   // TTreeReaderArray<Float_t> Electron_miniPFRelIso_all = {fReader, "Electron_miniPFRelIso_all"};
   // TTreeReaderArray<Float_t> Electron_miniPFRelIso_chg = {fReader, "Electron_miniPFRelIso_chg"};
   // TTreeReaderArray<Float_t> Electron_mvaHZZIso = {fReader, "Electron_mvaHZZIso"};
   // TTreeReaderArray<Float_t> Electron_mvaIso = {fReader, "Electron_mvaIso"};
   // TTreeReaderArray<Float_t> Electron_mvaNoIso = {fReader, "Electron_mvaNoIso"};
   // TTreeReaderArray<Float_t> Electron_pfRelIso03_all = {fReader, "Electron_pfRelIso03_all"};
   // TTreeReaderArray<Float_t> Electron_pfRelIso03_chg = {fReader, "Electron_pfRelIso03_chg"};
   // TTreeReaderArray<Float_t> Electron_phi = {fReader, "Electron_phi"};
   // TTreeReaderArray<Float_t> Electron_pt = {fReader, "Electron_pt"};
   // TTreeReaderArray<Float_t> Electron_r9 = {fReader, "Electron_r9"};
   // TTreeReaderArray<Float_t> Electron_scEtOverPt = {fReader, "Electron_scEtOverPt"};
   // TTreeReaderArray<Float_t> Electron_sieie = {fReader, "Electron_sieie"};
   // TTreeReaderArray<Float_t> Electron_sip3d = {fReader, "Electron_sip3d"};
   // TTreeReaderArray<Float_t> Electron_mvaTTH = {fReader, "Electron_mvaTTH"};
   // TTreeReaderValue<Int_t> nFatJet = {fReader, "nFatJet"};
   // TTreeReaderArray<UChar_t> FatJet_jetId = {fReader, "FatJet_jetId"};
   // TTreeReaderArray<UChar_t> FatJet_nConstituents = {fReader, "FatJet_nConstituents"};
   // TTreeReaderArray<Short_t> FatJet_subJetIdx1 = {fReader, "FatJet_subJetIdx1"};
   // TTreeReaderArray<Short_t> FatJet_subJetIdx2 = {fReader, "FatJet_subJetIdx2"};
   // TTreeReaderArray<Short_t> FatJet_electronIdx3SJ = {fReader, "FatJet_electronIdx3SJ"};
   // TTreeReaderArray<Short_t> FatJet_muonIdx3SJ = {fReader, "FatJet_muonIdx3SJ"};
   // TTreeReaderArray<Float_t> FatJet_area = {fReader, "FatJet_area"};
   // TTreeReaderArray<Float_t> FatJet_btagDDBvLV2 = {fReader, "FatJet_btagDDBvLV2"};
   // TTreeReaderArray<Float_t> FatJet_btagDDCvBV2 = {fReader, "FatJet_btagDDCvBV2"};
   // TTreeReaderArray<Float_t> FatJet_btagDDCvLV2 = {fReader, "FatJet_btagDDCvLV2"};
   // TTreeReaderArray<Float_t> FatJet_btagDeepB = {fReader, "FatJet_btagDeepB"};
   // TTreeReaderArray<Float_t> FatJet_btagHbb = {fReader, "FatJet_btagHbb"};
   // TTreeReaderArray<Float_t> FatJet_eta = {fReader, "FatJet_eta"};
   // TTreeReaderArray<Float_t> FatJet_mass = {fReader, "FatJet_mass"};
   // TTreeReaderArray<Float_t> FatJet_msoftdrop = {fReader, "FatJet_msoftdrop"};
   // TTreeReaderArray<Float_t> FatJet_n2b1 = {fReader, "FatJet_n2b1"};
   // TTreeReaderArray<Float_t> FatJet_n3b1 = {fReader, "FatJet_n3b1"};
   // TTreeReaderArray<Float_t> FatJet_particleNetWithMass_H4qvsQCD = {fReader, "FatJet_particleNetWithMass_H4qvsQCD"};
   // TTreeReaderArray<Float_t> FatJet_particleNetWithMass_HbbvsQCD = {fReader, "FatJet_particleNetWithMass_HbbvsQCD"};
   // TTreeReaderArray<Float_t> FatJet_particleNetWithMass_HccvsQCD = {fReader, "FatJet_particleNetWithMass_HccvsQCD"};
   // TTreeReaderArray<Float_t> FatJet_particleNetWithMass_QCD = {fReader, "FatJet_particleNetWithMass_QCD"};
   // TTreeReaderArray<Float_t> FatJet_particleNetWithMass_TvsQCD = {fReader, "FatJet_particleNetWithMass_TvsQCD"};
   // TTreeReaderArray<Float_t> FatJet_particleNetWithMass_WvsQCD = {fReader, "FatJet_particleNetWithMass_WvsQCD"};
   // TTreeReaderArray<Float_t> FatJet_particleNetWithMass_ZvsQCD = {fReader, "FatJet_particleNetWithMass_ZvsQCD"};
   // TTreeReaderArray<Float_t> FatJet_particleNet_QCD = {fReader, "FatJet_particleNet_QCD"};
   // TTreeReaderArray<Float_t> FatJet_particleNet_QCD0HF = {fReader, "FatJet_particleNet_QCD0HF"};
   // TTreeReaderArray<Float_t> FatJet_particleNet_QCD1HF = {fReader, "FatJet_particleNet_QCD1HF"};
   // TTreeReaderArray<Float_t> FatJet_particleNet_QCD2HF = {fReader, "FatJet_particleNet_QCD2HF"};
   // TTreeReaderArray<Float_t> FatJet_particleNet_XbbVsQCD = {fReader, "FatJet_particleNet_XbbVsQCD"};
   // TTreeReaderArray<Float_t> FatJet_particleNet_XccVsQCD = {fReader, "FatJet_particleNet_XccVsQCD"};
   // TTreeReaderArray<Float_t> FatJet_particleNet_XggVsQCD = {fReader, "FatJet_particleNet_XggVsQCD"};
   // TTreeReaderArray<Float_t> FatJet_particleNet_XqqVsQCD = {fReader, "FatJet_particleNet_XqqVsQCD"};
   // TTreeReaderArray<Float_t> FatJet_particleNet_XteVsQCD = {fReader, "FatJet_particleNet_XteVsQCD"};
   // TTreeReaderArray<Float_t> FatJet_particleNet_XtmVsQCD = {fReader, "FatJet_particleNet_XtmVsQCD"};
   // TTreeReaderArray<Float_t> FatJet_particleNet_XttVsQCD = {fReader, "FatJet_particleNet_XttVsQCD"};
   // TTreeReaderArray<Float_t> FatJet_particleNet_massCorr = {fReader, "FatJet_particleNet_massCorr"};
   // TTreeReaderArray<Float_t> FatJet_phi = {fReader, "FatJet_phi"};
   // TTreeReaderArray<Float_t> FatJet_pt = {fReader, "FatJet_pt"};
   // TTreeReaderArray<Float_t> FatJet_rawFactor = {fReader, "FatJet_rawFactor"};
   // TTreeReaderArray<Float_t> FatJet_tau1 = {fReader, "FatJet_tau1"};
   // TTreeReaderArray<Float_t> FatJet_tau2 = {fReader, "FatJet_tau2"};
   // TTreeReaderArray<Float_t> FatJet_tau3 = {fReader, "FatJet_tau3"};
   // TTreeReaderArray<Float_t> FatJet_tau4 = {fReader, "FatJet_tau4"};
   // TTreeReaderArray<Float_t> FatJet_lsf3 = {fReader, "FatJet_lsf3"};
   // TTreeReaderValue<Int_t> nFsrPhoton = {fReader, "nFsrPhoton"};
   // TTreeReaderArray<Short_t> FsrPhoton_electronIdx = {fReader, "FsrPhoton_electronIdx"};
   // TTreeReaderArray<Short_t> FsrPhoton_muonIdx = {fReader, "FsrPhoton_muonIdx"};
   // TTreeReaderArray<Float_t> FsrPhoton_dROverEt2 = {fReader, "FsrPhoton_dROverEt2"};
   // TTreeReaderArray<Float_t> FsrPhoton_eta = {fReader, "FsrPhoton_eta"};
   // TTreeReaderArray<Float_t> FsrPhoton_phi = {fReader, "FsrPhoton_phi"};
   // TTreeReaderArray<Float_t> FsrPhoton_pt = {fReader, "FsrPhoton_pt"};
   // TTreeReaderArray<Float_t> FsrPhoton_relIso03 = {fReader, "FsrPhoton_relIso03"};
   // TTreeReaderValue<Int_t> nGenJetAK8 = {fReader, "nGenJetAK8"};
   // TTreeReaderArray<Float_t> GenJetAK8_eta = {fReader, "GenJetAK8_eta"};
   // TTreeReaderArray<Float_t> GenJetAK8_mass = {fReader, "GenJetAK8_mass"};
   // TTreeReaderArray<Float_t> GenJetAK8_phi = {fReader, "GenJetAK8_phi"};
   // TTreeReaderArray<Float_t> GenJetAK8_pt = {fReader, "GenJetAK8_pt"};
   TTreeReaderValue<Int_t> nGenJet = {fReader, "nGenJet"};
   TTreeReaderArray<Float_t> GenJet_eta = {fReader, "GenJet_eta"};
   TTreeReaderArray<Float_t> GenJet_mass = {fReader, "GenJet_mass"};
   TTreeReaderArray<Float_t> GenJet_phi = {fReader, "GenJet_phi"};
   TTreeReaderArray<Float_t> GenJet_pt = {fReader, "GenJet_pt"};
   // TTreeReaderValue<Int_t> nGenPart = {fReader, "nGenPart"};
   // TTreeReaderArray<Short_t> GenPart_genPartIdxMother = {fReader, "GenPart_genPartIdxMother"};
   // TTreeReaderArray<UShort_t> GenPart_statusFlags = {fReader, "GenPart_statusFlags"};
   // TTreeReaderArray<Int_t> GenPart_pdgId = {fReader, "GenPart_pdgId"};
   // TTreeReaderArray<Int_t> GenPart_status = {fReader, "GenPart_status"};
   // TTreeReaderArray<Float_t> GenPart_eta = {fReader, "GenPart_eta"};
   // TTreeReaderArray<Float_t> GenPart_mass = {fReader, "GenPart_mass"};
   // TTreeReaderArray<Float_t> GenPart_phi = {fReader, "GenPart_phi"};
   // TTreeReaderArray<Float_t> GenPart_pt = {fReader, "GenPart_pt"};
   // TTreeReaderValue<Int_t> nGenProton = {fReader, "nGenProton"};
   // TTreeReaderArray<Bool_t> GenProton_isPU = {fReader, "GenProton_isPU"};
   // TTreeReaderArray<Float_t> GenProton_px = {fReader, "GenProton_px"};
   // TTreeReaderArray<Float_t> GenProton_py = {fReader, "GenProton_py"};
   // TTreeReaderArray<Float_t> GenProton_pz = {fReader, "GenProton_pz"};
   // TTreeReaderArray<Float_t> GenProton_vz = {fReader, "GenProton_vz"};
   // TTreeReaderValue<Int_t> nSubGenJetAK8 = {fReader, "nSubGenJetAK8"};
   // TTreeReaderArray<Float_t> SubGenJetAK8_eta = {fReader, "SubGenJetAK8_eta"};
   // TTreeReaderArray<Float_t> SubGenJetAK8_mass = {fReader, "SubGenJetAK8_mass"};
   // TTreeReaderArray<Float_t> SubGenJetAK8_phi = {fReader, "SubGenJetAK8_phi"};
   // TTreeReaderArray<Float_t> SubGenJetAK8_pt = {fReader, "SubGenJetAK8_pt"};
   // TTreeReaderValue<Int_t> Generator_id1 = {fReader, "Generator_id1"};
   // TTreeReaderValue<Int_t> Generator_id2 = {fReader, "Generator_id2"};
   // TTreeReaderValue<Float_t> Generator_binvar = {fReader, "Generator_binvar"};
   // TTreeReaderValue<Float_t> Generator_scalePDF = {fReader, "Generator_scalePDF"};
   // TTreeReaderValue<Float_t> Generator_weight = {fReader, "Generator_weight"};
   // TTreeReaderValue<Float_t> Generator_x1 = {fReader, "Generator_x1"};
   // TTreeReaderValue<Float_t> Generator_x2 = {fReader, "Generator_x2"};
   // TTreeReaderValue<Float_t> Generator_xpdf1 = {fReader, "Generator_xpdf1"};
   // TTreeReaderValue<Float_t> Generator_xpdf2 = {fReader, "Generator_xpdf2"};
   // TTreeReaderValue<Float_t> GenVtx_x = {fReader, "GenVtx_x"};
   // TTreeReaderValue<Float_t> GenVtx_y = {fReader, "GenVtx_y"};
   // TTreeReaderValue<Float_t> GenVtx_z = {fReader, "GenVtx_z"};
   // TTreeReaderValue<Int_t> nGenVisTau = {fReader, "nGenVisTau"};
   // TTreeReaderArray<UChar_t> GenVisTau_status = {fReader, "GenVisTau_status"};
   // TTreeReaderArray<Short_t> GenVisTau_charge = {fReader, "GenVisTau_charge"};
   // TTreeReaderArray<Short_t> GenVisTau_genPartIdxMother = {fReader, "GenVisTau_genPartIdxMother"};
   // TTreeReaderArray<Float_t> GenVisTau_eta = {fReader, "GenVisTau_eta"};
   // TTreeReaderArray<Float_t> GenVisTau_mass = {fReader, "GenVisTau_mass"};
   // TTreeReaderArray<Float_t> GenVisTau_phi = {fReader, "GenVisTau_phi"};
   // TTreeReaderArray<Float_t> GenVisTau_pt = {fReader, "GenVisTau_pt"};
   TTreeReaderValue<Float_t> genWeight = {fReader, "genWeight"};
   // TTreeReaderValue<Float_t> LHEWeight_originalXWGTUP = {fReader, "LHEWeight_originalXWGTUP"};
   // TTreeReaderValue<Int_t> nLHEPdfWeight = {fReader, "nLHEPdfWeight"};
   // TTreeReaderArray<Float_t> LHEPdfWeight = {fReader, "LHEPdfWeight"};
   // TTreeReaderValue<Int_t> nLHEReweightingWeight = {fReader, "nLHEReweightingWeight"};
   // TTreeReaderArray<Float_t> LHEReweightingWeight = {fReader, "LHEReweightingWeight"};
   // TTreeReaderValue<Int_t> nLHEScaleWeight = {fReader, "nLHEScaleWeight"};
   // TTreeReaderArray<Float_t> LHEScaleWeight = {fReader, "LHEScaleWeight"};
   // TTreeReaderValue<Int_t> nPSWeight = {fReader, "nPSWeight"};
   // TTreeReaderArray<Float_t> PSWeight = {fReader, "PSWeight"};
   // TTreeReaderValue<Int_t> nIsoTrack = {fReader, "nIsoTrack"};
   // TTreeReaderArray<Bool_t> IsoTrack_isHighPurityTrack = {fReader, "IsoTrack_isHighPurityTrack"};
   // TTreeReaderArray<Bool_t> IsoTrack_isPFcand = {fReader, "IsoTrack_isPFcand"};
   // TTreeReaderArray<Bool_t> IsoTrack_isFromLostTrack = {fReader, "IsoTrack_isFromLostTrack"};
   // TTreeReaderArray<Short_t> IsoTrack_charge = {fReader, "IsoTrack_charge"};
   // TTreeReaderArray<Short_t> IsoTrack_fromPV = {fReader, "IsoTrack_fromPV"};
   // TTreeReaderArray<Int_t> IsoTrack_pdgId = {fReader, "IsoTrack_pdgId"};
   // TTreeReaderArray<Float_t> IsoTrack_dxy = {fReader, "IsoTrack_dxy"};
   // TTreeReaderArray<Float_t> IsoTrack_dz = {fReader, "IsoTrack_dz"};
   // TTreeReaderArray<Float_t> IsoTrack_eta = {fReader, "IsoTrack_eta"};
   // TTreeReaderArray<Float_t> IsoTrack_pfRelIso03_all = {fReader, "IsoTrack_pfRelIso03_all"};
   // TTreeReaderArray<Float_t> IsoTrack_pfRelIso03_chg = {fReader, "IsoTrack_pfRelIso03_chg"};
   // TTreeReaderArray<Float_t> IsoTrack_phi = {fReader, "IsoTrack_phi"};
   // TTreeReaderArray<Float_t> IsoTrack_pt = {fReader, "IsoTrack_pt"};
   // TTreeReaderArray<Float_t> IsoTrack_miniPFRelIso_all = {fReader, "IsoTrack_miniPFRelIso_all"};
   // TTreeReaderArray<Float_t> IsoTrack_miniPFRelIso_chg = {fReader, "IsoTrack_miniPFRelIso_chg"};
   // TTreeReaderValue<Int_t> nJet = {fReader, "nJet"};
   // TTreeReaderArray<UChar_t> Jet_jetId = {fReader, "Jet_jetId"};
   // TTreeReaderArray<UChar_t> Jet_nConstituents = {fReader, "Jet_nConstituents"};
   // TTreeReaderArray<UChar_t> Jet_nElectrons = {fReader, "Jet_nElectrons"};
   // TTreeReaderArray<UChar_t> Jet_nMuons = {fReader, "Jet_nMuons"};
   // TTreeReaderArray<UChar_t> Jet_nSVs = {fReader, "Jet_nSVs"};
   // TTreeReaderArray<Short_t> Jet_electronIdx1 = {fReader, "Jet_electronIdx1"};
   // TTreeReaderArray<Short_t> Jet_electronIdx2 = {fReader, "Jet_electronIdx2"};
   // TTreeReaderArray<Short_t> Jet_muonIdx1 = {fReader, "Jet_muonIdx1"};
   // TTreeReaderArray<Short_t> Jet_muonIdx2 = {fReader, "Jet_muonIdx2"};
   // TTreeReaderArray<Short_t> Jet_svIdx1 = {fReader, "Jet_svIdx1"};
   // TTreeReaderArray<Short_t> Jet_svIdx2 = {fReader, "Jet_svIdx2"};
   // TTreeReaderArray<Int_t> Jet_hfadjacentEtaStripsSize = {fReader, "Jet_hfadjacentEtaStripsSize"};
   // TTreeReaderArray<Int_t> Jet_hfcentralEtaStripSize = {fReader, "Jet_hfcentralEtaStripSize"};
   // TTreeReaderArray<Float_t> Jet_PNetRegPtRawCorr = {fReader, "Jet_PNetRegPtRawCorr"};
   // TTreeReaderArray<Float_t> Jet_PNetRegPtRawCorrNeutrino = {fReader, "Jet_PNetRegPtRawCorrNeutrino"};
   // TTreeReaderArray<Float_t> Jet_PNetRegPtRawRes = {fReader, "Jet_PNetRegPtRawRes"};
   // TTreeReaderArray<Float_t> Jet_area = {fReader, "Jet_area"};
   // TTreeReaderArray<Float_t> Jet_btagDeepFlavB = {fReader, "Jet_btagDeepFlavB"};
   // TTreeReaderArray<Float_t> Jet_btagDeepFlavCvB = {fReader, "Jet_btagDeepFlavCvB"};
   // TTreeReaderArray<Float_t> Jet_btagDeepFlavCvL = {fReader, "Jet_btagDeepFlavCvL"};
   // TTreeReaderArray<Float_t> Jet_btagDeepFlavQG = {fReader, "Jet_btagDeepFlavQG"};
   // TTreeReaderArray<Float_t> Jet_btagPNetB = {fReader, "Jet_btagPNetB"};
   // TTreeReaderArray<Float_t> Jet_btagPNetCvB = {fReader, "Jet_btagPNetCvB"};
   // TTreeReaderArray<Float_t> Jet_btagPNetCvL = {fReader, "Jet_btagPNetCvL"};
   // TTreeReaderArray<Float_t> Jet_btagPNetQvG = {fReader, "Jet_btagPNetQvG"};
   // TTreeReaderArray<Float_t> Jet_btagPNetTauVJet = {fReader, "Jet_btagPNetTauVJet"};
   // TTreeReaderArray<Float_t> Jet_btagRobustParTAK4B = {fReader, "Jet_btagRobustParTAK4B"};
   // TTreeReaderArray<Float_t> Jet_btagRobustParTAK4CvB = {fReader, "Jet_btagRobustParTAK4CvB"};
   // TTreeReaderArray<Float_t> Jet_btagRobustParTAK4CvL = {fReader, "Jet_btagRobustParTAK4CvL"};
   // TTreeReaderArray<Float_t> Jet_btagRobustParTAK4QG = {fReader, "Jet_btagRobustParTAK4QG"};
   // TTreeReaderArray<Float_t> Jet_chEmEF = {fReader, "Jet_chEmEF"};
   // TTreeReaderArray<Float_t> Jet_chHEF = {fReader, "Jet_chHEF"};
   // TTreeReaderArray<Float_t> Jet_eta = {fReader, "Jet_eta"};
   // TTreeReaderArray<Float_t> Jet_hfsigmaEtaEta = {fReader, "Jet_hfsigmaEtaEta"};
   // TTreeReaderArray<Float_t> Jet_hfsigmaPhiPhi = {fReader, "Jet_hfsigmaPhiPhi"};
   // TTreeReaderArray<Float_t> Jet_mass = {fReader, "Jet_mass"};
   // TTreeReaderArray<Float_t> Jet_muEF = {fReader, "Jet_muEF"};
   // TTreeReaderArray<Float_t> Jet_muonSubtrFactor = {fReader, "Jet_muonSubtrFactor"};
   // TTreeReaderArray<Float_t> Jet_neEmEF = {fReader, "Jet_neEmEF"};
   // TTreeReaderArray<Float_t> Jet_neHEF = {fReader, "Jet_neHEF"};
   // TTreeReaderArray<Float_t> Jet_phi = {fReader, "Jet_phi"};
   // TTreeReaderArray<Float_t> Jet_pt = {fReader, "Jet_pt"};
   // TTreeReaderArray<Float_t> Jet_rawFactor = {fReader, "Jet_rawFactor"};
   // TTreeReaderValue<UChar_t> LHE_Njets = {fReader, "LHE_Njets"};
   // TTreeReaderValue<UChar_t> LHE_Nb = {fReader, "LHE_Nb"};
   // TTreeReaderValue<UChar_t> LHE_Nc = {fReader, "LHE_Nc"};
   // TTreeReaderValue<UChar_t> LHE_Nuds = {fReader, "LHE_Nuds"};
   // TTreeReaderValue<UChar_t> LHE_Nglu = {fReader, "LHE_Nglu"};
   // TTreeReaderValue<UChar_t> LHE_NpNLO = {fReader, "LHE_NpNLO"};
   // TTreeReaderValue<UChar_t> LHE_NpLO = {fReader, "LHE_NpLO"};
   TTreeReaderValue<Float_t> LHE_HT = {fReader, "LHE_HT"};
   // TTreeReaderValue<Float_t> LHE_HTIncoming = {fReader, "LHE_HTIncoming"};
   // TTreeReaderValue<Float_t> LHE_Vpt = {fReader, "LHE_Vpt"};
   // TTreeReaderValue<Float_t> LHE_AlphaS = {fReader, "LHE_AlphaS"};
   // TTreeReaderValue<Int_t> nLHEPart = {fReader, "nLHEPart"};
   // TTreeReaderArray<Int_t> LHEPart_pdgId = {fReader, "LHEPart_pdgId"};
   // TTreeReaderArray<Int_t> LHEPart_status = {fReader, "LHEPart_status"};
   // TTreeReaderArray<Int_t> LHEPart_spin = {fReader, "LHEPart_spin"};
   // TTreeReaderArray<Float_t> LHEPart_pt = {fReader, "LHEPart_pt"};
   // TTreeReaderArray<Float_t> LHEPart_eta = {fReader, "LHEPart_eta"};
   // TTreeReaderArray<Float_t> LHEPart_phi = {fReader, "LHEPart_phi"};
   // TTreeReaderArray<Float_t> LHEPart_mass = {fReader, "LHEPart_mass"};
   // TTreeReaderArray<Float_t> LHEPart_incomingpz = {fReader, "LHEPart_incomingpz"};
   // TTreeReaderValue<Int_t> nLowPtElectron = {fReader, "nLowPtElectron"};
   // TTreeReaderArray<Bool_t> LowPtElectron_convVeto = {fReader, "LowPtElectron_convVeto"};
   // TTreeReaderArray<UChar_t> LowPtElectron_convWP = {fReader, "LowPtElectron_convWP"};
   // TTreeReaderArray<UChar_t> LowPtElectron_lostHits = {fReader, "LowPtElectron_lostHits"};
   // TTreeReaderArray<Short_t> LowPtElectron_electronIdx = {fReader, "LowPtElectron_electronIdx"};
   // TTreeReaderArray<Short_t> LowPtElectron_photonIdx = {fReader, "LowPtElectron_photonIdx"};
   // TTreeReaderArray<Int_t> LowPtElectron_charge = {fReader, "LowPtElectron_charge"};
   // TTreeReaderArray<Int_t> LowPtElectron_pdgId = {fReader, "LowPtElectron_pdgId"};
   // TTreeReaderArray<Float_t> LowPtElectron_ID = {fReader, "LowPtElectron_ID"};
   // TTreeReaderArray<Float_t> LowPtElectron_convVtxRadius = {fReader, "LowPtElectron_convVtxRadius"};
   // TTreeReaderArray<Float_t> LowPtElectron_deltaEtaSC = {fReader, "LowPtElectron_deltaEtaSC"};
   // TTreeReaderArray<Float_t> LowPtElectron_dxy = {fReader, "LowPtElectron_dxy"};
   // TTreeReaderArray<Float_t> LowPtElectron_dxyErr = {fReader, "LowPtElectron_dxyErr"};
   // TTreeReaderArray<Float_t> LowPtElectron_dz = {fReader, "LowPtElectron_dz"};
   // TTreeReaderArray<Float_t> LowPtElectron_dzErr = {fReader, "LowPtElectron_dzErr"};
   // TTreeReaderArray<Float_t> LowPtElectron_eInvMinusPInv = {fReader, "LowPtElectron_eInvMinusPInv"};
   // TTreeReaderArray<Float_t> LowPtElectron_energyErr = {fReader, "LowPtElectron_energyErr"};
   // TTreeReaderArray<Float_t> LowPtElectron_eta = {fReader, "LowPtElectron_eta"};
   // TTreeReaderArray<Float_t> LowPtElectron_hoe = {fReader, "LowPtElectron_hoe"};
   // TTreeReaderArray<Float_t> LowPtElectron_mass = {fReader, "LowPtElectron_mass"};
   // TTreeReaderArray<Float_t> LowPtElectron_miniPFRelIso_all = {fReader, "LowPtElectron_miniPFRelIso_all"};
   // TTreeReaderArray<Float_t> LowPtElectron_miniPFRelIso_chg = {fReader, "LowPtElectron_miniPFRelIso_chg"};
   // TTreeReaderArray<Float_t> LowPtElectron_phi = {fReader, "LowPtElectron_phi"};
   // TTreeReaderArray<Float_t> LowPtElectron_pt = {fReader, "LowPtElectron_pt"};
   // TTreeReaderArray<Float_t> LowPtElectron_ptbiased = {fReader, "LowPtElectron_ptbiased"};
   // TTreeReaderArray<Float_t> LowPtElectron_r9 = {fReader, "LowPtElectron_r9"};
   // TTreeReaderArray<Float_t> LowPtElectron_scEtOverPt = {fReader, "LowPtElectron_scEtOverPt"};
   // TTreeReaderArray<Float_t> LowPtElectron_sieie = {fReader, "LowPtElectron_sieie"};
   // TTreeReaderArray<Float_t> LowPtElectron_unbiased = {fReader, "LowPtElectron_unbiased"};
   // TTreeReaderValue<Float_t> GenMET_phi = {fReader, "GenMET_phi"};
   // TTreeReaderValue<Float_t> GenMET_pt = {fReader, "GenMET_pt"};
   // TTreeReaderValue<Float_t> MET_MetUnclustEnUpDeltaX = {fReader, "MET_MetUnclustEnUpDeltaX"};
   // TTreeReaderValue<Float_t> MET_MetUnclustEnUpDeltaY = {fReader, "MET_MetUnclustEnUpDeltaY"};
   // TTreeReaderValue<Float_t> MET_covXX = {fReader, "MET_covXX"};
   // TTreeReaderValue<Float_t> MET_covXY = {fReader, "MET_covXY"};
   // TTreeReaderValue<Float_t> MET_covYY = {fReader, "MET_covYY"};
   // TTreeReaderValue<Float_t> MET_phi = {fReader, "MET_phi"};
   // TTreeReaderValue<Float_t> MET_pt = {fReader, "MET_pt"};
   // TTreeReaderValue<Float_t> MET_significance = {fReader, "MET_significance"};
   // TTreeReaderValue<Float_t> MET_sumEt = {fReader, "MET_sumEt"};
   // TTreeReaderValue<Float_t> MET_sumPtUnclustered = {fReader, "MET_sumPtUnclustered"};
   // TTreeReaderValue<Int_t> nMuon = {fReader, "nMuon"};
   // TTreeReaderArray<UChar_t> Muon_highPtId = {fReader, "Muon_highPtId"};
   // TTreeReaderArray<Bool_t> Muon_highPurity = {fReader, "Muon_highPurity"};
   // TTreeReaderArray<Bool_t> Muon_inTimeMuon = {fReader, "Muon_inTimeMuon"};
   // TTreeReaderArray<Bool_t> Muon_isGlobal = {fReader, "Muon_isGlobal"};
   // TTreeReaderArray<Bool_t> Muon_isPFcand = {fReader, "Muon_isPFcand"};
   // TTreeReaderArray<Bool_t> Muon_isStandalone = {fReader, "Muon_isStandalone"};
   // TTreeReaderArray<Bool_t> Muon_isTracker = {fReader, "Muon_isTracker"};
   // TTreeReaderArray<UChar_t> Muon_jetNDauCharged = {fReader, "Muon_jetNDauCharged"};
   // TTreeReaderArray<Bool_t> Muon_looseId = {fReader, "Muon_looseId"};
   // TTreeReaderArray<Bool_t> Muon_mediumId = {fReader, "Muon_mediumId"};
   // TTreeReaderArray<Bool_t> Muon_mediumPromptId = {fReader, "Muon_mediumPromptId"};
   // TTreeReaderArray<UChar_t> Muon_miniIsoId = {fReader, "Muon_miniIsoId"};
   // TTreeReaderArray<UChar_t> Muon_multiIsoId = {fReader, "Muon_multiIsoId"};
   // TTreeReaderArray<UChar_t> Muon_mvaMuID_WP = {fReader, "Muon_mvaMuID_WP"};
   // TTreeReaderArray<UChar_t> Muon_nStations = {fReader, "Muon_nStations"};
   // TTreeReaderArray<UChar_t> Muon_nTrackerLayers = {fReader, "Muon_nTrackerLayers"};
   // TTreeReaderArray<UChar_t> Muon_pfIsoId = {fReader, "Muon_pfIsoId"};
   // TTreeReaderArray<UChar_t> Muon_puppiIsoId = {fReader, "Muon_puppiIsoId"};
   // TTreeReaderArray<Bool_t> Muon_softId = {fReader, "Muon_softId"};
   // TTreeReaderArray<Bool_t> Muon_softMvaId = {fReader, "Muon_softMvaId"};
   // TTreeReaderArray<UChar_t> Muon_tightCharge = {fReader, "Muon_tightCharge"};
   // TTreeReaderArray<Bool_t> Muon_tightId = {fReader, "Muon_tightId"};
   // TTreeReaderArray<UChar_t> Muon_tkIsoId = {fReader, "Muon_tkIsoId"};
   // TTreeReaderArray<Bool_t> Muon_triggerIdLoose = {fReader, "Muon_triggerIdLoose"};
   // TTreeReaderArray<Short_t> Muon_jetIdx = {fReader, "Muon_jetIdx"};
   // TTreeReaderArray<Short_t> Muon_svIdx = {fReader, "Muon_svIdx"};
   // TTreeReaderArray<Short_t> Muon_fsrPhotonIdx = {fReader, "Muon_fsrPhotonIdx"};
   // TTreeReaderArray<Int_t> Muon_charge = {fReader, "Muon_charge"};
   // TTreeReaderArray<Int_t> Muon_pdgId = {fReader, "Muon_pdgId"};
   // TTreeReaderArray<Float_t> Muon_dxy = {fReader, "Muon_dxy"};
   // TTreeReaderArray<Float_t> Muon_dxyErr = {fReader, "Muon_dxyErr"};
   // TTreeReaderArray<Float_t> Muon_dxybs = {fReader, "Muon_dxybs"};
   // TTreeReaderArray<Float_t> Muon_dz = {fReader, "Muon_dz"};
   // TTreeReaderArray<Float_t> Muon_dzErr = {fReader, "Muon_dzErr"};
   // TTreeReaderArray<Float_t> Muon_eta = {fReader, "Muon_eta"};
   // TTreeReaderArray<Float_t> Muon_ip3d = {fReader, "Muon_ip3d"};
   // TTreeReaderArray<Float_t> Muon_jetPtRelv2 = {fReader, "Muon_jetPtRelv2"};
   // TTreeReaderArray<Float_t> Muon_jetRelIso = {fReader, "Muon_jetRelIso"};
   // TTreeReaderArray<Float_t> Muon_mass = {fReader, "Muon_mass"};
   // TTreeReaderArray<Float_t> Muon_miniPFRelIso_all = {fReader, "Muon_miniPFRelIso_all"};
   // TTreeReaderArray<Float_t> Muon_miniPFRelIso_chg = {fReader, "Muon_miniPFRelIso_chg"};
   // TTreeReaderArray<Float_t> Muon_mvaMuID = {fReader, "Muon_mvaMuID"};
   // TTreeReaderArray<Float_t> Muon_pfRelIso03_all = {fReader, "Muon_pfRelIso03_all"};
   // TTreeReaderArray<Float_t> Muon_pfRelIso03_chg = {fReader, "Muon_pfRelIso03_chg"};
   // TTreeReaderArray<Float_t> Muon_pfRelIso04_all = {fReader, "Muon_pfRelIso04_all"};
   // TTreeReaderArray<Float_t> Muon_phi = {fReader, "Muon_phi"};
   // TTreeReaderArray<Float_t> Muon_pt = {fReader, "Muon_pt"};
   // TTreeReaderArray<Float_t> Muon_ptErr = {fReader, "Muon_ptErr"};
   // TTreeReaderArray<Float_t> Muon_segmentComp = {fReader, "Muon_segmentComp"};
   // TTreeReaderArray<Float_t> Muon_sip3d = {fReader, "Muon_sip3d"};
   // TTreeReaderArray<Float_t> Muon_softMva = {fReader, "Muon_softMva"};
   // TTreeReaderArray<Float_t> Muon_tkRelIso = {fReader, "Muon_tkRelIso"};
   // TTreeReaderArray<Float_t> Muon_tunepRelPt = {fReader, "Muon_tunepRelPt"};
   // TTreeReaderArray<Float_t> Muon_bsConstrainedChi2 = {fReader, "Muon_bsConstrainedChi2"};
   // TTreeReaderArray<Float_t> Muon_bsConstrainedPt = {fReader, "Muon_bsConstrainedPt"};
   // TTreeReaderArray<Float_t> Muon_bsConstrainedPtErr = {fReader, "Muon_bsConstrainedPtErr"};
   // TTreeReaderArray<Float_t> Muon_mvaLowPt = {fReader, "Muon_mvaLowPt"};
   // TTreeReaderArray<Float_t> Muon_mvaTTH = {fReader, "Muon_mvaTTH"};
   // TTreeReaderValue<Int_t> nPhoton = {fReader, "nPhoton"};
   // TTreeReaderArray<Char_t> Photon_seediEtaOriX = {fReader, "Photon_seediEtaOriX"};
   // TTreeReaderArray<UChar_t> Photon_cutBased = {fReader, "Photon_cutBased"};
   // TTreeReaderArray<Bool_t> Photon_electronVeto = {fReader, "Photon_electronVeto"};
   // TTreeReaderArray<Bool_t> Photon_hasConversionTracks = {fReader, "Photon_hasConversionTracks"};
   // TTreeReaderArray<Bool_t> Photon_isScEtaEB = {fReader, "Photon_isScEtaEB"};
   // TTreeReaderArray<Bool_t> Photon_isScEtaEE = {fReader, "Photon_isScEtaEE"};
   // TTreeReaderArray<Bool_t> Photon_mvaID_WP80 = {fReader, "Photon_mvaID_WP80"};
   // TTreeReaderArray<Bool_t> Photon_mvaID_WP90 = {fReader, "Photon_mvaID_WP90"};
   // TTreeReaderArray<Bool_t> Photon_pixelSeed = {fReader, "Photon_pixelSeed"};
   // TTreeReaderArray<UChar_t> Photon_seedGain = {fReader, "Photon_seedGain"};
   // TTreeReaderArray<Short_t> Photon_electronIdx = {fReader, "Photon_electronIdx"};
   // TTreeReaderArray<Short_t> Photon_jetIdx = {fReader, "Photon_jetIdx"};
   // TTreeReaderArray<Int_t> Photon_seediPhiOriY = {fReader, "Photon_seediPhiOriY"};
   // TTreeReaderArray<Int_t> Photon_vidNestedWPBitmap = {fReader, "Photon_vidNestedWPBitmap"};
   // TTreeReaderArray<Float_t> Photon_ecalPFClusterIso = {fReader, "Photon_ecalPFClusterIso"};
   // TTreeReaderArray<Float_t> Photon_energyErr = {fReader, "Photon_energyErr"};
   // TTreeReaderArray<Float_t> Photon_energyRaw = {fReader, "Photon_energyRaw"};
   // TTreeReaderArray<Float_t> Photon_esEffSigmaRR = {fReader, "Photon_esEffSigmaRR"};
   // TTreeReaderArray<Float_t> Photon_esEnergyOverRawE = {fReader, "Photon_esEnergyOverRawE"};
   // TTreeReaderArray<Float_t> Photon_eta = {fReader, "Photon_eta"};
   // TTreeReaderArray<Float_t> Photon_etaWidth = {fReader, "Photon_etaWidth"};
   // TTreeReaderArray<Float_t> Photon_haloTaggerMVAVal = {fReader, "Photon_haloTaggerMVAVal"};
   // TTreeReaderArray<Float_t> Photon_hcalPFClusterIso = {fReader, "Photon_hcalPFClusterIso"};
   // TTreeReaderArray<Float_t> Photon_hoe = {fReader, "Photon_hoe"};
   // TTreeReaderArray<Float_t> Photon_hoe_PUcorr = {fReader, "Photon_hoe_PUcorr"};
   // TTreeReaderArray<Float_t> Photon_mvaID = {fReader, "Photon_mvaID"};
   // TTreeReaderArray<Float_t> Photon_pfChargedIso = {fReader, "Photon_pfChargedIso"};
   // TTreeReaderArray<Float_t> Photon_pfChargedIsoPFPV = {fReader, "Photon_pfChargedIsoPFPV"};
   // TTreeReaderArray<Float_t> Photon_pfChargedIsoWorstVtx = {fReader, "Photon_pfChargedIsoWorstVtx"};
   // TTreeReaderArray<Float_t> Photon_pfPhoIso03 = {fReader, "Photon_pfPhoIso03"};
   // TTreeReaderArray<Float_t> Photon_pfRelIso03_all_quadratic = {fReader, "Photon_pfRelIso03_all_quadratic"};
   // TTreeReaderArray<Float_t> Photon_pfRelIso03_chg_quadratic = {fReader, "Photon_pfRelIso03_chg_quadratic"};
   // TTreeReaderArray<Float_t> Photon_phi = {fReader, "Photon_phi"};
   // TTreeReaderArray<Float_t> Photon_phiWidth = {fReader, "Photon_phiWidth"};
   // TTreeReaderArray<Float_t> Photon_pt = {fReader, "Photon_pt"};
   // TTreeReaderArray<Float_t> Photon_r9 = {fReader, "Photon_r9"};
   // TTreeReaderArray<Float_t> Photon_s4 = {fReader, "Photon_s4"};
   // TTreeReaderArray<Float_t> Photon_sieie = {fReader, "Photon_sieie"};
   // TTreeReaderArray<Float_t> Photon_sieip = {fReader, "Photon_sieip"};
   // TTreeReaderArray<Float_t> Photon_sipip = {fReader, "Photon_sipip"};
   // TTreeReaderArray<Float_t> Photon_trkSumPtHollowConeDR03 = {fReader, "Photon_trkSumPtHollowConeDR03"};
   // TTreeReaderArray<Float_t> Photon_trkSumPtSolidConeDR04 = {fReader, "Photon_trkSumPtSolidConeDR04"};
   // TTreeReaderArray<Float_t> Photon_x_calo = {fReader, "Photon_x_calo"};
   // TTreeReaderArray<Float_t> Photon_y_calo = {fReader, "Photon_y_calo"};
   // TTreeReaderArray<Float_t> Photon_z_calo = {fReader, "Photon_z_calo"};
   // TTreeReaderValue<Int_t> Pileup_nPU = {fReader, "Pileup_nPU"};
   // TTreeReaderValue<Int_t> Pileup_sumEOOT = {fReader, "Pileup_sumEOOT"};
   // TTreeReaderValue<Int_t> Pileup_sumLOOT = {fReader, "Pileup_sumLOOT"};
   // TTreeReaderValue<Float_t> Pileup_nTrueInt = {fReader, "Pileup_nTrueInt"};
   // TTreeReaderValue<Float_t> Pileup_pudensity = {fReader, "Pileup_pudensity"};
   // TTreeReaderValue<Float_t> Pileup_gpudensity = {fReader, "Pileup_gpudensity"};
   // TTreeReaderValue<Float_t> PuppiMET_phi = {fReader, "PuppiMET_phi"};
   // TTreeReaderValue<Float_t> PuppiMET_phiJERDown = {fReader, "PuppiMET_phiJERDown"};
   // TTreeReaderValue<Float_t> PuppiMET_phiJERUp = {fReader, "PuppiMET_phiJERUp"};
   // TTreeReaderValue<Float_t> PuppiMET_phiJESDown = {fReader, "PuppiMET_phiJESDown"};
   // TTreeReaderValue<Float_t> PuppiMET_phiJESUp = {fReader, "PuppiMET_phiJESUp"};
   // TTreeReaderValue<Float_t> PuppiMET_phiUnclusteredDown = {fReader, "PuppiMET_phiUnclusteredDown"};
   // TTreeReaderValue<Float_t> PuppiMET_phiUnclusteredUp = {fReader, "PuppiMET_phiUnclusteredUp"};
   // TTreeReaderValue<Float_t> PuppiMET_pt = {fReader, "PuppiMET_pt"};
   // TTreeReaderValue<Float_t> PuppiMET_ptJERDown = {fReader, "PuppiMET_ptJERDown"};
   // TTreeReaderValue<Float_t> PuppiMET_ptJERUp = {fReader, "PuppiMET_ptJERUp"};
   // TTreeReaderValue<Float_t> PuppiMET_ptJESDown = {fReader, "PuppiMET_ptJESDown"};
   // TTreeReaderValue<Float_t> PuppiMET_ptJESUp = {fReader, "PuppiMET_ptJESUp"};
   // TTreeReaderValue<Float_t> PuppiMET_ptUnclusteredDown = {fReader, "PuppiMET_ptUnclusteredDown"};
   // TTreeReaderValue<Float_t> PuppiMET_ptUnclusteredUp = {fReader, "PuppiMET_ptUnclusteredUp"};
   // TTreeReaderValue<Float_t> PuppiMET_sumEt = {fReader, "PuppiMET_sumEt"};
   // TTreeReaderValue<Float_t> RawMET_phi = {fReader, "RawMET_phi"};
   // TTreeReaderValue<Float_t> RawMET_pt = {fReader, "RawMET_pt"};
   // TTreeReaderValue<Float_t> RawMET_sumEt = {fReader, "RawMET_sumEt"};
   // TTreeReaderValue<Float_t> RawPuppiMET_phi = {fReader, "RawPuppiMET_phi"};
   // TTreeReaderValue<Float_t> RawPuppiMET_pt = {fReader, "RawPuppiMET_pt"};
   // TTreeReaderValue<Float_t> RawPuppiMET_sumEt = {fReader, "RawPuppiMET_sumEt"};
   // TTreeReaderValue<Float_t> Rho_fixedGridRhoAll = {fReader, "Rho_fixedGridRhoAll"};
   // TTreeReaderValue<Float_t> Rho_fixedGridRhoFastjetAll = {fReader, "Rho_fixedGridRhoFastjetAll"};
   // TTreeReaderValue<Float_t> Rho_fixedGridRhoFastjetCentral = {fReader, "Rho_fixedGridRhoFastjetCentral"};
   // TTreeReaderValue<Float_t> Rho_fixedGridRhoFastjetCentralCalo = {fReader, "Rho_fixedGridRhoFastjetCentralCalo"};
   // TTreeReaderValue<Float_t> Rho_fixedGridRhoFastjetCentralChargedPileUp = {fReader, "Rho_fixedGridRhoFastjetCentralChargedPileUp"};
   // TTreeReaderValue<Float_t> Rho_fixedGridRhoFastjetCentralNeutral = {fReader, "Rho_fixedGridRhoFastjetCentralNeutral"};
   // TTreeReaderValue<Int_t> nGenDressedLepton = {fReader, "nGenDressedLepton"};
   // TTreeReaderArray<Bool_t> GenDressedLepton_hasTauAnc = {fReader, "GenDressedLepton_hasTauAnc"};
   // TTreeReaderArray<Int_t> GenDressedLepton_pdgId = {fReader, "GenDressedLepton_pdgId"};
   // TTreeReaderArray<Float_t> GenDressedLepton_eta = {fReader, "GenDressedLepton_eta"};
   // TTreeReaderArray<Float_t> GenDressedLepton_mass = {fReader, "GenDressedLepton_mass"};
   // TTreeReaderArray<Float_t> GenDressedLepton_phi = {fReader, "GenDressedLepton_phi"};
   // TTreeReaderArray<Float_t> GenDressedLepton_pt = {fReader, "GenDressedLepton_pt"};
   // TTreeReaderValue<Int_t> nGenIsolatedPhoton = {fReader, "nGenIsolatedPhoton"};
   // TTreeReaderArray<Float_t> GenIsolatedPhoton_eta = {fReader, "GenIsolatedPhoton_eta"};
   // TTreeReaderArray<Float_t> GenIsolatedPhoton_mass = {fReader, "GenIsolatedPhoton_mass"};
   // TTreeReaderArray<Float_t> GenIsolatedPhoton_phi = {fReader, "GenIsolatedPhoton_phi"};
   // TTreeReaderArray<Float_t> GenIsolatedPhoton_pt = {fReader, "GenIsolatedPhoton_pt"};
   // TTreeReaderValue<Int_t> nSoftActivityJet = {fReader, "nSoftActivityJet"};
   // TTreeReaderArray<Float_t> SoftActivityJet_eta = {fReader, "SoftActivityJet_eta"};
   // TTreeReaderArray<Float_t> SoftActivityJet_phi = {fReader, "SoftActivityJet_phi"};
   // TTreeReaderArray<Float_t> SoftActivityJet_pt = {fReader, "SoftActivityJet_pt"};
   // TTreeReaderValue<Int_t> SoftActivityJetNjets10 = {fReader, "SoftActivityJetNjets10"};
   // TTreeReaderValue<Int_t> SoftActivityJetNjets2 = {fReader, "SoftActivityJetNjets2"};
   // TTreeReaderValue<Int_t> SoftActivityJetNjets5 = {fReader, "SoftActivityJetNjets5"};
   // TTreeReaderValue<Float_t> SoftActivityJetHT = {fReader, "SoftActivityJetHT"};
   // TTreeReaderValue<Float_t> SoftActivityJetHT10 = {fReader, "SoftActivityJetHT10"};
   // TTreeReaderValue<Float_t> SoftActivityJetHT2 = {fReader, "SoftActivityJetHT2"};
   // TTreeReaderValue<Float_t> SoftActivityJetHT5 = {fReader, "SoftActivityJetHT5"};
   // TTreeReaderValue<Int_t> nSubJet = {fReader, "nSubJet"};
   // TTreeReaderArray<Float_t> SubJet_btagDeepB = {fReader, "SubJet_btagDeepB"};
   // TTreeReaderArray<Float_t> SubJet_eta = {fReader, "SubJet_eta"};
   // TTreeReaderArray<Float_t> SubJet_mass = {fReader, "SubJet_mass"};
   // TTreeReaderArray<Float_t> SubJet_n2b1 = {fReader, "SubJet_n2b1"};
   // TTreeReaderArray<Float_t> SubJet_n3b1 = {fReader, "SubJet_n3b1"};
   // TTreeReaderArray<Float_t> SubJet_phi = {fReader, "SubJet_phi"};
   // TTreeReaderArray<Float_t> SubJet_pt = {fReader, "SubJet_pt"};
   // TTreeReaderArray<Float_t> SubJet_rawFactor = {fReader, "SubJet_rawFactor"};
   // TTreeReaderArray<Float_t> SubJet_tau1 = {fReader, "SubJet_tau1"};
   // TTreeReaderArray<Float_t> SubJet_tau2 = {fReader, "SubJet_tau2"};
   // TTreeReaderArray<Float_t> SubJet_tau3 = {fReader, "SubJet_tau3"};
   // TTreeReaderArray<Float_t> SubJet_tau4 = {fReader, "SubJet_tau4"};
   // TTreeReaderValue<Int_t> nTau = {fReader, "nTau"};
   // TTreeReaderArray<UChar_t> Tau_decayMode = {fReader, "Tau_decayMode"};
   // TTreeReaderArray<Bool_t> Tau_idAntiEleDeadECal = {fReader, "Tau_idAntiEleDeadECal"};
   // TTreeReaderArray<UChar_t> Tau_idAntiMu = {fReader, "Tau_idAntiMu"};
   // TTreeReaderArray<Bool_t> Tau_idDecayModeNewDMs = {fReader, "Tau_idDecayModeNewDMs"};
   // TTreeReaderArray<Bool_t> Tau_idDecayModeOldDMs = {fReader, "Tau_idDecayModeOldDMs"};
   // TTreeReaderArray<UChar_t> Tau_idDeepTau2017v2p1VSe = {fReader, "Tau_idDeepTau2017v2p1VSe"};
   // TTreeReaderArray<UChar_t> Tau_idDeepTau2017v2p1VSjet = {fReader, "Tau_idDeepTau2017v2p1VSjet"};
   // TTreeReaderArray<UChar_t> Tau_idDeepTau2017v2p1VSmu = {fReader, "Tau_idDeepTau2017v2p1VSmu"};
   // TTreeReaderArray<UChar_t> Tau_idDeepTau2018v2p5VSe = {fReader, "Tau_idDeepTau2018v2p5VSe"};
   // TTreeReaderArray<UChar_t> Tau_idDeepTau2018v2p5VSjet = {fReader, "Tau_idDeepTau2018v2p5VSjet"};
   // TTreeReaderArray<UChar_t> Tau_idDeepTau2018v2p5VSmu = {fReader, "Tau_idDeepTau2018v2p5VSmu"};
   // TTreeReaderArray<UChar_t> Tau_nSVs = {fReader, "Tau_nSVs"};
   // TTreeReaderArray<Short_t> Tau_charge = {fReader, "Tau_charge"};
   // TTreeReaderArray<Short_t> Tau_decayModePNet = {fReader, "Tau_decayModePNet"};
   // TTreeReaderArray<Short_t> Tau_eleIdx = {fReader, "Tau_eleIdx"};
   // TTreeReaderArray<Short_t> Tau_jetIdx = {fReader, "Tau_jetIdx"};
   // TTreeReaderArray<Short_t> Tau_muIdx = {fReader, "Tau_muIdx"};
   // TTreeReaderArray<Short_t> Tau_svIdx1 = {fReader, "Tau_svIdx1"};
   // TTreeReaderArray<Short_t> Tau_svIdx2 = {fReader, "Tau_svIdx2"};
   // TTreeReaderArray<Float_t> Tau_chargedIso = {fReader, "Tau_chargedIso"};
   // TTreeReaderArray<Float_t> Tau_dxy = {fReader, "Tau_dxy"};
   // TTreeReaderArray<Float_t> Tau_dz = {fReader, "Tau_dz"};
   // TTreeReaderArray<Float_t> Tau_eta = {fReader, "Tau_eta"};
   // TTreeReaderArray<Float_t> Tau_leadTkDeltaEta = {fReader, "Tau_leadTkDeltaEta"};
   // TTreeReaderArray<Float_t> Tau_leadTkDeltaPhi = {fReader, "Tau_leadTkDeltaPhi"};
   // TTreeReaderArray<Float_t> Tau_leadTkPtOverTauPt = {fReader, "Tau_leadTkPtOverTauPt"};
   // TTreeReaderArray<Float_t> Tau_mass = {fReader, "Tau_mass"};
   // TTreeReaderArray<Float_t> Tau_neutralIso = {fReader, "Tau_neutralIso"};
   // TTreeReaderArray<Float_t> Tau_phi = {fReader, "Tau_phi"};
   // TTreeReaderArray<Float_t> Tau_photonsOutsideSignalCone = {fReader, "Tau_photonsOutsideSignalCone"};
   // TTreeReaderArray<Float_t> Tau_probDM0PNet = {fReader, "Tau_probDM0PNet"};
   // TTreeReaderArray<Float_t> Tau_probDM10PNet = {fReader, "Tau_probDM10PNet"};
   // TTreeReaderArray<Float_t> Tau_probDM11PNet = {fReader, "Tau_probDM11PNet"};
   // TTreeReaderArray<Float_t> Tau_probDM1PNet = {fReader, "Tau_probDM1PNet"};
   // TTreeReaderArray<Float_t> Tau_probDM2PNet = {fReader, "Tau_probDM2PNet"};
   // TTreeReaderArray<Float_t> Tau_pt = {fReader, "Tau_pt"};
   // TTreeReaderArray<Float_t> Tau_ptCorrPNet = {fReader, "Tau_ptCorrPNet"};
   // TTreeReaderArray<Float_t> Tau_puCorr = {fReader, "Tau_puCorr"};
   // TTreeReaderArray<Float_t> Tau_qConfPNet = {fReader, "Tau_qConfPNet"};
   // TTreeReaderArray<Float_t> Tau_rawDeepTau2017v2p1VSe = {fReader, "Tau_rawDeepTau2017v2p1VSe"};
   // TTreeReaderArray<Float_t> Tau_rawDeepTau2017v2p1VSjet = {fReader, "Tau_rawDeepTau2017v2p1VSjet"};
   // TTreeReaderArray<Float_t> Tau_rawDeepTau2017v2p1VSmu = {fReader, "Tau_rawDeepTau2017v2p1VSmu"};
   // TTreeReaderArray<Float_t> Tau_rawDeepTau2018v2p5VSe = {fReader, "Tau_rawDeepTau2018v2p5VSe"};
   // TTreeReaderArray<Float_t> Tau_rawDeepTau2018v2p5VSjet = {fReader, "Tau_rawDeepTau2018v2p5VSjet"};
   // TTreeReaderArray<Float_t> Tau_rawDeepTau2018v2p5VSmu = {fReader, "Tau_rawDeepTau2018v2p5VSmu"};
   // TTreeReaderArray<Float_t> Tau_rawIso = {fReader, "Tau_rawIso"};
   // TTreeReaderArray<Float_t> Tau_rawIsodR03 = {fReader, "Tau_rawIsodR03"};
   // TTreeReaderArray<Float_t> Tau_rawPNetVSe = {fReader, "Tau_rawPNetVSe"};
   // TTreeReaderArray<Float_t> Tau_rawPNetVSjet = {fReader, "Tau_rawPNetVSjet"};
   // TTreeReaderArray<Float_t> Tau_rawPNetVSmu = {fReader, "Tau_rawPNetVSmu"};
   // TTreeReaderValue<Float_t> TkMET_phi = {fReader, "TkMET_phi"};
   // TTreeReaderValue<Float_t> TkMET_pt = {fReader, "TkMET_pt"};
   // TTreeReaderValue<Float_t> TkMET_sumEt = {fReader, "TkMET_sumEt"};
   // TTreeReaderValue<Int_t> nTrigObj = {fReader, "nTrigObj"};
   // TTreeReaderArray<Short_t> TrigObj_l1charge = {fReader, "TrigObj_l1charge"};
   // TTreeReaderArray<UShort_t> TrigObj_id = {fReader, "TrigObj_id"};
   // TTreeReaderArray<Int_t> TrigObj_l1iso = {fReader, "TrigObj_l1iso"};
   // TTreeReaderArray<Int_t> TrigObj_filterBits = {fReader, "TrigObj_filterBits"};
   // TTreeReaderArray<Float_t> TrigObj_pt = {fReader, "TrigObj_pt"};
   // TTreeReaderArray<Float_t> TrigObj_eta = {fReader, "TrigObj_eta"};
   // TTreeReaderArray<Float_t> TrigObj_phi = {fReader, "TrigObj_phi"};
   // TTreeReaderArray<Float_t> TrigObj_l1pt = {fReader, "TrigObj_l1pt"};
   // TTreeReaderArray<Float_t> TrigObj_l1pt_2 = {fReader, "TrigObj_l1pt_2"};
   // TTreeReaderArray<Float_t> TrigObj_l2pt = {fReader, "TrigObj_l2pt"};
   // TTreeReaderValue<Int_t> genTtbarId = {fReader, "genTtbarId"};
   // TTreeReaderValue<Int_t> nOtherPV = {fReader, "nOtherPV"};
   // TTreeReaderArray<Float_t> OtherPV_z = {fReader, "OtherPV_z"};
   // TTreeReaderArray<Float_t> OtherPV_score = {fReader, "OtherPV_score"};
   // TTreeReaderValue<UChar_t> PV_npvs = {fReader, "PV_npvs"};
   // TTreeReaderValue<UChar_t> PV_npvsGood = {fReader, "PV_npvsGood"};
   // TTreeReaderValue<Float_t> PV_ndof = {fReader, "PV_ndof"};
   // TTreeReaderValue<Float_t> PV_x = {fReader, "PV_x"};
   // TTreeReaderValue<Float_t> PV_y = {fReader, "PV_y"};
   // TTreeReaderValue<Float_t> PV_z = {fReader, "PV_z"};
   // TTreeReaderValue<Float_t> PV_chi2 = {fReader, "PV_chi2"};
   // TTreeReaderValue<Float_t> PV_score = {fReader, "PV_score"};
   // TTreeReaderValue<Int_t> nSV = {fReader, "nSV"};
   // TTreeReaderArray<Short_t> SV_charge = {fReader, "SV_charge"};
   // TTreeReaderArray<Float_t> SV_dlen = {fReader, "SV_dlen"};
   // TTreeReaderArray<Float_t> SV_dlenSig = {fReader, "SV_dlenSig"};
   // TTreeReaderArray<Float_t> SV_dxy = {fReader, "SV_dxy"};
   // TTreeReaderArray<Float_t> SV_dxySig = {fReader, "SV_dxySig"};
   // TTreeReaderArray<Float_t> SV_pAngle = {fReader, "SV_pAngle"};
   // TTreeReaderArray<UChar_t> boostedTau_genPartFlav = {fReader, "boostedTau_genPartFlav"};
   // TTreeReaderArray<Short_t> boostedTau_genPartIdx = {fReader, "boostedTau_genPartIdx"};
   // TTreeReaderArray<UChar_t> Electron_genPartFlav = {fReader, "Electron_genPartFlav"};
   // TTreeReaderArray<Short_t> Electron_genPartIdx = {fReader, "Electron_genPartIdx"};
   // TTreeReaderArray<UChar_t> FatJet_hadronFlavour = {fReader, "FatJet_hadronFlavour"};
   // TTreeReaderArray<UChar_t> FatJet_nBHadrons = {fReader, "FatJet_nBHadrons"};
   // TTreeReaderArray<UChar_t> FatJet_nCHadrons = {fReader, "FatJet_nCHadrons"};
   // TTreeReaderArray<Short_t> FatJet_genJetAK8Idx = {fReader, "FatJet_genJetAK8Idx"};
   // TTreeReaderArray<UChar_t> GenJetAK8_hadronFlavour = {fReader, "GenJetAK8_hadronFlavour"};
   // TTreeReaderArray<Short_t> GenJetAK8_partonFlavour = {fReader, "GenJetAK8_partonFlavour"};
   // TTreeReaderArray<UChar_t> GenJet_hadronFlavour = {fReader, "GenJet_hadronFlavour"};
   // TTreeReaderArray<Short_t> GenJet_partonFlavour = {fReader, "GenJet_partonFlavour"};
   // TTreeReaderValue<Float_t> GenVtx_t0 = {fReader, "GenVtx_t0"};
   // TTreeReaderArray<UChar_t> Jet_hadronFlavour = {fReader, "Jet_hadronFlavour"};
   // TTreeReaderArray<Short_t> Jet_genJetIdx = {fReader, "Jet_genJetIdx"};
   // TTreeReaderArray<Short_t> Jet_partonFlavour = {fReader, "Jet_partonFlavour"};
   // TTreeReaderArray<UChar_t> LowPtElectron_genPartFlav = {fReader, "LowPtElectron_genPartFlav"};
   // TTreeReaderArray<Short_t> LowPtElectron_genPartIdx = {fReader, "LowPtElectron_genPartIdx"};
   // TTreeReaderArray<UChar_t> Muon_genPartFlav = {fReader, "Muon_genPartFlav"};
   // TTreeReaderArray<Short_t> Muon_genPartIdx = {fReader, "Muon_genPartIdx"};
   // TTreeReaderArray<UChar_t> Photon_genPartFlav = {fReader, "Photon_genPartFlav"};
   // TTreeReaderArray<Short_t> Photon_genPartIdx = {fReader, "Photon_genPartIdx"};
   // TTreeReaderValue<Float_t> MET_fiducialGenPhi = {fReader, "MET_fiducialGenPhi"};
   // TTreeReaderValue<Float_t> MET_fiducialGenPt = {fReader, "MET_fiducialGenPt"};
   // TTreeReaderArray<UChar_t> SubJet_hadronFlavour = {fReader, "SubJet_hadronFlavour"};
   // TTreeReaderArray<UChar_t> SubJet_nBHadrons = {fReader, "SubJet_nBHadrons"};
   // TTreeReaderArray<UChar_t> SubJet_nCHadrons = {fReader, "SubJet_nCHadrons"};
   // TTreeReaderArray<UChar_t> SV_ntracks = {fReader, "SV_ntracks"};
   // TTreeReaderArray<Float_t> SV_chi2 = {fReader, "SV_chi2"};
   // TTreeReaderArray<Float_t> SV_eta = {fReader, "SV_eta"};
   // TTreeReaderArray<Float_t> SV_mass = {fReader, "SV_mass"};
   // TTreeReaderArray<Float_t> SV_ndof = {fReader, "SV_ndof"};
   // TTreeReaderArray<Float_t> SV_phi = {fReader, "SV_phi"};
   // TTreeReaderArray<Float_t> SV_pt = {fReader, "SV_pt"};
   // TTreeReaderArray<Float_t> SV_x = {fReader, "SV_x"};
   // TTreeReaderArray<Float_t> SV_y = {fReader, "SV_y"};
   // TTreeReaderArray<Float_t> SV_z = {fReader, "SV_z"};
   // TTreeReaderArray<UChar_t> Tau_genPartFlav = {fReader, "Tau_genPartFlav"};
   // TTreeReaderArray<Short_t> Tau_genPartIdx = {fReader, "Tau_genPartIdx"};

   NanoV12Selector(TTree * /*tree*/ =0) { }
   NanoV12Selector(TString sampleName, float sumW):
   m_sampleName(sampleName),
   m_sumW(sumW){
      //
      if (m_sampleName.Contains("QCD_HT-40to70"))         m_xsec = 313100000.f;
      else if (m_sampleName.Contains("QCD_HT-70to100"))   m_xsec = 58920000.f;
      else if (m_sampleName.Contains("QCD_HT-100to200"))  m_xsec = 25320000.f;
      else if (m_sampleName.Contains("QCD_HT-200to400"))  m_xsec = 1964000.;
      else if (m_sampleName.Contains("QCD_HT-400to600"))  m_xsec = 96900.f;
      else if (m_sampleName.Contains("QCD_HT-600to800"))  m_xsec = 13600.f;
      else if (m_sampleName.Contains("QCD_HT-800to1000")) m_xsec = 3052.f;
      else if (m_sampleName.Contains("QCD_HT-1000to1200"))m_xsec = 892.9f;
      else if (m_sampleName.Contains("QCD_HT-1200to1500"))m_xsec = 386.3f;
      else if (m_sampleName.Contains("QCD_HT-1500to2000"))m_xsec = 126.7f;
      else if (m_sampleName.Contains("QCD_HT-2000"))      m_xsec = 26.65f;
      else m_xsec = 1.f;
   }

   ~NanoV12Selector() override { }
   Int_t   Version() const override { return 2; }
   void    Begin(TTree *tree) override;
   void    SlaveBegin(TTree *tree) override;
   void    Init(TTree *tree) override;
   Bool_t  Notify() override;
   Bool_t  Process(Long64_t entry) override;
   Int_t   GetEntry(Long64_t entry, Int_t getall = 0) override { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   void    SetOption(const char *option) override { fOption = option; }
   void    SetObject(TObject *obj) override { fObject = obj; }
   void    SetInputList(TList *input) override { fInput = input; }
   TList  *GetOutputList() const override { return fOutput; }
   void    SlaveTerminate() override;
   void    Terminate() override;

   void SetSumOfWeights(float sumW){
      m_sumW = sumW;
   }

private:
   TString m_sampleName;
   float m_sumW;
   float m_xsec;
   std::map<TString, TH1D*> m_histosMap;

   ClassDefOverride(NanoV12Selector,0);
};

#endif

#ifdef NanoV12Selector_cxx
void NanoV12Selector::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the reader is initialized.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   fReader.SetTree(tree);
}

Bool_t NanoV12Selector::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}


#endif // #ifdef NanoV12Selector_cxx
