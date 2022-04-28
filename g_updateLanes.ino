void updateLanes() {

  for (int logicPosition = 0; logicPosition < 16; logicPosition++) { // run process for each step

    // Sequence 1
    if (seq1[logicPosition] != lastSeq1[logicPosition]) { // if something has changed, reprint lane
      u8x8.setCursor(logicPosition, 0);
      u8x8.print(seq1[logicPosition]);
      lastSeq1[logicPosition] = seq1[logicPosition];
    }

    // Sequence 2
    if (seq2[logicPosition] != lastSeq2[logicPosition]) {
      u8x8.setCursor(logicPosition, 1);
      u8x8.print(seq2[logicPosition]);
      lastSeq2[logicPosition] = seq2[logicPosition];
    }

    // Sequence 3
    if (seq3[logicPosition] != lastSeq3[logicPosition]) {
      u8x8.setCursor(logicPosition, 2);
      u8x8.print(seq3[logicPosition]);
      lastSeq3[logicPosition] = seq3[logicPosition];
    }

    // Sequence 4
    if (seq4[logicPosition] != lastSeq4[logicPosition]) {
      u8x8.setCursor(logicPosition, 3);
      u8x8.print(seq4[logicPosition]);
      lastSeq4[logicPosition] = seq4[logicPosition];
    }
  }

}
