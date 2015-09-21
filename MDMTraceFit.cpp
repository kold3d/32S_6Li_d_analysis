//
// Created by euberseder on 8/30/15.
//

#include "MDMTraceFit.h"
#include "MDMTrace.h"
#include <math.h>
#include <stdio.h>

MDMTraceFit::MDMTraceFit(int *iterations,
                         double x1, double x2, double x3, double x4) :
        iterations_(iterations), x1_(x1), x2_(x2), x3_(x3), x4_(x4) {
}

double MDMTraceFit::operator()(const std::vector<double>& p) const {
    (*iterations_)++;

    MDMTrace* mdm = MDMTrace::Instance();

    double excitationEnergy = p[0];
    double scatteredAngle = p[1];
   
    //mdm->SetResidualEnergy(excitationEnergy);
    mdm->SetScatteredAngle(scatteredAngle);
    mdm->SetScatteredEnergy(excitationEnergy);


    //mdm->SendRayWithKinematics();
    mdm->SendRay();

    double x1,x2,x3,x4;
    mdm->GetOxfordWirePositions(x1,x2,x3,x4);

    double chi2=0.;
    if(x1_>-1000) chi2 += pow(x1_-x1*10.,2.)/pow(0.1*x1_,2.);
    if(x2_>-1000) chi2 += pow(x2_-x2*10.,2.)/pow(0.1*x2_,2.);
    if(x3_>-1000) chi2 += pow(x3_-x3*10.,2.)/pow(0.1*x3_,2.);
    if(x4_>-1000) chi2 += pow(x4_-x4*10.,2.)/pow(0.1*x4_,2.);

//    printf("%f %f %f %f %f %f %f\n",excitationEnergy,scatteredAngle,
//           x1_,x2_,x3_,x4_,chi2);
    return chi2;
}
