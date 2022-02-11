/* 
  MFB QuickStart 

  created 9 Feb 2022
  by Antonin Verdier
 */

const int forkPin = A0;
const int pulsePin = 9;
const int goTTL = 3;
const int nogoTTL = 4;

const int trialDuration = 3000;
const int maxTrialNumber = 320;
const int intertrialDuration = 3000;

void setup() {
  Serial.begin(9600); 
}

void loop() {

  // Generate trial type array
  int trialTypes[maxTrialNumber];
  for (int i; i < 320; i++){
    trialTypes[i] = random(1, 3); 
  }

  // Keep track of current trial number
  Serial.println("Protocol Starting ... \n");
  int currentTrial = 1;

  // Main loop
  while (currentTrial < maxTrialNumber){
    
    // Maybe switch would be more elegant for trial

    // DEBUG
    int trialType = trialTypes[currentTrial];

    // Apply different behaviours depending on trial type (Go/NoGo)    
    if (trialType == 1){
        Serial.println("Go Trial");

        // Send TTL on GO pin and keep track of trial timing
        digitalWrite(goTTL, HIGH);
        delay(5);
        digitalWrite(goTTL, LOW);

        int start_gotrial = millis();

        // Read input from IR fork during response window
        while (millis() - start_gotrial < trialDuration){
          int forkValue = analogRead(forkPin);
    
          // Check if the fork is pressed
          if (forkValue == 0){
            Serial.println("Lever pressed - HIT");
            // Send stimulus to pulse pal on pulse pin 
            break;
          } // fork pressed
        } // end trial window
      } // end trial type

      else if (trialType == 2){
        Serial.println("NoGo Trial");
  
        // Send TTL on GO pin and keep track of trial timing
        digitalWrite(nogoTTL, HIGH);
        delay(5);
        digitalWrite(nogoTTL, LOW);
        int start_nogotrial = millis();

        // Read input from IR fork during response window
        while (millis() - start_nogotrial < trialDuration){
          int forkValue = analogRead(forkPin);
    
          // Check if the fork is pressed
          if (forkValue == 0){
            Serial.println("Lever pressed - False Alarm");
            delay(5000);
            break;
          } // fork pressed
        } // end trial         
      } // end trial type

     // Reserved inter-trial time
     Serial.println("---Intertrial Time---");
     delay(intertrialDuration);
     currentTrial ++; 
  } // end main trial loop
  while(1);
}
