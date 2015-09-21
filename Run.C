void Run(TTree* tree) {
  gSystem->Load("libMinuit2");
  gSystem->Load("build/libMDM_test_analysis.so");
  SMDMCalibration::Init();
  rawDataTree->Process("SMDMAnalysis");
}
