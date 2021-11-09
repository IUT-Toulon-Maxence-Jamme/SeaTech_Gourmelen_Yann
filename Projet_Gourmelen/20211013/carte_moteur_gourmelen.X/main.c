#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "ChipConfig.h"
#include "IO.h"
#include "timer.h"
#include "PWM.h"
#include "adc.h"

int main (void){
/***************************************************************************************************/
//Initialisation de l?oscillateur
/****************************************************************************************************/
InitOscillator();

/****************************************************************************************************/
// Configuration des entrées sorties
/****************************************************************************************************/
InitIO();



InitPWM();

PWMSetSpeedConsigne(40,MOTEUR_GAUCHE);
PWMSetSpeedConsigne(40,MOTEUR_DROIT);

InitTimer1();
InitTimer23();

LED_BLANCHE = 1;
LED_BLEUE = 1;
LED_ORANGE = 1;

/****************************************************************************************************/
// Boucle Principale
/****************************************************************************************************/
while(1){
//    LED_BLANCHE=!LED_BLANCHE;
//    LED_BLEUE=!LED_BLEUE;
//    LED_ORANGE=!LED_ORANGE;

   if  (ADCConversionFinishedFlag==1){
       
       ADCClearConversionFinishedFlag();
       unsigned int * result = ADCGetResult();
       ADCValue0=result[0];
       ADCValue1=result[1];
       ADCValue2=result[2];
       
   }
} // fin main
}