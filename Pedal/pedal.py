import serial
import pyautogui as di 
import time
st = serial.Serial('COM5', 115200, timeout =.1)
timeout = 0
cnt = False
state = 0
state2 = 0
hold = 0
while(1):
    while(st.in_waiting > 0):
        rawdata = st.readline()
        data = str(rawdata.decode('latin-1'))
        if(data[0] == '1' and state == 0 and hold == 0):
            di.mouseDown()
            print(state)
            state = 1
            print("down")
            hold = 1
        if(data[1] == '1' and state2 == 0 and hold == 0):
            di.mouseDown()
            print(state)
            state2 = 1
            print("down")
        if(data[0] == '0' and state == 1):
            state = 0
            di.mouseUp()
            print("up")
            hold = 0
            #timeout = 10
        if(data[1] == '0' and state2 == 1):
            state2 = 0
            di.mouseUp()
            print( "up")
            hold =0
            #timeout = 10
            #di.mouseUp()
        #print(data)
        #print(state)


