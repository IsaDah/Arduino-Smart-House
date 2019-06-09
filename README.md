# Arduino-Smart-House
A simple demonstration of how Arduino and MIT App inventor can create a smart house, user will be able to control lock and lighting of their house from their Android device using Bluetooth.


4 files:

.ino contains the Arduino source code open it with Arduino IDE and upload it to the Arduino board make sure to unplug TX RX wires that are connected to the Arduino's Bluetooth module during upload or you will get an error after uploading plug them back in Bluetooth TX goes to Arduino RX and Arduino TX goes to Bluetooth RX !. 

.aia file source code for MIT App inventor import it there, from there you get the logic of the App view the logic blocks and the design. 

.apk file if you want to install the app on your phone.

Fritzing PNG showing how Arduino circuit is connected each white led represents a room.

Remember pair the device with bluetooth module first the password might vary from module to module, either 1234 or 0000.
After pairing open up the App and establish connection, the Bluetooth module by now should stop blinking.
