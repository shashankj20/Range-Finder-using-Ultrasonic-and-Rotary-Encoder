Range Finder using Ultrasonic Distance Sensor and Rotary Encoder
1. Description:
This project utilizes an Arduino to create a range finder using an ultrasonic distance sensor (HC-SR04) and a rotary encoder. The distance sensor measures the distance of an object, while the rotary encoder is used to adjust the detection range dynamically.

2. Components Lists:
Arduino Board (e.g., Arduino Uno)
Ultrasonic Distance Sensor (HC-SR04)
Rotary Encoder
LEDs (Red, Green, Blue)
Buzzer
Resistors
Breadboard
Jumper wires

3. Connection Guide:
Connect the HC-SR04's TRIG pin to pin 7, and the ECHO pin to pin 6 on the Arduino.
Connect the CLK (clock) pin of the rotary encoder to pin 9 and the DT (data) pin to pin 10.
Connect the LEDs: Red to pin 2, Green to pin 3, and Blue to pin 4.
Connect the buzzer to pin 8.
Ensure proper power and ground connections for all components.
Refer to the code comments for additional connection details.

4. Usage:
Upload the provided code to your Arduino board using the Arduino IDE.
Power the Arduino board.
Adjust the rotary encoder to expand or compress the detection range.
Observe the LED colors and listen to the buzzer for object detection feedback.

5. Functionality:
The ultrasonic distance sensor measures the distance of an object in front of it.
The rotary encoder allows for dynamic adjustment of the detection range between predefined minimum and maximum distances.
LEDs indicate object detection status: Red LED lights up when an object is within the detection range, while the Green LED indicates no object detected.
The Blue LED indicates rotary encoder usage.
The buzzer produces a sound when an object is detected within the range.

6. Customization:
Adjust the minimum and maximum detection ranges (minDistance and maxDistance variables) to suit your requirements.
Modify LED colors or add additional feedback elements based on your preferences.
Experiment with different frequencies for the buzzer tone.

7. Author:
This project was created by [Shashank J].

8. License:
This project is licensed under the Creative Commons License. Feel free to use and modify it for your own purposes, but please attribute the original author.
