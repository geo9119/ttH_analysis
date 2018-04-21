#include "TH1D.h"
#include "TH1F.h"
#include "TH2D.h"
#include "TH2F.h"
#include "TTree.h"
#include "TFile.h"
#include "TDirectory.h"
#include "TPaveText.h"
#include "TLegend.h"
#include "TCanvas.h"
#include "TMath.h"
#include "TStyle.h"
#include "TChain.h"
#include <iostream>
#include <fstream>
#include "TSystem.h"
#include "TROOT.h"
#include "TLorentzVector.h"
#include <vector>
#include <cstdlib>
#include </home/george/Desktop/efficiency_TMVA/TMVA2/setTDRStyle_teliko.C>


void hmass(){

// gROOT->LoadMacro("setTDRStyle_teliko.C");
 setTDRStyle_teliko();



float m_H = 0;
float prob = 0;
float ratio = 0;
int eventnumber = 0;

int in[6] = {};
int out[6] = {};

int in_nobdt = 0;
int out_nobdt = 0;

gStyle->SetOptStat(0);


float M_H = 0;
float Prob = 0;
float Ratio = 0;
int Eventnumber = 0;

//double w = (831.*1.*200000.)/3680.;	/// w = (cross_section*Branching_ratio*lumi)/(#of generated events)

//double w = 689/3887;

double w = 1.;


TH1D* histo_higgsmass[6]; 

TH1D* histo_higgsmass_bef = new TH1D("bef","bef",30,0,300);
histo_higgsmass_bef->SetXTitle("#bf{m_{b#bar{b}}}");
histo_higgsmass_bef->SetYTitle("#bf{Entries}");

TH1D* histo_ratio_w_correct = new TH1D("ratio_cor","ratio_cor",50,0,1);
histo_ratio_w_correct->SetXTitle("ratio #frac{w}{w_{max}}");
histo_ratio_w_correct->SetYTitle("#bf{Entries}");

TH1D* histo_ratio_w_wrong = new TH1D("ratio_wro","ratio_wro",50,0,1);
histo_ratio_w_wrong->SetXTitle("ratio #frac{w}{w_{max}}");
histo_ratio_w_wrong->SetYTitle("#bf{Entries}");


TFile *f1 = new TFile("ttjets_after_tmva_Eval.root");
TTree * tree1 = (TTree*) f1->Get("mytree");
tree1->SetBranchAddress("higgsmass",&m_H);
tree1->SetBranchAddress("eventnumber",&eventnumber);
tree1->SetBranchAddress("prob",&prob);
tree1->SetBranchAddress("ratio",&ratio);


	for(int k=0; k<tree1->GetEntries();k++){
		tree1->GetEntry(k);
			if(ratio==1){
				histo_higgsmass_bef->Fill(m_H,w);
				if(m_H>124 && m_H<126){
					in_nobdt+=1;
					//histo_ratio_w_correct->Fill(ratio);

				}
				if(m_H>126 || m_H<124){
					out_nobdt+=1;
					//histo_ratio_w_wrong->Fill(ratio);

				}

			}
	}



TFile *f2 = new TFile("ttjets_after_tmva_Eval.root");
TTree * tree2 = (TTree*) f2->Get("mytree");
tree2->SetBranchAddress("higgsmass",&M_H);
tree2->SetBranchAddress("eventnumber",&Eventnumber);
tree2->SetBranchAddress("prob",&Prob);
tree2->SetBranchAddress("ratio",&Ratio);

/*
vector<int> sameEV;

	for(int i=0; i<tree1->GetEntries();i++){
		tree1->GetEntry(i);
			if(prob>-999.9){
				for(int j=0;j<sameEV.size();j++){
					if(eventnumber==sameEV[j]){
						
					}
				else{
					for(int k=0;k<tree2->GetEntries();k++){
						tree2->GetEntry(k);
						if(eventnumber==Eventnumber && Ratio==1){
							histo_higgsmass->Fill(M_H);
							sameEV.push_back(eventnumber);				
						}
					}	
				}
				}		
			}
	}
*/
int l = 0;
int m = 0;

histo_higgsmass[0]= new TH1D("0","0",25,0,250);
histo_higgsmass[1]= new TH1D("1","1",25,0,250);
histo_higgsmass[2]= new TH1D("2","2",25,0,250);
histo_higgsmass[3]= new TH1D("3","3",25,0,250);
histo_higgsmass[4]= new TH1D("4","4",25,0,250);
histo_higgsmass[5]= new TH1D("5","5",25,0,250);

double z = -0.3;


for(int k=0;k<6;k++){
cout<<k<<endl;
cout<<l<<endl;
cout<<m<<endl;
cout<<z<<endl;
	for(int i=0; i<tree1->GetEntries();i++){
		tree1->GetEntry(i);
			if(prob>z && ratio==1){
				histo_higgsmass[l]->Fill(m_H,w);
				if(m_H>124 && m_H<126){
					in[m]+=1;
				}
				if(m_H>126 || m_H<124){
					out[m]+=1;

				}
	
			}
	}
m++;
l++;
z+=0.1;
}


double sc_1 = 689./3887.;
double sc_2 = 689./3848.;
double sc_3 = 689./3792.;
double sc_4 = 689./3656.;
double sc_5 = 689./2753.;
double sc_6 = 689./885.;
double sc_7 = 689./73.;


histo_higgsmass_bef->Scale(sc_1);
histo_higgsmass[0]->Scale(sc_1);
histo_higgsmass[1]->Scale(sc_1);
histo_higgsmass[2]->Scale(sc_1);
histo_higgsmass[3]->Scale(sc_1);
histo_higgsmass[4]->Scale(sc_1);
histo_higgsmass[5]->Scale(sc_1);



TCanvas *c1 = new TCanvas("c1","Higgs mass after BDT cut");
c1->cd();

histo_higgsmass[1]->SetLineColor(1);
histo_higgsmass[2]->SetLineColor(2);
histo_higgsmass[3]->SetLineColor(3);
histo_higgsmass[4]->SetLineColor(6);
histo_higgsmass[5]->SetLineColor(7);
histo_higgsmass_bef->SetLineColor(29);
histo_higgsmass_bef->SetLineWidth(3);
histo_higgsmass_bef->SetLineStyle(3);

histo_higgsmass_bef->Draw("HIST");
histo_higgsmass[0]->Draw("same HIST");
histo_higgsmass[1]->Draw("same HIST");
histo_higgsmass[2]->Draw("same HIST");
histo_higgsmass[3]->Draw("same HIST");
histo_higgsmass[4]->Draw("same HIST");
histo_higgsmass[5]->Draw("same HIST");


TLegend *leg1 = new TLegend(0.6,0.6,0.9,0.9);
   leg1->SetHeader("m_{b#bar{b}} after each BDT_{cut}");
   leg1->AddEntry(histo_higgsmass_bef,"No BDT_{cut}","f");
   leg1->AddEntry(histo_higgsmass[0],"BDT_{cut}>-0.3","f");
   leg1->AddEntry(histo_higgsmass[1],"BDT_{cut}>-0.2","f");
   leg1->AddEntry(histo_higgsmass[2],"BDT_{cut}>-0.1","f");
   leg1->AddEntry(histo_higgsmass[3],"BDT_{cut}>0.0","f");
   leg1->AddEntry(histo_higgsmass[4],"BDT_{cut}>0.1","f");
   leg1->AddEntry(histo_higgsmass[5],"BDT_{cut}>0.2","f");

leg1->Draw("same");

 TPaveText *paveCMS = new TPaveText(0.21,0.96,0.93,0.99,"NDC");
 paveCMS->AddText("#bf{CMS Simulation} (#it{reconstruction level)}     (13 TeV)"); //edw vale simulation sketo gt ta gegonota einai pythia
 paveCMS->SetFillColor(0);
 paveCMS->SetBorderSize(0);
 paveCMS->SetTextSize(0.04);
 paveCMS->SetTextFont(42);
 paveCMS->Draw("same");



c1->SaveAs("Higgsmass_afterBDT_cut_weighted.png");

cout<<"entries for each histo"<<endl;
cout<<"Number of entries ="<<histo_higgsmass_bef->GetEntries()<<"/in= "<<in_nobdt<<"/out= "<<out_nobdt<< endl;
cout<<"Number of entries ="<<histo_higgsmass[0]->GetEntries()<<"/in= "<<in[0]<<"/out= "<<out[0]<<endl;
cout<<"Number of entries ="<<histo_higgsmass[1]->GetEntries()<<"/in= "<<in[1]<<"/out= "<<out[1]<<endl;
cout<<"Number of entries ="<<histo_higgsmass[2]->GetEntries()<<"/in= "<<in[2]<<"/out= "<<out[2]<<endl;
cout<<"Number of entries ="<<histo_higgsmass[3]->GetEntries()<<"/in= "<<in[3]<<"/out= "<<out[3]<<endl;
cout<<"Number of entries ="<<histo_higgsmass[4]->GetEntries()<<"/in= "<<in[4]<<"/out= "<<out[4]<<endl;
cout<<"Number of entries ="<<histo_higgsmass[5]->GetEntries()<<"/in= "<<in[5]<<"/out= "<<out[5]<<endl;


cout<<"Number of WEIGHTED entries NO BDT="<<histo_higgsmass_bef->Integral()<<endl;
cout<<"Number of WEIGHTED entries BDT>-0.3 ="<<histo_higgsmass[0]->Integral()<<endl;
cout<<"Number of WEIGHTED entries BDT>-0.2 ="<<histo_higgsmass[1]->Integral()<<endl;
cout<<"Number of WEIGHTED entries BDT>-0.1 ="<<histo_higgsmass[2]->Integral()<<endl;
cout<<"Number of WEIGHTED entries BDT>0.0  ="<<histo_higgsmass[3]->Integral()<<endl;
cout<<"Number of WEIGHTED entries BDT>0.1  ="<<histo_higgsmass[4]->Integral()<<endl;
cout<<"Number of WEIGHTED entries BDT>0.2  ="<<histo_higgsmass[5]->Integral()<<endl;


double tot_0 = histo_higgsmass_bef->GetBinContent(6) + histo_higgsmass_bef->GetBinContent(7) + histo_higgsmass_bef->GetBinContent(8) + histo_higgsmass_bef->GetBinContent(9) + histo_higgsmass_bef->GetBinContent(10) + histo_higgsmass_bef->GetBinContent(11) + histo_higgsmass_bef->GetBinContent(12) + histo_higgsmass_bef->GetBinContent(13) + histo_higgsmass_bef->GetBinContent(14) + histo_higgsmass_bef->GetBinContent(15) + histo_higgsmass_bef->GetBinContent(16) + histo_higgsmass_bef->GetBinContent(17) + histo_higgsmass_bef->GetBinContent(18) + histo_higgsmass_bef->GetBinContent(19) + histo_higgsmass_bef->GetBinContent(20);

double tot_1 = histo_higgsmass[0]->GetBinContent(6) +histo_higgsmass[0]->GetBinContent(7) +histo_higgsmass[0]->GetBinContent(8) +histo_higgsmass[0]->GetBinContent(9) +histo_higgsmass[0]->GetBinContent(10) +histo_higgsmass[0]->GetBinContent(11) +histo_higgsmass[0]->GetBinContent(12) + histo_higgsmass[0]->GetBinContent(13) + histo_higgsmass[0]->GetBinContent(14) + histo_higgsmass[0]->GetBinContent(15) + histo_higgsmass[0]->GetBinContent(16)+ histo_higgsmass[0]->GetBinContent(17)+ histo_higgsmass[0]->GetBinContent(18)+ histo_higgsmass[0]->GetBinContent(19)+ histo_higgsmass[0]->GetBinContent(20);

double tot_2 = histo_higgsmass[1]->GetBinContent(6) +histo_higgsmass[1]->GetBinContent(7) +histo_higgsmass[1]->GetBinContent(8) +histo_higgsmass[1]->GetBinContent(9) +histo_higgsmass[1]->GetBinContent(10) +histo_higgsmass[1]->GetBinContent(11) +histo_higgsmass[1]->GetBinContent(12) + histo_higgsmass[1]->GetBinContent(13) + histo_higgsmass[1]->GetBinContent(14) + histo_higgsmass[1]->GetBinContent(15) + histo_higgsmass[1]->GetBinContent(16)+ histo_higgsmass[1]->GetBinContent(17)+ histo_higgsmass[1]->GetBinContent(18)+ histo_higgsmass[1]->GetBinContent(19)+ histo_higgsmass[1]->GetBinContent(20);

double tot_3 = histo_higgsmass[2]->GetBinContent(6) +histo_higgsmass[2]->GetBinContent(7) +histo_higgsmass[2]->GetBinContent(8) +histo_higgsmass[2]->GetBinContent(9) +histo_higgsmass[2]->GetBinContent(10) +histo_higgsmass[2]->GetBinContent(11) +histo_higgsmass[2]->GetBinContent(12) + histo_higgsmass[2]->GetBinContent(13) + histo_higgsmass[2]->GetBinContent(14) + histo_higgsmass[2]->GetBinContent(15) + histo_higgsmass[2]->GetBinContent(16)+ histo_higgsmass[2]->GetBinContent(17)+ histo_higgsmass[2]->GetBinContent(18)+ histo_higgsmass[2]->GetBinContent(19)+ histo_higgsmass[2]->GetBinContent(20);

double tot_4 = histo_higgsmass[3]->GetBinContent(6) +histo_higgsmass[3]->GetBinContent(7) +histo_higgsmass[3]->GetBinContent(8) +histo_higgsmass[3]->GetBinContent(9) +histo_higgsmass[3]->GetBinContent(10) +histo_higgsmass[3]->GetBinContent(11) +histo_higgsmass[3]->GetBinContent(12) + histo_higgsmass[3]->GetBinContent(13) + histo_higgsmass[3]->GetBinContent(14) + histo_higgsmass[3]->GetBinContent(15) + histo_higgsmass[3]->GetBinContent(16)+ histo_higgsmass[3]->GetBinContent(17)+ histo_higgsmass[3]->GetBinContent(18)+ histo_higgsmass[3]->GetBinContent(19)+ histo_higgsmass[3]->GetBinContent(20);

double tot_5 = histo_higgsmass[4]->GetBinContent(6) +histo_higgsmass[4]->GetBinContent(7) +histo_higgsmass[4]->GetBinContent(8) +histo_higgsmass[4]->GetBinContent(9) +histo_higgsmass[4]->GetBinContent(10) +histo_higgsmass[4]->GetBinContent(11) +histo_higgsmass[4]->GetBinContent(12) + histo_higgsmass[4]->GetBinContent(13) + histo_higgsmass[4]->GetBinContent(14) + histo_higgsmass[4]->GetBinContent(15) + histo_higgsmass[4]->GetBinContent(16)+ histo_higgsmass[4]->GetBinContent(17)+ histo_higgsmass[4]->GetBinContent(18)+ histo_higgsmass[4]->GetBinContent(19)+ histo_higgsmass[4]->GetBinContent(20);

double tot_6 = histo_higgsmass[5]->GetBinContent(6) +histo_higgsmass[5]->GetBinContent(7) +histo_higgsmass[5]->GetBinContent(8) +histo_higgsmass[5]->GetBinContent(9) +histo_higgsmass[5]->GetBinContent(10) +histo_higgsmass[5]->GetBinContent(11) +histo_higgsmass[5]->GetBinContent(12) + histo_higgsmass[5]->GetBinContent(13) + histo_higgsmass[5]->GetBinContent(14) + histo_higgsmass[5]->GetBinContent(15) + histo_higgsmass[5]->GetBinContent(16)+ histo_higgsmass[5]->GetBinContent(17)+ histo_higgsmass[5]->GetBinContent(18)+ histo_higgsmass[5]->GetBinContent(19)+ histo_higgsmass[5]->GetBinContent(20);



cout<<"Number of WEIGHTED entries NO BDT 90<m<160 = "<<tot_0<<endl;
cout<<"Number of WEIGHTED entries BDT>-0.3 || 90<m<160 = "<<tot_1<<endl;
cout<<"Number of WEIGHTED entries BDT>-0.2 || 90<m<160 = "<<tot_2<<endl;
cout<<"Number of WEIGHTED entries BDT>-0.1 || 90<m<160 = "<<tot_3<<endl;
cout<<"Number of WEIGHTED entries BDT>0.0  || 90<m<160 = "<<tot_4<<endl;
cout<<"Number of WEIGHTED entries BDT>0.1  || 90<m<160 = "<<tot_5<<endl;
cout<<"Number of WEIGHTED entries BDT>0.2  || 90<m<160 = "<<tot_6<<endl;


///////////////////////////////////////////////////////////////////////////////////////////////////////////////
TCanvas *c2 = new TCanvas("c2","Ratio of w");
c2->cd();

histo_ratio_w_correct->SetLineColor(1);
histo_ratio_w_wrong->SetLineColor(2);

histo_ratio_w_wrong->DrawNormalized();
histo_ratio_w_correct->DrawNormalized("same");

TLegend *leg2 = new TLegend(0.6,0.6,0.9,0.9);
   leg2->SetHeader("Ratio of w");
   leg2->AddEntry(histo_ratio_w_correct,"Correct","f");
   leg2->AddEntry(histo_ratio_w_wrong,"wrong","f");
	leg2->Draw("same");

 TPaveText *pave_CMS = new TPaveText(0.21,0.96,0.93,0.99,"NDC");
 pave_CMS->AddText("#bf{CMS Simulation} (#it{reconstruction level)}     (13 TeV)"); //edw vale simulation sketo gt ta gegonota einai pythia
 pave_CMS->SetFillColor(0);
 pave_CMS->SetBorderSize(0);
 pave_CMS->SetTextSize(0.04);
 pave_CMS->SetTextFont(42);
 pave_CMS->Draw("same");

c2->SaveAs("ratio_w_diff_definition.png");

}
