I have hooked up my keyswitch tester to an Arduino Nano clone, and wrote some software to interpret the signals from the tester. The python code turns the keyswitch tester into a 'media control button device'.

The keyswitch tester that I used was one by CoolerMaster, which had 5 cherry mx keyswitches (blue, green, brown, black and red) and one Topre switch. I unfortunately could not hook up the Topre switch to the arduino, as they work in a different way than cherry mx keyswitches do.

Since I believe the Arduino Nano can not emulate a keyboard natively, the device is not recognized as a keyboard. To circumvent this, I made the arduino write out to Serial every time a button is pressed. The signal is sent out only once per button press, so holding the button will still only execute the print statement one time.

In order for the device to actually do anything, I had to write some code that could interpret the signal being sent over the Serial port. For this reason I wrote the Python script (SerialBridge.py). This script will listen to the serial port (easy to configure on linux, not so sure about windows/osx). The signal sent over the serial port is '1','2','3','4' or '5', depending on which of the 5 buttons is being pressed.

Once the python scripts reads some information from the Serial Port, it then parses this bit of information, and using xdotools, executes media scripts.

You can see it in action [here](https://www.youtube.com/watch?v=aqqdNTFgwkc).