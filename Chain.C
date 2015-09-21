{
  TChain * chain = new TChain("rawDataTree");

  TString Path = "/hdfs/data/run0715a/tree/";

  chain->Add(Path+"run0715_040*_t.root");
  chain->Add(Path+"run0715_041*_t.root");
  chain->Add(Path+"run0715_042*_t.root");
}
