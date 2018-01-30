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

void masses_wrong_ratio_opt(char name[300]){

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

TH1D *h7 = new TH1D("w_wrong/w_max","Ratio of weights",50,0.,1.);
h7->SetXTitle("Ratio #frac{w_{w}}{W_{max}} ");
h7->SetYTitle("Entries");




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
double RATIO;
double weight;

int flag;
double w;
double ratio;
double m_Wp , m_Wm , m_H;
double m_t , m_tb;



int id;

int eventNumber2;
int mtop2 , mw2 , lepton_comb2 , jet_comb2;
double max_weight2 , max_higgs_mass2 , max_ttbar_mass2 , mean_higgs_mass2;
double Metx2 , Mety2;
double bh_1[4] , bh_2[4];
double b_top[4] , b_topb[4];
double l_p[4] , l_m[4];
double n1_px,n1_py,n1_pz , n2_px,n2_py,n2_pz;
double w_1,w_2,x_1,x_2;
int flag2;

int eventNumber3;
int mtop3 , mw3 , lepton_comb3 , jet_comb3;
double max_weight3 , max_higgs_mass3 , max_ttbar_mass3 , mean_higgs_mass3;
double Metx3 , Mety3;
double b_h_1[4] , b_h_2[4];
double b_Top[4] , b_Topb[4];
double l_P[4] , l_M[4];
double n1_p_x,n1_p_y,n1_p_z , n2_p_x,n2_p_y,n2_p_z;
double W_1,W_2,X_1,X_2;
int flag3;
double max_weight_forcrrct;
double corr_weight;

double maximumweight;

double n1e , n2e;

double deta1 , dphi1 , dr1;
double deta2 , dphi2 , dr2;
double deta3 , dphi3 , dr3;
double deta4 , dphi4 , dr4;
double deta5 , dphi5 , dr5;
double deta6 , dphi6 , dr6;
double deta7 , dphi7 , dr7;
double deta8 , dphi8 , dr8;
double deta9 , dphi9 , dr9;
double deta10 , dphi10 , dr10;
double deta11 , dphi11 , dr11;
double deta12 , dphi12 , dr12;
double deta13 , dphi13 , dr13;




double E_tt , m_tt;
double pt_H1 , pt_H2;
double asym;
double higgs_pt_ratio;

vector<double> ID;
vector<double> WEIGHT;



//////////////////////////////	TREE DEFINITION	//////////////////////////////////////////////////////////
/////////////////////////////	***************	//////////////////////////////////////////////////////////	
//////////////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////	Tree of wrong solutions	/////////////////////////////////////////////////

TTree *mytreewrng = new TTree("mytreewrng","mytreewrng");

mytreewrng->Branch("ratio_wrong"	,&RATIO		,"RATIO/D");
mytreewrng->Branch("w1"			,&w1		,"w1/D");
mytreewrng->Branch("w2"			,&w2		,"w2/D");
mytreewrng->Branch("x1"			,&x1		,"x1/D");
mytreewrng->Branch("x2"			,&x2		,"x2/D");
mytreewrng->Branch("E_tt"		,&E_tt		,"E_tt/D");
mytreewrng->Branch("higgs_pt_ratio"	,&higgs_pt_ratio,"higgs_pt_ratio/D");
mytreewrng->Branch("higgs_pt_asym"	,&asym		,"asym/D");
mytreewrng->Branch("deta1"		,&deta1		,"deta1/D");
mytreewrng->Branch("dphi1"		,&dphi1		,"dphi1/D");
mytreewrng->Branch("dr1"		,&dr1		,"dr1/D");
mytreewrng->Branch("deta2"		,&deta2		,"deta2/D");
mytreewrng->Branch("dphi2"		,&dphi2		,"dphi2/D");
mytreewrng->Branch("dr2"		,&dr2		,"dr2/D");
mytreewrng->Branch("deta3"		,&deta3		,"deta3/D");
mytreewrng->Branch("dphi3"		,&dphi3		,"dphi3/D");
mytreewrng->Branch("dr3"		,&dr3		,"dr3/D");
mytreewrng->Branch("deta4"		,&deta4		,"deta4/D");
mytreewrng->Branch("dphi4"		,&dphi4		,"dphi4/D");
mytreewrng->Branch("dr4"		,&dr4		,"dr4/D");
mytreewrng->Branch("deta5"		,&deta5		,"deta5/D");
mytreewrng->Branch("dphi5"		,&dphi5		,"dphi5/D");
mytreewrng->Branch("dr5"		,&dr5		,"dr5/D");
mytreewrng->Branch("deta6"		,&deta6		,"deta6/D");
mytreewrng->Branch("dphi6"		,&dphi6		,"dphi6/D");
mytreewrng->Branch("dr6"		,&dr6		,"dr6/D");
mytreewrng->Branch("deta7"		,&deta7		,"deta7/D");
mytreewrng->Branch("dphi7"		,&dphi7		,"dphi7/D");
mytreewrng->Branch("dr7"		,&dr7		,"dr7/D");
mytreewrng->Branch("deta8"		,&deta8		,"deta8/D");
mytreewrng->Branch("dphi8"		,&dphi8		,"dphi8/D");
mytreewrng->Branch("dr8"		,&dr8		,"dr8/D");
mytreewrng->Branch("deta9"		,&deta9		,"deta9/D");
mytreewrng->Branch("dphi9"		,&dphi9		,"dphi9/D");
mytreewrng->Branch("dr9"		,&dr9		,"dr9/D");
mytreewrng->Branch("deta10"		,&deta10	,"deta10/D");
mytreewrng->Branch("dphi10"		,&dphi10	,"dphi10/D");
mytreewrng->Branch("dr10"		,&dr10		,"dr10/D");
mytreewrng->Branch("deta11"		,&deta11	,"deta11/D");
mytreewrng->Branch("dphi11"		,&dphi11	,"dphi11/D");
mytreewrng->Branch("dr11"		,&dr11		,"dr11/D");
mytreewrng->Branch("deta12"		,&deta12	,"deta12/D");
mytreewrng->Branch("dphi12"		,&dphi12	,"dphi12/D");
mytreewrng->Branch("dr12"		,&dr12		,"dr12/D");
mytreewrng->Branch("deta13"		,&deta13	,"deta13/D");
mytreewrng->Branch("dphi13"		,&dphi13	,"dphi13/D");
mytreewrng->Branch("dr13"		,&dr13		,"dr13/D");



/////////////////////////////	Tree of correct solutions ////////////////////////////////////////////////

TTree *mytreecrrct = new TTree("mytreecrrct","mytreecrrct");

mytreecrrct->Branch("ratio_correct"	,&ratio		,"ratio/D");
mytreecrrct->Branch("w1"		,&w1		,"w1/D");
mytreecrrct->Branch("w2"		,&w2		,"w2/D");
mytreecrrct->Branch("x1"		,&x1		,"x1/D");
mytreecrrct->Branch("x2"		,&x2		,"x2/D");
mytreecrrct->Branch("E_tt"		,&E_tt		,"E_tt/D");
mytreecrrct->Branch("higgs_pt_ratio"	,&higgs_pt_ratio,"higgs_pt_ratio/D");
mytreecrrct->Branch("higgs_pt_asym"	,&asym		,"asym/D");
mytreecrrct->Branch("deta1"		,&deta1		,"deta1/D");
mytreecrrct->Branch("dphi1"		,&dphi1		,"dphi1/D");
mytreecrrct->Branch("dr1"		,&dr1		,"dr1/D");
mytreecrrct->Branch("deta2"		,&deta2		,"deta2/D");
mytreecrrct->Branch("dphi2"		,&dphi2		,"dphi2/D");
mytreecrrct->Branch("dr2"		,&dr2		,"dr2/D");
mytreecrrct->Branch("deta3"		,&deta3		,"deta3/D");
mytreecrrct->Branch("dphi3"		,&dphi3		,"dphi3/D");
mytreecrrct->Branch("dr3"		,&dr3		,"dr3/D");
mytreecrrct->Branch("deta4"		,&deta4		,"deta4/D");
mytreecrrct->Branch("dphi4"		,&dphi4		,"dphi4/D");
mytreecrrct->Branch("dr4"		,&dr4		,"dr4/D");
mytreecrrct->Branch("deta5"		,&deta5		,"deta5/D");
mytreecrrct->Branch("dphi5"		,&dphi5		,"dphi5/D");
mytreecrrct->Branch("dr5"		,&dr5		,"dr5/D");
mytreecrrct->Branch("deta6"		,&deta6		,"deta6/D");
mytreecrrct->Branch("dphi6"		,&dphi6		,"dphi6/D");
mytreecrrct->Branch("dr6"		,&dr6		,"dr6/D");
mytreecrrct->Branch("deta7"		,&deta7		,"deta7/D");
mytreecrrct->Branch("dphi7"		,&dphi7		,"dphi7/D");
mytreecrrct->Branch("dr7"		,&dr7		,"dr7/D");
mytreecrrct->Branch("deta8"		,&deta8		,"deta8/D");
mytreecrrct->Branch("dphi8"		,&dphi8		,"dphi8/D");
mytreecrrct->Branch("dr8"		,&dr8		,"dr8/D");
mytreecrrct->Branch("deta9"		,&deta9		,"deta9/D");
mytreecrrct->Branch("dphi9"		,&dphi9		,"dphi9/D");
mytreecrrct->Branch("dr9"		,&dr9		,"dr9/D");
mytreecrrct->Branch("deta10"		,&deta10	,"deta10/D");
mytreecrrct->Branch("dphi10"		,&dphi10	,"dphi10/D");
mytreecrrct->Branch("dr10"		,&dr10		,"dr10/D");
mytreecrrct->Branch("deta11"		,&deta11	,"deta11/D");
mytreecrrct->Branch("dphi11"		,&dphi11	,"dphi11/D");
mytreecrrct->Branch("dr11"		,&dr11		,"dr11/D");
mytreecrrct->Branch("deta12"		,&deta12	,"deta12/D");
mytreecrrct->Branch("dphi12"		,&dphi12	,"dphi12/D");
mytreecrrct->Branch("dr12"		,&dr12		,"dr12/D");
mytreecrrct->Branch("deta13"		,&deta13	,"deta13/D");
mytreecrrct->Branch("dphi13"		,&dphi13	,"dphi13/D");
mytreecrrct->Branch("dr13"		,&dr13		,"dr13/D");






//////////////////////////////////////////////////////////////////////////////////////////////////////////////



//	FILE *file = fopen("/home/george/Desktop/wrong_weights/wrong_weights_allsol.txt","r");
	FILE *file = fopen(name,"r");


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
	fscanf(file," %d "	   ,&flag);
	fscanf(file," %lf %lf "	   ,&w1,&w2);
	fscanf(file," %lf %lf "	   ,&x1,&x2);

//cout<<"loop1"<<'\n';
cout<<eventNumber<<'\n';

// Create all the 4Vectors //

TLorentzVector n1,n2;

n1e = sqrt(n1px*n1px + n1py*n1py + n1pz*n1pz);
n2e = sqrt(n2px*n2px + n2py*n2py + n2pz*n2pz);

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

TLorentzVector tt , ttH;

tt = n1 + n2 + l1 + l2 + t1 + t2;
ttH = tt + higgs1 + higgs2;


E_tt = tt.E();
m_tt = tt.M();

///	Reconstruction of the masses	//

// W masses //

TLorentzVector Wp, Wm;

Wp = n1 + l1;
Wm = n2 + l2;

m_Wp = Wp.M();
m_Wm = Wm.M();


// Higgs mass	//

TLorentzVector Higgs;

Higgs = higgs1 + higgs2;

m_H = Higgs.M();

pt_H1 = sqrt(bh1[1]*bh1[1]+bh1[2]*bh1[2]);
pt_H2 = sqrt(bh2[1]*bh2[1]+bh2[2]*bh2[2]);

asym = (pt_H1 - pt_H2)/(pt_H1 + pt_H2);

higgs_pt_ratio = pt_H1/pt_H2;

//// lp and b of top branch ////

deta1 = l1.Eta() - t1.Eta();
dphi1 = fabs(l1.DeltaPhi(t1));
dr1 = sqrt(deta1*deta1 + dphi1*dphi1);


//// lp and b of top bar branch ////

deta2 = l1.Eta() - t2.Eta();
dphi2 = fabs(l1.DeltaPhi(t2));
dr2 = sqrt(deta2*deta2 + dphi2*dphi2);

//// lp and b1 of Higgs////

deta3 = l1.Eta() - higgs1.Eta();
dphi3 = fabs(l1.DeltaPhi(higgs1));
dr3 = sqrt(deta3*deta3 + dphi3*dphi3);

//// lp and b2 of Higgs////

deta4 = l1.Eta() - higgs2.Eta();
dphi4 = fabs(l1.DeltaPhi(higgs2));
dr4 = sqrt(deta4*deta4 + dphi4*dphi4);



//// lm and b of top branch ////

deta5 = l2.Eta() - t1.Eta();
dphi5 = fabs(l2.DeltaPhi(t1));
dr5 = sqrt(deta5*deta5 + dphi5*dphi5);


//// lm and b of top bar branch ////

deta6 = l2.Eta() - t2.Eta();
dphi6 = fabs(l2.DeltaPhi(t2));
dr6 = sqrt(deta6*deta6 + dphi6*dphi6);

//// lm and b1 of Higgs////

deta7 = l2.Eta() - higgs1.Eta();
dphi7 = fabs(l2.DeltaPhi(higgs1));
dr7 = sqrt(deta7*deta7 + dphi7*dphi7);

//// lm and b2 of Higgs////

deta8 = l2.Eta() - higgs2.Eta();
dphi8 = fabs(l2.DeltaPhi(higgs2));
dr8 = sqrt(deta8*deta8 + dphi8*dphi8);

//// bh1 and bh2 ////

deta9 = higgs1.Eta() - higgs2.Eta();
dphi9 = fabs(higgs1.DeltaPhi(higgs2));
dr9 = sqrt(deta9*deta9 + dphi9*dphi9);


//// bh1 and b of top branch ////

deta10 = higgs1.Eta() - t1.Eta();
dphi10 = fabs(higgs1.DeltaPhi(t1));
dr10 = sqrt(deta10*deta10 + dphi10*dphi10);


//// bh1 and b of top bar branch ////

deta11 = higgs1.Eta() - t2.Eta();
dphi11 = fabs(higgs1.DeltaPhi(t2));
dr11 = sqrt(deta11*deta11 + dphi11*dphi11);


//// bh2 and b of top branch ////

deta12 = higgs2.Eta() - t1.Eta();
dphi12 = fabs(higgs2.DeltaPhi(t1));
dr12 = sqrt(deta12*deta12 + dphi12*dphi12);


//// bh2 and b of top bar branch ////

deta13 = higgs2.Eta() - t2.Eta();
dphi13 = fabs(higgs2.DeltaPhi(t2));
dr13 = sqrt(deta13*deta13 + dphi13*dphi13);


// Ratio of w_correct with w_max	//

w = (w1*w2)/(x1*x2);

//ratio =w_c/max_weight;

weight=(w_1*w_2)/(x_1*x_2);


id = eventNumber;


	
if(flag==0){

maximumweight = 0.0;

	for(int i=0; i< ID.size(); i++){

			if(id==ID[i]){
			maximumweight = WEIGHT[i];
			}		
	}


	if(maximumweight==0.0){

// loop over the same (wrong) event to get the maximum weight///

//FILE *file2 = fopen("/home/george/Desktop/wrong_weights/wrong_weights_allsol2.txt","r");
FILE *file2 = fopen(name,"r");


	while(!feof(file2)){

		fscanf(file2," %d "	,&eventNumber2);
		fscanf(file2," %d "	,&mtop2);
		fscanf(file2," %d "	,&mw2);
		fscanf(file2," %d "	,&lepton_comb2);
		fscanf(file2," %d "	,&jet_comb2);
		fscanf(file2," %lf "	,&max_weight2);
		fscanf(file2," %lf "	,&max_higgs_mass2);
		fscanf(file2," %lf "	,&max_ttbar_mass2);
		fscanf(file2," %lf "	,&mean_higgs_mass2);
		fscanf(file2," %lf %lf " ,&Metx2	,&Mety2);
        	fscanf(file2," %lf %lf %lf ", &bh_1[1]  ,&bh_1[2]  ,&bh_1[3]);
        	fscanf(file2," %lf %lf %lf ", &bh_2[1]  ,&bh_2[2]  ,&bh_2[3]);
        	fscanf(file2," %lf %lf %lf ", &b_top[1]  ,&b_top[2]  ,&b_top[3]);
        	fscanf(file2," %lf %lf %lf ", &b_topb[1]  ,&b_topb[2]  ,&b_topb[3]);
        	fscanf(file2," %lf %lf %lf ", &l_p[1]  ,&l_p[2]  ,&l_p[3]);
        	fscanf(file2," %lf %lf %lf ", &l_m[1]  ,&l_m[2]  ,&l_m[3]);
        	fscanf(file2," %lf %lf %lf ", &n1_px  ,&n1_py  ,&n1_pz);
        	fscanf(file2," %lf %lf %lf ", &n2_px  ,&n2_py  ,&n2_pz);
		fscanf(file2," %d "	   ,&flag2);
		fscanf(file2," %lf %lf "	   ,&w_1,&w_2);
		fscanf(file2," %lf %lf "	   ,&x_1,&x_2);
		
weight=(w_1*w_2)/(x_1*x_2);

//cout<<"read"<<'\n';
	if(flag2==0){
		if(id==eventNumber2){
//				cout<<"deepest-1 loop"<<'\n';		
//				cout<<"id="<<id<<'\n';
//				cout<<w_1<<"/"<<w_2<<"/"<<x_1<<"/"<<x_2<<'\n';
//				cout<<weight<<'\n';
//				cout<<maximumweight<<'\n';
			if(weight > maximumweight){
				maximumweight = weight; 
//				cout<<"DEEPEST LOOP"<<'\n';
			}
		}
	}
//cout<<"second loop"<<'\n';


	}
fclose(file2);

ID.push_back(id);
WEIGHT.push_back(maximumweight);


}// if from the case that no maximum weight was found in the vector


RATIO = w/maximumweight; 

mytreewrng->Fill();

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
if(m_H>120 && m_H<130){
	h1->Fill(m_Wp,m_t);
	h2->Fill(m_Wm,m_tb);

}

if(m_H<120 || m_H>130){
	h4->Fill(m_Wp,m_t);
	h5->Fill(m_Wm,m_tb);
}



//h6->Fill(ratio);
*/
//h7->Fill(RATIO);

//if (w_c<0){cout<<"problemo "<<w_c<<'\n';}


}	// flag's bracket

else{

	if(flag==1){
	//h3->Fill(m_H);

	//w_c = (w1*w2)/(x1*x2);	
	
	max_weight_forcrrct = 0.0;

	FILE *file3 = fopen(name,"r");


        while(!feof(file3)){

                fscanf(file3," %d "     ,&eventNumber3);
                fscanf(file3," %d "     ,&mtop3);
                fscanf(file3," %d "     ,&mw3);
                fscanf(file3," %d "     ,&lepton_comb3);
                fscanf(file3," %d "     ,&jet_comb3);
                fscanf(file3," %lf "    ,&max_weight3);
                fscanf(file3," %lf "    ,&max_higgs_mass3);
                fscanf(file3," %lf "    ,&max_ttbar_mass3);
                fscanf(file3," %lf "    ,&mean_higgs_mass3);
                fscanf(file3," %lf %lf " ,&Metx3       ,&Mety3);
                fscanf(file3," %lf %lf %lf ", &b_h_1[1]  ,&b_h_1[2]  ,&b_h_1[3]);
                fscanf(file3," %lf %lf %lf ", &b_h_2[1]  ,&b_h_2[2]  ,&b_h_2[3]);
                fscanf(file3," %lf %lf %lf ", &b_Top[1]  ,&b_Top[2]  ,&b_Top[3]);
                fscanf(file3," %lf %lf %lf ", &b_Topb[1]  ,&b_Topb[2]  ,&b_Topb[3]);
                fscanf(file3," %lf %lf %lf ", &l_P[1]  ,&l_P[2]  ,&l_P[3]);
                fscanf(file3," %lf %lf %lf ", &l_M[1]  ,&l_M[2]  ,&l_M[3]);
                fscanf(file3," %lf %lf %lf ", &n1_p_x  ,&n1_p_y  ,&n1_p_z);
                fscanf(file3," %lf %lf %lf ", &n2_p_x  ,&n2_p_y  ,&n2_p_z);
                fscanf(file3," %d "        ,&flag3);
                fscanf(file3," %lf %lf "   ,&W_1,&W_2);
                fscanf(file3," %lf %lf "   ,&X_1,&X_2);

		corr_weight = (W_1*W_2)/(X_1*X_2);
		
			if(id==eventNumber3){
				if(corr_weight>max_weight_forcrrct){
					max_weight_forcrrct = corr_weight;
				}
			}

	}
fclose(file3);

	ratio = w/max_weight_forcrrct;

mytreecrrct->Fill();
	}
}

}//	End of while loop	/////

fclose(file);

//	Canvases	//

/*
TCanvas *c1 = new TCanvas("c1","Higgs_mass");
c1->cd();

h3->Draw();

c1->SaveAs("Higgs_mass_sametxt.png");
*/
/////
/*
TCanvas *c2 = new TCanvas("c2","top vs mWp");
c2->cd();

h1->Draw("Colz");

c2->SaveAs("topmass_vs_mWpmass_inpeak.png");
*/

/////
/*
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

TCanvas *c5 = new TCanvas("c5","top vs mWp");
c5->cd();

h5->Draw("Colz");

c5->SaveAs("topbmass_vs_mWmmass_outofpeak.png");
*/
/////

/*
TCanvas *c6 = new TCanvas("c6","w_correct/w_max");
c6->cd();

h6->Draw();

c6->SaveAs("ratio_of_w.png");
*/
/*
TCanvas *c7 = new TCanvas("c6","w_wrong/w_max");
c7->cd();

h7->Draw();

c7->SaveAs("ratio_of_w_wrong_sametxt.png");
*/

//////////////////////////////////	ROOT FILES CREATION	//////////////////////////////////////////

TFile *fileW = new TFile("wrng_sol.root","RECREATE");

fileW->cd();

mytreewrng->Write();

fileW->Close();

/////////////////////////////////////////////////////////////////////////////////////////////////////////

TFile *fileC = new TFile("crrct_sol.root","RECREATE");

fileC->cd();

mytreecrrct->Write();

fileC->Close();


}
