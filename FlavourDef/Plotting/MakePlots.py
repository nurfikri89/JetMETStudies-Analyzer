import ROOT
ROOT.gROOT.SetBatch(True)
ROOT.gROOT.LoadMacro("tdrStyle.C")
ROOT.gROOT.ProcessLine("setTDRStyle();");

inDir="../histos/"
# inDir="../histos/Backup/"

samplesList = [
  "DYJetsToLL_LO_Herwig",
  "DYJetsToLL_LO_Pythia",
  "GJet_Pt-15To6000_Herwig",
  "GJets_HT-100To200_Pythia",
  "QCD_HT100to200_LO_Herwig",
  "QCD_HT100to200_LO_Pythia",
  "QCD_HT200to300_LO_Herwig",
  "QCD_HT200to300_LO_Pythia",
  "QCD_HT300to500_LO_Herwig",
  "QCD_HT50to100_LO_Herwig",
  "QCD_HT50to100_LO_Pythia",
  "MC23_GJet_PT-15to6000",
  "MC23_QCD_PT-50to80",
  # "MC23_DYto2L_NLO"
]

inFiles   = {}
for sample in samplesList:
  inFiles[sample]   = ROOT.TFile(f"{inDir}/Histos_{sample}.root","OPEN")


histosDict = {}
histosCloneDict = {}
for sample in samplesList:
  histosInSampleDict = {}
  histosCloneInSampleDict = {}
  for key in inFiles[sample].GetListOfKeys():
    if key.ReadObj().Class() == ROOT.TH1D.Class():
      objName = key.GetName()
      histosInSampleDict[objName] = inFiles[sample].Get(objName)
      if "qgl_ptD" in objName: histosInSampleDict[objName].Rebin(5)
      if "qgl_axis" in objName: histosInSampleDict[objName].Rebin(2)
      histosCloneInSampleDict[objName] = histosInSampleDict[objName].Clone(f"{str(objName)}_C")
  histosDict[sample] = histosInSampleDict
  histosCloneDict[sample] = histosCloneInSampleDict



def GetBinForLegend(ptBin):
  ptBinStr = "Jet "
  if   "pt20To50"   in ptBin: ptBinStr = " 20 < Jet pT < 50 GeV"
  elif "pt50To100"  in ptBin: ptBinStr = " 50 < Jet pT < 100 GeV"
  elif "pt100To150" in ptBin: ptBinStr = " 100 < Jet pT < 150 GeV"
  elif "pt150To200" in ptBin: ptBinStr = " 150 < Jet pT < 200 GeV"
  elif "pt200To300" in ptBin: ptBinStr = " 200 < Jet pT < 300 GeV"
  elif "pt300ToInf" in ptBin: ptBinStr = " Jet pT > 300 GeV"
  elif "pt20ToInf" in ptBin: ptBinStr  = " Jet pT > 20 GeV"
  return ptBinStr


def Plot(histosToPlot, varName, ptBin, canvName):

  canv = ROOT.TCanvas(f"canv_{varName}", f"canv_{varName}", 900, 900)
  canv.SetCanvasSize(900,900)
  canv.SetLeftMargin(0.15);
  canv.SetRightMargin(0.08);
  canv.SetTopMargin(0.05);

  legend = ROOT.TLegend(0.65,0.55,0.85,0.85)
  legend.SetTextSize(0.03)
  legend.SetLineWidth(0)
  legend.SetFillStyle(0)
  legend.SetBorderSize(0)

  maximum = -1
  for histo in histosToPlot:
    histo[0].Scale(1./histo[0].Integral(0,500))
    histMax = histo[0].GetMaximum()
    if histMax > maximum: maximum = histMax

  for i, histo in enumerate(histosToPlot):
    h = histo[0]
    color = histo[1]
    style = histo[2]
    leg = histo[3]
    h.SetMarkerColor(color+1)
    h.SetLineColor(color+1)
    h.SetMarkerStyle(style)
    h.SetMarkerSize(1.8)
    legend.AddEntry(h,leg,"p")
    if i == 0:
      h.SetMaximum(1.8*maximum)
      h.SetMinimum(0.0001)
      h.GetYaxis().SetTitle("Arbitrary Unit")
      if "qgl_axis" in varName:  h.GetXaxis().SetTitle("#sigma_{2}")
      elif "qgl_ptD" in varName: h.GetXaxis().SetTitle("pTD")
      elif "qgl_mult" in varName: h.GetXaxis().SetTitle("multiplicity")
      h.Draw("P")
    else:
      h.Draw("PSAME")

  legend.Draw("SAME")

  ptBinStr = GetBinForLegend(ptBin)
  latex = ROOT.TLatex()
  latex.SetNDC();
  latex.SetTextFont( 42 );
  latex.SetTextSize( 0.028 );
  latex.SetTextColor( 1 );
  latex.SetTextAlign( 12 );
  latex.DrawLatex(0.60, 0.90, ptBinStr );

  canv.SaveAs(f"./plots/{canvName}.pdf")
  del canv

def PlotForAVariablePythia(varName, ptBin=""):
  if ptBin != "": ptBin = f"{ptBin}_"
  histosToPlot = [
    (histosCloneDict["DYJetsToLL_LO_Pythia"]    [f"h_{ptBin}gluonjet_{varName}"],ROOT.kRed,20,   "Z+jet (gluon)"),
    (histosCloneDict["GJets_HT-100To200_Pythia"][f"h_{ptBin}gluonjet_{varName}"],ROOT.kBlue,21,  "#gamma+jet (gluon)"),
    (histosCloneDict["QCD_HT50to100_LO_Pythia"] [f"h_{ptBin}gluonjet_{varName}"],ROOT.kGreen,22, "dijet (gluon)"),
    (histosCloneDict["DYJetsToLL_LO_Pythia"]    [f"h_{ptBin}quarkjet_{varName}"],ROOT.kRed,24,   "Z+jet (quark)"),
    (histosCloneDict["GJets_HT-100To200_Pythia"][f"h_{ptBin}quarkjet_{varName}"],ROOT.kBlue,25,  "#gamma+jet (quark)"),
    (histosCloneDict["QCD_HT50to100_LO_Pythia"] [f"h_{ptBin}quarkjet_{varName}"],ROOT.kGreen,26, "dijet (quark)"),
  ]
  Plot(histosToPlot, varName, ptBin, f"Pythia_GluonVsQuark_{varName}_{ptBin}")


def PlotForAVariablePythiaRun3(varName, ptBin=""):
  if ptBin != "": ptBin = f"{ptBin}_"
  histosToPlot = [
    # (histosCloneDict["MC23_DYto2L_NLO"]      [f"h_{ptBin}gluonjet_{varName}"],ROOT.kRed,20,   "Z+jet (gluon)"),
    (histosCloneDict["MC23_GJet_PT-15to6000"][f"h_{ptBin}gluonjet_{varName}"],ROOT.kBlue,21,  "#gamma+jet (gluon)"),
    (histosCloneDict["MC23_QCD_PT-50to80"]   [f"h_{ptBin}gluonjet_{varName}"],ROOT.kGreen,22, "dijet (gluon)"),
    # (histosCloneDict["MC23_DYto2L_NLO"]      [f"h_{ptBin}quarkjet_{varName}"],ROOT.kRed,24,   "Z+jet (quark)"),
    (histosCloneDict["MC23_GJet_PT-15to6000"][f"h_{ptBin}quarkjet_{varName}"],ROOT.kBlue,25,  "#gamma+jet (quark)"),
    (histosCloneDict["MC23_QCD_PT-50to80"]   [f"h_{ptBin}quarkjet_{varName}"],ROOT.kGreen,26, "dijet (quark)"),
  ]
  Plot(histosToPlot, varName, ptBin, f"Run3_Pythia_GluonVsQuark_{varName}_{ptBin}")


def PlotForAVariableHerwig(varName, ptBin=""):
  if ptBin != "": ptBin = f"{ptBin}_"
  histosToPlot = [
    (histosCloneDict["DYJetsToLL_LO_Herwig"]    [f"h_{ptBin}gluonjet_{varName}"],ROOT.kRed,20,   "Z+jet (gluon)"),
    # (histosCloneDict["GJet_Pt-15To6000_Herwig"] [f"h_{ptBin}gluonjet_{varName}"],ROOT.kBlue,21,  "#gamma+jet (gluon)"),
    (histosCloneDict["QCD_HT50to100_LO_Herwig"] [f"h_{ptBin}gluonjet_{varName}"],ROOT.kGreen,22, "dijet (gluon)"),
    (histosCloneDict["DYJetsToLL_LO_Herwig"]    [f"h_{ptBin}quarkjet_{varName}"],ROOT.kRed,24,   "Z+jet (quark)"),
    # (histosCloneDict["GJet_Pt-15To6000_Herwig"] [f"h_{ptBin}quarkjet_{varName}"],ROOT.kBlue,25,  "#gamma+jet (quark)"),
    (histosCloneDict["QCD_HT50to100_LO_Herwig"] [f"h_{ptBin}quarkjet_{varName}"],ROOT.kGreen,26, "dijet (quark)"),
  ]
  Plot(histosToPlot, varName, ptBin, f"Herwig_GluonVsQuark_{varName}_{ptBin}")



ptBinsList = [
  "pt20ToInf",
  "pt20To50",
  "pt50To100",
  "pt100To150",
  "pt150To200",
  "pt200To300",
  "pt300ToInf",
]

for ptBin in ptBinsList:
  PlotForAVariablePythia("qgl_axis",ptBin)
  PlotForAVariablePythia("qgl_ptD", ptBin)
  PlotForAVariablePythia("qgl_mult",ptBin)
  PlotForAVariablePythiaRun3("qgl_axis",ptBin)
  PlotForAVariablePythiaRun3("qgl_ptD", ptBin)
  PlotForAVariablePythiaRun3("qgl_mult",ptBin)

for ptBin in ptBinsList:
  PlotForAVariableHerwig("qgl_axis",ptBin)
  PlotForAVariableHerwig("qgl_ptD", ptBin)
  PlotForAVariableHerwig("qgl_mult",ptBin)



#
#
#
#
########################
def StackInAGivenSample(histosToPlot, varName, ptBin, canvName):

  canv = ROOT.TCanvas(f"canv_{varName}", f"canv_{varName}", 900, 900)
  canv.SetCanvasSize(900,900)

  legend = ROOT.TLegend(0.65,0.55,0.85,0.85)
  legend.SetTextSize(0.03)
  legend.SetLineWidth(0)
  legend.SetFillStyle(0)
  legend.SetBorderSize(0)

  maximum = -1
  for histo in histosToPlot:
    histMax = histo[0].GetMaximum()
    if histMax > maximum: maximum = histMax

  stack = ROOT.THStack(f"stack_{varName}", f"stack_{varName}")
  for i, histo in enumerate(histosToPlot):
    h = histo[0]
    color = histo[1]
    leg = histo[2]
    h.SetFillColor(color+1)
    h.SetLineColor(ROOT.kBlack)
    h.SetLineWidth(2)
    stack.Add(h)
    legend.AddEntry(h, leg, "f")
  h_totalC = stack.GetStack().Last().Clone(f"TotalMC_{varName}")

  stack.Draw("hist")
  if "qgl_axis" in varName: stack.GetXaxis().SetTitle("#sigma_{2}")
  elif "qgl_ptD" in varName: stack.GetXaxis().SetTitle("pTD")
  elif "qgl_mult" in varName: stack.GetXaxis().SetTitle("multiplicity")
  stack.GetYaxis().SetTitle("Jets")
  legend.Draw("SAME")

  canv.Update()

  ptBinStr = GetBinForLegend(ptBin)
  latex = ROOT.TLatex()
  latex.SetNDC();
  latex.SetTextFont( 42 );
  latex.SetTextSize( 0.028 );
  latex.SetTextColor( 1 );
  latex.SetTextAlign( 12 );
  latex.DrawLatex(0.60, 0.90, ptBinStr );

  canv.SaveAs(f"./plots/{canvName}.pdf")

  del canv


def PlotForStackAVariableAndSample(varName, sampleName, ptBin=""):
  if ptBin != "": ptBin = f"{ptBin}_"
  histosToPlot = [
    (histosDict[sampleName] [f"h_{ptBin}gluonjet_{varName}"],ROOT.kRed,   "gluon"),
    (histosDict[sampleName] [f"h_{ptBin}quarkjet_{varName}"],ROOT.kBlue,  "quark"),
    (histosDict[sampleName] [f"h_{ptBin}undefjet_{varName}"],ROOT.kGreen, "undefined"),
    (histosDict[sampleName] [f"h_{ptBin}others_{varName}"],  ROOT.kGray,  "others"),
  ]
  StackInAGivenSample(histosToPlot, varName, ptBin, f"Stack_{sampleName}_{varName}_{ptBin}")


ptBinsList = [
  "pt20ToInf",
  # "pt20To50",
  # "pt50To100",
  # "pt100To150",
  # "pt150To200",
  # "pt200To300",
  # "pt300ToInf",
]
for sampleName in samplesList:
  for ptBin in ptBinsList:
    PlotForStackAVariableAndSample("qgl_axis",sampleName,ptBin)
    PlotForStackAVariableAndSample("qgl_ptD", sampleName,ptBin)
    PlotForStackAVariableAndSample("qgl_mult",sampleName,ptBin)

