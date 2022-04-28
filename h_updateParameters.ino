void updateParameters() {

  // Update Hits
  if (hits1 != lastHits1) { // checks if value has changed
    u8x8.setCursor(0, 4);
    if (hits1 < 10) {
      u8x8.print(hits1); u8x8.print(" ");  // adds a space at the beginning if value is only one character
    } else {
      u8x8.print(hits1);
    }
    lastHits1 = hits1;
  }

  if (hits2 != lastHits2) {
    u8x8.setCursor(0, 5);
    if (hits2 < 10) {
      u8x8.print(hits2); u8x8.print(" ");
    } else {
      u8x8.print(hits2);
    }
    lastHits2 = hits2;
  }

  if (hits3 != lastHits3) {
    u8x8.setCursor(0, 6);
    if (hits3 < 10) {
      u8x8.print(hits3); u8x8.print(" ");
    } else {
      u8x8.print(hits3);
    }
    lastHits3 = hits3;
  }

  if (hits4 != lastHits4) {
    u8x8.setCursor(0, 7);
    if (hits4 < 10) {
      u8x8.print(hits4); u8x8.print(" ");
    } else {
      u8x8.print(hits4);
    }
    lastHits4 = hits4;
  }

  // Update Steps
  if (steps1 != lastSteps1) {
    u8x8.setCursor(3, 4);
    if (steps1 < 10) {
      u8x8.print(steps1); u8x8.print(" ");
    } else {
      u8x8.print(steps1);
    }
    lastSteps1 = steps1;
  }

  if (mode != 1) { // leaves steps 2-4 blank in split mode
    if (steps2 != lastSteps2) {
      u8x8.setCursor(3, 5);
      if (steps2 < 10) {
        u8x8.print(steps2); u8x8.print(" ");
      } else {
        u8x8.print(steps2);
      }
      lastSteps2 = steps2;
    }

    if (steps3 != lastSteps3) {
      u8x8.setCursor(3, 6);
      if (steps3 < 10) {
        u8x8.print(steps3); u8x8.print(" ");
      } else {
        u8x8.print(steps3);
      }
      lastSteps3 = steps3;
    }

    if (steps4 != lastSteps4) {
      u8x8.setCursor(3, 7);
      if (steps4 < 10) {
        u8x8.print(steps4); u8x8.print(" ");
      } else {
        u8x8.print(steps4);
      }
      lastSteps4 = steps4;
    }

  }

  if (mode == 1) { // removes hysteresis error in split mode
    lastSteps2 = steps2;
    lastSteps3 = steps3;
    lastSteps4 = steps4;
  }

  // Update Offsets
  if (mode != 1) { // leaves offset 1 blank in steps mode
    if (offset1 != lastOffset1) {
      u8x8.setCursor(6, 4);
      if (offset1 < 10) {
        u8x8.print(offset1); u8x8.print(" ");
      } else {
        u8x8.print(offset1);
      }
      lastOffset1 = offset1;
    }
  }

  if (offset2 != lastOffset2) {
    u8x8.setCursor(6, 5);
    if (offset2 < 10) {
      u8x8.print(offset2); u8x8.print(" ");
    } else {
      u8x8.print(offset2);
    }
    lastOffset2 = offset2;
  }

  if (offset3 != lastOffset3) {
    u8x8.setCursor(6, 6);
    if (offset3 < 10) {
      u8x8.print(offset3); u8x8.print(" ");
    } else {
      u8x8.print(offset3);
    }
    lastOffset3 = offset3;
  }

  if (offset4 != lastOffset4) {
    u8x8.setCursor(6, 7);
    if (offset4 < 10) {
      u8x8.print(offset4); u8x8.print(" ");
    } else {
      u8x8.print(offset4);
    }
    lastOffset4 = offset4;
  }

  // Update Tempo
  if (tempo != lastTempo) {
    if (tempo < 100) {
      u8x8.setCursor(10, 7); u8x8.print(" "); u8x8.print(tempo); // adds a space at the beginning if tempo is only two characters
    } else {
      u8x8.setCursor(10, 7); u8x8.print(tempo);
    }
    lastTempo = tempo;
  }

}
