//
// Created by euberseder on 8/30/15.
//

#ifndef MDM_TEST_ANALYSIS_MDMTRACEFIT_H
#define MDM_TEST_ANALYSIS_MDMTRACEFIT_H

#include "Minuit2/FCNBase.h"

class MDMTraceFit : public ROOT::Minuit2::FCNBase {
public:
    MDMTraceFit(int*,double,double,double,double);
    double Up() const {return theErrorDef_;};
    double operator()(const std::vector<double>&) const;
    void SetErrorDef(double def) {theErrorDef_=def;};
private:
    double theErrorDef_;
    int* iterations_;
    double x1_;
    double x2_;
    double x3_;
    double x4_;
};


#endif //MDM_TEST_ANALYSIS_MDMTRACEFIT_H
