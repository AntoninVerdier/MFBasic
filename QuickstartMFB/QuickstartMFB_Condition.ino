/*
  MFB QuickStart - conditions the mouse to k/lever press

  created 9 Feb 2022
  by Antonin Verdier
*/

const int forkPin = A0;
const int pulsePin = 9;
const int goTTL = 3;

const int maxStimNumber = 500;
const int intertrialDuration = 2000;

void setup() {
  Serial.begin(115200);
}

void loop() {

  // Keep track of how many stimulaions the mouse has had
  //Serial.println("Protocol Starting ... \n");
  int totalStim = 0;

  // Main loop
  while (totalStim = < maxStimNumber) {
    //Serial.print("Trial: ");
    //Serial.print(currentTrial);
    //Serial.print(" \n ");

    // DEBUG
    int forkStatus = 0;
    int correct = 0;
    int timeFork = 0;

    unsigned long start_trial = millis();

    // Read input from IR fork only if last stim was more than intertrialDurat ms ago
    if (millis() - start_trial > intertrialDuration) {
      // Check if the fork is pressed
      if (analogRead(forkPin) == 0) {
        timeFork = millis() - start_gotrial;
        // send a pulse
        digitalWrite(pulsePin, HIGH);
        delay(5);
        digitalWrite(pulsePin, LOW);
        start_trial = millis();
      } // fork pressed
    } // end trial window

    Serial.print(totalStim);
    Serial.print(",");

  } // counts stimulations

} // main
