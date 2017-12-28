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


void masses(){

/////////////////////////////	Histograms	///////////////////////////////////////////////////////////////////

TH2D *h1 = new TH2D("2D Histo","2D Histo of mt and mWp in peak;mWp;mt",40,0.,400.,40,0.,400.);

TH2D *h2 = new TH2D("2DHisto","2D Histo of mtb and mWm in peak;mWm;mtb",40,0.,400.,40,0.,400.);

TH1D *h3 = new TH1D("Higgs mass","Higgs mass for greatest weight",50,0.,500.);
h3->SetXTitle("GeV");
h3->SetYTitle("Counts");

TH2D *h4 = new TH2D("2D Histos","2D Histo of mt and mWp out of peak;mWp;mt",40,0.,400.,40,0.,400.);

TH2D *h5 = new TH2D("2DHistos","2D Histo of mtb and mWm out of peak;mWm;mtb",40,0.,400.,40,0.,400.);

TH1D *h6 = new TH1D("w_correct/w_max","Ratio of weights",50,0.,1.);
h6->SetXTitle("Ratio #frac{w_{c}}{W_{max}} ");
h6->SetYTitle("Entries");




///////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////*******************************////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////


int eventNumber;
int mtop , mw , lepton_comb , jet_comb;
double max_weight , max_higgs_mass , max_ttbar_mass , mean_higgs_mass;
double Metx , Mety;
double bh1[4] , bh2[4];
double btop[4] , btopb[4];
double lp[4] , lm[4];
double n1px,n1py,n1pz , n2px,n2py,n2pz;
double w1,w2,x1,x2;
double w_c;

double w;
double ratio;
double m_Wp , m_Wm , m_H;
double m_t , m_tb;

	FILE *file = fopen("/home/george/Desktop/ttH_greatestweight_ratioofw2/ttH_greatestweight_wcorr.txt","r");

while(!feof(file)){

	fscanf(file," %d "	,&eventNumber);
	fscanf(file," %d "	,&mtop);
	fscanf(file," %d "	,&mw);
	fscanf(file," %d "	,&lepton_comb);
	fscanf(file," %d "	,&jet_comb);
	fscanf(file," %lf "	,&max_weight);
	fscanf(file," %lf "	,&max_higgs_mass);
	fscanf(file," %lf "	,&max_ttbar_mass);
	fscanf(file," %lf "	,&mean_higgs_mass);
	fscanf(file," %lf %lf " ,&Metx	,&Mety);
        fscanf(file," %lf %lf %lf ", &bh1[1]  ,&bh1[2]  ,&bh1[3]);
        fscanf(file," %lf %lf %lf ", &bh2[1]  ,&bh2[2]  ,&bh2[3]);
        fscanf(file," %lf %lf %lf ", &btop[1]  ,&btop[2]  ,&btop[3]);
        fscanf(file," %lf %lf %lf ", &btopb[1]  ,&btopb[2]  ,&btopb[3]);
        fscanf(file," %lf %lf %lf ", &lp[1]  ,&lp[2]  ,&lp[3]);
        fscanf(file," %lf %lf %lf ", &lm[1]  ,&lm[2]  ,&lm[3]);
        fscanf(file," %lf %lf %lf ", &n1px  ,&n1py  ,&n1pz);
        fscanf(file," %lf %lf %lf ", &n2px  ,&n2py  ,&n2pz);
	fscanf(file," %lf %lf "	   ,&w1,&w2);
	fscanf(file," %lf %lf "	   ,&x1,&x2);
	fscanf(file," %lf "	   ,&w_c);


// Create all the 4Vectors //

TLorentzVector n1,n2;

double n1e = sqrt(n1px*n1px + n1py*n1py + n1pz*n1pz);
double n2e = sqrt(n2px*n2px + n2py*n2py + n2pz*n2pz);

n1.SetPxPyPzE(n1px,n1py,n1pz,n1e);
n2.SetPxPyPzE(n2px,n2py,n2pz,n2e);

TLorentzVector t1,t2;

btop[0] = sqrt(btop[1]*btop[1] + btop[2]*btop[2] + btop[3]*btop[3] + 4.8*4.8);
btopb[0] = sqrt(btopb[1]*btopb[1] + btopb[2]*btopb[2] + btopb[3]*btopb[3] + 4.8*4.8);

t1.SetPxPyPzE(btop[1],btop[2],btop[3],btop[0]);
t2.SetPxPyPzE(btopb[1],btopb[2],btopb[3],btopb[0]);

TLorentzVector l1,l2;

lp[0] = sqrt(lp[1]*lp[1]+lp[2]*lp[2]+lp[3]*lp[3]);
lm[0] = sqrt(lm[1]*lm[1]+lm[2]*lm[2]+lm[3]*lm[3]);

l1.SetPxPyPzE(lp[1],lp[2],lp[3],lp[0]);
l2.SetPxPyPzE(lm[1],lm[2],lm[3],lm[0]);


TLorentzVector higgs1,higgs2;

bh1[0] = sqrt(bh1[1]*bh1[1]+bh1[2]*bh1[2]+bh1[3]*bh1[3]+4.8*4.8);
bh2[0] = sqrt(bh2[1]*bh2[1]+bh2[2]*bh2[2]+bh2[3]*bh2[3]+4.8*4.8);


higgs1.SetPxPyPzE(bh1[1],bh1[2],bh1[3],bh1[0]);
higgs2.SetPxPyPzE(bh2[1],bh2[2],bh2[3],bh2[0]);


TLorentzVector top , topb;

top  = n1 + l1 + t1;
topb = n2 + l2 + t2;

m_t  = top.M();
m_tb = topb.M();

///	Reconstruction of the masses	//

// W masses //

TLorentzVector Wp, Wm;

Wp = n1 + l1;
Wm = n2 + l2;

m_Wp = Wp.M();
m_Wm = Wm.M();

// top masses //



// Higgs mass	//

TLorentzVector Higgs;

Higgs = higgs1 + higgs2;

m_H = Higgs.M();

// Ratio of w_correct with w_max	//

w = (w1*w2)/(x1*x2);

ratio =w_c/max_weight;


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

if(m_H>120 && m_H<130){
	h1->Fill(m_Wp,m_t);
	h2->Fill(m_Wm,m_tb);

}

if(m_H<120 || m_H>130){
	h4->Fill(m_Wp,m_t);
	h5->Fill(m_Wm,m_tb);
}

h3->Fill(m_H);

h6->Fill(ratio);


if (w_c<0){cout<<"problemo "<<w_c<<'\n';}

}//	End of while loop	/////



//	Canvases	//


TCanvas *c1 = new TCanvas("c1","Higgs_mass");
c1->cd();

h3->Draw();

c1->SaveAs("Higgs_mass.png");

/////
/*
TCanvas *c2 = new TCanvas("c2","top vs mWp");
c2->cd();

h1->Draw("Colz");

c2->SaveAs("topmass_vs_mWpmass_inpeak.png");
*/

/////

TCanvas *c3 = new TCanvas("c3","topb vs mWm");
c3->cd();

h2->Add(h1);
h2->Draw("Colz");

c3->SaveAs("topmass_vs_mWmass_total_inpeak.png");


//

TCanvas *c4 = new TCanvas("c4","top vs mWp");
c4->cd();


h4->Add(h5);
h4->Draw("Colz");

c4->SaveAs("topmass_vs_mWmass_total_outofpeak.png");


/////
/*
TCanvas *c5 = new TCanvas("c5","top vs mWp");
c5->cd();

h5->Draw("Colz");

c5->SaveAs("topbmass_vs_mWmmass_outofpeak.png");
*/
/////

TCanvas *c6 = new TCanvas("c6","w_correct/w_max");
c6->cd();

h6->Draw();

c6->SaveAs("ratio_of_w.png");



}
