void setMode() {

  modeState1 = digitalRead(modeSwitch1);
  modeState2 = digitalRead(modeSwitch2);

  if (modeState1 == LOW) {
    mode = 2;                         // Offset Mode - all steps need to be set to 16
  } else if (modeState2 == LOW) {
    mode = 0;                         // Steps Mode - all offsets need to be set to 0
  } else {
    mode = 1;                         // Split Mode - steps 2-4 need to be set to follow steps1, and offest1 = 0
  }

  if (lastMode != mode) {      // checks if mode has changed, and sets parameters as above if it has

    // Steps Mode
    if (mode == 0) {
      lastSteps1 = 20;         // ensures steps are reprinted
      lastSteps2 = 20;
      lastSteps3 = 20;
      lastSteps4 = 20;
      lastStepsFloat1 = 2000;  // ensures setps are recalculated
      lastStepsFloat2 = 2000;
      lastStepsFloat3 = 2000;
      lastStepsFloat4 = 2000;
      u8x8.setCursor(10, 5); u8x8.print("Steps ");
      offset1 = 0;
      offset2 = 0;
      offset3 = 0;
      offset4 = 0;
      lastOffset1 = 0;
      lastOffset2 = 0;
      lastOffset3 = 0;
      lastOffset4 = 0;

      // Blank out offsets
      u8x8.setCursor(6, 4);  u8x8.print("  ");
      u8x8.setCursor(6, 5);  u8x8.print("  ");
      u8x8.setCursor(6, 6);  u8x8.print("  ");
      u8x8.setCursor(6, 7);  u8x8.print("  ");
    }

    // Split Mode
    if (mode == 1) {
      lastOffset2 = 20;        // ensures appropriate steps and offsets are reprinted
      lastOffset3 = 20;
      lastOffset4 = 20;
      lastSteps1 = 20;
      lastSteps2 = 20;
      lastSteps3 = 20;
      lastSteps4 = 20;
      lastOffsetFloat2 = 2000; // ensures appropriate steps and offsets are recalculated
      lastOffsetFloat3 = 2000;
      lastOffsetFloat4 = 2000;
      lastStepsFloat1 = 2000;
      lastStepsFloat2 = 2000;
      lastStepsFloat3 = 2000;
      lastStepsFloat4 = 2000;
      u8x8.setCursor(10, 5); u8x8.print("Split ");
      steps2 = steps1;
      steps3 = steps1;
      steps4 = steps1;
      offset1 = 0;

      // Blank out offset 1 & steps 2-4
      u8x8.setCursor(6, 4);  u8x8.print("  ");
      u8x8.setCursor(3, 5);  u8x8.print("  ");
      u8x8.setCursor(3, 6);  u8x8.print("  ");
      u8x8.setCursor(3, 7);  u8x8.print("  ");
    }

    //Offset Mode
    if (mode == 2) {
      lastOffset1 = 20;        // ensures offsets are reprinted
      lastOffset2 = 20;
      lastOffset3 = 20;
      lastOffset4 = 20;
      lastOffsetFloat1 = 2000; // ensures offsets are recalculated
      lastOffsetFloat2 = 2000;
      lastOffsetFloat3 = 2000;
      lastOffsetFloat4 = 2000;
      u8x8.setCursor(10, 5); u8x8.print("Offset");
      steps1 = 16;
      steps2 = 16;
      steps3 = 16;
      steps4 = 16;
      lastSteps1 = 20;
      lastSteps2 = 20;
      lastSteps3 = 20;
      lastSteps4 = 20;

      modeOffset = 1;
      
      // Blank Out Steps
      u8x8.setCursor(3, 4);  u8x8.print("  ");
      u8x8.setCursor(3, 5);  u8x8.print("  ");
      u8x8.setCursor(3, 6);  u8x8.print("  ");
      u8x8.setCursor(3, 7);  u8x8.print("  ");

    }

    lastMode = mode;
  }

}
