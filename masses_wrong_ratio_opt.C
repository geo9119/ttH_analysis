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



///////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////*******************************////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

int eventnumber , top_mass , w_mass , lep_comb , jet_comb; 
double max_weight;
double et1 , et2;
double bh1[4] , bh2[4];
double btop[4] , btopb[4];
double lp[4]  , lm[4];
double n1px , n1py , n1pz , n1e;
double n2px , n2py , n2pz , n2e;
double w1,w2,x1,x2;
double max_higgs_mass , max_ttbar_mass , mean_mass;

double m_H;
double m_top;


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
double weight , w;

int id;

vector<double> ID;
vector<double> WEIGHT;

////////////////////////////////////////for the second file that loops for greatest weight

int Eventnumber , Top_mass , W_mass , Lep_comb , Jet_comb; 
double Max_weight;
double Et1 , Et2;
double Bh1[4] , Bh2[4];
double Btop[4] , Btopb[4];
double Lp[4]  , Lm[4];
double N1px , N1py , N1pz;
double N2px , N2py , N2pz;
double w_1,w_2,x_1,x_2;
double Max_higgs_mass , Max_ttbar_mass , Mean_mass;

double m_t , m_tb;

double maximumweight;
double RATIO;

//////////////////////////////	TREE DEFINITION	//////////////////////////////////////////////////////////
/////////////////////////////	***************	//////////////////////////////////////////////////////////	
//////////////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////	Tree of wrong solutions	/////////////////////////////////////////////////

TTree *mytree = new TTree("mytree","mytree");

mytree->Branch("ratio"		,&RATIO		,"RATIO/D");
mytree->Branch("w1"		,&w1		,"w1/D");
mytree->Branch("w2"		,&w2		,"w2/D");
mytree->Branch("x1"		,&x1		,"x1/D");
mytree->Branch("x2"		,&x2		,"x2/D");
mytree->Branch("E_tt"		,&E_tt		,"E_tt/D");
mytree->Branch("higgs_pt_ratio"	,&higgs_pt_ratio,"higgs_pt_ratio/D");
mytree->Branch("higgs_pt_asym"	,&asym		,"asym/D");
mytree->Branch("deta1"		,&deta1		,"deta1/D");
mytree->Branch("dphi1"		,&dphi1		,"dphi1/D");
mytree->Branch("dr1"		,&dr1		,"dr1/D");
mytree->Branch("deta2"		,&deta2		,"deta2/D");
mytree->Branch("dphi2"		,&dphi2		,"dphi2/D");
mytree->Branch("dr2"		,&dr2		,"dr2/D");
mytree->Branch("deta3"		,&deta3		,"deta3/D");
mytree->Branch("dphi3"		,&dphi3		,"dphi3/D");
mytree->Branch("dr3"		,&dr3		,"dr3/D");
mytree->Branch("deta4"		,&deta4		,"deta4/D");
mytree->Branch("dphi4"		,&dphi4		,"dphi4/D");
mytree->Branch("dr4"		,&dr4		,"dr4/D");
mytree->Branch("deta5"		,&deta5		,"deta5/D");
mytree->Branch("dphi5"		,&dphi5		,"dphi5/D");
mytree->Branch("dr5"		,&dr5		,"dr5/D");
mytree->Branch("deta6"		,&deta6		,"deta6/D");
mytree->Branch("dphi6"		,&dphi6		,"dphi6/D");
mytree->Branch("dr6"		,&dr6		,"dr6/D");
mytree->Branch("deta7"		,&deta7		,"deta7/D");
mytree->Branch("dphi7"		,&dphi7		,"dphi7/D");
mytree->Branch("dr7"		,&dr7		,"dr7/D");
mytree->Branch("deta8"		,&deta8		,"deta8/D");
mytree->Branch("dphi8"		,&dphi8		,"dphi8/D");
mytree->Branch("dr8"		,&dr8		,"dr8/D");
mytree->Branch("deta9"		,&deta9		,"deta9/D");
mytree->Branch("dphi9"		,&dphi9		,"dphi9/D");
mytree->Branch("dr9"		,&dr9		,"dr9/D");
mytree->Branch("deta10"		,&deta10	,"deta10/D");
mytree->Branch("dphi10"		,&dphi10	,"dphi10/D");
mytree->Branch("dr10"		,&dr10		,"dr10/D");
mytree->Branch("deta11"		,&deta11	,"deta11/D");
mytree->Branch("dphi11"		,&dphi11	,"dphi11/D");
mytree->Branch("dr11"		,&dr11		,"dr11/D");
mytree->Branch("deta12"		,&deta12	,"deta12/D");
mytree->Branch("dphi12"		,&dphi12	,"dphi12/D");
mytree->Branch("dr12"		,&dr12		,"dr12/D");
mytree->Branch("deta13"		,&deta13	,"deta13/D");
mytree->Branch("dphi13"		,&dphi13	,"dphi13/D");
mytree->Branch("dr13"		,&dr13		,"dr13/D");
mytree->Branch("m_H"		,&m_H		,"m_H/D");
mytree->Branch("event_number"	,&eventnumber	,"eventnumber/I");
mytree->Branch("lep_comb"	,&lep_comb	,"lep_comb/I");
mytree->Branch("jet_comb"	,&jet_comb	,"jet_comb/I");



//////////////////////////////////////////////////////////////////////////////////////////////////////////////


//	FILE *file = fopen("/home/george/Desktop/ttjets/rootfiles_ttjets/output_ttjets_debug.txt","r");

//	FILE *file = fopen("/home/george/Desktop/ttjets/output_ttjets/ttjets_4.dat.out","r");
	FILE *file = fopen(name,"r");


while(!feof(file)){

        fscanf(file," %d "      ,&eventnumber);
        fscanf(file," %d "      ,&top_mass);
        fscanf(file," %d "      ,&w_mass);
        fscanf(file," %d "      ,&lep_comb);
        fscanf(file," %d "      ,&jet_comb);
        fscanf(file," %lf "     ,&max_weight);
        fscanf(file," %lf "     ,&max_higgs_mass);
        fscanf(file," %lf "     ,&max_ttbar_mass);
        fscanf(file," %lf "     ,&mean_mass);
        fscanf(file," %lf %lf " ,&et1  ,&et2);
        fscanf(file," %lf %lf %lf ", &bh1[1]  ,&bh1[2]  ,&bh1[3]);
        fscanf(file," %lf %lf %lf ", &bh2[1]  ,&bh2[2]  ,&bh2[3]);
        fscanf(file," %lf %lf %lf ", &btop[1]  ,&btop[2]  ,&btop[3]);
        fscanf(file," %lf %lf %lf ", &btopb[1]  ,&btopb[2]  ,&btopb[3]);
        fscanf(file," %lf %lf %lf ", &lp[1]  ,&lp[2]  ,&lp[3]);
        fscanf(file," %lf %lf %lf ", &lm[1]  ,&lm[2]  ,&lm[3]);
        fscanf(file," %lf %lf %lf ", &n1px  ,&n1py  ,&n1pz);
        fscanf(file," %lf %lf %lf ", &n2px  ,&n2py  ,&n2pz);
        fscanf(file," %lf %lf "    ,&w1,&w2);
        fscanf(file," %lf %lf "    ,&x1,&x2);


//cout<<"loop1"<<'\n';
cout<<eventnumber<<'\n';

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

/*//// bh2 and bh1  ////

deta14 = higgs2.Eta() - higgs1.Eta();
dphi14 = fabs(higgs2.DeltaPhi(higgs1));
dr14 = sqrt(deta14*deta14 + dphi14*dphi14);
*/


w = (w1*w2)/(x1*x2);

//ratio =w_c/max_weight;

//weight=(w_1*w_2)/(x_1*x_2);


id = eventnumber;


////////////////////////////////////////////////////////////////////////////////////////////	


maximumweight = 0.0;

	for(int i=0; i< ID.size(); i++){

			if(id==ID[i]){
			maximumweight = WEIGHT[i];
			}		
	}


	if(maximumweight==0.0){

// loop over the same (wrong) event to get the maximum weight///


//	FILE *file2 = fopen("/home/george/Desktop/ttjets/rootfiles_ttjets/output_ttjets_debug.txt","r");

//FILE *file2 = fopen("/home/george/Desktop/ttjets/output_ttjets/ttjets_4.dat.out","r");
FILE *file2 = fopen(name,"r");


	while(!feof(file2)){

        fscanf(file2," %d "      ,&Eventnumber);
        fscanf(file2," %d "      ,&Top_mass);
        fscanf(file2," %d "      ,&W_mass);
        fscanf(file2," %d "      ,&Lep_comb);
        fscanf(file2," %d "      ,&Jet_comb);
        fscanf(file2," %lf "     ,&Max_weight);
        fscanf(file2," %lf "     ,&Max_higgs_mass);
        fscanf(file2," %lf "     ,&Max_ttbar_mass);
        fscanf(file2," %lf "     ,&Mean_mass);
        fscanf(file2," %lf %lf " ,&Et1  ,&Et2);
        fscanf(file2," %lf %lf %lf ", &Bh1[1]  ,&Bh1[2]  ,&Bh1[3]);
        fscanf(file2," %lf %lf %lf ", &Bh2[1]  ,&Bh2[2]  ,&Bh2[3]);
        fscanf(file2," %lf %lf %lf ", &Btop[1]  ,&Btop[2]  ,&Btop[3]);
        fscanf(file2," %lf %lf %lf ", &Btopb[1]  ,&Btopb[2]  ,&Btopb[3]);
        fscanf(file2," %lf %lf %lf ", &Lp[1]  ,&Lp[2]  ,&Lp[3]);
        fscanf(file2," %lf %lf %lf ", &Lm[1]  ,&Lm[2]  ,&Lm[3]);
        fscanf(file2," %lf %lf %lf ", &N1px  ,&N1py  ,&N1pz);
        fscanf(file2," %lf %lf %lf ", &N2px  ,&N2py  ,&N2pz);
        fscanf(file2," %lf %lf "    ,&w_1,&w_2);
        fscanf(file2," %lf %lf "    ,&x_1,&x_2);
		
weight=(w_1*w_2)/(x_1*x_2);

//cout<<"read"<<'\n';
	
		if(id==Eventnumber){
//				cout<<"deepest-1 loop"<<'\n';		
//				cout<<"id="<<id<<'\n';
//				cout<<w_1<<"/"<<w_2<<"/"<<x_1<<"/"<<x_2<<'\n';
//				cout<<weight<<'\n';
//				cout<<maximumweight<<'\n';
			if(weight > maximumweight){
				maximumweight = weight; 
//				cout<<"\t DEEPEST LOOP"<<'\n';
			}
		}
	
//cout<<"second loop"<<'\n';


	}// end of while from the second scan
fclose(file2);

ID.push_back(id);
WEIGHT.push_back(maximumweight);


}// if from the case that no maximum weight was found in the vector


RATIO = w/maximumweight; 



	mytree->Fill();





}//	End of while loop	/////

fclose(file);

//////////////////////////////////	ROOT FILES CREATION	//////////////////////////////////////////

TFile *Rfile = new TFile("ttjets.root","RECREATE");

Rfile->cd();

mytree->Write();

Rfile->Close();

/////////////////////////////////////////////////////////////////////////////////////////////////////////


}
