#include<iostream>
#include "TFile.h"
#include "TH1D.h"
#include "TLegend.h"
#include "TLine.h"
#include "TPaveText.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "THStack.h"
#include "TPad.h"
#include "TVirtualPadPainter.h"
#include "TViewer3DPad.h"
#include "TVirtualPad.h"
#include "TAttBBox2D.h"
#include "TPoint.h"
#include "GuiTypes.h"
#include "TTree.h"
#include "TParticle.h"
#include "TClonesArray.h"
#include "TH1.h"
#include "TH2.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TLegend.h"
#include "TLatex.h"
#include "TObjArray.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "math.h"
#include <TAttMarker.h>


void postTMVA_plot(){

double m_H1 = 0;
double m_H2 = 0;


TH1D* histo1;
TH1D* histo2;

TH1D *histo3 = new TH1D("mh1","",100,0,250);
TH1D *histo4 = new TH1D("mh2","",100,0,250);


TFile file1("TMVApp_signal.root"); // opening file
file1.GetObject("higgs_mass", histo1);

TFile file2("TMVApp_Background.root"); // opening file
file2.GetObject("higgs_mass", histo2);

TFile *f1 = new TFile("/home/george/Desktop/wrong_weights/rootfiles_total2/crrct_sol_half2_final.root");
TTree * tree1 = (TTree*) f1->Get("mytreecrrct");
tree1->SetBranchAddress("m_H",&m_H1);

TFile *f2 = new TFile("/home/george/Desktop/wrong_weights/rootfiles_total2/wrng_sol_half2_quarter.root");
TTree * tree2 = (TTree*) f2->Get("mytreewrng2");
tree2->SetBranchAddress("m_H",&m_H2);

        for(int i=0; i<tree1->GetEntries(); i++){
                tree1->GetEntry(i);
                histo3->Fill(m_H1);
        }


        for(int j=0;j<tree2->GetEntries(); j++){
                tree2->GetEntry(j);
                histo4->Fill(m_H2);
        }

        
TCanvas *c1 = new TCanvas("c1","m_H");
c1->cd();

histo2->SetLineColor(2);
//histo3->SetLineColor(7);
//histo4->SetLineColor(3);

histo1->DrawNormalized();
histo2->DrawNormalized("same");
//histo3->DrawNormalized("same");
//histo4->DrawNormalized("same");

c1->SaveAs("m_H.png");

TCanvas *c2 = new TCanvas("c2","m_H2");
c2->cd();

histo4->SetLineColor(2);

histo3->DrawNormalized();
histo4->DrawNormalized("same");

c2->SaveAs("m_H_before.png");
}
