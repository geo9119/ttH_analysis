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


void angular2(){


//	Deta between lp and all b jets		//

TH1D *h1 = new TH1D("lp deta","lp deta",30,-10.,10.);
h1->SetXTitle("deta");
h1->SetYTitle("Counts");

TH1D *h2 = new TH1D("2 lp with b_tb","deta of lp with b of top bar branch",30,-10.,10.);
h2->SetXTitle("deta");
h2->SetYTitle("Counts");
h2->SetLineColor(kRed);

TH1D *h3 = new TH1D("3 lp with b_H1","deta of lp with b1 of Higgs",30,-10.,10.);
h3->SetXTitle("deta");
h3->SetYTitle("Counts");
h3->SetLineColor(kGreen);

TH1D *h4 = new TH1D("4 lp with b_H2","deta of lp with b2 of Higgs",30,-10.,10.);
h4->SetXTitle("deta");
h4->SetYTitle("Counts");
h4->SetLineColor(kMagenta);


//	Deta between lm and all b jets		//

TH1D *g1 = new TH1D("lm deta with b of top branch","deta",30,-10.,10.);
g1->SetXTitle("deta");
g1->SetYTitle("Counts");
g1->SetLineColor(kRed);

TH1D *g2 = new TH1D("lm deta","deta of lm",30,-10.,10.);
g2->SetXTitle("deta");
g2->SetYTitle("Counts");

TH1D *g3 = new TH1D("7 lm with b_H1","deta of lm with b1 of Higgs",30,-10.,10.);
g3->SetXTitle("deta");
g3->SetYTitle("Counts");
g3->SetLineColor(kGreen);

TH1D *g4 = new TH1D("8 lm with b_H2","deta of lm with b2 of Higgs",30,-10.,10.);
g4->SetXTitle("deta");
g4->SetYTitle("Counts");
g4->SetLineColor(kMagenta);


//	Dphi between lp and all b jets		//

TH1D *k1 = new TH1D("lp dphi with b of top branch","dphi of lp ",30,-1.,6.);
k1->SetXTitle("dphi");
k1->SetYTitle("Counts");

TH1D *k2 = new TH1D("lp dphi","dphi of lp",30,-1.,6.);
k2->SetXTitle("dphi");
k2->SetYTitle("Counts");
k2->SetLineColor(kRed);

TH1D *k3 = new TH1D("11 lp with b_H1","dphi of lp with b1 of Higgs",30,-1.,6.);
k3->SetXTitle("dphi");
k3->SetYTitle("Counts");
k3->SetLineColor(kGreen);

TH1D *k4 = new TH1D("12 lp with b_H2","dphi of lp with b2 of Higgs",30,-1.,6.);
k4->SetXTitle("dphi");
k4->SetYTitle("Counts");
k4->SetLineColor(kMagenta);


//	Dphi between lm and all b jets		//

TH1D *f1 = new TH1D("lm dphi","dphi of lm",30,-1.,6.);
f1->SetXTitle("dphi");
f1->SetYTitle("Counts");
f1->SetLineColor(kRed);

TH1D *f2 = new TH1D("14 lm with b_tb","dphi of lm with b of top bar branch",30,-1.,6.);
f2->SetXTitle("dphi");
f2->SetYTitle("Counts");

TH1D *f3 = new TH1D("15 lm with b_H1","dphi of lm with b1 of Higgs",30,-1.,6.);
f3->SetXTitle("dhi");
f3->SetYTitle("Counts");
f3->SetLineColor(kGreen);

TH1D *f4 = new TH1D("16 lm with b_H2","dphi of lm with b2 of Higgs",30,-1.,6.);
f4->SetXTitle("dphi");
f4->SetYTitle("Counts");
f4->SetLineColor(kMagenta);


//	DR between lp and all b jets		//

TH1D *p1 = new TH1D("lp dR with b of top branch","dR of lp",30,-1.,10.);
p1->SetXTitle("dR");
p1->SetYTitle("Counts");

TH1D *p2 = new TH1D("18 lp with b_tb","dR of lp with b of top bar branch",30,-1.,10.);
p2->SetXTitle("dR");
p2->SetYTitle("Counts");
p2->SetLineColor(kRed);

TH1D *p3 = new TH1D("lp dR","dR of lp",30,-1.,10.);
p3->SetXTitle("dR");
p3->SetYTitle("Counts");
p3->SetLineColor(kGreen);

TH1D *p4 = new TH1D("20 lp with b_H2","dR of lp with b2 of Higgs",30,-1.,10.);
p4->SetXTitle("dR");
p4->SetYTitle("Counts");
p4->SetLineColor(kMagenta);


//	DR between lm and all b jets		//

TH1D *d1 = new TH1D("lm dR","dR of lm",30,-1.,10.);
d1->SetXTitle("dR");
d1->SetYTitle("Counts");
d1->SetLineColor(kRed);

TH1D *d2 = new TH1D("22 lm with b_tb","dR of lm with b of top bar branch",30,-1.,10.);
d2->SetXTitle("dR");
d2->SetYTitle("Counts");

TH1D *d3 = new TH1D("23 lm with b_H1","dR of lm with b1 of Higgs",30,-1.,10.);
d3->SetXTitle("dR");
d3->SetYTitle("Counts");
d3->SetLineColor(kGreen);

TH1D *d4 = new TH1D("24 lm with b_H2","dR of lm with b2 of Higgs",30,-1.,10.);
d4->SetXTitle("dR");
d4->SetYTitle("Counts");
d4->SetLineColor(kMagenta);


//	Deta between bH1 and all b jets		//

TH1D *s1 = new TH1D("bH1 deta","deta of bH1",30,-10.,10.);
s1->SetXTitle("deta");
s1->SetYTitle("Counts");
s1->SetLineColor(kRed);

TH1D *s2 = new TH1D("26 bH1 with b_tb","deta of bH1 with b of top bar branch",30,-10.,10.);
s2->SetXTitle("deta");
s2->SetYTitle("Counts");
s2->SetLineColor(kGreen);

TH1D *s3 = new TH1D("27 bH1 with bH2","deta of bH1 with bH2 of Higgs",30,-10.,10.);
s3->SetXTitle("deta");
s3->SetYTitle("Counts");

//	Dphi between bH1 and all b jets		//

TH1D *z1 = new TH1D("bH1 dphi with b of top branch","dphi of bH1",30,-1.,6.);
z1->SetXTitle("dphi");
z1->SetYTitle("Counts");
z1->SetLineColor(kRed);

TH1D *z2 = new TH1D("29 bH1 with b_tb","dphi of bH1 with b of top bar branch",30,-1.,6.);
z2->SetXTitle("dphi");
z2->SetYTitle("Counts");
z2->SetLineColor(kGreen);

TH1D *z3 = new TH1D("bH1 dphi","dphi of bH1",30,-1.,6.);
z3->SetXTitle("dphi");
z3->SetYTitle("Counts");

//	DR between bH1 and all b jets		//

TH1D *q1 = new TH1D("31 bH1 dR with b of top branch","dR of bH1",30,0.,10.);
q1->SetXTitle("dR");
q1->SetYTitle("Counts");
q1->SetLineColor(kRed);

TH1D *q2 = new TH1D("32 bH1 with b_tb","dR of bH1 with b of top bar branch",30,0.,10.);
q2->SetXTitle("dR");
q2->SetYTitle("Counts");
q2->SetLineColor(kGreen);

TH1D *q3 = new TH1D("bH1 dR","dR of bH1",30,0.,10.);
q3->SetXTitle("dR");
q3->SetYTitle("Counts");


//	Deta between bH2 and all b jets		//

TH1D *s11 = new TH1D("bH2 deta","deta of bH2",30,-10.,10.);
s11->SetXTitle("deta");
s11->SetYTitle("Counts");
s11->SetLineColor(kRed);

TH1D *s21 = new TH1D("35 bH2 with b_tb","deta of bH2 with b of top bar branch",30,-10.,10.);
s21->SetXTitle("deta");
s21->SetYTitle("Counts");
s21->SetLineColor(kGreen);


//	Dphi between bH2 and all b jets		//

TH1D *z11 = new TH1D("bH2 dphi","dphi of bH2",30,-1.,6.);
z11->SetXTitle("dphi");
z11->SetYTitle("Counts");
z11->SetLineColor(kRed);

TH1D *z21 = new TH1D("37 bH2 with b_tb","dphi of bH2 with b of top bar branch",30,-1.,6.);
z21->SetXTitle("dphi");
z21->SetYTitle("Counts");
z21->SetLineColor(kGreen);


//	DR between bH2 and all b jets		//

TH1D *q11 = new TH1D("bH2 dR","dR of bH2",30,0.,10.);
q11->SetXTitle("dR");
q11->SetYTitle("Counts");
q11->SetLineColor(kRed);

TH1D *q21 = new TH1D("39 bH2 with b_tb","dR of bH2 with b of top bar branch",30,0.,10.);
q21->SetXTitle("dR");
q21->SetYTitle("Counts");
q21->SetLineColor(kGreen);

//	tt system energy	//

TH1D *e1 = new TH1D("Energy tt","Energy tt",30,100.,3000.);
e1->SetXTitle("E");
e1->SetYTitle("Counts");

TH1D *e2 = new TH1D("41 energy tt","Energy tt wrong",30,100.,3000.);
e2->SetXTitle("E  GeV");
e2->SetYTitle("Counts");
e2->SetLineColor(kRed);

//	ttH system energy	//

TH1D *e3 = new TH1D("Energy ttH","Energy ttH",30,400.,3000.);
e3->SetXTitle("E GeV");
e3->SetYTitle("Counts");

TH1D *e4 = new TH1D("43 energy ttH","Energy ttH wrong",30,400.,3000.);
e4->SetXTitle("E GeV");
e4->SetYTitle("Counts");
e4->SetLineColor(kRed);


//	tt system mass	//

TH1D *m1 = new TH1D("Mass tt","Mass tt",30,0.,2500.);
m1->SetXTitle("Mass GeV/c^2");
m1->SetYTitle("Counts");

TH1D *m2 = new TH1D("45 mass tt","Mass tt wrong",30,0.,2500.);
m2->SetXTitle("Mass GeV/c^2");
m2->SetYTitle("Counts");
m2->SetLineColor(kRed);


//	ttH system mass	//

TH1D *m3 = new TH1D("Mass ttH","Mass ttH",30,0.,3000.);
m3->SetXTitle("Mass GeV/c^2");
m3->SetYTitle("Counts");

TH1D *m4 = new TH1D("45 mass ttH","Mass ttH wrong",30,0.,3000.);
m4->SetXTitle("Mass GeV/c^2");
m4->SetYTitle("Counts");
m4->SetLineColor(kRed);

//	pt asymmetry of Higgs	//

TH1D *i1 = new TH1D("pt asymmetry Higgs","pt asymmetry Higgs correct",30,-1.,1.);
i1->SetXTitle("GeV");
i1->SetYTitle("Counts");

TH1D *i2 = new TH1D("p_t asymmetry Higgs","p_t asymmetry Higgs wrong",30,-1.,1.);
i2->SetXTitle("GeV");
i2->SetYTitle("Counts");
i2->SetLineColor(kRed);

//	2D histogram of pt momenta of Higgs	//

TH2D *v1 = new TH2D("2d histo","2-D histo of Higgs pt - CORRECT;pt_H1;pt_H2",30,0.,300.,30,0.,350.);
//v1->SetXTitle("pt1");
//v1->SetYTitle("pt2");

TH2D *v2 = new TH2D("2_d histo","2-D histo of Higgs pt - WRONG;pt_H1;pt_H2",30,0.,300.,30,0.,350.);
//v2->SetXTitle("pt1");
//v2->SetYTitle("pt2");

//	2D histogram of pt momenta of top and topbar	//

TH2D *v3 = new TH2D("2d histo 3","2-D histo of top/topb pt - CORRECT;pt_top;pt_topbar",30,0.,300.,30,0.,350.);
//v1->SetXTitle("pt1");
//v1->SetYTitle("pt2");

TH2D *v4 = new TH2D("2_d histo 4","2-D histo of top/topb pt - WRONG;pt_top;pt_topb",30,0.,300.,30,0.,350.);
//v2->SetXTitle("pt1");
//v2->SetYTitle("pt2");


//	pt1/pt2		//

TH1D *i3 = new TH1D("pt_h1/pt_h2","pt ratio - CORRECT",30,0.,5.);
i3->SetXTitle("GeV");
i3->SetYTitle("Counts");

TH1D *i4 = new TH1D("(pt_h1/pt_h2)","pt ratio - WRONG",30,0.,5.);
i4->SetXTitle("GeV");
i4->SetYTitle("Counts");
i4->SetLineColor(kRed);

//	Metx Mety		//

TH1D *i5 = new TH1D("Metx","Metx - CORRECT",30,0.,400.);
i5->SetXTitle("Met_{x} GeV");
i5->SetYTitle("Counts");

TH1D *i6 = new TH1D("Met_x","Metx - WRONG",30,0.,400.);
i6->SetXTitle("Met_{x} GeV");
i6->SetYTitle("Counts");
i6->SetLineColor(kRed);

TH1D *i7 = new TH1D("Mety","Mety - CORRECT",30,0.,400.);
i7->SetXTitle("Met_{y} GeV");
i7->SetYTitle("Counts");

TH1D *i8 = new TH1D("Met_y","Mety - WRONG",30,0.,400.);
i8->SetXTitle("Met_{y} GeV");
i8->SetYTitle("Counts");
i8->SetLineColor(kRed);


//	pnux pnuy		//

TH1D *i9 = new TH1D("pnux","pnux - CORRECT",30,0.,400.);
i9->SetXTitle("p_{#nu_{x}} GeV");
i9->SetYTitle("Counts");

TH1D *i10 = new TH1D("pnu_x","pnux - WRONG",30,0.,400.);
i10->SetXTitle("p_{#nu_{x}} GeV");
i10->SetYTitle("Counts");
i10->SetLineColor(kRed);

TH1D *i11 = new TH1D("pnuy","pnuy - CORRECT",30,0.,400.);
i11->SetXTitle("p_{#nu_{y}} GeV");
i11->SetYTitle("Counts");

TH1D *i12 = new TH1D("pnu_y","pnuy - WRONG",30,0.,400.);
i12->SetXTitle("p_{#nu_{y}} GeV");
i12->SetYTitle("Counts");
i12->SetLineColor(kRed);

//	pnubx pnuby		//

TH1D *i13 = new TH1D("pnubx","pnubx - CORRECT",30,0.,400.);
i13->SetXTitle("p_{#bar{#nu}_{x}} GeV");
i13->SetYTitle("Counts");

TH1D *i14 = new TH1D("pnub_x","pnubx - WRONG",30,0.,400.);
i14->SetXTitle("p_{#bar{#nu}_{x}} GeV");
i14->SetYTitle("Counts");
i14->SetLineColor(kRed);

TH1D *i15 = new TH1D("pnuby","pnuby - CORRECT",30,0.,400.);
i15->SetXTitle("p_{#bar{#nu}_{y}} GeV");
i15->SetYTitle("Counts");

TH1D *i16 = new TH1D("pnub_y","pnuby - WRONG",30,0.,400.);
i16->SetXTitle("p_{#bar{#nu}_{y}} GeV");
i16->SetYTitle("Counts");
i16->SetLineColor(kRed);

//      pnubz pnubz             //

TH1D *i17 = new TH1D("pnuz","pnuz - CORRECT",30,0.,400.);
i17->SetXTitle("p_{#nu_{z}} GeV");
i17->SetYTitle("Counts");

TH1D *i18 = new TH1D("pnu_z","pnuz - WRONG",30,0.,400.);
i18->SetXTitle("p_{#nu_{z}} GeV");
i18->SetYTitle("Counts");
i18->SetLineColor(kRed);

TH1D *i19 = new TH1D("pnubz","pnubz - CORRECT",30,0.,400.);
i19->SetXTitle("p_{#bar{#nu}_{z}} GeV");
i19->SetYTitle("Counts");

TH1D *i20 = new TH1D("pnub_z","pnubz - WRONG",30,0.,400.);
i20->SetXTitle("p_{#bar{#nu}_{z}} GeV");
i20->SetYTitle("Counts");
i20->SetLineColor(kRed);


////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////**************************************/////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////



int eventNumber,numb,nn;
double btop[4],btopb[4],lp[4],lm[4],bh1[4],bh2[4],bh_tot[4],metx,mety;
int dummy;
double dummy1,dummy2,comb,higgs_mass;
int mtop,mw,lep_comb,jet_comb;
double max_weight,mean_higgs_mass,tt_mass;
double n1px,n1py,n1pz,n2px,n2py,n2pz;
double top_mass , topb_mass;
double mWp_mass , mWm_mass;
double E_ttH , m_ttH;
double E_tt , m_tt;
double m_H;
int flags;
double sum_ett1=0;
double sum_ett2=0;
double tot_sum_ett1 , tot_sum_ett2;
double sum_mtt1=0;
double sum_mtt2=0;
double tot_sum_mtt1 , tot_sum_mtt2;
double ratio_ett1 , ratio_ett2;
double ratio_mtt1 , ratio_mtt2;


double sum_ettH1=0;
double sum_ettH2=0;
double tot_sum_ettH1 , tot_sum_ettH2;
double sum_mttH1=0;
double sum_mttH2=0;
double tot_sum_mttH1 , tot_sum_mttH2;
double ratio_ettH1 , ratio_ettH2;
double ratio_mttH1 , ratio_mttH2;

double pt_H1 , pt_H2;
double asym;

double pt_top , pt_topb;

double ratio;

  FILE *file = fopen("/home/george/Desktop/ttH_allsolutionsless0.5/ttH_allsolutless0.5.txt","r");


while(!feof(file))
{
     fscanf(file," %d ",&eventNumber);
     fscanf(file," %d ",&mtop);
     fscanf(file," %d ", &mw);
     fscanf(file," %d ", &lep_comb);
     fscanf(file," %d ", &jet_comb);
     fscanf(file," %lf ", &max_weight);
     fscanf(file," %lf ", &higgs_mass);
     fscanf(file," %lf ", &tt_mass);
     fscanf(file," %lf ", &mean_higgs_mass);
     fscanf(file," %lf %lf ",    &metx,&mety);
     fscanf(file," %lf %lf %lf ", &bh1[1]  ,&bh1[2]  ,&bh1[3]);
     fscanf(file," %lf %lf %lf ", &bh2[1]  ,&bh2[2]  ,&bh2[3]);
     fscanf(file," %lf %lf %lf ", &btop[1]  ,&btop[2]  ,&btop[3]);
     fscanf(file," %lf %lf %lf ", &btopb[1]  ,&btopb[2]  ,&btopb[3]);
     fscanf(file," %lf %lf %lf ", &lp[1]  ,&lp[2]  ,&lp[3]);
     fscanf(file," %lf %lf %lf ", &lm[1]  ,&lm[2]  ,&lm[3]);
     fscanf(file," %lf %lf %lf ", &n1px  ,&n1py  ,&n1pz);
     fscanf(file," %lf %lf %lf ", &n2px  ,&n2py  ,&n2pz);
     fscanf(file," %d ",&flags);



TLorentzVector n1,n2;

double n1e=sqrt(n1px*n1px+n1py*n1py+n1pz*n1pz);
double n2e=sqrt(n2px*n2px+n2py*n2py+n2pz*n2pz);

n1.SetPxPyPzE(n1px,n1py,n1pz,n1e);
n2.SetPxPyPzE(n2px,n2py,n2pz,n2e);


TLorentzVector higgs1,higgs2;

bh1[0] = sqrt(bh1[1]*bh1[1]+bh1[2]*bh1[2]+bh1[3]*bh1[3]+4.8*4.8);
bh2[0] = sqrt(bh2[1]*bh2[1]+bh2[2]*bh2[2]+bh2[3]*bh2[3]+4.8*4.8);


higgs1.SetPxPyPzE(bh1[1],bh1[2],bh1[3],bh1[0]);
higgs2.SetPxPyPzE(bh2[1],bh2[2],bh2[3],bh2[0]);

TLorentzVector t1,t2;
     
btop[0] = sqrt(btop[1]*btop[1]+btop[2]*btop[2]+btop[3]*btop[3]+4.8*4.8);
btopb[0] = sqrt(btopb[1]*btopb[1]+btopb[2]*btopb[2]+btopb[3]*btopb[3]+4.8*4.8);

t1.SetPxPyPzE(btop[1],btop[2],btop[3],btop[0]);
t2.SetPxPyPzE(btopb[1],btopb[2],btopb[3],btopb[0]);

TLorentzVector l1,l2;

lp[0] = sqrt(lp[1]*lp[1]+lp[2]*lp[2]+lp[3]*lp[3]);
lm[0] = sqrt(lm[1]*lm[1]+lm[2]*lm[2]+lm[3]*lm[3]);

l1.SetPxPyPzE(lp[1],lp[2],lp[3],lp[0]);
l2.SetPxPyPzE(lm[1],lm[2],lm[3],lm[0]);

TLorentzVector tt , ttH;

tt = n1 + l1 + t1 + n2 + t2 + l2;  

ttH = tt + higgs1 + higgs2;

E_tt = tt.E();
m_tt = tt.M();

E_ttH = ttH.E();
m_ttH = ttH.M();

TLorentzVector Higgs;

Higgs = higgs1 + higgs2;

m_H = Higgs.M();

pt_H1 = sqrt(bh1[1]*bh1[1]+bh1[2]*bh1[2]);
pt_H2 = sqrt(bh2[1]*bh2[1]+bh2[2]*bh2[2]);

asym = (pt_H1 - pt_H2)/(pt_H1 + pt_H2);

pt_top  = sqrt(btop[1]*btop[1]+btop[2]*btop[2]);
pt_topb = sqrt(btopb[1]*btopb[1]+btopb[2]*btopb[2]);


ratio = pt_H1/pt_H2;

//// lp and b of top branch ////

double deta1 = l1.Eta() - t1.Eta();
double dphi1 = fabs(l1.DeltaPhi(t1));
double dr1 = sqrt(deta1*deta1 + dphi1*dphi1);


//// lp and b of top bar branch ////

double deta2 = l1.Eta() - t2.Eta();
double dphi2 = fabs(l1.DeltaPhi(t2));
double dr2 = sqrt(deta2*deta2 + dphi2*dphi2);

//// lp and b1 of Higgs////

double deta3 = l1.Eta() - higgs1.Eta();
double dphi3 = fabs(l1.DeltaPhi(higgs1));
double dr3 = sqrt(deta3*deta3 + dphi3*dphi3);

//// lp and b2 of Higgs////

double deta4 = l1.Eta() - higgs2.Eta();
double dphi4 = fabs(l1.DeltaPhi(higgs2));
double dr4 = sqrt(deta4*deta4 + dphi4*dphi4);



//// lm and b of top branch ////

double deta5 = l2.Eta() - t1.Eta();
double dphi5 = fabs(l2.DeltaPhi(t1));
double dr5 = sqrt(deta5*deta5 + dphi5*dphi5);


//// lm and b of top bar branch ////

double deta6 = l2.Eta() - t2.Eta();
double dphi6 = fabs(l2.DeltaPhi(t2));
double dr6 = sqrt(deta6*deta6 + dphi6*dphi6);

//// lm and b1 of Higgs////

double deta7 = l2.Eta() - higgs1.Eta();
double dphi7 = fabs(l2.DeltaPhi(higgs1));
double dr7 = sqrt(deta7*deta7 + dphi7*dphi7);

//// lm and b2 of Higgs////

double deta8 = l2.Eta() - higgs2.Eta();
double dphi8 = fabs(l2.DeltaPhi(higgs2));
double dr8 = sqrt(deta8*deta8 + dphi8*dphi8);


//// bh1 and bh2 ////

double deta9 = higgs1.Eta() - higgs2.Eta();
double dphi9 = fabs(higgs1.DeltaPhi(higgs2));
double dr9 = sqrt(deta9*deta9 + dphi9*dphi9);


//// bh1 and b of top branch ////

double deta10 = higgs1.Eta() - t1.Eta();
double dphi10 = fabs(higgs1.DeltaPhi(t1));
double dr10 = sqrt(deta10*deta10 + dphi10*dphi10);


//// bh1 and b of top bar branch ////

double deta11 = higgs1.Eta() - t2.Eta();
double dphi11 = fabs(higgs1.DeltaPhi(t2));
double dr11 = sqrt(deta11*deta11 + dphi11*dphi11);


//// bh2 and b of top branch ////

double deta12 = higgs2.Eta() - t1.Eta();
double dphi12 = fabs(higgs2.DeltaPhi(t1));
double dr12 = sqrt(deta12*deta12 + dphi12*dphi12);


//// bh2 and b of top bar branch ////

double deta13 = higgs2.Eta() - t2.Eta();
double dphi13 = fabs(higgs2.DeltaPhi(t2));
double dr13 = sqrt(deta13*deta13 + dphi13*dphi13);



if(flags==1){

h1->Fill(deta1);
h2->Fill(deta2);
h3->Fill(deta3);
h4->Fill(deta4);
g1->Fill(deta5);
g2->Fill(deta6);
g3->Fill(deta7);
g4->Fill(deta8);
k1->Fill(dphi1);
k2->Fill(dphi2);
k3->Fill(dphi3);
k4->Fill(dphi4);
f1->Fill(dphi5);
f2->Fill(dphi6);
f3->Fill(dphi7);
f4->Fill(dphi8);
p1->Fill(dr1);
p2->Fill(dr2);
p3->Fill(dr3);
p4->Fill(dr4);
d1->Fill(dr5);
d2->Fill(dr6);
d3->Fill(dr7);
d4->Fill(dr8);
s1->Fill(deta10);
s2->Fill(deta11);
s3->Fill(deta9);
z1->Fill(dphi10);
z2->Fill(dphi11);
z3->Fill(dphi9);
q1->Fill(dr10);
q2->Fill(dr11);
q3->Fill(dr9);
s11->Fill(deta12);
s21->Fill(deta13);
z11->Fill(dphi12);
z21->Fill(dphi13);
q11->Fill(dr12);
q21->Fill(dr13);
e1->Fill(E_tt);
e3->Fill(E_ttH);
m1->Fill(m_tt);
m3->Fill(m_ttH);
i1->Fill(asym);
v1->Fill(pt_H1,pt_H2);
v3->Fill(pt_top,pt_topb);
i3->Fill(ratio);
i5->Fill(metx);
i7->Fill(mety);
i9->Fill(n1px);
i11->Fill(n1py);
i13->Fill(n2px);
i15->Fill(n2py);
i17->Fill(n1pz);
i19->Fill(n2pz);
}

else{
if(m_H<120. || m_H>130.){
e2->Fill(E_tt);
e4->Fill(E_ttH);
m2->Fill(m_tt);
m4->Fill(m_ttH);
i2->Fill(asym);
v2->Fill(pt_H1,pt_H2);
v4->Fill(pt_top,pt_topb);
i4->Fill(ratio);
i6->Fill(metx);
i8->Fill(mety);
i10->Fill(n1px);
i12->Fill(n1py);
i14->Fill(n2px);
i16->Fill(n2py);
i18->Fill(n1pz);
i20->Fill(n2pz);
}
}

}

///  %  loss of signal and background in E_tt histo after the cut: >1.6 TeV   ///

for(int i=16;i<31;i++){
sum_ett1 = sum_ett1 + e1->GetBinContent(i);
sum_ett2 = sum_ett2 + e2->GetBinContent(i);
tot_sum_ett1 = e1->GetEntries();
tot_sum_ett2 = e2->GetEntries();
}

///  %  loss of signal and background in m_tt histo after the cut: >1 TeV   ///

for(int j=13;j<31;j++){
sum_mtt1 = sum_mtt1 + m1->GetBinContent(j);
sum_mtt2 = sum_mtt2 + m2->GetBinContent(j);
tot_sum_mtt1 = m1->GetEntries();
tot_sum_mtt2 = m2->GetEntries();
}

ratio_ett1 = sum_ett1/tot_sum_ett1;
ratio_ett2 = sum_ett2/tot_sum_ett2;
ratio_mtt1 = sum_mtt1/tot_sum_mtt1;
ratio_mtt2 = sum_mtt2/tot_sum_mtt2;


cout<< "percentage of lost signal of E_tt = "<< ratio_ett1 <<'\n';
cout<< "percentage of lost background of E_tt = "<< ratio_ett2 <<'\n';
cout<< "percentage of lost signal of m_tt = "<< ratio_mtt1 <<'\n';
cout<< "percentage of lost background of m_tt = "<< ratio_mtt2 <<'\n';

///  %  loss of signal and background in E_ttH histo after the cut: >1.6 TeV   ///

for(int k=18;k<31;k++){
sum_ettH1 = sum_ettH1 + e3->GetBinContent(k);
sum_ettH2 = sum_ettH2 + e4->GetBinContent(k);
tot_sum_ettH1 = e3->GetEntries();
tot_sum_ettH2 = e4->GetEntries();
}

///  %  loss of signal and background in m_ttH histo after the cut: >1.2 TeV   ///

for(int l=13;l<31;l++){
sum_mttH1 = sum_mttH1 + m3->GetBinContent(l);
sum_mttH2 = sum_mttH2 + m4->GetBinContent(l);
tot_sum_mttH1 = m3->GetEntries();
tot_sum_mttH2 = m4->GetEntries();
}

ratio_ettH1 = sum_ettH1/tot_sum_ettH1;
ratio_ettH2 = sum_ettH2/tot_sum_ettH2;
ratio_mttH1 = sum_mttH1/tot_sum_mttH1;
ratio_mttH2 = sum_mttH2/tot_sum_mttH2;


cout<< "percentage of lost signal of E_ttH = "<< ratio_ettH1 <<'\n';
cout<< "percentage of lost background of E_ttH = "<< ratio_ettH2 <<'\n';
cout<< "percentage of lost signal of m_ttH = "<< ratio_mttH1 <<'\n';
cout<< "percentage of lost background of m_ttH = "<< ratio_mttH2 <<'\n';


TCanvas *c1 = new TCanvas("c1","eta1");
c1->cd();

h1->DrawNormalized();
h2->Add(h3);	//DrawNormalized("same");
h2->Add(h4);		//h3->DrawNormalized("same");
		//h4->DrawNormalized("same");

h2->DrawNormalized("same");

 
TLegend *leg1 = new TLegend(0.6,0.6,0.9,0.9);
   leg1->SetHeader("deta between lp and all jets"); 
   leg1->AddEntry(h1,"correct","f");
   leg1->AddEntry(h2,"wrong","f");
	
  // leg1->AddEntry(h1,"lp - b_t","f");
  // leg1->AddEntry(h2,"lp - b_tb","f");
  // leg1->AddEntry(h3,"lp - bH1","f");
  // leg1->AddEntry(h4,"lp - bH2","f");


leg1->Draw("same");
c1->SaveAs("deta_lp_jets_added.png");


//


TCanvas *c2 = new TCanvas("c2","eta2");
c2->cd();

g2->DrawNormalized();
g1->Add(g3);
g1->Add(g4);
g1->DrawNormalized("same");
//g1->DrawNormalized("same");
//g3->DrawNormalized("same");
//g4->DrawNormalized("same");

 
TLegend *leg2 = new TLegend(0.6,0.6,0.9,0.9);
   leg2->SetHeader("deta between lm and all jets"); 

leg2->AddEntry(g2,"correct","f");
leg2->AddEntry(g1,"wrong","f");
//   leg2->AddEntry(g1,"lm - b_t","f");
//   leg2->AddEntry(g2,"lm - b_tb","f");
//   leg2->AddEntry(g3,"lm - bH1","f");
//   leg2->AddEntry(g4,"lm - bH2","f");


leg2->Draw("same");
c2->SaveAs("deta_lm_jets_added.png");


//


TCanvas *c3 = new TCanvas("c3","phi1");
c3->cd();

//k2->DrawNormalized();
k1->DrawNormalized();
//k3->DrawNormalized("same");
//k4->DrawNormalized("same");
k2->Add(k3);
k2->Add(k4);
k2->DrawNormalized("same"); 

TLegend *leg3 = new TLegend(0.6,0.6,0.9,0.9);
   leg3->SetHeader("dphi between lp and all jets"); 

   leg3->AddEntry(k1,"correct","f");
   leg3->AddEntry(k2,"wrong","f");

//  leg3->AddEntry(k1,"lp - b_t","f");
//   leg3->AddEntry(k2,"lp - b_tb","f");
//   leg3->AddEntry(k3,"lp - bH1","f");
//   leg3->AddEntry(k4,"lp - bH2","f");


leg3->Draw("same");
c3->SaveAs("dphi_lp_jets_added.png");


//



TCanvas *c4 = new TCanvas("c4","phi2");
c4->cd();

//f1->DrawNormalized();
f2->DrawNormalized();
//f3->DrawNormalized("same");
//f4->DrawNormalized("same");
f1->Add(f3);
f1->Add(f4);
f1->DrawNormalized("same");
 
TLegend *leg4 = new TLegend(0.6,0.6,0.9,0.9);
   leg4->SetHeader("dphi between lm and all jets"); 
//   leg4->AddEntry(f1,"lm - b_t","f");
//   leg4->AddEntry(f2,"lm - b_tb","f");
//   leg4->AddEntry(f3,"lm - bH1","f");
//   leg4->AddEntry(f4,"lm - bH2","f");

leg4->AddEntry(f2,"correct","f");
leg4->AddEntry(f1,"wrong","f");

leg4->Draw("same");
c4->SaveAs("dphi_lm_jets_added.png");


//


TCanvas *c5 = new TCanvas("c5","dr1");
c5->cd();

//p2->DrawNormalized();
//p3->DrawNormalized("same");
p1->DrawNormalized();
//p4->DrawNormalized("same");
p2->Add(p3);
p2->Add(p4);
p2->DrawNormalized("same");
 
TLegend *leg5 = new TLegend(0.6,0.6,0.9,0.9);
   leg5->SetHeader("dR between lp and all jets"); 
//   leg5->AddEntry(p1,"lp - b_t","f");
//   leg5->AddEntry(p2,"lp - b_tb","f");
//   leg5->AddEntry(p3,"lp - bH1","f");
//   leg5->AddEntry(p4,"lp - bH2","f");

leg5->AddEntry(p1,"correct","f");
leg5->AddEntry(p2,"wrong","f");


leg5->Draw("same");
c5->SaveAs("dR_lp_jets_added.png");


//


TCanvas *c6 = new TCanvas("c6","dr2");
c6->cd();

//d1->DrawNormalized();
d2->DrawNormalized();
//d3->DrawNormalized("same");
//d4->DrawNormalized("same");
d1->Add(d3);
d1->Add(d4);
d1->DrawNormalized("same");
 
TLegend *leg6 = new TLegend(0.6,0.6,0.9,0.9);
   leg6->SetHeader("dR between lm and all jets"); 
//   leg6->AddEntry(d1,"lm - b_t","f");
//   leg6->AddEntry(d2,"lm - b_tb","f");
//   leg6->AddEntry(d3,"lm - bH1","f");
//   leg6->AddEntry(d4,"lm - bH2","f");

leg6->AddEntry(d2,"correct","f");
leg6->AddEntry(d1,"wrong","f");

leg6->Draw("same");
c6->SaveAs("dR_lm_jets_added.png");


//


TCanvas *c7 = new TCanvas("c7","eta3");
c7->cd();

//s1->DrawNormalized();
//s2->DrawNormalized("same");
s3->DrawNormalized();
s1->Add(s2);
s1->DrawNormalized("same");
 
TLegend *leg7 = new TLegend(0.6,0.6,0.9,0.9);
   leg7->SetHeader("deta between bH1 and all jets"); 
//   leg7->AddEntry(s1,"bH1 - b_t","f");
//   leg7->AddEntry(s2,"bH1 - b_tb","f");
//   leg7->AddEntry(s3,"bH1 - bH2","f");

leg7->AddEntry(s3,"correct","f");
leg7->AddEntry(s1,"wrong","f");

leg7->Draw("same");
c7->SaveAs("deta_bH1_jets_added.png");


//



TCanvas *c8 = new TCanvas("c8","phi3");
c8->cd();

z3->DrawNormalized();
//z2->DrawNormalized("same");
//z1->DrawNormalized("same");
z1->Add(z2);
z1->DrawNormalized("same");
 
TLegend *leg8 = new TLegend(0.6,0.6,0.9,0.9);
   leg8->SetHeader("dphi between bH1 and all jets"); 
//   leg8->AddEntry(z1,"bH1 - b_t","f");
//   leg8->AddEntry(z2,"bH1 - b_tb","f");
//   leg8->AddEntry(z3,"bH1 - bH2","f");

leg8->AddEntry(z3,"correct","f");
leg8->AddEntry(z1,"wrong","f");

leg8->Draw("same");
c8->SaveAs("dphi_bH1_jets_added.png");


//


TCanvas *c9 = new TCanvas("c9","dr3");
c9->cd();

q3->DrawNormalized();
//q2->DrawNormalized("same");
//q1->DrawNormalized("same");
q1->Add(q2);
q1->DrawNormalized("same");
 
TLegend *leg9 = new TLegend(0.6,0.6,0.9,0.9);
   leg9->SetHeader("dR between bH1 and all jets"); 
//   leg9->AddEntry(q1,"bH1 - b_t","f");
//   leg9->AddEntry(q2,"bH1 - b_tb","f");
//   leg9->AddEntry(q3,"bH1 - bH2","f");

leg9->AddEntry(q3,"correct","f");
leg9->AddEntry(q1,"wrong","f");

leg9->Draw("same");
c9->SaveAs("dR_bH1_jets_added.png");


//


TCanvas *c10 = new TCanvas("c10","eta4");
c10->cd();

//s11->DrawNormalized();
//s21->DrawNormalized("same");
s3->DrawNormalized();
s11->Add(s21);
s11->DrawNormalized("same");

 
TLegend *leg10 = new TLegend(0.6,0.6,0.9,0.9);
   leg10->SetHeader("deta between bH2 and all jets"); 
//   leg10->AddEntry(s11,"bH2 - b_t","f");
//   leg10->AddEntry(s21,"bH2 - b_tb","f");
//   leg10->AddEntry(s3,"bH1 - bH2","f");

leg10->AddEntry(s3,"correct","f");
leg10->AddEntry(s11,"wrong","f");
 
leg10->Draw("same");
c10->SaveAs("deta_bH2_jets_added.png");


//


TCanvas *c11 = new TCanvas("c11","phi4");
c11->cd();

z3->DrawNormalized();
//z11->DrawNormalized("same");
//z21->DrawNormalized("same");
z11->Add(z21);
z11->DrawNormalized("same");

TLegend *leg11 = new TLegend(0.6,0.6,0.9,0.9);
   leg11->SetHeader("dphi between bH1 and all jets"); 
//   leg11->AddEntry(z11,"bH2 - b_t","f");
//   leg11->AddEntry(z21,"bH2 - b_tb","f");
//   leg11->AddEntry(z3,"bH2 - bH1","f");

leg11->AddEntry(z3,"correct","f");
leg11->AddEntry(z11,"correct","f");

leg11->Draw("same");
c11->SaveAs("dphi_bH2_jets_added.png");


//


TCanvas *c12 = new TCanvas("c12","phi5");
c12->cd();

q3->DrawNormalized();
//q11->DrawNormalized("same");
//q21->DrawNormalized("same");
q11->Add(q21);
q11->DrawNormalized("same");

TLegend *leg12 = new TLegend(0.6,0.6,0.9,0.9);
   leg12->SetHeader("dR between bH2 and all jets"); 
//   leg12->AddEntry(q11,"bH1 - b_t","f");
//   leg12->AddEntry(q21,"bH1 - b_tb","f");
//   leg12->AddEntry(q3,"bH1 - bH2","f");

leg12->AddEntry(q3,"correct","f");
leg12->AddEntry(q11,"wrong","f");

leg12->Draw("same");
c12->SaveAs("dR_bH2_jets_added.png");


//


TCanvas *c13 = new TCanvas("c13","Energy of tt");
c13->cd();

e1->DrawNormalized();
e2->DrawNormalized("same");

TLegend *leg13 = new TLegend(0.6,0.6,0.9,0.9);
   leg13->SetHeader("Energy of tt system"); 
   leg13->AddEntry(e1,"E_tt correct","f");
   leg13->AddEntry(e2,"E_tt wrong","f");

leg13->Draw("same");
c13->SaveAs("E_tt.png");


//


TCanvas *c14 = new TCanvas("c14","Energy of ttH");
c14->cd();

e3->DrawNormalized();
e4->DrawNormalized("same");

TLegend *leg14 = new TLegend(0.6,0.6,0.9,0.9);
   leg14->SetHeader("Energy of ttH system"); 
   leg14->AddEntry(e3,"E_ttH correct","f");
   leg14->AddEntry(e4,"E_ttH wrong","f");

leg14->Draw("same");
c14->SaveAs("E_ttH.png");


//


TCanvas *c15 = new TCanvas("c15","Mass of tt");
c15->cd();

m1->DrawNormalized();
m2->DrawNormalized("same");

TLegend *leg15 = new TLegend(0.6,0.6,0.9,0.9);
   leg15->SetHeader("Energy of tt system"); 
   leg15->AddEntry(m1,"m_tt correct","f");
   leg15->AddEntry(m2,"m_tt wrong","f");

leg15->Draw("same");
c15->SaveAs("m_tt.png");


//


TCanvas *c16 = new TCanvas("c16","Mass of ttH");
c16->cd();

m3->DrawNormalized();
m4->DrawNormalized("same");

TLegend *leg16 = new TLegend(0.6,0.6,0.9,0.9);
   leg16->SetHeader("Mass of ttH system"); 
   leg16->AddEntry(m3,"m_ttH correct","f");
   leg16->AddEntry(m4,"m_ttH wrong","f");

leg16->Draw("same");
c16->SaveAs("m_ttH.png");


//


TCanvas *c17 = new TCanvas("c17","pt asymmetry of two Higgs jets");
c17->cd();

i2->DrawNormalized();
i1->DrawNormalized("same");

TLegend *leg17 = new TLegend(0.6,0.6,0.9,0.9);
   leg17->SetHeader("p_t asymmetry of two Higgs jets"); 
   leg17->AddEntry(i1,"p_t asymm correct","f");
   leg17->AddEntry(i2,"p_t asymm wrong","f");

leg17->Draw("same");
c17->SaveAs("pt_asymmetry.png");


//


TCanvas *c18 = new TCanvas("c18","pt of two Higgs jets");
c18->cd();

v1->Draw("Colz");

c18->SaveAs("pt1vspt2_correct.png");

//


TCanvas *c19 = new TCanvas("c19","p_t of two Higgs jets");
c19->cd();

v2->Draw("Colz");

c19->SaveAs("pt1vspt2_wrong.png");

//


TCanvas *c20 = new TCanvas("c20","p_t of correct top-topb");
c20->cd();

v3->Draw("Colz");

c20->SaveAs("pt_topvspttopb_correct.png");


//


TCanvas *c21 = new TCanvas("c21","p_t of wrong top-topb");
c21->cd();

v4->Draw("Colz");

c21->SaveAs("pttopvspttopb_wrong.png");


//


TCanvas *c22 = new TCanvas("c22","pt ratio of two Higgs jets");
c22->cd();

i4->DrawNormalized();
i3->DrawNormalized("same");

TLegend *leg22 = new TLegend(0.6,0.6,0.9,0.9);
   leg22->SetHeader("p_t ratio of two Higgs jets"); 
   leg22->AddEntry(i3,"p_t ratio correct","f");
   leg22->AddEntry(i4,"p_t ratio wrong","f");

leg22->Draw("same");
c22->SaveAs("ptHiggs_ratio.png");

//


TCanvas *c23 = new TCanvas("c23","#slashed{E}_{x}");
c23->cd();

i5->DrawNormalized();
i6->DrawNormalized("same");

TLegend *leg23 = new TLegend(0.6,0.6,0.9,0.9);
   leg23->SetHeader("#slash{E}_{x}"); 
   leg23->AddEntry(i5,"CORRECT","f");
   leg23->AddEntry(i6,"WRONG","f");

leg23->Draw("same");
c23->SaveAs("Metx.png");

//


TCanvas *c24 = new TCanvas("c24","#slashed{E}_{y}");
c24->cd();

i7->DrawNormalized();
i8->DrawNormalized("same");

TLegend *leg24 = new TLegend(0.6,0.6,0.9,0.9);
   leg24->SetHeader("#slash{E}_{y}"); 
   leg24->AddEntry(i7,"CORRECT","f");
   leg24->AddEntry(i8,"WRONG","f");

leg24->Draw("same");
c24->SaveAs("Mety.png");


//


TCanvas *c25 = new TCanvas("c25","p_{#nu_{x}}");
c25->cd();

i9->DrawNormalized();
i10->DrawNormalized("same");

TLegend *leg25 = new TLegend(0.6,0.6,0.9,0.9);
   leg25->SetHeader("p_{#nu_{x}}"); 
   leg25->AddEntry(i9,"CORRECT","f");
   leg25->AddEntry(i10,"WRONG","f");

leg25->Draw("same");
c25->SaveAs("pnux.png");

//


TCanvas *c26 = new TCanvas("c26","p_{#nu_{y}}");
c26->cd();

i11->DrawNormalized();
i12->DrawNormalized("same");

TLegend *leg26 = new TLegend(0.6,0.6,0.9,0.9);
   leg26->SetHeader("p_{#nu_{y}}"); 
   leg26->AddEntry(i11,"CORRECT","f");
   leg26->AddEntry(i12,"WRONG","f");

leg26->Draw("same");
c26->SaveAs("pnuy.png");


//


TCanvas *c27 = new TCanvas("c27","p_{#bar{#n}u_{x}}");
c27->cd();

i13->DrawNormalized();
i14->DrawNormalized("same");

TLegend *leg27 = new TLegend(0.6,0.6,0.9,0.9);
   leg27->SetHeader("p_{#bar{#nu}_{x}}"); 
   leg27->AddEntry(i13,"CORRECT","f");
   leg27->AddEntry(i14,"WRONG","f");

leg27->Draw("same");
c27->SaveAs("pnubx.png");

//


TCanvas *c28 = new TCanvas("c28","p_{#bar{#nu}_{y}}");
c28->cd();

i15->DrawNormalized();
i16->DrawNormalized("same");

TLegend *leg28 = new TLegend(0.6,0.6,0.9,0.9);
   leg28->SetHeader("p_{#bar{#nu}_{y}}"); 
   leg28->AddEntry(i15,"CORRECT","f");
   leg28->AddEntry(i16,"WRONG","f");

leg28->Draw("same");
c28->SaveAs("pnuby.png");

//


TCanvas *c29 = new TCanvas("c29","p_{#nu_{z}}");
c29->cd();

i17->DrawNormalized();
i18->DrawNormalized("same");

TLegend *leg29 = new TLegend(0.6,0.6,0.9,0.9);
   leg29->SetHeader("p_{#nu_{z}}");
   leg29->AddEntry(i17,"CORRECT","f");
   leg29->AddEntry(i18,"WRONG","f");

leg29->Draw("same");
c29->SaveAs("pnuz.png");

//


TCanvas *c30 = new TCanvas("c30","p_{#nu_{z}}");
c30->cd();

i19->DrawNormalized();
i20->DrawNormalized("same");

TLegend *leg30 = new TLegend(0.6,0.6,0.9,0.9);
   leg30->SetHeader("p_{#nu_{z}}");
   leg30->AddEntry(i19,"CORRECT","f");
   leg30->AddEntry(i20,"WRONG","f");

leg30->Draw("same");
c30->SaveAs("pnubz.png");



}
