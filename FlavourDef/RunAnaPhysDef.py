import os
import glob
import argparse
import ROOT
ROOT.gROOT.SetBatch()
# ROOT.gROOT.LoadMacro("AnaPhysDef.C+")
ROOT.gSystem.Load("obj/AnaPhysDef_C.so")

XROOTD="root://xrootd-cms.infn.it/"

parser = argparse.ArgumentParser("")
parser.add_argument('-s', '--sample',   type=str,  default="")
parser.add_argument('-c', '--cpus',     type=int,  default=1)
parser.add_argument('-a', '--analysis', type=str,  default="")
parser.add_argument('-f', '--nfiles',   type=int,  default=-1)
args = parser.parse_args()

sampleName = args.sample
nworkers = args.cpus
analysis = args.analysis
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

tree = ROOT.TChain("Events")
for f in inFilesFinal:
  # if "DYJetsToLL_LO_Herwig" in sampleName:
  #   if "DB72621B-C791-A24F-9584-38A773F4CE4D" in f: continue
  # print(f)
  tree.Add(f)

# nEvents=tree.GetEntries()
# print(f"{nEvents=} in sample")

if nworkers > 1:
  ROOT.TProof.Open(f"workers={nworkers}")

analyzer = ROOT.AnaPhysDef(sampleName,analysis)
tree.Process(analyzer)
