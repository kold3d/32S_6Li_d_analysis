#include "SMDMCalibration.h"
#include <algorithm>

void SMDMCalibration::Init() {


  std::ifstream param("param.in");
  if(param) {
    //printf("Reading param.in...\n");
    float parameterList[25];
    int i = 0;
    while(!param.eof()) {
      std::string line;
      std::getline(param,line);
      if(!param.eof()) {
        std::istringstream stm;
        stm.str(line);
        std::string parameterString;
        float value;
        stm >> parameterString >> value;
        parameterList[i] = value;
        i++;
      }
    }

    paramList.p11 = parameterList[0];
    paramList.p12 = parameterList[1];
    paramList.p13 = parameterList[2];
    paramList.p21 = parameterList[3];
    paramList.p22 = parameterList[4];
    paramList.p23 = parameterList[5];
    paramList.p31 = parameterList[6];
    paramList.p32 = parameterList[7];
    paramList.p33 = parameterList[8];
    paramList.p41 = parameterList[9];
    paramList.p42 = parameterList[10];
    paramList.p43 = parameterList[11];
    paramList.dist = parameterList[12];
    paramList.tht = parameterList[13];
    paramList.fpw = int(parameterList[14]);
    paramList.angw = parameterList[15];
    paramList.a1 = parameterList[16];
    paramList.a2 = parameterList[17];
    paramList.a3 = parameterList[18];
    paramList.b1 = parameterList[19];
    paramList.b2 = parameterList[20];
    paramList.b3 = parameterList[21];
    paramList.c1 = parameterList[22];
    paramList.c2 = parameterList[23];
    paramList.c3 = parameterList[24];

    /*for(int i=0; i<25; i++) {
      printf("%g\n",parameterList[i]);
    }
    printf("Done reading and assigning param.in...\n\n");
    */
  }

  std::ifstream calibs("si_calib.in");
  if(calibs) {
    //printf("Reading si_calib.in...\n");
    Float_t parameterList1[12][2];
    int j=0;
    while(!calibs.eof()) {
      std::string line1;
      std::getline(calibs,line1);
      if(!calibs.eof()) {
	std::istringstream stm1;
	stm1.str(line1);
	Float_t value1, value2;
	stm1 >> value1 >> value2;
	parameterList1[j][0] = value1;
	parameterList1[j][1] = value2;
	j++;
      }
    }

    for (int x=0; x<12; x++) {
    paramList1.det[x][0] = parameterList1[x][0];
    paramList1.det[x][1] = parameterList1[x][1];
    }
    /*
    for(int i=0; i<12; i++) 
      printf("%4.5e\t%4.5e\n",parameterList1[i][0], parameterList1[i][1]);

    printf("Done reading and assigning si_calib.in...\n\n");
    */
  }
}

parList SMDMCalibration::paramList;
parList1 SMDMCalibration::paramList1;
