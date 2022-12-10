# PES_FINAL_PROJECT_DIgital_angle_gauge
PES_FINAL_PROJECT_DIgital_angle_gauge - MALOLASIMMAN SRINIVASAN KANNAN
 
## Objective:
To implement the MMA8451Q accelerometer over I2C, and develop the logic for a digital angle gauge without the
LCD screen. Changing the LED color in response to the device orientation allows a user to set the saw blade on a
table saw to exactly 45° relative to the table. This project allows for calibration of the 0° setting – perhaps the user
could press a button connected to GPIO to indicate 0°, or the user could type commands over the serial port.

## Technologies: 
I2C, UART, TSI command processor, PWM, GPIO.

## Setup:
KL25Z Development Board, Sensor: MMA8451Q, Communication Protocol: UART, I2C

## Functionalities:
In semiconductor industries craft the chip according to dimensions or maybe 3d printing, in these fields it is easier to
add this project and it will be easier to measure. This project demonstrates and tries to solve one of the problems that
we have addressed above. Developed logic in such a way as to measure the digital angle and with respect to
orientation changes LED color. This project allows user provision to calibrate a zero reference through an interrupt
External switch connected PTD7 and user will give confirmation of reference angle through TSI after button press or with a serial monitor
where user can give the command through command processor as well.
# command options:

<img width="599" alt="Screenshot 2022-12-10 at 1 37 49 AM" src="https://user-images.githubusercontent.com/59477885/206841496-58a79147-1f0a-474b-8d73-2493e91a54b4.png">

# Angle detection
Angle can be detected using serial terminal or LED colors
for 30 degree i have choosen the red led 
45 degree selected green led
60 degree selected blue led
90 choosen white led

## Terminal Setting:
Baudrate 38400
stop bits 2 
parity none

## State Machine Diagram:
![Finite state machine](https://user-images.githubusercontent.com/59477885/206842357-a31d348d-5bf2-4483-a324-c9f70aa94b05.png)

## Demo Video link:
https://drive.google.com/file/d/1XDHooC2CWMwzR8Q8kRBI69o_KnPW2EIy/view?usp=sharing
## Test methodology:
Tested the Accelerometer and Circular buffer did the automated testcases;
1. Test_cbfifo() function im enquing and dequeing the characters to circular buffer 
    For circular buffer passed the string and enqued and dequed the characters and 
    also tested length and capacity of the functions.
2. Test_MMA8451 function i have tested the pwm with respect to accelerometer angle.
    In this function i have given angles and noted changes in LED color 
    
## Outcome:
FRDM KL25Z contains an inbuilt MMA8451Q accelerometer which is tied to the I2C line and depending on
the orientation, the led color can be changed, and the orientation axis will be displayed in the serial
monitor. This allows me to handle various communication protocols as well as how to incorporate the
sensor in KL25Z. I'll be using a combination of automated and manual testing for my project.



