void Run(TTree* tree) {
  gSystem->Load("libMinuit2");
  gSystem->Load("build/libs32_li6_d_analysis.so");
  SMDMCalibration::Init();
  rawDataTree->Process("SMDMAnalysis");
}
