/*
  SD card read/write


   SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4 (for MKRZero SD: SDCARD_SS_PIN)


*/

#include <SPI.h>
#include <SD.h>

File myFile;
const int pwr = 2;
const int error_led = 3;
const int write_led = 4;
const int read_led = 5;
const int readbutton = 6;
const String title = "log.txt";

void setup() {
  
  pinMode(pwr, OUTPUT);
  pinMode(error_led, OUTPUT);
  pinMode(write_led, OUTPUT);
  pinMode(read_led, OUTPUT);

  
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
  
    ; // wait for serial port to connect. Needed for native USB port only
  }


    Serial.print("Initializing SD card...");

  if (!SD.begin(53)) {
    Serial.println("initialization failed!");
    while (1);
    blink_(error_led);
    
  }
  Serial.println("initialization done.");

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile = SD.open(title, FILE_WRITE);



 

  // re-open the file for reading:
  
}

void loop() {
  no_blink(pwr);
  // nothing happens after setup

   // if the file opened okay, write to it:
  if (myFile) {
    Serial.print("Writing to datalogger");
    myFile.println("This is Kodion Datalogger system,\n This sytem takes the log of every activity on the transformer.....");//data to be written into SD card
    blink_(write_led);
    // close the file:
   // myFile.close();
    //Serial.println("done.");
  } else {
      blink_(error_led);
    // if the file didn't open, print an error:
    Serial.print("error opening");
     Serial.println(title);
  }

   read_logger(6);
}

void blink_(int pin){
  digitalWrite(pin, HIGH);
  delay(200);
   digitalWrite(pin, LOW);
  delay(200);
  }

void no_blink(int pin){
  
  digitalWrite(pin, HIGH);
  }

  void read_logger(int readbutton){
  int  read_ = digitalRead(readbutton);
    if(read_ == HIGH){
       myFile.close();

       myFile = SD.open(title);
  if (myFile) {
    Serial.println(title);

    // read from the file until there's nothing else in it:
    while (myFile.available()) {
       blink_(read_led);
      Serial.write(myFile.read());
     
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.print("error opening");
    Serial.println(title);
     blink_(error_led);
  }
      }
    }
