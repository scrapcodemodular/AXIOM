void runClock() {

  currentMillis = millis(); // captures current time

  if (currentMillis >= (lastClock + tempoMillis)) { // if enough time has passed, progress clock
    clockGate = 1;
    lastClock = currentMillis;
  }

  if (clockGate == 1) {
    digitalWrite(outputClock, LOW); // light clock LED
    clockGate = 0;
    clockGateActive = 1;

    if (digitalRead(clockSwitch) == LOW) {  // if clockSwitch is open, progress sequence
      progressSequence = 1;
    }
  }

  if ((clockGateActive == 1) && (currentMillis >= lastClock + gateLength)) {  // once gateLength has passed, turn off clock LED
    digitalWrite(outputClock, HIGH);
    clockGateActive = 0;
  }

}
