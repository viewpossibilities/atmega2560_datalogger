# atmega2560_datalogger
This is a datalogger system that is powered by the atmega2560 microcontroller having an SD card to store the data.
the SD card is connected to the microcontroller using the SPI communication protocol, pin 50,51 and 52 for the MISO,MOSI and SCK respectively while pin 53 is Chip select pin
The sytem writes data into the SD card, then at the press of a button it begins to reads data from the SD card to the serial port.
