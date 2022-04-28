void setParameters() {

  digitalWrite(muxControl3, HIGH); // digitalWrites set which input is routed through the mux to the analogRead pin

  // Steps Mode
  if (mode == 0) {

    digitalWrite(muxControl1, LOW);   digitalWrite(muxControl2, LOW);
    stepsFloat4 = analogRead(muxIn);
    if (stepsFloat4 - lastStepsFloat4 > hysteresis || stepsFloat4 - lastStepsFloat4 < -hysteresis) {  // check to see if value has changed
      lastStepsFloat4 = stepsFloat4;
      stepsFloat4 = (stepsFloat4 / 1024 * 16 + 1); // scale analogRead value to appropriate range
      steps4 = stepsFloat4;
    }

    digitalWrite(muxControl1, HIGH);
    stepsFloat3 = analogRead(muxIn);
    if (stepsFloat3 - lastStepsFloat3 > hysteresis || stepsFloat3 - lastStepsFloat3 < -hysteresis) {
      lastStepsFloat3 = stepsFloat3;
      stepsFloat3 = (stepsFloat3 / 1024 * 16 + 1);
      steps3 = stepsFloat3;
    }

    digitalWrite(muxControl1, LOW);   digitalWrite(muxControl2, HIGH);
    stepsFloat2 = analogRead(muxIn);
    if (stepsFloat2 - lastStepsFloat2 > hysteresis || stepsFloat2 - lastStepsFloat2 < -hysteresis) {
      lastStepsFloat2 = stepsFloat2;
      stepsFloat2 = (stepsFloat2 / 1024 * 16 + 1);
      steps2 = stepsFloat2;
    }

    digitalWrite(muxControl1, HIGH);
    stepsFloat1 = analogRead(muxIn);
    if (stepsFloat1 - lastStepsFloat1 > hysteresis || stepsFloat1 - lastStepsFloat1 < -hysteresis) {
      lastStepsFloat1 = stepsFloat1;
      stepsFloat1 = (stepsFloat1 / 1024 * 16 + 1);
      steps1 = stepsFloat1;
    }

  }

  // Split Mode
  if (mode == 1) {

    digitalWrite(muxControl1, HIGH);
    stepsFloat1 = analogRead(muxIn);
    if (stepsFloat1 - lastStepsFloat1 > hysteresis || stepsFloat1 - lastStepsFloat1 < -hysteresis) {
      lastStepsFloat1 = stepsFloat1;
      stepsFloat1 = (stepsFloat1 / 1024 * 16 + 1);
      steps1 = stepsFloat1;
      steps2 = stepsFloat1;
      steps3 = stepsFloat1;
      steps4 = stepsFloat1;
    }

    digitalWrite(muxControl1, LOW);   digitalWrite(muxControl2, LOW);
    offsetFloat4 = analogRead(muxIn);
    if (offsetFloat4 - lastOffsetFloat4 > hysteresis || offsetFloat4 - lastOffsetFloat4 < -hysteresis || steps4 != lastSteps4) {
      lastOffsetFloat4 = offsetFloat4;
      offsetFloat4 = (offsetFloat4 / 1024 * (steps4 + 1));
      offset4 = offsetFloat4;
    }

    digitalWrite(muxControl1, HIGH);
    offsetFloat3 = analogRead(muxIn);
    if (offsetFloat3 - lastOffsetFloat3 > hysteresis || offsetFloat3 - lastOffsetFloat3 < -hysteresis || steps3 != lastSteps3) {
      lastOffsetFloat3 = offsetFloat3;
      offsetFloat3 = (offsetFloat3 / 1024 * (steps3 + 1));
      offset3 = offsetFloat3;
    }

    digitalWrite(muxControl1, LOW);   digitalWrite(muxControl2, HIGH);
    offsetFloat2 = analogRead(muxIn);
    if (offsetFloat2 - lastOffsetFloat2 > hysteresis || offsetFloat2 - lastOffsetFloat2 < -hysteresis || steps2 != lastSteps2) {
      lastOffsetFloat2 = offsetFloat2;
      offsetFloat2 = (offsetFloat2 / 1024 * (steps2 + 1));
      offset2 = offsetFloat2;
    }

  }

  // Offset Mode
  if (mode == 2) {

    digitalWrite(muxControl1, LOW);   digitalWrite(muxControl2, LOW);
    offsetFloat4 = analogRead(muxIn);
    if (offsetFloat4 - lastOffsetFloat4 > hysteresis || offsetFloat4 - lastOffsetFloat4 < -hysteresis || steps1 != lastSteps1) {
      lastOffsetFloat4 = offsetFloat4;
      offsetFloat4 = (offsetFloat4 / 1024 * (steps4 + 1));
      offset4 = offsetFloat4;
    }

    digitalWrite(muxControl1, HIGH);
    offsetFloat3 = analogRead(muxIn);
    if (offsetFloat3 - lastOffsetFloat3 > hysteresis || offsetFloat3 - lastOffsetFloat3 < -hysteresis || steps2 != lastSteps2) {
      lastOffsetFloat3 = offsetFloat3;
      offsetFloat3 = (offsetFloat3 / 1024 * (steps3 + 1));
      offset3 = offsetFloat3;
    }

    digitalWrite(muxControl1, LOW);   digitalWrite(muxControl2, HIGH);
    offsetFloat2 = analogRead(muxIn);
    if (offsetFloat2 - lastOffsetFloat2 > hysteresis || offsetFloat2 - lastOffsetFloat2 < -hysteresis || steps3 != lastSteps3) {
      lastOffsetFloat2 = offsetFloat2;
      offsetFloat2 = (offsetFloat2 / 1024 * (steps2 + 1));
      offset2 = offsetFloat2;
    }

    digitalWrite(muxControl1, HIGH);
    offsetFloat1 = analogRead(muxIn);
    if (offsetFloat1 - lastOffsetFloat1 > hysteresis || offsetFloat1 - lastOffsetFloat1 < -hysteresis || steps4 != lastSteps4) {
      lastOffsetFloat1 = offsetFloat1;
      offsetFloat1 = (offsetFloat1 / 1024 * (steps1 + 1));
      offset1 = offsetFloat1;
    }

  }

  // Hits values (all modes)
  digitalWrite(muxControl1, LOW);   digitalWrite(muxControl2, LOW);   digitalWrite(muxControl3, LOW);
  hitsFloat1 = analogRead(muxIn);
  if (hitsFloat1 - lastHitsFloat1 > hysteresis || hitsFloat1 - lastHitsFloat1 < -hysteresis || steps1 != lastSteps1) {
    lastHitsFloat1 = hitsFloat1;
    hitsFloat1 = (hitsFloat1 / 1024 * (steps1 + 1));
    hits1 = hitsFloat1;
  }

  digitalWrite(muxControl1, HIGH);
  hitsFloat2 = analogRead(muxIn);
  if (hitsFloat2 - lastHitsFloat2 > hysteresis || hitsFloat2 - lastHitsFloat2 < -hysteresis || steps2 != lastSteps2) {
    lastHitsFloat2 = hitsFloat2;
    hitsFloat2 = (hitsFloat2 / 1024 * (steps2 + 1));
    hits2 = hitsFloat2;
  }

  digitalWrite(muxControl1, LOW);   digitalWrite(muxControl2, HIGH);
  hitsFloat3 = analogRead(muxIn);
  if (hitsFloat3 - lastHitsFloat3 > hysteresis || hitsFloat3 - lastHitsFloat3 < -hysteresis || steps3 != lastSteps3) {
    lastHitsFloat3 = hitsFloat3;
    hitsFloat3 = (hitsFloat3 / 1024 * (steps3 + 1));
    hits3 = hitsFloat3;
  }

  digitalWrite(muxControl1, HIGH);
  hitsFloat4 = analogRead(muxIn);
  if (hitsFloat4 - lastHitsFloat4 > hysteresis || hitsFloat4 - lastHitsFloat4 < -hysteresis || steps4 != lastSteps4) {
    lastHitsFloat4 = hitsFloat4;
    hitsFloat4 = (hitsFloat4 / 1024 * (steps4 + 1));
    hits4 = hitsFloat4;
  }

  // Set Tempo
  if (tempoPotCount == 1) {
    tempoPot1 = analogRead(tempoPot);
  }
  if (tempoPotCount == 2) {
    tempoPot2 = analogRead(tempoPot);
  }
  if (tempoPotCount == 3) {
    tempoPot3 = analogRead(tempoPot);
  }
  if (tempoPotCount == 4) {
    tempoPot4 = analogRead(tempoPot);
  }
  if (tempoPotCount == 5) {
    tempoPot5 = analogRead(tempoPot);
  }
  tempoPotCount++;
  if (tempoPotCount == 6) {
    tempoPotValue = (tempoPot1 + tempoPot2 + tempoPot3 + tempoPot4 + tempoPot5);
    tempoPotValue = tempoPotValue / 5;
    tempoPotCount = 1;
  }


  if (tempoPotValue - lastTempoPotValue > tempoHysteresis || tempoPotValue - lastTempoPotValue < -tempoHysteresis) {
    lastTempoPotValue = tempoPotValue;
    tempo = map(tempoPotValue, 0, 1023, minTempo, maxTempo);
    if (tempo == maxTempo) {
      tempo = maxTempo - 1;
    }

    tempoMillis = (15000 / tempo);            // turns tempo value into number of ms delay between each step
  }

  // modeOffset reset
  if (modeOffset == 1) {
    lastSteps1 = 16;
    lastSteps2 = 16;
    lastSteps3 = 16;
    lastSteps4 = 16;

    modeOffset = 0;

  }

}
