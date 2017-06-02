""" File that is a bridge between the Serial Out of the Nano, and emulating keyboard events."""

import glob
import sys
import serial





class SerialListener:
    """ Listen to all available serial ports.."""
    def __init__(self):
        self.setup()

    def setup(self):
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
            split = serialout.decode("utf-8").replace('\r','').split('\n')
            
            print(split)



if __name__ == '__main__':
    listener = SerialListener()
    
