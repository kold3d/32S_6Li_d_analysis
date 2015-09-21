#include "SMDMCalibration.h"

void SMDMCalibration::Init() {


  std::ifstream param("param.in");
  if(param) {
    printf("Reading param.in...\n");
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

    for(int i=0; i<25; i++) {
      printf("%g\n",parameterList[i]);
    }
    printf("Done reading and assigning param.in...\n\n");
  }

  std::ifstream gates("ang14_gates.in");
  if(gates) {
    printf("Reading ang14_gates.in...\n");
    float parameterList1[10];
    int j=0;
    while(!gates.eof()) {
      std::string line1;
      std::getline(gates,line1);
      if(!gates.eof()) {
	std::istringstream stm1;
	stm1.str(line1);
	float value1, value2;
	stm1 >> value1 >> value2;
	parameterList1[j] = value1;
	parameterList1[j+1] = value2;
	j+=2;
      }
    }
    paramList1.ang_low[4] = parameterList1[0];
    paramList1.ang_high[4] = parameterList1[1];
    paramList1.ang_low[3] = parameterList1[2];
    paramList1.ang_high[3] = parameterList1[3];
    paramList1.ang_low[2] = parameterList1[4];
    paramList1.ang_high[2] = parameterList1[5];
    paramList1.ang_low[1] = parameterList1[6];
    paramList1.ang_high[1] = parameterList1[7];
    paramList1.ang_low[0] = parameterList1[8];
    paramList1.ang_high[0] = parameterList1[9];

    for(int i=0; i<10; i++) 
      printf("%g\n",parameterList1[i]);

    printf("Done reading and assigning ang14_gates.in...\n\n");
  }

}

parList SMDMCalibration::paramList;
parList1 SMDMCalibration::paramList1;
