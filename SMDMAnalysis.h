//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Sep 21 10:45:22 2015 by ROOT version 5.34/24
// from TTree rawDataTree/Experimental Event Data
// found on file: run0915a_001001_t.root
//////////////////////////////////////////////////////////

#ifndef SMDMAnalysis_h
#define SMDMAnalysis_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>

#include <TH1F.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class SMDMAnalysis : public TSelector {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

   // Declaration of leaf types
   Int_t           siStripFrontMul;
   Int_t           siStripFrontId[16];   //[siStripFrontMul]
   Int_t           siStripFrontE[16];   //[siStripFrontMul]
   Int_t           siStripFrontT[16];   //[siStripFrontMul]
   Int_t           siStripRearMul;
   Int_t           siStripRearId[16];   //[siStripRearMul]
   Int_t           siStripRearE[16];   //[siStripRearMul]
   Int_t           siStripRearT[16];   //[siStripRearMul]
   Int_t           siQuadMul;
   Int_t           siQuadDet[12];   //[siQuadMul]
   Int_t           siQuadQuad[12];   //[siQuadMul]
   Int_t           siQuadIndex[12];   //[siQuadMul]
   Int_t           siQuadE[12];   //[siQuadMul]
   Int_t           siQuadT[12];   //[siQuadMul]
   Int_t           wireMul;
   Int_t           wireLeftE[3];   //[wireMul]
   Int_t           wireRightE[3];   //[wireMul]
   Int_t           wireLeftT[3];   //[wireMul]
   Int_t           wireRightT[3];   //[wireMul]
   Int_t           pmMul;
   Int_t           pmId[2];   //[pmMul]
   Int_t           pmE[2];   //[pmMul]
   Int_t           pmT[2];   //[pmMul]
   Int_t           tdcRef;

   // List of branches
   TBranch        *b_siStripFrontMul;   //!
   TBranch        *b_siStripFrontId;   //!
   TBranch        *b_siStripFrontE;   //!
   TBranch        *b_siStripFrontT;   //!
   TBranch        *b_siStripRearMul;   //!
   TBranch        *b_siStripRearId;   //!
   TBranch        *b_siStripRearE;   //!
   TBranch        *b_siStripRearT;   //!
   TBranch        *b_siQuadMul;   //!
   TBranch        *b_siQuadDet;   //!
   TBranch        *b_siQuadQuad;   //!
   TBranch        *b_siQuadIndex;   //!
   TBranch        *b_siQuadE;   //!
   TBranch        *b_siQuadT;   //!
   TBranch        *b_wireMul;   //!
   TBranch        *b_wireLeftE;   //!
   TBranch        *b_wireRightE;   //!
   TBranch        *b_wireLeftT;   //!
   TBranch        *b_wireRightT;   //!
   TBranch        *b_pmMul;   //!
   TBranch        *b_pmId;   //!
   TBranch        *b_pmE;   //!
   TBranch        *b_pmT;   //!
   TBranch        *b_tdcRef;   //!

   Int_t fEventSeen;

   TH1F* si_hist[3][4];
   TH1F* si_t_hist[3][4];

   SMDMAnalysis(TTree * /*tree*/ =0) : fChain(0) { }
   virtual ~SMDMAnalysis() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(SMDMAnalysis,0);
};

#endif

#ifdef SMDMAnalysis_cxx
void SMDMAnalysis::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("siStripFrontMul", &siStripFrontMul, &b_siStripFrontMul);
   fChain->SetBranchAddress("siStripFrontId", siStripFrontId, &b_siStripFrontId);
   fChain->SetBranchAddress("siStripFrontE", siStripFrontE, &b_siStripFrontE);
   fChain->SetBranchAddress("siStripFrontT", siStripFrontT, &b_siStripFrontT);
   fChain->SetBranchAddress("siStripRearMul", &siStripRearMul, &b_siStripRearMul);
   fChain->SetBranchAddress("siStripRearId", siStripRearId, &b_siStripRearId);
   fChain->SetBranchAddress("siStripRearE", siStripRearE, &b_siStripRearE);
   fChain->SetBranchAddress("siStripRearT", siStripRearT, &b_siStripRearT);
   fChain->SetBranchAddress("siQuadMul", &siQuadMul, &b_siQuadMul);
   fChain->SetBranchAddress("siQuadDet", siQuadDet, &b_siQuadDet);
   fChain->SetBranchAddress("siQuadQuad", siQuadQuad, &b_siQuadQuad);
   fChain->SetBranchAddress("siQuadIndex", siQuadIndex, &b_siQuadIndex);
   fChain->SetBranchAddress("siQuadE", siQuadE, &b_siQuadE);
   fChain->SetBranchAddress("siQuadT", siQuadT, &b_siQuadT);
   fChain->SetBranchAddress("wireMul", &wireMul, &b_wireMul);
   fChain->SetBranchAddress("wireLeftE", wireLeftE, &b_wireLeftE);
   fChain->SetBranchAddress("wireRightE", wireRightE, &b_wireRightE);
   fChain->SetBranchAddress("wireLeftT", wireLeftT, &b_wireLeftT);
   fChain->SetBranchAddress("wireRightT", wireRightT, &b_wireRightT);
   fChain->SetBranchAddress("pmMul", &pmMul, &b_pmMul);
   fChain->SetBranchAddress("pmId", pmId, &b_pmId);
   fChain->SetBranchAddress("pmE", pmE, &b_pmE);
   fChain->SetBranchAddress("pmT", pmT, &b_pmT);
   fChain->SetBranchAddress("tdcRef", &tdcRef, &b_tdcRef);
}

Bool_t SMDMAnalysis::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

#endif // #ifdef SMDMAnalysis_cxx
