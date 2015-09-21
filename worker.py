import ROOT

def analyze(filename) :
    hist = None
    ROOT.gROOT.SetBatch()
    file = ROOT.TFile("/hdfs"+filename[1][31:])
    print "/hdfs"+filename[1][31:]
    tree = file.Get("rawDataTree")
    ROOT.gSystem.Load("libMinuit2")
    ROOT.gSystem.Load("libMDM_test_analysis.so")
    print "Starting Calibrations Loading..."
    ROOT.SMDMCalibration.Init()
    print "Finished Calibrations Loading..."
    selector = ROOT.SMDMAnalysis();
    tree.Process(selector)
    returnList = []
    objs = ROOT.gDirectory.GetList()
    for obj in objs :
      if (obj.ClassName() == "TH1F" or obj.ClassName() == "TH2F") :
	obj.SetDirectory(0)
	returnList.append(obj)
    return returnList
