


## **Scrapcode Modular - AXIOM**

https://www.scrapcode.co.uk

This code is designed to be uploaded to an ATMEGA328PU microcontroller using the Arduino IDE.
An AXIOM module can be created by installing this into a circuit built using the included schematic.

This code makes use of the U8G2 library by olikraus for control of the LED display.  This can be installed using the library manger in Arduino IDE, and is also available here:
https://github.com/olikraus/u8g2

For more information please feel free to get in touch at info@scrapcode.co.uk


## **About AXIOM:**

*“Axiom (n) – a statement or proposition on which an abstractly defined structure is based”*

This module generates and outputs rhythms created using three such statements:

***Hits*** -  The number of notes to be played in each round of the sequence. Hits are as evenly spaced as possible, with longer gaps tending towards the end of each sequence.

***Steps*** - The number of Steps defines the length of each sequence.

***Offset*** - The starting position from which each sequence begins, with any overspill wrapped around to the beginning.

These three parameters can be controlled using both the knobs and CV inputs.
Four independent sequences are available, with each controlled, displayed and outputted as a separate lane.


AXIOM is a Eurorack module based on the popular concept of the Euclidean Rhythm, where a defined number of ***Hits*** is evenly distributed throughout a sequence.
It allows two CV inputs for each if its four lanes – one for the number of ***Hits*** in each lane, and a second for either the number of ***Steps*** in each sequence or for an ***Offset*** to its starting position.
Each sequence can be assigned a different length, causing the rhythms in each lane to move in and out of phase with one another. A pattern of up to 21,840 steps is possible before repeating if the right settings are chosen!
An internal clock or external CV trigger can be used to progress the sequencer.

AXIOM is available as either a DIY Kit or as a fully assembled product.
