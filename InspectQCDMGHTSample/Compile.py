import ROOT
import os

ROOT.gROOT.SetBatch()

ROOT.gROOT.ProcessLine(".O 2") # Set optimization level to 2
ROOT.gROOT.ProcessLine(".O") # Show optimization level
ROOT.gSystem.SetBuildDir("./obj/",True);
ROOT.gROOT.ProcessLine(".L ./src/NanoV12Selector.C+O")
