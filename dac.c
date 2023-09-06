#include "dac_h"

void enable_clock1(){
     SIM -> SCGC2 |= SIM_SCGC2_DAC0_MASK;
}
void enable_clock2(){
     SIM -> SCGC2 |= SIM_SCGC2_DAC1_MASK;
}
void enable_vref1(){
    DAC0->C0 = DAC_C0_DACEN_MASK | DAC_C0_DACRFS_MASK;
}
void enable_vref2(){
    DAC1->C0 = DAC_C0_DACEN_MASK | DAC_C0_DACRFS_MASK;
}
void enable_digitalvalue1(){
    DAC0->DAT[0].DATH = DAC_DATH_DATA1(int valor1 >> 8);
    DAC0->DAT[0].DATL = DAC_DATL_DATA0(int valor1 & 0xFF);
}
void enable_digitalvalue2(){
    DAC1->DAT[0].DATH = DAC_DATH_DATA1(int valor2 >> 8);
    DAC1->DAT[0].DATL = DAC_DATL_DATA0(int valor2 & 0xFF);
}
