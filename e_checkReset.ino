void checkReset() {

  resetStepsValue = digitalRead(resetSteps);

  if (resetStepsValue == 0 && lastresetStepsValue == 1) { // checks if reset needs to be performed and debounces

    // Unhighlight previously highlighted steps
    u8x8.setCursor((seqStep1 - 1), 0);
    u8x8.print(seq1[(seqStep1 - 1)]);
    u8x8.setCursor(seqStep2 - 1, 1);
    u8x8.print(seq2[seqStep2 - 1]);
    u8x8.setCursor(seqStep3 - 1, 2);
    u8x8.print(seq3[seqStep3 - 1]);
    u8x8.setCursor(seqStep4 - 1, 3);
    u8x8.print(seq4[seqStep4 - 1]);

    //As above but if the final step was highlighted
    if (seqStep1 == 0) {
      u8x8.setCursor((steps1 - 1), 0);
      u8x8.print(seq1[(steps1 - 1)]);
    }
    if (seqStep2 == 0) {
      u8x8.setCursor((steps2 - 1), 1);
      u8x8.print(seq2[(steps2 - 1)]);
    }
    if (seqStep3 == 0) {
      u8x8.setCursor((steps3 - 1), 2);
      u8x8.print(seq3[(steps3 - 1)]);
    }
    if (seqStep4 == 0) {
      u8x8.setCursor((steps4 - 1), 3);
      u8x8.print(seq4[(steps4 - 1)]);
    }

    // Reset all sequence positions to 0
    seqStep1 = 0;
    seqStep2 = 0;
    seqStep3 = 0;
    seqStep4 = 0;

    lastresetStepsValue = 0;

  }

  if (resetStepsValue == 1) { // part of debouncing process
    lastresetStepsValue = 1;
  }
}
