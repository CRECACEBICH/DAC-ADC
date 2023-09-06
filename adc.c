#include "ADC.h"

void SaCR1(){
    ADC0->SC1[0] = ADC_SC1_ADCH(C1);
}
void SaCR2(){
    ADC0->SC1[1] = ADC_SC1_ADCH(C2);
}
void Clock(){
    SIM->SCGC6 |= SIM_SCGC6_ADC0_MASK;
}
void CR1(){
    ADC0->CFG1 = ADC_CFG1_MODE(3) | ADC_CFG1_ADICLK(1) | ADC_CFG1_ADIV(0);
}
void calibrar(){
    ADC0->SC3 = ADC_SC3_AVGE_MASK | ADC_SC3_AVGS(3);
}
void SaCR3(){
    while (ADC0->SC3 & ADC_SC3_CAL_MASK);
}
void Leer {
    while (!(ADC0->SC1[0] & ADC_SC1_COCO_MASK));
}
void ReR(){
    return ADC0->R[0];
}
