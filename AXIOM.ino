#include <U8x8lib.h>
U8X8_SH1106_128X64_NONAME_HW_I2C u8x8(U8X8_PIN_NONE); // display setup

// Modifiables
char softwareVersion[] = "v220323"; // software version shown on splash screen
byte hysteresis = 10;               // smooths analogue inputs - higher values more smooth but less reactive
byte tempoHysteresis = 3;           // as above but for tempoPot
int minTempo = 20;                  // minimum tempo value
int maxTempo = 241;                 // maximum tempo value (add 1 for pot stability)
byte gateLength = 2;                // length of trigger outputs (ms)

// Microcontroller Pins
const int muxIn = A3;
const byte muxControl1 = 2;
const byte muxControl2 = 3;
const byte muxControl3 = 4;

const byte modeSwitch1 = 7;
const byte modeSwitch2 = 8;
const byte nextStep = 5;
const byte resetSteps = 6;

const byte output1 = 10;
const byte output2 = 11;
const byte output3 = 12;
const byte output4 = 13;

const int tempoPot = A2;
const byte clockSwitch = 1;
const byte outputClock = 9;

// Modes
byte modeState1 = 0;   // Steps side of switch (left)
byte modeState2 = 0;   // Offset side of switch (right)
byte mode = 1;         // 0 = Steps, 1 = Split, 2 = Offset
byte lastMode = 3;
byte modeOffset = 0;   // used to stop rewriting of steps from display after mode change recalculation complete

// Parameters
byte steps1 = 16;
byte steps2 = 16;
byte steps3 = 16;
byte steps4 = 16;
byte hits1 = 1;
byte hits2 = 1;
byte hits3 = 1;
byte hits4 = 1;
byte offset1 = 0;
byte offset2 = 0;
byte offset3 = 0;
byte offset4 = 0;

byte lastSteps1 = 20;
byte lastSteps2 = 20;
byte lastSteps3 = 20;
byte lastSteps4 = 20;
byte lastHits1 = 20;
byte lastHits2 = 20;
byte lastHits3 = 20;
byte lastHits4 = 20;
byte lastOffset1 = 20;
byte lastOffset2 = 20;
byte lastOffset3 = 20;
byte lastOffset4 = 20;

float stepsFloat1 = 0;
float stepsFloat2 = 0;
float stepsFloat3 = 0;
float stepsFloat4 = 0;
float hitsFloat1 = 0;
float hitsFloat2 = 0;
float hitsFloat3 = 0;
float hitsFloat4 = 0;
float offsetFloat1 = 0;
float offsetFloat2 = 0;
float offsetFloat3 = 0;
float offsetFloat4 = 0;

float lastStepsFloat1 = 1200;
float lastStepsFloat2 = 1200;
float lastStepsFloat3 = 1200;
float lastStepsFloat4 = 1200;
float lastHitsFloat1 = 1200;
float lastHitsFloat2 = 1200;
float lastHitsFloat3 = 1200;
float lastHitsFloat4 = 1200;
float lastOffsetFloat1 = 1200;
float lastOffsetFloat2 = 1200;
float lastOffsetFloat3 = 1200;
float lastOffsetFloat4 = 1200;

byte tempoPotCount = 1;
int tempoPot1 = 0;
int tempoPot2 = 0;
int tempoPot3 = 0;
int tempoPot4 = 0;
int tempoPot5 = 0;
int tempoPotValue = 0;
int lastTempoPotValue = 100000;

// Sequences
char seq1[17];
char seq2[17];
char seq3[17];
char seq4[17];
char lastSeq1[17];
char lastSeq2[17];
char lastSeq3[17];
char lastSeq4[17];

// Reset
byte resetStepsValue = 0;
byte lastresetStepsValue = 0;

// Display
byte displayCounter = 0;
char onValue = 42;    // displayed character when a hit is active "*"
char offValue = 45;   // displayed character when a hit is inactive "-"
char endValue = 124;  // end of line character " "

// Clock
int tempo = 120;
int lastTempo = 1;
int tempoMillis = 125;
unsigned long lastClock = 0;
byte clockGate = 0;
byte clockGateActive = 0;

// Sequencer
byte progressSequence = 0;
byte nextStepValue = 1;
byte lastnextStepValue = 1;
byte seqStep1 = 0;
byte seqStep2 = 0;
byte seqStep3 = 0;
byte seqStep4 = 0;
byte gateActive = 0;
unsigned long currentMillis = 0;
unsigned long startMillis = 0;


void setup() {

  pinMode(muxIn, INPUT);
  pinMode(muxControl1, OUTPUT);
  pinMode(muxControl2, OUTPUT);
  pinMode(muxControl3, OUTPUT);
  pinMode(nextStep, INPUT_PULLUP);
  pinMode(resetSteps, INPUT_PULLUP);
  pinMode(modeSwitch1, INPUT_PULLUP);
  pinMode(modeSwitch2, INPUT_PULLUP);
  pinMode(output1, OUTPUT);
  pinMode(output2, OUTPUT);
  pinMode(output3, OUTPUT);
  pinMode(output4, OUTPUT);
  pinMode(tempoPot, INPUT);
  pinMode(clockSwitch, INPUT_PULLUP);
  pinMode(outputClock, OUTPUT);

  // Turn LEDs off
  digitalWrite(output1, HIGH);
  digitalWrite(output2, HIGH);
  digitalWrite(output3, HIGH);
  digitalWrite(output4, HIGH);
  digitalWrite(outputClock, HIGH);

  // Display Setup
  u8x8.begin();
  u8x8.setFont(u8x8_font_pressstart2p_r);

  splashScreen();   // run splash screen process

  // Print Initial Display Values
  u8x8.setCursor(2, 4); u8x8.print("|  |  | Mode:");
  u8x8.setCursor(2, 5); u8x8.print("|  |  | Split");
  u8x8.setCursor(2, 6); u8x8.print("|  |  |");
  u8x8.setCursor(2, 7); u8x8.print("|  |  | 120bpm");

}

void loop() {

  setMode();
  setParameters();
  generateSequences();
  checkReset();
  runClock();
  updateLanes();
  updateParameters();
  runSequence();

}
