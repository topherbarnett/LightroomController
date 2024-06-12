/* USB MIDI AnalogControlChange Example

   You must select MIDI from the "Tools > USB Type" menu
   http://www.pjrc.com/teensy/td_midi.html

   This example code is in the public domain.
*/

#include <Encoder.h>
#include <Bounce.h>

Encoder Enc1(33, 34);     //Defines encoder pins - (pin A, pin B)
long oldPosition = -999;  // Referance for manual encoder positioning comparisons


int ccNum = 33;         //setup a global variable to assign CC numbers to, based on button presses
const int channel = 1;  // MIDI channel number


// Define variables to store CC values for channels 32 through 74
int cc32, cc33, cc34, cc35, cc36, cc37, cc38, cc39, cc40, cc41, cc42, cc43, cc44, cc45, cc46, cc47, cc48, cc49, cc50, cc51, cc52, cc53, cc54, cc55, cc56, cc57, cc58, cc59, cc60, cc61, cc62, cc63, cc64, cc65, cc66, cc67, cc68, cc69, cc70, cc71, cc72, cc73, cc74;



Bounce button1 = Bounce(1, 10);  //Bounce deals with contact chatter - (pin number, milliseconds to debounce)
Bounce button2 = Bounce(2, 10);
Bounce button3 = Bounce(3, 10);
Bounce button4 = Bounce(4, 10);
Bounce button5 = Bounce(5, 10);
Bounce button6 = Bounce(6, 10);
Bounce button7 = Bounce(7, 10);
Bounce button8 = Bounce(8, 10);
Bounce button9 = Bounce(9, 10);
Bounce button10 = Bounce(10, 10);
Bounce button11 = Bounce(11, 10);
Bounce button12 = Bounce(12, 10);
Bounce button13 = Bounce(13, 10);
Bounce button14 = Bounce(14, 10);
Bounce button15 = Bounce(15, 10);
Bounce button16 = Bounce(16, 10);
Bounce button17 = Bounce(17, 10);
Bounce button18 = Bounce(18, 10);
Bounce button19 = Bounce(19, 10);
Bounce button20 = Bounce(20, 10);
Bounce button21 = Bounce(21, 10);
Bounce button22 = Bounce(22, 10);
Bounce button23 = Bounce(23, 10);
Bounce button24 = Bounce(24, 10);


void setup() {

  Serial.begin(115200);  //Set serial baud rate

  pinMode(1, INPUT_PULLUP);  // Configure the pins for input mode with pullup resistors. Active Low.  (pin number, "INPUT_PULLUP")
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);
  pinMode(17, INPUT_PULLUP);
  pinMode(18, INPUT_PULLUP);
  pinMode(19, INPUT_PULLUP);
  pinMode(20, INPUT_PULLUP);
  pinMode(21, INPUT_PULLUP);
  pinMode(22, INPUT_PULLUP);
  pinMode(23, INPUT_PULLUP);
  pinMode(24, INPUT_PULLUP);
}

// store previously sent values, to detect changes





void loop() {

  // Check if there's any MIDI message
  if (usbMIDI.read()) {
    processMIDI();
  }


  long newPosition = Enc1.read();  // Get the current position of the manual encoder

  if (newPosition / 32 != oldPosition / 32) {

    if (newPosition >= 4064) {  //Make 127 the highest possible encoder value
      newPosition = 4064;
      Enc1.write(4064);
    }
    if (newPosition < 1) {  //Make 0 the lowest possible encoder value
      newPosition = 0;
      Enc1.write(0);
    }

    if (newPosition != oldPosition) {
      Serial.println();
      Serial.print("CC");  //send the value to IDE serial monitor
      Serial.print(ccNum);
      Serial.print(", ");
      Serial.print(newPosition / 32);
      usbMIDI.sendControlChange(ccNum, newPosition / 32, channel);  //Send MIDI CC (CC#, value, channel)
    }

    oldPosition = newPosition;
  }


  button1.update();  // Update all the buttons.
  button2.update();
  button3.update();
  button4.update();
  button5.update();
  button6.update();
  button7.update();
  button8.update();
  button9.update();
  button10.update();
  button11.update();
  button12.update();
  button13.update();
  button14.update();
  button15.update();
  button16.update();
  button17.update();
  button18.update();
  button19.update();
  button20.update();
  button21.update();
  button22.update();
  button23.update();
  button24.update();


  if (button24.fallingEdge()) {
    Serial.println("Mode 1");
  }
  if (button24.risingEdge()) {
    Serial.println("Mode 2");
  }

  //Change functions of buttons depending on latching button (button 24) position
  if (digitalRead(24) == HIGH) {


    //Set CC value for encoder based on button presses
    if (button2.fallingEdge()) {
      ccNum = 33;
      Serial.println("CC33");
      newPosition = cc33 * 32;
      Enc1.write(cc33 * 32);
    }
    if (button3.fallingEdge()) {
      ccNum = 34;
      Serial.println("CC34");
      newPosition = cc34 * 32;
      Enc1.write(cc34 * 32);
    }
    if (button4.fallingEdge()) {
      ccNum = 35;
      Serial.println("CC35");
      newPosition = cc35 * 32;
      Enc1.write(cc35 * 32);
    }
    if (button5.fallingEdge()) {
      ccNum = 36;
      Serial.println("CC36");
      newPosition = cc36 * 32;
      Enc1.write(cc36 * 32);
    }
    if (button6.fallingEdge()) {
      ccNum = 37;
      Serial.println("CC37");
      newPosition = cc37 * 32;
      Enc1.write(cc37 * 32);
    }
    if (button7.fallingEdge()) {
      usbMIDI.sendNoteOn(38, 99, channel);
      Serial.println("Note 38");
    }
    if (button8.fallingEdge()) {
      ccNum = 39;
      Serial.println("CC39");
      newPosition = cc39 * 32;
      Enc1.write(cc39 * 32);
    }
    if (button9.fallingEdge()) {
      ccNum = 40;
      Serial.println("CC40");
      newPosition = cc40 * 32;
      Enc1.write(cc40 * 32);
    }
    if (button10.fallingEdge()) {
      ccNum = 41;
      Serial.println("CC41");
      newPosition = cc41 * 32;
      Enc1.write(cc41 * 32);
    }
    if (button11.fallingEdge()) {
      ccNum = 42;
      Serial.println("CC42");
      newPosition = cc42 * 32;
      Enc1.write(cc42 * 32);
    }
    if (button12.fallingEdge()) {
      ccNum = 43;
      Serial.println("CC43");
      newPosition = cc43 * 32;
      Enc1.write(cc43 * 32);
    }
    if (button13.fallingEdge()) {
      ccNum = 44;
      Serial.println("CC44");
      newPosition = cc44 * 32;
      Enc1.write(cc44 * 32);
    }
    if (button16.fallingEdge()) {
      ccNum = 47;
      Serial.println("CC47");
      newPosition = cc47 * 32;
      Enc1.write(cc47 * 32);
    }
    if (button17.fallingEdge()) {
      ccNum = 48;
      Serial.println("CC48");
      newPosition = cc48 * 32;
      Enc1.write(cc48 * 32);
    }
    if (button18.fallingEdge()) {
      ccNum = 49;
      Serial.println("CC49");
      newPosition = cc49 * 32;
      Enc1.write(cc49 * 32);
    }
    if (button19.fallingEdge()) {
      ccNum = 50;
      Serial.println("CC50");
      newPosition = cc50 * 32;
      Enc1.write(cc50 * 32);
    }
    if (button20.fallingEdge()) {
      ccNum = 51;
      Serial.println("CC51");
      newPosition = cc51 * 32;
      Enc1.write(cc51 * 32);
    }
    if (button21.fallingEdge()) {
      usbMIDI.sendNoteOn(52, 99, channel);
      Serial.println("Note 52");
    }
    if (button22.fallingEdge()) {
      usbMIDI.sendNoteOn(53, 99, channel);
      Serial.println("Note 53");
    }
    if (button23.fallingEdge()) {
      usbMIDI.sendNoteOn(54, 99, channel);
      Serial.println("Note 54");
    }

    
  } else {


    if (button2.fallingEdge()) {
      usbMIDI.sendNoteOn(55, 99, channel);
      Serial.println("Note 55");
    }
    if (button3.fallingEdge()) {
      usbMIDI.sendNoteOn(56, 99, channel);
      Serial.println("Note 56");
    }
    if (button4.fallingEdge()) {
      usbMIDI.sendNoteOn(57, 99, channel);
      Serial.println("Note 57");
    }
    if (button5.fallingEdge()) {
      usbMIDI.sendNoteOn(58, 99, channel);
      Serial.println("Note 58");
    }
    if (button6.fallingEdge()) {
      usbMIDI.sendNoteOn(59, 99, channel);
      Serial.println("Note 59");
    }
    if (button7.fallingEdge()) {
      usbMIDI.sendNoteOn(60, 99, channel);
      Serial.println("Note 60");
    }
    if (button8.fallingEdge()) {
      ccNum = 61;
      Serial.println("CC61");
    }
    if (button9.fallingEdge()) {
      ccNum = 62;
      Serial.println("CC62");
    }
    if (button10.fallingEdge()) {
      ccNum = 63;
      Serial.println("CC63");
    }
    if (button11.fallingEdge()) {
      ccNum = 64;
      Serial.println("CC64");
    }
    if (button12.fallingEdge()) {
      ccNum = 65;
      Serial.println("CC65");
    }
    if (button13.fallingEdge()) {
      usbMIDI.sendNoteOn(66, 99, channel);
      Serial.println("Note 66");
    }
    if (button16.fallingEdge()) {
      ccNum = 47;
      Serial.println("CC47");
    }
    if (button17.fallingEdge()) {
      ccNum = 48;
      Serial.println("CC48");
    }
    if (button18.fallingEdge()) {
      ccNum = 49;
      Serial.println("CC49");
    }
    if (button19.fallingEdge()) {
      ccNum = 50;
      Serial.println("CC50");
    }
    if (button20.fallingEdge()) {
      ccNum = 51;
      Serial.println("CC51");
    }
    if (button21.fallingEdge()) {
      ccNum = 72;
      Serial.println("CC72");
    }
    if (button22.fallingEdge()) {
      ccNum = 73;
      Serial.println("CC73");
    }
    if (button22.fallingEdge()) {
      ccNum = 74;
      Serial.println("CC74");
    }
  }





  //Button Press to send MIDI note:
  if (button1.fallingEdge()) {
    usbMIDI.sendNoteOn(32, 99, channel);  // (note, velocity)
    Serial.println("Note 32");
  }
  if (button14.fallingEdge()) {
    usbMIDI.sendNoteOn(45, 99, channel);
    Serial.println("Note 45");
  }
  if (button15.fallingEdge()) {
    usbMIDI.sendNoteOn(46, 99, channel);
    Serial.println("Note 46");
  }
}



//Reading the MIDI back from the PC
void processMIDI(void) {
  byte type, data1, data2;

  // fetch the MIDI message
  type = usbMIDI.getType();    // which MIDI message, 128-255
  data1 = usbMIDI.getData1();  // first data byte of message, 0-127
  data2 = usbMIDI.getData2();  // second data byte of message, 0-127

  // Check if the message is a Control Change message (type 0xB0)
  if (type == usbMIDI.ControlChange) {
    // Check if the CC number is within the range we are interested in (channels 32-74)
    if (data1 >= 32 && data1 <= 74) {
      // Store the value in the corresponding variable
      switch (data1) {
        case 32: cc32 = data2; break;
        case 33: cc33 = data2; break;
        case 34: cc34 = data2; break;
        case 35: cc35 = data2; break;
        case 36: cc36 = data2; break;
        case 37: cc37 = data2; break;
        case 38: cc38 = data2; break;
        case 39: cc39 = data2; break;
        case 40: cc40 = data2; break;
        case 41: cc41 = data2; break;
        case 42: cc42 = data2; break;
        case 43: cc43 = data2; break;
        case 44: cc44 = data2; break;
        case 45: cc45 = data2; break;
        case 46: cc46 = data2; break;
        case 47: cc47 = data2; break;
        case 48: cc48 = data2; break;
        case 49: cc49 = data2; break;
        case 50: cc50 = data2; break;
        case 51: cc51 = data2; break;
        case 52: cc52 = data2; break;
        case 53: cc53 = data2; break;
        case 54: cc54 = data2; break;
        case 55: cc55 = data2; break;
        case 56: cc56 = data2; break;
        case 57: cc57 = data2; break;
        case 58: cc58 = data2; break;
        case 59: cc59 = data2; break;
        case 60: cc60 = data2; break;
        case 61: cc61 = data2; break;
        case 62: cc62 = data2; break;
        case 63: cc63 = data2; break;
        case 64: cc64 = data2; break;
        case 65: cc65 = data2; break;
        case 66: cc66 = data2; break;
        case 67: cc67 = data2; break;
        case 68: cc68 = data2; break;
        case 69: cc69 = data2; break;
        case 70: cc70 = data2; break;
        case 71: cc71 = data2; break;
        case 72: cc72 = data2; break;
        case 73: cc73 = data2; break;
        case 74: cc74 = data2; break;
      }
      Serial.print("CC");
      Serial.print(data1);
      Serial.print(" value: ");
      Serial.println(data2);
    }
  } else {
    Serial.println("Oops, an unknown MIDI message type!");
  }
}
