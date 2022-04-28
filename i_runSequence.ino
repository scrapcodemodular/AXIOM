void runSequence() {

  nextStepValue = digitalRead(nextStep);

  if (nextStepValue == 0 && lastnextStepValue == 1) { //  progresses sequence if external clock trigger present, with debounce
    progressSequence = 1;
    lastnextStepValue = 0;
  }

  if (progressSequence == 1) {  // progressSequence can be triggered either by the nestStep input or by the clock as part of runClock

    // Activate Output Triggers and Light LEDs
    if (seq1[seqStep1] == onValue) {
      digitalWrite(output1, LOW);
    }
    if (seq2[seqStep2] == onValue) {
      digitalWrite(output2, LOW);
    }
    if (seq3[seqStep3] == onValue) {
      digitalWrite(output3, LOW);
    }
    if (seq4[seqStep4] == onValue) {
      digitalWrite(output4, LOW);
    }

    // Current Step Check
    /* if current position is beyond the end of the sequence (most likely due to a reduction in sequence length),
       this will force the last step to be highlighted in the next stage, instead of erroneously highlighting an
       empty step beyond the end of the sequence.
    */
    if (seqStep1 >= steps1) {
      seqStep1 = steps1 - 1;
    }
    if (seqStep2 >= steps2) {
      seqStep2 = steps2 - 1;
    }
    if (seqStep3 >= steps3) {
      seqStep3 = steps3 - 1;
    }
    if (seqStep4 >= steps4) {
      seqStep4 = steps4 - 1;
    }

    // Highlight Currently Active Step
    u8x8.setInverseFont(1);
    u8x8.setCursor(seqStep1, 0);
    u8x8.print(seq1[seqStep1]);
    u8x8.setCursor(seqStep2, 1);
    u8x8.print(seq2[seqStep2]);
    u8x8.setCursor(seqStep3, 2);
    u8x8.print(seq3[seqStep3]);
    u8x8.setCursor(seqStep4, 3);
    u8x8.print(seq4[seqStep4]);
    u8x8.setInverseFont(0);

    // Claculate Previously Highlighted Steps
    int seqStep1x = seqStep1 - 1;
    if (seqStep1x < 0) {
      seqStep1x = (steps1 - 1);
    }
    int seqStep2x = seqStep2 - 1;
    if (seqStep2x < 0) {
      seqStep2x = (steps2 - 1);
    }
    int seqStep3x = seqStep3 - 1;
    if (seqStep3x < 0) {
      seqStep3x = (steps3 - 1);
    }
    int seqStep4x = seqStep4 - 1;
    if (seqStep4x < 0) {
      seqStep4x = (steps4 - 1);
    }

    // Unhighlight Appropriate Steps
    if (steps1 != 1) {
      u8x8.setCursor(seqStep1x, 0);
      u8x8.print(seq1[seqStep1x]);
    }
    if (steps2 != 1) {
      u8x8.setCursor(seqStep2x, 1);
      u8x8.print(seq2[seqStep2x]);
    }
    if (steps3 != 1) {
      u8x8.setCursor(seqStep3x, 2);
      u8x8.print(seq3[seqStep3x]);
    }
    if (steps4 != 1) {
      u8x8.setCursor(seqStep4x, 3);
      u8x8.print(seq4[seqStep4x]);
    }

    // Progress Sequence Positions
    seqStep1++;
    if (seqStep1 >= steps1) { // return to start if end of sequence reached
      seqStep1 = 0;
    }
    seqStep2++;
    if (seqStep2 >= steps2) {
      seqStep2 = 0;
    }
    seqStep3++;
    if (seqStep3 >= steps3) {
      seqStep3 = 0;
    }
    seqStep4++;
    if (seqStep4 >= steps4) {
      seqStep4 = 0;
    }

    gateActive = 1;
    startMillis = millis(); // store start of step time
    progressSequence = 0;
  }

  if (nextStepValue == 1) { // part of debounce
    lastnextStepValue = 1;
  }

  // Turn Off Triggers and LEDs After gateLength
  if (gateActive == 1) {
    if (currentMillis > startMillis + gateLength) {
      digitalWrite(output1, HIGH);
      digitalWrite(output2, HIGH);
      digitalWrite(output3, HIGH);
      digitalWrite(output4, HIGH);
      gateActive = 0;
    }
  }

}
