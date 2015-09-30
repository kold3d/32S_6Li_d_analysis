#define SMDMAnalysis_cxx
// The class definition in SMDMAnalysis.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.

// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// Root > T->Process("SMDMAnalysis.C")
// Root > T->Process("SMDMAnalysis.C","some options")
// Root > T->Process("SMDMAnalysis.C+")
//

#include "SMDMAnalysis.h"
#include "SMDMCalibration.h"
#include <TH2.h>
#include <TStyle.h>

#include <iostream>
#include <fstream>

void SMDMAnalysis::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   std::cout << "Starting..." <<std::endl;
   TString option = GetOption();

  for(Int_t i=0; i<3; i++) {
    for(Int_t j=0; j<4;j++ ) {
      TString name = Form("timing_%d_%d",i+1,j+1);
      TString name1 = Form("raw_energy_%d_%d",i+1,j+1);
      //h_raw[i]= new TH1F(name, name, 200,0,10000);
      si_hist[i][j] = new TH1F(name1,name1,1000,0,40000);
      //si_t_hist[i][j] = new TH1F(name,name,200,10000,30000);
    }
  }

  si_t_all = new TH1F("si_t_all","si_t_all",10000,0,40000);  

   fEventSeen = 0;

}

void SMDMAnalysis::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

Bool_t SMDMAnalysis::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either SMDMAnalysis::GetEntry() or TBranch::GetEntry()
   // to read either all or the required parts of the data. When processing
   // keyed objects with PROOF, the object is already loaded and is available
   // via the fObject pointer.
   //
   // This function should contain the "body" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.

  fChain->GetTree()->GetEntry(entry);
  fEventSeen++;

  if(fEventSeen !=0 && fEventSeen % 10000 ==0)
    std::cout << "Processed "<< fEventSeen << " events..." << std::endl;

  Int_t highSiEDet = -1;
  Int_t highSiEQuad = -1;
  float highSiE = 0.;
  float highSiT = 0.;
  Int_t highSiIndex = -1;

  float calE,rawE;

  for(Int_t i=0; i<siQuadMul; i++) {

    //if (siQuadT[i]> 0.) continue;

  //si_t_hist[highSiEDet-1][highSiEQuad-1]->Fill(highSiT);

     calE = siQuadE[i]*SMDMCalibration::paramList1.det[siQuadDet[i]-1][siQuadQuad[i]-1][0] + SMDMCalibration::paramList1.det[siQuadDet[i]-1][siQuadQuad[i]-1][1];
      rawE = siQuadE[i];
    
      if(calE>highSiE) {
	highSiE = calE;
	highSiEDet = siQuadDet[i];
	highSiEQuad = siQuadQuad[i];
	highSiT = siQuadT[i];
	highSiIndex = siQuadIndex[i];
      }
    //printf("det: %d quad: %d index: %d\n",highSiEDet,highSiEQuad,highSiIndex);
  }

  if(highSiE<=0.) return kTRUE;

  if(highSiEDet==0) return kTRUE;

  if(highSiT<0) return kTRUE;

  //printf("highSiE: %f highSiEDet: %d highSiEQuad: %d highSiT: %f\n",highSiE,highSiEDet,highSiEQuad,highSiT);

  si_t_all->Fill(highSiT);

  si_hist[highSiEDet-1][highSiEQuad]->Fill(highSiE);

  //si_t_hist[highSiEDet-1][highSiEQuad-1]->Fill(highSiT);

   return kTRUE;
}

void SMDMAnalysis::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void SMDMAnalysis::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

}
