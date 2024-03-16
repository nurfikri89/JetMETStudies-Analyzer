import os
datasets={}
# datasets["DYJetsToLL_LO_Pythia"]="/DYJetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/RunIISummer20UL18NanoAODv9-20UL18JMENano_106X_upgrade2018_realistic_v16_L1v1-v1/NANOAODSIM"
# datasets["DYJetsToLL_LO_Herwig"]="/DYJetsToLL_M-50_TuneCH3_13TeV-madgraphMLM-herwig7/RunIISummer20UL18NanoAODv9-20UL18JMENano_HerwigJetPartonBugFix_106X_upgrade2018_realistic_v16_L1v1-v1/NANOAODSIM"
# datasets["GJet_Pt-15To6000_Herwig"]="/GJet_Pt-15To6000_TuneCH3-Flat_13TeV_herwig7/RunIISummer20UL17NanoAODv9-20UL17JMENano_106X_mc2017_realistic_v9-v1/NANOAODSIM"
# datasets["GJets_HT-100To200_Pythia"]="/GJets_HT-100To200_TuneCP5_13TeV-madgraphMLM-pythia8/RunIISummer20UL16NanoAODAPVv9-20UL16APVJMENano_4cores5k_106X_mcRun2_asymptotic_preVFP_v11-v1/NANOAODSIM"
# datasets["QCD_HT50to100_LO_Pythia"]  ="/QCD_HT50to100_TuneCP5_PSWeights_13TeV-madgraph-pythia8/RunIISummer20UL18NanoAODv9-20UL18JMENano_106X_upgrade2018_realistic_v16_L1v1-v1/NANOAODSIM"
# datasets["QCD_HT50to100_LO_Herwig"]  ="/QCD_HT50to100_TuneCH3_13TeV-madgraphMLM-herwig7/RunIISummer20UL18NanoAODv9-20UL18JMENano_HerwigJetPartonBugFix_106X_upgrade2018_realistic_v16_L1v1-v1/NANOAODSIM"
# datasets["QCD_HT100to200_LO_Pythia"] ="/QCD_HT100to200_TuneCP5_PSWeights_13TeV-madgraph-pythia8/RunIISummer20UL18NanoAODv9-20UL18JMENano_106X_upgrade2018_realistic_v16_L1v1-v1/NANOAODSIM"
# datasets["QCD_HT100to200_LO_Herwig"] ="/QCD_HT100to200_TuneCH3_13TeV-madgraphMLM-herwig7/RunIISummer20UL18NanoAODv9-20UL18JMENano_HerwigJetPartonBugFix_106X_upgrade2018_realistic_v16_L1v1-v1/NANOAODSIM"
# datasets["QCD_HT200to300_LO_Pythia"] ="/QCD_HT200to300_TuneCP5_PSWeights_13TeV-madgraph-pythia8/RunIISummer20UL18NanoAODv9-20UL18JMENano_106X_upgrade2018_realistic_v16_L1v1-v1/NANOAODSIM"
# datasets["QCD_HT200to300_LO_Herwig"] ="/QCD_HT200to300_TuneCH3_13TeV-madgraphMLM-herwig7/RunIISummer20UL18NanoAODv9-20UL18JMENano_HerwigJetPartonBugFix_106X_upgrade2018_realistic_v16_L1v1-v1/NANOAODSIM"
# datasets["QCD_HT300to500_LO_Pythia"] ="/QCD_HT300to500_TuneCP5_PSWeights_13TeV-madgraph-pythia8/RunIISummer20UL18NanoAODv9-20UL18JMENano_106X_upgrade2018_realistic_v16_L1v1-v1/NANOAODSIM"
# datasets["QCD_HT300to500_LO_Herwig"] ="/QCD_HT300to500_TuneCH3_13TeV-madgraphMLM-herwig7/RunIISummer20UL18NanoAODv9-20UL18JMENano_HerwigJetPartonBugFix_106X_upgrade2018_realistic_v16_L1v1-v1/NANOAODSIM"

datasets["MC23_GJet_PT-15to6000"] = "/GJet_PT-15to6000_TuneCP5-Flat_13p6TeV_pythia8/Run3Summer23NanoAODv12-JMENano12p5_132X_mcRun3_2023_realistic_v5-v1/NANOAODSIM"
datasets["MC23_QCD_PT-50to80"] = "/QCD_PT-50to80_TuneCP5_13p6TeV_pythia8/Run3Summer23NanoAODv12-JMENano12p5_132X_mcRun3_2023_realistic_v5-v1/NANOAODSIM"
datasets["MC23_DYto2L_NLO"] = "/DYto2L-2Jets_MLL-50_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/Run3Summer23NanoAODv12-JMENano12p5_132X_mcRun3_2023_realistic_v5-v2/NANOAODSIM"


for sampleName in datasets:
  dbs = f'dasgoclient -query="file dataset={datasets[sampleName]}"'
  dbsOut = os.popen(dbs).readlines()
  fileList = [f.strip() for f in dbsOut]
  with open(f"./{sampleName}.txt", 'w') as f:
    for file in fileList:
      print(file)
      f.write(f"{file}\n")
