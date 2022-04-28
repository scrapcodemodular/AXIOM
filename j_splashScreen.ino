void splashScreen() {
  int delayTime = 50;

  // Print "SCRAPCODE MODULAR"
  delay(delayTime * 2);
  u8x8.setCursor(3, 1); u8x8.print("S"); delay(delayTime);
  u8x8.setCursor(4, 1); u8x8.print("C"); delay(delayTime);
  u8x8.setCursor(5, 1); u8x8.print("R"); delay(delayTime);
  u8x8.setCursor(6, 1); u8x8.print("A"); delay(delayTime);
  u8x8.setCursor(7, 1); u8x8.print("P"); delay(delayTime);
  u8x8.setCursor(8, 1); u8x8.print("C"); delay(delayTime);
  u8x8.setCursor(9, 1); u8x8.print("O"); delay(delayTime);
  u8x8.setCursor(10, 1); u8x8.print("D"); delay(delayTime);
  u8x8.setCursor(11, 1); u8x8.print("E"); delay(delayTime);

  u8x8.setCursor(4, 2); u8x8.print("M"); delay(delayTime);
  u8x8.setCursor(5, 2); u8x8.print("O"); delay(delayTime);
  u8x8.setCursor(6, 2); u8x8.print("D"); delay(delayTime);
  u8x8.setCursor(7, 2); u8x8.print("U"); delay(delayTime);
  u8x8.setCursor(8, 2); u8x8.print("L"); delay(delayTime);
  u8x8.setCursor(9, 2); u8x8.print("A"); delay(delayTime);
  u8x8.setCursor(10, 2); u8x8.print("R"); delay(delayTime * 10);

  // Print "AXIOM"
  u8x8.setFont(u8x8_font_profont29_2x3_r);
  u8x8.setCursor(3, 4); u8x8.print("A"); delay(delayTime);
  u8x8.setCursor(5, 4); u8x8.print("X"); delay(delayTime);
  u8x8.setCursor(7, 4); u8x8.print("I"); delay(delayTime);
  u8x8.setCursor(9, 4); u8x8.print("O"); delay(delayTime);
  u8x8.setCursor(11, 4); u8x8.print("M"); delay(delayTime * 20);

  // Print Current Software Version
  u8x8.setFont(u8x8_font_pressstart2p_r);
  u8x8.setCursor(9, 7); u8x8.print(softwareVersion);
  delay(delayTime * 30);
  u8x8.clearDisplay();
  delay(delayTime * 5);

}
