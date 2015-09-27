#ifndef SMDMCalibration_h
#define SMDMCalibration_h

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <TROOT.h>
#include <map>

typedef struct parList {
  float p11; float p12; float p13;
  float p21; float p22; float p23;
  float p31; float p32; float p33;
  float p41; float p42; float p43;
  float dist; float tht; float angw;
  float a1; float a2; float a3;
  float b1; float b2; float b3;
  float c1; float c2; float c3;
  int fpw;
} parList;

typedef struct parList1 {
  Float_t det[3][4][2];
} parList1;

class SMDMCalibration {

public:
  static void Init();

  static parList paramList;
  static parList1 paramList1;
};

#endif

