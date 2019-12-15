from psonic import *
import serial

# ser = serial.Serial('/dev/ttyUSB0', 9600)
ser = serial.Serial('/dev/tty.SLAB_USBtoUART', 9600)
s = [0]
print("Starting while loop\n")
marioPattern = [7, 7, 7, 4, 7, 9, 1]
fairyPattern = [8, 6, 8, 7, 5, 5]
christmasPattern = [4, 8, 8, 9, 8, 7, 6, 6]
pattern = []

def PlayMario():
	notes = [C5,  G4,   E4,   A4,   B4,  Bb4,   A4,  G4,  E5,   G5,  A5,    F5,   G5,   E5,  C5, D5, B4]
	time =  [0.5, 0.5, 0.5, 0.35, 0.35, 0.15, 0.25, .25, .25, 0.25, 0.35, 0.15, 0.35, 0.35, 0.15, 0.15, 0.15]
	for i in range(0, len(notes)):
		play(notes[i], amp=0.25)
		sleep(time[i])

def PlaySugarPlum():
	notes = [ C5,   C5,  C5,   B4,   B4,  B4,  Bb4,  Bb4,  Bb4,   G4,   D5,  Bb4,   D5, A4]
	time = [0.35, 0.35, 0.5, 0.35, 0.35, 0.5, 0.35, 0.35,  0.5, 0.35, 0.35, 0.35, 0.35, 1]
	for i in range(0, len(notes)):
		play(notes[i], amp=0.25)
		sleep(time[i])

def PlayChristmas():
	notes = [D5,  G5,   G5,   A5,   G5,   F5,   E5,  C5,   C5,  A5,   A5,  Bb5,   A5,   G5,   F5,  D5,   C5,   C5,  D5, G5,   E5,  F5]
	time = [0.5, 0.5, 0.25, 0.25, 0.25, 0.25,  0.5, 0.5,  0.5, 0.5, 0.25, 0.25, 0.25, 0.25,  0.5, 0.5, 0.25, 0.25, 0.5, 0.5, 0.5, 0.5]
	for i in range(0, len(notes)):
		play(notes[i], amp=0.25)
		sleep(time[i])

while True:
	read_serial = ord(ser.read(1).decode())
	print(read_serial)
	# s[0] = str(int (ser.readline(), 16))
	# print s[0]

	if (read_serial == 1):
		play(G4, amp=0.3)
	elif (read_serial == 2):
		play(A4, amp=0.3)
	elif (read_serial == 3):
		play(B4, amp=0.3)
	elif (read_serial == 4):
		play(C5, amp=0.3)
	elif (read_serial == 5):
		play(Cs5, amp=0.3)
	elif (read_serial == 6):
		play(D5, amp=0.3)
	elif (read_serial == 7):
		play(E5, amp=0.3)
	elif (read_serial == 8):
		play(F5, amp=0.3)
	elif (read_serial == 9):
		play(G5, amp=0.3)

	print(len(pattern))
	if (len(pattern) > 7):
		pattern.pop(0)
	pattern.append(read_serial)
	print(pattern)

	if (pattern == christmasPattern):
		sleep(0.5)
		PlayChristmas()
		pattern = []
	elif (pattern[1:] == marioPattern or pattern[0:7] == marioPattern):
		sleep(0.5)
		PlayMario()
		pattern = []
	elif (pattern[2:] == fairyPattern or pattern[0:6] == fairyPattern):
		sleep(0.5)
		PlaySugarPlum()
		pattern = []



