echo ""
echo "=====START"
date
echo ""

# SAMPLE="DYJetsToLL_LO_Pythia"; ANALYSIS="ZPlusJets"
# SAMPLE="DYJetsToLL_LO_Herwig"; ANALYSIS="ZPlusJets"

# SAMPLE="QCD_HT100to200_LO_Pythia"; ANALYSIS="Dijets"
# SAMPLE="QCD_HT100to200_LO_Herwig"; ANALYSIS="Dijets"

# SAMPLE="GJets_HT-100To200_Pythia"; ANALYSIS="PhotonPlusJets"
# SAMPLE="GJet_Pt-15To6000_Herwig"; ANALYSIS="PhotonPlusJets"

SAMPLE="MC23_GJet_PT-15to6000"; ANALYSIS="PhotonPlusJets"

python3 RunAnaPhysDef.py --sample $SAMPLE --analysis $ANALYSIS --cpus 1 --nfiles 1

echo ""
echo ""
date
echo "=====END"
