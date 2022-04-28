void generateSequences() {

  // Sequence 1
  for (int logicStep = 1; logicStep <= steps1; logicStep++) {    // repeats the same process for each step in the sequence
    int logicRemainder = (logicStep + offset1) * hits1 % steps1; // algorithm to determine which steps should be hits
    int logicStepValue = offValue;                               // overwrites previous value with offValue character
    if (logicRemainder < hits1) {
      logicStepValue = onValue;                                  // replaces this with onValue character if appropriate
    }
    int logicPosition = steps1 - logicStep;                      // progresses this process to the next step
    seq1[logicPosition] = logicStepValue;                        // writes results into sequence array
  }

  // Sequence 2
  for (int logicStep = 1; logicStep <= steps2; logicStep++) {
    int logicRemainder = (logicStep + offset2) * hits2 % steps2;
    int logicStepValue = offValue;
    if (logicRemainder < hits2) {
      logicStepValue = onValue;
    }
    int logicPosition = steps2 - logicStep;
    seq2[logicPosition] = logicStepValue;
  }

  // Sequence 3
  for (int logicStep = 1; logicStep <= steps3; logicStep++) {
    int logicRemainder = (logicStep + offset3) * hits3 % steps3;
    int logicStepValue = offValue;
    if (logicRemainder < hits3) {
      logicStepValue = onValue;
    }
    int logicPosition = steps3 - logicStep;
    seq3[logicPosition] = logicStepValue;
  }

  // Sequence 4
  for (int logicStep = 1; logicStep <= steps4; logicStep++) {
    int logicRemainder = (logicStep + offset4) * hits4 % steps4;
    int logicStepValue = offValue;
    if (logicRemainder < hits4) {
      logicStepValue = onValue;
    }
    int logicPosition = steps4 - logicStep;
    seq4[logicPosition] = logicStepValue;
  }

  // Display endValue after last step
  seq1[steps1] = endValue;
  seq2[steps2] = endValue;
  seq3[steps3] = endValue;
  seq4[steps4] = endValue;

  // Display blanks after endValue symbols
  for (int logicPosition = (steps1 + 1); logicPosition < 16; logicPosition++) {
    seq1[logicPosition] = 0;
  }
  for (int logicPosition = (steps2 + 1); logicPosition < 16; logicPosition++) {
    seq2[logicPosition] = 0;
  }
  for (int logicPosition = (steps3 + 1); logicPosition < 16; logicPosition++) {
    seq3[logicPosition] = 0;
  }
  for (int logicPosition = (steps4 + 1); logicPosition < 16; logicPosition++) {
    seq4[logicPosition] = 0;
  }

}
