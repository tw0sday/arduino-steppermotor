// Bsp. zum Steuern eines Steppermotors 28BYJ-48 mit 4096 Schritten/Umdrehung
// Anbindung über Motor-Treiber ULN2003An, Rückmeldung steps, Winkel (HK2022)
// ===========================================================================

// Bibliothek für direkte Schrittmotorsteuerung
#include <CheapStepper.h>

CheapStepper stepper;
// Richtungszuweisung des Motors
boolean moveClockwise = true;	 

void setup()
{
    // Rückmeldung über die serielle Schnittstelle
    Serial.begin(9600); 
    Serial.println("28BYJ-48 bereit."); 
} 

void loop() 
{ 
    // Eine volle Umdrehung beinhaltet 4096 Schritte 
    for (int s=0; s<4096; s++)
    {
        // Ausgabe der akt. Motorposition in der Konsole 
        stepper.step(moveClockwise);
        long nStep = stepper.getStep(); 
        // Variable zum Rechnen
        float arc;                   		 
        // Ausgabe jeden 12. Schritt
        if (nStep%12==0)
        {
            // Winkel berechnen
            arc= (nStep * 90) / 1024;
            Serial.print("current step position: ");
            Serial.print(nStep);
            Serial.print(" arc: ");
            Serial.print(arc);
            Serial.println();
        } 
  } // end for 
    // 1 sek. warten
    delay(1000);
    // Richtungswechsel nach vollständiger Umdrehung
    moveClockwise = !moveClockwise;
} // end loop 