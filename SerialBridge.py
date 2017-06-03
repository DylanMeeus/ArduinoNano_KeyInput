""" File that is a bridge between the Serial Out of the Nano, and emulating keyboard events."""

import glob
import sys
import os
import serial
import uinput # This needs the uinput kernel module (terminal: modprobe uinput)




class EventParser:
    """ Class to parse events that are found on the serial port """
    def __init__(self):
        self.mute = 1

    def parse(self, code):
        """ parses the code. The code will trigger an action """
        if(code == "1"):
            os.system('pactl set-sink-mute 1 ' + str(self.mute % 2))
            self.mute += 1


class KeySender:
    """ Sends keys to the OS, needs to be multi-os to handle it"""

    def __init__(self):
        pass


class SerialListener:
    """ Listen to all available serial ports.."""
    def __init__(self):
        self.setup()

    def setup(self):
        self.parser = EventParser()
        self.serialport = '/dev/ttyUSB0' # hardcoded for now because I know where it is..
        self.baud = 9600
        self.timeout = 1
        self.serial = serial.Serial(self.serialport, self.baud, timeout=self.timeout)
        self.listen()

    def listPorts(self):
        """ List all the available ports on linux """
        ports = glob.glob('/dev/tty[A-Za-z]*')
        print(ports)
        
    def listen(self):
        """ Listen to the chosen port"""
        while True:
            self.serial.close()
            self.serial.open()
            serialout = self.serial.read(size=64)
            incoming_codes = serialout.decode("utf-8").replace('\r','').split('\n')
            incoming_codes = list(filter(lambda k: k != '',incoming_codes))
            for code in incoming_codes:
                self.parser.parse(code)




if __name__ == '__main__':
    listener = SerialListener()
    #keysender = KeySender()
