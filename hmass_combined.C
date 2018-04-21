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


void hmass_combined(){

// gROOT->LoadMacro("setTDRStyle_teliko.C");
 setTDRStyle_teliko();



float m_H = 0;
float prob = 0;
float ratio = 0;
int eventnumber = 0;

float M_H = 0;
float Prob = 0;
float Ratio = 0;
int Eventnumber = 0;




int in[6] = {};
int out[6] = {};

int in_nobdt = 0;
int out_nobdt = 0;

gStyle->SetOptStat(0);

//double w = (0.5071*0.5824*200000.)/1167.;
double w = 1;

/*
float M_H = 0;
float Prob = 0;
float Ratio = 0;
int Eventnumber = 0;
*/

TH1D* histo_higgsmass[6]; 
TH1D* Histo_higgsmass[6]; 


TH1D* histo_higgsmass_bef = new TH1D("bef","bef",30,0,300);
histo_higgsmass_bef->SetXTitle("#bf{m_{b#bar{b}}}");
histo_higgsmass_bef->SetYTitle("#bf{Entries}");

TH1D* Histo_higgsmass_bef = new TH1D("Bef","Bef",30,0,300);
Histo_higgsmass_bef->SetXTitle("#bf{m_{b#bar{b}}}");
Histo_higgsmass_bef->SetYTitle("#bf{Entries}");



TH1D* histo_ratio_w_correct = new TH1D("ratio_cor","ratio_cor",50,0,1);
histo_ratio_w_correct->SetXTitle("ratio #frac{w}{w_{max}}");
histo_ratio_w_correct->SetYTitle("#bf{Entries}");

TH1D* histo_ratio_w_wrong = new TH1D("ratio_wro","ratio_wro",50,0,1);
histo_ratio_w_wrong->SetXTitle("ratio #frac{w}{w_{max}}");
histo_ratio_w_wrong->SetYTitle("#bf{Entries}");


TFile *f1 = new TFile("post_TMVA_FINAL_BOTH_2.root");
TTree * tree1 = (TTree*) f1->Get("mytree");
tree1->SetBranchAddress("higgsmass",&m_H);
tree1->SetBranchAddress("eventnumber",&eventnumber);
tree1->SetBranchAddress("prob",&prob);
tree1->SetBranchAddress("ratio",&ratio);


TFile *f2 = new TFile("ttjets_after_tmva_Eval.root");
TTree * tree2 = (TTree*) f2->Get("mytree");
tree2->SetBranchAddress("higgsmass",&M_H);
tree2->SetBranchAddress("eventnumber",&Eventnumber);
tree2->SetBranchAddress("prob",&Prob);
tree2->SetBranchAddress("ratio",&Ratio);



	for(int k=0; k<tree1->GetEntries();k++){
		tree1->GetEntry(k);
			if(ratio==1){
				histo_higgsmass_bef->Fill(m_H,w);
				//if(m_H>124 && m_H<126){
					//in_nobdt+=1;
					//histo_higgsmass_bef->Fill(m_H);

				//}
				//if(m_H>126 || m_H<124){
					//out_nobdt+=1;
					//histo_higgsmass_bef->Fill(m_H);

				//}

			}
	}


        for(int k=0; k<tree2->GetEntries();k++){
                tree2->GetEntry(k);
                        if(Ratio==1){
                                Histo_higgsmass_bef->Fill(M_H,w);
                                //if(M_H>124 && M_H<126){
                                        //in_nobdt+=1;
                                        //Histo_higgsmass_bef->Fill(M_H);

                                //}
                                //if(M_H>126 || M_H<124){
                                        //out_nobdt+=1;
                                        //Histo_higgsmass_bef->Fill(M_H);

                                //}

                        }
        }





/*
TFile *f2 = new TFile("post_TMVA_FINAL_BOTH_2.root");
TTree * tree2 = (TTree*) f2->Get("mytree");
tree2->SetBranchAddress("higgsmass",&M_H);
tree2->SetBranchAddress("eventnumber",&Eventnumber);
tree2->SetBranchAddress("prob",&Prob);
tree2->SetBranchAddress("ratio",&Ratio);


vector<int> sameEV;

	for(int i=0; i<tree1->GetEntries();i++){
		tree1->GetEntry(i);
			if(prob>){
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
				/*if(m_H>124 && m_H<126){
					in[m]+=1;
				}
				if(m_H>126 || m_H<124){
					out[m]+=1;

				}*/
	
			}
	}
m++;
l++;
z+=0.1;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

int L = 0;
int M = 0;

Histo_higgsmass[0]= new TH1D("0_","0_",25,0,250);
Histo_higgsmass[1]= new TH1D("1_","1_",25,0,250);
Histo_higgsmass[2]= new TH1D("2_","2_",25,0,250);
Histo_higgsmass[3]= new TH1D("3_","3_",25,0,250);
Histo_higgsmass[4]= new TH1D("4_","4_",25,0,250);
Histo_higgsmass[5]= new TH1D("5_","5_",25,0,250);

double Z = -0.3;


for(int k=0;k<6;k++){
cout<<k<<endl;
cout<<L<<endl;
cout<<M<<endl;
cout<<Z<<endl;
	for(int i=0; i<tree2->GetEntries();i++){
		tree2->GetEntry(i);
			if(Prob>Z && Ratio==1){
				Histo_higgsmass[L]->Fill(M_H,w);
				/*if(m_H>124 && m_H<126){
					in[m]+=1;
				}
				if(m_H>126 || m_H<124){
					out[m]+=1;

				}*/
	
			}
	}
M++;
L++;
Z+=0.1;
}




double sc_1 = 31./889.;
double sc_2 = 689./3887.;


histo_higgsmass_bef->Scale(sc_1);
histo_higgsmass[0]->Scale(sc_1);
histo_higgsmass[1]->Scale(sc_1);
histo_higgsmass[2]->Scale(sc_1);
histo_higgsmass[3]->Scale(sc_1);
histo_higgsmass[4]->Scale(sc_1);
histo_higgsmass[5]->Scale(sc_1);

Histo_higgsmass_bef->Scale(sc_2);
Histo_higgsmass[0]->Scale(sc_2);
Histo_higgsmass[1]->Scale(sc_2);
Histo_higgsmass[2]->Scale(sc_2);
Histo_higgsmass[3]->Scale(sc_2);
Histo_higgsmass[4]->Scale(sc_2);
Histo_higgsmass[5]->Scale(sc_2);




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




////////////////////	CALCULATION OF WEIGHTED ENTRIES	////////////////////////////////////////////////////////

cout<<"Number of WEIGHTED entries NO BDT="<<histo_higgsmass_bef->Integral()<<endl;
cout<<"Number of WEIGHTED entries BDT>-0.3 ="<<histo_higgsmass[0]->Integral()<<endl;
cout<<"Number of WEIGHTED entries BDT>-0.2 ="<<histo_higgsmass[1]->Integral()<<endl;
cout<<"Number of WEIGHTED entries BDT>-0.1 ="<<histo_higgsmass[2]->Integral()<<endl;
cout<<"Number of WEIGHTED entries BDT>0.0  ="<<histo_higgsmass[3]->Integral()<<endl;
cout<<"Number of WEIGHTED entries BDT>0.1  ="<<histo_higgsmass[4]->Integral()<<endl;
cout<<"Number of WEIGHTED entries BDT>0.2  ="<<histo_higgsmass[5]->Integral()<<endl;


double tot_0 = 0;
double tot_1 = 0;
double tot_2 = 0;
double tot_3 = 0;
double tot_4 = 0;
double tot_5 = 0;
double tot_6 = 0;

	for(int i=13;i<14;i++){
		tot_0+=(histo_higgsmass_bef->GetBinContent(i)*histo_higgsmass_bef->GetBinContent(i))/Histo_higgsmass_bef->GetBinContent(i);
	}

	for(int i=13;i<14;i++){
		tot_1+=(histo_higgsmass[0]->GetBinContent(i)*histo_higgsmass[0]->GetBinContent(i))/Histo_higgsmass[0]->GetBinContent(i);
	}

	for(int i=13;i<14;i++){
		tot_2+=(histo_higgsmass[1]->GetBinContent(i)*histo_higgsmass[1]->GetBinContent(i))/Histo_higgsmass[1]->GetBinContent(i);
	}

	for(int i=13;i<14;i++){
		tot_3+=(histo_higgsmass[2]->GetBinContent(i)*histo_higgsmass[2]->GetBinContent(i))/Histo_higgsmass[2]->GetBinContent(i);
	}

	for(int i=13;i<14;i++){
		tot_4+=(histo_higgsmass[3]->GetBinContent(i)*histo_higgsmass[3]->GetBinContent(i))/Histo_higgsmass[3]->GetBinContent(i);
	}

	for(int i=13;i<14;i++){
		tot_5+=(histo_higgsmass[4]->GetBinContent(i)*histo_higgsmass[4]->GetBinContent(i))/Histo_higgsmass[4]->GetBinContent(i);
	}

	for(int i=13;i<14;i++){
		tot_6+=(histo_higgsmass[5]->GetBinContent(i)*histo_higgsmass[5]->GetBinContent(i))/Histo_higgsmass[5]->GetBinContent(i);
	}


cout<<"NOOOOO = "<<histo_higgsmass_bef->GetBinContent(13)<<endl;
cout<<"NOOOOO = "<<Histo_higgsmass_bef->GetBinContent(13)<<endl;














cout<<"EFFICIENCY NO BDT   || 50<m<200 = "<<sqrt(tot_0)<<endl;
cout<<"EFFICIENCY BDT>-0.3 || 50<m<200 = "<<sqrt(tot_1)<<endl;
cout<<"EFFICIENCY BDT>-0.2 || 50<m<200 = "<<sqrt(tot_2)<<endl;
cout<<"EFFICIENCY BDT>-0.1 || 50<m<200 = "<<sqrt(tot_3)<<endl;
cout<<"EFFICIENCY BDT>0.0  || 50<m<200 = "<<sqrt(tot_4)<<endl;
cout<<"EFFICIENCY BDT>0.1  || 50<m<200 = "<<sqrt(tot_5)<<endl;
cout<<"EFFICIENCY BDT>0.2  || 50<m<200 = "<<sqrt(tot_6)<<endl;


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


////////

TCanvas *c3 = new TCanvas("c3","test");
c3->cd();

histo_higgsmass_bef->Draw("HIST");

c3->SaveAs("test.png");

}
