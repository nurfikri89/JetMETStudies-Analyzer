import os
import glob
import argparse
import ROOT
ROOT.gROOT.SetBatch()
# ROOT.gROOT.LoadMacro("NanoV12Selector.C+")
ROOT.gSystem.Load("obj/NanoV12Selector_C.so")

XROOTD="root://xrootd-cms.infn.it/"

parser = argparse.ArgumentParser("")
parser.add_argument('-s', '--sample',   type=str,  default="")
parser.add_argument('-c', '--cpus',     type=int,  default=1)
parser.add_argument('-f', '--nfiles',   type=int,  default=-1)
args = parser.parse_args()

sampleName = args.sample
nworkers = args.cpus
nfiles = args.nfiles

inFiles=[]
with open(f"./txtfiles/{sampleName}.txt", 'r') as txtfile:
  inFiles = [line.rstrip() for line in txtfile]

if nfiles > 0:
  print(f"Only process {nfiles} files")
  inFiles = inFiles[0:nfiles]
else:
  print("Process all files")

inFilesFinal = [XROOTD+f for f in inFiles]

print(f"Running sample = {sampleName}")
#
#
#
treeRuns = ROOT.TChain("Runs")
for f in inFilesFinal:
  treeRuns.Add(f)

nEntries = treeRuns.GetEntries()

treeRunsReader = ROOT.TTreeReader(treeRuns)
genEventSumw = ROOT.TTreeReaderValue[ROOT.Double_t](treeRunsReader, "genEventSumw")

sumOfWeight = 0
for iEntry in range(0,nEntries):
  treeRunsReader.SetEntry(iEntry)
  sumOfWeight += genEventSumw.Get()[0]

print(f"sumOfWeight = {sumOfWeight}")

#
#
#
treeEvents = ROOT.TChain("Events")
for f in inFilesFinal:
  treeEvents.Add(f)

if nworkers > 1:
  ROOT.TProof.Open(f"workers={nworkers}")

analyzer = ROOT.NanoV12Selector(sampleName,sumOfWeight)
treeEvents.Process(analyzer)
